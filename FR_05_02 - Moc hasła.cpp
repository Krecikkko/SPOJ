// not working solution - have to find a mistake

#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string pw;
        getline(cin, pw);

        bool is_num = false;
        bool is_lower_letter = false;
        bool is_upper_letter = false;
        bool is_sign = false;
        int pw_len = pw.length();

        if (pw_len < 8) break;
        for (int i = 0; i < pw_len; i++) {
            if (pw[i] >= '0' && pw[i] <= '9') is_num = true;
            else if (pw[i] >= 'a' && pw[i] <= 'z') is_lower_letter = true;
            else if (pw[i] >= 'A' && pw[i] <= 'Z') is_upper_letter = true;
            else is_sign = true;
        }

        if (is_num && is_lower_letter && is_upper_letter && is_sign) cout << pw << endl;
    }
    return 0;
}
