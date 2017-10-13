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

const int maxn=1e6+5;
int par[maxn],ran[maxn];

void init(){
    for(int i=0;i<maxn;++i)
        par[i]=ran[i]=0;
    return;
}

int fnd(int x){
    if(par[x]==x) return x;
    else return par[x]=fnd(par[x]);
}

void unite(int x,int y){
    x=fnd(x),y=fnd(y);
    if(x==y) return x;
    if(ran[x]<ran[y]) par[x]=y;
    else{
        par[y]=x;
        if(ran[x]==ran[y])
            ++ran[x];
    }
}

bool same(int x,int y){
    return fnd(x)==fnd(y);
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
