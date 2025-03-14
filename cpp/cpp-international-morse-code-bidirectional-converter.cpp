// Copyright notice:
// © 2025 Adrian-Gabriel Doaga. All Rights Reserved.
// Email: adriangabrieldoaga@gmail.com
// Website: https://github.com/adriangabrieldoaga/pieces-of-code
// Year: 2025

// Bibliography: https://en.wikipedia.org/wiki/Morse_code

#include <iostream>
#include <map>
#include <sstream>

using std::cout;
using std::cin;
using std::string;
using std::map;

int main()
{
    int choice;
    string message;
    bool valid = true;
    map<char, string> morse_chart =
    {
        {'a', ".-"}, {'b', "-..."}, {'c', "-.-."}, {'d', "-.."}, {'e', "."},
        {'f', "..-."}, {'g', "--."}, {'h', "...."}, {'i', ".."}, {'j', ".---"},
        {'k', "-.-"}, {'l', ".-.."}, {'m', "--"}, {'n', "-."}, {'o', "---"},
        {'p', ".--."}, {'q', "--.-"}, {'r', ".-."}, {'s', "..."}, {'t', "-"},
        {'u', "..-"}, {'v', "...-"}, {'w', ".--"}, {'x', "-..-"}, {'y', "-.--"},
        {'z', "--.."}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
        {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."},
        {'8', "---.."}, {'9', "----."}, {'0', "-----"}
    };
    map<string, char> reverse_Morse;

    for (auto& pair : morse_chart)
    {
        reverse_Morse[pair.second] = pair.first;
    }
    cout << "1. Alphanumeric to Morse\n";
    cout << "2. Morse to alphanumeric\n";
    cout << "Choice: ";
    cin >> choice;
    cin.ignore();
    if (choice == 1)
    {
        cout << "Alphanumeric message:\n";
        getline(cin, message);
        cout << "\nMorse code:\n";
        for (char c : message)
        {
            if (c == ' ')
            {
                cout << "  "; // 3 spaces between words
            }
            else if (morse_chart.count(tolower(c)))
            {
                cout << morse_chart[tolower(c)] << " ";
            }
            else
            {
                cout << c << " ";
                valid = false;
            }
        }
        cout << "\n";
        if (!valid)
        {
            cout << "\nFound invalid characters\n";
        }
    }
    else if (choice == 2)
    {
        cout << "Morse code message:\n";
        getline(cin, message);
        std::istringstream iss(message);
        string Morse_char;
        cout << "\nAlphanumeric message:\n";
        while (iss >> Morse_char)
        {
            if (reverse_Morse.count(Morse_char))
            {
                cout << reverse_Morse[Morse_char];
            }
            else
            {
                cout << "?"; // Invalid Morse sequence
                valid = false;
            }
            if (iss.peek() == ' ')
            {
                iss.get(); // Consume space
                if (iss.peek() == ' ')
                {
                    iss.get(); // Consume another space
                    cout << " "; // Print space between words
                }
            }
        }
        cout << "\n";
        if (!valid)
        {
            cout << "\nFound invalid Morse sequences\n";
        }
    }
    else
    {
        cout << "Invalid choice.\n";
    }

    return 0;
}

/*
Input and output example 1:
1. Alphanumeric to Morse
2. Morse to alphanumeric
Choice: 1
Alphanumeric message:
This 1 is 2 a 3 test

Morse code:
- .... .. ...   .----   .. ...   ..---   .-   ...--   - . ... -

Input and output example 2:
1. Alphanumeric to Morse
2. Morse to alphanumeric
Choice: 2
Morse code message:
- .... .. ...   .----   .. ...   ..---   .-   ...--   - . ... -

Alphanumeric message:
this 1 is 2 a 3 test

Input and output example 3:
1. Alphanumeric to Morse
2. Morse to alphanumeric
Choice: 1
Alphanumeric message:
This 1 is 2 a @ test

Morse code:
- .... .. ...   .----   .. ...   ..---   .-   @   - . ... -

Found invalid characters

Input and output example 4:
1. Alphanumeric to Morse
2. Morse to alphanumeric
Choice: 2
Morse code message:
- .... .. ...   .----   .. ...   ..---   .-   ..a.--   - . ... -

Alphanumeric message:
this 1 is 2 a ? test

Found invalid Morse sequences

Input and output example 5:
1. Alphanumeric to Morse
2. Morse to alphanumeric
Choice: 2
Morse code message:
- .... .. ...   .----   .. ...   ..---   .---.--.-   ...--   - . ... -

Alphanumeric message:
this 1 is 2 ? 3 test

Found invalid Morse sequences

*/
