#include <iostream>
#include <string>
using namespace std;

//����������� ������
//���������� � ������ � ����� � �� ���������� ������
//�������� � ������ � ����� � �� ���������� ������
// ����������� ������� ��� ������ �������� Node
// ��� ������ ����� ����� push_front(T data) pop_back � insert(T value, int index) removeAt(int index)
//

template<typename T>
class List
{
public:
	List();
	~List();
	void pop_front();//������� ������� �������
	void push_back(T data);//�������� � ����� ������
	void clear();
	int GetSize() { return Size; }
	T& operator[](const int index);

	void push_front(T data);//��������� � ������ ������
	void insert(T value, int index);//�� ������ ������� ������ � ������ ���� ��������� ���� ����� ������
	void removeAt(int index);//������� ������� �� �������
	void pop_back();//������� ������� � ����� ������



private:


	//����� ��������
	template<typename T>
	class Node//����������� ��� ����
	{
	public:
		Node* pNext;//��������� �� ���� �������
		T data;
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;//���-�� ��������� � ����� ������
	Node<T>* head;//�������� � ������ ��������� ����� �������, ������� �������� ���� ����� �������� � ����
};

int main()
{
	setlocale(LC_ALL, "ru");
	List<int> lst;
	lst.push_back(55);
	lst.push_back(11);
	lst.push_back(2);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << endl << "��������� � ������: " << lst.GetSize() << endl << "�������� ����� pop_front" << endl << endl;
	lst.pop_front();
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << endl << "��������� � ������: " << lst.GetSize() << endl;
	cout << endl << "�������� ����� clear" << endl;
	lst.clear();
	cout << endl << "��������� � ������: " << lst.GetSize() << endl;

	lst.push_front(5);//������� ����� ���������� �������
	lst.push_front(11);//������� ����� ���������� �������
	lst.push_front(33);//������� ����� ���������� �������

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}
	cout << endl << "insert " << endl << endl;
	lst.insert(99, 1);//������ �������� - ��� data, ������ �������� - ��� ������, �� ����� ����� ��� ��������
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}
	cout << endl << "RemoveAt " << endl << endl;
	lst.removeAt(2);//��������� ������� � �������� 2
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}
	cout << endl << "pop_back " << endl << endl;
	lst.pop_back();
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}


	return 0;
}

template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::pop_front()
{
	//������ ������� ���� ������� ������
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;//��������� �� ������� ������� � ������� ������ ���������
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}

}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T value, int index)
{
	if (index == 0)
	{
		push_front(value);
	}
	else
	{
		Node<T>* previous = this->head;//previous - ����������� ����������
		for (int i = 0; i < index - 1; i++)//�� ������� ������� � ���������� ��������, ��� �� ��������� ����� ���� ��� ��� ����� �������
		{
			previous = previous->pNext;
		}
		/*Node<T>* newNode = new Node<T>(value, previous->pNext);
		previous->pNext = newNode;*/
		previous->pNext = new Node<T>(value, previous->pNext);

		Size++;
	}


}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		Size--;
	}
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}
