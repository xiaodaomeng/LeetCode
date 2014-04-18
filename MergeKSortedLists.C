/**
 Merge k Sorted Lists
 Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class mycomp{
public:   
    bool operator()(ListNode *a,ListNode *b){
        return a->val>b->val?true:false;
    }
};
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        //priority_queue,time O(n1+n2+...),space O(1)
        priority_queue<ListNode*,vector<ListNode *>,mycomp> q;
        ListNode dummy(0),*cur=&dummy;
        for(int i=0;i<lists.size();i++){
            if(lists[i]) q.push(lists[i]);
        }
        while(!q.empty()){
            ListNode *node=q.top();
            cur->next=node;
            q.pop();
            cur=cur->next;
            if(node->next) q.push(node->next);
        }
        return dummy.next;
    }
};
