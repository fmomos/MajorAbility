// 7-25 愿天下有情人都是失散多年的兄妹
// 分数 15
// 作者 陈越
// 单位 浙江大学
// 呵呵。大家都知道五服以内不得通婚，即两个人最近的共同祖先如果在五代以内（即本人、父母、祖父母、曾祖父母、高祖父母）则不可通婚。
// 本题就请你帮助一对有情人判断一下，他们究竟是否可以成婚？

// 输入格式：
// 输入第一行给出一个正整数N（2 ≤ N ≤10^4），随后N行，每行按以下格式给出一个人的信息：

// 本人ID 性别 父亲ID 母亲ID
// 其中ID是5位数字，每人不同；性别M代表男性、F代表女性。如果某人的父亲或母亲已经不可考，则相应的ID位置上标记为-1。

// 接下来给出一个正整数K，随后K行，每行给出一对有情人的ID，其间以空格分隔。

// 注意：题目保证两个人是同辈，每人只有一个性别，并且血缘关系网中没有乱伦或隔辈成婚的情况。

// 输出格式：
// 对每一对有情人，判断他们的关系是否可以通婚：如果两人是同性，输出Never Mind；
// 如果是异性并且关系出了五服，输出Yes；如果异性关系未出五服，输出No。

// 输入样例：
// 24
// 00001 M 01111 -1
// 00002 F 02222 03333
// 00003 M 02222 03333
// 00004 F 04444 03333
// 00005 M 04444 05555
// 00006 F 04444 05555
// 00007 F 06666 07777
// 00008 M 06666 07777
// 00009 M 00001 00002
// 00010 M 00003 00006
// 00011 F 00005 00007
// 00012 F 00008 08888
// 00013 F 00009 00011
// 00014 M 00010 09999
// 00015 M 00010 09999
// 00016 M 10000 00012
// 00017 F -1 00012
// 00018 F 11000 00013
// 00019 F 11100 00018
// 00020 F 00015 11110
// 00021 M 11100 00020
// 00022 M 00016 -1
// 00023 M 10012 00017
// 00024 M 00022 10013
// 9
// 00021 00024
// 00019 00024
// 00011 00012
// 00022 00018
// 00001 00004
// 00013 00016
// 00017 00015
// 00019 00021
// 00010 00011
// 输出样例：
// Never Mind
// Yes
// Never Mind
// No
// Yes
// No
// Yes
// No
// No
#include <bits/stdc++.h>
using namespace std;
struct human
{
    char gender;
    string fid;
    string mid; 
};
unordered_map<string,human> familyMap;//存储所有人的信息
unordered_map<string,unordered_set<string>> ancestors;//存储每个人的祖先集合。
void find(const string& id,int generation,unordered_set<string>& ancestor_set){
if(generation>5)
return;
if(familyMap.find(id)==familyMap.end())
return;
ancestor_set.insert(id);
if(familyMap[id].fid!="-1"){
    find(familyMap[id].fid,generation+1,ancestor_set);
}
if(familyMap[id].mid!="-1"){
    find(familyMap[id].mid,generation+1,ancestor_set);
}
}
int main(){
    int n;
    cin>>n;
    while(n--){
        human p;
        string id;
        cin>>id>>p.gender>>p.fid>>p.mid;
        familyMap[id]=p;
         // 递归查找父亲和母亲的祖先
        if(p.fid!="-1"&&familyMap.find(p.fid)==familyMap.end()){
            familyMap[p.fid]={'M',"-1","-1"};
        }
        if(p.mid!="-1"&&familyMap.find(p.mid)==familyMap.end()){
            familyMap[p.mid]={'F',"-1","-1"};// 假设母亲性别为 'F'
        }
    }
    for(const auto& p:familyMap){
        unordered_set<string> ancestors_set;//使用 unordered_set 可以确保每个祖先ID只被记录一次
        find(p.first,1,ancestors_set);
        ancestors[p.first]=ancestors_set;
    }
    int m;
    cin>>m;
    while(m--){
        string p1,p2;
        cin>>p1>>p2;
        if(familyMap[p1].gender==familyMap[p2].gender){
            cout<<"Never Mind"<<endl;
        }else{
            bool related=false;
            for(const auto& ancestor:ancestors[p1]){
              if(ancestors[p2].count(ancestor)){//查找集合重复的部分
                related=true;
                break;
              }
            }
            if(related){
                cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }
        }
        
    }
}