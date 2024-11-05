// 6-5 2017Final 乐观的中考生
// 分数 15
// 作者 何振峰
// 单位 福州大学
// 作为参加首届全省统一中考的学生，小林同学的压力非常大。
// 每天老师都会布置很多批作业，每批作业具有相同的优先值（不同批的任务的优先值不一样），
// 由若干个不同的任务组成，每个任务都有唯一的编号，小林同学会把每批作业先按照编号顺序整理好，
// 然后按照这批作业的优先值，放入活页夹里。接下来，她将按照任务在活页夹的顺序依次把作业完成。

// 但近期情况有改变了：妈妈给她生了一个弟弟，所以她要时不时帮妈妈照看一下他。令她欣慰的是：
// 可爱的弟弟非常乖，每次吵闹的时间和程度都是可以预期的。因此她可以确定当前能用于完成作业的最长时间，
// 每项任务的可持续时间（最短时间和最长时间，其中设置最短时间是因为连续的学习时间非常宝贵，
// 所以在预期弟弟会安静较长时间时，她要把时间放在那些工作量较大的任务上），然后按符合条件的任务在活页夹中的顺序来完成。

// 林同学非常乐观，当她整理完一批作业，或者结束一次工作时，
// 都会找出该批作业的第三个任务或者活页夹中的第三个任务（因为3是她的幸运数字）看一下，如果任务数少于3个，
// 她会愉快地说一声"OK"。

// 现在要输出林同学看到的任务和她说的"OK"。

// 输入时，每次输入一行：

// （1）如果该行的第一个数字是正数N时，说明新来了一批任务，这批任务由N个任务构成。
// 第二个数字是该批任务的优先值，为不超过10000的正整数，从第三个数字开始的2*N个数字是顺序的N个任务的信息，
// 前面一个是任务号（不超过10000的正整数），后一个是任务的持续时间（不超过200的正整数）。（每批任务在输入时，
// 已经按照编号排好序了，因此不需要考虑按顺序号的从小到大排序过程，只好按任务来到的顺序简单整理好，放进一个小链表就可以了。）
// 。然后再将这批任务根据优先值插入活页夹（大链表）。

// （2）如果该行的第一个数字是负数，则说明现在可以做作业了，接下来会输入三个数字，第一个数字是单项任务的最短持续时间mi，
// 第二个数字是单项任务的最长持续时间ma,最后一个数字是本次工作的最长持续时间load.

// （3）如果该行的第一个数字是0，则结束。

// 函数接口定义：
// Task* getBatch(int m);   //接收一批任务，该批任务共有m项任务
// Task* addBatch(Task *head, Task *h);//将h指向的小链表插入head指向的大链表，并返回新的大链表首指针。
// void display(Task *head, int m);//输出第m项任务的信息，或者输出OK
// Task* study(Task*head, int mi, int ma, int load);
// //mi是本次学习过程中，所学习的各个单项任务的最短持续时间约束，ma是单项任务的最长持续时间约束, load是本次学习过程的最长持续时间
// 裁判测试程序样例：
// #include <iostream>
// using namespace std;
// struct Task{
//     int ID;//任务编号
//     int key;//任务优先级
//     int load;//任务持续时间
//     Task *next;
// };

// /* 请在这里填写答案 */

// void del(Task* head){//删除链表
//     if(head==NULL) return;
//     del(head->next);
//     delete head;
// }
// const int K=3;//幸运数字
// int main(){
//     int count, mi, ma, load;
//     Task *head=NULL, *h;
//     cin>>count;//输入行的第一个数字
//     while(count!=0){
//         if(count>0){   //新添加count个任务
//             h=getBatch(count);//构建链表，并将首指针返回给h
//             display(h, K);//显示小链表的第K个任务或输出OK
//             head=addBatch(head, h);//将小链表加入大链表，并将首指针返回
//         }else{
//             cin>>mi>>ma>>load;
//             head=study(head, mi, ma, load);
//             display(head,K);//显示大链表的第K个任务或输出OK
//         }
//         cin>>count;        
//     }
//     del(head);
//     return 0;
// }

// 输入样例：
// 4 12 101 5 102 3 103 6 104 7
// 2 22 105 12 106 8
// 1 9 107 9
// -1 5 10 25
// 0
// 输出样例：
// 输出时先输出任务号，再输出任务的优先级，最后输出时间。如果没有可输出的任务，则输出“OK”。

// 103 12 6
// OK
// OK
// 105 22 12
// 说明：

// （1）输入：4 12 101 5 102 3 103 6 104 7后，

