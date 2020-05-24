#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 4096

int main(int argc, char *args[]) {
  int   pipeA[2], pipeB[2];
  pid_t pid;
   
  

  // Pipes erzeugen
  if(pipe(pipeA) < 0 || pipe(pipeB) < 0) {
    perror("pipe error");
    exit(1);
  }

  pid = fork();
  if (pid < 0) {
    perror("fork error");
    exit(1);
  }     
  
  else if (pid > 0) {           /* parent */
    char readLine[MAXLINE];

    close(pipeA[0]);
    close(pipeB[1]);

    write(pipeA[1], args[1], strlen(args[1]));
    read(pipeB[0], readLine, MAXLINE);
    printf("Im Elternprozess empfangen: %s", readLine);

    wait(NULL);
  } 
  else {                        /* child */
    char readLine[MAXLINE];

    close(pipeA[1]);
    close(pipeB[0]);

    read(pipeA[0], readLine, strlen(args[1]));
    for(int i = 0; i < strlen(readLine); i++) {
        readLine[i] = toupper(readLine[i]);
    }

    sleep(1);

    write(pipeB[1], read, MAXLINE);
  }
  wait(NULL);
  return 0;
}