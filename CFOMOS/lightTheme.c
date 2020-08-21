#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("U turned on light theme! \n");
    printf("Congratulations! \n");
    printf("Ur probably going blind from the bright light of ur screen! \n");

    FILE *cssFile;
    char css[50] = "#window {\n"
                   "    background-color: #EAEAEA;\n"
                   "}";


    if ( (cssFile = fopen("css/windowColor.css", "a") ) == NULL)
        printf("Cannot change to light theme \n");
        printf("Thank god that didn't work \n");
    else {
        fputs(css, cssFile);
        fclose(cssFile);
    }

    system("./restart");
}
