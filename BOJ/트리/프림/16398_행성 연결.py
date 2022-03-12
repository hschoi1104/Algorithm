import sys
import heapq

input = sys.stdin.readline

def solution(s):
    visited = [False] * (n+1)
    heap = [[0,0]]
    ans = 0
    cnt = 0
    while cnt < n:
        c, v = heapq.heappop(heap)
        if visited[v]:
            continue
        visited[v] = True
        ans += c
        cnt += 1
        for k, w in edge[v]:
            heapq.heappush(heap, [k, w])
    return ans

n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]
edge = [[] for _ in range(n + 1)]

for a in range(n):
    for b in range(n):
        if a != b:
            edge[a].append([graph[a][b],b])

print(solution(0))
