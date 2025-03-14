#include <iostream>
#include <cstring>

using std::cout;

int main()
{
    char initial_string[] = "abcdefgcdefg";
    char substring_to_delete[] = "cd";
    char *p = NULL;
    int substring_to_delete_length = strlen(substring_to_delete);

    p = strstr(initial_string, substring_to_delete);
    while (p)
    {
        strcpy(p, p + substring_to_delete_length);
        p = strstr(initial_string, substring_to_delete);
    }

    cout << initial_string << "\n";

    return 0;
}
