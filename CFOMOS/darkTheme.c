#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *cssFile;
    char css[150] = "#window {\n"
                   "    background-color: #2B2B2B;\n"
                   "}\n"
                   "\n"
                   "#time {\n"
                   "    color: #ffffff;\n"
                   "}\n"
                   "\n"
                   "#text {\n"
                   "    color: #ffffff;\n"
                   "}";


    if ( (cssFile = fopen("css/lightDarkTheme.css", "w") ) == NULL)
        printf("Cannot change to dark theme");
    else {
        fputs(css, cssFile);
        fclose(cssFile);
    }

    return 0;
}
