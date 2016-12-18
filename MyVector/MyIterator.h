#pragma once 
#include <iostream>
using namespace std;


struct InputIteratorTag {};												//ֻ�����͵ĵ�����
struct OutputIteratorTag {};											//ֻд���͵ĵ�����
struct ForwardIteratorTag : public InputIteratorTag {};					//���Խ��ж�д�����ĵ�����
struct BidirectionalIteratorTag : public ForwardIteratorTag {};			//��˫���ƶ��ĵ�����
struct RandomAccessIteratorTag : public BidirectionalIteratorTag {};    //��������ָ���������������ĵ�����


template <class Category, class T, class Distance = size_t,
class Pointer = T*, class Reference = T&>
struct Iterator
{
	typedef Category			IteratorCategory;
	typedef T					ValueType;
	typedef Distance			DifferenceType;
	typedef T*					Pointer;
	typedef T&					Reference;
};

//������ȡ
template <class Iterator>
struct IteratorTraits
{
	typedef typename Iterator::IteratorCategory IteratorCategory;
	typedef typename Iterator::ValueType        ValueType;
	typedef typename Iterator::DifferenceType   DifferenceType;
	typedef typename Iterator::Pointer           Pointer;
	typedef typename Iterator::Reference         Reference;
};

//ԭ��ָ���������ȡ
template <class T>
struct IteratorTraits<T*>
{
	typedef RandomAccessIteratorTag	   IteratorCategory;
	typedef T                          ValueType;
	typedef ptrdiff_t                  DifferenceType;
	typedef T*                         Pointer;
	typedef T&                         Reference;
};


//���const T*��������ȡ
template <class T>
struct IteratorTraits<const T*>
{
	typedef RandomAccessIteratorTag	   IteratorCategory;
	typedef T                          ValueType;
	typedef ptrdiff_t                  DifferenceType;
	typedef T*                         Pointer;
	typedef T&                         Reference;
};

//��ͨ���͵�������������֮�����ĺ���
template <class InputIterator>
inline size_t __Distance(InputIterator first, InputIterator last, InputIteratorTag) {
	size_t n = 0;
	while (first != last) {
		++first; ++n;
	}
	return n;
}


//RandomAccessIteratorTag���͵�������������֮�����ĺ���
template <class RandomAccessIterator>
inline size_t __Distance(RandomAccessIterator first, RandomAccessIterator last, RandomAccessIteratorTag)
{
	size_t n = 0;
	n += last - first;
	return n;
}


//������������֮��ľ���ĺ���
template <class InputIterator>
inline size_t Distance(InputIterator first, InputIterator last) {
	return __Distance(first, last, IteratorTraits<InputIterator>::IteratorCategory());
}

