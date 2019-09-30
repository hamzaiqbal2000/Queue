#include <iostream>
using namespace std;

template <class T>
class Queue {
private:
	int front;
	int rear;
	int size;
	T* s;
public:
	Queue() {
		rear = front = -1;
		size = 10;
		s = new T[size];
	}
	Queue(int size) {
		this->size = size;
		rear = front = -1;
		s = new T[size];
	}
	void enqueue(T data);
	T dequeue();
	int isFull();
	int isEmpty();
	void Display();
};

template<class T>
void Queue<T>::enqueue(T data) {
	if (isFull()) {
		cout << "Queue is Full";
	}
	else {
		s[++rear] = data;
	}
}

template<class T>
T Queue<T>::dequeue() {
	T x = -1;
	if (isEmpty()) {
		cout << "Queue is Empty";
	}
	else {
		x = s[front++];
	}
	return x;
}

template<class T>
int Queue<T>::isEmpty() {
	if (front == rear) {
		return 1;
	}
	else return 0;
}

template<class T>
int Queue<T>::isFull() {
	if (rear == size - 1) {
		return 1;
	}
	else return 0;
}

template<class T>
void Queue<T>::Display() {
	for (int i = front+1; i <= rear; i++) {
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

}