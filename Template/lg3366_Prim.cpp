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
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
inline int gi(){
    int f=1,sum=0;char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}
    return sum*f;
}
const int N=5010,M=200010;
struct node{
    int to,nxt,w;
}e[M<<1];
int front[N],cnt,vis[N],n,m;
priority_queue<pii,vector<pii>,greater<pii> >q;
void Add(int u,int v,int w){e[++cnt]=(node){v,front[u],w};front[u]=cnt;}
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    n=gi();m=gi();
    memset(front,-1,sizeof(front));
    for(int i=1;i<=m;i++){
        int u=gi(),v=gi(),w=gi();
        Add(u,v,w);Add(v,u,w);
    }
    int ans=0,s=0;q.push(mp(0,1));
    while(!q.empty()){
        int u=q.top().second,val=q.top().first;
        q.pop();
        if(vis[u])continue;vis[u]=1;ans+=val;s++;
        for(int i=front[u];~i;i=e[i].nxt){
            int v=e[i].to;
            if(!vis[v])q.push(mp(e[i].w,v));
        }
    }
    if(s==n)printf("%d\n",ans);
    else puts("orz");
    return 0;
}