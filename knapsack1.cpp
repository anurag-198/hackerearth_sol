#include<iostream>
using namespace std;
int a[2000] = {0};
int func(int i,int k,int n){
    if(k == 0){
        return 0;
    }
    else if(k < 0){
        return k+a[i];
    }
    else{
        if( i >= n){
            return k;
        }
        return min(func(i,k-a[i],n),func(i+1,k,n));
    }
}

int dp[2002];
int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n,k;
        cin>>n>>k;
        int i;
        for(i = 0; i < n; i++){
            cin>>a[i];
        }
        int ans = func(0,k,n);
        cout<<k - ans<<"\n";
    }
    return 0;
}