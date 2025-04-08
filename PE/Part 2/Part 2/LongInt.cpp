#include "LongInt.h"

LongInt::LongInt(string num)  {
	for (int i = 0; i < num.length(); i++)
	{
		char c = num.at(i);
		m_ll.push_head(c-'0');
	}
};


std::string LongInt::to_string() const {
	std::string result;

	for (Node* node = m_ll.m_head; node != nullptr; node = node->next) {
		result = std::to_string(node->element) + result;
	}
	return result;
}
