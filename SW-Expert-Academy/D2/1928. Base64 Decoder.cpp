#include <stdio.h>
int ascii[150];
void init() {
	for (int i = 0; i < 26; i++) ascii[i + 'A'] = i;
	for (int i = 0; i < 26; i++) ascii[i + 'a'] = i + 26;
	for (int i = 0; i < 11; i++) ascii[i + '0'] = i + 52;
	ascii['+'] = 62;
	ascii['/'] = 63;
}
int main() {
	init();
	int t; scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		char encode[100001];
		char decode[100001];
		scanf("%s", &encode);

		int bits, p1 = 0, p2 = 0;
		while (encode[p1]) {
			bits = ascii[encode[p1++]] << 18;
			bits += ascii[encode[p1++]] << 12;
			bits += ascii[encode[p1++]] << 6;
			bits += ascii[encode[p1++]];
			decode[p2++] = bits >> 16;
			decode[p2++] = bits >> 8 ;
			decode[p2++] = bits;
		}
		decode[p2] = 0;
		printf("#%d %s\n", tt, decode);
	}
	return 0;
}