#include <iostream>
#include <stdexcept>

using namespace std;

struct Point {
    int x, y;

    int& operator[](const int idx) {
        if (idx == 0) {
            return this->x;
        }
        if (idx == 1) {
            return this->y;
        }
        throw invalid_argument("Wrong index value. The correct one is 0 or 1.");
    }

    Point operator-(Point& p) const {
        const int newX = this->x - p[0];
        const int newY = this->y - p[1];
        return Point{newX, newY};
    }

    void operator-=(Point& p) {
        this->x -= p[0];
        this->y -= p[1];
    }

    // Check if point is in (0, 0) so in the center of cartesian system
    bool isCentre() const {
        return (!x && !y);
    }
};

class Triangle {
    Point points[3]{};
public:
    Triangle(const Point points[3]) {
        for (int i = 0 ; i < 3; i++) {
            this->points[i] = points[i];
        }
    }

    bool isPointInside(Point point) {
        // Barycentric coordinates system
        // B = B - A
        points[1] -= points[0];
        // C = C - A
        points[2] -= points[0];
        // P = P - A
        point -= points[0];

        // d = x2y3 - x3y2
        int d = points[1][0] * points[2][1] - points[2][0] * points[1][1];

        int w1 = point[0] * (points[1][2] - points[2][2]) + point[1] * (points[2][0] - points[1][0]) + points[1][0] * points[2][1] - points[2][0] * points[1][1];
        int w2 = point[0] * points[2][1] - point[1] * points[2][0];
        int w3 = point[1] * points[1][0] - point[0] * points[1][1];

        return checkIfInBounds(w1, 0, d) && checkIfInBounds(w2, 0, d) && checkIfInBounds(w3, 0, d);
    }

    bool checkIfInBounds(int val, int min, int max) {
        return val >= min && val <= max;
    }
};

int main() {
    while (true) {
        Point trianglePoints[3] = {};
        Point point{};
        bool isEnd = true;
        for (Point& p : trianglePoints) {
            for (int j = 0; j < 2; j++) {
                cin >> p[j];
                if (!p.isCentre()) isEnd = false;
            }
        }
        cin >> point[0] >> point[1];
        if (!point.isCentre()) isEnd = false;
        // Check if all the points are in (0, 0) so in the center of cartesian system
        if (isEnd) break;

        Triangle triangle(trianglePoints);


    }
}