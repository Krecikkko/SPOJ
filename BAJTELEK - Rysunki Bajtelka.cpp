#include <iostream>
#include <vector>

#define BLACK_INK_BITOKUL 10
#define GRAY_INK_BITOKUL 6

using namespace std;

struct Coord
{
    long long x, y;

    Coord() : x(0), y(0) {}
    Coord(const int x, const int y) : x(x), y(y) {}
};

struct Polyline
{
    vector<Coord> points;

    double calculateArea()
    {
        // Using Shoelace Algorithm
        double area = 0.0;
        int n = points.size();
        if (n < 3) return 0;

        for (int i = 0; i < n; i++)
        {
            int j = (i + 1) % n;
            area += (double)points[i].x * points[j].y;
            area -= (double)points[j].x * points[i].y;
        }
        return abs(area) / 2.0;
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

    int getInkUsage()
    {
        if (polylines.size() < 0)
        {
            return 0;
        }

        double blackArea = polylines[0].calculateArea();
        double totalArea = polylines[1].calculateArea();
        double grayArea = totalArea - blackArea;

        return (int)(blackArea * BLACK_INK_BITOKUL + grayArea * GRAY_INK_BITOKUL);
    }
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
            Coord firstCord;
            bool hasFirst = false;
            Polyline polyline;
            while (true)
            {
                Coord coord;
                cin >> coord.x >> coord.y;

                if (!hasFirst)
                {
                    firstCord = coord;
                    hasFirst = true;
                    polyline.points.push_back(coord);
                    continue;
                }

                if (firstCord.x == coord.x && firstCord.y == coord.y)
                {
                    break;
                }

                polyline.points.push_back(coord);
            }
            drawing.addPolyline(polyline);
        }
        cout << drawing.getInkUsage() << endl;
    }
    return 0;
}

// Not finished