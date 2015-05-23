#include <bits/stdc++.h>

using namespace std;

int main() {
	vector <int> a, b;

	int n, k1, k2, no, i,j, flag;

	cin >> n;

	cin >> k1;

	int ev1[k1];


	for (i = 0; i < k1; i++) {
		cin >> no;
		ev1[i] = no;
		a.push_back(no);
	}

	cin >> k2;

	int ev2[k2];

	for (i = 0; i < k2; i++) {
		cin >> no;
		ev2[i] = no;
		b.push_back(no);
	}

	int val, val1, sum1, sum2, count = 0;
	while (!a.empty() && !b.empty()) {
		count++;
		sum1 = 0; sum2 = 0;
		if (a.front() > b.front()) {
			val = b[0];
			val1 = a[0];

			b.erase(b.begin());
			a.erase(a.begin());
			a.push_back(val);
			a.push_back(val1);
		}
		else {
			val = a[0];
			val1 = b[0];
			a.erase(a.begin());
			b.erase(b.begin());
			b.push_back(val);
			b.push_back(val1);

		}

	//	cout << a.size() <<" " << b.size() <<"\n";

		/*if (a.size() == k1 && b.size() == k2) {
	
			for (i = 0; i < k1; i++) {
				if (a[i] != ev1[i]) {
					break;
				}
			}

			for (j = 0; j < k2; j++) {
				if (b[j] != ev2[j]) {
					break;
				}
			}

			if ((i == k1) && (j == k2)) {
				cout << "-1\n";
				return 0; 
			}
		} */

		if (count > 500000) {
			cout << "-1\n";
				return 0; 
		}
	
	}



		if (a.empty()) {
			cout << count <<" " << "2\n";
		}
		else {
			cout << count <<" " <<"1\n";
		}


return 0;
}