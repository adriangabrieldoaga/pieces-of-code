/* The Unlicense
// You can use this code freely, without any restrictions or attribution.
// Creator: Adrian-Gabriel Doaga
// Email: adriangabrieldoaga@gmail.com
// Website: https://github.com/adriangabrieldoaga/pieces-of-code
// Year: 2025
*/

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>

int main()
{
    std::ifstream input_file("text-file-full-path");
    if (!input_file.is_open())
    {
        std::cerr << "Error: Could not open the file." << std::endl;
        return 1;
    }

    std::string line;
    std::regex pattern("^[a-zA-Z0-9]{8}: [a-zA-Z0-9]{2} [a-zA-Z0-9]{2}$");
    std::vector<int> matching_lines;
    bool consecutive_match = false;
    int line_index = 1;

    while (std::getline(input_file, line))
    {
        if (std::regex_match(line, pattern))
        {
            if (!consecutive_match)
            {
                matching_lines.push_back(line_index);
                consecutive_match = true;
            }
        }
        else
        {
            consecutive_match = false;
        }
        ++line_index;
    }
    input_file.close();

    if (matching_lines.empty())
    {
        std::cout << "All files are identical." << std::endl;
    }
    else
    {
        for (int index : matching_lines)
        {
            std::cout << "Matching line at index: " << index << std::endl;
        }
    }

    return 0;
}
