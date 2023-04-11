#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
vector<short> sw;

int main(void) {
    fastio;
    int size, val;
    cin >> size;
    for (int i = 0; i < size; i++) {
        cin >> val;
        sw.push_back(val);
    }
    int n;
    cin >> n;
    while (n--) {
        int opt, num;
        cin >> opt >> num;
        if (opt == 1) {
            for (int i = num; i <= size; i += num) {
                sw[i - 1] = !sw[i - 1];
            }
        } else {
            sw[num - 1] = !sw[num - 1];
            for (int i = 1;; i++) {
                int left = num - i - 1;
                int right = num + i - 1;
                if (left < 0 || right >= size) {
                    break;
                }
                if (sw[left] == sw[right]) {
                    sw[left] = !sw[left];
                    sw[right] = !sw[right];
                } else {
                    break;
                }
            }
        }
    }
    for (int i = 0; i < size; i++) {
        if (i != 0 && i % 20 == 0) {
            cout << endl;
        }
        cout << sw[i] << ' ';
    }
}