#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n,k,w, ans;

	cin >> k >> n >> w;

	ans = ((((w) * (w + 1)) / 2 ) * k ) - n;
	if (ans <= 0)
		cout << "0\n";
	else
		cout << ans << endl;
	 return 0;
}