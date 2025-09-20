#include "strfun.h"
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

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

void    export_2_csv(char *file_name, Node *head)
{
    int fd;
    char *str;
    int len;
    char    buffer[256];
    Node *temp;


    fd = open(file_name, O_RDWR | O_CREAT, 0644);
    if (fd == -1)
        return ;

    // writing into the file 
    // writing the headers
    str = "time,theta,omega,alpha,Kinetic energy,Potential energy,Total energy\n";
    len = strlen(str);
    write(fd, str, len);
    // writing the data
    temp = head;
    while (temp)
    {
        len = snprintf(buffer, sizeof(buffer),
                       "%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f\n",
                       temp->time,temp->angular,temp->angular_vel,temp->angular_acc,
                       temp->kin_ene,temp->pot_ene,temp->tot_ene);
        write(fd, buffer, len);
        temp = temp->next;
    }
    close(fd);
}
