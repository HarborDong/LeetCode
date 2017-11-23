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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	int temp = 0;
	struct ListNode *templist1 = l1, *templist2 = l2;
    
    if(!l1 && l2)
		return l2;
	
	while(templist1 || templist2 || temp)
	{
		if(templist1 && templist2)
		{
			temp = templist1->val + templist2->val + temp;
		}
		else if(templist1 && !templist2)
		{
			temp = templist1->val + temp;
		}
		templist1->val = temp%10;
		temp = temp/10;
		if(temp && !templist1->next)
		{
			templist1->next = new struct ListNode(0);
		}
		else if(!temp && templist1->next && !templist2)
		{
			return l1;
		}
		else if(!templist1->next && templist2 && templist2->next)
		{
			templist1->next = templist2->next;
			templist2->next = 0;
		}
		templist1 = templist1->next;
		if(templist2)
			templist2 = templist2->next;
	}
	return l1;
    }
};
