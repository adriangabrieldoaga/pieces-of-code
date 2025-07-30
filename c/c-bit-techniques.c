#include <stdio.h>

void print_Binary(int n)
{
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

int main()
{
    int n1; // 42 in binary: 101010
    int n2; // 15 in binary: 1111
    int k;

    printf("Initial value of n1: ");
    scanf("%d", &n1);
    printf("Initial value of n2: ");
    scanf("%d", &n2);
    printf("Bit position (0-based): ");
    scanf("%d", &k);
    printf("\n");
    printf("Binary representation of n1: ");
    print_Binary(n1);
    printf("Binary representation of n2: ");
    print_Binary(n2);

    // Test if the k-th bit is set
    if (n1 & (1 << k))
    {
        printf("The %d-th bit is set.\n", k);
    }
    else
    {
        printf("The %d-th bit is not set.\n", k);
    }

    // Set the k-th bit
    n1 |= (1 << k);
    printf("After setting the %d-th bit: %d\n", k, n1);
    printf("Binary representation of n1: ");
    print_Binary(n1);

    // Toggle the k-th bit
    n1 &= ~(1 << k);
    printf("After toggling the %d-th bit: %d\n", k, n1);
    printf("Binary representation of n1: ");
    print_Binary(n1);

    // Turn on the k-th bit
    n1 ^= (1 << k);
    printf("After turning on the %d-th bit: %d\n", k, n1);
    printf("Binary representation of n1: ");
    print_Binary(n1);

    // Multiply by 2^k
    int multiplied = n1 << k;
    printf("After multiplying by 2^%d: %d\n", k, multiplied);

    // Divide by 2^k
    int divided = n1 >> k;
    printf("After dividing by 2^%d: %d\n", k, divided);

    // Check if n1 is a power of 2 using (n1 & (n1 - 1)) == 0
    if ((n1 & (n1 - 1)) == 0)
    {
        printf("%d is a power of 2 (method 1).\n", n1);
    }
    else
    {
        printf("%d is not a power of 2 (method 1).\n", n1);
    }

    // Check if n1 is a power of 2 using (n1 & (-n1)) == n1
    if ((n1 & (-n1)) == n1)
    {
        printf("%d is a power of 2 (method 2).\n", n1);
    }
    else
    {
        printf("%d is not a power of 2 (method 2).\n", n1);
    }

    // Swap two variables using bitwise XOR
    printf("\nBefore swapping: n1 = %d, n2 = %d\n", n1, n2);
    n1 ^= n2;
    n2 ^= n1;
    n1 ^= n2;
    printf("After swapping: n1 = %d, n2 = %d\n", n1, n2);

    return 0;
}

/*
Input and output example:
Initial value of n1: 42
Initial value of n2: 15
Bit position (0-based): 3

Binary representation of n1: 00000000000000000000000000101010
Binary representation of n2: 00000000000000000000000000001111
The 3-th bit is set.
After setting the 3-th bit: 42
Binary representation of n1: 00000000000000000000000000101010
After toggling the 3-th bit: 34
Binary representation of n1: 00000000000000000000000000100010
After turning on the 3-th bit: 42
Binary representation of n1: 00000000000000000000000000101010
After multiplying by 2^3: 336
After dividing by 2^3: 5
42 is not a power of 2 (method 1).
42 is not a power of 2 (method 2).

Before swapping: n1 = 42, n2 = 15
After swapping: n1 = 15, n2 = 42

*/
