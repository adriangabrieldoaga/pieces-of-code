#include <iostream>
#include <conio.h>

using std::cout;

int main()
{
    int i = 0;

    cout << "Press any key to increase count by 1.\n";
    cout << i << "\n";
    while (1)
    {
        _getch();
        i++;
        cout << i << "\n";
    }

    return 0;
}
