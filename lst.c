#include "strfun.h"

Node *create_node(double t, double angular, double vel, double acc)
{
    Node *new_node = malloc(sizeof(Node));

    if (!new_node)
        return NULL;

    new_node->time = t;
    new_node->angular = angular;
    new_node->angular_vel = vel;
    new_node->angular_acc = acc;
    new_node->next = NULL;
    return (new_node);
}

void    append_node(Node **head, Node *new_node)
{
    Node *temp;
    
    if (head == NULL)
        *head = new_node;

    temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void    free_list(Node *head)
{
    Node *temp;

    if (head->next == NULL)
    {
        free(head);
        return;
    }

    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
