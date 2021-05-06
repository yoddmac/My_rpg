/*
** EPITECH PROJECT, 2020
** create
** File description:
** create_window
*/

#include "../../my_rpg.h"

void init_window(game_t *game)
{
    game->sound->song_scene = 0;
    init_sprite_fight_boss(game);
    init_sprite_menu(game);
    init_sprite_game(game);
    init_rect_perso(game);
    init_sprite_fight(game);
    init_sprite_buttonfight(game);
    inventory_init(game);
    init_rect_zombie_infight(game);
    pause_in_game(game);
    game->window->video.width = 1920;
    game->window->video.height = 1040;
    game->perso->perso_life = 100;
    game->perso->perso_max_health = 100;
    game->fight->life_zombie1 = 80;
    game->fight->life_zombie2 = 100;
    game->fight->life_boss = 200;
    game->window->window = sfRenderWindow_create(game->window->video,
        "MY_RPG", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->window->window, 30);
}

int gest_music(game_t *game)
{
    if (game->sound->song_scene == 0 && game->sound->music_menu != NULL) {
        sfMusic_play(game->sound->music_menu);
        game->sound->song_scene = 2;
    }
    if (game->sound->song_scene == 1 && game->sound->music_ingame != NULL) {
        game->sound->song_scene = 2;
        sfMusic_stop(game->sound->music_menu);
        sfMusic_play(game->sound->music_ingame);
    }
    return (0);
}

void window_isopen(game_t *game)
{
    gest_music(game);
    animation(game);
    inventory_update(game);
    anim_zombie(game);
    open_scene_game(game);
    open_scene_in_game(game);
    stats_life(game);
    anim_zombie_infight(game);
    sfClock_restart(game->time_game->clock);
    sfRenderWindow_display(game->window->window);
}

void create_window(game_t *game)
{

    init_window(game);
    declare_map(game);

    while (sfRenderWindow_isOpen(game->window->window)) {
        game->time_game->time_clock =
            sfClock_getElapsedTime(game->time_game->clock);
        game->time_game->sec =
            game->time_game->time_clock.microseconds / 1000000.0;
        while (sfRenderWindow_pollEvent(game->window->window,
            &game->window->event)) {
            call_all_button(game);
            if (game->pause->scene == 1)
                button_pause_in_game(game);
            analyse_events(game);
            menu_button_attack(game);
            create_fight(game);
        }
        window_isopen(game);
    }
    destroy_all(game);
}
