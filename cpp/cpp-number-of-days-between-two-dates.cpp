// C++ program to find number of days between two given dates (including the
// last day from the second date)

#include <iostream>

using std::cout;

// This function counts the number of leap years before the given date
int count_Leap_Years(int day, int month, int year)
{
    int years = year;
    // Check if the current year needs to be considered for the count of leap
    /// years or not
    if (month <= 2)
        years--;
    // A year is a leap year if it is a multiple of 4, but if it is a multiple
    // of 100, it must also be a multiple of 400
    return years / 4 - years / 100 + years / 400;
}

int main()
{
    int earlier_day = 1;
    int earlier_month = 2;
    int earlier_year = 2000;
    int later_day = 1;
    int later_month = 2;
    int later_year = 2004;
    int days_each_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // count the total number of days before the first date d1

    // initialize count using years and day
    long int n1 = earlier_year * 365 + earlier_day;

    // add days for months in the given date
    for (int i = 0; i < earlier_month - 1; i++)
        n1 += days_each_month[i];

    // since every leap year has 366 days, add a day for every leap year
    n1 += count_Leap_Years(earlier_day, earlier_month, earlier_year);

    // count the total number of days before the second date d2

    long int n2 = later_year * 365 + later_day;
    for (int i = 0; i < later_month - 1; i++)
        n2 += days_each_month[i];
    n2 += count_Leap_Years(later_day, later_month, later_year);

    cout << "The difference of days between the two dates is " << n2 - n1 + 1 << ", including the end date\n";
    // add 1 day to include the last day from the second date

    return 0;
}
