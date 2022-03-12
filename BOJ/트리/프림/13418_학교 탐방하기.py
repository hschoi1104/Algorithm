#!/usr/bin/env python

import sys
import heapq

input = sys.stdin.readline

def solution(flag):
    visited = [False] * (n+2)
    heap = [[0,0]]
    ans = 0
    cnt = 0
    while cnt<n+1:
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

n, m = map(int, input().split())
edge = [[] for _ in range(n + 2)]

for _ in range(m+1):
    a,b,c = map(int, input().split())
    edge[a].append([c^1, b])
    edge[b].append([c^1, a])

# print(solution(1))
print(solution(-1)**2 - solution(1)**2)
