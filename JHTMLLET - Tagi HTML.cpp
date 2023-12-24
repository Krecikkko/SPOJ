#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string code;
    int begPlace;

    while(getline(cin, code))
    {
        for (int i=0; i<code.length(); i++)
        {
            if (code[i] == '<')
            {
                begPlace = i;
            }
            else if (code[i] == '>')
            {
                for (int j=begPlace; j<i; j++)
                {
                    code[j] = toupper(code[j]);
                }
            }
        }

        cout << code << endl;
    }

    return 0;
}
