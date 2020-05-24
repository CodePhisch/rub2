#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Pipe erzeugen
    int fd[2];
    pipe(fd);
    printf("FD1: %d FD2: %d\n", fd[0], fd[1]);

    // Schreiben
    char testWrite[] = "Test";
    write(fd[1], testWrite, 4); 
    printf("WRITE: %s\n", testWrite);

    // Lesen
    char testRead[5];
    read(fd[0], testRead, 4);
    printf("READ: %s\n", testRead);

    // Pipe schließen
    close(fd[0]);
    close(fd[1]);
}