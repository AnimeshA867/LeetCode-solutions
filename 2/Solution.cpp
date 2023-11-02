class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head= new ListNode(0);
        ListNode *p1=new ListNode(); 
        p1=head;
        
        int carry=0,sum;
        while(l1||l2||carry){
           int x= (l1)?l1->val:0;
           int y=l2?l2->val:0;
           sum=x+y+carry;
           carry=sum/10;
           p1->next=new ListNode(sum%10);
           p1=p1->next;
           l1?l1=l1->next:NULL;
           l2?l2=l2->next:NULL;
        }
        return head->next;
        

    }
};