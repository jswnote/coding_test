#단지 번호
from collections import deque
import sys

# def bfs(graph, x, y, visited, N):
#     if x < 0 or x >= N or y < 0 or y >= N:
#         return 0
#     visited[x][y] = True
#     count = 1
    
#     dx = [-1, 1, 0, 0]
#     dy = [0, 0, -1, 1]
    
#     queue = deque([(x,y)])
    
#     while queue:
#         cx, cy = queue.popleft()
        
#         for i in range(4):
#             nx, ny = cx + dx[i], cy + dy[i]
#             if 0 <= nx < N and 0 <= ny < N:
#                 if graph[nx][ny] == 1 and not visited[nx][ny]:
#                     queue.append((nx, ny))
#                     visited[nx][ny] = True
#                     count += 1
    
#     return count


# N = int(input())
# graph = [list(map(int,sys.stdin.readline().strip())) for _ in range(N)]
# visited = [[False] * N for _ in range(N)]
# part_count = []

# for i in range(N):
#     for j in range(N):
#         if graph[i][j] == 1 and not visited[i][j]:
#             part_count.append(bfs(graph, i, j, visited, N))

# part_count.sort()
# print(len(part_count))
# for c in part_count:
#     print(c)
    
sys.setrecursionlimit(10**6) #재귀 깊이 제한

def dfs(graph, x, y, visited, N):
    if x < 0 or x >= N or y < 0 or y >= N:
        return 0
    visited[x][y] = True
    count = 1
    
    dx = [-1,1,0,0]
    dy = [0,0,-1,1]
    
    for i in range(4):
        nx, ny = x+dx[i], y+dy[i]
        if 0 <= nx < N and 0 <= ny < N:
            if graph[nx][ny] == 1 and not visited[nx][ny]:
                count += dfs(graph, nx, ny, visited, N)
    
    return count

N = int(input())
graph = [list(map(int,sys.stdin.readline().strip())) for _ in range(N)]
visited = [[False] * N for _ in range(N)]
part_count = []

for i in range(N):
    for j in range(N):
        if graph[i][j] == 1 and not visited[i][j]:
            part_count.append(dfs(graph, i, j, visited, N))

part_count.sort()
print(len(part_count))
for c in part_count:
    print(c)
