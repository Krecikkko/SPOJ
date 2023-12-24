#include <iostream>

using namespace std;

int main()
{
    int num, howMany=0;
    bool isDif = false;

    while(cin >> num)
    {
        cout << num << endl;

        if ((num == 42) && isDif)
        {
            howMany++;
            if (howMany == 3)
            {
                break;
            }
            isDif = false;
        }
        else if (num == 42)
        {
            isDif = false;
        }
        else
        {
            isDif = true;
        }
    }

    return 0;
}
