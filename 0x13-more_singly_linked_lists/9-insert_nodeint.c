#include "lists.h"

/**
 * insert_nodeint_at_index - Adds a new node to a listint_t list at a specified index.
 * @head: Double pointer to the head of the listint_t list.
 * @idx: The position at which to insert the new node; indexing starts at 0.
 * @n: The integer value to be stored in the new node.
 *
 * Return: The address of the newly inserted node, or NULL if insertion fails.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    listint_t *new_node, *current;
    unsigned int position;

    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return NULL;

    new_node->n = n;

    // Handle insertion at the beginning
    if (idx == 0)
    {
        new_node->next = *head;
        *head = new_node;
        return new_node;
    }

    // Traverse to the node before the desired position
    current = *head;
    for (position = 0; position < idx - 1; position++)
    {
        if (current == NULL)
        {
            free(new_node);
            return NULL; // Index is out of bounds
        }
        current = current->next;
    }

    // Insert the new node
    new_node->next = current->next;
    current->next = new_node;

    return new_node;
}

