#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *cssFile;
    char css[50] = "#window {\n"
                  "    background-color: #2B2B2B;\n"
                  "}";


    if ( (cssFile = fopen("css/windowColor.css", "w") ) == NULL)
        printf("Cannot change to dark theme");
    else {
        fputs(css, cssFile);
        fclose(cssFile);
    }

    return 0;
}
