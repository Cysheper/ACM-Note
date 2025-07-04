e = [[] for i in range(1000)]
vis = [0 for i in range(1000)]
ans, poi = 0, 0
def dfs(x, dep):
    global ans
    vis[x] = 1
    for v in e[x]:
        if vis[x] == 0: dfs(v, dep + 1)
    if dep > ans:
        ans = dep
        poi = x
        
def solve():
    n = int(input())
    a, b = map(int, input().split())
    for i in range(0, n-1):
        a, b = map(int, input().split())
        e[a].append(b)
        e[b].append(a)
    dfs(1, 1)
    vis.clear()
    dfs(poi, 1)
    print(ans - 1)

def main():
    solve()
    
if __name__ == "__main__":
    main()


    