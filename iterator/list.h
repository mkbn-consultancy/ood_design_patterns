#ifndef __LIST_H__
#define __LIST_H__

#include <iostream>
#include <assert.h>

//----------------------------------
//	class List
//		arbitrary size lists
//		permits insertion and removal
//		only from the front of the list
//-----------------------------------
template <class T>
class List
{
private:
	//----------------------------------
	//	class Element
	//		a single element in the
	//		List class.
	//-----------------------------------
	template <typename T>
	class Element
	{
	public:
		//constructors:
		Element(T value, Element<T>* pNext) : m_value(value), m_pNext(pNext){};
		Element(const Element<T>& source) : m_value(source.m_value), m_pNext(source.m_pNext){};

		//data areas:
		T			m_value;
		Element<T>*	m_pNext;
	};

public:
	//----------------------------------
	//	class Iterator
	//		provides a way to iterate the
	//		list’s elements without
	//		revealing the internal implementation
	//-----------------------------------
	template <typename T>
	class ListIterator
	{
	public:
		ListIterator(Element<T>* pElm = nullptr) : m_pCurrElm(pElm){};

		ListIterator<T>	operator++(int)
		{
			ListIterator<T> itr(*this);
			if(m_pCurrElm)
				m_pCurrElm = m_pCurrElm->m_pNext;
			return itr;
		}

		ListIterator<T>& operator++()
		{
			if(m_pCurrElm)
				m_pCurrElm = m_pCurrElm->m_pNext;
			return *this;
		}

		bool	operator==(const ListIterator<T>& itr) const
		{
			return (m_pCurrElm==itr.m_pCurrElm);
		}

		bool	operator!=(const ListIterator<T>& itr) const
		{
			return (m_pCurrElm!=itr.m_pCurrElm);
		}

		T&	operator*() const {return m_pCurrElm->m_value;}
		T*	operator->() const {return &(m_pCurrElm->m_value);}

	private:
		Element<T>*	m_pCurrElm;
	};

	typedef ListIterator<T> iterator;

public:
	// constructors:
	List() : m_pHead (nullptr){};
	List(const List <T>&) {/*implement deep copy*/ }
	~List() {/*delete all list*/ };

	// operations:
	virtual void	Add(const T& value) {/*add one element to the list by copying it*/ }
	virtual void	RemoveFirst() {/*implement removeing first element from list*/ }
	virtual void	Clear() {/*implement clearing the list*/ }
	T				FirstElement() const { return m_pHead->m_value; }
	bool			IsEmpty() const { return m_pHead == nullptr; }
	List<T>& operator=(const List <T>&) {/*implements deep assignment*/ return *this; }

	//iterators:
	iterator	begin()	{return ListIterator<T>(m_pHead);}
	iterator	end()	{return ListIterator<T>(nullptr);}

protected:
	// data field
	Element <T>*	m_pHead;
};

#endif //__LIST_H__