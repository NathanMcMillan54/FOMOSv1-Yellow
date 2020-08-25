#include <stdio.h>
#include <stdlib.h>


int main() {
    printf("Starting FOMOS... \n");
    printf("\nCompiling files... \n");
    system("sh compile.sh");
    printf("\nStarting UI...\n");
    system("./FOMOSUI");
    return 0;
}
