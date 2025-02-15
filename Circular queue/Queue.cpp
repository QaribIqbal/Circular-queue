#include<iostream>
using namespace std;
class queue {
private:
	int* arr;
	int size;
	int count;
	int front;
	int rear;
public:
	queue() :arr(nullptr), size(0), count(0), front(0), rear(0) {};
	queue(int s) :arr(new int[s]), size(s), count(0), front(0), rear(0) {};
	bool enqueue(int val)
	{
		if (count == size)
		{
			cout << "\nQueue is full!\n";
			return 0;
		}
		else {
			arr[rear] = val;
			rear = (rear + 1) % size;
			count++;
			return 1;
		}
	}
	bool dequeue(int& val)
	{
		if (count == 0)
		{
			cout << "\nQueue is empty\n";
			return 0;
		}
		else {
			val = arr[front];
			arr[front] = -1;
			front = (front + 1) % size;
			count--;
			return 1;
		}
	}
	bool display()
	{
		int itr = 0;
		if (count != 0) {
			itr = front;
			do {
				if (arr[itr] != -1)
				{	
				cout << arr[itr] << " ";
				}
				itr = (itr + 1) % size;
			} while (itr != rear);
			return 1;
		}
		else {
			cout << "\nQueue is empty!\n";
		}
	}
	bool remove(int val)
	{
		int itr = 0;
		if (count != 0) {
			itr = front;
			do {
				if (arr[itr] == -1)
				{
					continue;
				}
				if (arr[itr] == val)
				{
					cout << " \nValue removed : " << arr[itr] << endl;
					arr[itr] = -1;
					count--;
					break;
				}
				itr = (itr + 1) % size;
			} while (itr != rear);
			return 1;
		}
		else {
			cout << "\nQueue is empty!\n";
		}
	}
	int getCount()
	{
		return count;
	}
	int getSize()
	{
		return size;
	}
	bool isFull() 
	{
		if (count == size)
		{
			return 1;
		}
		else {
			return 0;
		}
	}
};
int main()
{
	queue arr(5);
	arr.enqueue(1);
	arr.enqueue(2);
	arr.enqueue(3);
	arr.enqueue(4);
	arr.enqueue(5);
	arr.enqueue(6);
	arr.display();
	int val = 0;
	arr.dequeue(val);
	cout << "\nValue dequeued : " << val << " \n";

	arr.display();
	arr.remove(4);
	arr.display();
	cout << "\nTotal elements in the queue : " << arr.getCount() << endl;
	cout << "\nSize of the queue : " << arr.getSize() << endl;
	if (arr.isFull())
	{
		cout << "\nQueue is full!\n";
	}
	else {
		cout << "\nQueue is not full!\n";
	}
	return 0;
}