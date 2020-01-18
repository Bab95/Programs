/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*Link:https://leetcode.com/problems/split-linked-list-in-parts/*/
class Solution {
public:
    int lengthList(ListNode* p){
        int res = 0;
        while(p!=NULL){
            res++;
            p = p->next;
        }
        return res;
    }
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<pair<ListNode*,ListNode*> > startEndMap(k);
        int i = 0;
        ListNode* p = root;
        int count = 0;
        int len = lengthList(root);
        //cout<<len<<endl;
        int q = len/k;
        int rem = len%k;
        while(i<k){
            count = (rem!=0)?(q+1):q;
            rem = (rem>1)?(rem-1):0;
            startEndMap[i].first = p;
            while(p!=NULL&&count>1){
                p = p->next;
                count--;
            }
            startEndMap[i].second = p;
            p = (p!=NULL)?(p->next):NULL;
            i++;
        }
        vector<ListNode*> resultVector;
        for(int i=0;i<k;i++){
            resultVector.push_back(startEndMap[i].first);
            if(startEndMap[i].second!=NULL){
                startEndMap[i].second->next = NULL;
            }
        }
        return resultVector;
    }
};
