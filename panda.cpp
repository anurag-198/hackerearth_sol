#include <bits/stdc++.h>
#define mod 1000003

using namespace std;

long long fac[1000005];

void calc() {
	int i;
	fac[0] = 1;
	for (i = 1; i <= 1000004; i++) {
		fac[i] = ((fac[i - 1] % mod) * (i % mod)) % mod;
		if (fac[i] < 0) {
			fac[i] += mod;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	long long tc, n, k;
	long long ans;
	cin >> tc;
	calc();
	
	while (tc--) {
		cin >> n >> k;
		if (n >= 1000003) {
			cout << "0\n";
			continue;
		}

		ans = ((fac[n] % mod)* (k % mod)) % mod;
		if (ans < 0) {
			ans += mod;
		}
		cout << ans << endl;
	}
}