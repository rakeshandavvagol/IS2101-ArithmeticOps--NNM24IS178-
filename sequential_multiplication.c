#include <stdio.h>

// Function to display binary with fixed width
void printBits(int value, int width) {
    unsigned mask = 1u << (width - 1);
    for (int i = 0; i < width; i++) {
        putchar((value & mask) ? '1' : '0');
        mask >>= 1;
    }
}

// Shift-Add Multiplication (alternative style)
void multiplyShiftAdd(int X, int Y, int width) {
    int P = 0;              // Partial product register
    int N = (Y < 0) ? -Y : Y;  // Absolute multiplier
    int M = (X < 0) ? -X : X;  // Absolute multiplicand
    int k = width;          // Iteration counter

    printf("\n--- Shift-Add Multiplication ---\n");
    printf("Initial: P="); printBits(P, width);
    printf(" N="); printBits(N, width);
    printf(" M="); printBits(M, width); printf("\n\n");

    while (k > 0) {
        printf("Step %d:\n", width - k + 1);

        // Check least significant bit of multiplier
        if (N & 1) {
            P = P + M;
            printf("  LSB=1 -> Add M, P=%d\n", P);
        } else {
            printf("  LSB=0 -> No addition, P=%d\n", P);
        }

        // Shift right (combine P and N as one register)
        int combined = (P << width) | N;  // join P and N
        combined >>= 1;                   // shift right
        P = combined >> width;            // upper part back into P
        N = combined & ((1 << width) - 1); // lower part back into N

        printf("  After shift: P="); printBits(P, width);
        printf(" N="); printBits(N, width); printf("\n");

        k--;
    }

    // Combine P and N for final result
    int result = (P << width) | N;

    // Apply sign correction
    if ((X < 0) ^ (Y < 0)) {
        result = -result;
    }

    printf("Final Product = %d", result);
}

int main() {
    int a, b;
    printf("Enter first number (multiplicand): ");
    scanf("%d", &a);
    printf("Enter second number (multiplier): ");
    scanf("%d", &b);

    multiplyShiftAdd(a, b, 8);  // Using 8-bit width
    return 0;
}


