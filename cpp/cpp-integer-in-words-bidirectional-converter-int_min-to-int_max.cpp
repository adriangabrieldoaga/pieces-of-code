// Copyright notice:
// © 2025 Adrian-Gabriel Doaga. All Rights Reserved.
// Email: adriangabrieldoaga@gmail.com
// Website: https://github.com/adriangabrieldoaga/pieces-of-code
// Year: 2025

#include <iostream>
#include <string>
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

string convert_Integers_Less_Than_Thousand(int integer_var)
{
    if (integer_var < 20)
    {
        return units[integer_var];
    }
    if (integer_var < 100)
    {
        int ten = integer_var / 10;
        int unit = integer_var % 10;
        return tens[ten] + (unit != 0 ? " " + units[unit] : "");
    }
    int hundred = integer_var / 100;
    int remainder = integer_var % 100;
    return units[hundred] + " hundred" + (remainder != 0 ? " " + convert_Integers_Less_Than_Thousand(remainder) : "");
}

string integer_To_Words(int integer_var)
{
    if (integer_var == 0)
    {
        return "zero";
    }
    if (integer_var < 0)
    {
        return "negative " + integer_To_Words(abs(integer_var));
    }

    if(integer_var == INT_MAX) return "two billion one hundred forty seven million four hundred eighty three thousand six hundred forty seven";
    if(integer_var == INT_MIN) return "negative two billion one hundred forty seven million four hundred eighty three thousand six hundred forty eight";

    if (integer_var == 0) return "zero";
    if (integer_var < 0) return "negative " + integer_To_Words(abs(integer_var));

    string result = "";
    if (integer_var >= 1000000000) {
        result += convert_Integers_Less_Than_Thousand(integer_var / 1000000000) + " billion ";
        integer_var %= 1000000000;
    }
    if (integer_var >= 1000000) {
        result += convert_Integers_Less_Than_Thousand(integer_var / 1000000) + " million ";
        integer_var %= 1000000;
    }
    if (integer_var >= 1000) {
        result += convert_Integers_Less_Than_Thousand(integer_var / 1000) + " thousand ";
        integer_var %= 1000;
    }
    if (integer_var > 0) {
        result += convert_Integers_Less_Than_Thousand(integer_var);
    }
    // Remove trailing whitespace
    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }

    return result;
}

int words_To_Integer(const string& words) {
    map<string, int> words_to_integer_chart = {
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

    while (ss >> word) {
        if (word == "negative") {
            negative = true;
            continue;
        }

        if (words_to_integer_chart.find(word) != words_to_integer_chart.end()) {
            int value = words_to_integer_chart[word];
            if (value == 100) {
                current *= value;
            } else if (value == 1000 || value == 1000000 || value == 1000000000) {
                result += current * value;
                current = 0;
            } else {
                current += value;
            }
        } else {
            return 0; // Invalid word
        }
    }

    result += current;

    return negative ? -result : result;
}

int main()
{
    int choice;

    cout << "1. Integer to Words\n";
    cout << "2. Words to Integer\n";
    cout << "Choice: ";
    cin >> choice;
    cin.ignore();
    if (choice == 1)
    {
        int integer_var;
        cout << "Enter an integer: ";
        cin >> integer_var;
        cout << "Number in words: " << integer_To_Words(integer_var) << "\n";
    }
    else
    if (choice == 2)
    {
        string words;
        cout << "Enter number in words: ";
        getline(cin, words);
        cout << "Integer: " << words_To_Integer(words) << "\n";
    }
    else
    {
        cout << "Invalid choice\n";
    }

    return 0;
}

/*
Input and output example 1:
1. Integer to Words
2. Words to Integer
Choice: 1
Enter an integer: 2123456789
Number in words: two billion one hundred twenty three million four hundred fifty six thousand seven hundred eighty nine

Input and output example 2:
1. Integer to Words
2. Words to Integer
Choice: 2
Enter number in words: two billion one hundred twenty three million four hundred fifty six thousand seven hundred eighty nine
Integer: 2123456789

*/
