//
// Created by mgcv on 10/11/23.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void goUp(char *dir){
    if(dir==NULL){
        perror("the directory passed to the goUp function was null");
    }
    size_t len = strlen(dir);
    if(len==0)
        return;
    if(dir[len-1]=='/'){
        dir[len-1]='\0';
    }
    for(size_t i=len-1; i>=0; i--){
        if(dir[i]=='/') {
            dir[i] = '\0';
            return;
        }
    }
}

int isChar(char *str){
    for(size_t i=0; i<strlen(str); i++){
        if((((int) str[i])>48) && (((int) str[i])<57) || (((int) str[i])==45)){
            continue;
        }
        return 1;
    }
    return 0;
}

void empty_str(char *str){
    for(size_t i=0; i<strlen(str); i++){
        str[i] = '\0';
    }
}