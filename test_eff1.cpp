#include <iostream>
using namespace std;
#include <vector>
#include <memory> 
#include <string>

//��Ҫ�������������׳��쳣
//class DBManager
//{
//public:
//	DBManager(const size_t& size=10)
//	{
//		_V1.resize(size);
//		for (int i = 0; i < size; i++)
//		{
//			_V1[i] = i;
//		}
//	}
//
//	void CloseDB()
//	{
//		throw int();
//	}
//
//	~DBManager()
//	{
//		try{
//			CloseDB();
//		}
//		catch (int)
//		{
//			cout << "�������������" << endl;
//			abort();         //������������ֹ�쳣�����������д�����ȥ
//		}
//	}
//protected:
//	vector<int> _V1;
//};



// <<Effective C++>>  ��Ҫ�ڹ��캯���е����麯��
//class Transation
//{
//public:
//	Transation()
//		:_Sum(0)
//	{
//		LogTransation();
//	}
//
//	virtual void LogTransation()
//	{
//		cout << "Transation is write" << endl;
//	}
//protected:
//	int _Sum;
//};
//class BuyTransation :public Transation
//{
//public:
//	virtual void LogTransation()
//	{
//		cout << "BuyTransation is write" << endl;
//	}
//};
//class SellTransation :public Transation
//{
//public:
//	virtual void LogTransation()
//	{
//		cout << "SellTransation is write" << endl;
//	} 
//};
//
//int main()
//{
//	BuyTransation by;
//	return 0;
//}


//class A
//{
//public:
//	 A(const int& a)
//		:_a(a)
//	{
//		cout << "A()" << endl;
//	}
//
//	int Show()
//	{
//		cout << "a::" << _a << endl;
//		return _a;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//
//protected:
//	int _a;
//};
//
//int Geta(const auto_ptr<A> pa)           //����д��00000
//{
//	return pa->Show();
//}
//
//void TestSharedPtr()
//{
//	auto_ptr<A> pa(new A(10));
//	//auto_ptr<A> pa=new A(10);  ����д��
//	//explicit auto_ptr(_Ty *_Ptr = 0) _THROW0()
//	//	: _Myptr(_Ptr)
//	//{	// construct from object pointer
//	//}
//	cout<<Geta(pa)<<endl;
//	pa->Show();
//}
typedef  std::string AddressLine[4];
int main()
{
	///*TestSharedPtr*/();
	string* pa = new AddressLine;
	pa[0] = "hehe";
	pa[1] = "lzh";
	for (size_t i = 0; i < 2; i++)
		cout << pa[i] << " ";
	delete[] pa;
	return 0;
}