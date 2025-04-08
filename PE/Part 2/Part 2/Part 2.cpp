// CS2040C Assignment 1 Linked List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "LinkedList.h"
#include "LongInt.h"

void push_tail_test1();
void push_tail_test2();
void LongInt_test();
void LongInt_test0();
void LongInt_test1();
void LongInt_test2();

int main()
{

    
    push_tail_test1();
    push_tail_test2();
    
    
    cout << "Using normal C++ integer" << endl;
    unsigned long long x = 12345678901234567890;
    // largest integer: 18,446,744,073,709,551,615 (18446744073709551615)
    
    cout << "If x = " << x << endl;
    cout << "Then C++ will computer x+x = " << x + x << endl << endl;;

    
    cout << "The number 12345 will be stored in a linked list as:" << endl;
    LongInt li("12345");
    li.showList();
    
    LongInt_test();
    LongInt_test0();
    LongInt_test1();
    LongInt_test2();

    // you should write more test cases for yourself
    
}

void push_tail_test1()
{

    std::cout << "push_tail_test1()" << std::endl;
    //int vec[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3 };
    //int vecSize = 16;

    List list;
    for (int i = 0; i < 20;i++) {
            list.push_tail(i);
    }

    std::cout << list.to_string() << std::endl  << endl;
    /* Should print out:
     {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19}
    */
}

void push_tail_test2()
{

    std::cout << "push_tail_test2()" << std::endl;
    //int vec[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3 };
    //int vecSize = 16;

    List list;
    for (int i = 0; i < 20;i++) {
        if (i % 2)
            list.push_head(i);
        else
            list.push_tail(i);
    }

    std::cout << list.to_string() << std::endl  << endl;
    /* Should print out:
    {19, 17, 15, 13, 11, 9, 7, 5, 3, 1, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18}
    */
}


void LongInt_test0()
{
    std::cout << "LongInt_test1()" << std::endl;
    LongInt LI1("12345678901234567890");
    LongInt LI2("12345678901234567890");
    LongInt LI3(LI1, LI2);
    cout << "The two numbers are " << LI1.to_string() << " and " << LI2.to_string() << endl;
    cout << "And their sum is: " << LI3.to_string() << endl << endl;
    // should be 24691357802469135780
    
}
 
void LongInt_test()
{
    std::cout << "LongInt_test()" << std::endl;
    LongInt LI1("12");
    LongInt LI2("33");
    LongInt LI3(LI1, LI2);
    cout << "The two numbers are " << LI1.to_string() << " and " << LI2.to_string() << endl;
    cout << "And their sum is: " << LI3.to_string() << endl << endl;
    LongInt LI4(LI3,LI2);
    cout << "The two numbers are " << LI3.to_string() << " and " << LI2.to_string() << endl;
    cout << "And their sum is: " << LI4.to_string() << endl << endl;
    // should be 11188892
    
}

void LongInt_test1()
{
    std::cout << "LongInt_test1()" << std::endl;
    LongInt LI1("12349");
    LongInt LI2("11176543");
    LongInt LI3(LI1, LI2);
    cout << "The two numbers are " << LI1.to_string() << " and " << LI2.to_string() << endl;
    cout << "And their sum is: " << LI3.to_string() << endl << endl;
    // should be 11188892
    
}
 
void LongInt_test2()
{
    std::cout << "LongInt_test2()" << std::endl;
    LongInt LI1("229057298502835759606209");
    LongInt LI2("12304980758064686720460453374");
    LongInt LI3(LI1, LI2);
    cout << "The two numbers are " << LI1.to_string() << " and " << LI2.to_string() << endl;
    cout << "And their sum is: " << LI3.to_string()  << endl << endl;
    // should be "12305209815363189556220059583"
}

