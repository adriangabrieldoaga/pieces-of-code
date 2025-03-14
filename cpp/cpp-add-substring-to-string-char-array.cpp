#include <iostream>
#include <cstring>

using std::cout;

int main()
{
    char initial_string[] = "abcdefg";
    char substring_to_add[] = "123";
    char buffer_string[strlen(initial_string) + strlen(substring_to_add)] = "";
    char *p = NULL;
    int position = 4; // position of added substring

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
