// The Unlicense
// This is basic code, you can use it freely, without any restrictions or attribution.
// Creator: Adrian-Gabriel Doaga
// Email: adriangabrieldoaga@gmail.com
// Website: https://github.com/adriangabrieldoaga/pieces-of-code
// Year: 2024

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main()
{
    int i;

    for (i = 0; i < 135; i++)
    {
        fprintf(stderr, "%d: %s\n", i, strerror(i));
    }

    return 0;
}
