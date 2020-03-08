#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define vi vector <int>
#define vvi vector <vi>
#define pii pair<int,int>
#define fs first
#define sd second
using namespace std;
struct LIB {
	int cnt = 0, signup = 0, ship = 0, libNum = 0;
	int book[1000] = {};
	bool operator < (const LIB& tmp) const {
		return signup < tmp.signup;
	}
};
vector<LIB> libs;
vector<LIB> ans;
LIB lib[100005];
int B, L, D, visit[100005], arr[100005], Max, ansc;
int order[100005];

int main() {
	FIO;
	cin >> B >> L >> D;
	int score[100005];// 책 점수들
	for (int i = 1; i <= B; i++) cin >> score[i];

	int cntMax = 0, cntMin = INT_MAX, signupMAX = 0, signupMIN = INT_MAX, shipMAX = 0, shipMIN = INT_MAX;
	for (int i = 1; i <= L; i++) { //도서관
		cin >> lib[i].cnt >> lib[i].signup >> lib[i].ship;
		for (int j = 1; j <= lib[i].cnt; j++)
			cin >> lib[i].book[j];
		libs.push_back(LIB{ 0,lib[i].signup,lib[i].ship,i });
	}
	sort(libs.begin(), libs.end());
	int t = 0, idx = 0, signupProc = 0, bookCNT = 0;
	/*while (t < D) {*/
	while (bookCNT != B) {
		if (!signupProc) {
			//결과(책번호 저장)
			for (int i = 0; i < ans.size(); i++) {
				if (ans[i].cnt < lib[ans[i].libNum].cnt) {
					ans[i].book[ans[i].cnt] = lib[ans[i].libNum].book[ans[i].cnt + 1];
					ans[i].cnt++;
					bookCNT += 1;
				}
			}
			if (idx < libs.size()) {
				ans.push_back(libs[idx]);
				signupProc = libs[idx++].signup;
			}
		}
		else {
			//결과(책번호 저장, signup 1개 제외)
			for (int i = 0; i < ans.size() - 1; i++) {
				if (ans[i].cnt < lib[ans[i].libNum].cnt) {
					ans[i].book[ans[i].cnt] = lib[ans[i].libNum].book[ans[i].cnt + 1];
					ans[i].cnt++;
					bookCNT += 1;
				}
			}
		}
		if (signupProc > 0) signupProc--;
		t++;
	}
	int ansScore = 0;
	cout << ans.size() << "\n";
	for (auto it : ans) {
		cout << it.libNum << " " << it.cnt << "\n";
		for (int j = 0; j < it.cnt; j++) {
			cout << it.book[j] << " ";
			ansScore += score[it.book[j] + 1];
		}
		cout << "\n";
	}
	return 0;
}