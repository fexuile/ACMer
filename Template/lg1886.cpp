#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#define re register
#define ll long long
using namespace std;
typedef pair<int,int> pii;
inline int gi(){
    int f=1,sum=0;char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}
    return sum*f;
}
const int N=1000010;
int n,k,a[N],q[N];
void work(){
    
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    n=gi();k=gi();
    for(int i=1;i<=n;i++)a[i]=gi();
    work();
    for(int i=1;i<=n;i++)a[i]=-a[i];
    work();
    return 0;
}