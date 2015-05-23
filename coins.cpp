#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
map <int , long long> h;
long long f(int n)
{
if (n == 0) return 0;
long long r = h[n];
if (r == 0)
{
r = (n > f(n>>1)+f(n/3)+f(n>>2) )?n:f(n>>1)+f(n/3)+f(n>>2);
h[n] = r;
}
return r;
 
}
int main()
{
int i=0;
int n[10];
for(i=0;i<10;i++)
{
cin>>n[i];
}
for(i=0;i<10;i++)
{
 
cout<<f(n[i])<<endl;
 
}
return 0;
}
 
