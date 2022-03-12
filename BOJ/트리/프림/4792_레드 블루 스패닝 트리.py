import sys
import heapq

input = sys.stdin.readline

def solution(flag, edge):
    visited = [False] * (n+2)
    heap = [[0,1]]
    ans = 0
    cnt = 0
    while cnt<n:
        c, v = heapq.heappop(heap)
        if visited[v]:
            continue
        visited[v] = True
        ans += c
        cnt += 1
        for k, w in edge[v]:
            if visited[w] == False:
                heapq.heappush(heap, [k*flag, w])
    return ans


# 파란간선 최대 = B cost = 0 R cost = 1
# 파란간선 최소 = B cost = 1 R cost = 0

while True:
    n, m, k = map(int, input().split())
    if n == 0:
        break
    min_edge = [[] for _ in range(n + 2)]
    max_edge = [[] for _ in range(n + 2)]
    for _ in range(m):
        c, f, t = input().split()
        f, t = int(f), int(t)
        if c == 'B':
            max_edge[f].append([1,t])
            max_edge[t].append([1,f])
        else:
            max_edge[f].append([0,t])
            max_edge[t].append([0,f])
    if k<= -solution(-1, max_edge) and solution(1, max_edge) <= k:
        sys.stdout.write("1\n")
    else:
        sys.stdout.write("0\n")

#!/usr/bin/env python

