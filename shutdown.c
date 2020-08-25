#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Shutting down...");
    system("shutdown -P now");
    exit(0);
    /* as i (Nathan McMillan) was rewriting this i realized
     * that it's weird how i was using js a frontend language
     * to call a shellscript now im using c a language used for
     * interacting with the os and hardware to call a shellscript
     * but in FOMOSv2 i use nothing but c for shutdown idk why i
     * wrote this comment i just got bored */
    /* but i just don't know why ur still reading this comment
     * go back to work! */
}
