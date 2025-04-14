#include <stdlib.h>
#include <time.h>
#include "splashkit.h"

void draw_star(color clr, double x, double y, int width, int height) //declaring variables to draw a star
{
    double x2=x+width;
    double y2=y+height;
    double left_x=x-width;
    double mid_x=x+width/2;
    double mid_y=y+height/2;
    double bottom_y=y2+height;
    double top_y=y-height;
    double right_x=x2+width;

    switch(rand()%4) //randomizing the colors of the stars
    {
        case 0: clr = COLOR_RED;
        break;
        case 1: clr = COLOR_YELLOW;
        break;
        case 2: clr = COLOR_GREEN;
        break;
        case 3: clr = COLOR_BLUE;
        break;  
    }
    //commands to draw a star
    fill_rectangle(clr, x, y, width, height);
    fill_triangle(clr, x, y ,x2, y, mid_x, top_y);
    fill_triangle(clr, x2,y, x2, y2, right_x, mid_y);
    fill_triangle(clr, x2, y2, mid_x, bottom_y, x, y2);
    fill_triangle(clr, x, y2, left_x, mid_y, x, y);
}

int main() //splashkit commands
{
    open_window("Shape", 800, 600);
    clear_screen(COLOR_WHITE);
    srand(time(NULL));
    int row=1, column, x=100, y=100;
    
    //displaying the coordinates of each star
    while(row<=10)
    {
        column=1;
        while(column<=row)
        {
            draw_star(random_color(), x, y, 10, 10);
            x = x + 50;
            column++;
        }
        row++;
        x = 100;
        y = y + 50;
    }
    //splashkit commands
    refresh_screen(60);
    delay(5000);
    return 0;
}
