#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int cutVertexNum[1000002], cutEdgeNum[1000002], cutVertexCnt = 0, cutEdgeCnt = 0;
vector<vector<int>>g;
set<int>cutVertex;
set<pair<int, int>>cutEdge;
vector<pair<int, int>>edge;
int findCutVertex(int idx, bool root) {
	int low = cutVertexNum[idx] = ++cutVertexCnt, child = 0, c = 0, ret = cutVertexCnt;
	for (int i = 0; i < g[idx].size(); i++) {
		int next = g[idx][i];
		if (!cutVertexNum[next]) {
			low = findCutVertex(next, false);
			child++;
		}
		else {
			ret = min(ret, cutVertexNum[g[idx][i]]);
			continue;
		}
		if (!root && low >= cutVertexNum[idx])c = 1;

		ret = min(ret, low);
	}
	if (c || root && child > 1)  cutVertex.insert(idx);
	return ret;
}
int findCutEdge(int idx, int par) {
	int low = cutEdgeNum[idx] = ++cutEdgeCnt, child = 0, c = 0, ret = cutEdgeCnt;
	for (int i = 0; i < g[idx].size(); i++) {
		int next = g[idx][i];
		if (!cutEdgeNum[next]) {
			low = findCutEdge(next, idx);
			if (low > cutEdgeNum[idx]) {
				c = next;
				cutEdge.insert({ min(idx,next),max(idx,next) });
			}
			ret = min(ret, low);
		}
		else if (next != par) {
			ret = min(ret, cutEdgeNum[next]);
		}
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int v; cin >> v;
	g.resize(v + 1);
	for (int i = 0; i < v - 1; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b); g[b].push_back(a);
		edge.push_back({ min(a,b),max(a,b) });
	}
	for (int i = 1; i <= v; i++) {
		if (!cutEdgeNum[i]) findCutEdge(i, 0);
		if (!cutVertexNum[i]) findCutVertex(i, true);
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int a, b; cin >> a >> b;
		if (a == 1) {//k정점이 단절점인가?
			if (cutVertex.find(b) != cutVertex.end()) cout << "yes\n";
			else cout << "no\n";
		}
		else {
			if (cutEdge.find({ edge[b-1] }) != cutEdge.end()) cout << "yes\n";
			else cout << "no\n";
		}
	}
	return 0;
}