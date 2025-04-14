#include "splashkit.h"
using namespace std;


// Define the selection areas for shapes
bool choiceSquare = (mouse_x() >= 100) && (mouse_x() <= 175) && (mouse_y() >= 100) && (mouse_y() <= 175);
bool choiceRectangle = (mouse_x() >= 200) && (mouse_x() <= 300) && (mouse_y() >= 100) && (mouse_y() <= 120);
bool choiceCircle = (mouse_x() >= 350) && (mouse_x() <= 375) && (mouse_y() >= 110) && (mouse_y() <= 165);
bool choiceTriangle = (mouse_x() >= 400) && (mouse_x() <= 450) && (mouse_y() >= 100) && (mouse_y() <= 195);
    
// Define the selection areas for colors
bool choiceBlue = (mouse_x() >= 100) && (mouse_x() <= 175) && (mouse_y() >= 250) && (mouse_y() <= 325);
bool choiceRed = (mouse_x() >= 200) && (mouse_x() <= 275) && (mouse_y() >= 250) && (mouse_y() <= 325);
bool choiceBlack = (mouse_x() >= 300) && (mouse_x() <= 375) && (mouse_y() >= 250) && (mouse_y() <= 325);
bool choiceGreen = (mouse_x() >= 400) && (mouse_x() <= 475) && (mouse_y() >= 250) && (mouse_y() <= 325);
    
// Define the final area where the shape will be drawn
bool choiceFinal = (mouse_x() >= 100) && (mouse_x() <= 245) && (mouse_y() >= 370) && (mouse_y() <= 410);

void draw_shape()
{
    draw_rectangle(COLOR_BLACK, 100, 100, 75, 75);
    draw_rectangle(COLOR_BLACK, 200, 100, 100, 20);
    draw_circle(COLOR_BLACK, 350, 110, 25);
    draw_triangle(COLOR_BLACK, 400, 140, 450, 140, 425, 70);
}

void click_space()
{
    if(mouse_down(LEFT_BUTTON))
    {
            // Define the selection areas for shapes
        bool choiceSquare = (mouse_x() >= 100) && (mouse_x() <= 175) && (mouse_y() >= 100) && (mouse_y() <= 175);
        bool choiceRectangle = (mouse_x() >= 200) && (mouse_x() <= 300) && (mouse_y() >= 100) && (mouse_y() <= 120);
        bool choiceCircle = (mouse_x() >= 350) && (mouse_x() <= 375) && (mouse_y() >= 110) && (mouse_y() <= 165);
        bool choiceTriangle = (mouse_x() >= 400) && (mouse_x() <= 450) && (mouse_y() >= 100) && (mouse_y() <= 195);
            
            // Define the selection areas for colors
        bool choiceBlue = (mouse_x() >= 100) && (mouse_x() <= 175) && (mouse_y() >= 250) && (mouse_y() <= 325);
        bool choiceRed = (mouse_x() >= 200) && (mouse_x() <= 275) && (mouse_y() >= 250) && (mouse_y() <= 325);
        bool choiceBlack = (mouse_x() >= 300) && (mouse_x() <= 375) && (mouse_y() >= 250) && (mouse_y() <= 325);
        bool choiceGreen = (mouse_x() >= 400) && (mouse_x() <= 475) && (mouse_y() >= 250) && (mouse_y() <= 325);
        
        if(choiceSquare)
        {
            draw_text("Square", COLOR_BLACK, "Arial.ttf", 100, 670 , 110);
        }
        if(choiceRectangle)
        {
            draw_text("Rectangle", COLOR_BLACK, "Arial.ttf", 100, 670 , 110);
        }
        if(choiceCircle)
        {
            draw_text("Circle", COLOR_BLACK, "Arial.ttf", 100, 670 , 110);
        }
        if(choiceTriangle)
        {
            draw_text("Triangle", COLOR_BLACK, "Arial.ttf", 100, 670 , 110);
        }
        if(choiceBlue)
        {
            draw_text("Blue", COLOR_BLUE, "Arial.ttf", 100, 670 , 255);
        }
        if(choiceRed)
        {
            draw_text("Red", COLOR_RED, "Arial.ttf", 100, 670 , 255);
        }
        if(choiceBlack)
        {
            draw_text("Black", COLOR_BLACK, "Arial.ttf", 100, 670 , 255);
        }
        if(choiceGreen)
        {
            draw_text("Green", COLOR_GREEN, "Arial.ttf", 100, 670 , 255);
        }
    } 
}

