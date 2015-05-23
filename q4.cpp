#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REV(i,a,b) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back
#define oo 1e9
#define eps 1e-9
#define PI 3.14159265358979323846264338327950
#define MAX 5000009
#define sz(v) (int)v.size()
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define show(x) cerr<<#x<<" = "<<x<<endl;
#define mem(s,v) memset(s,v,sizeof(s))
#define ppc(x) __builtin_popcount((x))
#define iter(it,s) for (__typeof(s.begin()) it = s.begin(); it != s.end(); it++)

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int si;
int np[MAX], primes[MAX];

void sieve() {
	memset(np, 0, sizeof np);
	np[1] = 1;
	int i = 2;
	si = 0;
	while (i < MAX) {
		if (!np[i]) {
			primes[si++] = i;
			for (ll j = i * (ll) i; j < MAX; j += i)
				np[j] = 1;
		}
		i++;
	}


}

int memo[5000001];
int cntPrimeFactors(int x) {
	int r = 0;
	int i = 0;
	while (x > 1 && i < si) {
		while (x % primes[i] == 0)
			x /= primes[i], r++;
		i++;
		if (!np[x]) {
			r++;
			break;
		}
	}
	return r;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
	//	freopen("o.txt", "wt", stdout);
#endif
	int t , a, i , b;
	scanf("%d" , &t);
	sieve();
	memo[1] = 0;
	FOR(i , 2 , 5000001)
		memo[i] = cntPrimeFactors(i) + memo[i - 1];

		
	while (t--) {
		scanf("%d%d" , &a , &b);
		printf("%d\n" , memo[a] - memo[b]);
	}
	return 0;
}