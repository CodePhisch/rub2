#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ascii2int(char *s) 
{
    int zahl = 0;

    for(int i = 0; s[i] <= '9' && s[i] >= '0'; i++) {
        zahl = zahl * 10 + (s[i] - '0');
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