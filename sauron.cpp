#include <bits/stdc++.h>
#include <math.h>
#define ll long long
using namespace std;
#define mod 1000000007

void mul(ll a[2][2], ll b[2][2])
{
    ll c[2][2];
    int i;
    int j;
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            c[i][j] = 0;
        }
    }
    int k;
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            for(k = 0; k < 2; k++) {
                c[i][j] = ((c[i][j]%mod) + (((a[i][k] % mod)* (b[k][j]%mod)) % mod))%mod;
            }
        }
    }
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            a[i][j] = c[i][j];
        }
    }
}  
void mat_mul(ll mat[2][2], ll n)
{
    if(n == 0 || n == 1) {
        return;
    }
    mat_mul(mat,n/2);
    ll m[2][2] = {{3,-1},{1,0}};
    mul(mat,mat);
    if(n % 2 != 0) {
        mul(mat,m);
    }
}

ll fibo(ll a, ll b, ll n)
{
    ll mat[2][2] = {{3,-1},{1,0}};
    mat_mul(mat,n);
    int i;
    int j;
   
   
    return ((3 * mat[0][0] % mod)+  (mat[0][1] % mod))  % mod;
   
}
       
int main()
{
   std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    int k;
   
   
    for(k  = 1; k <= t; k++) {
       
        int i;
       
        ll a,b,c,n,m;
	cin >> n;
//        cin >> a >> b >> n >> m ;
//        cout << "Case " << k << ": ";
        if(n == 1) {
            cout <<"1" << endl;
            continue;
        }
	if (n == 2) {
		cout <<"3" << endl;
		continue;
	}

        ll ans1 = fibo(1,3,n - 2);
       	if (ans1 < 0) {
		ans1 = ans1 + mod;
	}
        cout << ans1 << endl;
    }
   
	return 0;
}
