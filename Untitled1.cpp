#ifndefH_LinkedListType
#defineH_LinkedListType

#include<iostream>
#include<cassert>
usingnamespacestd();

template<classType>
structnodeType
{
	Type info;
	nodeType<Type>*link;
};

template<classType>
classlinkedListType
{
	template<classType>
	friendostream&operator<<(ostream&,constlinkedListType<Type>&);

public:
constlinkedListType<Type>&operator=
			(constlinkedListType<Type>&);

voidinitializeList();

boolisEmptyList();


	int length();

.
voiddestroyList();

Type front();

Type back();
bool search(constType&searchItem);


voidinsertFirst(constType&newItem);

voidinsertLast(constType&newItem);


voiddeleteNode(constType&deleteItem);

	voiddeleteSmallest();

linkedListType();

linkedListType(constlinkedListType<Type>&otherList);


~linkedListType();


protected:
int count;
nodeType<Type>*first;
nodeType<Type>*last;
private:
voidcopyList(constlinkedListType<Type>&otherList);

};

template<classType>
voidlinkedListType<Type>::deleteSmallest()
{
	Type smallest;

	deleteNode(smallest);
}

template<classType>
boollinkedListType<Type>::isEmptyList()
{
	return(first == NULL);
}

template<classType>
linkedListType<Type>::linkedListType()
{
	first = NULL;
	last = NULL;
	count =0;
}

template<classType>
voidlinkedListType<Type>::destroyList()
{
	nodeType<Type>*temp;
	while(first != NULL)
	{
	   temp = first;
	   first = first->link;
	delete temp;
	}

	last = NULL;
	count =0;
}


template<classType>
voidlinkedListType<Type>::initializeList()
{
	destroyList();
}

template<classType>
intlinkedListType<Type>::length()
{
	return count;
}// end length

template<classType>
TypelinkedListType<Type>::front()
{
    assert(first != NULL);
	return first->info;

template<classType>
TypelinkedListType<Type>::back()
{
	 assert(last != NULL);
	return last->info;
}//end back

template<classType>
boollinkedListType<Type>::search(constType&searchItem)
{
nodeType<Type>*current;
bool found;

    current = first;
    found =false;
while(current != NULL &&!found)
if(current->info ==searchItem)
           found =true;
else
           current = current->link;

return found;
}

template<classType>
voidlinkedListType<Type>::insertFirst(constType&newItem)
{
	nodeType<Type>*newNode;

	newNode=newnodeType<Type>;
	assert(newNode!= NULL);

	newNode->info =newItem;
	newNode->link = first;
	first =newNode;
	count++;
	if(last == NULL)
		last =newNode;
}

template<classType>
voidlinkedListType<Type>::insertLast(constType&newItem)
{
	nodeType<Type>*newNode;
	newNode=newnodeType<Type>;

	assert(newNode!= NULL);

	newNode->info =newItem;
	newNode->link = NULL;

	if(first == NULL)
	{
		first =newNode;
		last =newNode;
		count++;
	}
	else
	{
		last->link =newNode;
		last =newNode;
		count++;
	}
}

template<classType>
voidlinkedListType<Type>::deleteNode(constType&deleteItem)
{
	nodeType<Type>*current;
	nodeType<Type>*trailCurrent;
	bool found;

	if(first == NULL)
		cerr<<"Can not delete from an empty list.\n";
	else
	{
		if(first->info ==deleteItem)//Case 2
		{
			current = first;
			first = first->link;
			count--;
			if(first == NULL)
				last = NULL;
			delete current;
		}
		else
		{
			found =false;
			trailCurrent= first;
			current = first->link;

			while(current != NULL &&!found)
			{
				if(current->info !=deleteItem)
				{
					trailCurrent= current;
					current = current->link;
				}
				else
					found =true;
			}

			if(found)
			{
				trailCurrent->link = current->link;
				count--;

				if(last == current)
					last =trailCurrent;

				delete current;
			}
			else
				cout<<"Item to be deleted is not in the list."<<endl;

template<classType>
ostream&operator<<(ostream&osObject,constlinkedListType<Type>&list)
{
	nodeType<Type>*current;

	current =list.first;
	while(current != NULL)
	{
	osObject<<current->info<<" ";
	   current = current->link;
	}

	returnosObject;
}

template<classType>
linkedListType<Type>::~linkedListType()
{
	destroyList();
}

template<classType>
voidlinkedListType<Type>::copyList
	(constlinkedListType<Type>&otherList)
{
nodeType<Type>*newNode;
nodeType<Type>*current;

if(first != NULL)
	destroyList();

if(otherList.first== NULL)
{
		first = NULL;
		last = NULL;
		count =0;
}
else
{
		current =otherList.first;
		count =otherList.count;


		first =newnodeType<Type>;

		assert(first != NULL);

		first->info = current->info;
		first->link = NULL;
		last = first;
		current = current->link;

		while(current != NULL)
		{
			newNode=newnodeType<Type>;

			assert(newNode!= NULL);

			newNode->info = current->info;
			newNode->link = NULL;
			last->link =newNode;
			last =newNode;
			current = current->link;
template<classType>
linkedListType<Type>::linkedListType
	(constlinkedListType<Type>&otherList)
{
	first = NULL;

	copyList(otherList);

template<classType>
constlinkedListType<Type>&linkedListType<Type>::operator=
				(constlinkedListType<Type>&otherList)
{
	if(this!=&otherList)
		copyList(otherList);

	return*this;



