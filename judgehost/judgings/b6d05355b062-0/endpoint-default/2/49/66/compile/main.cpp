#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<set>
#include<iostream>

using namespace std;

const int maxn=1001;

struct Edge
{
    int u,v;
};
stack<Edge> S;
vector<int> G[maxn],bcc[maxn];

int count_ap;
int ar[1001];
int bcc_cnt,t;
int depth[maxn],iscut[maxn],low[maxn];
int bccno[maxn];

void dfs(int u,int p)
{
    low[u]=depth[u]=++t;
    int child=0;
    bool ap = false;

    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(v==p) continue;
        Edge e = (Edge){u,v};
        if(!depth[v])
        {
            S.push(e);
            child++;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v] >= depth[u])
            {
                ap = true;
                //iscut[u]=true;
                bcc_cnt++;
                bcc[bcc_cnt].clear();
                while(true)
                {
                    Edge x=S.top(); S.pop();
                    if(bccno[x.u]!=bcc_cnt)
                    {
                        bcc[bcc_cnt].push_back(x.u);
                        bccno[x.u]=bcc_cnt;
                    }
                    if(bccno[x.v]!=bcc_cnt)
                    {
                        bcc[bcc_cnt].push_back(x.v);
                        bccno[x.v]=bcc_cnt;
                    }
                    if(x.u==u && x.v==v) break;
                }
            }
        }
        else if(depth[v]<depth[u])
        {
            S.push(e);
            low[u]=min(low[u],depth[v]);
        }
    }
    //if(p<0 && child==1) iscut[u]=0;
    if (((u == p)&&(child > 1))||((u!=p)&&(ap==true))){
    ar[u]=1;
    count_ap++;
  }
}

void find_bcc(int n)
{
    memset(depth,0,sizeof(depth));
    memset(iscut,0,sizeof(iscut));
    memset(bccno,0,sizeof(bccno));
    memset(ar,0,sizeof(ar));
    t = bcc_cnt = count_ap=0;
    for(int i=0;i<=n;i++)

        if(!depth[i])
            dfs(i,i);

}
int main()
{

    int n,m;
    while(cin >> n >> m)
    {
        for(int i=0;i<n;i++) G[i].clear();
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        find_bcc(n);
        int total=0;
        int iso_re=0;
        int t1=0;
        int t2=0;
        int tt=0;
        set<int> t3;

        for(int i=1;i<=n;i++){
        if(!G[i].size()) total++;}

        for(int i=1;i<=n;i++){
            for(int j=1;j<=G[i].size();j++){
                t1=G[i][0]; 
                t2=G[i][j];
                tt=G[i][G[i].size()];
            
                
                if (t1==t2&&t2==tt&&t2==i)
                {
                    t3.insert(i);
                }
                
            }
        }

        iso_re=t3.size();

        cout << total+bcc_cnt+iso_re << endl;



        set<int>::iterator it;
        for(it=t3.begin();it!=t3.end();it++){
            cout << *it << endl;
        }



        for(int i=1;i<=n;i++){
        if(!G[i].size()) cout <<i<<endl;
       }

    
        
        

        for(int i=1;i<=bcc_cnt;i++)
        {

            for(int j=0;j<bcc[i].size();j++)
            {
                printf("%d ",bcc[i][j]);
            }
            printf("\n");
        }




        cout << count_ap <<endl;
    for(int i=0;i<=n;i++){
      if (ar[i]) cout << i << " ";
    }
    cout <<""<< endl;
    return 0;
    }

}
