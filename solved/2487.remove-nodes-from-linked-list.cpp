/*
 * @lc app=leetcode id=2487 lang=cpp
 *
 * [2487] Remove Nodes From Linked List
 *
 * https://leetcode.com/problems/remove-nodes-from-linked-list/description/
 *
 * algorithms
 * Medium (74.43%)
 * Likes:    1999
 * Dislikes: 70
 * Total Accepted:    182.3K
 * Total Submissions: 245K
 * Testcase Example:  '[5,2,13,3,8]'
 *
 * You are given the head of a linked list.
 * 
 * Remove every node which has a node with a greater value anywhere to the
 * right side of it.
 * 
 * Return the head of the modified linked list.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [5,2,13,3,8]
 * Output: [13,8]
 * Explanation: The nodes that should be removed are 5, 2 and 3.
 * - Node 13 is to the right of node 5.
 * - Node 13 is to the right of node 2.
 * - Node 8 is to the right of node 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,1,1,1]
 * Output: [1,1,1,1]
 * Explanation: Every node has value 1, so no nodes are removed.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of the nodes in the given list is in the range [1, 10^5].
 * 1 <= Node.val <= 10^5
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {

        // MONOTONIC STACK METHOD
        vector<ListNode*> stack;
        while(head)
        {
            while(!stack.empty() && stack.back()->val < head->val)
                stack.pop_back();
            
            stack.push_back(head);

            head = head->next;
        }

        for (size_t i = 0; i < stack.size()-1; ++i)
        	 stack[i]->next = stack[i+1];
        
        return stack.front();
    }
};
// @lc code=end

