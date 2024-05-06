#pragma once

template <class T>
class Stack {
private:
	T* __arr{};
	uint16_t __size;
	int __top; // индекс верхнего элемента

	bool __realocateNeeded() {
		return __top + 1 == __size - 1;
	}

	void __realocate() {
		T* new_arr = new T[__size * 2];
		std::copy(__arr, __arr + __size, new_arr);
		delete[] __arr;
		__arr = std::move(new_arr);
		__size *= 2;
	}

public:
	Stack(uint16_t size = 10) : __size(size) {
		__top = -1;
		__arr = new T[__size];
	};
	~Stack() {

		delete[] __arr;
	}

	bool isEmpty() {
		return __top == -1;
	}


	void push(T x) {
		if (__realocateNeeded()) __realocate();

		__arr[++__top] = x;
	}

	T pop() {
		if (isEmpty()) {
			std::cout << "Stack is empty!" << "\n";
			return -1;
		}
		return __arr[__top--];
	}

	uint16_t size() {
		return __top + 1;
	}

	uint16_t capacity() {
		return __size;
	}

	T head() {
		if (isEmpty()) {
			std::cout << "Stack is empty!" << "\n";
			return -1;
		}
		return __arr[__top];
	}

	void showAll() {
		for (size_t i = 0; i != size(); ++i)
		{
			std::cout << __arr[i] << " ";
		}
		std::cout << "\n";
	}

	T& operator[](uint16_t index) {
		if (index >= this->size()) {
			throw std::out_of_range("Index out of bounds");
		}

		return __arr[index];
	}

};

template <class T>
class Numbers : public Stack<T> {
public:
	Numbers(uint16_t size = 10) : Stack<T>(size) {}

	void sort() {
		if (this->isEmpty()) {
			std::cout << "Stack is empty!" << "\n";
		}
		else {
			for (int i = 1; i < this->size(); i++)
			{
				int x = get(i);
				int j = i - 1;
				while (j >= 0 && get(j) > x) {
					set(get(j), j + 1);
					j--;
				}
				set(x, j + 1);
			}
		}
	}

private:
	T get(uint16_t index) {
		if (!this->isEmpty()) {
			int i;
			Stack<T> new_arr;
			for (i = this->size() - 1; i > index; i--) {
				new_arr.push(this->pop());
			}

			T temp = this->head();

			while (!this->isEmpty()) {
				new_arr.push(this->pop());
			}

			while (!new_arr.isEmpty()) {
				this->push(new_arr.pop());
			}

			return temp;

		}
		else {
			std::cout << "Stack is empty!" << "\n";
			return -1;
		}
	}

	void set(T x, uint16_t index) {
		if (!this->isEmpty()) {
			int i;
			Stack<T> new_arr;
			for (i = this->size() - 1; i > index; i--) {
				new_arr.push(this->pop());
			}

			this->pop();
			this->push(x);

			while (!new_arr.isEmpty()) {
				this->push(new_arr.pop());
			}
		}
		else {
			std::cout << "Stack is empty!" << "\n";
		}
	}
};