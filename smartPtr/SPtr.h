// SPtr.h: interface for the SPtr class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __SPTR_H__
#define __SPTR_H__

#include <assert.h>
#include <iostream>

template <class T>
class RefCnt
{
private:
	T*	m_pObj;
	int	m_cnt;
public:
	RefCnt(T* pObj) : m_pObj(pObj), m_cnt(0) {}
	~RefCnt() 
	{
		assert(m_cnt==0); 
		delete m_pObj;
	}

	T* operator*()	{return m_pObj;}

	int inc()	{m_cnt++; std::cout<<"increment to:"<<m_cnt<<std::endl; return m_cnt;}
	int dec()	{m_cnt--; std::cout<<"decrement to:"<<m_cnt<<std::endl; return m_cnt;}
};

template <class T>
class SPtr  
{
private:
	RefCnt<T>* m_ptr;

	// hide new/delete operators to disallow allocating a SPtr<T> from the heap.
	void* operator new(size_t) = delete;
	void  operator delete(void*) = delete;

public:
	SPtr() : m_ptr(NULL){}
	SPtr(T* p) {m_ptr = new RefCnt<T>(p); m_ptr->inc();}
	SPtr(const SPtr<T>& sp) { m_ptr = sp.m_ptr; m_ptr->inc();}
	~SPtr() 
	{
		if(m_ptr->dec()==0)
			delete m_ptr;
	}
	void operator=(const SPtr<T>& sp)
	{
		if(this!=&sp)
		{
			//first we need to delete the current object, so we just 
			//decrement its reference count and check if it's zero.
			if(m_ptr && (m_ptr->dec()==0))
				delete m_ptr;
			m_ptr = sp.m_ptr;
			m_ptr->inc();
		}
	}

	//we want to wrap the pointer to class T, so we need to suply the -> operator
	T* operator->() {return *(*m_ptr);}
};

#endif //__SPTR_H__