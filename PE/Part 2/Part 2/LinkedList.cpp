#include "LinkedList.h"

// copy the following code to coursemology without the above line of "#include "LinkedList.h""

// Returns the value at head
int List::head() {
	// TODO: Implement this method
	return m_head->element;
}

// Checks whether the container is empty
bool List::empty() const {
	// TODO: Implement this method
	return (m_head == nullptr) ? true : false;
}

// Returns the number of elements
size_t List::size() const {
	// TODO: Implement this method
	return m_size;
}

// Inserts an element to the head
void List::push_head(int element) {
	Node* node = new Node{ element, m_head };
	m_head = node;
	m_size++;
}



// Removes the head element
int List::pop_head() {
	Node* node = m_head;
	m_head = m_head->next;
	m_size--;
	int result = node->element;
	delete node;
	return result;
}

// Checks whether the container contains the specified element
bool List::contains(int element) const {
	// TODO: Implement this method
	return 0;
}

// Returns a std::string equivalent of the container
std::string List::to_string() const {
	std::string result;
	result += "{";
	std::string separator;
	for (Node* node = m_head; node != nullptr; node = node->next) {
		result += separator + std::to_string(node->element);
		separator = ", ";
	}
	result += "}";
	return result;
}
