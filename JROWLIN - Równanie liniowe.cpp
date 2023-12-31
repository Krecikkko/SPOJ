#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float a,b,c;
    float result;
    cin >> a >> b >> c;

    c -= b;
    if (a == 0) {
        if (c == 0) cout << "NWR" << endl;
        else cout << "BR" << endl;
    } else {
        cout << fixed << setprecision(2);
        cout << c/a << endl;
    }

    return 0;
}
