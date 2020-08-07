#include <time.h>
#include <stdio.h>
#include <unistd.h>

int showTime() {
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf("Date and time: %s", asctime(timeinfo));
    return 0;
}

int main() {
    for (;;) {
        showTime();
        sleep(1);
    }
}
