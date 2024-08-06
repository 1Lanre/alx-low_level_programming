#include "lists.h"

/**
 * sum_listint - Computes the total sum of the data in a listint_t list.
 * @head: Pointer to the start of the listint_t list.
 *
 * Return: The sum of all data (n) in the list; returns 0 if the list is empty.
 */
int sum_listint(listint_t *head)
{
    int total = 0;

    while (head != NULL)
    {
        total += head->n;
        head = head->next;
    }

    return total;
}

