#include "lists.h"
#include <stdio.h>

size_t count_unique_nodes_in_loop(const listint_t *head);
size_t print_listint_safely(const listint_t *head);

/**
 * count_unique_nodes_in_loop - Determines the number of unique nodes
 *                               in a potentially looped listint_t linked list.
 * @head: Pointer to the head of the listint_t list to examine.
 *
 * Return: The count of unique nodes if the list is looped; otherwise, 0.
 */
size_t count_unique_nodes_in_loop(const listint_t *head)
{
    const listint_t *slow, *fast;
    size_t node_count = 0;

    if (head == NULL || head->next == NULL)
        return 0;

    slow = head;
    fast = head->next;

    while (fast && fast->next)
    {
        if (slow == fast)
        {
            const listint_t *loop_start = head;

            while (loop_start != slow)
            {
                node_count++;
                loop_start = loop_start->next;
                slow = slow->next;
            }

            do
            {
                node_count++;
                slow = slow->next;
            } while (slow != loop_start);

            return node_count;
        }

        slow = slow->next;
        fast = fast->next->next;
    }

    return 0;
}

/**
 * print_listint_safely - Outputs a listint_t list, handling loops safely.
 * @head: Pointer to the head of the listint_t list to print.
 *
 * Return: The total number of nodes printed.
 */
size_t print_listint_safely(const listint_t *head)
{
    size_t total_nodes, index;
    size_t nodes_printed = 0;

    total_nodes = count_unique_nodes_in_loop(head);

    if (total_nodes == 0)
    {
        while (head != NULL)
        {
            printf("[%p] %d\n", (void *)head, head->n);
            head = head->next;
            nodes_printed++;
        }
    }
    else
    {
        for (index = 0; index < total_nodes; index++)
        {
            printf("[%p] %d\n", (void *)head, head->n);
            head = head->next;
            nodes_printed++;
        }

        printf("-> [%p] %d\n", (void *)head, head->n);
    }

    return nodes_printed;
}

