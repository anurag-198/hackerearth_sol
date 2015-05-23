#include <bits/stdc++.h>

using namespace std;

int main() {
	long long tc, i, n;
	cin >> tc;
	while (tc--) {
			cin >> n;
			long long a[n];

			for (i = 0; i < n; i++) {
					cin >> a[i]; 
			}

			long long pro = 0, max = INT_MIN;

			for (i = n - 1; i >= 0; i--) {
				if (max < a[i]) {
					max = a[i];
				}
				pro += (max - a[i]); 
			}

			cout << pro << endl;

	}

	return 0;
}