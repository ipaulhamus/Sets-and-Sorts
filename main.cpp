/*
 * Name: [Ian Paulhamus]
 * South Hills Username: [ipaulhamus61]
 */

#include <iostream>
#include <cstdlib>
#include "mySet.h"

void testSet();
void testOneElementSet();
void testEmptySet();
void testDifferentFormat();

int main()
{
    testSet();
    testOneElementSet();
    testEmptySet();
    testDifferentFormat();

    return 0;
}

void testSet()
{
    MySet::MySet<int> mySet;

    mySet.Insert(16);
    mySet.Insert(23);
    mySet.Insert(5);
    mySet.Insert(67);
    mySet.Insert(44);
    mySet.Insert(90);

    //Testing "No Duplicate Values" Restriction (Uncommenting Will Return an Error)
    //mySet.Insert(90);

    std::cout << "--- Regular Set ---" << std::endl;

    std::cout << "Set after insert: " << mySet.ToString() << std::endl;

    std::cout << "Searching for index of '16' in set: " << mySet.Find(16) << std::endl;

    mySet.Remove(23);

    std::cout << "Removing '23' value from set: " << mySet.ToString() << std::endl;

    std::cout << "The set median value: " << mySet.Median() << std::endl;

    mySet.BubbleSort();

    std::cout << "Bubble sorted: " << mySet.ToString() << std::endl;

    mySet.Clear();

    mySet.Insert(16);
    mySet.Insert(5);
    mySet.Insert(67);
    mySet.Insert(44);
    mySet.Insert(90);

    std::cout << "Set re-scrambled: " << mySet.ToString() << std::endl;

    mySet.InsertionSort();

    std::cout << "Insertion sorted: " << mySet.ToString() << std::endl;

    mySet.Clear();

    mySet.Insert(16);
    mySet.Insert(5);
    mySet.Insert(67);
    mySet.Insert(44);
    mySet.Insert(90);

    std::cout << "Set re-scrambled: " << mySet.ToString() << std::endl;

    mySet.SelectionSort();

    std::cout << "Selection sorted: " << mySet.ToString() << std::endl;

    mySet.Clear();

    mySet.Insert(16);
    mySet.Insert(5);
    mySet.Insert(67);
    mySet.Insert(44);
    mySet.Insert(90);

    std::cout << "Set re-scrambled: " << mySet.ToString() << std::endl;

    mySet.InsertionSortVerbose();

    std::cout << "Insertion sorted (verbose): " << mySet.ToString() << std::endl;

    mySet.Clear();

    mySet.Insert(16);
    mySet.Insert(5);
    mySet.Insert(67);
    mySet.Insert(44);
    mySet.Insert(90);

    std::cout << "Set re-scrambled: " << mySet.ToString() << std::endl;

    mySet.BidirectionalBubbleSort();

    std::cout << "Bidirectional bubble sorted: " << mySet.ToString() << std::endl;

    mySet.Clear();

    //Testing insert through an index as well
    mySet.Insert(16, 0);
    mySet.Insert(5, 0);
    mySet.Insert(67, 0);
    mySet.Insert(44, 0);
    mySet.Insert(90, 0);

    std::cout << "Set re-scrambled: " << mySet.ToString() << std::endl;

    mySet.OddEvenSort();

    std::cout << "OddEven sorted: " << mySet.ToString() << std::endl;

    std::cout << "--Set Complete!--" << std::endl;
}

void testOneElementSet()
{
    MySet::MySet<int> oneElementSet;
    oneElementSet.Insert(12);

    //One Element Set

    std::cout << "\n---- One Element Set ----" << std::endl;

    std::cout << "Single element List: " << oneElementSet.ToString() << std::endl;

    std::cout << "Single element finding index of '12': " << oneElementSet.Find(12) << std::endl;

    std::cout << "Single element delete: " << std::endl;

    oneElementSet.Remove(12);

    std::cout << "Deleted element: " << oneElementSet.ToString() << std::endl;

    oneElementSet.Insert(25);

    std::cout << "New Element: " << oneElementSet.ToString() << std::endl;

    std::cout << "Single element median: " << oneElementSet.Median() << std::endl;

    oneElementSet.BubbleSort();

    std::cout << "Bubble sorted: " << oneElementSet.ToString() << std::endl;

    oneElementSet.InsertionSort();

    std::cout << "Insertion sorted: " << oneElementSet.ToString() << std::endl;

    oneElementSet.SelectionSort();

    std::cout << "Selection sorted: " << oneElementSet.ToString() << std::endl;

    oneElementSet.InsertionSortVerbose();

    std::cout << "Insertion sorted (verbose): " << oneElementSet.ToString() << std::endl;

    oneElementSet.BidirectionalBubbleSort();

    std::cout << "Bidirectional bubble sorted: " << oneElementSet.ToString() << std::endl;

    oneElementSet.OddEvenSort();

    std::cout << "Odd even sorted: " << oneElementSet.ToString() << std::endl;

    std::cout << "--Set Complete!--" << std::endl;
}

