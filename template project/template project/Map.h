#pragma once
#include <iostream>
#include <assert.h>

using namespace std;

template<class K,class V>
class MyMap
{
	K* Keys;
	V* Values;
	int size;

public:
	MyMap();
	~MyMap();
	MyMap(const MyMap&);
	MyMap& operator=(const MyMap&);
    void AddPair (K Key, V Value);
	void DeletePair(K Key);
	bool IsHere(K Key);
	int NumbOfPairs();
	const V& operator[](K Key) const;
	template<typename K,typename V> friend ostream& operator<<(ostream& , const MyMap<K, V>& MyDictionary);
	
	template<typename Operation>
	void Transformation(Operation op)
	{
		for(int i=0;i<size-1;i++)
		Keys[i] = op(Keys[i]);
	}
};

template<class K, class V>
MyMap<K, V>::MyMap()
{
	size = 1;
	Keys = new K[size];
	Values = new V[size];
	
}

template<class K, class V>
MyMap<K, V>::MyMap(const MyMap<K, V>& ToCopy)
{
	size = ToCopy.size;
	Keys = new K[size];
	Values = new V[size];

	for (int i = 0; i < size; i++)
	{
		Keys[i] = ToCopy.Keys[i];
		Values[i] = ToCopy.Values[i];
	}
}

template<class K, class V>
MyMap<K, V>& MyMap<K, V>::operator=(const MyMap<K, V>& ToCopy)
{
	 size = ToCopy.size;
	 Keys = new K[size];
	 Values = new V[size];

	for (int i = 0; i < size; i++)
	{
		Keys[i] = ToCopy.Keys[i];
		Values[i] = ToCopy.Values[i];
	}
	return *this;
}

template<class K, class V>
void MyMap<K, V>::AddPair(K Key, V Val)
{
	for (int i = 0; i < size; i++)
		if (Keys[i] == Key)
		{
			Values[i] = Val;
			return;
		}

	//resize
	size++;
	K* DummyKey = new K[size];
	V* DummyValue = new V[size];

	for (int i = 0; i < size - 1; i++)
	{
		DummyKey[i] = Keys[i];
		DummyValue[i] = Values[i];
	}
	delete[]Keys;
	delete[]Values;
	Keys = DummyKey;
	Values = DummyValue;
	

	Keys[size - 2] = Key;
	Values[size - 2] = Val;
	
}

template<class K, class V>
void MyMap<K, V>::DeletePair(K Key)
{
	int PosOfApparition = -1;
	try {
		
		for (int i = 0; i < size; i++)
			if (Keys[i] == Key)
			{
				PosOfApparition = i;

				for (int i = PosOfApparition; i < size - 1; i++)
				{
					Keys[i] = Keys[i + 1];
					Values[i] = Values[i + 1];
				}


				size--;
			}
		if (PosOfApparition == -1)
			throw Key;
	}
	catch (K Key)
	{
		cout << "Key doesnt exist  " << Key << endl;
		assert(PosOfApparition != -1);
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
	return size-1;
}

template<class K, class V>
const V& MyMap<K, V>::operator[](K Key) const
{

		for (int i = 0; i < size; i++)
			if (Keys[i] == Key)
				return Values[i];
	
}


template<class K, class V>
MyMap<K, V>::~MyMap()
{
	delete[] Keys;
	delete[] Values;
}

template<class K, class V>
ostream&  operator<<(ostream& os, const MyMap<K, V>& MyDictionary)
{
	cout << "KEY VALUE"<<endl;
	for (int i = 0; i < MyDictionary.size-1; i++)
	{
		os << MyDictionary.Keys[i]<<"   ";
		os << MyDictionary.Values[i] << endl;
	}

	return os;
}


