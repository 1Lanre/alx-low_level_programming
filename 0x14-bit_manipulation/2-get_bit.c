#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * get_bit - Gets the value of a bit at a given index.
 * @n: The number to find the bit from.
 * @index: The index of the bit to find.
 *
 * Return: The value of the bit at the given index, or -1 if the index is out of range.
 */
int get_bit(unsigned long int n, unsigned int index)
{
    // Check if the index is within the valid range of bit positions
    if (index >= sizeof(n) * 8)
        return (-1);

    // Right shift n by index bits and check the least significant bit
    return ((n >> index) & 1);
}

