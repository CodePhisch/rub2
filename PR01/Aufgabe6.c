#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ascii2int(char *s) 
{
    int zahl = 0;

    // Startpointer des Strings kopieren damit dieser erhalten bleibt
    char *c = s;   

    // Tatsächliche Länge der Zahl ermitteln
    int zlength = 0;
    while(c < s + strlen(s)) 
    {
        if(*c - '0' <= 9 && *c - '0' >= 0)
        {
            zlength++;
        } else
        {
            break;
        }
        
        c++;
    }

    // Pointer auf den Anfang des Strings zurücksetzen
    c = s;

    // Variablen für Berechnung der aktuellen Zehnerpotenz
    int exp, pow;

    // Für alle Zeichen der tatsächlichen Zahl durchgehen
    while(c < s + zlength) 
    {
        // Aktuelle Stelle der Zahl ermitteln (Exponent der Zehnerpotenz)
        exp = zlength - (c - s) - 1;
        
        // Zehnerpotenz an aktueller Position ermitteln
        pow = 1;
        for(int i = 0; i < exp; i++)
        {
            pow *= 10;
        }

        zahl += pow * (*c - '0');
        c++;
    }
    
    return zahl;
}

int main()
{
    char *zahl[] = 
    {
        "53463",
        "44227 Dortmund",
        "01234"
    };

    for(int i = 0; i < sizeof(zahl) / sizeof(char *); i++)
    {
        printf("Der String '%s' ist als Integer dargestellt '%d'\n", zahl[i], ascii2int(zahl[i]));
    }

    return EXIT_SUCCESS;
}