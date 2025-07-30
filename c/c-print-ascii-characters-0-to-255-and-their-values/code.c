#include <stdio.h>

int main()
{
    int i;

    printf("Each right delimiter is followed by 3 newline characters. This line is also followed by 3 newline characters.\n\n\n");
    for (i = 0; i < 256; i++)
    {
        printf("%d: [left delimiter]%c[right delimiter]\n\n\n", i, i);
    }

    return 0;
}
