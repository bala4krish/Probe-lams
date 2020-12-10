// Given two Linked Lists with integers in reverse order, add them and return the sum as a linked list.

// Example - 543 + 657 = 1200
//          list1 = 3 -> 4 -> 5
//          list2 = 7 -> 5 -> 6
//            ans = 0 -> 0 -> 2 -> 1

//Algorithm:
//          1. Use one pointer to update the sum. I used L1.
//          2. Insert new node if L1->next is null, until the sum is zero && L1->next is null && L2 is null.
//          3. Store the previous of current L1 before updating it to the next.
//          4. Delete the last node of L1 using prev.

//Code
struct ListNode 
{
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
        int carry = 0;
        ListNode* ans = l1;
        ListNode* prev;
        while(l1 || l2 )
        {
            int temp = 0;
            if(l1)
                temp += l1->val;
            if(l2)
                temp += l2->val;
            temp += carry;
            if(temp == 0 && !l1->next && !l2)
                break;
            l1->val = temp % 10;
            carry = temp / 10;
            prev = l1;
            if(!l1->next)
                l1->next = new ListNode();
            l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        prev->next = nullptr;
        return ans;
}
    
