/*
** EPITECH PROJECT, 2022
** PANORAMIX
** File description:
** dialogue
*/

#include "../include/panoramix.h"

void villager_start(int id)
{
    printf("Villager %d: Going into battle!\n", id);
}

void drink_some_potion(int id, int nb_left)
{
    printf("Villager %d: I need a drink... I see %d servings left.\n", \
    id, nb_left);
}

void call_for_a_refill(int id)
{
    printf("Villager %d: Hey Pano wake up! We need more potion.\n", id);
}

void villager_is_fighting(int id, int fight_left)
{
    printf("Villager %d: Take that roman scum! Only %d left.\n", \
    id, fight_left);
}

void villager_done_fighting(int id)
{
    printf("Villager %d: I'm going to sleep now.\n", id);
}
