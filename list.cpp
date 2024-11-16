#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "list_function.h"
#include "filinghtml.h"


int main(){
    list lst = {};
    Filling_the_beginning_of_html ();
    ListCtor (&lst, SIZE_LIST);

    ListPush (&lst, 10, 0);
    ListPush (&lst, 20, 0);
    ListPush (&lst, 52, 2);
    ListPush (&lst, 40, 1);
    ListDelet (&lst, 1);
    ListDelet (&lst, 2);

    
    Filling_the_end_of_html ();
}
