/*
** EPITECH PROJECT, 2022
** PANORAMIX
** File description:
** dialogue
*/

#include "../include/panoramix.h"

void druid_start(void)
{
    printf("Druid: I'm ready... but sleepy...\n");
}

void refill_the_pot(int refill)
{
    printf("Druid: Ah! Yes, yes, I'm awake! Working on it! ");
    printf("Beware I can only make %d more refills after this one.\n", refill);
}

void run_out_of_ingredients(void)
{
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
}
