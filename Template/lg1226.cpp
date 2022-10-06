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
int Mod;
int qpow(int a,int b){
    int ret=1;
    while(b){
        if(b&1)ret=1ll*ret*a%Mod;
        a=1ll*a*a%Mod;b>>=1;
    }
    return ret;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    int a,b;
    a=gi(),b=gi(),Mod=gi();
    printf("%d^%d mod %d=%d\n",a,b,Mod,qpow(a,b));
    return 0;
}