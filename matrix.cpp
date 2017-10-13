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

const int mod=1000;
int n,m;

struct matrix{
    int mp[25][25];
    matrix operator * (matrix b){
        matrix ans;
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j){
                ans.mp[i][j]=0;
                for(int k=0;k<n;++k){
                    ans.mp[i][j]+=(mp[i][k]*b.mp[k][j])%mod;
                    ans.mp[i][j]%=mod;
                }
            }
        return ans;
    }
    void print(){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(j) printf(" ");
                printf("%d",mp[i][j]);
            }
            printf("\n");
        }
    }
    void init(){
        memset(mp,0,sizeof mp);
    }
};

matrix pow(matrix a,int t){
    matrix b;
    b.init();
    for(int i=0;i<n;++i)
        b.mp[i][i]=1;
    while(t){
        if(t&1) b=b*a;
        a=a*a;
        t>>=1;
    }
    return b;
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
