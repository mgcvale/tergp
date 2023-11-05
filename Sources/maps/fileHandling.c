//
// Created by mgcv on 10/11/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../../headers/headers.h"
#include "../../headers/map.h"
#include "../../headers/lists.h"

/*Func get_map_dir: gets a number and returns the string of the directory of the map of that number, without any file extension.
 * @param n: the number of the map which directory will be gathered
 * @return *char: the directory of the file
 */

void stack_str(char *str, char ch){
    unsigned i = 0;
    while(str[i]!='\0'){
        i++;
    }
    str[i]=ch;
    str[i+1]='\0';
}

char* get_map_dir(int n){
    char nchar[2], *dir;

    nchar[0] = (char) ('0' + n);
    nchar[1] = '\0';
    dir = (char*) malloc(100*sizeof(char));

    getcwd(dir, 100);
    goUp(dir);
    strcat(dir, "/assets/maps/map");
    strcat(dir, nchar);
    return dir;
}

char **handle_level_file(int n, struct map map){
    char *dir, mapStr[25], nChar, **mapArray;
    int funcN = n;
    mapArray= (char**) malloc(50*sizeof(char*));
    for(size_t i=0; i<50; i++){
        mapArray[i] = (char*) malloc(151*sizeof(char));
    }
    FILE *mapF;
    //get the string to the level loaded in the dir variable;
    dir=get_map_dir(funcN);
    strcat(dir, ".txt");

    //open the file and check whether it has opened
    mapF = fopen(dir, "r");
    if(mapF==NULL){
        puts(dir);
        perror("Error opening map file");
        exit(EXIT_FAILURE);
    }
    //if it has successfully done so, assign to every char in the array the correspondent char in the file.
    for(size_t y=0; y<map.size.y; y++) {
        for(size_t x=0; x<map.size.x+1; x++) {
            mapArray[y][x]= (char) fgetc(mapF);
        }
    }
    fclose(mapF);
    return mapArray;
}
struct node *get_map_mdat(int n){
    char ch, *fileStr;
    FILE *mdatFile;
    int count=0, funcN=n, fileChIndex=0, fileStr_int;
    struct node *list = NULL;
    fileStr = (char*) malloc(16*sizeof(char));
    fileStr[0]='\0';

    //allocate Dir and get the directory of the mdat file
    char *dir = get_map_dir(funcN);
    strcat(dir, "_mdat.txt");

    //open the file and check for errors
    mdatFile = fopen(dir, "r");
    if(mdatFile==NULL){
        puts(dir);
        perror("Error opening mdat map file");
        exit(EXIT_FAILURE);
    }

    //get, from the file, all the chars. Every time a comma is encountered, it means it is time for the next map attribute.
    while(1){
        ch = fgetc(mdatFile);
        if((ch==',')||(ch=='.')) {
            fileStr_int = (int) strtol(fileStr, NULL, 10);
            list = insert_ord(list, &fileStr_int, NULL);
            fileStr[0]='\0';
            if(ch=='.')
                break;
            continue;
        }
        stack_str(fileStr, ch);
    }
    return list;
}
