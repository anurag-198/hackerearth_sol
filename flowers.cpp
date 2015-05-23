#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int n, k,z, i, pr[100], tm[100];
	cin >> n >> k;
	priority_queue <ll> pq;

	memset(tm, 0, sizeof(tm));

	for (i = 0; i < n; i++) {
		cin >> pr[i];
		pq.push(pr[i]);
	}

	ll price = 0;

	i = 0;
	while (!pq.empty()) {
		i = i % k;
		tm[i]++;
		z = pq.top();
		pq.pop();
		price += tm[i] * z;
	//	cout << z << " " << tm[i] << endl;
		 
		i++;
	}

	cout << price << endl;
	return 0;
}