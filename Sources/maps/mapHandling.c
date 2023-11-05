//
// Created by mgcv on 10/11/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "../../headers/map.h"
#include "../../headers/headers.h"

extern struct player player1;

//map stuff
struct screen initScreen(){
    struct screen retScreen;
    retScreen.start.y=0;
    retScreen.start.x=0;
    return retScreen;
};

void print_map(struct map map) {
    if((map.currentScreen.end.x>map.size.x) || (map.currentScreen.end.y>map.size.y)){
        printf("Error printing map: Screen is bigger than map size: (%i, %i), (%i, %i)", map.size.x, map.size.y, map.currentScreen.end.x, map.currentScreen.end.y);
        exit(EXIT_FAILURE);
    }
    for (unsigned int y=map.currentScreen.start.y; y<map.currentScreen.end.y; y++){
        for(unsigned int x=map.currentScreen.start.x; x<map.currentScreen.end.x; x++) {
            printf("%c", map.mapArray[y][x]);
        }
        printf("\n");
    }
}

void print_map_curses(struct map map){
    if((map.currentScreen.end.x>map.size.x) || (map.currentScreen.end.y>map.size.y)){
        printf("Error printing map: Screen is bigger than map size: (%i, %i), (%i, %i)", map.size.x, map.size.y, map.currentScreen.end.x, map.currentScreen.end.y);
        exit(EXIT_FAILURE);
    }
    for (unsigned int y=map.currentScreen.start.y; y<map.currentScreen.end.y; y++){
        for(unsigned int x=map.currentScreen.start.x; x<map.currentScreen.end.x; x++) {
            addch(map.mapArray[y][x]);
        }
        addch('\n');
    }
}

//mdat stuff
struct map proc_list(struct map map){
    struct node *list = map.mapInfo;
    int n;
    //map size
    if((list==NULL)||(list->next==NULL)) {
        puts("Failed extracting map size from mdat stack.");
        return map;
    }
    list = pop(list, &map.size.x, NULL);
    list = pop(list, &map.size.y, NULL);

    //map screen
    if((list==NULL)||(list->next==NULL)){
        puts("Failed extracting map screen from mdat stack.");
        return map;
    }
    list = pop(list, &map.defaultScreen.end.x, NULL);
    list = pop(list, &map.defaultScreen.end.y, NULL);

    if((list==NULL)||(list->next==NULL)){
        puts("Failed extracting player spawn-point from mdat stack.");
        return map;
    }
    list = pop(list, &map.spawnpoint.x, NULL);
    list = pop(list, &map.spawnpoint.y, NULL);

    if((list==NULL) || (list->next==NULL)){
        puts("Failed extracting minimum threshold for updating string from mdat stack.");
        return map;
    }

    list = pop(list, &map.sUpdatePos.x, NULL);
    list = pop(list, &map.sUpdatePos.y, NULL);

    return map;
}

void spawn_player(struct map *map, struct point sp, struct player *player){
    map->mapArray[sp.y][sp.x]='o';
    player->playerPos.y = sp.y;
    player->playerPos.x = sp.x;
}