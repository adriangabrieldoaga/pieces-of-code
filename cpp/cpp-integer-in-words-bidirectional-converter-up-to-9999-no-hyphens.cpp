/*
Copyright notice:
© 2025 Adrian-Gabriel Doaga. All Rights Reserved.
Email: adriangabrieldoaga@gmail.com
Website: https://github.com/adriangabrieldoaga/pieces-of-code
*/

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

    string result = "";
    if (int_var >= 1000)
    {
        result += integer_To_Words(int_var / 1000) + " thousand ";
        int_var %= 1000;
    }
    if (int_var >= 100)
    {
        result += integer_To_Words(int_var / 100) + " hundred ";
        int_var %= 100;
    }
    if (int_var > 0)
    {
        if (!result.empty() && int_var < 100)
        {
            result += "and ";
        }
        if (integer_to_words_chart.count(int_var))
        {
            result += integer_to_words_chart[int_var];
        }
        else
        {
            result += integer_to_words_chart[(int_var / 10) * 10] + " " + integer_to_words_chart[int_var % 10];
        }
    }
    return result;
}

int words_To_Integer(string words)
{
    stringstream ss(words);
    string word;
    int result = 0, current = 0;
    bool negative = false;

    while (ss >> word)
    {
        if (word == "negative")
        {
            negative = true;
            continue;
        }
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
    if (negative)
    {
        return -(result + current);
    }
    else
    {
        return result + current;
    }
}

int main()
{
    int choice;

    initialize_Words_To_Integer_Chart();
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
Enter an integer: -9223
Number in words: negative nine thousand two hundred and twenty three

Input and output example 2:
0. Close program
1. Integer to Words
2. Words to Integer
Choice: 2
Enter number in words: negative nine thousand two hundred and twenty three
Integer: -9223

*/
