#include "strfun.h"

void    print_lst(Node *head)
{
    Node *temp;
    
    if (head == NULL)
        return ;
    
    printf("time\t\ttheta\t\tomega\t\talpha\n");
    printf("------------------------------------------\n");
    
    temp = head;
    while (temp)
    {
        printf("%.3f\t%.3f\t%.3f\t%.3f\n",
               temp->temp,
               temp->angular,
               temp->angular_vel,
               temp->angular_acc);
        
        temp = temp->next;
    }
}

