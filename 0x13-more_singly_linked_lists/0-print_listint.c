#include "lists.h"
#include <stdio.h>

/**
 * print_listint - Outputs all the values of a listint_t list.
 * @h: Pointer to the beginning of the listint_t list.
 *
 * Return: Total number of nodes in the listint_t list.
 */
size_t print_listint(const listint_t *h)
{
    size_t count = 0;

    while (h != NULL)
    {
        printf("%d\n", h->n);
        count++;
        h = h->next;
    }

    return count;
}

