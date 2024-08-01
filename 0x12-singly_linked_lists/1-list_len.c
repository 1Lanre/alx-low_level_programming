#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * list_len - Computes the total number of nodes in a linked list.
 * @head: Pointer to the start of the linked list.
 *
 * Return: The number of nodes in the linked list.
 */
size_t list_len(const list_t *head)
{
    size_t node_count = 0;

    for (const list_t *current = head; current != NULL; current = current->next)
    {
        node_count++;
    }

    return node_count;
}

