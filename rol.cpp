#include <iostream>

using namespace std;

int main()
{
    int t,n;

    cin >> t;

    while(t--)
    {
        cin >> n;
        int tab[n];

        for (int i=0; i<n; i++)
        {
            cin >> tab[i];
        }
        for (int i=1; i<n; i++)
        {
            cout << tab[i] << " ";
        }
        cout << tab[0] << endl;
    }

    return 0;
}
