#ifndef LIST_FUNCTION_H
#define LIST_FUNCTION_H
#include <stdio.h> 

int ListCtor (struct list* lst, size_t n);
int ListPush (struct list* lst, int x, int number);
int ListDelet (struct list* lst, int number);

#define SIZE_LIST 10

struct list {
    int* data;
    int* next;
    int* pref;
    size_t free;
    size_t head;
    size_t tall;
    size_t elem;
};



#endif