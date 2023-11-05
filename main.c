#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "headers/headers.h"
#include "headers/map.h"
#include "headers/player.h"

int main(int argc, char *argv[]){
    int n=1, key, coll;
    char str[10];
    if(argc!=1){
        n=atoi(argv[1]);
    }

    struct player player1;

    //init all the stuff (map, mdat, playerPos etc
    struct map map1;
    map1.defaultScreen = initScreen();
    map1.mapInfo = get_map_mdat(n);
    map1 = proc_list(map1);
    map1.mapArray = handle_level_file(n, map1);
    spawn_player(&map1, map1.spawnpoint, &player1);
    map1.currentScreen = map1.defaultScreen;


    initscr();
    key = getch();
    do{
        clear();
        addstr("last move: ");
        sprintf(str, "%i", player1.lastMove); addstr(str); addch('\n');
        print_map_curses(map1);
        key=getch();
        coll = move_player(key, &map1, &player1);
        map1.currentScreen = update_screen_live(map1, &player1);
        if(coll==COLLISION_ENEMY){
            break;
        }
        refresh();
    }while(key!=ESCAPE_KEY);
    endwin();
    clear();
    system("clear");
    printf("perdeu\n\n");
    return 0;
}