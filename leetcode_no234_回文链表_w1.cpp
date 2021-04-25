/* ------------------------------------------------------------------|
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意:
不能使用代码库中的排序函数来解决这道题。

示例:

输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]
进阶：

一个直观的解决方案是使用计数排序的两趟扫描算法。
首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
你能想出一个仅使用常数空间的一趟扫描算法吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-colors
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	双指针法
*
*	执行用时：288 ms, 在所有 C++ 提交中击败了22.39%的用户
*	内存消耗：115.2 MB, 在所有 C++ 提交中击败了35.36%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

//时间复杂度:O(n)
//空间复杂度:O(n)
//bool isPalindrome(ListNode* head) {
//    vector<int> nums;
//    while (head) {
//        nums.emplace_back(head->val);
//        head = head->next;
//    }
//    int n = nums.size();
//    int i = 0;
//    int j = n - 1;
//    while (i <= j) {
//        if (nums[i++] != nums[j--]) {
//            return false;
//        }
//    }
//    return true;
//}

ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    while (head->next) {
        ListNode* next = head->next;
        head->next = next->next;
        next->next = dummy->next;
        dummy->next = next;
    }
    return dummy->next;
}

bool isPalindrome(ListNode* head) {
    //len=0||len=1
    if (!head || !head->next) {
        return true;
    }
    //len=2
    if (!head->next->next) {
        return head->val == head->next->val;
    }
    //快慢指针确定位置
    //pre为第一节队尾
    //pre->next为第二节队头
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* pre = dummy;
    ListNode* fast = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        pre = pre->next;
    }
    //反转链表
    pre->next = reverseList(pre->next);
    //判断回文
    bool res = 1;
    ListNode* p = head;
    ListNode* q = pre->next;
    while (p != pre->next) {
        if (p->val != q->val) {
            res = 0;
            break;
        }
        p = p->next;
        q = q->next;
    }
    //还原反转
    pre->next = reverseList(pre->next);
    return res;
}