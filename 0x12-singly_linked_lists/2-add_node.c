#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - Prepends a new node to the start of the linked list.
 * @head_ref: Pointer to the pointer to the head of the list.
 * @str: The string to be duplicated and added to the new node.
 *
 * Return: Pointer to the new node, or NULL if allocation fails.
 */
list_t *add_node(list_t **head_ref, const char *str)
{
    list_t *new_node;

    if (head_ref == NULL || str == NULL)
        return NULL;

    new_node = malloc(sizeof(list_t));
    if (new_node == NULL)
        return NULL;

    new_node->str = strdup(str);
    if (new_node->str == NULL) {
        free(new_node);  // Free allocated memory if strdup fails
        return NULL;
    }

    new_node->len = _strlen(str);
    new_node->next = *head_ref;
    *head_ref = new_node;

    return new_node;
}

/**
 * _strlen - Computes the length of a string.
 * @str: The string whose length is to be determined.
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