// 子链（即小链表)共有四项任务101,102,103和104，其中第三项任务是103, 所以输出它的编号，优先值和时间103 12 6

// 将子链加入活页夹（大链表）后，活页夹中也是四项任务

// （2）输入：2 22 105 12 106 8后

// 子链中共有两项任务105和106，找不到第三项，所以输出OK。

// 加入活页夹中，此时活页夹中共有六项任务：101,102,103,104,105,106

// （3）输入：1 9 107 9后

// 子链中共有一项任务，所以输出OK。

// 加入活页夹中，此时活页夹中共有七项任务，顺序为：107,101,102,103,104,105,106

// (4)-1 5 12 25

// 则顺序完成活页夹中时间在5和12之间的任务，最多持续时间为20

// 第一项任务107，持续时间为9，符合要求，完成该项任务后，剩余时间为16

// 第二项任务101, 持续时间为5, 符合要求，完成该项任务后，剩余时间为11
// 第三项任务102，持续时间为3, 不符合最低持续时间为5的要求，直接忽略。

// 第四项任务103,持续时间为6，符合要求，完成该项任务后，剩余时间为5。

// 接下来的任务都没有足够时间完成，所以此时活页夹中剩余四项任务，为：102,104,105,106

// 此时输出活页夹的第三项任务信息：105 22 12

// (5)输入0，结束

Task* getBatch(int m){
    Task *head=nullptr,*tail=nullptr;//指针初始化，nullptr更安全
    int priority;
    cin>>priority;
    for(int i=0;i<m;i++){
       Task* p = new Task;//声明了一个指向 Task 类型对象的指针 p1，并为它分配实际的对象。
       cin>>p->ID>>p->load;
        p->key=priority;
        p->next=nullptr;
    if(head==nullptr){
        head=p;
        tail=p;
    }else{
        tail->next=p;//连接现在的尾部
        tail=p;//移动尾指针
    }
}
    return head;
}
void display(Task *head, int m){
    int cnt=0;
    Task *current=head;
    while(current!=NULL){
        cnt++;
        if(cnt==m){
            cout<<current->ID<<" "<<current->key<<" "<<current->load<<endl;
            return;
        }
        current=current->next;
    }
    cout<<"OK\n";
}
Task* addBatch(Task *head, Task *h) {
    if (h == nullptr) return head; // 如果小链表为空，直接返回大链表
    if (head == nullptr) return h; // 如果大链表为空，返回小链表
    Task *htail=h;//小链表的尾指针！！！！
    while(htail->next!=nullptr){
        htail=htail->next;
    }
    // 检查小链表的优先级是否大于或等于大链表头节点的优先级
    if (head->key >= h->key) {
        htail->next = head; // 小链表成为新的头，小链表尾指针指向大链表！！！
        return h;
    }
    // 遍历大链表以找到合适的插入位置
    Task *current = head;
    while (current->next != nullptr) {
        // 当前节点的优先级大于或等于小链表的优先级，且下一个节点的优先级小于或等于小链表的优先级
        if (current->key <= h->key && current->next->key >= h->key) {
            htail->next = current->next; // 将小链表插入到当前节点和下一个节点之间
            current->next = h;
            return head; // 返回更新后的大链表头
        }
        current = current->next; // 移动到下一个节点
    }

    // 如果遍历到大链表末尾，说明小链表的优先级最低
    current->next = h; // 大链表的尾指针指向小链表的头指针！！！！
    return head;
}
Task* study(Task *head, int mi, int ma, int load) {
    Task *current = head;
    Task *prev = nullptr;
    //      Task* current1 = head; // 从头节点开始
    // while (current1 != nullptr) { // 直到到达链表末尾
    //     cout << "ID: " << current1->ID 
    //          << ", 优先级: " << current1->key 
    //          << ", 持续时间: " << current1->load << endl;
    //     current1 = current1->next; // 移动到下一个节点
    // }
    while (current != nullptr) {
        if (current->load >= mi && current->load <= ma && load >= current->load) {
            load -= current->load; // 减去任务持续时间
            Task *temp = current;
            // 删除当前任务
            if (prev == nullptr) {
                // 删除头节点
                head = current->next; // 更新头指针
                current = current->next; // 移动到下一个任务
            } else {
                // 删除中间或尾部节点
                prev->next = current->next;
                current = current->next; // 移动到下一个任务
            }
            delete temp; // 释放内存
        } else {
            prev = current; // 更新前一个节点
            current = current->next; // 移动到下一个任务
        }
    }

    return head;
}