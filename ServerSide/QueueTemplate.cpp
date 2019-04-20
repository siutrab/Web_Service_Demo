//#include "QueueTemplate.h"
//
//template<typename T>
//Queue<T>::Queue()
//	: itemQueue()
//{
//}
//
//template<typename T>
//Queue<T>::~Queue()
//{	}
//
//template<typename T>
//void Queue<T>::addItem(T* item)
//{
//	itemQueue.push(item);
//}
//
//template<typename T>
//T* Queue<T>::getItem()
//{
//	T* item = itemQueue.front();
//	itemQueue.pop();
//	return item;
//}
//template<typename T>
//bool Queue<T>::isEmpty()
//{
//	if (itemQueue.size() == 0) return true;
//	else return false;
//}