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


const int maxn=26;

struct node{
    node *fail;
    node *nxt[maxn];
    int cnt;
    node(){
        cnt=0;
        fail=null;
        for(int i=0;i<maxn;++i)
            nxt[i]=null;
    }
}*q[500001];

char s[1000001];
int head,tail;

void ins(node *root){
    node *p=root;
    int i=0,index;
    while(s[i]){
        index=s[i++]-'a';
        if(p->nxt[index]==null)
            p->nxt[index]=new node();
        p=p->nxt[index];
    }
    p->cnt++;
    return;
}

void build(node *root){
    root->fail=null;
    q[head++]=root;
    while(head!=tail){
        node *temp=q[tail++];
        node *p=null;
        for(int i=0;i<maxn;++i){
            if(temp->nxt[i]!=null){
                if(temp==root) temp->nxt[i]->fail=root;
                else{
                    p=temp->fail;
                    while(p!=null){
                        if(p->nxt[i]!=null){
                            temp->nxt[i]->fail=p->nxt[i];
                            break;
                        }
                        p=p->fail;
                    }
                    if(p==null) temp->nxt[i]->fail=root;
                }
                q[head++]=temp->nxt[i];
            }
        }
    }
    return;
}

int query(node *root){
    int i=0,cnt=0,index;
    node *p=root;
    while(s[i]){
        index=s[i++]-'a';
        while(p->nxt[index]==null&&p!=root) p=p->fail;
        p=p->nxt[index];
        p=(p==null)?root:p;
        node *temp=p;
        while(temp!=root&&temp->cnt!=-1){
            cnt+=temp->cnt;
            temp->cnt=-1;
            temp=temp->fail;
        }
    }
    return cnt;
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
