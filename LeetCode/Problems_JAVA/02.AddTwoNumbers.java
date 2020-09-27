/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode result = null;
        ListNode q = null;
        int carry = 0;
        while(l1!=null||l2!=null){
            int a,b;
            if(l1==null){
                a = 0;
            }else{
                a = l1.val;
                l1 = l1.next;
            }
            if(l2==null){
                b = 0;
            }else{
                b = l2.val;
                l2 = l2.next;
            }


            int sum = a + b + carry;
            carry = sum/10;
            sum = sum%10;
            if(result==null){
                result = new ListNode(sum);
                q = result;
            }else{
                q.next = new ListNode(sum);
                q = q.next;
            }
        }
        if(carry!=0){
            q.next = new ListNode(carry);
        }
        return result;
    }
}
