#include <iostream>
#include <random>
#include <ctime>


class Node {
private:
	Node* next;
	Node* prev;
	bool cell;
public:
	Node();
	Node(bool cell);

	Node* get_next() const;
	Node* get_prev() const;
	bool get_cell() const;

	void set_next(Node* next);
	void set_prev(Node* prev);
	void set_cell(bool cell);
};

class NodeList {
private:
	Node* head = nullptr;
	Node* tail = nullptr;
	size_t size;
public:
	NodeList();
	NodeList(const size_t& size);
	NodeList(const NodeList& _list);

	~NodeList();

	size_t get_size() const;

	Node& get_tail() const;

	Node& get_head() const;

	void push_tail(const bool cell);
	void push_tail(NodeList LinkedList);

	void push_head(const bool cell);
	void push_head(NodeList LinkedList);

	void pop_head();
	void pop_tail();
	void delete_all();

	void operator=(NodeList _list);
	bool operator[](const size_t _index) const;

	void add_element(size_t _index, const bool cell);
};

std::ostream& operator<<(std::ostream& stream, const NodeList& _list);

bool push_automat_elem(const NodeList& _list, size_t index, int key);
NodeList next_state(NodeList& init_state);