void testEmptySet()
{
    MySet::MySet<int> emptySet;

    //Empty Set

    std::cout << "\n---- Empty Set ----" << std::endl;

    std::cout << "Empty List: " << emptySet.ToString() << std::endl;

    std::cout << "Empty median: " << emptySet.Median() << std::endl;

    emptySet.BubbleSort();

    std::cout << "Bubble sorted: " << emptySet.ToString() << std::endl;

    emptySet.InsertionSort();

    std::cout << "Insertion sorted: " << emptySet.ToString() << std::endl;

    emptySet.SelectionSort();

    std::cout << "Selection sorted: " << emptySet.ToString() << std::endl;

    emptySet.InsertionSortVerbose();

    std::cout << "Insertion sorted (verbose): " << emptySet.ToString() << std::endl;

    emptySet.BidirectionalBubbleSort();

    std::cout << "Bidirectional bubble sorted: " << emptySet.ToString() << std::endl;

    emptySet.OddEvenSort();

    std::cout << "Odd even sorted: " << emptySet.ToString() << std::endl;

    std::cout << "--Set Complete!--" << std::endl;
}

void testDifferentFormat()
{
     MySet::MySet<double> mySet;

    mySet.Insert(18.545);
    mySet.Insert(2.102);
    mySet.Insert(79.764);
    mySet.Insert(52.444);
    mySet.Insert(154.909);
    mySet.Insert(23.342);

    //Testing "No Duplicate Values" Restriction (Uncommenting Will Return an Error)
    //mySet.Insert(23.342);

    std::cout << "\n--- Decimal Set ---" << std::endl;

    std::cout << "Set after insert: " << mySet.ToString() << std::endl;

    std::cout << "Searching for index of '23.342' in set: " << mySet.Find(23.342) << std::endl;

    mySet.Remove(23.342);

    std::cout << "Removing '23.342' value from set: " << mySet.ToString() << std::endl;

    std::cout << "The set median value: " << mySet.Median() << std::endl;

    mySet.BubbleSort();

    std::cout << "Bubble sorted: " << mySet.ToString() << std::endl;

    mySet.Clear();

    mySet.Insert(18.545);
    mySet.Insert(2.102);
    mySet.Insert(79.764);
    mySet.Insert(52.444);
    mySet.Insert(154.909);

    std::cout << "Set re-scrambled: " << mySet.ToString() << std::endl;

    mySet.InsertionSort();

    std::cout << "Insertion sorted: " << mySet.ToString() << std::endl;

    mySet.Clear();

    mySet.Insert(18.545);
    mySet.Insert(2.102);
    mySet.Insert(79.764);
    mySet.Insert(52.444);
    mySet.Insert(154.909);

    std::cout << "Set re-scrambled: " << mySet.ToString() << std::endl;

    mySet.SelectionSort();

    std::cout << "Selection sorted: " << mySet.ToString() << std::endl;

    mySet.Clear();

    mySet.Insert(18.545);
    mySet.Insert(2.102);
    mySet.Insert(79.764);
    mySet.Insert(52.444);
    mySet.Insert(154.909);

    std::cout << "Set re-scrambled: " << mySet.ToString() << std::endl;

    mySet.InsertionSortVerbose();

    std::cout << "Insertion sorted (verbose): " << mySet.ToString() << std::endl;

    mySet.Clear();

    mySet.Insert(18.545);
    mySet.Insert(2.102);
    mySet.Insert(79.764);
    mySet.Insert(52.444);
    mySet.Insert(154.909);

    std::cout << "Set re-scrambled: " << mySet.ToString() << std::endl;

    mySet.BidirectionalBubbleSort();

    std::cout << "Bidirectional bubble sorted: " << mySet.ToString() << std::endl;

    mySet.Clear();

    mySet.Insert(18.545);
    mySet.Insert(2.102);
    mySet.Insert(79.764);
    mySet.Insert(52.444);
    mySet.Insert(154.909);

    std::cout << "Set re-scrambled: " << mySet.ToString() << std::endl;

    mySet.OddEvenSort();

    std::cout << "OddEven sorted: " << mySet.ToString() << std::endl;

    std::cout << "--Set Complete!--" << std::endl;
}