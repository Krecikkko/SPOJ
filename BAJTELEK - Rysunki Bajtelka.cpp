#include <iostream>
#include <vector>

using namespace std;

struct Coord
{
    int x, y;

    Coord() : x(0), y(0) {}
    Coord(const int x, const int y) : x(x), y(y) {}
};

struct Polyline
{
    vector<Coord> points;
};

struct Drawing
{
private:
    vector<Polyline> polylines;
public:
    void addPolyline(Polyline polyline)
    {
        polylines.push_back(polyline);
    }
};

int main() {
    int n;

    cin >> n;

    Drawing drawing;
    for (int i = 0; i < 2 * n; i++)
    {
        Coord* firstCord = nullptr;
        Polyline polyline;
        while (true)
        {
            Coord coord;
            cin >> coord.x >> coord.y;

            if (firstCord == nullptr)
            {
                firstCord = &polyline.points.back();
            } else if (firstCord->x == coord.x && firstCord->y == coord.y)
            {
                break;
            }

            polyline.points.push_back(coord);
        }
        drawing.addPolyline(polyline);
    }

    return 0;
}