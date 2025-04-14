#include "splashkit.h"
#include <ctime>
#define SIZE 1000

void fill_array(int data[])
{
    int i;
    
    for(i=0; i<SIZE; i++)
    {
        data[i]=rand()%700;
    }
}

void draw_bar(int data[])
{
    int i;
    float x, y, rectwidth;
    rectwidth=5;
    
    for(i=0; i<SIZE; i++)
    {
        x = rectwidth*i;
        y = screen_height() - data[i];
        fill_rectangle(COLOR_RED, x, y, rectwidth, data[i]);
    }
}

int main()
{
    int data[SIZE];
    
    open_window("Array Rectangle", 800, 600);
    srand(time(NULL));
    fill_array(data);
    
    while(not quit_requested())
    {
        process_events();
        clear_screen(COLOR_WHITE);
        draw_bar(data);
        refresh_screen();
    }
}

