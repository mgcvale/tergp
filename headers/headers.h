//
// Created by mgcv on 11/5/23.
//

#ifndef TERGP_HEADERS_H
#define TERGP_HEADERS_H
#include "lists.h"

struct point{
    int x;
    int y;
};
struct screen{
    struct point start;
    struct point end;
};
struct map{
    char *mapName;
    char **mapArray;
    struct point spawnpoint;
    struct point size;
    struct screen currentScreen;
    struct screen defaultScreen;
    struct node *mapInfo;
    struct point sUpdatePos;
};
struct player{
    struct point playerPos;
    int lastMove;
};

void print_map(struct map map);
void print_map_curses(struct map map);
struct screen initScreen();
int mainG();
void goUp(char* dir);
int isChar(char *str);
void empty_str(char *str);
char *get_map_dir(int n);
char **handle_level_file(int n, struct map map);
struct node *get_map_mdat(int n);
struct map proc_list(struct map map);
void spawn_player(struct map *map, struct point sp, struct player *player);
struct screen update_screen_live(struct map map, struct player *player);


#endif //TERGP_HEADERS_H
