

#include "LinkedList.h"
#include <iostream>
#include <string>

using namespace std;

class LongInt {
private:
    List m_ll;
public:
    LongInt(string);
    LongInt(const LongInt&,const LongInt&); // add up the two inputs
    void showList() { cout << m_ll.to_string() << endl; };
    // Converts the container to std::string
    std::string to_string() const;
};

