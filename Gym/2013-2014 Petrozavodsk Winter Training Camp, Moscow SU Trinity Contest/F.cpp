#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
const int N=2010;
int a[N],s[N],n;
ll f[N][N],ans;
struct node{
    int x,y,i;
    bool operator<(const node &b)const{return x<b.x||(x==b.x&&y<b.y);}
    node operator-(const node &b)const{return (node){x-b.x,y-b.y};}
}p[N];
ll cross(node a,node b){return a.x*b.y-a.y*b.x;}
int sta[N],top;
void build(int m){
    //if (m == 5)
    //    puts("cam");
    top=0;
    for(int i=1;i<m;i++)p[i].x=s[i-1],p[i].y=f[m-1][i],p[i].i=i;
    sort(p+1,p+m);
    sta[++top]=1;
    for(int i=2;i<m;i++){
        while(top>1&&cross(p[sta[top]]-p[sta[top-1]],p[i]-p[sta[top-1]])>=0)top--;
        sta[++top]=i;
    }
    p[0]=(node){p[1].x-1,-2000000,0};p[sta[top]+1]=(node){p[sta[top]].x+1,-2000000,0};
}
double get(node a,node b){return (double)(a.y-b.y)*1./(a.x-b.x);}
int check(int k){
    int l=1,r=top,res=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(get(p[sta[mid]],p[sta[mid-1]])<(double)k)r=mid-1;
        else l=mid+1,res=mid;
    }
    return res;
}
const ll Inf=1e18+10;
signed main(){
    //freopen("a.in","r",stdin);
    //freopen("f.out", "w", stdout);
    scanf("%lld",&n);for(int i=1;i<=n;i++)scanf("%lld",&a[i]),s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=-Inf;
    for(int i=1;i<=n;i++)f[1][i]=0;
    for(int j=1;j<=n;j++){
        build(j);
        for(int i=j;i<=n;i++){
            int k=p[sta[check(s[i]-s[j-1])]].i;
            if(k)f[i][j]=1ll*s[i]*s[j-1]-1ll*s[j-1]*s[j-1]+f[j-1][k]-1ll*(s[i]-s[j-1])*s[k-1];
            f[i][j]=max(f[i][j],1ll*s[i]*s[j-1]-1ll*s[j-1]*s[j-1]);
            //printf("%d %d :%d %d\n",i,j,k,f[i][j]);
            if(i==n)ans=max(ans,f[i][j]);
        }
    }
    //for (int i = 1; i <= n; ++i, puts(""))
    //   for (int j = 1; j <= i; ++j) printf("%d ", f[i][j]);
    printf("%lld\n",ans);
    return 0;
}