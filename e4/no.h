#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Student *data;
    struct Node *next;
};

struct Student
{
    int id;
    float CR;
};

struct Student *createStudent(int id, float CR)
{
    struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));
    newStudent->id = id;
    newStudent->CR = CR;
    return newStudent;
}

struct Node *createNode(struct Student *data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node **head_ref, struct Student *data)
{
    struct Node *new_node = createNode(data);
    struct Node *last = *head_ref;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("ID: %d, CR: %.2f\n", node->data->id, node->data->CR);
        node = node->next;
    }
}
