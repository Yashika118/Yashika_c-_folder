// made by yashika 2K21/EP/118
#include <iostream>
using namespace std;
class Queue
{
private:
    int front;
    int rear;
    int maxSize;
    int *array;

public:
    Queue(int size)
    {
        maxSize = size;
        array = new int[maxSize];
        front = -1;
        rear = -1;
    }
    ~Queue()
    {
        delete[] array;
    }
    bool isEmpty()
    {
        return front == -1;
    }
    bool isFull()
    {
        return (rear + 1) % maxSize == front;
    }
    void enqueue(int item)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue " << item << endl;
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % maxSize;
        }
        array[rear] = item;
        cout << item << " enqueued to the queue." << endl;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        cout << array[front] << " dequeued from the queue." << endl;
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % maxSize;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
        }
        else
        {
            int i = front;
            while (true)
            {
                cout << array[i] << " ";
                if (i == rear)
                {
                    break;
                }
                i = (i + 1) % maxSize;
            }
            cout << endl;
        }
    }
};
int main()
{
    int size, choice, item;
    cout << "Enter the maximum size of the queue: ";
    cin >> size;
    Queue queue(size);
    do
    {
        cout << "\nQueue Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display Queue\n";
        cout << "4. Check if Queue is Empty\n";
        cout << "5. Check if Queue is Full\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter an item to enqueue: ";
            cin >> item;
            queue.enqueue(item);
            break;
        case 2:
            queue.dequeue();
            break;
        case 3:
            cout << "Queue Contents: ";
            queue.display();
            break;
        case 4:
            if (queue.isEmpty())
            {
                cout << "Queue is empty." << endl;
            }
            else
            {
                cout << "Queue is not empty." << endl;
            }
            break;
        case 5:
            if (queue.isFull())
            {
                cout << "Queue is full." << endl;
            }
            else
            {
                cout << "Queue is not full." << endl;
            }
            break;
        case 6:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
    return 0;
}

// //Made by Yashika 2K21/EP/118
// #include <iostream>
// using namespace std;
// class Node
// {
// public:
//  int data;
//  Node *next;
//  Node(int d)
//  {
//  data = d;
//  next = NULL;
//  }
// };
// class Queue
// {
//  Node *head;
//  int len;
// public:
//  Queue()
//  {
//  head = NULL;
//  len = 0;
//  }
//  // push or inster at front
//  void push(int d)
//  {
//  Node *n = new Node(d);
//  if (head == NULL)
//  {
//  head = n;
//  len++;
//  return;
//  }
//  Node *temp = head;
//  while (temp->next != NULL)
//  {
//  temp = temp->next;
//  }
//  temp->next = n;
//  len++;
//  }
//  // pop delete at front
//  void pop()
//  {
//  if (head == NULL)
//  {
//  return;
//  }
//  else if (head->next == NULL)
//  {
//  delete head;
//  head = NULL;
//  len--;
//  }
//  else
//  {
//  Node *temp = head;
//  head = head->next;
//  delete temp;
//  len--;
//  }
//  }
//  // top
//  int top()
//  {
//  return head->data;
//  }
//  // size
//  int size()
//  {
//  return len;
//  }
//  // if empty or not
//  bool empty()
//  {
//  if (len == 0)
//  {
//  return true;
//  }
//  else
//  {
//  return false;
//  }
//  }
// };
// int main()
// {
//  Queue q;
//  q.push(34);
//  q.push(3234);
//  q.push(645);
//  q.push(419);
//  q.push(92872);
//  q.pop();
//  q.pop();
//  while (!q.empty())
//  {
//  cout << q.top() << " ";
//  q.pop();
//  }
// }