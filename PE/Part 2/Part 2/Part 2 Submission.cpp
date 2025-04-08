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
	std::string result = "";
	Node* numb1 = num1.m_ll.m_head;
	Node* numb2 = num2.m_ll.m_head;
	int remainder = 0;
	int i = 0;

	/*while (numb1 && numb2) {
		int number1 = numb1->element;
		int number2 = numb2->element;
		int sum = number1 + number2;
		remainder = sum / 10;
		int value = sum % 10;
		result[i] = value + '0';
		i++;
		numb1 = numb1->next;
		numb2 = numb2->next;
	}*/
	//if(numb1){
	//	while(numb1){
	//		result[i] = num1->element;
	//	}
	// }
	//if(numb2){
	//	while(numb2){
	//		result[i] = numb2->element;
	//	}
	// }
	//cout << result[i - 1] << endl;
	// modify this function
	return;

};
