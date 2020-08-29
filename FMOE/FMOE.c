#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int makeAFile() {
    system("./makeFile");
    return 0;
}

int editAFile() {
    system("./editFile");
    return 0;
}

int openAFile() {
    system("./openFile");
    return 0;
}

int help() {
    system("./help");
    return 0;
}

int aQ() {

    char MOE[50];
    printf("\nEnter M, O, or E\n");
    printf("");
    scanf("%s", MOE);
    if(!strcmp(MOE, "help")) {
        help();
    } else if (!strcmp(MOE, "O")) {
        openAFile();
    } else if (!strcmp(MOE, "M")) {
        makeAFile();
    } else if (!strcmp(MOE, "E")) {
        editAFile();
    } else if (!strcmp(MOE, "exit")) {
        exit(0);
    }
    else {
        printf("Enter M, O, or E \n");
    }

    return 0;
}

int main() {
    printf("________\n");
    printf("| FMOE |\n");
    printf("--------\n");
    printf("The text editor for FOMOS and GNU \n\n");

    for (;;) {
        aQ();
    }

}
