#include <bits/stdc++.h>
using namespace std;

typedef struct node {
  node *prev, *next;
  int number;
} node;

unordered_map<int, node *> dict;
node *head, *tail;

void print(node *p) {
    cout << p->number << '\n';
}

node *generate_node(node *prev, node *next, int number) {
    node *p = (node *)malloc(sizeof(node));
    p->number = number;
    p->prev = prev;
    p->next = next;
    dict[number] = p;
    return p;
}

void insert_prev(node *p, int number) {
    node *new_node = generate_node(p->prev, p, number);
    p->prev->next = new_node;
    p->prev = new_node;
}

void insert_next(node *p, int number) {
    node *new_node = generate_node(p, p->next, number);
    p->next->prev = new_node;
    p->next = new_node;
}

int remove(node *p) {
    p->next->prev = p->prev;
    p->prev->next = p->next;

    int number = p->number;
    free(p);
    dict[number] = nullptr;

    return number;
}

void solve(string command) {
    int i, j;
    cin >> i;
    if (command[0] == 'B') cin >> j;

    node *p = dict[i];
    if (p == nullptr) {
        cout << "null!\n";
        return;
    }

    if (command == "BN") {
        print(p->next);
        insert_next(p, j);
    } else if (command == "BP") {
        print(p->prev);
        insert_prev(p, j);
    } else if (command == "CP") {
        cout << remove(p->prev) << '\n';
    } else if (command == "CN") {
        cout << remove(p->next) << '\n';
    }
}

void initialize() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    head = generate_node(nullptr, nullptr, 0);
    tail = generate_node(head, nullptr, 0);
    head->next = tail;
}

int main() {
    initialize();

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int number;
        cin >> number;
        insert_next(tail->prev, number);
    }

    node *first = head->next;
    node *last = tail->prev;
    first->prev = last;
    last->next = first;

    for (int i = 0; i < m; ++i) {
        string command;
        cin >> command;
        solve(command);
    }
    
    return 0;
}