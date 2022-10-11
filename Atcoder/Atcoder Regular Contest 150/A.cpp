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
const int N=300010;
char s[N];int n,k;
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    int T=gi();
    while(T--){
        n=gi();k=gi();scanf("%s",s+1);
        int last=0,first=0;
        for(int i=1;i<=n;i++)
            if(s[i]=='1')
                if(!last)last=first=i;
                else last=i;
        if(!last){
            int t=0,ans=0;
            for(int i=1;i<=n;i++)
                if(s[i]=='?')t++;
                else{if(t&&t>=k)ans+=t-k+1;t=0;}
            if(t>=k)ans+=t-k+1;
            if(ans==1)puts("Yes");else puts("No");
            continue;
        }
        int flag=1;
        for(int i=first;i<=last;i++)if(s[i]=='0'){flag=0;break;}
        if(!flag){puts("No");continue;}
        k-=last-first+1;
        if(k<0)puts("No");
        else if(!k)puts("Yes");
        else{
            int left=0,right=0;
            for(int i=first-1;i;i--)if(s[i]=='?')left++;else break;
            for(int i=last+1;i<=n;i++)if(s[i]=='?')right++;else break;
            if(left==0&&right>=k)puts("Yes");
            else if(right==0&&left>=k)puts("Yes");
            else if(left+right==k)puts("Yes");
            else puts("No");
        }
    }
    return 0;
}