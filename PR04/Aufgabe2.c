#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int signal) {
    if(signal == SIGTERM) puts("SIGTERM");
    else if(signal == SIGINT) puts("SIGINT");
}

int main(void) {
    signal(SIGTERM, handler);
    signal(SIGINT, handler);

    for( ; ; ) {
        pause();
        puts("main: Signal empfangen");
    }
}