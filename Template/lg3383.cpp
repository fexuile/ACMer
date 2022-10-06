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
bool is_prime[100000010];
int s,prime[N],n,q;
void init(int MX){
    is_prime[1]=1;
    for(int i=2;i<=MX;i++){
        if(!is_prime[i])prime[++s]=i;
        for(int j=1;j<=s&&i*prime[j]<=MX;j++){
            is_prime[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    n=gi();q=gi();init(n);
    while(q--)printf("%d\n",prime[gi()]);
    return 0;
}