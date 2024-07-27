/*
 * linkedList.h
 *
 *  Created on: Mar 2, 2024
 *      Author: brandonlau
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
using namespace std;


template<typename elemType>
struct Node
{
    Node *next;
    elemType data;
};

template <typename elemType>
class LinkedList
{
  Node <elemType> *head;
  Node <elemType> *tail;
  static const int max_list_size = 5;
  int listLength;



public:
  LinkedList()
  {
    head = NULL;
    tail = NULL;
    listLength=0;
  }

  ~LinkedList()
  {
    Node <elemType> *currentNode = head;

    while(currentNode != NULL)
    {
        Node <elemType> *nextNode = currentNode;
        delete currentNode;
        currentNode = nextNode->next;
    }
  }

  LinkedList& operator=(const LinkedList& otherNode)
  {

       if (this != &otherNode)
       {
           Node <elemType>* currentNode = otherNode.head;
           while (currentNode != nullptr)
           {
               insertEnd(currentNode->data);
               currentNode = currentNode->next;
           }
       }
       return *this;
  }


  void print()
  {
    Node <elemType> *p = head;
    cout << "printing list data: " << endl;
    while(p != NULL)
    {
      cout << p->data << endl;
      p = p->next;
    }
  }


  void insertEnd(elemType n)
  {

	Node <elemType>*n3 = new Node <elemType>();
	n3->data = n;
	n3->next = NULL;
	listLength++;


	if(head==NULL)
	{
		head  = n3;
		tail = n3;

	}
	else
	{
		tail->next = n3;
		tail = n3;
	}
  }

  void insertAt(int position, elemType item)
  {


	  Node <elemType> *newNode = new Node <elemType> ();
	  if(position==0 && listLength==0)
	  {
		  Node <elemType> *newNode = new Node <elemType> ();
		  head = newNode;
		  head->data = item;
	 	  head->next = NULL;
	 	  listLength++;
	  }

	  if(position==0)
	  {
		  Node <elemType> *newNode = new Node <elemType> ();
		  Node <elemType> *currentNode = head;
		  head = newNode;
		  head->next = currentNode;
		  head->data = item;
		  listLength++;
	  }


	  Node <elemType> *currentNode = head;
	  int index=0;


	  while(currentNode->next!=NULL && index<=position-1)
	  {
		  currentNode = currentNode->next;
		  index++;
	  }

	  if(index!=position-1)
	  {
		  delete newNode;
		  return;
	  }

	  newNode->next = currentNode->next;
	  newNode->data = item;
	  listLength++;
	  currentNode->next = newNode;
  }

  void clearList()
  {

	  head = NULL;
	  tail = NULL;
  }

  void replaceAt(int position, elemType item)
  {
	  if(position<0)
	  {
		  cout << "List index out of range." << endl;
	  }

	  Node <elemType> *currentNode = head;
	  int index=0;



	  while(currentNode->next!=NULL)
	  {
		 //currentNode = currentNode->next;
		 if(index==position)
		 {
			 //cout << "position: " << position << endl;
			 currentNode->data = item;
			 currentNode = currentNode->next;
			 index++;
		 }
		 else
		 {
			 currentNode = currentNode->next;
			 index++;
		 }
	  }
  }

  void removeAt(int position)
  {
	  if(position<0)
	  {
		  cout << "list index is out of range." << endl;
	  }


	  cout << "List length: " << listLength << endl;

	  Node <elemType> *temp = head;
	  Node <elemType> *tail = head;

	  //delete head node
	  if(position==0)
	  {
		  head = temp->next;
		  delete temp;
		  listLength--;
		  cout << "List length: " << listLength << endl;
		  return;
	  }


	  int i=0;
	  if(position==1)
	  {
		  while(temp->next!=NULL&&position!=i)
		  {
			  temp = temp->next;
			  i++;
		  }
		  if(position==i)
		  {
			  head->next = temp->next;
		  }
		  listLength--;
		  cout << "List length: " << listLength << endl;
	  }



	  int index=0;
	  while(temp->next!=NULL&&position!=index)
	  {
		  temp = temp->next;
		  index++;
	  }

	  int j=0;
	  while(tail->next!=NULL&&j<index-1)
	  {
		  tail = tail->next;
		  j++;
		  if(j==position-1)
		  {
			  tail->next=temp->next;
			  delete temp;
			  listLength--;
			  cout << "List length: " << listLength << endl;
			  return;
		  }
	  }
	  int k=0;
	  while(temp->next!=NULL&&position!=k)
	  {
		  temp = temp->next;
		  k++;
	  }
  }



  bool isEmpty()
  {
	  return (head == NULL && tail==NULL);
  }

  bool isFull()
  {
	  return (listLength == max_list_size);
  }

  bool isItemAtEqual(int position, elemType item)
  {


	  if(position<0)
	  {
		cout << "List index out of range. " << endl;
		return false;
	  }

	  Node <elemType>*currentNode = head;
	  int index=0;

	  while(currentNode->next!=NULL)
	  {
			  currentNode = currentNode->next;
			  index++;
	  }

	  if(currentNode == NULL)
	  {
		  cout << "List index out of range. " << endl;
		  return false;
	  }

	  if(index==position && currentNode->data==item)
	  {
		  return true;
	  }
	  else
	  {
		  return false;
	  }
  }

  elemType retrieveAt(int position)
  {
	  if(position<0)
	  {
		  cout << "List index out of range." << endl;
	  }

	  Node <elemType>*currentNode = head;
	  int index=0;

	  while(currentNode->next!=NULL && index!=position)
	  {
		  currentNode = currentNode->next;
		  index++;
		  if(position==index && position<max_list_size)
		  {
			  return (currentNode->data);
		  }
	  }

	  if(currentNode==NULL)
	  {
		  cout << "List index out of range." << endl;
	  }
  }



  int maxListSize() const
  {
	  return max_list_size;
  }

  int listSize() const
   {
 	  return listLength;
   }

  elemType myMin() const
  {
	  Node <elemType> *currentNode = head;
	  Node <elemType> *min;
	  Node <elemType> *i;

	  min = currentNode;

	   	  for(i=currentNode; i!=NULL; i = i->next)
	   	  {
	   		  if(i->data<min->data)
	   		  {
	   			  min->data = i->data;
	   		  }
	   	  }

	   	  return min->data;
  }

   elemType myMax() const
   {
	   Node <elemType> *currentNode = head;
	   Node <elemType> *max;
	   Node <elemType> *i;

	   	  max = currentNode;

	   	   	  for(i=currentNode; i!=NULL; i = i->next)
	   	   	  {
	   	   		  if(i->data>max->data)
	   	   		  {
	   	   			  max->data = i->data;
	   	   		  }
	   	   	  }

	   	   	  return max->data;


   }

   int count(const elemType &element)
   {
	   int occurrences=0;
	   Node <elemType> *currentNode = head;
	   Node <elemType> *i;
	   	for(i=currentNode; i!=NULL; i = i->next)
	   	{
	   		if(i->data==element)
	   		{
	   			occurrences++;
	   		}
	   	}
	   	return occurrences;
   }

   void extend(const LinkedList *otherList)
   {
	   Node <elemType> *currentNode = otherList->head;
	   Node <elemType> *i;
	   if(this->listLength>=max_list_size)
	   {
	   		cout << "Error: Cannot extend, max list size exceeded." << endl;
	   		return;
	   }
	   	else
	   	{

	   		for (i=currentNode; i!=NULL; i = i->next)
	   		{
	   			insertEnd(currentNode->data);
	   		}

	   	}
   }

   Node <elemType> *getHead()
   {
	   return head;
   }

   elemType getMinRecursive(Node <elemType> *currentNode)
   	{


   			if(currentNode->next==NULL)
   			{
   				return currentNode->data;
   			}
   			else
   			{

   				return min(currentNode->data, getMinRecursive(currentNode->next));

   			}
   	}

   elemType getMaxRecursive(Node <elemType> *currentNode)
   {


      			if(currentNode->next==NULL)
      			{
      				return currentNode->data;
      			}
      			else
      			{

      				return max(currentNode->data, getMaxRecursive(currentNode->next));

      			}
   }

   bool seqSearchIter(elemType element)
   {
	   Node <elemType> *currentNode=head;
	   while(currentNode!=NULL)
	   {
		   if(currentNode->data==element)
		   {
			   return true;
		   }
		   else
		   {
			   currentNode = currentNode->next;
		   }
	   }
	   return false;
   }

   bool linearSearchRec(Node <elemType>*currentNode, elemType element)
   {

	   if(currentNode==NULL)
	   {
		   return false;
	   }
	   if(currentNode->data==element)
	   {
		   return true;
	   }
	   else
	   {
		   return linearSearchRec(currentNode->next, element);
	   }
   }

   	bool seqSearchRec(elemType element)
    {
   		Node <elemType> *currentNode=head;
   		bool result = linearSearchRec(currentNode, element);
   		return result;
    }



};


#endif /* LINKEDLIST_H_ */
