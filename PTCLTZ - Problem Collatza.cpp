#include <iostream>

using namespace std;

int main() {
    int t, s, iterations;
    cin >> t;

    for (int i = 0; i < t; i++) {
        iterations = 0;
        cin >> s;

        while (s != 1) {
            if (s % 2 == 0) {
                s = s / 2;
            } else {
                s = 3 * s + 1;
            }

            iterations++;
        }

        cout << iterations << endl;
    }

    return 0;
}
