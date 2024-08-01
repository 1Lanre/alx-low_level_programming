#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_list - Outputs each element of a linked list.
 * @head: Pointer to the first node in the linked list.
 *
 * Return: The total number of nodes in the linked list.
 */
size_t print_list(const list_t *head)
{
    size_t node_count = 0;

    while (head != NULL)
    {
        if (head->str == NULL)
        {
            printf("[0] (nil)\n");
        }
        else
        {
            printf("[%u] %s\n", head->len, head->str);
        }

        head = head->next;
        node_count++;
    }

    return node_count;
}

