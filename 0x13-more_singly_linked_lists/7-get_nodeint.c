#include "lists.h"

/**
 * get_nodeint_at_index - Finds the node at a specific index in a listint_t list.
 * @head: Pointer to the head of the listint_t list.
 * @index: The position of the node to find, with indexing starting at 0.
 *
 * Return: The node at the specified index, or NULL if the index is out of range.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
    unsigned int current_index = 0;

    while (head != NULL)
    {
        if (current_index == index)
            return head;
        head = head->next;
        current_index++;
    }

    return NULL;
}

