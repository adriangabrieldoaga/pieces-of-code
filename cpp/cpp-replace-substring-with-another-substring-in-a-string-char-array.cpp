#include <iostream>
#include <cstring>

using std::cout;

int main()
{
    char initial_string[] = "abcdefgcdefg";
    char substring_that_replaces[] = "etg";
    char substring_to_be_replaced[] = "cd";
    char aux[strlen(initial_string) - strlen(substring_to_be_replaced) + strlen(substring_that_replaces) + 1];
    char *p {};

    p = strstr(initial_string, substring_to_be_replaced);
    while (p != 0)
    {
        strcpy(aux, substring_that_replaces);
        strcat(aux, p + strlen(substring_to_be_replaced) );
        strcpy(p, aux);
        p = strstr(p + strlen(substring_that_replaces), substring_to_be_replaced);
    }

    cout << initial_string << "\n";

    return 0;
}
