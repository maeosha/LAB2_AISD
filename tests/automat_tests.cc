#include <automat/automat.h>

int main() {
	{
		std::cout << "TEST 1'st: Random constructor test:" << std::endl;
		NodeList list(20);
		NodeList _list(20);
		std::cout << "The first random list:  " << list;
		std::cout << "The second random list: " << _list;
		std::cout << std::endl;
	}
	{
		std::cout << "TEST 2'nd: Copy constructor test:" << std::endl;
		NodeList list(20);
		NodeList _list(list);
		std::cout << "The list:         " << list;
		std::cout << "The copied sheet: " << _list;
		std::cout << std::endl;
	}
	{
		std::cout << "TEST 3'rd: Destructor test:" << std::endl;
		NodeList list(20);
		std::cout << "The list: " << list;
		std::cout << "List size: " << list.get_size() << std::endl;
		list.delete_all();
		std::cout << "The sheet after the destructor: " << list;
		std::cout << "The size of the list after the destructor: " << list.get_size() << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "TEST 4'th: Operator= test:" << std::endl;
		NodeList list(20);
		NodeList _list;
		_list = list;
		std::cout << "The list:         " << list;
		std::cout << "The copied sheet: " << _list;
		std::cout << std::endl;
	}
	{
		std::cout << "TEST 5'th: push_tail test:" << std::endl;
		NodeList list(5);
		std::cout << "The list: " << list;
		bool elem = 0;
		std::cout << "The element to be added to the tail: " << elem << std::endl;

		list.push_tail(elem);
		std::cout << "The list: " << list;
		std::cout << std::endl;
	}

	{
		std::cout << "TEST 6'th: push_tail list test:" << std::endl;
		NodeList list(5);
		NodeList _list(20);
		std::cout << "The list: " << list;
		std::cout << "The list to be added to the tail: " << _list;
		list.push_tail(_list);
		std::cout << "The list: " << list;
		std::cout << std::endl;
	}

	{
		std::cout << "TEST 7'th: push_head test:" << std::endl;
		NodeList list(5);
		std::cout << "The list: " << list;
		bool elem = 0;
		std::cout << "The element to be added to the head: " << elem << std::endl;

		list.push_head(elem);
		std::cout << "The list: " << list;
		std::cout << std::endl;
	}

	{
		std::cout << "TEST 8'th: push_head list test:" << std::endl;
		NodeList list(5);
		NodeList _list(20);
		std::cout << "The list: " << list;
		std::cout << "The list to be added to the head: " << _list;
		list.push_head(_list);
		std::cout << "The list: " << list;
		std::cout << std::endl;
	}

	{
		std::cout << "TEST 9'th: pop_tail test:" << std::endl;
		NodeList list(5);
		std::cout << "The list: " << list;
		list.pop_tail();
		std::cout << "The list after deleting the last element: " << list;
		std::cout << std::endl;
	}

	{
		std::cout << "TEST 10'th: pop_head test:" << std::endl;
		NodeList list(5);
		std::cout << "The list: " << list;
		list.pop_head();
		std::cout << "The list after deleting the first element: " << list;
		std::cout << std::endl;
	}

	{
		std::cout << "TEST 11'th: operator[] test:" << std::endl;
		NodeList list(5);
		std::cout << "The list: " << list;
		for (size_t index = 0; index < list.get_size(); index++) {
			std::cout << "An element with an " << index << " index: " << list[index] << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "TEST 13'th: next_state test:" << std::endl;
		NodeList list(20);
		std::cout << "The initial state of the machine: " << list;
		next_state(list);
		std::cout << std::endl;
	}
}