#include "splashkit.h"
#define WIDTH 100
#define HEIGHT 100

int main()
{   
    double x, y;
    open_window("Rectangle Moving", 800, 600);
    x=350;
    y=250;
    while(not quit_requested())
    {
        process_events();
        clear_screen(COLOR_WHITE);
        
        fill_rectangle(COLOR_RED, x, y, WIDTH, HEIGHT);
        if(key_down(DOWN_KEY) and y+HEIGHT<screen_height())
            y = y+10;
        if(key_down(UP_KEY) and y>=0)
            y = y-10;
        if(key_down(RIGHT_KEY) and x+WIDTH<screen_width())
            x = x+10;
        if(key_down(LEFT_KEY)and x>=0)
            x = x-10;
            
        refresh_screen(60);
    }
    return 0;
}