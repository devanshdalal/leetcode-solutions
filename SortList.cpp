/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int len(ListNode* A){
    if(A==NULL)return 0;
    return 1+len(A->next);
}

pair<ListNode*,ListNode*> partition(ListNode* head) {
    
    ListNode* n1=NULL,*n2=NULL,*it=NULL,*jt=NULL;
    int n = len(head);
    
    ListNode* i=head;
    for(int j=1;j<n/2;j++){
        i=i->next;
    }
    
    auto tmp = i->next;
    i->next=NULL;
    return make_pair(head,tmp);
} 

ListNode* merge(ListNode* a,ListNode* b) {
    
    if(a==NULL)return b;
    if(b==NULL)return a;
    
    auto it=a,jt=b;
    ListNode * res=NULL,*i;
    
    while(it!=NULL and jt!=NULL){
        if(it->val<=jt->val){
            if(res==NULL){
                res=i=it;
            }else{
                i->next=it;
                i=i->next;
            }
            it=it->next;
        }
        else{
            if(res==NULL){
                res=i=jt;
            }else{
                i->next=jt;
                i=i->next;
            }
            jt=jt->next;
        }
    }
    
    while(it!=NULL ){
        i->next=it;
        i=i->next;
        it=it->next;
    }
    
    while(jt!=NULL ){
        i->next=jt;
        i=i->next;
        jt=jt->next;
    }
    return res;
}

ListNode* my_sort(ListNode* head) {
    
    // if(head==NULL)return head;
    int n = len(head);
    if(n<=1)return head;
    // int x= min(head->val,head->next->val);
    auto p=partition(head);
    
    auto left = my_sort(p.first);
    auto right = my_sort(p.second);
    
    return merge(left,right);
} 

class Solution {
public:

    ListNode* sortList(ListNode* head) {
        
        return my_sort(head);        
    }
};