def cut_sum(cutter):
    sum = 0
    for tree in tree_arr:
        height = tree - cutter
        if height > 0:
            sum += height
    return sum


def search(start, end, target):
    if start > end:
        return end
    mid = (start + end) // 2
    if cut_sum(mid) >= target:
        return search(mid + 1, end, target)
    else:
        return search(start, mid - 1, target)


n, m = map(int, input().split())
tree_arr = [int(x) for x in input().split()]
print(search(1, max(tree_arr), m))
