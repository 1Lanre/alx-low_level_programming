#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * add_node_end - Appends a new node to the end of the linked list.
 * @head_ref: Pointer to the pointer to the head of the list.
 * @str: The string to be copied into the new node.
 *
 * Return: Pointer to the new node, or NULL if allocation fails.
 */
list_t *add_node_end(list_t **head_ref, const char *str)
{
    if (str == NULL)
        return NULL;

    list_t *new_node = malloc(sizeof(list_t));
    if (new_node == NULL)
        return NULL;

    new_node->str = strdup(str);
    if (new_node->str == NULL) {
        free(new_node); // Free the new node if strdup fails
        return NULL;
    }

    new_node->len = _strlen(str);
    new_node->next = NULL;

    // If the list is empty, the new node becomes the head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return new_node;
    }

    // Otherwise, find the last node and append the new node
    list_t *current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
    return new_node;
}

/**
 * _strlen - Calculates the length of a string.
 * @str: The string to be measured.
 *
 * Return: The length of the string.
 */
int _strlen(const char *str)
{
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    return length;
}

