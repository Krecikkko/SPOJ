#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        int num;
        cin >> num;
        if (num == 1) {
            cout << "NIE" << endl;
            continue;
        } else if (num == 2) {
            cout << "TAK" << endl;
            continue;
        }
        bool is_first = true;
        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                is_first = false;
                break;
            } else {
                is_first = true;
            }
        }
        if (is_first) cout << "TAK" << endl;
        else cout << "NIE" << endl;
    }
    return 0;
}
