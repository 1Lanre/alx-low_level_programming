#include "lists.h"

/**
 * free_listint - Deallocates memory used by a listint_t list.
 * @head: Pointer to the start of the listint_t list to be freed.
 */
void free_listint(listint_t *head)
{
    listint_t *current_node;

    while (head != NULL)
    {
        current_node = head->next;
        free(head);
        head = current_node;
    }
}

