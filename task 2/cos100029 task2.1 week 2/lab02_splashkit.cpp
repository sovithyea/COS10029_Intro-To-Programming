#include "splashkit.h"
using namespace std;

int main()
{
    open_window("Splashkit Drawing", 800, 800);
    clear_screen(COLOR_BLUE);
    fill_ellipse(COLOR_GREEN,0,600,800,600);
    fill_rectangle(COLOR_RED, 400,400,200,200);
    fill_rectangle(COLOR_YELLOW, 200,200,200,200);
    refresh_screen();
    delay (5000);
    return 0; 
}
