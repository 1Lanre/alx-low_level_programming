#include "main.h"

/**
 * get_endianness - Checks the endianness of the system.
 *
 * Return: If the system is big-endian - 0.
 *         If the system is little-endian - 1.
 */
int get_endianness(void)
{
    // Create a 16-bit integer with a known value
    unsigned int value = 0x1;
    
    // Check the least significant byte
    unsigned char *byte = (unsigned char *)&value;

    // If the least significant byte is 0x1, it's little-endian
    return (*byte == 0x1);
}

