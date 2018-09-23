//
// Created by edz on 2018/9/23.
//
#include <vector>
#include "iostream"
#include "sstream"
#include <stack>
#include <queue>
#include <math.h>
using namespace std;
bool Find(int target, vector<vector<int> > array) {
    /*
     * 矩阵是有序的 从左下角开始
     * 上边的都比他小 右边的都比他大
     * */
    int rowCount = array.size();
    int colCount = array[0].size();
    int i,j;
    for(i=rowCount-1,j=0;i>=0&&j<colCount;)
    {
        if(target == array[i][j])
            return true;
        if(target < array[i][j])
        {
            i--;
            continue;
        }
        if(target > array[i][j])
        {
            j++;
            continue;
        }
    }
    return false;


}
void replaceSpace(char *str,int length) {
    // 1.从前往后插入 2.从后往前插入
    stringstream stringstream;
    for (int i;i<length;i++) {
//        cout<<int(str[i])<<endl;
        if (int(str[i]) != 32){
            stringstream<<str[i];
        } else {
            stringstream<<"%20";
        }
    }
    stringstream >> str;

    cout<<str<<endl;
}

 struct ListNode {
       int val;
       struct ListNode *next;
       ListNode(int x) :
             val(x), next(NULL) {
       }
 };

vector<int> printListFromTailToHead(ListNode* head) {
    vector<int > result;
    stack<int> s;
    while (head!=NULL) {
        s.push(head->val);
        head=head->next;
    }
    while (!s.empty()) {
       result.push_back(s.top());
       s.pop();
    }
    return result;
}

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {

    int inlen=in.size();

    if(inlen==0)

        return NULL;

    vector<int> left_pre,right_pre,left_in,right_in;

    //创建根节点，根节点肯定是前序遍历的第一个数

    TreeNode* head=new TreeNode(pre[0]);

    //找到中序遍历根节点所在位置,存放于变量gen中

    int gen=0;

    for(int i=0;i<inlen;i++)

    {

        if (in[i]==pre[0])

        {

            gen=i;

            break;

        }

    }

    //对于中序遍历，根节点左边的节点位于二叉树的左边，根节点右边的节点位于二叉树的右边

    //利用上述这点，对二叉树节点进行归并

    for(int i=0;i<gen;i++)

    {

        left_in.push_back(in[i]);

        left_pre.push_back(pre[i+1]);//前序第一个为根节点

    }

    for(int i=gen+1;i<inlen;i++)

    {

        right_in.push_back(in[i]);

        right_pre.push_back(pre[i]);

    }

    //和shell排序的思想类似，取出前序和中序遍历根节点左边和右边的子树

    //递归，再对其进行上述所有步骤，即再区分子树的左、右子子数，直到叶节点

    head->left=reConstructBinaryTree(left_pre,left_in);

    head->right=reConstructBinaryTree(right_pre,right_in);

    return head;

}
void Solution1() {
//    在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
//    每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
//    Find()
}
void Solution2() {
    /*
     * 请实现一个函数，将一个字符串中的每个空格替换成“%20”。
     * 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
     * */
//    replaceSpace();

}
void Solution3() {
    /*
     * 输入一个链表，按链表值从尾到头的顺序返回一个ArrayList
     * */
    //printListFromTailToHead(ListNode* head)

}
void Sloution4() {
    /*
     * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
     * 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
     * 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
     * 使用递归的思路
     * */
    //reConstructBinaryTree
}
void Sloution5() {
//    用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

}
class Solution5
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
       while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int result = stack2.top();
        stack2.pop();
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return result;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

void  Sloution6() {
    /*
     * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
     * 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
     * NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
     * */
    //minNumberInRotateArray
}
int minNumberInRotateArray(vector<int> rotateArray) {
    if (rotateArray.size() == 0) return 0;
    else if (rotateArray.size() == 1) return rotateArray[0];
    else if (rotateArray.size() == 2) return rotateArray[0];
    else {
        for (int i=0;i<rotateArray.size();i++) {
            if (rotateArray[i+1] - rotateArray[i]<0){
                return rotateArray[i+1];
            }
        }
    }
}

