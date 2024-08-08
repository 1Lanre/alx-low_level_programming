#include <stdlib.h>
#include "main.h"

/**
 * flip_bits - Calculates the number of bits that need to be flipped
 *             to convert number `n` to number `m`.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits that need to be flipped.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
    unsigned long int xor_result = n ^ m;
    unsigned int count = 0;

    // Count the number of set bits (1s) in xor_result
    while (xor_result)
    {
        count += (xor_result & 1);
        xor_result >>= 1;
    }

    return count;
}

