#include <iostream>
using namespace std;

double find_velocity(double u, double a, double t)
{
    double v; 
    v = u + a * t;
    
    return v;
}

int main()
{
    double initial_velocity, time, acceleration, velocity;
    
    initial_velocity=10;
    time=180;
    acceleration=9.08;
    velocity=find_velocity(initial_velocity, acceleration,time);
    cout << "Velocity 1: " <<velocity<< endl;

    initial_velocity=10.5;
    time=10.5;
    acceleration=12.5;
    velocity=find_velocity(initial_velocity, acceleration,time);
    cout << "Velocity 2: " <<velocity<<endl;

    cout << "Enter the value of the initial velocity: ";
    cin >> initial_velocity;
    cout << "Enter the value of the acceleration: ";
    cin >> acceleration;
    cout << "Enter the value of time: ";
    cin >> time;
    velocity=find_velocity(initial_velocity, acceleration,time);
    cout << "Velocity 3: " <<velocity<<endl;

    return 0;
}
