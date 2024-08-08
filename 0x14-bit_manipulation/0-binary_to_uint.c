#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: The binary string to convert.
 *
 * Return: The positive number converted from a binary string,
 *         or 0 if the input is NULL or contains invalid characters.
 */
unsigned int binary_to_uint(const char *b)
{
    unsigned int result = 0;
    int i = 0;

    if (b == NULL)
        return (0);

    while (b[i] != '\0')
    {
        if (b[i] != '0' && b[i] != '1')
            return (0);

        result = (result << 1) | (b[i] - '0');
        i++;
    }

    return (result);
}

