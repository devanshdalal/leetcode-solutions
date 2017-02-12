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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry=0;
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        
        ListNode* hd=(ListNode *) malloc(sizeof(ListNode) ),*r=hd;
        
        ListNode* i1=l1,*i2=l2;
        while(i1!=NULL and i2!=NULL){
            int res= i1->val + i2->val + carry;
            auto node=(ListNode *) malloc(sizeof(ListNode) );
            node->val = res%10;
            hd->next=node;
            hd=node;
            carry=res/10;
            i1=i1->next; i2=i2->next;
            
        }
        
        while(i1!=NULL ){
            int res= i1->val +  carry;
            auto  node=(ListNode *) malloc(sizeof(ListNode) );
            node->val = res%10;
            hd->next=node;
            hd=node;
            carry=res/10;
            i1=i1->next;
        }
        
        while(i2!=NULL ){
            int res= i2->val +  carry;
            auto node=(ListNode *) malloc(sizeof(ListNode) );
            node->val = res%10;
            hd->next=node;
            hd=node;
            carry=res/10;
            i2=i2->next;
        }
        
        hd->next=NULL;
        
        if(carry){
            auto node=(ListNode *) malloc(sizeof(ListNode) );
            node->val = carry;
            hd->next=node;
            node->next=NULL;
        }
        
        return r->next;
        
    }
};