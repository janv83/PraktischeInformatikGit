#include "myHeap.h"



template <typename myType>
myHeap<myType>::myHeap(unsigned n)  : elements(0), size(n), data(new myType[n]) 
{
}

template <typename myType>
myHeap<myType>::~myHeap()
{
	delete [] data;
}

template <typename myType>
bool myHeap<myType>::empty() const
{
	return elements;
}

template <typename myType>
myType myHeap<myType>::top() const
{
	assert(elements > 0);
	return data[0];
}
template <typename myType>
void myHeap<myType>::push(myType d)
{
	assert(elements < size);
	data[elements++] = d;
	unsigned idx = elements-1;
	while (idx != 0) 
	{
		unsigned pidx = parent_index(idx);
		if (data[pidx] < d)
		{
			std::swap(data[idx], data[pidx]);
		}
		else
		{
			break;
		} 
		idx = pidx;
	}
}
template <typename myType>
void myHeap<myType>::pop()
{
	assert(elements > 0);
	data[0] = data[--elements];
	unsigned idx = 0;
	do 
	{
		unsigned childs = children(idx);
		if (childs == 0)
		{
			break;
		}
		unsigned max_idx = left_index(idx);
		if (childs == 2) 
		{
			if (data[max_idx] < data[max_idx + 1])
			{
					max_idx++;
			}
		}
		if (data[idx] < data[max_idx]) 
		{
			std::swap(data[idx], data[max_idx]);
			idx = max_idx;
		}
		else 
		{
			break;
		}
	} while (true);
}
template <typename myType>
void myHeap<myType>::print() const
{
	for(int i = 0 ; i < elements; i++)
	{
		
		std::cout << data[i] << std::endl;
	
	}
}
template <typename myType>
unsigned myHeap<myType>::left_index(unsigned idx) const
{
	return 2 * idx + 1;
}
template <typename myType>
unsigned myHeap<myType>::right_index(unsigned idx) const
{
	return 2 * idx + 2;
}
template <typename myType>
unsigned myHeap<myType>::parent_index(unsigned idx) const
{
	return (idx - 1) / 2;
}
template <typename myType>
unsigned myHeap<myType>:: children(unsigned idx) const
{
	if (elements <= left_index(idx)) 
	{
		return 0;
	}
	else if (elements > right_index(idx)) 
	{
		return 2;
	}
	else 
	{
		return 1;
	}
}
template <typename myType>
unsigned myHeap<myType>::getElements()
{
	return elements;
}

template <typename myType>
myType* myHeap<myType>::sort()
{
	int elementsTemp = elements;
	
	myType* returnArray = new myType[elements];
	for(int i = 0; i < elementsTemp; i++)
	{
		returnArray[i] = top();
		pop(); // this way the heap gets sorted again
	}
	for(int i = 0; i < elementsTemp; i++)
	{
		push(returnArray[i]);
	}

	return returnArray;
}

class ComparableClass
{
	private:
			int value;
			
	public: 
			ComparableClass():value(0){}
			ComparableClass(int i):value(i){}
			bool operator<(ComparableClass c1)
			{
				if(value < c1.value)
					return true;
				else 
					return false;
			}
			int getValue(){
				return value;
			}
			void print()
			{
				std::cout << value << std::endl;
			}
		friend std::ostream& operator<<(std::ostream& out, ComparableClass& cc)
		{
			return out << cc.getValue();
		}

};

/*int main()
{
	myHeap<int> testHeap1(15);
	testHeap1.push(1);
	testHeap1.push(2);
	testHeap1.push(8);
	testHeap1.push(5);
	testHeap1.print();
	
	myHeap<ComparableClass> testHeap2(15);
	ComparableClass cc1(13);
	ComparableClass cc2(11);
	ComparableClass cc3(18);
	ComparableClass cc4(15);
	testHeap2.push(cc1);
	testHeap2.push(cc2);
	testHeap2.push(cc3);
	//testHeap2.push(cc4);
	testHeap2.print();
	
	testHeap2.top().print();
}
*/
