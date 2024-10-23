// 7-21 装箱问题
// 分数 15
// 作者 DS课程组
// 单位 浙江大学
// 假设有N项物品，大小分别为s1、s2、…、si、…、sN，其中si为满足1≤si≤100的整数。要把这些物品装入到容量为100的一批箱子（序号1-N）中。
//  装箱方法是：对每项物品, 顺序扫描箱子，把该物品放入足以能够容下它的第一个箱子中。
//  请写一个程序模拟这种装箱过程，并输出每个物品所在的箱子序号，以及放置全部物品所需的箱子数目。

// 输入格式：
// 输入第一行给出物品个数N（≤1000）；第二行给出N个正整数si（1≤si≤100，表示第i项物品的大小）。

// 输出格式：
// 按照输入顺序输出每个物品的大小及其所在的箱子序号，每个物品占1行，最后一行输出所需的箱子数目。

// 输入样例：
// 8
// 60 70 80 90 30 40 10 20
// 输出样例：
// 60 1
// 70 2
// 80 3
// 90 4
// 30 1
// 40 5
// 10 1
// 20 2
// 5
#include <bits/stdc++.h>
using namespace std;
struct store
{
    int id;
    int size;
};
int main()
{
    int n,cnt=0;
    cin >> n;
    vector<int> boxes(n, 100);
    vector<store> store_res(n);
    for (int i=1;i<=n;i++)
    {
        int s;
        cin >> s;
        int k = 0 ;
        while (boxes[k] < s)
        {
            k++;
        }
        if(k>cnt){
            cnt=k;
        }
            boxes[k] -= s;
            store_res[i].id = k+1;//编号要加一，因为原来是从零开始
            store_res[i].size = s;
    }
    for (int i=1;i<=n;i++)
    {
        cout << store_res[i].size << " " << store_res[i].id << endl;
    }
    cout<<cnt+1;
}