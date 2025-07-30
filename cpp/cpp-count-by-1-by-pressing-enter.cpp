#include <iostream>
#include <limits>

using std::cout;
using std::cin;
using std::numeric_limits;
using std::streamsize;

int main()
{
    int i = 0;

    cout << "Press Enter to increase count by 1.\n";
    cout << i;
    while (1)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        i++;
        cout << i;
    }

    return 0;
}

