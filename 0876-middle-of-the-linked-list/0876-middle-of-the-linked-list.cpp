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
    
    //getting length of the linked list.
    int getLength(ListNode* &head, ListNode* curr){
        int cnt = 0;
        while(curr != NULL){
            curr = curr -> next;
            cnt++;
        }
        return cnt;
    }
    
    
    ListNode* middleNode(ListNode* head) {
        ListNode* curr = head;
        ListNode* temp = head;
        
        int len = getLength(head, curr);
        
        //finding middle of linked list
        int mid = len/2;
        int it = 0;
        while(it != mid){
            temp = temp -> next;
            it++;
        }
        return temp;
    }
};