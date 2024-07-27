/*
 * arrayList.h
 *
 *  Created on: Feb 15, 2024
 *      Author: brandonlau
 */

#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#include <iostream>
using namespace std;

template <typename elemType>
class arrayList
{
	public:
		arrayList()
		{
			arrLength=0;
			max_list_size = defaultSize;
			arr = new elemType[max_list_size];
		}
		~arrayList()
		{
				delete []arr;

		}
		bool isEmpty() const
		{
			return (arrLength==0);
		}
		bool isFull() const
		{
			return (arrLength==max_list_size);
		}
		int listSize() const
		{
			return arrLength;
		}
		int maxListSize() const
		{
			return max_list_size;
		}
		void print()
		{
			if(this->arrLength>max_list_size)
			{
				cout << "cannot print." << endl;
				return;
			}
			else
			{
				for(int i=0; i<arrLength; i++)
				{
					cout << "arr[" << i << "]=" << arr[i] << endl;
				}
			}
		}
		bool isItemAtEqual(int location, elemType item)
		{
			return ((arr[location]==item)&&(location<max_list_size));
		}
		void insertAt(int position, elemType item)
		{
			if(position>max_list_size)
			{
				cout << "error: requested position greater than max list size." << endl;
			}
			else if(arrLength>=max_list_size)
			{
				cout << "error: length of array exceeds max list size." << endl;
			}
			else
			{
				arrLength++;
				for(int i=arrLength; i>=position; i--)
				{
					arr[i+1]=arr[i];
				}
				arr[position]=item;
			}
		}
		void insertEnd(elemType item)
		{
			arr[arrLength]=item;
			arrLength++;
			if(arrLength>max_list_size)
			{
				cout << "error: length of array size exceeded." << endl;
			}
		}


		elemType retrieveAt(int location)
		{
			for(int i=0; i<arrLength; i++)
			{
				if((arr[i]==arr[location])&&(location<max_list_size))
				{
					return(arr[i]);
				}
			}
		}
		void replaceAt(int location, elemType item)
		{
			if(location<max_list_size)
			{
				arr[location] = item;
			}
			else
			{
				cout << "Error: cannot replace item at requested location. Location exceeds list size." << endl;
			}
		}
		void extend(const arrayList *aList)
		{
			if(this->arrLength>=max_list_size)
			{
				cout << "Error: Cannot extend, max list size exceeded." << endl;
				return;
			}
			else
			{
				for (int i=0; i<aList->arrLength; i++)
				{
					insertEnd(aList->arr[i]);
				}
			}
		}
		elemType myMin() const
		{
			for(int i=0; i<arrLength; i++)
			{
				for(int j=0; j<arrLength-1; j++)
				{
					if(arr[j+1]<arr[j])
					{
						elemType temp;
						temp = arr[j];
						arr[j] = arr[j+1];
						arr[j+1] = temp;
					}
				}
			}

			elemType min=arr[0];
			return min;
		}
		elemType myMax() const
		{
			for(int i=0; i<arrLength; i++)
			{
				for(int j=0; j<arrLength-1; j++)
				{
					if(arr[j+1]>arr[j])
					{
						elemType temp;
						temp = arr[j];
						arr[j] = arr[j+1];
						arr[j+1] = temp;
					}
				}
			}

			elemType max=arr[0];
			return max;
		}
		int count(const elemType &listElement)
		{
			int occurrences=0;
			for(int i=0; i<arrLength; i++)
			{
				if(arr[i]==listElement)
				{
					occurrences++;
				}
			}
			return occurrences;
		}





		elemType getMinRecursive(int n)
		{

			if(n==1)
			{
				return arr[0];
			}
			else
			{
				return min(arr[n-1],getMinRecursive(n-1));
			}
		}

		elemType getMaxRecursive(int n)
		{
			if(n==1)
			{
				return arr[0];
			}
			else
			{
				return max(arr[n-1], getMaxRecursive(n-1));
			}

		}

		unsigned int seqSearchIter(elemType element)
		{
			int key = element;
			for(int i=0; i<max_list_size; i++)
			{
				if(arr[i]==key)
				{
					return i;
				}
			}
			return -1;
		}

		unsigned int seqSearchRecHelperFn(int *arr,int size, int key)
		{

			if(arrLength==0)
			{
				return -1;
			}
			else if(arr[size-1]==key)
			{
				return size-1;
			}
			else
			{
				return seqSearchRecHelperFn(arr, size-1, key);
			}

		}

		unsigned int seqSearchRec(elemType element)
		{
			int key = element;
			unsigned int result = seqSearchRecHelperFn(arr, arrLength, key);
			return result;
		}



	private:
		elemType *arr;
		int arrLength;
		int max_list_size;
		static const int defaultSize=5;


};



#endif /* ARRAYLIST_H_ */
