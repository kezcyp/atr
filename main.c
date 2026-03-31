#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <iso646.h>

char* strdup(const char* oldstr)
{
    char* newstr = malloc(strlen(oldstr)+1);
    char* p;
    if(newstr == NULL) return NULL;
    p = newstr;
    while(*oldstr) *p++ = *oldstr++;
    return newstr;
}

char* roman_check(char *arabic) {
    uint8_t placement = 0; 
    char roman_number[15] = "";

    if (strlen(arabic) == 4) {
        placement = 0;
        switch (arabic[placement]) {
            case '1': strcat(roman_number, "M");   break;
            case '2': strcat(roman_number, "MM");  break;
            case '3': strcat(roman_number, "MMM"); break;
        }     
    }
    if (strlen(arabic) > 2) { 
        if (strlen(arabic) == 3)
            placement = 0;
        if (strlen(arabic) == 4)
            placement = 1;
        switch (arabic[placement]) {
            case '1': strcat(roman_number, "C");    break;
            case '2': strcat(roman_number, "CC");   break;
            case '3': strcat(roman_number, "CCC");  break;
            case '4': strcat(roman_number, "CD");   break;
            case '5': strcat(roman_number, "D");    break;
            case '6': strcat(roman_number, "DC");   break;
            case '7': strcat(roman_number, "DCC");  break;
            case '8': strcat(roman_number, "DCCC"); break;
            case '9': strcat(roman_number, "CM");   break;
        }
    }
    if (strlen(arabic) > 1) {
        if (strlen(arabic) == 2) 
            placement = 0;
        if (strlen(arabic) == 3)
            placement = 1;
        if (strlen(arabic) == 4)
            placement = 2;
        switch (arabic[placement]) {
            case '1': strcat(roman_number, "X");    break;
            case '2': strcat(roman_number, "XX");   break;
            case '3': strcat(roman_number, "XXX");  break;
            case '4': strcat(roman_number, "XL");   break;
            case '5': strcat(roman_number, "L");    break;
            case '6': strcat(roman_number, "LX");   break;
            case '7': strcat(roman_number, "LXX");  break;
            case '8': strcat(roman_number, "LXXX"); break;
            case '9': strcat(roman_number, "XC");   break;
        }
    }
    if (strlen(arabic) > 0) {
        if (strlen(arabic) == 1) 
            placement = 0;
        if (strlen(arabic) == 2) 
            placement = 1;
        if (strlen(arabic) == 3)
            placement = 2;
        if (strlen(arabic) == 4)
            placement = 3;
        switch (arabic[placement]) {
            case '1': strcat(roman_number, "I");    break;
            case '2': strcat(roman_number, "II");   break;
            case '3': strcat(roman_number, "III");  break;
            case '4': strcat(roman_number, "IV");   break;
            case '5': strcat(roman_number, "V");    break;
            case '6': strcat(roman_number, "VI");   break;
            case '7': strcat(roman_number, "VII");  break;
            case '8': strcat(roman_number, "VIII"); break;
            case '9': strcat(roman_number, "IX");   break;
        }
    }
    return strdup(roman_number); 
}

int main(int argc, char** argv) {
    for (uint8_t i = 1; i < argc; i++) {
        if (atoi(argv[i]) > 3999 or atoi(argv[i]) < 1) {
            fprintf(stderr, "number coudn't be converted to roman\n");
            exit(EXIT_FAILURE);
        }
        else {
            printf("%s", roman_check(argv[i]));
            printf("\n");
        }
    }
}

