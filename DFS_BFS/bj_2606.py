#바이러스
#그래프 만드는 문법 중요

import sys

def dfs(graph, visited, v):
    visited[v] = True
    
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, visited, i)    

N = int(sys.stdin.readline())
M = int(sys.stdin.readline())
graph = [[] for _ in range(N+1)]
visited = [False] * (N+1)

for _ in range(M):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(len(graph)):
    graph[i].sort()

dfs(graph, visited, 1)

print(sum(visited) - 1)
