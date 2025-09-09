#include <stdio.h>
#include <stdlib.h>

// Print in binary (two's complement for negatives)
void showBinary(int val, int width) {
    unsigned mask = (1u << width) - 1;
    unsigned twosComp = val & mask;   // force two's complement
    for (int i = width - 1; i >= 0; i--) {
        printf("%d", (twosComp >> i) & 1);
    }
}

// Restoring Division Function
void restoringDiv(int num, int den, int bits) {
    int R = 0;                  // remainder register
    int Qreg = abs(num);        // dividend (working copy)
    int D = abs(den);           // divisor
    int cycles = bits;

    printf("Initial:\n");
    printf("R = "); showBinary(R, bits);
    printf("  Q = "); showBinary(Qreg, bits);
    printf("  D = "); showBinary(D, bits);
    printf("\n\n");

    while (cycles > 0) {
        // Left shift R:Q
        int combo = (R << bits) | Qreg;
        combo <<= 1;
        R = (combo >> bits) & ((1 << bits) - 1);
        Qreg = combo & ((1 << bits) - 1);

        // Subtract divisor
        R = R - D;

        if (R < 0) {
            // Restore remainder, set Q0 = 0
            R += D;
            Qreg &= ~1;
        } else {
            // Set Q0 = 1
            Qreg |= 1;
        }

        cycles--;
    }

    // Final quotient & remainder
    int qAns = Qreg;
    int rAns = R;

    if ((num < 0) ^ (den < 0)) {
        qAns = -qAns;
    }
    if (num < 0) {
        rAns = -rAns;
    }

    printf("Final Quotient (Decimal): %d\n", qAns);
    printf("Final Quotient (Binary) : ");
    showBinary(qAns, bits);
    printf("\n");

    printf("Final Remainder (Decimal): %d\n", rAns);
    printf("Final Remainder (Binary) : ");
    showBinary(rAns, bits);
    printf("\n");
}

int main() {
    int n, d;
    printf("Enter Dividend: ");
    scanf("%d", &n);
    printf("Enter Divisor: ");
    scanf("%d", &d);

    if (d == 0) {
        printf("Error: Division by zero not allowed.\n");
        return 1;
    }

    restoringDiv(n, d, 8);   // using 8-bit width
    return 0;
}


