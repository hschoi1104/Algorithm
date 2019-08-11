#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;
//방정보
typedef struct node {
	ll t;//회복 or 전투
	ll a;//공격증가 or 적 공격력
	ll h;//체력증가 or 적 체력
};
vector<node>v;

int main() {
	ll n, atk, x, y, z, ans = 0;
	scanf("%lld %lld", &n, &atk);
	for (ll i = 0; i < n; i++) {
		scanf("%lld %lld %lld", &x, &y, &z);
		node temp = { x,y,z };
		v.push_back(temp);
	}
	ll l = 0, r = 1e18;
	while (l + 1 < r) {
		ll mid = (l + r) / 2, hp = mid, natk = atk, myremainhp = 0;
		bool flag = false;
		for (int i = 0; i < v.size(); i++) {
			node R = v[i];
			//전투
			if (R.t == 1) {
				ll myatkcnt = R.h / natk;
				if (R.h % natk != 0) myatkcnt += 1;
				myremainhp = hp - R.a * (myatkcnt - 1);
				if (myremainhp <= 0) break;
				else hp = myremainhp;
			}
			//회복
			else {
				hp = (R.h + hp > mid) ? mid : R.h + hp;
				natk += R.a;
			}
			if (i == v.size() - 1) flag = true;
		}
		if (flag == true) r = mid;
		else l = mid;
	}
	printf("%lld", r);
	return 0;
}