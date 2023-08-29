#include "lists.h" 

/**
 * pop_listint - Removes the head node of a linked list and returns its data.
 * @head: Pointer to a pointer to the head node of the linked list.
 * Return: Data stored in the removed head node, or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
    int data = 0;
    listint_t *temp;

    if (*head == NULL) 
        return (0);

    temp = *head; 
    data = temp->n; 
    *head = (*head)->next;
    free(temp); 
    return (data); 
}
