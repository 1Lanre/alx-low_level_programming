#include "lists.h"

/**
 * delete_nodeint_at_index - Removes the node at a specified index from a listint_t list.
 * @head: Double pointer to the head of the listint_t list.
 * @index: The position of the node to be deleted, with indexing starting at 0.
 *
 * Return: 1 if the node was successfully deleted, or -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    listint_t *node_to_delete, *prev_node;
    unsigned int i;

    // Check if the list is empty
    if (*head == NULL)
        return -1;

    // Handle deletion of the head node
    if (index == 0)
    {
        node_to_delete = *head;
        *head = (*head)->next;
        free(node_to_delete);
        return 1;
    }

    // Traverse to the node just before the one to be deleted
    prev_node = *head;
    for (i = 0; i < index - 1; i++)
    {
        if (prev_node == NULL || prev_node->next == NULL)
            return -1;
        prev_node = prev_node->next;
    }

    // Delete the node
    node_to_delete = prev_node->next;
    if (node_to_delete == NULL)
        return -1;
    prev_node->next = node_to_delete->next;
    free(node_to_delete);

    return 1;
}

