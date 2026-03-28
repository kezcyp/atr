#include <stdint.h>
#include <stdio.h>

char atr_arabictoroman(uint16_t arabic) {
    if (arabic > 3999 && arabic < 1) {
        return 'h';
    }
}
