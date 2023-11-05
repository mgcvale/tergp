//
// Created by mgcv on 11/5/23.
//

#ifndef TERGP_PLAYER_H
#define TERGP_PLAYER_H
#include "headers.h"

#define UP 105
#define LEFT 106
#define DOWN 107
#define RIGHT 108
#define NO_MOVEMENT -1
#define ESCAPE_KEY 27

#define NO_COLLISION 0
#define COLLISION_BORDER 1
#define COLLISION_WALL 2
#define COLLISION_ENEMY 3
#define COLLISION_PWUP 4

int check_collision(int movement, struct map map, struct player player1);
int move_player(int movement, struct map *map, struct player *player);


#endif //TERGP_PLAYER_H
