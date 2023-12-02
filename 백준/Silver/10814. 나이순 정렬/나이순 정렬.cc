#include <bits/stdc++.h>
using namespace std;

struct person {
  int age;
  string name;
};

int compare(const person &a, const person &b) {
    return a.age < b.age;
}

int N;
person A[100'000];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i].age >> A[i].name;
    }

    stable_sort(A, A + N, compare);

    for (int i = 0; i < N; ++i) {
        person p = A[i];
        cout << p.age << ' ' << p.name << '\n';
    }

    return 0;
}