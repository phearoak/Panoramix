/*
** EPITECH PROJECT, 2022
** PANORAMIX
** File description:
** main
*/

#include "../include/panoramix.h"

void villager_loop(panoramix_data_t *panoramix, villager_t villager)
{
    while (villager.nb_fights > 0 && \
    (panoramix->nb_refills > 0 || panoramix->nb_fills > 0)) {
        pthread_mutex_lock(&panoramix->mutex);
        if (panoramix->nb_refills == 0 && panoramix->nb_fills == 0) {
            pthread_mutex_unlock(&panoramix->mutex);
            break;
        }
        drink_some_potion(villager.id, panoramix->nb_fills);
        if (panoramix->nb_fills == 0 && panoramix->nb_refills > 0) {
            call_for_a_refill(villager.id);
            sem_post(&panoramix->update_refills);
            sem_wait(&panoramix->refills);
        }
        panoramix->nb_fills -= 1;
        villager.nb_fights -= 1;
        panoramix->nb_fights_total -= 1;
        pthread_mutex_unlock(&panoramix->mutex);
        villager_is_fighting(villager.id, villager.nb_fights);
    }
}

void druid_loop(panoramix_data_t *panoramix)
{
    while (panoramix->nb_fills > 0 && \
    panoramix->nb_refills != 0 && panoramix->nb_fights_total > 0) {
        sem_wait(&panoramix->update_refills);
        if (panoramix->nb_fights_total <= 0) {
            pthread_exit(EXIT_SUCCESS);
        }
        panoramix->nb_refills -= 1;
        refill_the_pot(panoramix->nb_refills);
        panoramix->nb_fills = panoramix->pot_size;
        sem_post(&panoramix->refills);
    }
}

void *villager_job(void *arg)
{
    panoramix_data_t *panoramix = (panoramix_data_t *)arg;
    sem_wait(&panoramix->update_id);
    villager_t villager = init_villager(panoramix);
    villager_start(villager.id);
    sem_post(&panoramix->update_id);
    sem_wait(&panoramix->start);
    villager_loop(panoramix, villager);

    if (panoramix->nb_fights_total <= 0) {
        sem_post(&panoramix->update_refills);
    }
    villager_done_fighting(villager.id);
    pthread_exit(EXIT_SUCCESS);
}

void *druid_job(void *arg)
{
    panoramix_data_t *panoramix = (panoramix_data_t *)arg;
    druid_start();
    sem_post(&panoramix->start);
    druid_loop(panoramix);
    run_out_of_ingredients();
    pthread_exit(EXIT_SUCCESS);
}

int main(int ac, char **av)
{
    if (ac != 5) return (EXIT_FAILURE);

    panoramix_data_t panoramix = init_panoramix(av);
    pthread_t threads[panoramix.nb_villagers + 1];

    pthread_create(&threads[0], NULL, druid_job, &panoramix);
    sem_wait(&panoramix.start);
    create_pthread(threads, panoramix.nb_villagers, &panoramix);
    wait_for_battle(&panoramix);
    join_pthread(threads, panoramix.nb_villagers);
    destroy_sem_and_mutex(&panoramix);
    return EXIT_SUCCESS;
}
