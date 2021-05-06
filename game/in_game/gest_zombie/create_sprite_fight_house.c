/*
** EPITECH PROJECT, 2020
** fight_house
** File description:
** create_scene_fight_house
*/

#include "../../../my_rpg.h"

void create_sprite_fight(game_t *game)
{
    game->fight->house_sprite = sfSprite_create();
    game->fight->sprite_perso_fight = sfSprite_create();
    game->fight->sprite_zombie_fight = sfSprite_create();
    game->fight->sprite_perso_fight_fire = sfSprite_create();
    game->sound->sound = sfSound_create();
    game->sound->sound_persotakedam = sfSound_create();
    game->sound->sound_zombietakedam = sfSound_create();
    game->score->text_perso = sfText_create();
    game->score->text_zombie = sfText_create();
    game->fight->rect_perso_fight.height = 315;
    game->fight->rect_perso_fight.width = 154;
    game->fight->rect_perso_fight.top = 0;
    game->fight->rect_perso_fight.left = 0;
    game->fight->rect_boss_fight.height = 507;
    game->fight->rect_boss_fight.width = 333;
    game->fight->rect_boss_fight.top = 0;
    game->fight->rect_boss_fight.left = 0;
}

void create_texture_fight(game_t *game)
{
    game->fight->house_texture = sfTexture_createFromFile
        ("./game/in_game/png/house.png", NULL);
    game->fight->texture_perso_fight = sfTexture_createFromFile
        ("./game/in_game/png/soldat_fight.png", NULL);
    game->fight->texture_zombie_fight = sfTexture_createFromFile
        ("./game/in_game/png/zombie.png", NULL);
    game->fight->texture_perso_fight_fire = sfTexture_createFromFile
        ("./game/in_game/png/soldat_fight_fire.png", NULL);
    game->sound->buffer = sfSoundBuffer_createFromFile
        ("./game/in_game/png/bruit_arme.ogg");
    game->sound->buffer_persotakedam = sfSoundBuffer_createFromFile
        ("./game/in_game/png/persotakedam.ogg");
    game->sound->buffer_zombietakedam = sfSoundBuffer_createFromFile
        ("./game/in_game/png/Degats.ogg");
    game->score->font = sfFont_createFromFile("./font.ttf");
    game->fight->n = 0;
}

void set_texture_fight(game_t *game)
{
    sfSprite_setTexture(game->fight->house_sprite,
        game->fight->house_texture, sfTrue);
    sfSprite_setTexture(game->fight->sprite_perso_fight,
        game->fight->texture_perso_fight, sfTrue);
    sfSprite_setTexture(game->fight->sprite_zombie_fight,
        game->fight->texture_zombie_fight, sfTrue);
    sfSprite_setTexture(game->fight->sprite_perso_fight_fire,
        game->fight->texture_perso_fight_fire, sfTrue);
    sfSound_setBuffer(game->sound->sound, game->sound->buffer);
    sfSound_setBuffer(game->sound->sound_persotakedam,
        game->sound->buffer_persotakedam);
    sfSound_setBuffer(game->sound->sound_zombietakedam,
        game->sound->buffer_zombietakedam);
    sfSprite_setPosition(game->fight->sprite_perso_fight,
        (sfVector2f){350, 520});
    sfSprite_setPosition(game->fight->sprite_perso_fight_fire,
        (sfVector2f){350, 520});
    sfSprite_setPosition(game->fight->sprite_zombie_fight,
        (sfVector2f){700, 520});
}

void draw_texture_fight(game_t *game)
{
    sfRenderWindow_drawSprite(game->window->window,
        game->fight->house_sprite, NULL);
    sfRenderWindow_drawSprite(game->window->window,
        game->fight->sprite_perso_fight, NULL);
    sfRenderWindow_drawSprite(game->window->window,
        game->fight->sprite_zombie_fight, NULL);
    sfRenderWindow_drawText(game->window->window,
        game->score->text_perso, NULL);
    sfRenderWindow_drawText(game->window->window,
        game->score->text_zombie, NULL);
}

void init_sprite_fight(game_t *game)
{
    create_sprite_fight(game);
    create_texture_fight(game);
    set_texture_fight(game);
}