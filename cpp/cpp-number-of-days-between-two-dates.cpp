/*
Copyright notice:
© 2025 Adrian-Gabriel Doaga. All Rights Reserved.
Email: adriangabrieldoaga@gmail.com
Website: https://github.com/adriangabrieldoaga/pieces-of-code
*/

// C++ program to find number of days between two given dates, including the
// last day from the second date.

#include <iostream>

using std::cout;
using std::cin;
using std::cerr;

// This function counts the number of leap years before the given date.
// return type is the same type as n1 and n2 to prevent buffer overflow of the integer
unsigned long long int count_Leap_Years(int day, int month, int year)
{
    int years = year;

    // Check if the current year needs to be considered for the count of leap
    // years or not.
    if (month <= 2)
    {
        years--;
    }

    // A year is a leap year if it is a multiple of 4, but if it is a multiple
    // of 100, it must also be a multiple of 400.
    return years / 4 - years / 100 + years / 400;
}

int main()
{
    int earlier_year, earlier_month, earlier_day;
    int later_year, later_month, later_day;
    unsigned long long int days_each_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // elements are of the same type as n1 and n2
    // to prevent buffer overflow of the integer

    cout << "Earlier year: ";
    cin >> earlier_year;
    cout << "Earlier month: ";
    cin >> earlier_month;
    cout << "Earlier day: ";
    cin >> earlier_day;
    cout << "\nLater year: ";
    cin >> later_year;
    cout << "Later month: ";
    cin >> later_month;
    cout << "Later day: ";
    cin >> later_day;

    if (earlier_month < 1 || earlier_month > 12 || later_month < 1 || later_month > 12)
    {
        cerr << "Error: Month must be between 1 and 12.\n";
        return 1;
    }

    if (earlier_day < 1 || earlier_day > days_each_month[earlier_month - 1] ||
        later_day < 1 || later_day > days_each_month[later_month - 1])
    {
        cerr << "Error: Day is out of range for the given month.\n";
        return 1;
    }

    // Adjust February for leap year if necessary.
    if ((earlier_year % 4 == 0 && earlier_year % 100 != 0) || (earlier_year % 400 == 0))
    {
        days_each_month[1] = 29;
    }

    // count the total number of days before the first date d1

    // initialize count using years and day
    unsigned long long int n1 = earlier_year * 365 + earlier_day;

    // add days for months in the given date
    for (int i = 0; i < earlier_month - 1; i++)
    {
        n1 += days_each_month[i];
    }

    // Since every leap year has 366 days, add a day for every leap year.
    n1 += count_Leap_Years(earlier_day, earlier_month, earlier_year);

    // Reset February before calculating for the second date
    if ((later_year % 4 == 0 && later_year % 100 != 0) || (later_year % 400 == 0))
    {
        days_each_month[1] = 29;
    }
    else
    {
        days_each_month[1] = 28;
    }

    // count the total number of days before the second date d2

    unsigned long long int n2 = later_year * 365 + later_day;
    for (int i = 0; i < later_month - 1; i++)
    {
        n2 += days_each_month[i];
    }
    n2 += count_Leap_Years(later_day, later_month, later_year);

    // check for negative difference
    if (n1 > n2)
    {
        cerr << "Error: The earlier date is after the later date.\n";
        return 1;
    }

    cout << "\nIncluding the end date, the difference of days between the two dates is " << n2 - n1 + 1 << ".\n";
    // add 1 day to include the last day from the second date

    return 0;
}

/*
Input and output example:
Earlier year: 2008
Earlier month: 4
Earlier day: 15

Later year: 2012
Later month: 7
Later day: 7

Including the end date, the difference of days between the two dates is 1545.

*/
