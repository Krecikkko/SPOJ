#include <iostream>

using namespace std;

int char_to_int(char c) {
    if (c >= '0' && c <= '9') return (c - '0');
    return 0;
}

bool is_divisible_by_three(string input) {
    int sum = 0;
    for (int i = 0; i < input.length(); i++) {
        sum += char_to_int(input[i]);
    }
    if (sum % 3 == 0) return true;
    return false;
}

bool is_divisible_by_five(string input) {
    if (input[input.length()-1] == '0' || input[input.length()-1] == '5') return true;
    return false;
}

int main() {
    string input;

    while (cin >> input) {
        if (input == "0") break;
        if (is_divisible_by_three(input) && is_divisible_by_five(input)) cout << "TAK" << endl;
        else cout << "NIE" << endl;
    }

    return 0;
}
