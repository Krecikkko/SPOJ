#include <iostream>

using namespace std;

int nwd(int a, int b) {
    // Euclides' algorythm
    if (a%b == 0) return b;
    return nwd(b, a%b);
}

int main() {
    int t;
    int a,b;
    cin >> t;

    while (t--) {
        cin >> a >> b;
        cout << nwd(a, b) << endl;
    }

    return 0;
}
