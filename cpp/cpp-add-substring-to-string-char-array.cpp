/*
The Unlicense
This is basic code, you can use it freely, without any restrictions or attribution.
Creator: Adrian-Gabriel Doaga
Email: adriangabrieldoaga@gmail.com
Website: https://github.com/adriangabrieldoaga/pieces-of-code
Year: 2025
*/

#include <iostream>
#include <cstring>

using std::cout;
using std::cerr;

int main()
{
    char initial_string[] = "abcdefg";
    size_t initial_string_length = strlen(initial_string);
    char substring_to_add[] = "123";
    char buffer_string[initial_string_length + strlen(substring_to_add)+1] = "";
    char *p = nullptr;
    int position = 4; // position of added substring

    if (position < 1 || position > initial_string_length + 1)
    {
        cerr << "Invalid position\n";
        return 1;
    }

    p = initial_string + position - 1;
    strncat(buffer_string, initial_string, p - initial_string);
    strcat(buffer_string, substring_to_add);
    strcat(buffer_string, p);
    strcpy(initial_string, buffer_string);

    cout << initial_string << "\n";

    return 0;
}

/*
Output:
abc123defg

*/
