/*
Copyright notice:
© 2025 Adrian-Gabriel Doaga. All Rights Reserved.
Email: adriangabrieldoaga@gmail.com
Website: https://github.com/adriangabrieldoaga/pieces-of-code
*/

#include <iostream>
#include <map>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::pair;
using std::map;

string int_To_Roman(int int_var)
{
    vector<pair<int, string>> Roman_chart =
    {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    string result = "";
    for (const auto &pair : Roman_chart)
    {
        while (int_var >= pair.first)
        {
            result += pair.second;
            int_var -= pair.first;
        }
    }
    return result;
}

int Roman_To_Int(string Roman_numeral)
{
    map<char, int> Roman_chart = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int result = 0;
    int previous = 0;

    for (int i = Roman_numeral.length() - 1; i >= 0; i--)
    {
        int current = Roman_chart[Roman_numeral[i]];
        if (current < previous)
        {
            result -= current;
        }
        else
        {
            result += current;
        }
        previous = current;
    }
    return result;
}

int main()
{
    int choice;

    do
    {
        cout << "0. Close program\n";
        cout << "1. Integer to Roman\n";
        cout << "2. Roman to integer\n";
        cout << "3. Print all roman numerals from 1 to 3999\n";
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
            int int_var;
            cout << "Enter an integer (1 - 3999): ";
            cin >> int_var;
            if (int_var <= 0 || int_var > 3999)
            {
                cout << "Number out of range.\n";
            }
            else
            {
                cout << "Roman numeral: " << int_To_Roman(int_var) << "\n";
            }
            break;
        }
        else
        if (choice == 2)
        {
            string Roman_numeral;
            cout << "Enter a Roman numeral: ";
            cin >> Roman_numeral;
            cout << "Integer value: " << Roman_To_Int(Roman_numeral) << "\n";
            break;
        }
        else
        if (choice == 3)
        {
            for (int int_var = 1; int_var <= 3999; int_var++)
            {
                cout << int_var << " = " << int_To_Roman(int_var) << "\n";
            }
            break;
        }
        else
        {
            cout << "Invalid choice. Try again.\n\n";
            continue;
        }
    } while (true);

    return 0;
}
