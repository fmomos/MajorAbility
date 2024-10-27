// 6-2 工作备忘录的生成（链表）
// 分数 15
// 作者 何振峰
// 单位 福州大学
// 每天都要处理很多事务，为了更好地安排工作，希望在每天开始工作前，根据工作记录，
// 生成工作备忘录。首先输入工作记录数（大于0的一个整数），再逐条输入各条工作记录，
// 每条工作记录包括：工作名，开始时间，结束时间。假设每项工作的开始时间均小于它的结束时间，并且各项工作的开始时间互不相同。

// 我们的工作是需要把这些工作记录按开始时间排序并输出，
// 在输出时，如果某项工作与若干项工作冲突（在做该项工作时，需要同时做其它工作），则在该工作名前加'*'。

// 函数接口定义：
// Node* add(Node *, Node *);
// void display(Node *);
// 裁判测试程序样例：
// #include<iostream>
// #include <string>
// using namespace std;
// struct Node{
//     string name;
//     int start;
//     int end;
//     Node *next;
// };
// Node* add(Node *, Node *);
// void display(Node *);
// bool check(Node *head)
// {
//     if(head==NULL || head->next==NULL) return true;
//     Node *p=head->next;
//     if(head->start > p->start) return false;
//     return check(p);
// }
// int main()
// {
//     Node *head=NULL, *p;
//     int i, repeat;
//     cin>>repeat;
//     for(i=0;i<repeat;i++){
//         p = new Node;
//         cin>>p->name>>p->start>>p->end;
//         p->next=NULL;
//         head = add(head, p);
//     }
//     if(!check(head)) cout<<"ERROR"<<endl;
//     display(head);
//     return 0;
// }

// /* 请在这里填写答案 */
// 输入样例：
// 4
// aaa 19 20
// ccc 169 200
// ddd 153 170
// bbb 20 111
// 输出样例：
// aaa 19 20
// bbb 20 111
// *ddd 153 170
// *ccc 169 200

Node* add(Node *head, Node *newnode){
    if(head==NULL||newnode->start<head->start){
        newnode->next=head;
        return newnode;
    }
    Node *current=head;
    while(current->next!=NULL&&current->next->start<newnode->start){
        current=current->next;
    }
    newnode->next=current->next;
    current->next=newnode;
    return head;
};
// void display(Node *head){
//     int flag=0;
//     Node *current=head;
//     while(current!=NULL){
//         if(current->next!=NULL){
//         if(current->end<=current->next->start&&flag==0){
//              cout<<current->name<<" "<<current->start<<" "<<current->end<<endl;
//         }else if(current->end<=current->next->start&&flag==1) {
//             cout<<"*"<<current->name<<" "<<current->start<<" "<<current->end<<endl;
//             flag=0;
//         }else {
//             cout<<"*"<<current->name<<" "<<current->start<<" "<<current->end<<endl;
//             flag=1;
//         }
//         }else{
//             if(flag==0){
//                 cout<<current->name<<" "<<current->start<<" "<<current->end<<endl;
//             }else{
//                 cout<<"*"<<current->name<<" "<<current->start<<" "<<current->end<<endl;
//             }
//         }
//         current=current->next;
//     }
// };
void display(Node *head) {
    Node *current = head;
    while (current != NULL) {
        bool hasConflict = false;
        Node *check = head;
        
        // 检查当前工作是否与其他工作冲突
        while (check != NULL) {
            if (check != current && ((current->start < check->end && current->end > check->start))) {
                hasConflict = true;
                break;
            }
            check = check->next;
        }
        
        // 如果有冲突，在工作名前加 '*'
        if (hasConflict) {
            cout << '*' << current->name << ' ' << current->start << ' ' << current->end << endl;
        } else {
            cout << current->name << ' ' << current->start << ' ' << current->end << endl;
        }
        
        current = current->next;
    }
}