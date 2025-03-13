#pragma once
#include <stdexcept>

template <typename T>
class Stack
{
	struct Node
	{
		T data;
		Node* next;

		Node(T value) : data(value), next(nullptr)
		{
		}
	};

	Node* head;
	int size;

public:
	Stack() : head(nullptr), size(0)
	{
	}

	Stack(const Stack& other) : head(nullptr), size(0)
	{
		Node* temp = other.head;
		while (temp)
		{
			push(temp->data);
			temp = temp->next;
		}
	}

	void push(T value)
	{
		Node* newNode = new Node(value);
		newNode->next = head;
		head = newNode;
		size++;
	}

	T pop()
	{
		if (head == nullptr)
		{
			return 0;
		}

		Node* temp = head;
		T value = head->data;
		head = head->next;
		delete temp;
		size--;
		return value;
	}

	T peek()
	{
		if (head) return head->data;
		// throw std::runtime_error("Stack is empty.");
		return 0;
	}

	// if empty return true, else return false
	bool isEmpty()
	{
		return head == nullptr;
	}

	int length() const
	{
		return size;
	}
};
