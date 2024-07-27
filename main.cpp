//============================================================================
// Name        : cmpe126lab9.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "arrayList.h"
#include "linkedList.h"
#include "sortedarrayList.h"
using namespace std;

template <typename elemType>
struct key
{
    elemType key;
};


int main()
{

    unsigned int choice=0;
    do
    {
        cout << "Choose your search type:" << endl;
        cout << "1. Arrays: Sequential Search without recursion" << endl;
        cout << "2. Arrays: Sequential Search with recursion" << endl;
        cout << "3. Ordered Arrays: Binary Search without recursion" << endl;
        cout << "4. Ordered Arrays: Binary Search with recursion" << endl;
        cout << "5. Linked List: Search without recursion" << endl;
        cout << "6. Linked List: Search with recursion" << endl;
        cout << "Enter 0 to exit" << endl;
        cout << "Your choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            arrayList<int> arrList;
            key<int> k;
            unsigned int result;
            arrList.insertEnd(4);
            arrList.insertEnd(8);
            arrList.insertEnd(2);
            arrList.insertEnd(3);
            arrList.insertEnd(10);
            cout << "\nSpecify the element to be searched for: ";
            cin >> k.key;
            result = arrList.seqSearchIter(k.key);
            if (result == -1)
            {
                cout << "Element was not found in array." << endl;
            }
            else
            {
                cout << "Element was found at index: " << result << endl;
            }
            break;
        }
        case 2:
        {
            arrayList<int> arrList;
            key<int> k;
            unsigned int result;
            arrList.insertEnd(4);
            arrList.insertEnd(8);
            arrList.insertEnd(2);
            arrList.insertEnd(3);
            arrList.insertEnd(10);
            cout << "\nSpecify the element to be searched for: ";
            cin >> k.key;
            result = arrList.seqSearchRec(k.key);
            if (result == -1)
            {
                cout << "Element was not found in array." << endl;
            }
            else
            {
                cout << "Element was found at index: " << result << endl;
            }
            break;
        }

        case 3:
        {
        	sortedarrayList <int> s;
        	 key<int> k;
        	if(s.insert(5))
        	{
        		cout << "element inserted successfully." << endl;
        	}
        	if(s.insert(3))
        	{
        		cout << "element inserted successfully." << endl;
        	}
        	if(s.insert(10))
        	{
        		cout << "element inserted successfully." << endl;
        	}
        	if(s.insert(6))
        	{
        		cout << "element inserted successfully." << endl;
        	}
        	if(s.insert(1))
        	{
        		cout << "element inserted successfully." << endl;
        	}

        	cout << "\nSpecify the element to be searched for: ";
        	cin >> k.key;

        	s.print();
        	cout << "Binary searched without recursion: " << s.binarySearchIter(k.key) << endl;


        	break;
        }
        case 4:
        {
        	sortedarrayList <int> s;
        	key<int> k;
        	if(s.insert(5))
        	{
        	   cout << "element inserted successfully." << endl;
        	}
        	if(s.insert(3))
        	{
        	   cout << "element inserted successfully." << endl;
        	}
        	if(s.insert(10))
        	{
        	    cout << "element inserted successfully." << endl;
        	}
        	if(s.insert(6))
        	{
        		cout << "element inserted successfully." << endl;
        	}
        	if(s.insert(1))
        	{
        	    cout << "element inserted successfully." << endl;
        	}

        	cout << "\nSpecify the element to be searched for: ";
        	cin >> k.key;

        	s.print();
        	cout << "Binary searched with recursion: " << s.binarySearchRec(k.key) << endl;

        	break;
        };
        case 5:
        {
            LinkedList<int> l;
            key<int> k;

            l.insertEnd(3);
            l.insertEnd(2);
            l.insertEnd(6);
            l.insertEnd(10);
            l.insertEnd(12);
            cout << "\nSpecify the element to be searched for: ";
            cin >> k.key;

            if (l.seqSearchIter(k.key))
            {
                cout << "Requested element is present in linked list." << endl;
            }
            else
            {
                cout << "Requested element is not present in linked list." << endl;
            }
            break;
        }
        case 6:
        {
            LinkedList<int> l;
            key<int> k;
            l.insertEnd(5);
            l.insertEnd(2);
            l.insertEnd(6);
            l.insertEnd(10);
            l.insertEnd(12);
            cout << "\nSpecify the element to be searched for: ";
            cin >> k.key;
            if (l.seqSearchRec(k.key))
            {
                cout << "Requested element is present in linked list." << endl;
            }
            else
            {
                cout << "Requested element is not present in linked list." << endl;
            }
            break;
        }
        case 0:
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }


    } while (choice != 0);

    return 0;
}




