#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <deque>


//class Base
//{
//public:
//	Base()
//	{
//		cout << "Base()" << endl;
//	}
//
//
//	//��ʹ��dynamic_cast����ת��ʱ���������Ҫ��������������
//	virtual ~Base()
//	{
//		cout << "~Base()" << endl;
//	}
//};
//
//class Dervise:public  Base
//{
//public:
//	Dervise()
//	{
//		cout << "Dervise()" << endl;
//	}
//
//	~Dervise()
//	{
//		cout << "~Dervise()" << endl;
//	}
//};
//
//
////ʹ��dynamic_cast����ת��   RTTI
//
//int main()
//{
//	Base* pb=new Base;
//	Dervise* pd = dynamic_cast<Dervise*>(pb);
//	return 0;
//}


////��������
//
//int Add(int a, int b)
//{
//	return a + b;
//}
//
//float Add(float a, float b)
//{
//	return a + b;
//}
//
//
//int main()
//{
//	float a1 = 1.2;
//	float a2 = 3.4;
//	cout << Add(a1, 3.4) << endl;
//	return 0;
//}


//
//class A
//{
//public:
//	//ȱʡ�����Ĺ��캯��
//	A(int a=10)
//	{
//		_a = a;
//	}
//
//	//�������캯��
//	//��������������ã��ڵ��ÿ������캯��ʱ�������һ����ʱ��������ʱ��������Ҫ���ÿ������캯��
//	//�����ͻ�������޵ݹ�
//	A(const A& a)
//		:_a(a._a)
//	{}
//
//
//	//����ֵ���ó�������ÿ���ʵ������
//	A& operator=(const A& a)
//	{
//		_a = a._a;
//	}
//protected:
//	int _a;
//};
//
//
//int main()
//{
//	int a1 = 10;
//	A a(20);
//	A a2(a);
//	A a3(1);
//	a=a3 = a2;
//	return 0;
//}


//���캯���ĳ�ʼ���б�
//
//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//
//
//class B
//{
//public:
//	B(A& pa, int b, int c, int d)
//		:a(pa)
//		, _c(c)
//		, _d(d)
//	{
//		b = _b;
//	}
//private:
//	A a;
//	int _b;
//	int& _c;
//	const int _d;
//};


//���캯���ĳ�ʼ���б����Ч

//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//		_a = 0;
//	}
//
//	A(const A& pa)
//		:_a(pa._a)
//	{
//		cout << "A(const A& pa)" << endl;
//	}
//
//	A& operator=(const A& pa)
//	{
//		cout << "operator(const A& pa)" << endl;
//		_a = pa._a;
//		return *this;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//
//class B
//{
//public:
//	//���캯����ʼ���б�Ϊʲô��Ч��
//	//������һ��  ���캯��+��ֵ���������->�������캯��
//	B(const A& a)
//		//:_pa(a)
//	{
//	/*	cout << "���캯����ʼ���б��ʼ��" << endl;*/
//		cout << "�����ʼ����ʽ" << endl;
//		_pa = a;       //�����˹��캯��
//	}
//private:
//	A _pa;
//};
//
//int main()
//{
//	A a;
//	B b(a);
//	return 0;
//}


//
//class A
//{
//public:
//	A(int a=10)
//		:_a(a)
//	{}
//
//	void setvalue(int a)
//	{
//		this->_a = a;
//		//this->show();
//	}
//
//	void show() const
//	{
//		cout << "the value is:" << this->_a << endl;
//	}
//private:
//	int _a;
//};
//
//
//int main()
//{
//	A a;           //��const����
//	a.SetValue(20);
//	a.Show();
//
//	const A pa;
//	//pa.SetValue(20);   //const �����ܵ��÷�const �����Ա����
//	pa.Show();           //const������Ե���const��Ա����
//	return 0;
//}

//��Ԫ��
//class Time
//{
//	//��һ�����н���һ��������Ϊ��Ԫ�࣬��ô
//	//���������������Է���������е������Ա
//	friend class Date;
//	int m_minute;
//	int m_hour;
//public:
//	Time(int hour=59, int minute=20)
//		:m_minute(hour)
//		, m_hour(minute)
//	{}
//
//	void Show() const
//	{
//		cout << this->m_hour << ":" << this->m_minute << endl;
//	}
//};
//
//
//class Date
//{
//	//��Ԫ����
//	friend void Display(const Date& date);
//	int m_year;
//	int m_month;
//	int m_day;
//	Time m_t;
//public:
//	Date(int year = 1996,int month = 3, int day = 24)
//		:m_year(year)
//		, m_month(month)
//		, m_day(day)
//		, m_t(22,22)
//	{}
//
//	void Show()
//	{
//		cout << m_year << "-" << m_month << "-" << m_day << endl;
//		cout << m_t.m_hour << ":" << m_t.m_minute << endl;
//	}
//
//	//���������������غ�������Ҫ�з���ֵ
//	friend ostream& operator<<(ostream& os,const Date& date)
//	{
//		os << date.m_year << "-" << date.m_month << "-" << date.m_day << endl;
//		return os;
//	}
//
//};
//
////��Ԫ����������ĳ�Ա����
////��Ԫ��������ͨ��������������ĳ�Ա 
//void Display(const Date& date)
//{
//	cout << date.m_year << "-" << date.m_month << "-" << date.m_day << endl;
//}
//
//int main()
//{
//	Date d;
//	//Display(d);
//	//
//	//cout << (d) << endl;
//	d.Show();
//	return 0;
//}


