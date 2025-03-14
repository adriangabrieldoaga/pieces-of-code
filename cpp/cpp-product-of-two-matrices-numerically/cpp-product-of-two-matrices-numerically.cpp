// The Unlicense
// This is basic code, you can use it freely, without any restrictions or attribution.
// Creator: Adrian-Gabriel Doaga
// Email: adriangabrieldoaga@gmail.com
// Website: https://github.com/adriangabrieldoaga/pieces-of-code
// Year: 2025

#include <iostream>
#include <iomanip> // For precision formatting

using std::cout;
using std::cin;

int main()
{
    int precision, l1, c1, l2, c2, i, j, k;

    cout << "Set product matrix decimal precision: ";
    cin >> precision;
    cout << std::fixed << std::setprecision(precision);
    cout << "Number of lines of the first matrix: ";
    cin >> l1;
    cout << "Number of columns of the first matrix: ";
    cin >> c1;
    cout << "Number of lines of the second matrix: ";
    cin >> l2;
    cout << "Number of columns of the second matrix: ";
    cin >> c2;

    if (c1 != l2)
    {
        cout << "To multiply two matrices, the number of columns of the first matrix must be equal to the number of lines of the second matrix\n";
        return 0;
    }

    double a[l1][c1], b[l2][c2];

    for (i = 0; i < l1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
    for (i = 0; i < l2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            cout << "b[" << i << "][" << j << "] = ";
            cin >> b[i][j];
        }
    }

    cout << "\nProduct matrix:\n";

    double product[l1][c2];
    // The product matrix will have as many lines as the first matrix and as many columns as the second matrix. Elements must be initialized with
    // 0 for the product matrix, because products must be added in a loop

    for (i = 0; i < l1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            product[i][j] = 0;
            for (k = 0; k < c1; k++)
            {
                product[i][j] += a[i][k] * b[k][j];
                // Add the products between the elements of the lines and the columns, one by one, in an element of the product
                // matrix, c1 and l2 being equal
            }
            cout << product[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*
Input and output example:
Set product matrix decimal precision: 7
Number of lines of the first matrix: 3
Number of columns of the first matrix: 4
Number of lines of the second matrix: 4
Number of columns of the second matrix: 5
a[0][0] = 1.1
a[0][1] = 2.2
a[0][2] = 3.3
a[0][3] = 4.4
a[1][0] = 5.5
a[1][1] = 6.6
a[1][2] = 7.7
a[1][3] = 8.8
a[2][0] = 9.9
a[2][1] = 10.1
a[2][2] = 11.11
a[2][3] = 12.12
b[0][0] = 13.13
b[0][1] = 14.14
b[0][2] = 15.15
b[0][3] = 16.16
b[0][4] = 17.17
b[1][0] = 18.18
b[1][1] = 19.19
b[1][2] = 20.2
b[1][3] = 21.21
b[1][4] = 22.22
b[2][0] = 23.23
b[2][1] = 24.24
b[2][2] = 25.25
b[2][3] = 26.26
b[2][4] = 27.27
b[3][0] = 28.28
b[3][1] = 29.29
b[3][2] = 30.3
b[3][3] = 31.31
b[3][4] = 32.32

Product matrix:
255.5300000 266.6400000 277.7500000 288.8600000 299.9700000
619.9380000 648.8240000 677.7100000 706.5960000 735.4820000
914.4439000 958.1062000 1001.7685000 1045.4308000 1089.0931000

*/
