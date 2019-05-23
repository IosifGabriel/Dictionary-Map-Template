#include "pch.h"
#include "Map.h"
#include <iostream>

using namespace std;

template<class K, class V>
MyMap<K,V>::MyMap()
{
    K* Keys = new K;
	V* Values = new V;
	Keys = NULL;
	Values = NULL;
	size = 1;
}

template<class K, class V>
MyMap<K, V>::MyMap(const MyMap<K,V>& ToCopy)
{
	size = ToCopy.size;
	 Keys = new K[size];
	 Values = new V[size];

	for (int i=0;i<size;i++)
	{
		Keys[i] = ToCopy.Keys[i];
		Values[i] = ToCopy.Values[i];
	}
}

template<class K, class V>
MyMap<K,V>& MyMap<K, V>::operator=(const MyMap<K, V>& ToCopy)
{
	size = ToCopy.size;
	 K* Keys = new K[size];
	 V* Values = new V[size];

	for (int i = 0; i < size; i++)
	{
		Keys[i] = ToCopy.Keys[i];
		Values[i] = ToCopy.Values[i];
	}
	return *this;
}

template<class K, class V>
void MyMap<K,V>::AddPair(K Key, V Val)
{
	for (int i = 0; i < size; i++)
		if (Keys[i] == Key)
		{
			Values[i] = Val;
			return;
		}
		
		size++;
		K* Keys = new K[size];
		V* Values = new V[size];
		Keys[size - 1] = Key;
		Values[size - 1] = Val;
}

template<class K, class V>
void MyMap<K, V>::DeletePair(K Key, V Val)
{
	int PosOfApparition;
	for (int i = 0; i < size; i++)
		if (Keys[i] == Key && Values[i] == Val)
		{
			PosOfApparition = i;

			for (int i = PosOfApparition; i < size; i++)
			{
				Keys[i] = Keys[i + 1];
				Values[i] = Values[i + 1];
			}

			Values[size - 1] = NULL;
			Keys[size - 1] = NULL;
			size--;
		}
}

template<class K, class V>
bool MyMap<K, V>::IsHere(K Key)
{
	for (int i = 0; i < size; i++)
		if (Keys[i] == Key)
			return true;
	return false;
}

template<class K, class V>
int MyMap<K, V>::NumbOfPairs()
{
	return size;
}

template<class K, class V>
const V& MyMap<K, V>::operator[](K Key) const
{
	for (int i = 0; i < size; i++)
		if (Keys[i] == Key)
			return Values[i];
}


template<class K, class V>
MyMap<K,V>::~MyMap()
{
	delete[] Keys;
	delete[] Values;
}

template<class K, class V>
ostream&  operator<<(ostream& os, const MyMap<K,V>& MyDictionary)
{
	for (int i = 0; i < MyDictionary.size; i++)
	{
		os << MyDictionary.Keys[i];
		os << MyDictionary.Values[i];
	}

	return os;
}
