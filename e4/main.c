#include "no.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct Node *head = NULL;

    struct Student *student1 = createStudent(1, 3.5);
    struct Student *student2 = createStudent(2, 4.0);
    struct Student *student3 = createStudent(3, 3.7);

    append(&head, student1);
    append(&head, student2);
    append(&head, student3);

    printf("Lista de estudantes:\n");
    printList(head);

    return 0;
}