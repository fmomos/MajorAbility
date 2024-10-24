// 7-26 深入虎穴
// 分数 15
// 作者 陈越
// 单位 浙江大学
// 著名的王牌间谍 007 需要执行一次任务，获取敌方的机密情报。
// 已知情报藏在一个地下迷宫里，迷宫只有一个入口，里面有很多条通路，每条路通向一扇门。
// 每一扇门背后或者是一个房间，或者又有很多条路，同样是每条路通向一扇门……
// 他的手里有一张表格，是其他间谍帮他收集到的情报，他们记下了每扇门的编号，以及这扇门背后的每一条通路所到达的门的编号。
// 007 发现不存在两条路通向同一扇门。

// 内线告诉他，情报就藏在迷宫的最深处。但是这个迷宫太大了，他需要你的帮助 —— 请编程帮他找出距离入口最远的那扇门。

// 输入格式：
// 输入首先在一行中给出正整数 N（<10^5），是门的数量。最后 N 行，第 i 行（1≤i≤N）按以下格式描述编号为 i 的那扇门背后能通向的门：

// K D[1] D[2] ... D[K]
// 其中 K 是通道的数量，其后是每扇门的编号。

// 输出格式：
// 在一行中输出距离入口最远的那扇门的编号。题目保证这样的结果是唯一的。

// 输入样例：
// 13
// 3 2 3 4
// 2 5 6
// 1 7
// 1 8
// 1 9
// 0
// 2 11 10
// 1 13
// 0
// 0
// 1 12
// 0
// 0
// 输出样例：
// 12
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5;
vector<int> Map[maxn];
int n;
unordered_set<int> doorset(n + 1);
vector<int> depth(n + 1);
int maxdepth = 0,fardoor=0;
void dfs(int start,int depth)
{
    if(maxdepth<depth){
        maxdepth=depth;
        fardoor=start;
    }
    for(int i=0;i<Map[start].size();i++){
       dfs(Map[start][i],depth+1); 
    }

}
int main()
{
    int start;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        for (int j = 1; j <= m; j++)
        {
            int door;
            cin >> door;
            Map[i].push_back(door);
            doorset.insert(door);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (doorset.find(i) == doorset.end())
        {
            start = i;
            break;
        }
    }
    dfs(start,0);
    cout<<fardoor;
}
//dfs
//vector<int> v[maxn](maxn个vector<int>容器)和vector<int> v(maxn)不一样(一个vector<int>容器)



//bfs
// #include<bits/stdc++.h>//不知道入口在哪里，1不是入口！没有结点指向它的就是入口
// using namespace std;
// int bfs(const vector<vector<int>>& graph,int start,int dnum){
//     queue<int> q;
//     vector<bool>visited(dnum+1,false);//标记是否访问过
//     vector<int> depth(dnum+1,0);//在图的表示中，我们通常从 1 开始编号节点，因此需要 N + 1 来确保可以访问到第 N 个节点（节点编号从 1 到 N）。
//     //depth 数组用于记录每个节点到起始节点的距离（即深度）。初始化为 0 表示在开始时，所有节点的深度都是未知的。
//     q.push(start);
//     visited[start]=true;
//     int maxdepth=0;
//     int farthestdoor=start;
//     while(!q.empty()){
//         int current=q.front();
//         q.pop();
//         for(int neighbor:graph[current]){
//             if(!visited[neighbor]){
//                 visited[neighbor]=true;
//                 depth[neighbor]=depth[current]+1;
//                 q.push(neighbor);
//             }
//             if(depth[neighbor]>maxdepth){
//                 maxdepth=depth[neighbor];
//                 farthestdoor=neighbor;
//             }
            
            
//         }
//     }
//     return farthestdoor;
    
// }

// int main(){
//     int dnum;
//     cin>>dnum;
//     vector<vector<int>> graph(dnum+1);
//     vector<int> flag(dnum+1,0);
//     int start;
//     for(int i=1;i<=dnum;i++){//从1开始读取邻接表
//         int k;
//         cin>>k;
//         graph[i].resize(k);//设置大小
//         for(int j=0;j<k;j++){
//             int door;
//             cin>>door;
//             flag[door]=1;//如果前方有门，标记
//             graph[i][j]=door;
//         }
//     }
//     for(int i=1;i<=dnum;i++){
//         if(flag[i]==0){//入度为零的门是入口
//             start=i;
//             break;
//         }
//     }
//     int farthest=bfs(graph,start,dnum);
//     cout<<farthest;
// }