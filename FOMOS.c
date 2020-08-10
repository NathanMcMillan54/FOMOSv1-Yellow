#include <stdio.h>
#include <stdlib.h>


int main() {
    printf("Starting FOMOS... \n");
    printf("\nCompiling files... \n");
    system("sh power/compile.sh");
    printf("\nStarting UI...\n");
    system("sh ui/compile.sh");
    system("./ui/FOMOSUI");
    return 0;
}
