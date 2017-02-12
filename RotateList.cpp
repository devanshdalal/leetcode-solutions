/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    int len(ListNode* a){
        if(a==NULL)return 0;
        return len(a->next)+1;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        int n = len(head);
        if(n==0)return head;
        if(k>=n)k=k%n;
        if(k==0)return head;
        
        ListNode* it=head;
        
        for(int i=0;i<n-k-1;i++){
            it=it->next;
        }
        
        ListNode* new_head=it->next;
        
        it->next=NULL;
        
        it=new_head;
        while(it->next){
            it=it->next;
        }
        
        it->next=head;
        return new_head;
        
        
    }
};