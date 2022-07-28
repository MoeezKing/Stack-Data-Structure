#include <iostream>
using namespace std;
class Node
{
	int data;
	Node* next;
public:
	void setData(int data)
	{
		this->data = data;
	}
	void setNext(Node* next)
	{
		this->next = next;
	}
	int getData()
	{
		return data;
	}
	Node* getNext()
	{
		return next;
	}
	Node(int data = 0, Node* next = NULL)
	{
		setData(data);
		setNext(next);
	}

};
class LinkedList
{
	Node* head;
public:
	void setHead(Node* head)
	{
		this->head = head;
	}
	Node* getHead()
	{
		return head;
	}
	LinkedList(Node* head = NULL)
	{
		setHead(head);
	}
	bool isEmpty()
	{
		return (head == NULL) ? true : false;
	}
	void insertAtBeginning(int data)
	{
		if (isEmpty())
		{
			Node* t = new Node(data);
			head = t;
		}
		else
		{
			Node* t = new Node(data);
			t->setNext(head);
			head = t;
		}
	}
	
	bool removeFromBeginning()
	{
		if (isEmpty())
		{
			return false;
		}
		else
		{
			Node* t = head->getNext();
			delete head;
			head = t;
			return true;
		}
	}
	int getLenght()
	{
		int lenght = 0;
		Node* temp = head;
		while (temp != NULL)
		{
			lenght++;
			temp = temp->getNext();
		}
		return lenght;
	}

	int getFirstElement()
	{
		return head->getData();
	}

	void print()
	{
		cout << endl;
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->getData() << endl;
			temp = temp->getNext();
		}
	}

};
class Stack
{
	LinkedList l1;
	int size;
public:
	void setSize(int size)
	{
		this->size = size;
	}
	int getSize()
	{
		return size;
	}
	Stack(int size = 15)
	{
		setSize(size);
	}
	bool push(int val)
	{
		if (!(isFull()))
		{
			l1.insertAtBeginning(val);
			return true;
		}
		else
		{
			cout << "\nStack is Full";
			return false;
		}
		}
	int pop()
	{
		if (!(isEmpty()))
		{
			int data = l1.getFirstElement();
			l1.removeFromBeginning();
			return data;
		}
		else
		{
			cout << "\nStack is Empty";
			return NULL;
		}
	}
	bool isEmpty()
	{
		return (l1.isEmpty()) ? true : false;
	}
	bool isFull()
	{
		int lenght = l1.getLenght();
		return (lenght == size) ? true : false;
	}
	int getTop()
	{
		if (!(l1.isEmpty()))
		{
			return l1.getFirstElement();
		}
		else
		{
			cout << "\n Stack is Empty .";
			return NULL;
		}
	}
	void printStack()
	{
		l1.print();
	}
};
int main()
{
	Stack s1(99);
	
	for(int i=0;i<15;i++)
	s1.push(i+1);

	if (s1.isFull())
		cout << "\nStack is full.";
	else
		cout << "\nStack is not Full yet.";

	cout<<"\nSize of stack is "<<s1.getSize();

	s1.push(1);

	cout << "\nTop most value in stack is " << s1.getTop();
	s1.printStack();

	int sum = 0;
	for (int i = 0; i < 17; i++)
		sum = sum + s1.pop();

	cout << "\nsum of all elements in stack is " << sum;
	return 0;
}
