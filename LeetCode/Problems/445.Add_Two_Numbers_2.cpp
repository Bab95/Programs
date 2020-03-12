/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//#include<mast_model>
class Solution {
public:
    int length(ListNode* l1){
        int res = 0;
        while(l1!=NULL){
            res++;
            l1 = l1->next;
        }
        return res;
    }
    ListNode* reverse(ListNode* start){
        ListNode* ptr = start,*prev=NULL,*next;
        while(ptr!=NULL){
            next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = next;
        }
        start = prev;
        return start;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        /*ListNode* result = NULL,*q = NULL;
        l1 = reverse(l1);
        l2 = reverse(l2);
        int sum = 0;
        int carry = 0;
        while(l1!=NULL||l2!=NULL){
            int n1 = (l1==NULL)?0:l1->val;
            int n2 = (l2==NULL)?0:l2->val;
            sum = n1+n2+carry;
            carry = sum/10;
            sum = sum%10;
            if(result==NULL){
                result = new ListNode(sum);
                q = result;
            }else{
                q->next = new ListNode(sum);
                q = q->next;
            }
            if(l1!=NULL){
                l1 = l1->next;
            }
            if(l2!=NULL){
                l2 = l2->next;
            }
        }
        if(carry!=0){
            q->next = new ListNode(carry);
        }
        return reverse(result);*/
        int len1 = length(l1);
        int len2 = length(l2);
        cout<<len1<<" "<<len2<<endl;
        ListNode *small,*large;
        int diff = 0;
        int size = 0;
        if(len1<len2){
            small = l1;
            large = l2;
            diff = len2-len1;
            size = len2;
        }else{
            small = l2;
            large = l1;
            diff = len1-len2;
            size = len1;
        }
        int arr[size];
        int k = 0;
        while(diff--){
            arr[k] = large->val;
            large = large->next;
            k++;
        }
        while(large&&small){
            arr[k] = large->val+small->val;
            k++;
            large = large->next;
            small = small->next;
        }
        ListNode* result = NULL;
        int carry = 0;
        while(k--){
            if(result==NULL){
                result = new ListNode(arr[k]%10);
                carry = arr[k]/10;
            }
            else{
                int sum = arr[k]+carry;
                ListNode* tmp = new ListNode((sum)%10);
                carry = sum/10;
                tmp->next = result;
                result = tmp;
            }
        }
        if(carry!=0){
            ListNode* tmp = new ListNode(carry);
            tmp->next = result;
            result = tmp;
        }
        return result;
    }
};
