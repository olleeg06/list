#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "filinghtml.h"

void Filling_the_beginning_of_html ()
{
    FILE* file_html = fopen ("dump.html", "a+");
    assert  (file_html && "file open err");

    fprintf (file_html,"%s", html_begging);

    fclose  (file_html);
}

void Filling_the_end_of_html ()
{
    FILE* file_html = fopen( "dump.html", "a+");
    assert  (file_html && "file open err");

    fprintf (file_html,"<body>\n\n");
    fprintf (file_html,"</html>");

    fclose  (file_html);
}

