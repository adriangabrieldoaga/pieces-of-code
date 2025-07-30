/*
Copyright notice:
© 2025 Adrian-Gabriel Doaga. All Rights Reserved.
Email: adriangabrieldoaga@gmail.com
Website: https://github.com/adriangabrieldoaga/pieces-of-code
*/

// C++ program to get age in years, months and days from date of birth, including the date of today.

#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::cerr;

bool is_Leap_Year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int get_Days_In_Month(int month, int year)
{
    int days_each_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Adjust for leap year
    if (month == 2 && is_Leap_Year(year))
    {
        return 29;
    }
    return days_each_month[month - 1];
}

int main()
{
    int year_of_birth;
    int month_of_birth;
    int day_of_birth;

    cout << "Year of birth: ";
    cin >> year_of_birth;
    cout << "Month of birth: ";
    cin >> month_of_birth;
    cout << "Day of birth: ";
    cin >> day_of_birth;

    if (month_of_birth < 1 || month_of_birth > 12 || day_of_birth < 1 || day_of_birth > get_Days_In_Month(month_of_birth, year_of_birth))
    {
        cerr << "Invalid date of birth.\n";
        return 1;
    }

    // Get current time
    time_t t = time(0);
    tm* now = localtime(&t);

    // Current date: day/month/year
    int current_day = now->tm_mday;
    int current_month = now->tm_mon + 1;
    int current_year = now->tm_year + 1900;

   // Ensure birthdate is not in the future
    if (year_of_birth > current_year ||
        (year_of_birth == current_year && month_of_birth > current_month) ||
        (year_of_birth == current_year && month_of_birth == current_month && day_of_birth > current_day))
    {
        cerr << "Birthdate cannot be in the future.\n";
        return 1;
    }

    // Borrow days from previous month
    if (day_of_birth > current_day)
    {
        current_day += get_Days_In_Month(current_month - 1, current_year);
        current_month -= 1;
    }

    // Borrow months from previous year
    if (month_of_birth > current_month)
    {
        current_month += 12;
        current_year -= 1;
    }

    int calculated_years = current_year - year_of_birth;
    int calculated_months = current_month - month_of_birth;
    int calculated_days = current_day - day_of_birth;

    cout << "\nIncluding the date of today, the age is:\n"
         << "Years: " << calculated_years << "\n"
         << "Months: " << calculated_months << "\n"
         << "Days: " << calculated_days << "\n";

    return 0;
}

/*
Input and output example on 23rd of March, 2025:
Year of birth: 2003
Month of birth: 3
Day of birth: 21

Including the date of today, the age is:
Years: 21
Months: 11
Days: 22

*/
