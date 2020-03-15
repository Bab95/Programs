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
  void add(ListNode* head,bool *flag){
    if(head->next==NULL){
      head->val += 1;
      *flag = (head->val/10==1)?true:false;
      head->val = head->val%10;
      return;
    }
    add(head->next,flag);
    if(*flag==true){
      head->val += 1;
      *flag = (head->val/10==1)?true:false;
      head->val = head->val%10;
      return;
    }
  }
  ListNode* plusOne(ListNode* head) {
      bool carry = false;
      add(head,&carry);
      if(carry==true){
        ListNode* sentinal = new ListNode(1);
        sentinal->next = head;
        head = sentinal;

      }
      return head;
  }
};
/*
#include <iostream>
using namespace std;
struct ListNode {
     int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
  void add(ListNode* head,bool *flag){
      if(head->next==NULL){
        head->val += 1;
        *flag = (head->val/10==1)?true:false;
        head->val = head->val%10;
        return;
      }
      add(head->next,flag);
      if(*flag==true){
        head->val += 1;
        *flag = (head->val/10==1)?true:false;
        head->val = head->val%10;
        return;
      }
    }
    ListNode* plusOne(ListNode* head) {
        bool carry = false;
        add(head,&carry);
        if(carry==true){
          ListNode* sentinal = new ListNode(1);
          sentinal->next = head;
          head = sentinal;

        }
        return head;
    }
    void print(ListNode* head){
    	while(head!=NULL){
    		cout<<head->val<<" ";
    		head = head->next;
    	}
    	cout<<endl;
    }
int main() {
	// your code goes here
	int n;
	cin>>n;
	int input;
	ListNode *head = NULL,*q = NULL;
	while(n--){
		cin>>input;
		if(head==NULL){
			head = new ListNode(input);
			q = head;
		}else{
			q->next = new ListNode(input);
			q = q->next;
		}
	}
	head = plusOne(head);
	print(head);
	return 0;
}
*/
