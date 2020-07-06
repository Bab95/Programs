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
        while(ss.size()>0){
            auto itr = ss.begin();
            pair<int,ListNode*> p = *itr;
            ss.erase(itr);
            if(result==NULL){
                result = p.second;
                q = result;

                if(p.second->next!=NULL){
                    ss.insert(make_pair(p.second->next->val,p.second->next));
                }
                q->next = NULL;
            }else{
                q->next = p.second;
                q = q->next;

                if(p.second->next!=NULL){
                    ss.insert(make_pair(p.second->next->val,p.second->next));
                }
                q->next = NULL;
            }
        }
        return result;
    }
};
