#include <bits/stdc++.h>

using namespace std;
//int k[100001][200001];

int knapsack (int W, int wt[], int n) {
	int i, w;

	int k[2002];
		
	sort(wt,wt + n - 1);
	//cout << "hello \n";
	memset (k, 0, sizeof(k));
	
	for (w = 1; w <= W; w++) {
		for (i = 0; i < n; i++) {
			 if (wt[i] > w)
			 		continue;
//			 	cout << wt[i] << "---------         "<< w - wt[i] << endl;
//			 cout << w - wt[i] << " "<<endl;
			 k[w] = max(k[w], wt[i] + k[w - wt[i]]);
			// cout << k[w] <<" ";
			 	
		}
	}

	cout << k[W];
	
	cout << endl;
}

int main() {
	int n, tc,k,i;
	scanf("%d", &tc);
	
	while (tc--) {
		scanf ("%d%d", &n, &k);
		int wt[n];
	
		for (i = 0; i < n; i++) {
			scanf ("%d", &wt[i]);
		}

		knapsack(k,wt,n);
	}
	
	return 0;
}
