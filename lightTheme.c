#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("U turned on light theme! \n");
    printf("Congratulations! \n");
    printf("Ur probably going blind from the bright light of ur screen! \n");

    FILE *cssFile;
    char css[150] = "#window {\n"
                    "    background-color: #B2B2B2;\n"
                    "}\n"
                    "\n"
                    "#time {\n"
                    "    color: #000000;\n"
                    "}\n"
                    "\n"
                    "#text {\n"
                    "    color: #000000;\n"
                    "}";



    if ( (cssFile = fopen("css/lightDarkTheme.css", "w") ) == NULL)
        printf("Cannot change to light theme \n");
    else {
        fputs(css, cssFile);
        fclose(cssFile);
    }

    return 0;
}
