#include "strfun.h"

void    print_lst(Node *head)
{
    Node *temp;
    
    if (head == NULL)
        return ;
    
    printf("time\ttheta\tomega\talpha\tKinetic energy\tPotential energy\tTotal energy\n");
    printf("------------------------------------------\n");
    
    temp = head;
    while (temp)
    {
        printf("%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\n",
                temp->time,
                temp->angular,
                temp->angular_vel,
                temp->angular_acc,
                temp->kin_ene,
                temp->pot_ene,
                temp->tot_ene);
    
        temp = temp->next;
    }
}

