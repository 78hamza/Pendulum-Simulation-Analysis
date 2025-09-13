#ifndef STRFUN_H
# define STRFUN_H

#include <stdlib.h>
#include <math.h>

typedef struct Node{
    double time;
    double angular;
    double angular_vel;
    double angular_acc;
    struct Node *next;
} Node;

Node    *create_node(double t, double angular, double vel, double acc);
void    append_node(Node **head, Node *new_node);
void    free_list(Node *head);

// pendulum physics function
double  compute_acc(double theta);
void    update_pendulum(double *theta, double *omega, double  dt);

// energy functions
double kinetic_energy(double omega);
double potential_energy(double theta);
double total_energy(double theta, double omega);
#endif

