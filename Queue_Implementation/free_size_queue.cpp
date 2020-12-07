
// Free size Queue

#include <iostream>

struct LL
{
      int val;
      LL* next;
      LL(): val(0), next(nullptr) {}
};

struct Queue
{
private:
      LL* front;
      LL* rear;
      int size;
public:
      Queue(int s=0) : size(s)
      {
            front = new LL();
            rear = front;
      }
      void Push(int x)
      {
            rear->val = x;
            rear->next = new LL();
            rear = rear->next;
            size++;
      }
      void Pop()
      {
            if(isEmpty())
            {
                  std::cout << "The queue is empty, cannot Pop" << std::endl;
                  return;
            }
            front = front->next;
            size--;
      }
      bool isEmpty()
      {
            return front == rear;
      }
      int Front()
      {
            if(isEmpty())
            {
                  std::cout << "Queue is empty" << std::endl;
                  return -1;
            }
            return front->val;
      }
      int Back()
      {
            if(isEmpty())
            {
                  std::cout << "Queue is empty" << std::endl;
                  return -1;
            }
            return rear->val;
      }
      int Size()
      {
            return size;
      }
      ~Queue()
      {
            if(!isEmpty())
                  delete front;
            delete rear;
      }
      
};

int main() {
      Queue myQ;
      myQ.Push(1);
      myQ.Push(5);
      myQ.Push(7);
      std::cout << myQ.Front() << "\n";
      myQ.Pop();
      std::cout << (myQ.isEmpty() ? "The Queue is empty \n" : "The Queue is not empty \n");
      std::cout << "Queue size is : " << myQ.Size() << "\n";
      myQ.Push(9);
      std::cout << myQ.Front() << "\n";
      myQ.Pop();
      std::cout << myQ.Front() << "\n";
      myQ.Pop();
      std::cout << myQ.Front() << "\n";
      myQ.Pop();
      std::cout << myQ.Front() << "\n";
      return 0;
}
