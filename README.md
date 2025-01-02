# Sets-and-Sorts
A generic class for implementing an array-based set in C++20, utilizing a template class with the "is_arithmetic_v" constraint to ensure only numeric types are used.

*This project's set class implements the following methods:*

- Constructors: A default constructor and a capacity constructor to initialize the set's capacity
- Destructor: Ensures memory allocated to the set is properly freed, preventing memory leaks.
- find(): Returns the index of a given element.
- insert(): Inserts and item into the set. There are two versions of this implemented. One version appends an item to the set and the other inserts at a position specified by the user.
- remove(): Removes an element provided by the user.
- removeAt(): Removes an element at a specified index.
- clear(): Clears the set, the destructor then frees the memory.
- toString(): Returns the contents of the set as a string.

*This project also includes implementations of multiple types of sorting algorithms that sort numbers given in the set:*

- bubbleSort(): A simple sort that arranges numbers by stepping through the list and swapping elements that are in the wrong order. This is repeated until the set is sorted.
- insertionSort(): A sort that iterates through the set one item at a time, comparing each item with the rest and inserting it at the correct position.
- selectionSort(): A selection sort iterates through the set to find the smallest value and swaps the lowest value to the correct spot. This is repeated until the set is sorted.
- oddEvenSort(): The OddEven sort is a sort that repeatedly makes two passes through the set. The first pass checks the even indexes, while the second checks the odds. Each pass is similar to a bubble sort, swapping values that are out of order.
- bidirectionalBubbleSort(): A modified bubble sort that iterates through the array in both directions rather than one.
- insertionSortVerbose(): An insertion sort that counts the number of copies and comparisons it makes throughout the sorting process, displaying the statistics to the user.

*Finally, this class implements other useful methods:*

- swap(): Swaps two values in the set, this method is utilized in many of the sorting algorithms.
- median(): Returns the median value of the set.

This class is tested with a variety of different numeric data types and multiple sizes of data sets, ensuring its functionality is consistent across a variety of data sets. 

This project demonstrates an understanding of C++, data structures, and algorithms.



