import sys

input = sys.stdin.readline


def preorder(node):
    if node == ".":
        return
    print(node, end='')
    left, right = tree[node]
    preorder(left)
    preorder(right)


def inorder(node):
    if node == ".":
        return
    left, right = tree[node]
    inorder(left)
    print(node, end='')
    inorder(right)


def postorder(node):
    if node == ".":
        return
    left, right = tree[node]
    postorder(left)
    postorder(right)
    print(node, end='')


tree = {}
n = int(input())

for _ in range(n):
    node, left, right = input().split()
    tree[node] = (left, right)

preorder('A')
print()
inorder('A')
print()
postorder('A')
print()
