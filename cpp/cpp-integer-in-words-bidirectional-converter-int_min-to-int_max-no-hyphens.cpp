/*
Copyright notice:
© 2025 Adrian-Gabriel Doaga. All Rights Reserved.
Email: adriangabrieldoaga@gmail.com
Website: https://github.com/adriangabrieldoaga/pieces-of-code
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using std::cout;
using std::cin;
using std::string;
using std::stringstream;
using std::map;

map<int, string> units =
{
    {0, "zero"}, {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}, {10, "ten"},
    {11, "eleven"}, {12, "twelve"}, {13, "thirteen"}, {14, "fourteen"}, {15, "fifteen"}, {16, "sixteen"}, {17, "seventeen"},
    {18, "eighteen"}, {19, "nineteen"}
};

map<int, string> tens =
{
    {2, "twenty"}, {3, "thirty"}, {4, "forty"}, {5, "fifty"},
    {6, "sixty"}, {7, "seventy"}, {8, "eighty"}, {9, "ninety"}
};

string convert_Integers_Less_Than_Thousand(int int_var)
{
    if (int_var < 20)
    {
        return units[int_var];
    }
    if (int_var < 100)
    {
        int ten = int_var / 10;
        int unit = int_var % 10;
        return tens[ten] + (unit != 0 ? " " + units[unit] : "");
    }
    int hundred = int_var / 100;
    int remainder = int_var % 100;
    return units[hundred] + " hundred" + (remainder != 0 ? " " + convert_Integers_Less_Than_Thousand(remainder) : "");
}

string integer_To_Words(int int_var)
{
    if (int_var == 0)
    {
        return "zero";
    }
    if (int_var < 0)
    {
        return "negative " + integer_To_Words(abs(int_var));
    }

    // Just for conserving the convention
    if( int_var == INT_MAX)
    {
        return "two billion one hundred forty seven million four hundred eighty three thousand six hundred forty seven";
    }
    if(int_var == INT_MIN)
    {
        return "negative two billion one hundred forty seven million four hundred eighty three thousand six hundred forty eight";
    }

    string result = "";
    if (int_var >= 1000000000)
    {
        result += convert_Integers_Less_Than_Thousand(int_var / 1000000000) + " billion ";
        int_var %= 1000000000;
    }
    if (int_var >= 1000000)
    {
        result += convert_Integers_Less_Than_Thousand(int_var / 1000000) + " million ";
        int_var %= 1000000;
    }
    if (int_var >= 1000)
    {
        result += convert_Integers_Less_Than_Thousand(int_var / 1000) + " thousand ";
        int_var %= 1000;
    }
    if (int_var > 0)
    {
        result += convert_Integers_Less_Than_Thousand(int_var);
    }
    // Remove trailing whitespace
    if (!result.empty() && result.back() == ' ')
    {
        result.pop_back();
    }

    return result;
}

int words_To_Integer(const string& words)
{
    map<string, int> words_to_integer_chart =
    {
        {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
        {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9},
        {"ten", 10}, {"eleven", 11}, {"twelve", 12}, {"thirteen", 13},
        {"fourteen", 14}, {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17},
        {"eighteen", 18}, {"nineteen", 19}, {"twenty", 20}, {"thirty", 30},
        {"forty", 40}, {"fifty", 50}, {"sixty", 60}, {"seventy", 70},
        {"eighty", 80}, {"ninety", 90}, {"hundred", 100}, {"thousand", 1000},
        {"million", 1000000}, {"billion", 1000000000}
    };

    stringstream ss(words);
    string word;
    long long result = 0;
    long long current = 0;
    bool negative = false;

    while (ss >> word)
    {
        if (word == "negative")
        {
            negative = true;
            continue;
        }
        if (words_to_integer_chart.find(word) != words_to_integer_chart.end())
        {
            int value = words_to_integer_chart[word];
            if (value == 100)
            {
                current *= value;
            }
            else
            if (value == 1000 || value == 1000000 || value == 1000000000)
            {
                result += current * value;
                current = 0;
            }
            else
            {
                current += value;
            }
        }
        else
        {
            return 0; // Invalid word
        }
    }
    result += current;
    if (negative)
    {
        return -result;
    }
    else
    {
        return result;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "0. Close program\n";
        cout << "1. Integer to Words\n";
        cout << "2. Words to Integer\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();
        if (choice == 0)
        {
            cout << "You closed the program.\n";
            break;
        }
        else
        if (choice == 1)
        {
            int int_var;
            cout << "Enter an integer: ";
            cin >> int_var;
            cout << "Number in words: " << integer_To_Words(int_var) << "\n";
            break;
        }
        else
        if (choice == 2)
        {
            string words;
            cout << "Enter number in words: ";
            getline(cin, words);
            cout << "Integer: " << words_To_Integer(words) << "\n";
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

/*
Input and output example 1:
0. Close program
1. Integer to Words
2. Words to Integer
Choice: 1
Enter an integer: -2123456789
Number in words: negative two billion one hundred twenty three million four hundred fifty six thousand seven hundred eighty nine

Input and output example 2:
0. Close program
1. Integer to Words
2. Words to Integer
Choice: 2
Enter number in words: negative two billion one hundred twenty three million four hundred fifty six thousand seven hundred eighty nine
Integer: -2123456789

*/
