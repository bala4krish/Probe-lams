Queue implementation using Linked List for a fixed size and free size.

Algorithm :
  1. Construct two same pointers to the struct LinkedList. 
  2. For fized size - recurse and create link the list for the mentioned size conneting the last node back to the two pointers.
  3. Push - Use one pointer to insert the value and move this pointer pointer to point to it's own next.
  4. Pop - Move the other pointer to move to it's next.
  5. isEmpty - true if two pointers are same 
  6. isFull - true if the next of the pointer(used for push) is the other pointer.
  7. Front - value of the pointer used for Pop
  8. Back - value of the pointer used for Push
