// The Unlicense
// This is basic code, you can use it freely, without any restrictions or attribution.
// Creator: Adrian-Gabriel Doaga
// Email: adriangabrieldoaga@gmail.com
// Website: https://github.com/adriangabrieldoaga/pieces-of-code
// Year: 2024

#include <iostream>

using std::cout;
using std::cin;

int main()
{
    int l1, c1, l2, c2, i, j, k;
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
