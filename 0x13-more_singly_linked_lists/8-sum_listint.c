#include "lists.h"

/**
 * sum_listint - Calculates the sum of all the data in a listint_t linked list.
 * @head: Pointer to the head of the linked list.
 * 
 * Return: Sum of all the data in the linked list.
 */
int sum_listint(listint_t *head)
{
    int sum = 0;
    listint_t *current = head;

    while (current != NULL) 
    {
        sum += current->n;
        current = current->next;
    }

    return (sum);

}
