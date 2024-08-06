#include "lists.h"

/**
 * add_nodeint - Inserts a new node at the start
 *               of a listint_t linked list.
 * @head: Double pointer to the head of the listint_t list.
 * @n: Value to be stored in the new node.
 *
 * Return: On success, the address of the newly created node.
 *         On failure, returns NULL.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
    listint_t *new_node;

    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return NULL;

    new_node->n = n;
    new_node->next = *head;
    *head = new_node;

    return new_node;
}

