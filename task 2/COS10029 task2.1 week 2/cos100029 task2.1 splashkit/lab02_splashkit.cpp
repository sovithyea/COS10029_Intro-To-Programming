#include "splashkit.h"
using namespace std;

int main()
{
    open_window("Splashkit Drawing", 600, 800);
    clear_screen(COLOR_GRAY);
    fill_ellipse(COLOR_GREEN,0,600,800,600);

    refresh_screen();
    
    delay (5000);
    
    return 0;
}
