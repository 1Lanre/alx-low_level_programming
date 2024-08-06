#include "lists.h"

/**
 * looped_listint_count - Counts the number of unique nodes in a potentially looped listint_t list.
 * @head: Pointer to the head of the listint_t list to examine.
 *
 * Return: The number of unique nodes if there is a loop; 0 otherwise.
 */
size_t looped_listint_count(listint_t *head)
{
    const listint_t *slow, *fast;
    size_t count = 0;

    if (head == NULL || head->next == NULL)
        return 0;

    slow = head;
    fast = head;

    // Detect if there is a loop
    do
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
    } while (fast != NULL && fast != slow);

    // If there is no loop
    if (fast == NULL)
        return 0;

    // Find the start of the loop
    const listint_t *loop_start = head;
    while (loop_start != slow)
    {
        loop_start = loop_start->next;
        slow = slow->next;
    }

    // Count the nodes in the loop
    do
    {
        count++;
        slow = slow->next;
    } while (slow != loop_start);

    return count;
}

/**
 * free_listint_safe - Frees a listint_t list and handles loops safely.
 * @h: Double pointer to the head of the listint_t list.
 *
 * Return: The number of nodes that were freed.
 *
 * Description: The function also sets the head pointer to NULL.
 */
size_t free_listint_safe(listint_t **h)
{
    listint_t *current, *next_node;
    size_t count = 0;

    if (h == NULL || *h == NULL)
        return 0;

    // Count nodes and detect loops
    size_t loop_size = looped_listint_count(*h);

    if (loop_size == 0)
    {
        // Free nodes in a non-looped list
        while (*h != NULL)
        {
            next_node = (*h)->next;
            free(*h);
            *h = next_node;
            count++;
        }
    }
    else
    {
        // Free nodes in a looped list
        for (size_t i = 0; i < loop_size; i++)
        {
            next_node = (*h)->next;
            free(*h);
            *h = next_node;
            count++;
        }

        // Set the head to NULL after freeing the loop
        *h = NULL;
    }

    return count;
}

