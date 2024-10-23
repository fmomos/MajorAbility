// 7-24 链表去重
// 分数 15
// 作者 陈越
// 单位 浙江大学
// 给定一个带整数键值的链表 L，你需要把其中绝对值重复的键值结点删掉。
// 即对每个键值 K，只有第一个绝对值等于 K 的结点被保留。
// 同时，所有被删除的结点须被保存在另一个链表上。例如给定 L 为 21→-15→-15→-7→15，你需要输出去重后的链表 21→-15→-7，还有被删除的链表 -15→15。

// 输入格式：
// 输入在第一行给出 L 的第一个结点的地址和一个正整数 N（≤10^5，为结点总数）。一个结点的地址是非负的 5 位整数，空地址 NULL 用 -1 来表示。

// 随后 N 行，每行按以下格式描述一个结点：

// 地址 键值 下一个结点
// 其中地址是该结点的地址，键值是绝对值不超过10^4的整数，下一个结点是下个结点的地址。

// 输出格式：
// 首先输出去重后的链表，然后输出被删除的链表。每个结点占一行，按输入的格式输出。

// 输入样例：
// 00100 5
// 99999 -7 87654
// 23854 -15 00000
// 87654 15 -1
// 00000 -15 99999
// 00100 21 23854
// 输出样例：
// 00100 21 23854
// 23854 -15 99999
// 99999 -7 -1
// 00000 -15 87654
// 87654 15 -1
#include <bits/stdc++.h>
using namespace std;
struct node{
    string adr;
    int value;
    string next_adr;
};//结构体
int main()
{
    int n;
    string head_adr;
    cin>>head_adr>>n;
    unordered_map<string,node> nodeMap;//存链表
    for(int i=0;i<n;i++){
        node c;
        cin>>c.adr>>c.value>>c.next_adr;
        nodeMap[c.adr]=c;
    }
    vector<node> unique_nodelist;//存去重后的链表
    vector<node> delete_nodelist;
    unordered_set<int> repeat;//去重
    string current_adr=head_adr;
    while(current_adr!="-1"){
        node current_node=nodeMap[current_adr];
        if(repeat.find(abs(current_node.value))==repeat.end()){//如果 find 方法返回的迭代器等于 repeat 的 end 迭代器，则说明该绝对值不在 repeat 中
            repeat.insert(abs(current_node.value));
            unique_nodelist.push_back(current_node);
        }else{
            delete_nodelist.push_back(current_node);// // 重复值，加入删除列表
        }
        current_adr=current_node.next_adr;//改变地址
    }
    for(int i=0;i<unique_nodelist.size();i++){//更新地址指针，因为原来的有些节点被去除
        if(i<unique_nodelist.size()-1){//除了最后一个节点
            unique_nodelist[i].next_adr=unique_nodelist[i+1].adr;
        }else{
            unique_nodelist[i].next_adr="-1";
        }

    }
    for(int i=0;i<delete_nodelist.size();i++){
        if(i<delete_nodelist.size()-1){
            delete_nodelist[i].next_adr=delete_nodelist[i+1].adr;
        }else{
            delete_nodelist[i].next_adr="-1";
        }

    }
    for(node c:unique_nodelist){
        cout<<c.adr<<" "<<c.value<<" "<<c.next_adr<<endl;
    }
    for(node c:delete_nodelist){
        cout<<c.adr<<" "<<c.value<<" "<<c.next_adr<<endl;
    }

}