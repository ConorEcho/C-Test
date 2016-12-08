#include <iostream>
using namespace std;
#include <string>
#include <cassert>



//�ַ�����������ת��
void ReverseString(char* str, int begin,int end)
{
	while (begin < end)
	{
		swap(str[end--], str[begin++]);
	}
}
void LeftRomateString(char* str, int n, int m)    //nλ�ַ����ĳ���   mΪ�ַ����ƶ��ַ��ĸ���
{
	assert(str);
	m %= n;
	ReverseString(str,0, m - 1);
	ReverseString(str, m , n-1);
	ReverseString(str, 0, n-1);
}

//����ķ�ת
struct  ListNode
{
	ListNode* _Next;
	int _data;

    explicit ListNode(const int& data)
		:_data(data)
		, _Next(NULL)
	{}
};

typedef ListNode Node;
class List
{
public:
	List()
		:_head(NULL)
		, _size(0)
	{}

	size_t size()
	{
		return _size;
	}
	Node* ReturnHead()
	{
		return _head;
	}
	void PrintList()
	{
		Node* cur = _head;
		while (cur)
		{
			cout << cur->_data << " ";
			cur = cur->_Next;
		}
		cout << endl;
	}
	//�����β��
	void PushBack(const int& x)
	{
		if (_head == NULL)
		{
			_head = new Node(x);
			_size++;
			return;
		}

		Node* NewNode = new Node(x);
		Node* cur = _head;
		while (cur->_Next)        //�ҵ������β���ڵ�
		{
			cur = cur->_Next;
		}
		cur->_Next = NewNode;
		_size++;
	}
protected:
	Node* _head;
	size_t _size;
};

void ReverseSubList(Node* head,int begin,int end)    
{
	Node* cur = head;
	Node* Rnode = cur;
	Node* tail = head;
	Node* prev = NULL;
	for (int i = begin; i < end; i++)
	{
		prev = tail;
		tail = tail->_Next;
	}
	for (int i = begin; i < end; i++)
	{
		cur = cur->_Next;
		Rnode->_Next = tail->_Next;
		tail = Rnode;
		Rnode = cur;
	}
}
void RomateList(Node* head, int n, int m)    //nΪ����ĳ��ȣ�  Ҫ���Ƶĸ���
{
	assert(head);
	m %= n;
	ReverseSubList(head, 0, m - 1);
	ReverseSubList(head, m, n - 1);
	ReverseSubList(head, 0, n - 1);
}


void TestString()
{
	string s("abcdef");
	cout << s << endl;
	LeftRomateString((char*)s.c_str(), s.size(), 2);
	cout << s << endl;
}

void TestList()
{
	List list;
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);
	list.PushBack(5);
	list.PushBack(6);
	list.PrintList();
	RomateList(list.ReturnHead(), list.size(), 2);
	list.PrintList();
}
int main()
{
	TestList();
	return 0;
}