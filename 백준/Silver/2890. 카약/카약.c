#include <stdio.h>
#include <stdlib.h>

typedef struct info {
    int team;
    int progress;
    int rank;
} info;

int R, C;

int compare_by_progress(const info* a, const info* b)
{
    return a->progress - b->progress;
}

int compare_by_team_number(const info* a, const info* b)
{
    return a->team - b->team;
}

int main()
{
    scanf("%d %d", &R, &C);

    info teams[10] = { 0 };
    for (int r = 0; r < R; r++) {
        char s[55];
        scanf("%s", s);
        for (int c = 1; c < C - 1; c++) {
            if ('1' <= s[c] && s[c] <= '9') {
                int t = s[c] - '0';
                teams[t].team = t;
                teams[t].progress = C - 4 - c;
                break;
            }
        }
    }

    // calculate ranks
    qsort(teams + 1, 9, sizeof(info), compare_by_progress);
    int cur_rank = 1;
    teams[1].rank = cur_rank;
    for (int i = 2; i <= 9; ++i) {
        if (teams[i].progress > teams[i - 1].progress)
            ++cur_rank;
        teams[i].rank = cur_rank;
    }

    // sort by team number
    qsort(teams + 1, 9, sizeof(info), compare_by_team_number);

    for (int i = 1; i <= 9; ++i) {
        printf("%d\n", teams[i].rank);
    }
}