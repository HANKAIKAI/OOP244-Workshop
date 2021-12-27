//Name:YuanKai Han
//ID: 154477194
//Email: yhan77@myseneca.ca
// Date: 2021.12.1
/*-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_
#include <iostream>
#include "Collection.h"

namespace sdds
{
	//First use the keyword template, and use the type name T and T2 to identify a type.
	template<typename T, typename T2>
	bool check(T arr[], int index, T2 key) {
		// Call "==" operator corresponding to each type
		return arr[index] == key;
	}

	//First use the keyword template, and use the type name T and T2 to identify a type.
	template<typename T, typename T2>
	//This search function can find if the key value is match in the array or not.
	//Also, it will add all the match found to the collection.
	bool search(T arr[], int size_arr, T2 key, Collection<T>& collection) {
		//set a boolean to control if the function is match or not.
		bool match = false;
		for (int i = 0; i < size_arr; i++){
			// invoke check function if the element in the array matchs the key value, 
			if (check(arr, i, key)){
				//set the boolean to true means match, and add it to the collection.
				match = true;
				collection.add(arr[i]);
			}
		}
		return match;
	}

	//First use the keyword template, and use the type name T to identify a type.
	template<typename T>
	//This listArrayElements function will list all the elements of an array.
	void listArrayElements(const char* title_List,const T arr[], int size_arr) {
		//First print the tittle of the list of the array.
		std::cout << title_List << std::endl;
		//Use a loop to print the row number and also print the elements inside.
		for (int i = 0; i < size_arr; i++)
			// Call "<<" operator from the ReadWrite class that is abstract base class
			// and then compiler determines the actual object and Call the corresponding display()
			std::cout << (i + 1) << ": " << arr[i] << std::endl;
	}

	//First use the keyword template, and use the type name T to identify a type.
	template<typename T>
	//This sizeCheck function will compares the sizes of the two collections
	bool sizeCheck(Collection<T>& collection1, Collection<T>& collection2) {
		// Call the template function "size" in Collection template class
		//if collection 1 is larger than collection 2 return True
		return collection1.size() > collection2.size();
	}

}
#endif // !SDDS_SEARCH_H_