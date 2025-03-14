// Copyright notice:
// © 2025 Adrian-Gabriel Doaga. All Rights Reserved.
// Email: adriangabrieldoaga@gmail.com
// Website: https://github.com/adriangabrieldoaga/pieces-of-code
// Year: 2025

#include <iostream>
#include <map>
#include <vector>
#include <sstream>

using std::cout;
using std::cin;
using std::string;
using std::stringstream;
using std::map;

map<int, string> integer_to_words_chart =
{
    {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}, {10, "ten"},
    {11, "eleven"}, {12, "twelve"}, {13, "thirteen"}, {14, "fourteen"}, {15, "fifteen"}, {16, "sixteen"}, {17, "seventeen"}, {18, "eighteen"}, {19, "nineteen"},
    {20, "twenty"}, {30, "thirty"}, {40, "forty"}, {50, "fifty"}, {60, "sixty"}, {70, "seventy"}, {80, "eighty"}, {90, "ninety"}, {100, "hundred"}, {1000, "thousand"}
};
map<string, int> words_to_integer_chart;

void initialize_Words_To_Integer_Chart()
{
    for (const auto &pair : integer_to_words_chart)
    {
        words_to_integer_chart[pair.second] = pair.first;
    }
    words_to_integer_chart["zero"] = 0;
}

string integer_To_Words(int integer_var)
{
    if (integer_var == 0)
    {
        return "zero";
    }
    string result = "";
    if (integer_var >= 1000)
    {
        result += integer_To_Words(integer_var / 1000) + " thousand ";
        integer_var %= 1000;
    }
    if (integer_var >= 100)
    {
        result += integer_To_Words(integer_var / 100) + " hundred ";
        integer_var %= 100;
    }
    if (integer_var > 0)
    {
        if (!result.empty() && integer_var < 100)
        {
            result += "and ";
        }
        if (integer_to_words_chart.count(integer_var))
        {
            result += integer_to_words_chart[integer_var];
        }
        else
        {
            result += integer_to_words_chart[(integer_var / 10) * 10] + " " + integer_to_words_chart[integer_var % 10];
        }
    }
    return result;
}

int words_To_Integer(string words)
{
    stringstream ss(words);
    string word;
    int result = 0, current = 0;
    while (ss >> word)
    {
        if (word == "thousand")
        {
            result += current * 1000;
            current = 0;
        }
        else
        if (word == "hundred")
        {
            current *= 100;
        }
        else
        if (word == "and")
        {
            continue;
        }
        else
        {
            current += words_to_integer_chart[word];
        }
    }
    return result + current;
}

int main()
{
    int choice;

    initialize_Words_To_Integer_Chart();
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
        cout << "Invalid choice!\n";
    }

    return 0;
}

/*
Input and output example 1:
1. Integer to Words
2. Words to Integer
Choice: 1
Enter an integer: 9123
Number in words: nine thousand one hundred and twenty three

Input and output example 2:
1. Integer to Words
2. Words to Integer
Choice: 2
Enter number in words: nine thousand one hundred and twenty three
Integer: 9123

*/
