#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fileName;
    char IFileName[14] = "editFile.txt";
    char I2File[9999];
    char space[2] = "\n";

    printf("\nYou are in: \n");
    system("pwd");

    printf("Add to file: ");
    scanf("%[^\n]", I2File);

    printf("Enter file name: ");
    scanf("%s", IFileName);


    if ( (fileName = fopen(IFileName, "a") ) == NULL)
        printf("Cannot open file.");
    else {
        fputs(space, fileName);
        fputs(I2File, fileName);
        fclose(fileName);
    }

    return 0;
}
