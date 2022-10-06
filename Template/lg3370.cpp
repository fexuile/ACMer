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
const int N=100010,base=19260817;
#define ull unsigned long long
ull key[N];
char s[N];
int n;
ull getHash(){
    int len=strlen(s+1);ull ret=0;
    for(int i=1;i<=len;i++)
        ret=ret*base+s[i];
    return ret;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    n=gi();
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        key[i]=getHash();
    }
    sort(key+1,key+n+1);n=unique(key+1,key+n+1)-key-1;
    printf("%d\n",n);
    return 0;
}
#undef ull