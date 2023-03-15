/*
** EPITECH PROJECT, 2022
** PANORAMIX
** File description:
** PANORAMIX
*/

#ifndef PANORAMIX_H_
    #define PANORAMIX_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdbool.h>
    #include <sys/stat.h>
    #include <sys/mman.h>
    #include <pthread.h>
    #include <fcntl.h>
    #include <semaphore.h>

typedef struct panoramix_data_s panoramix_data_t;
typedef struct villager_s villager_t;

struct villager_s {
    int id;
    int nb_fights;
};

struct panoramix_data_s {
    int nb_villagers;
    int pot_size;
    int nb_fights;
    int nb_refills;
    int nb_fills;
    int id;
    int nb_fights_total;
    pthread_mutex_t mutex;
    sem_t start;
    sem_t refills;
    sem_t update_refills;
    sem_t update_id;
};

char *get_file(char *filename);
char **str_to_word_array(char *str, char c);
villager_t init_villager(panoramix_data_t *panoramix);
panoramix_data_t init_panoramix(char **av);
void init_sem_and_mutex(panoramix_data_t *panoramix);
void create_pthread(pthread_t threads[], int nb, panoramix_data_t *panoramix);
void join_pthread(pthread_t threads[], int nb);
void wait_for_battle(panoramix_data_t *panoramix);
void destroy_sem_and_mutex(panoramix_data_t *panoramix);
void *druid_job(void *arg);
void *villager_job(void *arg);

/* dialogue */
void druid_start(void);
void refill_the_pot(int refill);
void run_out_of_ingredients(void);
void villager_start(int id);
void drink_some_potion(int id, int nb_left);
void call_for_a_refill(int id);
void villager_is_fighting(int id, int fight_left);
void villager_done_fighting(int id);

#endif /* !PANORAMIX_H_ */
