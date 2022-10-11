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
#define int ll
using namespace std;
typedef pair<int,int> pii;
inline int gi(){
    int f=1,sum=0;char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}
    return sum*f;
}
int get(int A,int B,int k){
    if(k*A>=B)return k*A-B;
    return (ll)ceil(B*1./k)*(k+1)-A-B;
}
signed main(){
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    int T=gi();
    while(T--){
        int A=gi(),B=gi();
        if(B<=A)printf("%lld\n",A-B);
        else if(B%A==0)puts("0");
        else {
            int k=B/A,ans=B-A;
            for(int i=max(1ll,k-2000000);i<=k+2000000;i++){
                ans=min(ans,get(A,B,i));
                if(i*A>=B)break;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}