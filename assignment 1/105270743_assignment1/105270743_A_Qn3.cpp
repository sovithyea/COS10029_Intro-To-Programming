#include <iostream>
#include <cstdlib> 
#include <ctime> 
using namespace std;

//declaring variables
int point;

int rollDice() //randomizing each dice roll
{
    int roll1 = rand() % 6 + 1;
    int roll2 = rand() % 6 + 1;
    int roll3 = rand() % 6 + 1;
    int sum = roll1 + roll2 + roll3;
    cout << "Player rolled " << roll1 << " + " << roll2 << " + " << roll3 << " = " << sum << endl;
    return sum;
}

void result()
{ 
    int sum = rollDice();
    point = sum;
    if (sum >= 13) //13 or greater means player wins
    { 
        cout << "Player wins " << endl;
        return;
    }
    else if (sum <= 6) //6 or lower means player loses
    {
        cout << "Player loses" << endl;
        return;
    }
    else if (sum >= 7 && sum <= 12) //for if sum is between 7 and 12
    {
        cout << "Point is " << sum << endl;
    }
    do 
    {
        sum = rollDice();
            
        if (sum == point)
        {
            cout << "You win!" << endl;
            break;
        }
        else if (sum >= 15) //must roll under 15 to win
        {
            cout << "You lose due to your sum " << sum << " being greater than or equal to 15 before making the point" << endl;
            break;
        }
    } while (true);
}

int main() 
{
    srand(time(NULL));
    result();
    return 0;
}
