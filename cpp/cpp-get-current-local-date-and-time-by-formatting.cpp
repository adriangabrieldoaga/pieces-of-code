/*
Copyright notice:
© 2025 Adrian-Gabriel Doaga. All Rights Reserved.
Email: adriangabrieldoaga@gmail.com
Website: https://github.com/adriangabrieldoaga/pieces-of-code
*/

#include <iostream>
#include <ctime>

using std::cout;

int main()
{
    // Get time now
    time_t t = time(0);
    tm* now = localtime(&t);

    cout << "Year: " << (now->tm_year + 1900) << "\n"
         << "Month: " << (now->tm_mon + 1) << " (";

    switch (now->tm_mon + 1)
    {
        case 1:
            cout << "January";
            break;
        case 2:
            cout << "February";
            break;
        case 3:
            cout << "March";
            break;
        case 4:
            cout << "April";
            break;
        case 5:
            cout << "May";
            break;
        case 6:
            cout << "June";
            break;
        case 7:
            cout << "July";
            break;
        case 8:
            cout << "August";
            break;
        case 9:
            cout << "September";
            break;
        case 10:
            cout << "October";
            break;
        case 11:
            cout << "November";
            break;
        case 12:
            cout << "December";
    }

    cout << ") \n" << "Day: " << now->tm_mday << "\n"
         << "Time: " << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec << "\n";

    return 0;
}

/*
Output:
Year: 2025
Month: 3 (March)
Day: 15
Time: 10:46:28

*/
