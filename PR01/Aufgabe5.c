#include <stdio.h>
#include <stdlib.h>

void quadrat(float*);

int main() 
{
    float seitenlaenge = 3.7;
    float *zahl = &seitenlaenge;

    quadrat(zahl);

    printf("Quadrat: %f", *zahl);

    return EXIT_SUCCESS;
}

void quadrat(float *zahl)
{
    *zahl = *zahl * *zahl;
}