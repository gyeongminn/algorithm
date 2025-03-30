#include <stdio.h>
#define MAX(a, b) (a > b ? a : b)
#define CARD_SIZE 5

int calculate_score(const int* cards, const int depth, const int selected, int sum)
{
	if (selected == 3) {
		return sum % 10;
	}
	if (depth == CARD_SIZE) {
		return -99999;
	}

	int chosen = calculate_score(cards, depth + 1, selected + 1, sum + cards[depth]);
	int not_chosen = calculate_score(cards, depth + 1, selected, sum);

	return MAX(chosen, not_chosen);
}

int main()
{
	int n;
	scanf("%d", &n);

	int winner = 0, max_score = 0;
	for (int i = 0; i < n; i++) {
		int cards[CARD_SIZE];
		for (int j = 0; j < CARD_SIZE; j++) {
			scanf("%d", &cards[j]);
		}

		int score = calculate_score(cards, 0, 0, 0);
		if (max_score <= score) {
			winner = i + 1;
			max_score = score;
		}
	}

	printf("%d", winner);
}
