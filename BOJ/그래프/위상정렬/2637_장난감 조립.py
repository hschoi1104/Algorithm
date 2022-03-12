import sys
import collections

input = sys.stdin.readline


def solution(cur, point):
    ans[cur] += point

    if indegree[cur] != 0:
        return

    for node in graph[cur]:
        nxt = node[0]
        cost = node[1]

        indegree[nxt] -= 1

        solution(nxt, ans[cur] * cost)


n = int(input().rstrip())
m = int(input().rstrip())

indegree = [0 for _ in range(n + 1)]
outdegree = [0 for _ in range(n + 1)]
ans = [0 for _ in range(n + 1)]
graph = collections.defaultdict(list)

for _ in range(m):
    a, b, c = map(int, input().split())
    indegree[b] += 1
    outdegree[a] += 1
    graph[a].append((b, c))

solution(n, 1)

for i in range(1,n+1):
    if outdegree[i] == 0:
        print(i,ans[i])
