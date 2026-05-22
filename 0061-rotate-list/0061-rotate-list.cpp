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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* ptr = head;
        int n = 0;
        while(ptr!=nullptr){
            n++;
            ptr = ptr->next;
        }

        if(n<2) return head;

        k = k % n;
        if(k==0) return head;
        
        ListNode* prev = nullptr;
        ptr = head;
        int i=0;
        while(i<n-k){
            prev = ptr;
            ptr = ptr->next;
            i++;
        }

        prev->next = nullptr;
        ListNode* tp = ptr;

        while(ptr && ptr->next!=nullptr){
            ptr = ptr->next;    
        }

        ptr->next = head;
        return tp;
    }
};