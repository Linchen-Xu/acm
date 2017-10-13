#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <list>
#include <set>
#include <map>
#define null NULL

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll c[1005];
struct node{
    int x,y;
}e[1000005];

bool cmp(node a,node b){
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}

void add(int i,int v){
    while(i<=m){
        c[i]+=(ll)v;
        i+=i&-i;
    }
    return;
}

ll sum(int i){
    ll ans=0;
    while(i>0){
        ans+=c[i];
        i&=i-1;
    }
    return ans;
}


int main(){
    #ifndef ONLINE_JUDGE
    //freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif // ONLINE_JUDGE




    #ifndef ONLINE_JUDGE
    //fclose(stdin);
    fclose(stdout);
    //system("D:\\input.txt");
    system("D:\\output.txt");
    #endif // ONLINE_JUDGE
    return 0;
}
