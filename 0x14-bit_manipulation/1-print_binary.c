#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to represent in binary.
 *
 * Return: Nothing.
 */
void print_binary(unsigned long int n)
{
    // Edge case: if the number is zero, just print '0'
    if (n == 0)
    {
        _putchar('0');
        return;
    }

    // Find the most significant bit position
    unsigned long int mask = 1UL << (sizeof(n) * 8 - 1);

    // Skip leading zeros
    while ((n & mask) == 0 && mask != 0)
    {
        mask >>= 1;
    }

    // Print the binary representation
    while (mask > 0)
    {
        if (n & mask)
            _putchar('1');
        else
            _putchar('0');
        mask >>= 1;
    }
}


