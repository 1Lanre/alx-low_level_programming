#include "lists.h"

/**
 * reverse_listint - Reverses the order of nodes in a listint_t list.
 * @head: Double pointer to the head of the listint_t list.
 *
 * Return: Pointer to the new head of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
    listint_t *previous = NULL, *current = *head, *next_node;

    if (head == NULL || *head == NULL)
        return NULL;

    while (current != NULL)
    {
        next_node = current->next;  // Save the next node
        current->next = previous;   // Reverse the link
        previous = current;         // Move previous up to current
        current = next_node;        // Move to next node
    }

    *head = previous;  // Update the head to the new first node

    return *head;
}

