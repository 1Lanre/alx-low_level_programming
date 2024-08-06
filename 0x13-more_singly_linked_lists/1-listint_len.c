#include "lists.h"
#include <stdio.h>

/**
 * listint_len - Counts the number of nodes in a linked listint_t list.
 * @h: Pointer to the start of the listint_t list.
 *
 * Return: The total number of nodes in the listint_t list.
 */
size_t listint_len(const listint_t *h)
{
    size_t count = 0;

    while (h != NULL)
    {
        count++;
        h = h->next;
    }

    return count;
}

