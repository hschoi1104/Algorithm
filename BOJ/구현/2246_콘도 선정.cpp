#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
vector<pair<int, int>>dist;
vector<pair<int, int>>cost;
int main() {
	int n, a, b, ans = 0;
	bool flag = false;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		dist.push_back({ a,b });
		cost.push_back({ b,a });
	}
	sort(dist.begin(), dist.end());
	sort(cost.begin(), cost.end());
	//�Ÿ�-���ں�
	//���纸�� �ܵ� ��ġ
	for (int i = 0; i < dist.size(); i++) {
		flag = true;
		//�ڽ� �տ��ִ� �ܵ���
		for (int j = 0; j < i && dist[i].first != dist[j].first; j++) {
			if (dist[j].second <= dist[i].second) flag = false;
		}
		//���ں�-�Ÿ�
		if (flag == true) {
			flag = false;
			for (int j = 0; j < n; j++) {
				if (cost[j].first == dist[i].second && cost[j].second == dist[i].first) break;
				if (cost[j].second <= dist[i].first) flag = true;
			}
			if (flag == false) ans += 1;
		}
	}
	printf("%d", ans);
	return 0;
}