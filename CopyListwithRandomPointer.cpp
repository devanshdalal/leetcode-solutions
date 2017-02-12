/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL)return NULL;
        
        
        map<RandomListNode *,RandomListNode *> m;
        
        RandomListNode * it=head;
        
        RandomListNode * nlist=(RandomListNode *)malloc(sizeof(RandomListNode)),*ret=nlist;
        nlist->next=NULL;
        while(1){
            nlist->label = it->label;
            m[it]=nlist;
            if(it->next!=NULL){
                nlist->next=(RandomListNode *)malloc(sizeof(RandomListNode));
                nlist=nlist->next;
                nlist->next=NULL;
                it=it->next;   
            }else{
                break;
            }
        }
        
        nlist=ret;
        it=head;
        while(it!=NULL){
            nlist->random=m[it->random];
            nlist=nlist->next;
            it=it->next;
        }
        
        return ret;
        
        
        
        
        
    }
};