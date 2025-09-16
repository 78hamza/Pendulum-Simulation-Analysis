#include "strfun.h"

int main()
{
    double omega;
    double theta;
    int steps;
    double dt;
    double t;
    double alpha;
    double kin_ene;
    double pot_ene;
    double tot_ene;
    Node *n;
    Node *head;
    int i;

    t = 0.0;
    printf("First let's enter some of data:\n");
    printf("theta >");
    scanf("%le", &theta); 
    printf("omega >");
    scanf("%le", &omega);
    printf("dt >");
    scanf("%le", &dt);
    printf("steps >");
    scanf("%d", &steps);
    
    head = NULL;
    i = 0;
    while (i < steps)
    {
        alpha = compute_acc(&theta);
        kin_ene = kinetic_energy(omega);
        pot_ene = potential_energy(theta);
        tot_ene = total_energy(theta, omega);
        n = create_node(t, theta, omega, alpha, kin_ene, pot_ene, tot_ene);
        append_node(&head, n);

        update_pendulum(&theta, &omega, dt);
        t += dt;
        i++;
    }
    print_lst(head);
    return 0;
}
