#include<stdio.h>
#include<string.h>
int main() {
    int C, score[1001], person, N = 0, count = 0;
    float avg;
    scanf("%d", &C);
    for (int i = 0; i < C; i++) {
        scanf("%d", &person);
        for (int j = 0; j < person; j++) {
            scanf("%d", &score[j]);
            N += score[j];
        }
        avg = (float)N / person;
        for (int k = 0; k < person; k++) {
            if (avg < score[k])
                count++;
        }
        printf("%.3f%%\n", (float)count / person * 100);
        N = 0;
        count = 0;
    }
    return 0;
}