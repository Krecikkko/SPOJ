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

    float calculateArea()
    {
        float fArea = 0.5 * ((points[1].x - points[0].x) * (points[2].y - points[0].y) -
            (points[1].y - points[0].y) * (points[2].x - points[0].y));
        float sArea = 0.5 * ((points[3].x - points[2].x) * (points[0].y - points[2].y) -
            (points[3].y - points[2].y) * (points[0].x - points[2].y));
        float area = fArea + sArea;
    }
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

    float calculateBlackArea() {}
};

int main() {
    int n;

    cin >> n;

    // Drawing drawing;
    for (int i = 0; i < n; i++)
    {
        Drawing drawing;
        for (int j = 0; j < 2; j++)
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
    }

    return 0;
}