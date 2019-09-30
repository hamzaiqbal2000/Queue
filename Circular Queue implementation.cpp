#include <iostream>
using namespace std;

template <class T>
class Queue {
private:
	int size;
	int front;
	int rear;
	T* s;
public:
	Queue() {
		size = 10;
		front = rear = -1;
		s = new T[size];
	}
	Queue(int size) {
		this->size = size;
		front = rear = -1;
		s = new T[this->size];
	}

	void enqueue(T data);
	T dequeue();
	void Display();
};

template<class T>
void Queue<T>::enqueue(T data) {
	if ((rear + 1) % size == front) {
		cout << "Queue is Full";
	}
	else {
		rear = (rear + 1) % size;
		s[rear] = data;
	}
}

template<class T>
T Queue<T>::dequeue() {
	T x = -1;
	if (front == rear) {
		cout << "Queue is Empty";
	}
	else {
		front = (front + 1) % size;
		x = s[front];
	}
	return x;
}

template<class T>
void Queue<T>::Display() {
	for (int i = front + 1; i <= rear; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

int main() {
	Queue<char> a[5];
	a->enqueue('a');
	a->enqueue('b');
	a->enqueue('c');
	a->enqueue('d');
	a->enqueue('e');
	a->Display();

	a->dequeue();
	//a->dequeue();
	a->enqueue('f');

	a->Display();

}