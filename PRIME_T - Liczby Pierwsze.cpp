#include <iostream>

using namespace std;

bool check_if_is_first(int num) {
    if (num == 1) {
        return false;
    } else if (num == 2) {
        return true;
    }
    bool is_first = true;
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int num;
        cin >> num;
        if (check_if_is_first(num)) cout << "TAK" << endl;
        else cout << "NIE" << endl;
    }
    return 0;
}
