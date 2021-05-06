/*
** EPITECH PROJECT, 2020
** sprite_menu
** File description:
** create_sprite_menu
*/

#include "../../my_rpg.h"

void create_sprite_menu(game_t *game)
{
    game->menu->sprite_fond = sfSprite_create();
    game->menu->start_sprite = sfSprite_create();
    game->menu->option_sprite = sfSprite_create();
    game->menu->quit_sprite = sfSprite_create();
    game->menu->resume_sprite = sfSprite_create();
    game->menu->go_sprite = sfSprite_create();
    game->sound->sound_typewriter = sfSound_create();
    game->sound->sound_heal = sfSound_create();
    game->sound->sound_click = sfSound_create();
    game->menu->spritehowtoplay = sfSprite_create();
}

void create_texture_menu(game_t *game)
{
    game->menu->texturehowtoplay = sfTexture_createFromFile(
        "./game/menu/png/howtoplay.png", NULL);
    game->sound->music_menu = sfMusic_createFromFile
        ("./game/menu/png/musique_menu.ogg");
    game->sound->buffer_heal = sfSoundBuffer_createFromFile
        ("./game/menu/png/Soin.ogg");
    game->sound->buffer_heal = sfSoundBuffer_createFromFile
        ("./game/menu/png/Soin.ogg");
    game->sound->buffer_typewriter = sfSoundBuffer_createFromFile
        ("./game/menu/png/machine.ogg");
    game->sound->buffer_click = sfSoundBuffer_createFromFile
        ("./game/menu/png/Click.ogg");
    game->menu->go_texture = sfTexture_createFromFile
        ("./game/menu/png/Go.png", NULL);
    game->menu->texture_fond = sfTexture_createFromFile
        ("./game/menu/png/menu_fond.png", NULL);
    game->menu->resume_texture = sfTexture_createFromFile
        ("./game/menu/png/resumé.png", NULL);
    create_texture_menu_next(game);
}

void create_texture_menu_next(game_t *game)
{
    game->menu->start_texture = sfTexture_createFromFile
        ("./game/menu/png/start.png", NULL);
    game->menu->start2_texture = sfTexture_createFromFile
        ("./game/menu/png/start2.png", NULL);
    game->menu->option_texture = sfTexture_createFromFile
        ("./game/menu/png/option.png", NULL);
    game->menu->option2_texture = sfTexture_createFromFile
        ("./game/menu/png/option2.png", NULL);
    game->menu->quit_texture = sfTexture_createFromFile
        ("./game/menu/png/quit.png", NULL);
    game->menu->quit2_texture = sfTexture_createFromFile
        ("./game/menu/png/quit2.png", NULL);
}

void set_texture_menu(game_t *game)
{
    sfSprite_setTexture(game->menu->spritehowtoplay,
        game->menu->texturehowtoplay, sfTrue);
    sfSprite_setTexture(game->menu->go_sprite,
        game->menu->go_texture, sfTrue);
    sfSprite_setTexture(game->menu->sprite_fond,
        game->menu->texture_fond, sfTrue);
    sfSprite_setTexture(game->menu->start_sprite,
        game->menu->start_texture, sfTrue);
    sfSprite_setTexture(game->menu->option_sprite,
        game->menu->option_texture, sfTrue);
    sfSprite_setTexture(game->menu->quit_sprite,
        game->menu->quit_texture, sfTrue);
    sfSprite_setTexture(game->menu->resume_sprite,
        game->menu->resume_texture, sfTrue);
    set_sound_menu(game);
    sfSprite_setPosition(game->menu->start_sprite, (sfVector2f){800, 270});
    sfSprite_setPosition(game->menu->option_sprite, (sfVector2f){800, 540});
    sfSprite_setPosition(game->menu->quit_sprite, (sfVector2f){800, 810});
    sfSprite_setPosition(game->menu->go_sprite, (sfVector2f){1400, 800});
}

void set_sound_menu(game_t *game)
{
    sfSound_setBuffer(game->sound->sound_typewriter,
        game->sound->buffer_typewriter);
    sfSound_setBuffer(game->sound->sound_heal,
        game->sound->buffer_heal);
    sfSound_setBuffer(game->sound->sound_click,
        game->sound->buffer_click);
}
