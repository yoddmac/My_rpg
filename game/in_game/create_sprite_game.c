/*
** EPITECH PROJECT, 2020
** create_sprite_game
** File description:
** create_sprite_game
*/

#include "../../my_rpg.h"

void create_sprite_game(game_t *game)
{
    game->perso->sprite_perso = sfSprite_create();
    game->zombie->sprite_zombie = sfSprite_create();
    game->zombie->sprite_zombie2 = sfSprite_create();
    game->zombie->sprite_bosszombie = sfSprite_create();
    game->perso->text_life = sfText_create();
    game->perso->text_life_max = sfText_create();
    game->perso->text_slach = sfText_create();
    game->perso->spritepnj_quete = sfSprite_create();
    game->perso->sprite_speakpnj = sfSprite_create();
    game->rain->sprite = sfSprite_create();
}

void create_texture_game(game_t *game)
{
    game->perso->texture_perso = sfTexture_createFromFile
        ("./game/in_game/png/perso.png", NULL);
    game->zombie->texture_zombie = sfTexture_createFromFile
        ("./game/in_game/png/zombie_base.png", NULL);
    game->zombie->texture_zombie2 = sfTexture_createFromFile
        ("./game/in_game/png/zombie_base.png", NULL);
    game->zombie->texture_bosszombie = sfTexture_createFromFile
        ("./game/in_game/png/boss.png", NULL);
    game->sound->music_ingame = sfMusic_createFromFile
        ("./game/in_game/png/musique_jeu.ogg");
    game->perso->texturepnj_quete = sfTexture_createFromFile
        ("./game/in_game/png/pnj_quete.png", NULL);
    game->perso->texture_speakpnj = sfTexture_createFromFile
    ("./game/in_game/png/speakpnj.png", NULL);
    game->rain->texture = sfTexture_createFromFile
        ("./game/in_game/png/Rain.png", NULL);
}

void set_texture_game(game_t *game)
{
    sfSprite_setTexture(game->perso->sprite_perso,
        game->perso->texture_perso, sfTrue);
    sfSprite_setTexture(game->zombie->sprite_zombie,
        game->zombie->texture_zombie, sfTrue);
    sfSprite_setTexture(game->zombie->sprite_zombie2,
        game->zombie->texture_zombie2, sfTrue);
    sfSprite_setTexture(game->zombie->sprite_bosszombie,
        game->zombie->texture_bosszombie, sfTrue);
    sfSprite_setTexture(game->perso->spritepnj_quete,
        game->perso->texturepnj_quete, sfTrue);
    sfSprite_setTexture(game->perso->sprite_speakpnj,
        game->perso->texture_speakpnj, sfTrue);
    sfSprite_setTexture(game->rain->sprite, game->rain->texture, sfTrue);
    sfSprite_setPosition(game->perso->spritepnj_quete, (sfVector2f){50, 130});
    sfSprite_setPosition(game->zombie->sprite_zombie, (sfVector2f){170, 150});
    sfSprite_setPosition(game->zombie->sprite_zombie2, (sfVector2f){600, 600});
}

void draw_texture_game(game_t *game)
{
    sfRenderWindow_drawSprite(game->window->window,
        game->perso->sprite_perso, NULL);
    sfRenderWindow_drawSprite(game->window->window,
        game->zombie->sprite_zombie, NULL);
    sfRenderWindow_drawSprite(game->window->window,
        game->zombie->sprite_zombie2, NULL);
    sfRenderWindow_drawSprite(game->window->window,
        game->perso->spritepnj_quete, NULL);
    if (game->zombie->alive == 2) {
        game->fight->here = 1;
        sfRenderWindow_drawSprite(game->window->window,
            game->zombie->sprite_bosszombie, NULL);
        sfSprite_setPosition(game->zombie->sprite_bosszombie,
            (sfVector2f){1650, 200});
    }
    draw_texture_game_next(game);
}

void draw_texture_game_next(game_t *game)
{
    sfRenderWindow_drawText(game->window->window, game->perso->text_life, NULL);
    sfRenderWindow_drawText(game->window->window,
        game->perso->text_life_max, NULL);
    sfRenderWindow_drawText(game->window->window,
        game->perso->text_slach, NULL);
    if (game->perso->speak == 1) {
        sfRenderWindow_drawSprite(game->window->window,
            game->perso->sprite_speakpnj, NULL);
        sfRenderWindow_drawSprite(game->window->window,
            game->menu->go_sprite, NULL);
    }
}