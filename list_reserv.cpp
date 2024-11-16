#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int ListCtor (struct list* lst, size_t n);
int ListPush (struct list* lst, int x, int number);
int ListDump (struct list lst);
int ListDelet (struct list* lst, int number);

struct list {
    int* data;
    int* next;
    int* pref;
    size_t free;
    size_t head;
    size_t tall;
    size_t elem;
};

int poison = -52333;


int main(){
    list lst = {};

    ListCtor (&lst, 100);

    ListPush (&lst, 10, 0);
    ListDump (lst);
    ListPush (&lst, 20, 1);
    ListDump (lst);
    ListDelet (&lst, 2);
    ListDump (lst);
    ListPush (&lst, 52, 1);

    
    ListDump (lst);
}


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
    }   
    lst->next[n - 1] = 0;

    for (size_t i = 1; i < n; i++){
        lst->pref[i] = -1;
    }

}

int ListPush (struct list* lst, int x, int number){
                                                                    //assert num poison in list!!!

    if (number == 0){
        if (lst->tall == 0 && lst->head == 0){
            lst->head = lst->free;
            lst->tall = lst->free;
            lst->data[lst->free] = x;
            lst->pref[lst->free] = 0;
            lst->next[lst->free] = 0;
            lst->elem++;
            printf ("{%d} head = tall = 0, data = %d, next = %d, pref = %d\n", lst->free, lst->data[lst->free], lst->next[lst->free], lst->pref[lst->free]);
            size_t i = 1;
            while (lst->data[i] != poison) i++;
            lst->free = i;
            printf ("new free = %d\n\n", lst->free);
        } else {
            lst->data[lst->free] = x;
            lst->pref[lst->free] = 0;
            lst->next[lst->free] = lst->tall;
            lst->pref[lst->tall] = lst->free;
            lst->tall = lst->free;
            lst->elem++;
            printf ("{%d} x <= tall, data = %d, next = %d, pref = %d\n", lst->free, lst->data[lst->free], lst->next[lst->free], lst->pref[lst->free]);
            size_t i = 1;
            while (lst->data[i] != poison) i++;
            lst->free = i;
        }  
        
    } else if (number == lst->head){
        lst->data[lst->free] = x;
        lst->next[lst->free] = 0;
        lst->pref[lst->free] = lst->head;
        lst->next[lst->head] = lst->free;
        lst->head = lst->free;
        lst->elem++;
        printf ("{%d} x >= head, data = %d, next = %d, pref = %d\n", lst->free, lst->data[lst->free], lst->next[lst->free], lst->pref[lst->free]);
        size_t i = 1;
        while (lst->data[i] != poison) i++;
        lst->free = i;
        printf ("new free = %d\n\n", lst->free);

    } else {
        int i = lst->tall;
        for (int j = 0; j != number; j++){
            i = lst->next[i];
            //printf ("\t\tj = %d, i = %d\t\t\n", j, i);
        }

        lst->data[lst->free] = x;
        lst->next[lst->free] = lst->next[lst->pref[i]];
        lst->next[lst->pref[i]] = lst->free;
        lst->pref[lst->free] = lst->pref[i];
        lst->pref[i] = lst->free;
        lst->elem++;
        printf ("{%d} data = %d, next = %d, pref = %d\n", lst->free, lst->data[lst->free], lst->next[lst->free], lst->pref[lst->free]);
        printf ("new free = %d\n\n", lst->free);
        i = 1;
        while (lst->data[i] != poison) i++;
        lst->free = i;
        

    }
}

int ListDelet (struct list* lst, int number){
    
    if (1) {                                       //////////

    }
    if (lst->tall == lst->head){
        lst->data[number] = poison;
        lst->pref[number] = -1;
        lst->free = number;
        lst->next[number] = number + 1;
    }
    else {
        lst->data[number] = poison;
        lst->pref[lst->next[number]] = lst->pref[number];
        lst->next[lst->pref[number]] = lst->next[number];
        lst->next[number] = lst->free;
        lst->pref[number] = -1;
        lst->free = number;
    }

}


int ListDump (struct list lst){
    printf ("------------------------------------\n");
    //printf ("tall = %d, head = %d\n", lst.tall, lst.head);
    for (size_t i = lst.tall; i != 0; i = lst.next[i]){
        printf ("elem {%d} = %d\n", i, lst.data[i]);
        //printf ("next = %d, pref = %d\n\n", lst.next[i], lst.pref[i]);
    }
    printf ("------------------------------------\n");
}