#ifndef DUMPIK_H
#define DUMPIK_H

const int SIZE_FILENAME = 100;
const int SIZE_COMMAND = 256; 
const char adding_html_first[] = "\n"
                                "digraph structs {\n"
                                "charset = \"UTF-8\";\n"
                                "rankdir=TB;\n"
                                "bgcolor = \"#0000aa\";\n"
                                "fontcolor = black;\n"
                                "fontsize = 18;\n"
                                "style = \"rounded\";\n"
                                "margin = 0.3;\n"
                                "splines = ortho;\n"
                                "ranksep = 1.0;\n"
                                "nodesep = 0.9;\n"
                                "bgcolor = \"#8ED2EB\";\n"
                                "edge [color=\"#96080C\"];\n"
                                "\n";

void Dump_moment (struct list* list);

#endif // DUMPIK_H