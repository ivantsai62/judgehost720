#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge{
  int num;
  int v1;
  int v2;
  int c;
};
bool cmp(Edge a,Edge b){
  return a.c < b.c;
}
Edge edge[300001];
int num[501],parent[501];
int findParent(int a)
{
  while(a!=parent[a]){
    a=parent[a];
  }
  return a;
}
int main()
{
    int choose[300001];
    int edgenum = 0;
    int n , m ,numEdge,result;
    int v1,v2,c;
    cin>>n>>m;
    for(int i = 1 ; i <m+1;i++)
    {
        cin>>edge[i].v1>>edge[i].v2>>edge[i].c;
        edge[i].num = i;
    }
    for(int i=1;i<n+1;i++)
    {
      parent[i]=i;
      num[i]=1;
    }
    sort(edge,edge+m+1,cmp);
    result=0,numEdge=0;
    for(int i=1;i<m+1 && numEdge<n+1;i++){
      int a,b;
      a=findParent(edge[i].v1);
      b=findParent(edge[i].v2);
      if (a != b){
        if (num[a]>num[b])
        {
          parent[b]=a;
          num[a]+=num[b];
        } else
        {
          parent[a]=b;
          num[b]+=num[a];
        }
        result+=edge[i].c;
        choose[edgenum]=edge[i].num;
        edgenum++;
        numEdge++;
      }
    }

        if (numEdge == (n-1)||result==0) cout << result << endl;

    for(int i= 0 ; i<edgenum;i++)
    {
        if(i==edgenum)
        {
            cout<<choose[i];
        }
        else
        cout<<choose[i]<<" ";
    }
    return 0;
}
