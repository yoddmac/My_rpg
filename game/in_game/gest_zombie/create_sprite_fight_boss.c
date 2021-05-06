/*
** EPITECH PROJECT, 2020
** fight_boss
** File description:
** create_sprite_fight_boss
*/

#include "../../../my_rpg.h"

void create_sprite_fight_boss(game_t *game)
{
    game->fight->sprite_boss_fight = sfSprite_create();
    game->fight->sprite_cemetery = sfSprite_create();

}

void create_texture_fight_boss(game_t *game)
{
    game->fight->texture_boss_fight = sfTexture_createFromFile
        ("./game/in_game/png/boss_fight.png", NULL);
    game->fight->texture_cemetery = sfTexture_createFromFile
        ("./game/in_game/png/cimetiere.png", NULL);
}

void set_texture_fight_boss(game_t *game)
{
    sfSprite_setTexture(game->fight->sprite_boss_fight,
        game->fight->texture_boss_fight, sfTrue);
    sfSprite_setTexture(game->fight->sprite_cemetery,
        game->fight->texture_cemetery, sfTrue);
    sfSprite_setPosition(game->fight->sprite_boss_fight,
        (sfVector2f){1000, 350});
}

void draw_texture_fight_boss(game_t *game)
{
    sfRenderWindow_drawSprite(game->window->window,
        game->fight->sprite_cemetery, NULL);
    sfRenderWindow_drawSprite(game->window->window,
        game->fight->sprite_boss_fight, NULL);
    sfRenderWindow_drawSprite(game->window->window,
        game->fight->sprite_perso_fight, NULL);
    sfRenderWindow_drawText(game->window->window,
        game->score->text_perso, NULL);
    sfRenderWindow_drawText(game->window->window,
        game->score->text_zombie, NULL);
}

void init_sprite_fight_boss(game_t *game)
{
    create_sprite_fight_boss(game);
    create_texture_fight_boss(game);
    set_texture_fight_boss(game);
}