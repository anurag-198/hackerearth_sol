#include<bits/stdc++.h>
using namespace std;
int main(){
    std::ios::sync_with_stdio(false);
    int n,x0,y0;

    cin>>n>>x0>>y0;

    int j;
    int x1[n],y1[n];

    double a1[n];
    for(j  = 0; j < n; j++){
	        cin>>x1[j]>>y1[j];
   	     a1[j] =(double)(y1[j] - y0)/(double)(x1[j] - x0);

    	   	 if(x1[j] == x0){
        	    if(a1[j] < 0){
       	        	 a1[j] = (-1) * a1[j];
            		}
        	}
    }

    sort(a1,a1+n);
    int ans = 1;

    for(j = 0; j < n; j++){
        if(j != n-1){
            if(a1[j] != a1[j + 1]){
                ans++;
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}
