#include <stdio.h>
#include <stdlib.h>


int main() {
    printf("Starting FOMOS... \n");
    printf("\nCompiling files... \n");
    system("make all");
    printf("\nStarting UI...\n");
    system("./FOMOSUI.o");
    return 0;
}
