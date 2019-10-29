#include "linkedlist.c"

void reverseListIteratively(List **head)
{
    List *predecessor = NULL;
    List *current = *head;
    List *successor = NULL;

    while (current != NULL)
    {
        // Store the successor list
        successor = current->next;
        // Reverse the current list
        current->next = predecessor;
        // Move to the successor list
        predecessor = current;
        current = successor;
    }
    
    *head = predecessor;
  
}

void reverseListRecursively(List **head, List *current, List *predecessor)
{
    // If it is the last list, change the head pointer to point to it
    if (current->next == NULL)
    {
        *head = current;
        current->next = predecessor;
        return;
    }
    // Save the current list for recursive call
    List *successor = current->next;
    // Reverse the current list
    current->next = predecessor;
    predecessor = current;
    // Move to the successor list
    reverseListRecursively(head, successor, predecessor);
}

int main(void)
{
    List sampleList = { 0, NULL };
    List *head;
    int item;
    // Initialize the head pointer to the first list
    head = &sampleList;
    // Initialize a singly-linked list
    printf("First item: ");
    scanf("%d", &item);
    insertList(&head, item);
    printf("Second item: ");
    scanf("%d", &item);
    insertList(&head, item);
    printf("Third item: ");
    scanf("%d", &item);    
    insertList(&head, item);
    printf("Fourth item: ");
    scanf("%d", &item);    
    insertList(&head, item);
    // Display the linked list
    printList(head);
    printf("\n");
    
    reverseListRecursively(&head, head, NULL);
    printList(head);
    printf("\n");
    reverseListIteratively(&head);
    printList(head);
    printf("\n");

    return 0;
}