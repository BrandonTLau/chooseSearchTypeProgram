/*
 * sortedarrayList.h
 *
 *  Created on: May 6, 2024
 *      Author: brandonlau
 */

#ifndef SORTEDARRAYLIST_H_
#define SORTEDARRAYLIST_H_

#include <iostream>
using namespace std;

template <typename elemType>
class sortedarrayList
{
	public:
		sortedarrayList()
		{
			arrLength=0;
			max_list_size = defaultSize;
			arr = new elemType[max_list_size];
		}
		~sortedarrayList()
		{
			delete []arr;
		}
		bool isEmpty()
		{
			return (arrLength==0);
		}
		bool isFull()
		{
			return (arrLength==max_list_size);
		}
		int listSize()
		{
			return arrLength;
		}
		int maxListSize()
		{
			return max_list_size;
		}
		void print()
		{
			for(int i=0; i<arrLength; i++)
			{
				cout << "arr[" << i << "]:" << arr[i] << endl;
			}
		}
		bool insert(elemType element)
		{
			while(arrLength<max_list_size)
			{
				arr[arrLength] = element;
				arrLength++;

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
			return true;
			}
			return false;
		}

		void remove(elemType element)
		{

			int x;
			for(int i=0; i<arrLength; i++)
			{
				if(arr[i]==element)
				{
					x = i;
				}
			}

			for(int j=x; j<arrLength; j++)
			{

				arr[j] = arr[j+1];
			}
			arrLength--;
		}

		void clearList()
		{

			for(int i=0; i<arrLength; i++)
			{
				arr[i] = 0;
			}
		}


		unsigned int binarySearchIter(elemType element)
		{
			int low = 0;
			int high = arrLength-1;
			int mid;



			while(low<=high)
			{
				mid = (low+high)/2;

				if(element==arr[mid])
				{
					return mid;
				}

				else if(element>arr[mid])
				{
					low = mid+1;
				}
				else
				{
					high = mid-1;
				}
			}
		}

		unsigned int binarySearchHelperFn(int arr[], int low, int high, elemType element)
		{
			while(low<=high)
			{
				int mid = (low+high)/2;
				if(element==arr[mid])
				{
					return mid;
				}
				else if(element>arr[mid])
				{
					low = mid+1;
					return binarySearchHelperFn(arr, mid+1, high, element);
				}
				else
				{
					high = mid-1;
					return binarySearchHelperFn(arr, low, mid-1, element);
				}
			}
		}


		unsigned int binarySearchRec(elemType element)
		{
			int low = 0;
			int high = arrLength-1;
			int mid;

			mid = binarySearchHelperFn(arr, low, high, element);
			return mid;
		}




	private:
		elemType *arr;
		int arrLength;
		int max_list_size;
		static const int defaultSize=5;
};




#endif /* SORTEDARRAYLIST_H_ */
