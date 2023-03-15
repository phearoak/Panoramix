/*
** EPITECH PROJECT, 2022
** PANORAMIX
** File description:
** pthread_functions
*/

#include "../include/panoramix.h"

void create_pthread(pthread_t threads[], int nb, panoramix_data_t *panoramix)
{
    for (int i = 1; i < nb + 1; i++) {
        pthread_create(&threads[i], NULL, villager_job, panoramix);
    }
}

void join_pthread(pthread_t threads[], int nb)
{
    for (int i = 1; i < nb + 1; i++) {
        pthread_join(threads[i], NULL);
    }
}

void wait_for_battle(panoramix_data_t *panoramix)
{
    while (1) {
        if (panoramix->nb_villagers == panoramix->id) {
            break;
        }
    }
    for (int j = 0; j < panoramix->nb_villagers + 1; j++) {
        sem_post(&panoramix->start);
    }
}
