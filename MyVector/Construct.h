#pragma once 


template<class T, class Value>
inline void Construct(T* node, Value value)
{
	new(node)T(value);             //���ö�λnew���ʽ��ʼ��������
}


template<class T>
inline void Destory(T* node)
{
	node->~T();                   //������������
}