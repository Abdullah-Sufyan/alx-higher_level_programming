#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * insert_node - Inserts a number into a sorted singly linked list.
 * @head: Pointer to the head of the list.
 * @number: Number to be inserted.
 *
 * Return: Address of the new node, or NULL if it failed.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node = malloc(sizeof(listint_t));

	listint_t *current;
	listint_t *prev;

	if (!new_node)
	{
		return (NULL);
	}

	new_node->n = number;
	new_node->next = NULL;

	current = *head;
	prev = NULL;

	if (!current || current->n >= number)
	{
		new_node->next = current;
		*head = new_node;
		return (new_node);
	}

	while (current && current->n < number)
	{
		prev = current;
		current = current->next;
	}

	prev->next = new_node;
	new_node->next = current;

	return (new_node);
}

/**
 * print_list - Prints all elements of a linked list.
 * @head: Pointer to the head of the list.
 */
void print_list(listint_t *head)
{
	while (head != NULL)
	{
		printf("%d ", head->n);
		head = head->next;
	}
	printf("\n");
}
