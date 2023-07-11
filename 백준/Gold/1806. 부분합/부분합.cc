#include <iostream>
#include <climits>
#define ull unsigned long long
using namespace std;

int N, S;
int A[100100];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> S;
	for (int i = 0; i < N; ++i) cin >> A[i];

	int s = 0, e = 0, ans = INT_MAX;
	ull sum = A[0];
	while (s < N) {
		while (e + 1 < N) {
			if (sum >= S) {
				ans = min(ans, e - s + 1);
				break;
			}
			sum += A[++e];
		}
		if (sum >= S) {
			ans = min(ans, e - s + 1);
		}
		sum -= A[s++];
	}
	if (ans == INT_MAX) ans = 0;
	cout << ans;
}