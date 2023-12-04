#include <automat/automat.h>

Node::Node() {
	next = nullptr;
	prev = nullptr;
	cell = 0;
}

Node::Node(bool cell) {
	next = this;
	prev = this;
	this->cell = cell;
}
Node* Node::get_next() const {
	return next;
}
Node* Node::get_prev() const {
	return prev;
}
bool Node::get_cell() const {
	return cell;
}
void Node::set_next(Node* next) {
	this->next = next;
}
void Node::set_prev(Node* prev) {
	this->prev = prev;
}
void Node::set_cell(bool cell) {
	this->cell = cell;
}

NodeList::NodeList() {
	size = 0;
}

NodeList::NodeList(const size_t& size) {
	this->size = 0;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, 1);
	for (size_t index = 0; index < size; index++) {
		bool random_cell = dist(gen) % 2;
		this->push_tail(random_cell);
	}
}

NodeList::NodeList(const NodeList& _list) {
	this->size = 0;
	size_t _list_size = _list.get_size();
	for (size_t index = 0; index < _list_size; index++) {
		bool elem = _list[index];
		this->push_tail(elem);
	}
}

NodeList::~NodeList() {
	this->delete_all();
}

size_t NodeList::get_size() const {
	return size;
}

Node& NodeList::get_tail() const {
	return *tail;
}

Node& NodeList::get_head() const {
	return *head;
}

void NodeList::push_tail(const bool cell) {
	if (size == 0) {
		head = tail = new Node(cell);
		(*head).set_next(head);
		(*head).set_prev(head);
		size += 1;
	}
	else {
		Node* ptr_node = new Node(cell);
		ptr_node->set_next(head);
		ptr_node->set_prev(tail);
		(*head).set_prev(ptr_node);
		(*tail).set_next(ptr_node);
		tail = ptr_node;
		size += 1;
	}
}

void NodeList::push_tail(NodeList LinkedList) {
	for (size_t index = 0; index < LinkedList.get_size(); index++) {
		bool elem = LinkedList[index];
		this->push_tail(elem);
	}
}

void NodeList::push_head(const bool cell) {
	if (size == 0) {
		head = tail = new Node(cell);
		(*head).set_next(head);
		(*head).set_prev(head);
		size += 1;
	}
	Node* ptr_node = new Node(cell);
	ptr_node->set_next(head);
	ptr_node->set_prev(tail);
	(*head).set_prev(ptr_node);
	(*tail).set_next(ptr_node);
	head = ptr_node;
	size += 1;
}

void NodeList::push_head(NodeList LinkedList) {
	for (size_t index = LinkedList.get_size(); index > 0; index--) {
		bool elem = LinkedList[index - 1];
		this->push_head(elem);
	}
}

void NodeList::pop_head() {
	if (size == 0) {
		std::cout << "Error!";
	}
	if (size == 1) {
		delete tail;
		head = tail = nullptr;
	}
	Node* tmp_ptr = head;
	tmp_ptr = tmp_ptr->get_next();
	tmp_ptr->set_prev(tail);
	(*tail).set_next(tmp_ptr);
	delete head;
	head = tmp_ptr;
	size -= 1;
}

void NodeList::pop_tail() {
	if (size == 0) {
		std::cout << "Error!";
	}
	if (size == 1) {
		delete tail;
		head = tail = nullptr;
		size -= 1;
	}
	else {
		Node* tmp_ptr = tail;
		tmp_ptr = tmp_ptr->get_prev();
		tmp_ptr->set_next(head);
		(*head).set_prev(tmp_ptr);
		delete tail;
		tail = tmp_ptr;
		size -= 1;
	}
}

void NodeList::delete_all() {
	size_t tmp_size = size;
	for (size_t index = 0; index < tmp_size; index++) {
		this->pop_tail();
	}
}

bool NodeList::operator[](const size_t _index) const {
	Node* tmp_ptr = head;
	for (size_t index = 0; index < _index; index++) {
		tmp_ptr = tmp_ptr->get_next();
	}
	return tmp_ptr->get_cell();
}

void NodeList::add_element(size_t _index, bool cell) {
	Node* tmp_ptr = head;
	for (size_t index = 0; index < _index - 1; index++) {
		tmp_ptr = tmp_ptr->get_next();
	}
	Node* tmp_node = new Node(cell);

	tmp_node->set_next(tmp_ptr->get_next());
	tmp_node->set_prev(tmp_ptr);

	tmp_ptr->set_next(tmp_node);
	tmp_ptr = tmp_ptr->get_next();
	tmp_ptr = tmp_ptr->get_next();
	tmp_ptr->set_prev(tmp_node);
	size++;
}

void NodeList::operator=(NodeList _list) {
	this->delete_all();
	size_t _list_size = _list.get_size();
	for (size_t index = 0; index < _list_size; index++) {
		bool elem = _list[index];
		this->push_tail(elem);
	}
}