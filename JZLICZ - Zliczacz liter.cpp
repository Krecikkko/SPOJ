#include <iostream>
#include <string>

using namespace std;

// a-z 97-122    A-Z 65-90

int main() {
    const int letters = 60;
    int arr[letters];
    for (int i = 0; i < letters; i++) arr[i] = 0;
    
    int N;
    cin >> N;
    cin.ignore();

    while (N--) {
        string text;
        getline(cin, text);
        for (int i = 0; i < text.length(); i++) {
            if (text[i] >= 'a' && text[i] <= 'z') {
                arr[(int(text[i]) - 97)]++;
            } else if (text[i] >= 'A' && text[i] <= 'Z') {
                arr[(int(text[i]) - 65 + 26)]++;
            }
        }
    }

    for (int i = 0; i < letters; i++) {
        if (arr[i] != 0 && i <= 25) {
            cout << char(i + 97) << " " << arr[i] << endl;
        } else if (arr[i] != 0 && i > 25) {
            cout << char(i + 65 - 26) << " " << arr[i] << endl;
        }
    }

    return 0;
}
