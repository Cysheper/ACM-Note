from heapq import heappush, heappop
import math

class Dijkstra:
    def __init__(self, n):
        self.G = [[] for _ in range(n + 1)]       # 邻接表存储图
        self.d = [math.inf] * (n + 1)             # 距离数组
        self.vis = [0] * (n + 1)                  # 访问标记
    
    def add(self, u, v, w):
        self.G[u].append((v, w))                  # 添加边
    
    def dijkstra(self, s):
        self.d[s] = 0
        q = [(0, s)]                              # (距离,节点)的优先队列
        
        while q:
            _, u = heappop(q)
            
            if self.vis[u]: continue
            self.vis[u] = 1
            
            for v, w in self.G[u]:
                if self.d[v] > self.d[u] + w:
                    self.d[v] = self.d[u] + w
                    heappush(q, (self.d[v], v))

def solve():
    n, m, s = map(int, input().split())
    dij = Dijkstra(n)
    
    for _ in range(m):
        u, v, w = map(int, input().split())
        dij.add(u, v, w)
    
    dij.dijkstra(s)
    
    print(' '.join(map(str, dij.d[1:n+1])))

if __name__ == "__main__":
    solve()


