from heapq import heappop, heappush
import math

class Dijkstra:
    def __init__(self, n):
        self.G = [[] for i in range(n + 1)]
        self.d = [math.inf] * (n + 1)
        self.vis = [0] * (n + 1)
        
    def add(self, u, v, w):
        self.G[u].append((v, w))
    
    def dijkstra(self, s):
        self.d[s] = 0
        q = [(0, s)]

        while q:
            _, u = heappop(q)

            if self.vis[u]: continue
            self.vis[u] = 1

            for v, w in self.G[u]:
                if self.d[v] > self.d[u] + w:
                    self.d[v] = self.d[u] + w
                    heappush(q, (self.d[v], v))

def main():
    n, m, s = map(int, input().split())
    dij = Dijkstra(n)
    
    for i in range(m):
        u, v, w = map(int, input().split())
        dij.add(u, v, w)
        
    dij.dijkstra(s)

    for i in range(1, n + 1):
        print(dij.d[i], end = ' ')
    

main()




    
    
