//
// Created by mgcv on 11/5/23.
//

#ifndef TERGP_LISTS_H
#define TERGP_LISTS_H

struct node{
    int i;
    char *str;
    struct node *next;
};

struct node *insert_ord(struct node *list, const int *i, char *str);
char *str_read(struct node *list, int index);
int int_read(struct node *list, int index);
void print_lst(struct node *list);
struct node *pop(struct node *list, int *i, char *ch);


#endif //TERGP_LISTS_H
