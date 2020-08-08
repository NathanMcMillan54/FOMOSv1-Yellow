#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

int printTime() {
    for (;;) {
        time_t rawtime;
        struct tm *timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        printf("%s", asctime(timeinfo));
        sleep(1);
        exit(0);
    }
}

int main() {
    printTime();
    return 0;
}
