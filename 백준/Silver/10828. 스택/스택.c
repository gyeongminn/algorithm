#include <stdio.h>
#include <string.h>

int stack[10000];
int top = -1;

int is_empty() { return top == -1; }

void push(int data) { stack[++top] = data; }

int pop() { return stack[top--]; }

int main(void) {
    int n, item;
    char cmd[100] = "";
    scanf("%d", &n);
    while (n--) {
        scanf("%s", cmd);
        if (strcmp(cmd, "push") == 0) {
            scanf("%d", &item);
            push(item);
        } else if (strcmp(cmd, "pop") == 0) {
            if (is_empty()) {
                printf("-1\n");
            } else {
                printf("%d\n", pop());
            }
        } else if (strcmp(cmd, "size") == 0) {
            printf("%d\n", top + 1);
        } else if (strcmp(cmd, "empty") == 0) {
            if (is_empty()) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        } else if (strcmp(cmd, "top") == 0) {
            if (is_empty()) {
                printf("-1\n");
            } else {
                printf("%d\n", stack[top]);
            }
        }
    }
}