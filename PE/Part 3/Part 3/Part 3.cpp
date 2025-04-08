// Assignment 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Part 3 Submission.hpp"

void tree_parent_test();
void tree_removal_test1();
void tree_removal_test2();
void tree_removal_test3();

int main()
{


    tree_parent_test();
    tree_removal_test1();
    tree_removal_test2();
    tree_removal_test3();
}

void tree_parent_test()
{

    std::cout << "Tree parent test" << std::endl;

    Tree<int> tree;
    tree.insert(2);
    tree.insert(4);
    tree.insert(1);
    tree.insert(0);
    tree.insert(3);
    std::cout << tree.to_string() << std::endl;

    int arr[] = { 0,1,3,4,2 };
    for (int i = 0; i < 5; i++)
        std::cout << tree.parent(arr[i]) << " is the parent of " << arr[i] << std::endl;
    std::cout << std::endl;

}

void tree_removal_test1()
{
std::cout << "Tree removal test " << std::endl;
    Tree<int> tree;
    tree.insert(2);
    tree.insert(4);
    tree.insert(1);
    tree.insert(0);
    tree.insert(3);

    int arr2[] = { 0,3,1,4 };
    for (int i = 0; i < 4; i++)
    {
        std::cout << "Removing " << arr2[i] << std::endl;
        tree.remove(arr2[i]);
        std::cout << tree.to_string() << std::endl;
    }

    std::cout << std::endl;
}

void tree_removal_test2()
{
std::cout << "Tree removal test " << std::endl;
    Tree<int> tree;
    tree.insert(2);
    tree.insert(4);
    tree.insert(1);
    tree.insert(0);
    tree.insert(3);

    int arr2[] = { 4, 1 };
    for (int i = 0; i < 2; i++)
    {
        std::cout << "Removing " << arr2[i] << std::endl;
        tree.remove(arr2[i]);
        std::cout << tree.to_string() << std::endl;
    }
    std::cout << std::endl;
}

void tree_removal_test3()
{
std::cout << "Tree removal test " << std::endl;
    Tree<int> tree;
    tree.insert(2);
    tree.insert(4);
    tree.insert(1);
    tree.insert(0);
    tree.insert(3);

    int arr2[] = { 1,3,4,0,2 };
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Removing " << arr2[i] << std::endl;
        tree.remove(arr2[i]);
        std::cout << tree.to_string() << std::endl;
    }
    std::cout << std::endl;
}

