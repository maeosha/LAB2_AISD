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
