#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index.
 * @n: Pointer to the number to modify.
 * @index: The index of the bit to set to 1.
 *
 * Return: 1 if the operation was successful, or -1 if an error occurred.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
    // Check if the index is out of range
    if (index >= sizeof(unsigned long int) * 8)
        return (-1);

    // Set the bit at the specified index to 1
    *n |= (1UL << index);

    return (1);
}

