#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 * @n: Pointer to the number to modify.
 * @index: The index of the bit to set to 0.
 *
 * Return: 1 if the operation was successful, or -1 if an error occurred.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
    // Check if the index is out of range
    if (index >= sizeof(unsigned long int) * 8)
        return (-1);

    // Create a mask with 0 at the bit position and 1s elsewhere
    unsigned long int mask = ~(1UL << index);

    // Clear the bit at the specified index by applying the mask
    *n &= mask;

    return (1);
}

