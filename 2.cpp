#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, i, min, lasy, sum1, sum, ans;
	cin >> n;

	int a[n];
	sum1 = 0;

	for (i = 0; i < n; i++) {
		cin >> a[i];
		sum1 += a[i];
		
	}

	sort(a, a+n);

	min = a[0];
	
	lasy = min + n - 1;

	

	sum = ((min + lasy) * n) / 2;
	
	

	ans = sum - sum1;

	cout << ans << endl;
	return 0;
}