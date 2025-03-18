#include <math.h>
#include <stdio.h>

int is_group_word(char s[])
{
    int count[26] = { 0 };

    for (int i = 0; s[i] != '\0'; i++) {
        int current = s[i];
        int next = s[i + 1];
        
        if (current == next) {
            continue;
        }
        
        int index = current - 'a';
        if (count[index] > 0) {
            return 0;
        }
        count[index]++;
    }

    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);

    char str[101];
    int answer = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        if (is_group_word(str)) {
            answer++;
        }
    }
    printf("%d", answer);

    return 0;
}