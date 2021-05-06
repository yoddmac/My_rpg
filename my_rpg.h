/*
** EPITECH PROJECT, 2020
** my_rpg.h
** File description:
** my_rpg
*/

#ifndef MY_RPG_H_
#define MY_RPG_H_

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct s_slot
{
    int empty;
    char *name;
    int quantity;
    sfVector2f scale;
    sfVector2f pos;
    sfTexture *texture;
    sfSprite *sprite;
}slot_t;

typedef struct s_inventory
{
    slot_t *slot_1;
    slot_t *slot_2;
    slot_t *slot_3;
    slot_t *slot_4;
    slot_t *slot_5;
}invent_t;

typedef struct button_ingame_s
{
    sfSprite *sprite_attack;
    sfTexture *texture_attack;
    int change;

} button_ingame_t;

typedef struct score_s {
    sfTexture* score;
    sfVector2f pos;
    sfText* text_perso;
    sfText *text_zombie;
    sfFont *font;
    sfClock* clock;
} score_t;

typedef struct sound_s
{
    sfSoundBuffer *buffer;
    sfSound *sound;
    sfSoundBuffer *buffer_typewriter;
    sfSound *sound_typewriter;
    int song_scene;
    sfMusic *music_ingame;
    sfMusic *music_menu;
    sfSoundBuffer *buffer_heal;
    sfSound *sound_heal;
    sfSoundBuffer *buffer_click;
    sfSound *sound_click;
    sfSoundBuffer *buffer_zombietakedam;
    sfSound *sound_zombietakedam;
    sfSoundBuffer *buffer_persotakedam;
    sfSound *sound_persotakedam;
} sound_t;

typedef struct zombie_s
{
    float time;
    sfSprite *sprite_zombie;
    sfTexture *texture_zombie;
    sfVector2f pos_zombie;
    sfIntRect rect_zombie;
    sfFloatRect f_rect;
    sfIntRect fight_zone;

    sfSprite *sprite_zombie2;
    sfTexture *texture_zombie2;
    sfVector2f pos_zombie2;
    sfIntRect rect_zombie2;
    sfFloatRect f_rect2;
    sfIntRect fight_zone2;

    sfSprite *sprite_bosszombie;
    sfTexture *texture_bosszombie;
    sfVector2f pos_boss;
    sfFloatRect f_rectboss;
    sfIntRect fight_zone_boss;

    int c;
    int alive;

} zombie_t;

typedef struct perso_s
{
    sfSprite *spritepnj_quete;
    sfTexture *texturepnj_quete;

    sfSprite *sprite_speakpnj;
    sfTexture *texture_speakpnj;

    sfSprite *sprite_perso;
    sfTexture *texture_perso;

    sfVector2f pos_perso;
    sfIntRect rect_perso;
    sfFloatRect fperso_rect;

    int perso_life;
    int perso_max_health;

    sfVector2f pos;
    sfText* text_life;
    sfText *text_slach;
    sfText *text_life_max;

    int speak;
    int x;
    int y;
    int tile;
    int **map;

} perso_t;

typedef struct window_s
{
    int scene;
    sfRenderWindow *window;
    sfVideoMode video;
    sfEvent event;
} window_t;

typedef struct rain_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    float sec;
}rain_t;

typedef struct menu_s
{
    int end_story;

    sfSprite *spritehowtoplay;
    sfTexture *texturehowtoplay;
    sfSprite *sprite_fond;
    sfTexture *texture_fond;

    sfSprite *start_sprite;
    sfTexture *start_texture;
    sfTexture *start2_texture;

    sfSprite *option_sprite;
    sfTexture *option2_texture;
    sfTexture *option_texture;

    sfSprite *quit_sprite;
    sfTexture *quit_texture;
    sfTexture *quit2_texture;

    sfSprite *resume_sprite;
    sfTexture *resume_texture;

    sfSprite *go_sprite;
    sfTexture *go_texture;

} menu_t;

typedef struct fight_s
{
    sfSprite *house_sprite;
    sfTexture *house_texture;

    sfSprite *sprite_perso_fight;
    sfTexture *texture_perso_fight;

    sfSprite *sprite_perso_fight_fire;
    sfTexture *texture_perso_fight_fire;

    sfSprite *sprite_zombie_fight;
    sfTexture *texture_zombie_fight;
    sfIntRect rect_zombie_fight;
    sfIntRect rect_perso_fight;
    sfIntRect rect_boss_fight;

    sfSprite *sprite_boss_fight;
    sfTexture *texture_boss_fight;
    sfSprite *sprite_cemetery;
    sfTexture *texture_cemetery;

    int life_zombie1;
    int life_zombie2;
    int life_boss;
    int scene;
    int here;
    float sec;
    int turn;
    float turn_sec;
    int phase_p;
    int phase_z;
    int phase_b;
    int n;
} fight_t;

typedef struct pause_s {

    sfSprite *sprite_pause_font;
    sfTexture *texture_pause_font;

    sfSprite *resume_sprite;
    sfTexture *resume_texture;

    sfSprite *menu_sprite;
    sfTexture *menu_texture;

    sfSprite *exit_sprite;
    sfTexture *exit_texture;
    int scene;

} pause_t;

typedef struct vertex_s
{
    int width;
    int height;
    sfVector2u pos;
    sfRenderStates state;
    sfVertexArray *map_array;
    sfVertexArray *map_props;
    sfTexture *tiles_text;
} vertex_t;

typedef struct time_game_s
{
    sfClock *clock;
    sfTime time_clock;
    float sec;
} time_game_t;

