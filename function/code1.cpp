// 6-1 表彰优秀学生（多态）
// 分数 15
// 作者 何振峰
// 单位 福州大学
// 学期结束，班主任决定表彰一批学生，已知该班学生数在6至50人之间，有三类学生：
// 普通生，特招运动员，学科专长生，其中学科专长生不超过5人。

// 主函数根据输入的信息，相应建立GroupA, GroupB, GroupC类对象。

// GroupA类是普通生，有2门课程的成绩（均为不超过100的非负整数）；

// GroupB类是特招运动员，有2门课程的成绩（均为不超过100的非负整数），1次运动会的表现分，表现分有：A、B、C、D共4等。

// GroupC类是学科专长生，有5门课程的成绩（均为不超过100的非负整数）。

// 表彰人员至少符合以下3个条件中的一个：

// （1）2门课程平均分在普通生和特招运动员中，名列第一者。

// a.该平均分称为获奖线。

// b.存在成绩并列时，则全部表彰，例如某次考试有2人并列第1，则他们全部表彰。

// （2）5门课程平均分达到或超过获奖线90%的学科专长生，给予表彰。

// （3）2门课程平均分达到或超过获奖线70%的特招运动员，如果其运动会表现分为A，给予表彰。

// 输入格式：每个测试用例占一行，第一项为类型，1为普通生，2为特招运动员，3为学科专长生,
//  输入0表示输入的结束。第二项是学号，第三项是姓名。对于普通生来说，共输入5项，
//  第4、5项是课程成绩。对于特招运动员来说，共输入6项，第4、5项是课程成绩，
//  第6项是运动会表现。对于学科专长生来说，共输入8项，第4、5、6、7、8项是课程成绩。

// 输出时，打印要表彰的学生的学号和姓名。(输出顺序与要表彰学生的输入前后次序一致)

// 函数接口定义：
// 以Student为基类，构建GroupA, GroupB和GroupC三个类
// 裁判测试程序样例：
// #include<iostream>
// #include <string>
// using namespace std;

// /* 请在这里填写答案 */

// int main()
// {
//     const int Size=50;
//     string num, name;
//     int i,ty,s1,s2,s3,s4,s5;
//     char gs;
//     Student *pS[Size];
//     int count=0;
//     for(i=0;i<Size;i++){
//         cin>>ty;
//         if(ty==0) break;
//         cin>>num>>name>>s1>>s2;
//         switch(ty){
//              case 1:pS[count++]=new GroupA(num, name, s1, s2); break;
//              case 2:cin>>gs; pS[count++]=new GroupB(num, name, s1,s2, gs); break;
//              case 3:cin>>s3>>s4>>s5; pS[count++]=new GroupC(num, name, s1,s2,s3,s4,s5); break;
//         }            
//     }
//     for(i=0;i<count;i++) {
//         pS[i]->display();
//         delete pS[i];
//     }
//     return 0;
// }
// 输入样例：
// 1 001 AAAA 96 80
// 2 009 BBB 82 75 A
// 1 007 CC 100 99
// 3 012 CCCC 97 95 90 99 93
// 1 003 DDD 62 50
// 1 022 ABCE 78 92
// 2 010 FFF 45 40 A
// 3 019 AAA 93 97 94 82 80
// 0
// 输出样例：
// 009 BBB
// 007 CC
// 012 CCCC


class Student{//获奖线是普通生和特招运动员的2门课程平均分！！！所以要用两个构造函数区别开来以免学科特长生的成绩影响到获奖线
protected:
    string num;
    string name;
    int course1,course2;
public:
    static float aw;
    Student(const string& num,const string& name):num(num),name(name){
        
    }//“：   ”是构造列表；string和vector用const&更好大数组，复杂的类，int不需要
    Student(const string& num,const string& name,int s1,int s2):
    num(num), name(name),course1(s1), course2(s2){
         if((course1+course2)/2.0>=aw){
            aw=(course1+course2)/2.0;//获取获奖线
        }
    }
    virtual void display()=0;//纯虚函数，必须在子类定义实现
};
float Student::aw = 0.0;
class GroupA:public Student{
    public:
    GroupA(const string& num,const string& name,int s1,int s2):
    Student(num,name,s1,s2){
       
    }//不需要加；
    void display(){
        if((course1+course2)/2.0==aw){
            cout<<num<<" "<<name<<endl;
        }
    }
};
class GroupB:public Student{
    char performance;
    public:
    GroupB(const string& num,const string& name,int s1,int s2,char performance):
    Student(num,name,s1,s2),performance(performance){
    }
    void display(){
        if((course1+course2)/2.0==aw){
            cout<<num<<" "<<name<<endl;
        }else if((course1+course2)/2.0>=aw*0.7&&performance=='A'){
             cout<<num<<" "<<name<<endl;
        }
    }
};
class GroupC:public Student{
    int c1,c2,c3,c4,c5;
    public:
    GroupC(const string& num,const string& name,int c1,int c2,int c3,int c4,int c5):
    Student(num,name),c1(c1),c2(c2), c3(c3), c4(c4), c5(c5){
    }
    void display(){
        if((c1+c2+c3+c4+c5)/5.0>=aw*0.9){
            cout<<num<<" "<<name<<endl;
        }
    }
    
};

1
// class Student{
//     protected:
//     string id;
//     string name;
//     int s1;
//     int s2;
//     static float awardline;//静态成员变量！！！
//     public:
//      Student(const string& id,const string& name):
//     id(id),name(name){//获奖线是普通生和特招运动员的2门课程平均分！！！所以要用两个构造函数区别开来以免学科特长生的成绩影响到获奖线
//     }
//     Student(const string& id,const string& name,int s1,int s2):
//     id(id),name(name),s1(s1),s2(s2){
//         if((s1+s2)/2.0>awardline){
//             awardline=(s1+s2)/2.0;
//         }
//     }
//     virtual void display()=0;
// };
// float Student::awardline = 0.0; // 初始化静态成员变量！！！
// class GroupA:public Student{
//     public:
//     GroupA(const string& id,const string& name,int s1,int s2):
//     Student(id, name, s1, s2){
//     }
//     void display(){
//         if((s1+s2)/2.0==awardline){
//             cout<<id<<" "<<name<<endl;
//         }
//     }
// };
// class GroupB:public Student{
//     protected:
//     char gs;
//     public:
//     GroupB(const string& id,const string&  name,int s1,int s2,char gs):
//     Student(id, name, s1, s2),gs(gs){
        
//     }
//      void display(){
//         if((s1+s2)/2.0==awardline){
//             cout<<id<<" "<<name<<endl;
//         }else if((s1+s2)/2.0>=awardline*0.7&&gs=='A'){
//             cout<<id<<" "<<name<<endl;
//         }
//     }
// };
// class GroupC:public Student{
//     protected:
//     int s1,s2,s3,s4,s5;
//     public:
//     GroupC(const string& id,const string&  name,int s1,int s2,int s3,int s4, int s5):
//     Student(id, name),s1(s1),s2(s2),s3(s3),s4(s4),s5(s5){
        
//     }
//      void display(){
//         if((s1+s2+s3+s4+s5)/5.0>=awardline*0.9){
//             cout<<id<<" "<<name<<endl;
//         }
//     }
// };