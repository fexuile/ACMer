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
bool check(int x){
    if(x%4==0&&x%100!=0)return true;
    return x%400==0;
}
int month[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    int n=gi(),m=gi(),s=0;
    for(int i=1900;i<n;i++)s+=365+check(i);
    for(int i=1;i<m;i++)s+=month[check(n)][i];
    s%=7;s++;puts(" Sun Mon Tue Wed Thu Fri Sat");
    if(s!=7)for(int i=1;i<=s;i++)printf("    ");
    for(int i=1;i<=month[check(n)][m];i++){
        printf("%4.d",i);if(s==6)puts("");
        s=s%7+1;
    }
    return 0;
}