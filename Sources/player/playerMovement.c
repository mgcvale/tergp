//
// Created by mgcv on 10/30/23.
//
#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include "../../headers/player.h"
#include "../../headers/headers.h"

//checks for collisions based on the movement made
int AUX_check_coll_type(char ch){
    switch (ch){
        case '|':
        case '-':
            return COLLISION_WALL;
        case 'x':
            return COLLISION_ENEMY;
        case 'u':
            return COLLISION_PWUP;
        case ' ':
            return NO_COLLISION;
        default:
            perror("Error handling collision detection");
    }
}

int check_collision(int movement, struct map map, struct player player1){
    char ch;
    switch(movement){
        case UP:
            //check collision with a border
            if(player1.playerPos.y-1==0)
                return COLLISION_BORDER;
            //set the char to be checked
            ch = map.mapArray[player1.playerPos.y-1][player1.playerPos.x];
            //check the char
            return AUX_check_coll_type(ch);
        case DOWN:
            if(player1.playerPos.y+1==map.size.y)
                return COLLISION_BORDER;
            ch = map.mapArray[player1.playerPos.y+1][player1.playerPos.x];
            return AUX_check_coll_type(ch);
        case LEFT:
            if(player1.playerPos.x-1==0)
                return COLLISION_BORDER;
            ch = map.mapArray[player1.playerPos.y][player1.playerPos.x-1];
            return AUX_check_coll_type(ch);
        case RIGHT:
            if(player1.playerPos.x+1==map.size.x)
                return COLLISION_BORDER;
            ch = map.mapArray[player1.playerPos.y][player1.playerPos.x+1];
            return AUX_check_coll_type(ch);
        default:
            perror("Error: invalid movement command passed to collision checker");
    }
}

int move_player(int movement, struct map *map, struct player *player){
    int coll;
    coll = check_collision(movement, *map, *player);

    if(coll!=NO_COLLISION && coll!=COLLISION_PWUP){
        player->lastMove = NO_MOVEMENT;
        return coll;
    }

    player->lastMove = movement;

    map->mapArray[player->playerPos.y][player->playerPos.x] = ' ';
    switch(movement){
        case UP:
            player->playerPos.y--;
            break;
        case LEFT:
            player->playerPos.x--;
            break;
        case DOWN:
            player->playerPos.y++;
            break;
        case RIGHT:
            player->playerPos.x++;
            break;
        default:
            perror("Invalid player movement input");
            return coll;
    }
    map->mapArray[player->playerPos.y][player->playerPos.x] = 'o';
    return coll;
}

struct screen update_screen_live(struct map map, struct player *player){
    //first, check if the player is in range of

    switch(player->lastMove){
        case UP:
        case DOWN:
            if(player->playerPos.y>map.sUpdatePos.y) {
                map.currentScreen.start.y = player->playerPos.y - map.sUpdatePos.y-1;
                map.currentScreen.end.y = map.currentScreen.start.y + map.defaultScreen.end.y;
                return map.currentScreen;
            }
        case LEFT:
        case RIGHT:
            if(player->playerPos.x>map.sUpdatePos.x) {
                map.currentScreen.start.x = player->playerPos.x - map.sUpdatePos.x-1;
                map.currentScreen.end.x = map.currentScreen.start.x + map.defaultScreen.end.x;
                return map.currentScreen;
            }
    }

    return map.currentScreen;
}


