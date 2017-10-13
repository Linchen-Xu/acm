#define maxm 2005
#define type int
#define maxn 25
#define INF 1e9

//s源点t汇点N总点数
int s, t;
struct node {
    int u, v, next;
    type cap, flow, cost;
}edge[maxm];
int head[maxn], cnt;
int pre[maxn];
type dis[maxn];
bool vis[maxn];
int N;

void init () {
    memset (head, -1, sizeof head);
    cnt = 0;
}

void add_edge (int u, int v, type cap, type cost) {
    edge[cnt].u = u, edge[cnt].v = v, edge[cnt].cap = cap, edge[cnt].flow = 0;
    edge[cnt].cost = cost, edge[cnt].next = head[u], head[u] = cnt++;
    edge[cnt].u = v, edge[cnt].v = u, edge[cnt].cap = 0, edge[cnt].flow = 0;
    edge[cnt].cost = -cost, edge[cnt].next = head[v], head[v] = cnt++;
}

bool spfa (int s, int t) {
    queue <int> q;
    for (int i = 0; i < N; i++) {
        dis[i] = INF;
        vis[i] = 0;
        pre[i] = -1;
    }
    dis[s] = 0;
    vis[s] = 1;
    q.push (s);
    while (!q.empty ()) {
        int u = q.front (); q.pop ();
        vis[u] = 0;
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].v;
            if (edge[i].cap > edge[i].flow && dis[v] > dis[u]+edge[i].cost) {
                dis[v] = dis[u]+edge[i].cost;
                pre[v] = i;
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push (v);
                }
            }
        }
    }
    if (pre[t] == -1)
        return 0;
    else
        return 1;
}

int MCMF (int s, int t, type &cost) {
    type flow = 0;
    cost = 0;
    while (spfa (s, t)) {
        type Min = INF;
        for (int i = pre[t]; i != -1; i = pre[edge[i^1].v]) {
            if (Min > edge[i].cap-edge[i].flow) {
                Min = edge[i].cap-edge[i].flow;
            }
        }
        for (int i = pre[t]; i != -1; i = pre[edge[i^1].v]) {
            edge[i].flow += Min;
            edge[i^1].flow -= Min;
            cost += edge[i].cost*Min;
        }
        flow += Min;
    }
    return flow;
}
 

