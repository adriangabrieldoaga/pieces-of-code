// Copyright notice:
// © 2024 Adrian-Gabriel Doaga. All Rights Reserved.
// Email: adriangabrieldoaga@gmail.com
// Website: https://github.com/adriangabrieldoaga/pieces-of-code

// Grid-based approach to compute the area and perimeter of the figure formed out of the composition of a number
// of rectangles from xmin, ymin, xmax, ymax

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using std::cout;
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

    vector<double> x_coordonate, y_coordonate;
    for (const auto &point : points)
    {
        x_coordonate.push_back(point.first);
        y_coordonate.push_back(point.second);
    }

    sort(x_coordonate.begin(), x_coordonate.end());
    sort(y_coordonate.begin(), y_coordonate.end());
    x_coordonate.erase(unique(x_coordonate.begin(), x_coordonate.end()), x_coordonate.end());
    y_coordonate.erase(unique(y_coordonate.begin(), y_coordonate.end()), y_coordonate.end());

    vector<vector<int>> grid(x_coordonate.size() - 1, vector<int>(y_coordonate.size() - 1, 0));

    for (const auto &element : rectangles)
    {
        int x1 = lower_bound(x_coordonate.begin(), x_coordonate.end(), element.xmin) - x_coordonate.begin();
        int x2 = lower_bound(x_coordonate.begin(), x_coordonate.end(), element.xmax) - x_coordonate.begin();
        int y1 = lower_bound(y_coordonate.begin(), y_coordonate.end(), element.ymin) - y_coordonate.begin();
        int y2 = lower_bound(y_coordonate.begin(), y_coordonate.end(), element.ymax) - y_coordonate.begin();

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
                total_area += (x_coordonate[i + 1] - x_coordonate[i]) * (y_coordonate[j + 1] - y_coordonate[j]);
                if (i == 0 || grid[i - 1][j] == 0)
                {
                    total_perimeter += (y_coordonate[j + 1] - y_coordonate[j]); // left edge
                }
                if (i == grid.size() - 1 || grid[i + 1][j] == 0)
                {
                    total_perimeter += (y_coordonate[j + 1] - y_coordonate[j]); // right edge
                }
                if (j == 0 || grid[i][j - 1] == 0)
                {
                    total_perimeter += (x_coordonate[i + 1] - x_coordonate[i]); // bottom edge
                }
                if (j == grid[i].size() - 1 || grid[i][j + 1] == 0)
                {
                    total_perimeter += (x_coordonate[i + 1] - x_coordonate[i]); // top edge
                }
            }
        }
    }

    return {total_area, total_perimeter};
}

int main()
{
    ifstream my_file("input.txt");

    int n;
    my_file >> n;

    vector<Rectangle> rectangles(n);
    for (int i = 0; i < n; i++)
    {
        my_file >> rectangles[i].xmin >> rectangles[i].ymin >> rectangles[i].xmax >> rectangles[i].ymax;
    }

    pair<double, double> result = compute_Area_And_Perimeter_Of_Formed_Figure(rectangles);
    double area = result.first;
    double perimeter = result.second;

    cout << "Area: " << area << "\n";
    cout << "Perimeter: " << perimeter << "\n";

    return 0;
}
