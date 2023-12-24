#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float r,d;
    long double circleArea, rCircle;

    cin >> r >> d;

    rCircle = r*r-d*d/4;
    circleArea = M_PI*rCircle;

    cout.precision(2);
    cout << fixed << circleArea;

    return 0;
}
