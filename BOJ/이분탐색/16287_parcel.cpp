#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int arr[5001];
vector < pair<int, pair<int, int>>> V1; // weight,parcel1,parcel2
vector <int> V2; // for binarysearch, only V1.weight

int main() {
	int W, N;
	scanf("%d %d", &W, &N);
	//input parcels
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	//make vector1&2
	int index = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			V1.push_back({ arr[i] + arr[j],{ i,j } });
		}
	}
	//for binarysearch
	sort(V1.begin(), V1.end());
	for (int i = 0; i < V1.size(); i++) {
		V2.push_back(V1[i].first);
	}

	for (auto it = V1.begin(); it != V1.end(); it++) {
		if (it->first >= W) break;
		auto pos = lower_bound(V2.begin(), V2.end(), W - it->first);
		while (V1[pos - V2.begin()].first == W - it->first && pos != V2.end()) {
			if (it->second.first != V1[pos - V2.begin()].second.first && it->second.first != V1[pos - V2.begin()].second.second && it->second.second != V1[pos - V2.begin()].second.second && it->second.second != V1[pos - V2.begin()].second.first) {
				printf("YES\n");
				return 0;
			}
			pos++;
		}
	}

	printf("NO\n");
	return 0;
}