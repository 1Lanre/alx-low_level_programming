#include <stdlib.h>
#include "lists.h"

/**
 * free_list - Frees a linked list.
 * @head: The pointer to the first node of the linked list.
 *
 * Return: Nothing
 */
void free_list(list_t *head)
{
    list_t *current_node;

    while (head != NULL)
    {
        current_node = head;
        head = head->next;

        free(current_node->str);
        free(current_node);
    }
}

