//Type 1 to rotate 90 degrees clockwise or 2 to rotate 90 degrees
// counterclockwise after reading the matrix

#include <iostream>

using std::cout;
using std::cin;

int main()
{
    int n, m, x, i, j;

    cout << "Number of lines: ";
    cin >> n;
    cout << "Number of columns: ";
    cin >> m;

    double a[n][m], b[m][n];

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
    cout << "\nYour matrix is:\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\nType 1 to rotate 90 degrees clockwise or 2 to rotate 90 degrees counterclockwise\n";
    cin >> x;
    if (x == 1)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= m; j++)
            {
                b[j][n - i + 1] = a[i][j];
            }
        }
    }
    else
    {
        if (x == 2)
        {
            for (i = 1; i <= n; i++)
            {
                for (j = 1; j <= m; j++)
                {
                    b[m - j + 1][i] = a[i][j];
                }
            }
        }
    }

    cout << "\nThe rotated matrix is:\n";
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
            {
                cout << b[i][j] << " ";
            }
        cout << "\n";
    }

    return 0;
}
