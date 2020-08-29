#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("\nYou are in: \n");
    system("pwd");

    FILE * fPtr;
    char fileName[50];

    printf("Enter file name: ");
    scanf("%s", fileName);

    fPtr = fopen(fileName, "w");

    if(fPtr == NULL) {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }

    fclose(fPtr);


    printf("File created successfully. \n");

    exit(0);
}
