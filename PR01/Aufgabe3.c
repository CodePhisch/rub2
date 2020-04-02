#include <stdio.h>
#include <ctype.h>
#include <string.h>

void to_upper_case(char in[], char out[]) 
{
    char *input = in;

    while(in < input + strlen(input)) 
    {
        *out = toupper(*in);
        out++;
        in++;
    }
}

int main() 
{
    char input[30] = "a-6430 ötztal-bahnhof";
    char output[30];

    printf("Orginal: %s\n", input);

    to_upper_case(input, output);

    printf("Umgewandelt: %s\n", output);
}