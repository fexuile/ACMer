#include<bits/stdc++.h>
using namespace std;
#define double long double
int main(){
    int n,k;scanf("%d%d",&n,&k);
    if(k==1)return printf("%.10Lf\n",((double)n*(n+1))/2),0;
    double ans=0,s=-1,base=1;
    for(int i=1;i<=n&&(ans-s)>1e-15;i++){
        s=ans;
        if(i%2==0)base=base*1.*k;
        ans+=(double)(n-i+1)*1./base;
    }
    printf("%.10Lf\n",ans);
    return 0;
}