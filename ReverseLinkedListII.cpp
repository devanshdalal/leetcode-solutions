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
    
    int len(ListNode* h){
        if(h==NULL)return 0;
        return 1+len(h->next);
    }
    
    pair<ListNode*,ListNode*> reverse(ListNode* h){
        if(h==NULL or h->next==NULL)return make_pair(h,h);
        
        auto t=reverse(h->next);
        
        t.second->next=h;
        h->next=NULL;
        
        return make_pair(t.first,h);
        
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        int l =len(head);
        if(l==0)return NULL;
        if(m>n)return head;
        
        // cout << "here " << endl;
        int i;
        ListNode* it = head;
        ListNode* prev=NULL;
        
        // cout << "here " << endl;
        
        for(i=1;i<m;i++){
            prev=it;
            it=it->next;
        }
        
        
        
        ListNode* jt = it;
        for(;i<n;i++){
            jt=jt->next;
        }
        
        ListNode* tmp = jt->next;
        jt->next=NULL;
        
        
        
        pair<ListNode*,ListNode*> rev=reverse(it);
        
        
        
        if(prev==NULL){
            head = rev.first;
        }else{
            prev->next = rev.first;
        }
        
        rev.second->next=tmp;
        
        return head;
        
    }
};