#include "pch.h"
#include <iostream>
#include "Map.h"
#include "IncrementFunctor.h"
#include <string>


using namespace std;

int main()
{
	IncrementFunctor<int> incrementfunctor(1);
	MyMap<int, char> MyDictionary;
	MyDictionary.AddPair(1, 'a');
	MyDictionary.Transformation(incrementfunctor);
	MyDictionary.DeletePair(1);;

	cout << MyDictionary<<MyDictionary.NumbOfPairs();
	
}
