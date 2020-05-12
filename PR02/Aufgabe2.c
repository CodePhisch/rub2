#include <stdio.h> 
#include <stdlib.h> 

long fakul(long);

int main(int argc, char *args[]) {
  long zahl; 
 
  zahl = atol(args[1]);
  printf("Zahl: %ld \n",zahl);
  printf("Ergebnis: %lu\n", fakul(zahl));

  return EXIT_SUCCESS; 
} 

long fakul(long zahl) { 
  if (zahl == 0) 
    return 1; 
  else 
    return fakul(zahl - 1) * zahl;
}