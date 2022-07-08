#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string current, correct;
    cin >> current >> correct;
    int currstart = (current[0] - '0') * 10 + (current[1] - '0');
    int currend = (current[3] - '0') * 10 + (current[4] - '0');
    int corrstart = (correct[0] - '0') * 10 + (correct[1] - '0');
    int corrend = (correct[3] - '0') * 10 + (correct[4] - '0');
    int y = 0;
    int d = corrend - currend;
    if (corrend >= currend)
    {

        if (d >= 15)
        {
            cout<<"hi"<<endl;
            y = d / 15;
            if (d % 15 >= 5)
            {
                y += (d % 15) / 5 + (d % 15) % 5;
            }
            else
            {
                y += (d % 15);
            }
             cout << corrstart - currstart + y << endl;
        }
        else if (d >= 5)
        {
            cout<<"bi";
            y = d / 5 + d % 5;
             cout << corrstart - currstart + y << endl;
        }
        else
        {
            cout<<"inside";
            y = d;
             cout << corrstart - currstart + y << endl;
        }
      
    }

    else
    {
        d = 60 - currend + corrend;
        if (d >= 15)
        {
            y = d / 15;
            if (d % 15 >= 5)
            {
                y += (d % 15) / 5 + (d % 15) % 5;
            }
            else
            {
                y += (d % 15);
            }
        }
        else if (d >= 5)
        {
            y = d / 5 + d % 5;
        }
        else
        {
            y = d;
        }
        cout << corrstart - currstart + y - 1 << endl;
        ;
    }
    return 0;
}