#include "lists.h"

/**
 * find_listint_loop - Detects the starting node of a loop in a listint_t linked list.
 * @head: Pointer to the head of the listint_t list.
 *
 * Return: Address of the node where the loop begins, or NULL if there is no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *slow = head, *fast = head;

    // Use Floyd's Tortoise and Hare algorithm to detect a loop
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;             // Move slow pointer by 1 step
        fast = fast->next->next;      // Move fast pointer by 2 steps

        if (slow == fast)             // Loop detected
        {
            listint_t *start = head;

            // Find the start of the loop
            while (start != slow)
            {
                start = start->next;
                slow = slow->next;
            }

            return start;             // The start of the loop
        }
    }

    return NULL;                     // No loop detected
}

