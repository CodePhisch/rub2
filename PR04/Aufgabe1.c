#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    printf("Programm gestartet. Warte 3 Sekunden...\n");
    sleep(3);
    printf("Programm wird gestoppt. SIGTERM wird gesendet...\n");
    kill(getpid(), SIGTERM);
}