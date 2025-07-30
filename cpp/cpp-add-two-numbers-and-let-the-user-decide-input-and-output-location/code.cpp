/*
Copyright notice:
© 2025 Adrian-Gabriel Doaga. All Rights Reserved.
Email: adriangabrieldoaga@gmail.com
Website: https://github.com/adriangabrieldoaga/pieces-of-code
*/

#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::cerr;
using std::string;
using std::getline;
using std::stoi;
using std::ofstream;
using std::ifstream;

void generate_Example_File(const string &path)
{
    ofstream outfile(path);
    if (outfile.is_open())
    {
        outfile << "a = 3\n";
        outfile << "b = 4\n";
        outfile.close();
        cout << "Example file generated successfully at: " << path << "\n";
    }
    else
    {
        cerr << "Failed to create example file at: " << path << "\n";
    }
}

void get_Input_From_File(const string &path, int &a, int &b)
{
    ifstream infile(path);
    if (infile.is_open())
    {
        string line;
        while (getline(infile, line))
        {
            if (line.find("a = ") != string::npos)
            {
                a = stoi(line.substr(line.find('=') + 2));
            }
            else
            if (line.find("b = ") != string::npos)
            {
                b = stoi(line.substr(line.find('=') + 2));
            }
        }
        infile.close();
    }
    else
    {
        cerr << "Failed to open file at: " << path << "\n";
    }
}

void print_Output_To_File(const string &path, int sum)
{
    ofstream outfile(path);
    if (outfile.is_open())
    {
        outfile << "sum = " << sum << "\n";
        outfile.close();
        cout << "Output written successfully to: " << path << "\n";
    }
    else
    {
        cerr << "Failed to write to file at: " << path << "\n";
    }
}

int main()
{
    int choice;
    int a = 0, b = 0, sum = 0;

    while (true)
    {
        cout << "0. Close\n";
        cout << "1. Generate example of input text file\n";
        cout << "2. Get input from text file\n";
        cout << "3. Get input from terminal\n";
        cout << "Select option: ";
        cin >> choice;
        cout << "\n";

        if (choice == 0)
        {
            cout << "You closed the program.\n";
            break;
        }

        switch (choice)
        {
            case 1:
            {
                string path;
                cout << "Enter the absolute path of the file name to create, including the file name and extension: ";
                cin.ignore(); // To ignore the leftover newline character
                getline(cin, path);
                generate_Example_File(path);
                cout << "\n";
                continue;
            }
            case 2:
            {
                string path;
                cout << "Enter the absolute path of the input file, including the file name and extension: ";
                cin.ignore();
                getline(cin, path);
                get_Input_From_File(path, a, b);
                cout << "\n";
                break;
            }
            case 3:
            {
                cout << "a = ";
                cin >> a;
                cout << "b = ";
                cin >> b;
                cout << "\n";
                break;
            }
            default:
            {
                cout << "Invalid option. Try again." << "\n";
                continue;
            }
        }
        sum = a + b;

        // Now present the second set of options.
        while (true)
        {
            cout << "0. Close\n";
            cout << "1. Print output in text file\n";
            cout << "2. Print output in terminal\n";
            cout << "Select option: ";
            cin >> choice;
            cout << "\n";

            if (choice == 0)
            {
                cout << "You closed the program.\n";
                return 0;
            }

            switch (choice)
            {
                case 1:
                {
                    string path;
                    cout << "Enter the absolute path of the output file, including the file name and extension: ";
                    cin.ignore();
                    getline(cin, path);
                    print_Output_To_File(path, sum);
                    cout << "\n";
                    break;
                }
                case 2:
                {
                    cout << "sum = " << sum << "\n\n";
                    break;
                }
                default:
                {
                    cout << "Invalid option. Try again.\n";
                    continue;
                }
            }
            break; // Break out of the second set of options loop to return to the first menu.
        }
    }

    return 0;
}
