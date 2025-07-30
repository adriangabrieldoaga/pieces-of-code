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
    char initial_string[] = "abc123def123g";
    if (strlen(initial_string) == 0)
    {
        cerr << "The initial string cannot be empty.\n";
        return 1;
    }
    char substring_to_be_replaced[] = "123";
    size_t substring_to_be_replaced_length = strlen(substring_to_be_replaced);
    if (substring_to_be_replaced_length == 0)
    {
        cerr << "The substring to be replaced cannot be empty.\n";
        return 1;
    }
    char substring_that_replaces[] = "ABC";
    char *p = initial_string;
    char aux[1000]; // large size so that it works for multiple replacements

    while ((p = strstr(p, substring_to_be_replaced)) != nullptr)
    {
        // copy part before the match
        size_t prefix_len = p - initial_string;
        strncpy(aux, initial_string, prefix_len);
        aux[prefix_len] = '\0';  // Null-terminate

        // append the replacement string
        strcat(aux, substring_that_replaces);

        // append the rest after the match
        strcat(aux, p + substring_to_be_replaced_length);

        // copy the result back
        strcpy(initial_string, aux);

        // move past the replaced portion
        p = initial_string + prefix_len + strlen(substring_that_replaces);
    }

    cout << initial_string << "\n";

    return 0;
}

/*
Output:
abcABCdefABCg

*/
