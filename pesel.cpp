#include <iostream>

using namespace std;

bool is_correct(char* pesel);

int main() {
    int t;
    char pesel[12];

    cin >> t;

    while (t--) {
        cin >> pesel;

        if (is_correct(pesel)) {
            cout << 'D' << endl;
        } else {
            cout << 'N' << endl;
        }
    }

    return 0;
}

bool is_correct(char* pesel) {
    int weights[11] = {1,3,7,9,1,3,7,9,1,3,1};
    int sum=0;

    for (int i = 0; i < 11; i++) {
        sum += ((int) pesel[i] - 48) * weights[i];
    }

    if ((sum <= 0) || ((sum % 10) != 0)) {
        return false;
    }

    return true;
}
