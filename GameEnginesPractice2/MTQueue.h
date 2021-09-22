#pragma once
template <class T>
class MTQueue
{
public:
	MTQueue();
	MTQueue(size_t nSize, size_t nCapacity);
	MTQueue(const MTQueue <T>& mtQueue);
	~MTQueue();

	// Increase size of array and return ptr to the beging
	T* Resize(size_t nNewSize);
	void Clear();
	size_t Size();
	size_t Capacity();

	T* operator * ();
	MTQueue <T>& operator = (const MTQueue <T>& other);
private:
	T* allocate();
	T* deallocate();

private:
	T* m_pData;
	size_t m_nSize;
	size_t m_nCapacity;
};

template <class T>
MTQueue <T>::MTQueue()
	: m_pData(nullptr)
	, m_nSize(0)
	, m_nCapacity(0)
{}

template <class T>
MTQueue <T>::MTQueue(size_t nSize, size_t nCapacity)
	: m_nSize(nSize)
	, m_nCapacity(nCapacity)
{
	m_pData = allocate();
}

template <class T>
MTQueue <T>::MTQueue(const MTQueue <T>& mtQueue)
{
	m_nSize = mtQueue.m_nSize;
	m_nCapacity = mtQueue.m_nCapacity;
	m_pData = allocate();
	if (mtQueue.m_pData)
		memcpy(m_pData, mtQueue.m_pData, m_nCapacity);
}

template <class T>
MTQueue <T>::~MTQueue()
{
	deallocate();
}

template <class T>
T* MTQueue <T>::Resize(size_t nSize)
{
	m_nSize = m_nCapacity;
	m_nCapacity = nSize;
	T* newData = allocate();
	if (m_pData)
		memcpy(newData, m_pData, m_nCapacity);
	m_pData = deallocate();
	m_pData = newData;
	return m_pData + m_nSize;
}

template<class T>
void MTQueue<T>::Clear()
{
	m_pData = deallocate();
	m_nSize = 0;
	m_nCapacity = 0;
}

template<class T>
size_t MTQueue<T>::Capacity()
{
	return m_nCapacity;
}

template<class T>
size_t MTQueue<T>::Size()
{
	return m_nSize;
}

template <class T>
MTQueue <T>& MTQueue <T>::operator = (const MTQueue <T>& other)
{
	if (this == &other)
		return *this;
	if (m_nSize != other.m_nSize)
	{
		m_pData = deallocate();
		m_nSize = other.m_nSize;
		m_nCapacity = other.m_nCapacity;
		m_pData = allocate();
	}
	if (other.m_pData)
		memcpy(m_pData, other.m_pData, m_nCapacity);
	return *this;
}

template<class T>
T* MTQueue<T>::operator * ()
{
	return m_pData;
}

template <class T>
T* MTQueue <T>::allocate()
{
	return new T[m_nCapacity];
}

template <class T>
T* MTQueue <T>::deallocate()
{
	if (m_pData)
	{
		delete m_pData;
	}
	return nullptr;
}
