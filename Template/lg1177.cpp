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
const int N=100010;
int n,a[N],b[N];
void merge(int l,int r){
    int mid=(l+r)>>1;if(l==r)return;
    merge(l,mid);merge(mid+1,r);
    int i=l,j=mid+1,k=0;
    for(;i<=mid || j<=r;)
        if((i<=mid&&a[i]<a[j])||j>r)b[++k]=a[i++];
        else b[++k]=a[j++];
    for(int i=1;i<=r-l+1;i++)a[i+l-1]=b[i];
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    n=gi();for(int i=1;i<=n;i++)a[i]=gi();
    merge(1,n);
    for(int i=1;i<=n;i++)printf("%d%c",a[i],i==n?'\n':' ');
    return 0;
}