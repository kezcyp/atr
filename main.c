#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "atr.h"

int main(int argc, char** argv) {
    int ArabicNum = atoi(argv[1]);
    printf("%s %d %c\n", argv[0], ArabicNum, atr_arabictoroman(4200));
}
