#include <iostream>

using namespace std;

int main() {
    int num1, num2;
    int arr[10];
    char sign;

    while (cin >> sign >> num1 >> num2) {
        if (sign == 'z') {
            arr[num1] = num2;
        } else if (sign == '+') {
            cout << arr[num1]+arr[num2] << endl;
        } else if (sign == '-') {
            cout << arr[num1]-arr[num2] << endl;
        } else if (sign == '*') {
            cout << arr[num1]*arr[num2] << endl;
        } else if (sign == '/') {
            cout << arr[num1]/arr[num2] << endl;
        } else if (sign == '%') {
            cout << arr[num1]%arr[num2] << endl;
        }
    }
    return 0;
}
