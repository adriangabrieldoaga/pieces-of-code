/*
Copyright notice:
© 2025 Adrian-Gabriel Doaga. All Rights Reserved.
Email: adriangabrieldoaga@gmail.com
Website: https://github.com/adriangabrieldoaga/pieces-of-code
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <windows.h>

using std::vector;
using std::string;
using std::set;
using std::unordered_map;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::cin;
using std::cerr;
using std::getline;

vector<string> get_All_Text_Files_In_Current_Directory()
{
    vector<string> files;
    WIN32_FIND_DATA find_file_data;
    HANDLE h_find = FindFirstFile("*.txt", &find_file_data);

    if (h_find != INVALID_HANDLE_VALUE)
    {
        do
        {
            files.push_back(find_file_data.cFileName);
        } while (FindNextFile(h_find, &find_file_data));
        FindClose(h_find);
    }
    return files;
}

set<string> find_Identical_Lines(const vector<string>& files)
{
    unordered_map<string, int> line_count;
    int total_files = files.size();

    for (size_t i = 0; i < files.size(); i++)
    {
        ifstream infile(files[i].c_str());
        set<string> unique_lines;
        string line;

        while (getline(infile, line))
        {
            unique_lines.insert(line);
        }

        for (set<string>::iterator it = unique_lines.begin(); it != unique_lines.end(); it++)
        {
            line_count[*it]++;
        }
    }

    set<string> identical_lines;
    for (unordered_map<string, int>::iterator it = line_count.begin(); it != line_count.end(); it++)
    {
        if (it->second == total_files)
        {
            identical_lines.insert(it->first);
        }
    }

    return identical_lines;
}

void write_Identical_Lines_To_File(const set<string>& lines, const string& output_file)
{
    ofstream outfile(output_file.c_str());
    for (set<string>::const_iterator it = lines.begin(); it != lines.end(); it++)
    {
        outfile << *it << "\n";
    }
}

int main()
{
    int choice;

    cout << "0. Close\n";
    cout << "1. Find identical lines in all text files in this folder\n";
    cout << "2. Find identical lines in N specified text files\n";
    cout << "Select option: ";
    cin >> choice;
    cin.ignore();

    if (choice == 0)
        {
            cout << "You closed the program.\n";
            return 0;
        }

    vector<string> selected_files;

    if (choice == 1)
    {
        selected_files = get_All_Text_Files_In_Current_Directory();
    } else if (choice == 2)
    {
        cout << "\nEnter the number of files: ";
        int n;
        cin >> n;
        cin.ignore();

        for (int i = 0; i < n; i++)
        {
            cout << "Enter file path: ";
            string file_path;
            getline(cin, file_path);
            selected_files.push_back(file_path);
        }
    }
    else
    {
        cerr << "Invalid choice.\n";
        return 1;
    }

    if (selected_files.empty())
    {
        cerr << "No files to process.\n";
        return 1;
    }

    set<string> identical_lines = find_Identical_Lines(selected_files);
    write_Identical_Lines_To_File(identical_lines, "identical-lines.txt");
    cout << "\nIdentical lines have been written to identical-lines.txt\n";

    return 0;
}
