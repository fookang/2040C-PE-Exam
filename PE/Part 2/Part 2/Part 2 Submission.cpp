#include "LinkedList.h"
#include "LongInt.h"

void List::push_tail(int element) {
	if (m_size == 0) {
		m_head = new Node(element);
		m_size++;
		return;
	}
	Node* node = m_head;
	while (node->next) {
		node = node->next;
	}
	node->next = new Node(element);

	m_size++;
	// modify this function
}


LongInt::LongInt(const LongInt& num1, const LongInt& num2) {
	Node* numb1 = num1.m_ll.m_head;
	Node* numb2 = num2.m_ll.m_head;
	int remainder = 0;

	while (numb1 && numb2) {
		int number1 = numb1->element;
		int number2 = numb2->element;
		int sum = number1 + number2 + remainder;
		remainder = sum / 10;
		int value = sum % 10;
		m_ll.push_tail(value);
		numb1 = numb1->next;
		numb2 = numb2->next;
	}
	if(numb1){
		while(numb1){
			m_ll.push_tail(numb1->element + remainder);
			numb1 = numb1->next;
			remainder = 0;
		}
	 }
	if(numb2){
		while(numb2){
			m_ll.push_tail(numb2->element + remainder);
			numb2 = numb2->next;
			remainder = 0;
		}
	}
};
