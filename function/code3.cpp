// 6-3 学生排名表（析构函数）
// 分数 15
// 作者 何振峰
// 单位 福州大学
// 现在输入一批学生（人数大于0且不超过100）的名次和他们的姓名。要求按名次输出每个人的排名。

// 输入格式：每行为一个学生的信息，共两项，
// 第一项为排名（为正整数，且任意两名学生的排名均不同），第二项为学生姓名。当输入－1时，表示输入结束。

// 输出格式：按名次输出学生姓名，每行一个。

// 函数接口定义：
// main函数的一部分。
// 裁判测试程序样例：
// #include <iostream>
// #include <string>
// using namespace std;
// class Student{
//     int rank;
//     string name;
//     public:
//         int getRank(){return rank;    }
//         Student(string name, int rank):name(name), rank(rank){    }
//         ~Student(){ cout<<name<<endl;}
// };
// int main(){
//     int rank, count=0;
//     const int SIZE=100;
//     Student *pS[SIZE];
//     string name;
//     cin>>rank;
//     while(count<SIZE && rank>0){
//         cin>>name;
//         pS[count++]= new Student(name, rank);
//         cin>>rank;
//     }

// /* 请在这里填写答案 */

//     return 0;
// }
// 输入样例：
// 1 Jack
// 5 Peter
// 2 Alice
// 6 Kate
// 52 Mike
// -1
// 输出样例：
// Jack
// Alice
// Peter
// Kate
// Mike

for(int i=0;i<count-1;i++){
    int minindex=i;
    for(int j=i+1;j<count;j++){
        if(pS[j]->getRank()<pS[minindex]->getRank()){
            minindex=j;
        }
    }
    if(minindex!=i){
        swap(pS[i],pS[minindex]);
    }
}
for(int i=0;i<count;i++){
    delete pS[i];
}