typedef struct game_s
{
    int restart;
    window_t *window;
    menu_t *menu;
    vertex_t *vertex_map;
    vertex_t *vertex_props;
    perso_t *perso;
    zombie_t *zombie;
    time_game_t *time_game;
    pause_t *pause;
    fight_t *fight;
    sound_t *sound;
    button_ingame_t *button_ingame;
    score_t *score;
    invent_t *invent;
    rain_t *rain;
} game_t;

//music
int gest_music(game_t *game);
void set_menu_menu(game_t *game);
void set_sound_menu(game_t *game);

//sprite_menu
void game_create(game_t *game);
void create_texture_menu_next(game_t *game);
void draw_story_game(game_t *game);
void call_all_button(game_t *game);
void menu_button_start(game_t *game);
void menu_button_option(game_t *game);
void menu_button_go(game_t *game);
void menu_button_go_speak(game_t *game);
void menu_button_quit(game_t *game);
void menu_button_start_next(game_t *game);
void create_sprite_menu(game_t *game);
void create_texture_menu(game_t *game);
void set_texture_menu(game_t *game);
void draw_texture_menu(game_t *game);
void init_sprite_menu(game_t *game);

//mouve_perso
void mouve_perso_down(game_t *game);
void mouve_perso_up(game_t *game);
void mouve_perso_left(game_t *game);
void mouve_perso_right(game_t *game);
void init_rect_perso(game_t *game);
void call_all_deplacement(game_t *game);

//mouve_zombie
void anim_zombie(game_t *game);
void init_rect_zombie(game_t *game);

//fight
void open_scene_fight(game_t *game);
void create_zone_fight(game_t *game);
void create_fight(game_t *game);
void create_sprite_fight(game_t *game);
void create_texture_fight(game_t *game);
void set_texture_fight(game_t *game);
void draw_texture_fight(game_t *game);
void init_sprite_fight(game_t *game);
void anim_zombie_infight(game_t *game);
void init_rect_zombie_infight(game_t *game);
void create_sprite_fight_boss(game_t *game);
void create_texture_fight_boss(game_t *game);
void set_texture_fight_boss(game_t *game);
void draw_texture_fight_boss(game_t *game);
void init_sprite_fight_boss(game_t *game);
void fight_2(game_t *game);
void open_scene_fight_2(game_t *game);
void fight_2_in_progress(game_t *game);
void fight_2_end(game_t *game);
void fight_2_change_scene(game_t *game);
void open_scene_fight(game_t *game);
void fight_in_progress(game_t *game);
void fight_end(game_t *game);
void fight_change_scene(game_t *game);
void open_scene_fight_boss(game_t *game);
void fight_boss_in_progress(game_t *game);
void fight_boss_end(game_t *game);
void fight_boss_change_scene(game_t *game);
void gestion_scenes_fight(game_t *game);

//button_fight
void create_sprite_buttonfight(game_t *game);
void create_texture_buttoningame(game_t *game);
void set_texture_buttonfight(game_t *game);
void draw_texture_buttonfight(game_t *game);
void init_sprite_buttonfight(game_t *game);
void menu_button_attack(game_t *game);

//sprite_game
void init_sprite_game(game_t *game);
void draw_texture_game(game_t *game);
void draw_texture_game_next(game_t *game);
void set_texture_game(game_t *game);
void create_texture_game(game_t *game);
void create_sprite_game(game_t *game);
void anim_zombie2(game_t *game);
void init_rect_zombie2(game_t *game);
void init_rain_anim(game_t *game);
void animation(game_t *game);

//pause
void button_pause_in_game(game_t *game);
void draw_texture_pause(game_t *game);
void pause_in_game(game_t *game);
void set_texture_pause(game_t *game);
void create_texture_pause(game_t *game);
void create_sprite_pause(game_t *game);
void open_scene_in_game(game_t *game);
void key_moves(game_t *game);
void button_exit_in_game(game_t *game);
void analyse_events(game_t *game);

//window
void open_scene_game(game_t *game);
void analyse_events(game_t *game);
void init_window(game_t *game);
void create_window(game_t *game);
int *parsing_csv (int width, int height);
int *parsing_props_csv (int width, int height);
void declare_map(game_t *game);
vertex_t *initialisation_vertex(void);
sfVertexArray *create_vertex(vertex_t *vertex, int *parse_csv, int width,
    int height);
void tiles_info(vertex_t *vertex, sfVertexArray *vertex_tab, int *parse_csv);

//lib
char *my_strchr(const char *str, char c);
int my_strspn(const char *str, const char *accept);
int my_strcspn(const char *str, const char *reject);
char *my_strtok(char *str, const char *sep);
void my_putchar(char c);
void my_putstr(char *str);
void my_putchar_error(char c);
void my_putstr_error(char *str);
int my_strlen (char const *str);
int my_getnbr(char const *str);
char *itoa(int i, char b[]);

//damage
void damage_zombie(game_t *game, int zombie);
void damage_perso(game_t *game);

//stats
void stats_life(game_t *game);

//colision
int **itoitab(int *int_tab, int x, int y);
void get_which_tile(game_t *game);

//inventory
void inventory_init(game_t *game);
void inventory_update(game_t *game);
void inventory_render(game_t *game);
void click_invent(game_t *game);

void finishquest(game_t *game);
void startquest(game_t *game);

void animation(game_t *game);

//destroy
void destroy_menu(game_t *game);
void destroy_vertex_map(game_t *game);
void destroy_perso(game_t *game);
void destroy_zombie(game_t *game);
void destroy_time(game_t *game);
void destroy_fight(game_t *game);
void destroy_sound(game_t *game);
void destroy_score(game_t *game);
void destroy_slot(game_t *game);
void destroy_rain(game_t *game);
void destroy_all(game_t *game);
#endif /* !MY_RPG_H_ */
