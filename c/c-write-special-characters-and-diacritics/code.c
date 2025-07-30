// crt_setmodeunicode.c (C source file used to configure the input/output modes for Unicode compatibility)
// This program uses _setmode to change stdout to Unicode. Cyrillic and Ideographic characters will appear on the console (if your console font supports
// those character sets).

#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <wchar.h>

int main()
{
    _setmode(_fileno(stdout), 0x00020000);
    int n = 2;
    wchar_t ch = L'ș';
    wchar_t str[20] = L"aaaî";
    wchar_t str_input[20];
    wprintf(L"ăĂîÎAâÂșȘțȚ\n"); // you can also use unicode, for example: wprintf(L"\x0040");
                               // and it'll print "@"
    wprintf(L"\x0040\n");
    wprintf(L"%d\n", 1);
    wprintf(L"%d\n", n);
    wprintf(L"%c\n", L'ă');
    wprintf(L"%c\n", ch);
    wprintf(L"%s\n", str);
    wprintf(L"Enter an integer: ");
    wscanf(L"%d", &n);
    wprintf(L"%d\n", n);
    wprintf(L"Enter a string: ");
    wscanf(L"%ls", str_input); // reading with diacritics does not work, but if
                               // you comment out the _setmode command at the beginning, this function works
                               // with some special characters
    wprintf(L"%ls", str_input);
    wprintf(L"\n");

    return 0;
}

