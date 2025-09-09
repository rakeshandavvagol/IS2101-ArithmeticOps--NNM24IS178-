#include <stdio.h>

// Utility: show binary representation
void showBits(int value, int width) {
    unsigned mask = 1u << (width - 1);
    for (int i = 0; i < width; i++) {
        putchar((value & mask) ? '1' : '0');
        mask >>= 1;
    }
}

// Non-restoring division algorithm
void nonRestoringDivide(int dividend, int divisor, int width) {
    int remainder = 0;
    int quotient  = dividend;
    int divisorCopy = divisor;

    printf("\n--- Non-Restoring Division ---\n");
    printf("Initial: R="); showBits(remainder, width + 1);
    printf(" Q="); showBits(quotient, width);
    printf(" D="); showBits(divisorCopy, width); printf("\n\n");

    for (int step = 1; step <= width; step++) {
        // Left shift (remainder:quotient)
        remainder = (remainder << 1) | ((quotient >> (width - 1)) & 1);
        quotient  = (quotient << 1) & ((1 << width) - 1);

        printf("Step %d after shift: R=", step); showBits(remainder, width + 1);
        printf(" Q="); showBits(quotient, width); printf("\n");

        // Decision: subtract or add divisor
        if (remainder >= 0) {
            remainder -= divisorCopy;
            if (remainder >= 0) quotient |= 1;
        } else {
            remainder += divisorCopy;
            if (remainder >= 0) quotient |= 1;
        }

        printf("        after op:    R="); showBits(remainder, width + 1);
        printf(" Q="); showBits(quotient, width); printf("\n\n");
    }

    // Final correction
    if (remainder < 0) remainder += divisorCopy;

    printf("Final Quotient = "); showBits(quotient, width); printf(" (%d)\n", quotient);
    printf("Final Remainder = "); showBits(remainder, width + 1); printf(" (%d)\n", remainder);
}

int main() {
    int num, div, bits;

    printf("Enter dividend: ");
    scanf("%d", &num);
    printf("Enter divisor: ");
    scanf("%d", &div);
    printf("Enter number of bits: ");
    scanf("%d", &bits);

    if (div== 0) {
        printf("Error: divisor cannot be zero!\n");
        return 1;
    }

    nonRestoringDivide(num, div, bits);
    return 0;
}
