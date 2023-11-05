//
// Created by mgcv on 10/25/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../headers/lists.h"

struct node *insert_ord(struct node *list, const int *i, char *str){
    struct node *aux = list;

    if((i==NULL) && (str==NULL))
        return list;

    struct node *newList = (struct node*) malloc(sizeof(struct node));

    if(str!=NULL){
        newList->str = (char*) malloc(strlen(str)*sizeof(char));
        strcpy(newList->str, str);
    }
    if(i!=NULL){
        newList->i=*i;
    }
    if(list!=NULL){
        while(aux->next!=NULL){
            aux=aux->next;
        }
        aux->next=newList;
    }else{
        list=newList;
    }
    return list;
}

char *str_read(struct node *list, int index){
    int k=0;
    struct node* aux=list;

    while(k!=index){
        if(aux!=NULL){
            return NULL;
        }
        aux=aux->next;
        k++;
    }
    return aux->str;
}

int int_read(struct node *list, int index){
    int k=0;
    struct node *aux=list;

    while(k!=index){
        if(aux!=NULL){
            return 0;
        }
        aux=aux->next;
        k++;
    }
    return aux->i;
}

void print_lst(struct node *list){
    for(struct node *aux=list; aux!=NULL; aux=aux->next){
        if(aux->i!=-999)
            printf("%i\n", aux->i);
        if(aux->str!=NULL)
            printf("%s\n", aux->str);
    }
}

struct node *pop(struct node *list, int *i, char *ch){
    if(list==NULL){
        perror("Error: trying to pop an empty list");
    }

    struct node *newList=list->next;
    if(list->str!=NULL){
        if(ch!=NULL) {
            ch = (char *) malloc(strlen(list->str) * sizeof(char));
            strcpy(ch, list->str);
        }
    }
    if(i!=NULL) {
        *i = list->i;
    }
    return newList;
}