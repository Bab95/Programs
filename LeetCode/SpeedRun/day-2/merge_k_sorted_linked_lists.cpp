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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        set<pair<int,ListNode*> > ss;
        for(int i=0;i<lists.size();++i){
            if(lists[i]!=NULL){
                ss.insert(make_pair(lists[i]->val,lists[i]));
            }
        }
        ListNode* result = NULL;
        ListNode* q = NULL;
        while(!ss.empty()){
            pair<int,ListNode*> p = *ss.begin();
            ss.erase(ss.begin());
            if(result==NULL){
                result = p.second;
                q = result;
                if(p.second->next){
                    p.first = p.second->next->val;
                    p.second = p.second->next;
                    ss.insert(p);
                }
                q->next = NULL;
            }else{
                q->next = p.second;
                q = q->next;
                if(p.second->next){
                    p.first = p.second->next->val;
                    p.second = p.second->next;
                    ss.insert(p);
                }
                q->next = NULL;
            }
        }
        return result;
    }
};
