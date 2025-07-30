/*
Copyright notice:
© 2025 Adrian-Gabriel Doaga. All Rights Reserved.
Email: adriangabrieldoaga@gmail.com
Website: https://github.com/adriangabrieldoaga/pieces-of-code
*/

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

int main()
{
    int m, n, choice;

    cout << "Number of rows: ";
    cin >> m;
    cout << "Number of columns: ";
    cin >> n;

    vector<vector<double>> a(m, vector<double>(n));
    vector<vector<double>> b(n, vector<double>(m));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "a[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> a[i][j];
        }
    }

    cout << "\nYour matrix is:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    do
    {
        cout << "\n0. Close program\n";
        cout << "1. Rotate 90 degrees clockwise\n";
        cout << "2. Rotate 90 degrees counterclockwise\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 0)
        {
            cout << "You closed the program.\n";
            break;
        }
        else
        if (choice == 1)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    b[i][j] = a[m - j - 1][i];
                }
            }
        }
        else
        if (choice == 2)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    b[i][j] = a[j][n - i - 1];
                }
            }
        }
        else
        {
            cout << "Invalid choice. Try again.\n";
            continue;
        }
        break;
    } while (true);

    cout << "\nThe rotated matrix is:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*
Input and output example 1:
Number of rows: 3
Number of columns: 4
a[1][1] = 1
a[1][2] = 2
a[1][3] = 3
a[1][4] = 4
a[2][1] = 5
a[2][2] = 6
a[2][3] = 7
a[2][4] = 8
a[3][1] = 9
a[3][2] = 10
a[3][3] = 11
a[3][4] = 12

Your matrix is:
1 2 3 4
5 6 7 8
9 10 11 12

0. Close program
1. Rotate 90 degrees clockwise
2. Rotate 90 degrees counterclockwise
Choice: 1

The rotated matrix is:
9 5 1
10 6 2
11 7 3
12 8 4

Input and output example 2:
Number of rows: 3
Number of columns: 4
a[1][1] = 1
a[1][2] = 2
a[1][3] = 3
a[1][4] = 4
a[2][1] = 5
a[2][2] = 6
a[2][3] = 7
a[2][4] = 8
a[3][1] = 9
a[3][2] = 10
a[3][3] = 11
a[3][4] = 12

Your matrix is:
1 2 3 4
5 6 7 8
9 10 11 12

0. Close program
1. Rotate 90 degrees clockwise
2. Rotate 90 degrees counterclockwise
Choice: 2

The rotated matrix is:
4 8 12
3 7 11
2 6 10
1 5 9

*/
