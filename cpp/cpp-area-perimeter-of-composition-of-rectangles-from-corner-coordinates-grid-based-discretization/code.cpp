/*
Copyright notice:
© 2025 Adrian-Gabriel Doaga. All Rights Reserved.
Email: adriangabrieldoaga@gmail.com
Website: https://github.com/adriangabrieldoaga/pieces-of-code
*/

// A grid-based discretization approach to computing the area and perimeter of a figure formed by the composition of multiple
// rectangles from xmin, ymin, xmax, ymax.
// The solution is approximate, as an all-integer coordinate input will output an integer result.

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using std::cout;
using std::cerr;
using std::max;
using std::min;
using std::ifstream;
using std::pair;
using std::vector;
using std::set;

struct Rectangle
{
    double xmin, ymin, xmax, ymax;
};

pair<double, double> compute_Area_And_Perimeter_Of_Formed_Figure(const vector<Rectangle> &rectangles)
{
    set<pair<double, double>> points;
    for (const auto &element : rectangles)
    {
        points.insert({element.xmin, element.ymin});
        points.insert({element.xmax, element.ymin});
        points.insert({element.xmin, element.ymax});
        points.insert({element.xmax, element.ymax});
    }

    vector<double> x_coordinate, y_coordinate;
    for (const auto &point : points)
    {
        x_coordinate.push_back(point.first);
        y_coordinate.push_back(point.second);
    }

    sort(x_coordinate.begin(), x_coordinate.end());
    sort(y_coordinate.begin(), y_coordinate.end());
    x_coordinate.erase(unique(x_coordinate.begin(), x_coordinate.end()), x_coordinate.end());
    y_coordinate.erase(unique(y_coordinate.begin(), y_coordinate.end()), y_coordinate.end());

    vector<vector<int>> grid(x_coordinate.size() - 1, vector<int>(y_coordinate.size() - 1, 0));

    for (const auto &element : rectangles)
    {
        int x1 = lower_bound(x_coordinate.begin(), x_coordinate.end(), element.xmin) - x_coordinate.begin();
        int x2 = lower_bound(x_coordinate.begin(), x_coordinate.end(), element.xmax) - x_coordinate.begin();
        int y1 = lower_bound(y_coordinate.begin(), y_coordinate.end(), element.ymin) - y_coordinate.begin();
        int y2 = lower_bound(y_coordinate.begin(), y_coordinate.end(), element.ymax) - y_coordinate.begin();

        for (int i = x1; i < x2; i++)
        {
            for (int j = y1; j < y2; j++)
            {
                grid[i][j] = 1;
            }
        }
    }

    double total_area = 0;
    double total_perimeter = 0;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                total_area += (x_coordinate[i + 1] - x_coordinate[i]) * (y_coordinate[j + 1] - y_coordinate[j]);
                if (i == 0 || grid[i - 1][j] == 0)
                {
                    total_perimeter += (y_coordinate[j + 1] - y_coordinate[j]); // left edge
                }
                if (i == grid.size() - 1 || grid[i + 1][j] == 0)
                {
                    total_perimeter += (y_coordinate[j + 1] - y_coordinate[j]); // right edge
                }
                if (j == 0 || grid[i][j - 1] == 0)
                {
                    total_perimeter += (x_coordinate[i + 1] - x_coordinate[i]); // bottom edge
                }
                if (j == grid[i].size() - 1 || grid[i][j + 1] == 0)
                {
                    total_perimeter += (x_coordinate[i + 1] - x_coordinate[i]); // top edge
                }
            }
        }
    }

    return {total_area, total_perimeter};
}

int main()
{
    ifstream my_file("input-example-1.txt");

    if (!my_file.is_open())
    {
        cerr << "Couldn't open the input file.";
        return 1;
    }

    int n;
    my_file >> n;

    vector<Rectangle> rectangles(n);
    for (int i = 0; i < n; i++)
    {
        my_file >> rectangles[i].xmin >> rectangles[i].ymin >> rectangles[i].xmax >> rectangles[i].ymax;
    }
    my_file.close();

    pair<double, double> result = compute_Area_And_Perimeter_Of_Formed_Figure(rectangles);
    double area = result.first;
    double perimeter = result.second;

    cout << "Area: " << area << "\n";
    cout << "Perimeter: " << perimeter << "\n";

    return 0;
}

/*
Output example 1:
Area: 14
Perimeter: 22

Output example 2:
Area: 16.94
Perimeter: 24.2

*/
