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

const int maxn=1e6+5,maxm=1e4+5;

int t,n,m,a[maxn],b[maxm],nxt[maxm];

void getnxt(){
    nxt[0]=-1;
    int k=-1,j=0;
    while(j<m-1){
        if(k==-1||b[j]==b[k]){
            ++j;
            ++k;
            if(b[j]!=b[k]) nxt[j]=k;
            else nxt[j]=nxt[k];
        }else k=nxt[k];
    }
    return;
}

int kmp(){
    int i=0,j=0;
    while(i<n&&j<m){
        if(j==-1||a[i]==b[j]){
            ++i;
            ++j;
        }else j=nxt[j];
    }
    if(j==m) return i-m+1;
    else return -1;
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
