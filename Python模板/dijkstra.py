import heapq

class Edge:
    def __init__(self, v, w):
        self.v = v  # 目标节点
        self.w = w  # 边权重

def dijkstra(n, G, s):
    INF = float('inf')
    d = [INF] * (n + 1)    # 存储到各节点的最短距离
    path = [0] * (n + 1)    # 存储前驱节点
    vis = [False] * (n + 1) # 标记是否已确定最短路径
    d[s] = 0
    heap = [] # 优先队列，存储(距离, 节点)元组
    heapq.heappush(heap, (0, s))
    while heap:
        u = heapq.heappop(heap)[1]
        # 如果当前距离大于已记录的距离，跳过
        if vis[u]: continue     
        vis[u] = True       
        for e in G[u]:
            v, w = e.v, e.w
            if d[v] > d[u] + w:
                d[v] = d[u] + w
                path[v] = u
                heapq.heappush(heap, (d[v], v))
    return d, path

def print_path(u, path):
    if u == 0:
        return
    print_path(path[u], path)
    print(u, end=' ' if path[u] != 0 else '\n')

def main():
    n, m, s = map(int, input().split())
    G = [[] for _ in range(n + 1)]
    for i in range(m):
        u, v, w = map(int, input().split())
        G[u].append(Edge(v, w))
    dijkstra(n, G, s)
    d, path = dijkstra(n, G, s)
    for i in range(1, n+1):
        print(d[i], end=' ')
        
if __name__ == "__main__":
    main()