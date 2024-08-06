#include "lists.h"

/**
 * pop_listint - Removes and returns the data from the head node of a listint_t list.
 * @head: Double pointer to the head of the listint_t list.
 *
 * Return: The data (n) from the head node, or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
    listint_t *node_to_remove;
    int node_data;

    if (head == NULL || *head == NULL)
        return 0;

    node_to_remove = *head;
    node_data = node_to_remove->n;
    *head = node_to_remove->next;

    free(node_to_remove);

    return node_data;
}

