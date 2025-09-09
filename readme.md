# Project: Pendulum simulation and analysis
## Overview
This project simulate the motion of a simple pendulum using numerical integration (Euler's method) and stores the result in a linked list.
It allows the user to analyze the pendulum's dynamics, including angle, angular velocity, angular acceleration, and energy over time. The simulation data can also exported to CSV for further analysis.

The second part of the project extends the simulation with Machine Learning (ML) experiment using Python. The exported data can be visulized,
used for regression and classfication tasks, or even train a neural networl to learn the pendulum's dynamics.

This project combines:

- Physics (Mechanics & energy conversationn)
- Computer Science (C programming, data structures, memory management)
- Machine learning (data-driven predictions and visualisation)

### Simulation (C)
- simulate pendulum motion with customizable:
    - Initial angle
    - Pendulum length
    - Gravity
    - Time step
    - Total simulation time
- store data in a linked list.
- compute kinetic, potential, and total energy.
- export results to csv for external analysis

### Machine learning (Python)
- Load and analyze simulation data with Pandas and Matplotlib.
- visualize:
    - Angle vs Time.
    - Phase Space (θ vs θ’).
    - Energy conservation
- ML experiments:
    - regression -> predict pendulum angle over time.
    - classification -> classify stable vs chaotic regimes (future extension)
    - Neural networks -> train RNNs/LSTMs to learn pendulum dynamics.


### Project structure:
pendulum_simulation/
|
|-- main.c # program entry and menu handling

|-- pendulum.c # simulation and linked list creation

|-- energy.c # energy calculation funcionts
|-- print.c # printing and csv export
|-- structs.h # linked list node definition
|-- Makefile # compilation instrucitons
|-- analysis.py #Python ML & visualisation


### Physics behind the simulation
The simpe pendulum equation is:
    
    |-------------------------------------------------------|
    |                                                       |
    |    w(t) = - (g / L)sin(theta(t))                      |
    |                                                       |
    |-------------------------------------------------------|

- theta(t) : angle from vertical (radians)
- w(t) : angular acceleration
- g : gravitaional acceleration (9.81 m/s^2)
- L : pendulum length

we use **Euler's method** to approximate the solution:

    |-------------------------------------------------------|
    |                                                       |
    |                                                       |
    |       θ(t+Δt)=θ(t)+θ′(t)⋅Δt                           |
    |       θ′(t+Δt)=θ′(t)+θ′′(t)⋅Δt                        |
    |-------------------------------------------------------|

