N = int(2e5 + 5)

par = []

def init(x):
    global par
    par = [i for i in range(1, x + 1)]

def find(x):
    if par[x] != x:
        par[x] = find(par[x])
    return par[x]

def unite(x, y):
    x = find(x)
    y = find(y)
    if x != y: par[x] = y

def same(x, y):
    return find(x) == find(y)

def solve():
    n, x ,y = map(int, input().split())
    init(n)
    if n == 1: unite(x, y)
    elif same(x, y): print("Y")
    else: print("N")

solve()
    