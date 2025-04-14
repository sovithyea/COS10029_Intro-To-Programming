#include <iostream>
#include <cstdlib>
#include <ctime>
#include "splashkit.h"
#define SIZE 800 // amount of bars on the screen
using namespace std;

struct sample
{
    int value;
    color clr;
};

color get_color(float num)
{
    float hue = num / float(screen_height());
    return hsb_color(hue, 0.7, 0.8); // hsb color is used to change the hues of color on the bars
}

// randomizes the height and color of the bars
void fill_array(sample data[])
{
    for(int i = 0; i < SIZE; i++)
    {
        data[i].value = rand() % (screen_height() -100);
        data[i].clr = get_color(data[i].value);
    }
}

// draws the bars
void draw_bar(sample data[])
{
    float rect_width = 800.0 / SIZE;
    for(int i = 0; i < SIZE; i++)
    {
        float x = rect_width * i;
        float y = screen_height() - data[i].value;
        fill_rectangle(data[i].clr, x, y, rect_width, data[i].value);
    }
}

// the red line above the bars
void draw_red_line()
{
    draw_line(COLOR_RED, 0, 50, screen_width(), 50);
}

// draws the buttons
void draw_buttons()
{
    fill_rectangle(COLOR_GREEN, 50, 10, 100, 30);
    fill_rectangle(COLOR_GREEN, 200, 10, 100, 30);
    fill_rectangle(COLOR_GREEN, 350, 10, 100, 30);
    draw_text("Draw Bars", COLOR_WHITE, 60, 15);
    draw_text("Sort 1", COLOR_WHITE, 225, 15);
    draw_text("Sort 2", COLOR_WHITE, 375, 15);
}

// bubblesort function
void BubbleSort(sample data[], int array_size)
{
    int i, j;
    sample temp;  // declare 'temp' as a struct to hold both 'value' and 'clr'
    
    for (i = 0; i < (array_size - 1); i++)
    {
        for (j = 0; j < array_size - 1 - i; j++)
        {
            if (data[j].value > data[j+1].value) // compare the 'value' field of the struct
            {
                temp = data[j+1];  // swap the entire struct
                data[j+1] = data[j]; 
                data[j] = temp;
            }
        }
    }
}

void SelectionSort(sample data[], int array_size)
{
    int i, j, min_idx;
    sample temp;  // declare 'temp' as 'sample' to store both 'value' and 'clr'
    
    for (i = 0; i < array_size - 1; i++)
    {
        min_idx = i;
        
        for (j = i + 1; j < array_size; j++)
        {
            if (data[j].value < data[min_idx].value)  // compare based on the 'value' field
            {
                min_idx = j;
            }
        }
        
        // swap the found minimum element with the first element
        temp = data[min_idx];  // swap the entire struct (both 'value' and 'clr')
        data[min_idx] = data[i];
        data[i] = temp;
    }
}

// function to click the buttons
void button_clicks(sample data[], bool &draw_bars)
{
    if (mouse_clicked(LEFT_BUTTON))
    {
        if (mouse_x() > 50 && mouse_x() < 150 && mouse_y() > 10 && mouse_y() < 40)
        {
            fill_array(data);
            draw_bars = true; // draws bar when button is pressed
        }
        else if (mouse_x() > 200 && mouse_x() < 300 && mouse_y() > 10 && mouse_y() < 40)
        {
            BubbleSort(data, SIZE);
        }
        // This condition should have functionality if needed
        else if (mouse_x() > 350 && mouse_x() < 450 && mouse_y() > 10 && mouse_y() < 40)
        {
            SelectionSort(data, SIZE);
        }
    }
}

int main()
{
    sample data[SIZE];
    open_window("Array Rectangle", 800, 700);
    srand(time(NULL));

    bool draw_bars = false; // waits until button is pressed to draw bars
    while(not quit_requested())
    {
        process_events();
        clear_screen(COLOR_WHITE);
        draw_buttons();
        draw_red_line();
        button_clicks(data, draw_bars);
        
        if (draw_bars)
        {
            draw_bar(data);
        }

        refresh_screen(60);
    }

    return 0;  
}
