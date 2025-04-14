/*––––––––––––––––––––––––––––––––––––––––––––––––––––––––––*/
/*
/*
*/
/* This program computes the
*/
/* distance between two points.
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double x1 = 1, y1 = 5, x2 = 4, y2 = 7, side_1, side_2, distance;
    side_1 = x2 - x1;
    side_2 = y2 - y1;
    distance = sqrt(side_1 * side_1 + side_2 * side_2);
    cout << "The distance between the two points is " << fixed <<
setprecision(2) << distance << endl;
    return 0;
}/*––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––*/