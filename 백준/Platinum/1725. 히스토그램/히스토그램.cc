#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A;

int maxSquareAreaWithDilation(int left, int right, int mid) {
    int low = mid, high = mid + 1;
    int height = min(A[low], A[high]);

    int ret = height * 2;
    while (left < low || high < right) {
        if ((high < right) && (low == left || A[low - 1] < A[high + 1])) {
            height = min(height, A[++high]);
        } else {
            height = min(height, A[--low]);
        }
        ret = max(ret, height * (high - low + 1));
    }

    return ret;
}

int solve(int left, int right) {
    if (left == right) return A[left];

    int mid = (left + right) / 2;

    int leftPart = solve(left, mid);
    int rightPart = solve(mid + 1, right);
    int midPart = maxSquareAreaWithDilation(left, right, mid);

    return max({leftPart, rightPart, midPart});
}

void input() {
    cin >> N;
    A.resize(N);
    for (int &i : A) cin >> i;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    cout << solve(0, N - 1);
    return 0;
}