//��̬��Ա�����;�̬��Ա����
//class Student
//{
//public:
//	Student(char* name="leap", int age=21)
//		:_name(name)
//		, _age(age)
//	{
//		_count++;
//	}
//
//	void Show()
//	{
//		cout << "Num:" << this->_count << endl;
//		cout << "Name:" << _name << endl;
//		cout << "Age:" << _age << endl;
//	}
//
//
//	//��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
//	//���ܹ����ʷǾ�̬��Ա����
//	static void Print()
//	{
//		cout << _count << endl;
//	}
//public:
//	static int _count;
//private:
//	string _name;
//	int _age;
//};
//
//
////1.��ľ�̬��Ա��������Ҫ�����ⶨ�壬�����н���������
////2.��ľ�̬��Ա�������������࣬������ĳһ������
//
//int Student::_count ;
//
//int main()
//{
//	Student s1;
//	//s1.Show();
//	//cout << Student::_count << endl;
//	s1.Print();
//	Student::Print();
//	return 0;
//}

//
//class A
//{
//public:
//	A(int)
//	{}
//
//	A()
//	{};
//
//	void Fun()
//	{
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A a(10);
//	a.Fun();
//	A b();
//	return 0;
//}

//
//int main()
//{
//	vector<int> v1;
//	v1.resize(10);
//	v1[0] = 1;
//	v1.at(11)=1;
//	return 0;
//}


//int main()
//{
//	int a[][2] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
//	int *ptr =(int*) (&a + 1);
//	int *ptr1 = (int*)(a + 1);
//	int *ptr2 = a[0] + 1;         //
//	int *ptr3 = &a[0][0] + 1;     //
//
//	printf("%d\n", sizeof(double));
//	return 0;
//}
//
//class A {
//public:
//	int GetValue() const {
//	    vv = 1;
//		return vv;
//	}
//private:
//	mutable int vv;
//};
//
//int main()
//{
//	A a;
//	a.GetValue();
//	return 0;
//}


//struct A
//{
//	int a;
//	char data[0];
//};
//
//int main()
//{
//	printf("size=%d\n", sizeof(A));
//	A* a=new A;
//	a->data
//	return 0;
//}


//int main()
//{
//	//string str="abcdef";
//	//str[5] = 'c';
//	return 0;
//}



//����
//#include <iostream>
//using namespace std;
//struct Foo {
//	Foo() {}
//	Foo(int) {}
//	void fun() {}
//};
//int main(void) {
//	Foo a(10); //���1  
//	a.fun(); //���2  
//	Foo b(); //���3    ����������Ϊ���3ʱһ����������������b����û�ж���
//	b.fun(); //���4  
//	return 0;
//	16.
//}

//int main()
//{
//	deque<int> q;
//	q.push_back(1);
//	cout << q[0] << endl;
//	return 0;
//}


//int main()
//{
//	int* p1 = (int*)malloc(sizeof(int)* 10);
//	for (int i = 0; i < 10; i++)
//	{
//		p1[i] = i;
//	}
//	int* p2 = (int*)realloc(p1, sizeof(int)* 20);
//	for (int i = 10; i < 20; i++)
//	{
//		p2[i] = i;
//	}
//
//
//	return 0;
//}

//
//struct A
//{
//	int m;
//};
//
//struct B
//{
//	~B()
//	{}
//
//	int m;
//};
//
//class C
//{
//	//C()
//	//:m()
//	//{}
//
//	//~C()
//	//{}
//protected:
//	int m;
//};
//
//int main()
//{
//	A* pa1 = new A;       //POD type
//	A* pa2 = new A();
//
//	B* pb1 = new B;       //non-pod
//	B* pb2 = new B();
//
//	C* pc1 = new C;      //non-pod
//	C* pc2 = new C();
//	return 0;
//}



//��λnew���ʽ


//class Arr
//{
//public:
//	Arr(int size = 10)
//		:_size(10)
//		, _pArr(NULL)
//	{
//		cout << "Construct Function" << endl;
//		if (_size > 0)
//		{
//			_pArr = new int[_size]();
//		}
//	}
//private:
//	int _size;
//	int* _pArr;
//};
//
//int main()
//{
//	Arr* pArr = (Arr*)malloc(sizeof(Arr));
//	new(pArr) Arr(20);             //���ö�λnew���ʽ��ʼ������
//	return 0;
//}