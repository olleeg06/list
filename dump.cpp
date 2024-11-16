#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>
#include <iostream>
#include <assert.h>

#include "list_function.h"
#include "dump.h"

void Dump_moment (struct list* lst)
{
    assert (lst);

    struct timeval tv;
    gettimeofday (&tv, NULL);
    long seconds = tv.tv_sec;
    long microseconds = tv.tv_usec;

    char filename[SIZE_FILENAME] = {0};
    snprintf (filename, sizeof(filename), "file_%ld_%06ld.dot",  seconds, microseconds);
    
    FILE* file_html = fopen ("dump.html", "a+");
    assert (file_html && "file open err");

    FILE* file_dump = fopen (filename, "a+");
    assert (file_dump && "file open err");
    
    fprintf (file_dump, "%s", adding_html_first);
    
    for (int i = 0; i < SIZE_LIST; i++)
    {
        fprintf (file_dump,"node%d [shape=record,label=\"{ip: %d|<f1> data: %d | <f2> next: %d | <f3> prev: %d}\"];\n", i, i,
        lst->data[i], 
        lst->next[i], lst->pref[i]);
    }

    fprintf (file_dump, "\n");

    for (int i = 1; i < SIZE_LIST - 1; i++)
    {
        fprintf (file_dump, "node%d:f2 -> node%d:f1;\n", i, lst->next[i]);
    }

    char command[SIZE_COMMAND] = {};
    snprintf(command, sizeof(command), "dot -Tpng %s -o %.22s.png", filename, filename);
    snprintf(filename, sizeof(filename), "file_%ld_%06ld.png",  seconds, microseconds);
    
    fprintf(file_html, "\t<img src=\"%s\"/>\n", filename);
    fprintf(file_dump, "free -> node%d\n", lst->free);
    fprintf(file_dump, "head -> node%d\n", lst->head);
    fprintf(file_dump, "tail -> node%d\n", lst->tall);
    fprintf(file_dump, "{ rank = same; node0; node1; node2; node3; node4; node5; node6; node7; node8; }\n");
    fprintf(file_dump, "}\n");
    
    fclose(file_dump);
    
    system(command);
    
    fclose(file_html);
}