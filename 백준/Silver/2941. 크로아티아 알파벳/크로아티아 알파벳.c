#include <stdio.h>
#define TARGET_SIZE 8

char list[TARGET_SIZE][4] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

int check(const char* begin, const char* target)
{
    int index = 0;
    while (target[index]) {
        if (begin[index] == target[index]) {
            index++;
        } else {
            return 0;
        }
    }

    return index;
}

int main()
{
    char str[101];
    scanf("%s", str);

    int count = 0;
    for (char* p1 = str; *p1; p1++) {
        int is_matched = 0;
        for (int i = 0; i < TARGET_SIZE; i++) {
            int length = check(p1, list[i]);

            if (length > 0) {
                count++;
                p1 += length - 1;
                is_matched = 1;
                break;
            }
        }

        if (!is_matched) {
            count++;
        }
    }

    printf("%d", count);

    return 0;
}