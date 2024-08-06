#include "lists.h"

/**
 * add_nodeint_end - Appends a new node to the
 *                   end of a listint_t linked list.
 * @head: Double pointer to the head of the listint_t list.
 * @n: The integer value to be stored in the new node.
 *
 * Return: The address of the newly added node, or NULL if it fails.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
    listint_t *new_node, *current;

    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return NULL;

    new_node->n = n;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        current = *head;
        while (current->next != NULL)
            current = current->next;
        current->next = new_node;
    }

    return new_node;
}

