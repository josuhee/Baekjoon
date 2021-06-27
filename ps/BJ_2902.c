//[백준] 2902 : KMP는 왜 KMP일까?

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char name[101];
    scanf("%s", name);

    for (int i = 0; i < strlen(name); i++)
        if (isupper(name[i]))
            printf("%c", name[i]);
    printf("\n");

    return 0;
}