#include <stdio.h>

char get_grade(int score)
{
    char result = 'F';
    if (score >= 90) {
        result = 'A';
    } else if (score >= 80) {
        result = 'B';
    } else if (score >= 70) {
        result = 'C';
    } else if (score >= 60) {
        result = 'D';
    }

    return result;
}

int main()
{
    int score;
    scanf("%d", &score);

    char grade = get_grade(score);
    printf("%c", grade);

    return 0;
}