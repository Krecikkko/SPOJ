#include <iostream>

using namespace std;

int main() {
    int value;
    int stack[10];
    int address_of_first_element=0;
    char sign;

    while (cin >> sign) {
        if (sign == '+') {
            cin >> value;
            if (address_of_first_element < 10) {
                stack[address_of_first_element++] = value;
                cout << ":)" << endl;
            } else cout << ":(" << endl;
        } else if (sign == '-' && address_of_first_element > 0) {
            cout << stack[--address_of_first_element] << endl;
        } else {
            cout << ":(" << endl;
        }
    }
    return 0;
}
