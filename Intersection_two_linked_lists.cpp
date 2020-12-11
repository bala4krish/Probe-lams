// Problem
// Find the intersecting node of two linked lists.

// Example : list1 = [1 -> 3 -> 7 -> 11 -> 4]
//           list2 = [5 -> 8 -> 7 -> 11 -> 4]
//          Output = Node with value 7. 


// Algorithm:
//          1. Traverse through the lists - find the length and tail of each.
//          2. If the tails are different, return null since this means no intersection
//          3. Now the move the pointer of the bigger list to the right times the difference of lengths.
//          4. You are now starting evenly. Iterrate until the two nodes meet.

struct ListNode 
{
        int val;
        ListNode *next;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
        if(!headA || !headB)
            return nullptr;
        ListNode *tailA = headA;
        ListNode *tailB = headB;
        int lenA = 1;
        int lenB = 1;
        while(tailA->next)
        {
            lenA++;
            tailA = tailA->next;
        }
        while(tailB->next)
        {
            lenB++;
            tailB = tailB->next;
        }
        if(tailA != tailB)
            return nullptr;
        
        int diff = std::abs(lenA - lenB);
        if(lenA > lenB)
            while(diff--)
                headA = headA->next;
        else
            while(diff--)
                headB = headB->next;
        
        while(headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
}
