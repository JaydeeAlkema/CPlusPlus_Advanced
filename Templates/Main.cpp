#include <iostream>
#include <chrono>
#include <vector>


#pragma region Sorting
template<class T>
void swap(T& lhs, T& rhs)
{
	T temp = lhs;
	lhs = rhs;
	rhs = temp;
}

template<class T>
void display(T arr[], int size)
{
	std::cout << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << "\t " << arr[i];
	}
	std::cout << std::endl;
}

template<class T>
void bubbleSort(T arr[], int size)
{
	auto start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
			}
		}
	}

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Sorting took: " << duration.count() << "ms" << std::endl;
}
#pragma endregion

#pragma region Queue
//template<class T>
//T* put(T arr[], T element)
//{
//	int n = sizeof(arr) / sizeof(arr[0]);
//	std::vector<T> copyArr(arr, arr + n + 1);
//
//	copyArr.push_back(element);
//
//	T output[sizeof(copyArr)]{};
//	std::copy(copyArr.begin(), copyArr.end(), output);
//
//	return output;
//}

template<typename T> class Queue
{
private:
	T* arr;
	int capacity;
	int front;
	int rear;
	int count;

public:
	Queue(int size = SIZE);

	void pull();		// Remove last element from the Queue.
	void put(T t);		// Add element to the end of the Queue.
	T get();			// Get the front element of the Queue.
	int size();			// Returns the size of the Queue.
	bool isEmpty();		// Checks if Queue is empty.
	bool isFull();		// Checks if Queue is full.
};

template<typename T>
Queue<T>::Queue(int size)
{
	arr = new T[size];
	capacity = size;
	front = 0;
	rear = -1;
	count = 0;
}

template<typename T>
void Queue<T>::pull()
{
	if (isEmpty())
	{
		std::cout << "Queue is EMPTY. Program Terminated" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "Removing " << arr[front] << std::endl;

	front = (front + 1) % capacity;
	count--;
}

template<typename T>
void Queue<T>::put(T t)
{
	if (isFull())
	{
		std::cout << "Queue is FULL. Program Terminated" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "Inserting " << t << std::endl;

	rear = (rear + 1) % capacity;
	arr[rear] = t;
	count++;
}

template<typename T>
T Queue<T>::get()
{
	if (isEmpty())
	{
		std::cout << "Queue is EMPTY. Program Terminated" << std::endl;
		exit(EXIT_FAILURE);
	}

	return arr[front];
}

template<typename T>
int Queue<T>::size()
{
	return count;
}

template<typename T>
bool Queue<T>::isEmpty()
{
	return (size() == 0);
}

template<typename T>
bool Queue<T>::isFull()
{
	return (size() == capacity);
}
#pragma endregion





int main()
{
#pragma region Sorting
	std::cout << "\n =================> Int Array: " << std::endl;

	float floatArr[10] = { 1.42353525, 1.65363343465, 1.22353252352, 1.2527773, 1.67855, 2.01, 1.67474573243, 1.25342652, 1.36346636163, 1.42562343631 };

	display(floatArr, 10);

	bubbleSort(floatArr, 10);

	display(floatArr, 10);

	std::cout << "\n =================> String Array: " << std::endl;

	std::string stringArr[26] = { "a", "e", "l", "d", "k", "m", "f", "b", "j", "n", "p", "o", "v", "q", "c", "g", "s", "z", "r", "h", "x", "i", "t", "y", "w", "u" };

	display(stringArr, 26);

	bubbleSort(stringArr, 26);

	display(stringArr, 26);
#pragma endregion
#pragma region Queue
	std::cout << std::endl;
	std::cout << "=================> Queue: " << std::endl;

	Queue<int> intQ(5);

	intQ.put(41);
	intQ.put(85);
	intQ.put(41);
	intQ.put(55);
	intQ.put(76);

	std::cout << "Front element is: " << intQ.get() << std::endl;

	intQ.pull();

	intQ.put(512412);

	std::cout << "Queue size is: " << intQ.size() << std::endl;

	intQ.pull();
	intQ.pull();
	intQ.pull();

	if (intQ.isEmpty())
	{
		std::cout << "Queue is empty!" << std::endl;
	}
	else
	{
		std::cout << "Queue is NOT empty!" << std::endl;
	}

#pragma endregion

	return 0;
}