void choose_color()
{
    fill_rectangle(COLOR_BLUE, 100, 250, 75, 75);
    fill_rectangle(COLOR_RED, 200, 250, 75, 75);
    fill_rectangle(COLOR_BLACK, 300, 250, 75, 75);
    fill_rectangle(COLOR_GREEN, 400, 250, 75, 75);
}

void boxes()
{
    draw_rectangle(COLOR_BLACK, 600, 100, 145, 60);
    draw_rectangle(COLOR_BLACK, 600, 250, 145, 60);
    draw_rectangle(COLOR_BLACK, 100, 370, 145, 40);
             fill_triangle(COLOR_BLACK, 500, 240, 550, 240, 525, 170);
}

void draw_shapeFinal()
{
    
    if(mouse_down(LEFT_BUTTON))
    {
    // Define the final area where the shape will be drawn
    bool choiceFinal = (mouse_x() >= 100) && (mouse_x() <= 245) && (mouse_y() >= 370) && (mouse_y() <= 410);
    
   
    

        if(choiceBlue && choiceSquare)
        {
            fill_rectangle(COLOR_BLUE, 500, 300, 100, 100);
        }
        if(choiceBlue && choiceRectangle)
        {
            fill_rectangle(COLOR_BLUE, 500, 300, 100, 20);
        }
        if(choiceBlue && choiceCircle)
        {
            fill_circle(COLOR_BLUE, 500, 300, 20);
        }
        if(choiceBlue && choiceTriangle)
        {
            fill_triangle(COLOR_BLUE, 500, 240, 550, 240, 525, 170);
        }
        if(choiceRed && choiceSquare)
        {
            fill_rectangle(COLOR_RED, 500, 300, 100, 100);
        }
        if(choiceRed && choiceRectangle)
        {
            fill_rectangle(COLOR_RED, 500, 300, 100, 20);
        }
        if(choiceRed && choiceCircle)
        {
            fill_circle(COLOR_RED, 500, 300, 20);
        }
        if(choiceRed && choiceTriangle)
        {
            fill_triangle(COLOR_RED, 500, 240, 550, 240, 525, 170);
        }
        if(choiceBlack && choiceSquare)
        {
            fill_rectangle(COLOR_BLACK, 500, 300, 100, 100);
        }
        if(choiceBlack && choiceRectangle)
        {
            fill_rectangle(COLOR_BLACK, 500, 300, 100, 20);
        }
        if(choiceBlack && choiceCircle)
        {
            fill_circle(COLOR_BLACK, 500, 300, 20);
        }
        if(choiceBlack && choiceTriangle)
        {
            fill_triangle(COLOR_BLACK, 500, 240, 550, 240, 525, 170);
        }
        if(choiceGreen && choiceSquare)
        {
            fill_rectangle(COLOR_GREEN, 500, 300, 100, 100);
        }
        if(choiceGreen && choiceRectangle)
        {
            fill_rectangle(COLOR_GREEN, 500, 300, 100, 20);
        }
        if(choiceGreen && choiceCircle)
        {
            fill_circle(COLOR_GREEN, 500, 300, 20);
        }
        if(choiceGreen && choiceTriangle)
        {
            fill_triangle(COLOR_GREEN, 500, 240, 550, 240, 525, 170);
        }
    
    }
}

int main()
{
    open_window("Button click", 800, 600);
    clear_screen(COLOR_WHITE);
  

    while(not quit_requested())
    {
        draw_shape();
        click_space();
        choose_color();
        boxes();
        draw_shapeFinal();
        draw_text("Shape: ", COLOR_BLACK, "Arial.ttf", 50, 610, 110);
        draw_text("Color: ", COLOR_BLACK, "Arial.tff", 50, 610, 255);
        draw_text("Click to draw", COLOR_BLACK, "Arial.ttf", 50, 110, 385);
        
        process_events();
        refresh_screen(60);
    }
    return 0;
} 