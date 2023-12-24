// code is not accepted by SPOJ

#include <iostream>
#include <cmath>

using namespace std;

class Point {
public:
    string name;
    int x;
    int y;
    int distance;

    void calcDist() {
        distance = sqrt(x*x + y*y);
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        Point* arr = new Point[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i].name;
            cin >> arr[i].x;
            cin >> arr[i].y;
            arr[i].calcDist();
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (arr[j].distance > arr[j+1].distance) {
                    Point temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            cout << arr[i].name << " " << arr[i].x << " " << arr[i].y << endl;
        }
        delete [] arr;
        cout << endl;
    }

    return 0;
}
