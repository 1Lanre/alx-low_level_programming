#include "lists.h"

/**
 * free_listint2 - Releases the memory of a listint_t list and sets head to NULL.
 * @head: Double pointer to the head of the listint_t list to be freed.
 *
 * Description: After freeing the list, it sets the head pointer to NULL.
 */
void free_listint2(listint_t **head)
{
    listint_t *current;

    if (head == NULL || *head == NULL)
        return;

    while (*head != NULL)
    {
        current = (*head)->next;
        free(*head);
        *head = current;
    }

    *head = NULL;
}

