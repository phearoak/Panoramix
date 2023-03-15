/*
** EPITECH PROJECT, 2022
** PANORAMIX
** File description:
** initialisation
*/

#include "../include/panoramix.h"

villager_t init_villager(panoramix_data_t *panoramix)
{
    villager_t villager;
    villager.id = panoramix->id;
    villager.nb_fights = panoramix->nb_fights;
    panoramix->id++;
    return villager;
}

panoramix_data_t init_panoramix(char **av)
{
    panoramix_data_t panoramix;
    panoramix.nb_villagers = atoi(av[1]);
    panoramix.pot_size = atoi(av[2]);
    panoramix.nb_fills = atoi(av[2]);
    panoramix.nb_fights = atoi(av[3]);
    panoramix.nb_refills = atoi(av[4]);
    panoramix.nb_fights_total = panoramix.nb_fights * panoramix.nb_villagers;
    panoramix.id = 0;
    pthread_mutex_init(&panoramix.mutex, NULL);
    sem_init(&panoramix.start, 0, 0);
    sem_init(&panoramix.refills, 0, 0);
    sem_init(&panoramix.update_refills, 0, 0);
    sem_init(&panoramix.update_id, 0, 1);
    return panoramix;
}

void destroy_sem_and_mutex(panoramix_data_t *panoramix)
{
    pthread_mutex_destroy(&panoramix->mutex);
    sem_destroy(&panoramix->start);
    sem_destroy(&panoramix->refills);
    sem_destroy(&panoramix->update_refills);
    sem_destroy(&panoramix->update_id);
}
