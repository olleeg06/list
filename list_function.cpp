#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int poison = 333;

#include "list_function.h"
#include "dump.h"

int ListCtor (struct list* lst, size_t n){
    lst->data = (int*) calloc (n, sizeof(int));
    lst->next = (int*) calloc (n, sizeof(int));
    lst->pref = (int*) calloc (n, sizeof(int));
    lst->head = 0;
    lst->tall = 0;
    lst->free = 1;

    for (size_t i = 1; i < n; i++){
        lst->data[i] = poison;
    }

    for (size_t i = 1; i < n - 1; i++){
        lst->next[i] = i + 1;
        //printf ("next[%d] = %d\n", i, lst->next[i]);
    }   
    lst->next[n - 1] = 0;

    for (size_t i = 1; i < n; i++){
        lst->pref[i] = -1;
    }
    return 0;
}

int ListPush (struct list* lst, int x, int number){

    if (number == 0){
        if (lst->tall == 0 && lst->head == 0){
            lst->head = lst->free;
            lst->tall = lst->free;
            lst->data[lst->free] = x;
            int tmp = lst->next[lst->free];
            lst->pref[lst->free] = 0;
            lst->next[lst->free] = 0;
            lst->elem++;
            
            
            lst->free = tmp;
            

        } else {
            lst->data[lst->free] = x;
            lst->pref[lst->free] = 0;
            int tmp = lst->next[lst->free];
            lst->next[lst->free] = lst->tall;
            lst->pref[lst->tall] = lst->free;
            lst->tall = lst->free;
            lst->elem++;
            
            lst->free = tmp;
            

        }  
        
    } else if (lst->elem == number){
        lst->data[lst->free] = x;
        int tmp = lst->next[lst->free];
        lst->next[lst->free] = 0;
        lst->pref[lst->free] = lst->head;
        lst->next[lst->head] = lst->free;
        lst->head = lst->free;
        lst->elem++;
        
        lst->free = tmp;

    } else {
        int i = lst->tall;
        for (int j = 0; j != number; j++){
            i = lst->next[i];
        }

        int tmp = lst->next[lst->free];
        lst->data[lst->free] = x;
        lst->next[lst->free] = lst->next[lst->pref[i]];
        lst->next[lst->pref[i]] = lst->free;
        lst->pref[lst->free] = lst->pref[i];
        lst->pref[i] = lst->free;
        lst->elem++;
        
        lst->free = tmp;

    }


    Dump_moment (lst);
    return 0;

}

int ListDelet (struct list* lst, int number){

    if (lst->tall == lst->head){
        if (lst->head != 0){
            lst->head = 0;
            lst->tall = 0;
            lst->next[number + 1] = lst->free;
            lst->free = number + 1;
            lst->elem--;
            } else {
                printf ("you are trying to delete a non-existent element");
                exit(1);
            }
    } else if (lst->tall == number + 1){
        lst->tall = lst->next[number + 1];
        lst->data[number + 1] = poison;
        int tmp = lst->next[number + 1];
        lst->next[number + 1] = lst->free;
        lst->pref[number + 1] = -1;
        lst->free = lst->pref[tmp];
        lst->pref[tmp] = 0;
        lst->elem--;

    } else if (lst->head == number + 1){
        lst->head = lst->pref[number + 1];
        lst->data[number + 1] = poison;
        int tmp = lst->next[lst->pref[number + 1]];
        lst->next[lst->pref[number + 1]] = 0;
        lst->pref[number + 1] = -1;
        lst->next[number + 1] = lst->free;
        lst->free = tmp;
        lst->elem--;

    } else {
        lst->data[number + 1] = poison;
        lst->next[lst->pref[number + 1]] = lst->next[lst->next[number + 1]];
        int tmp = lst->pref[lst->next[number + 1]];
        lst->pref[lst->next[number + 1]] = lst->pref[number + 1];
        lst->next[number + 1] = lst->free;
        lst->pref[number + 1] = -1;
        lst->free = tmp;
        lst->elem--;
        }


    Dump_moment (lst);
    return 0;

}