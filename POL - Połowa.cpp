#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string text;
        cin >> text;

        for (int i = 0; i < text.length()/2; i++) {
            cout << text[i];
        }
        cout << endl;
    }
    return 0;
}
