//drawing a star
#include "splashkit.h"

void draw_star(color clr, double x, double y, int width, int height)
{
    double x2=x+width;
    double y2=y+height;
    double left_x=x-width;
    double mid_x=x+width/2;
    double mid_y=y+height/2;
    double bottom_y=y2+height;
    double top_y=y-height;
    double right_x=x2+width;

    fill_rectangle(clr, x, y, width, height);
    fill_triangle(clr, x, y ,x2, y, mid_x, top_y);
    fill_triangle(clr, x2,y, x2, y2, right_x, mid_y);
    fill_triangle(clr, x2, y2, mid_x, bottom_y, x, y2);
    fill_triangle(clr, x, y2, left_x, mid_y, x, y);

    return draw_star;
}

int main()
{
    open_window("Star", 800,600);
    clear_screen(COLOR_WHITE);

    draw_star(COLOR_GREEN, 100, 100, 100, 100);
    draw_star(COLOR_RED, 600, 100,100,100);
    draw_star(COLOR_BLUE, 100, 400, 100, 100);
    draw_star(COLOR_ORANGE, 600, 400, 100, 100);
    draw_star(COLOR_PURPLE, 350, 250, 100, 100);

    refresh_screen(60);
    delay(10000);

    return 0;
}