void Solution7() {
    /*
     *大家都知道斐波那契数列，现在要求输入一个整数n，
     *请你输出斐波那契数列的第n项（从0开始，第0项为0）。
      n<=39
     * */

}
int Fibonacci(int n) {
    if (n==0)
        return 0;
    else if (n==1) {
        return 1;
    } else {
        int a = 1;
        int b = 1;
        int t = 0;
        for (int i = 2; i < n; i++) {
            t = a;
            a = b;
            b = b + t;
        }
        return b;
    }
    return 0;
}

void Solution8(){
    /*
     * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。
     * 求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
     * */
}
int jumpFloor(int number) {
    if (number==0) return 0;
    else if (number==1) return 1;
    else if (number==2) return 2;
    else {
        return jumpFloor(number-1)+jumpFloor(number-2);
    }
}
void Solution9() {
    /*
     * 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
     * 求该青蛙跳上一个n级的台阶总共有多少种跳法。
     * */
}
int jumpFloorII(int number) {
    if (number==0) return 0;
    else if (number==1) return 1;
    else if (number==2) return 2;
    else {
        return jumpFloorII(number-1)+jumpFloorII(number-2)+jumpFloorII(number-2);
    }
}
void Solution10() {
    /*
     * 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
     * 请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
     * */
}
int rectCover(int number) {
    if (number==1) return 1;
    else if (number==2) return 2;
    else {
        rectCover(number-1)+rectCover(number-2);
    }
    return 0;
}
void Solution11() {
    /*
     * 输入一个整数，输出该数二进制表示中1的个数。
     * 其中负数用补码表示。
     * 。如1100&1011=1000.也就是说，把一个整数减去1，再和原整数做与运算，会把该整数最右边一个1变成0.
     * 那么一个整数的二进制有多少个1，就可以进行多少次这样的操作。
     * */
}
int  NumberOf1(int n) {
    int count = 0;
    while (n!=0) {
        n=n & (n-1);
    }
    return count;
}
void Solution12() {
    /*
     * 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
     * */
}
double Power(double base, int exponent) {
    return pow(base,exponent);
}
void Solution13() {
    /*
     *输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
     *所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
     * */
}
void reOrderArray(vector<int> &array) {
    queue<int> ou_queue;
    queue<int > ji_queue;
    for (int i = 0; i < array.size(); ++i) {
        if (array[i]%2==0) {
            ou_queue.push(array[i]);
        } else{
            ji_queue.push(array[i]);
        }
    }
    int n=0;
    while(!ji_queue.empty()) {
        array[n] = ji_queue.front();
        ji_queue.pop();
        n++;
    }

    while(!ou_queue.empty()) {
        array[n] = ou_queue.front();
        ou_queue.pop();
        n++;
    }
    return;
}
void Solution14() {
    /*输入一个链表，输出该链表中倒数第k个结点*/
    /*
     * 两个指针，先让第一个指针和第二个指针都指向头结点，然后再让第一个指正走(k-1)步，到达第k个节点。然后两个指针同时往后移动，当第一个结点到达末尾的时候，第二个结点所在位置就是倒数第k个节点了
     * */

}
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    stack<ListNode*> s;

    while (pListHead!=NULL) {
        s.push(pListHead);
        pListHead=pListHead->next;
    }
//    k--;
//    for (;k>0;k--) {
        cout<<s.top()->val<<endl;
//        s.pop();
//    }
//
//    return s.top();
}
void Solution15() {
    /*输入一个链表，反转链表后，输出新链表的表头。*/

}
ListNode* ReverseList(ListNode* pHead) {

}
void Test(){
//    vector<int > array;
//    array.push_back(3);
//    cout<<array.size()<<endl;
//    cout<<array.at(array.size()-1);
    ListNode listNode(0);
    ListNode listNode1(1);
    ListNode listNode2(2);
    listNode.next=&listNode1;
    listNode1.next=&listNode2;
    cout<<FindKthToTail(&listNode,2)->val;

}