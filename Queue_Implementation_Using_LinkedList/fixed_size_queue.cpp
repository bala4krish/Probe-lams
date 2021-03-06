// Fized size queue

#include <iostream>

struct LL
{
      int val;
      LL* next;
};
struct Queue
{
private:
      int size;
      LL* front;
      LL* rear;
public:
      void recurse(int index, LL* root)
      {
            if(index == size)
            {
                  root->next = front;
                  return;
            }
            root->next = new LL();
            recurse(index+1, root->next);
      }
      Queue(int s)
      {
            size = s;
            front = new LL();
            rear = front;
            recurse(0, front);
      }
      ~ Queue()
      {
            if(!isEmpty())
                  delete front;
            delete rear;
      }
      
      bool isEmpty()
      {
            return (front == rear);
      }
      
      bool isFull()
      {
            return rear->next == front;
      }
      
      void Push(int x)
      {
            if(isFull())
            {
                  std::cout << "Queue is full. Please Dequeue" << std::endl;
                  return;
            }
            rear->val = x;
            rear = rear->next;
      }
      
      void Pop()
      {
            if(isEmpty())
            {
                  std::cout << "Queue is empty. Cannot Pop" << std::endl;
                  return;
            }
            front = front->next;
      }
      int Front()
      {
            if(isEmpty())
            {
                  std::cout << "Queue is empty. No element in front" << std::endl;
                  return -1;
            }
            return front->val;
      }
      
};


int main()
{
      Queue fq(5);
      fq.Push(6);
      fq.Push(3);
      fq.Pop();
      fq.Pop();
      fq.Push(5);
      fq.Push(7);
      fq.Push(8);
      fq.Push(9);
      fq.Push(11);
      fq.Push(12);

      std::cout << fq.Front() << std::endl;
      fq.Pop();
      std::cout << fq.Front() << std::endl;
      fq.Pop();
      std::cout << fq.Front() << std::endl;
      fq.Pop();
      std::cout << fq.Front() << std::endl;
      fq.Pop();
      std::cout << fq.Front() << std::endl;
      fq.Pop();
      std::cin.get();
}
