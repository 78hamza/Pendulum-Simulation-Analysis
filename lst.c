#include "strfun.h"

Node *create_node(double t, double angular, double vel, double acc, double kin_ene, double pot_ene, double tot_ene)
{
    Node *new_node = malloc(sizeof(Node));

    if (!new_node)
        return NULL;

    new_node->time = t;
    new_node->angular = angular;
    new_node->angular_vel = vel;
    new_node->angular_acc = acc;
    new_node->kin_ene = kin_ene;
    new_node->pot_ene = pot_ene;
    new_node->tot_ene = tot_ene;
    new_node->next = NULL;
    return (new_node);
}

void    append_node(Node **head, Node *new_node)
{
    Node *temp;
    
    if (*head == NULL)
    {
        *head = new_node;
        return ;
    }
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
