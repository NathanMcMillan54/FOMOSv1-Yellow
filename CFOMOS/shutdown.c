#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Shutting down...");
    system("shutdown -P now");
    exit(0);
}
