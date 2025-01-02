#ifndef IT230_PROJECT1_MYSET_H
#define IT230_PROJECT1_MYSET_H
#include <array>
#include <stdlib.h>
#include <iostream>

namespace MySet
{
    template <typename T>
    concept Numeric = std::is_arithmetic_v<T>;

    template <typename T>
    class MySet
    {
    private:
        T* setItems = nullptr;
        size_t setSize = 0;
        size_t setCapacity = 0;

        void Swap(int index, int index2);

    public:

        MySet();

        explicit MySet(size_t capacity);

        ~MySet();

        //[] Override
        T& operator[](size_t index);

        size_t Find(const T& setItem);

        void Insert(T setItem);

        void Insert(T setItem, size_t index); //Will return an error

        bool Remove(const T& setItem);

        void RemoveAt(size_t index);

        void Clear();

        std::string ToString() const;

        void Grow();

        void Shrink();

        //Extra Methods

        size_t Median() const;

        //Sorting Methods

        void BubbleSort();

        void InsertionSort();

        void InsertionSortVerbose();

        void SelectionSort();

        void BidirectionalBubbleSort();

        void OddEvenSort();
    };
}

#endif //IT230_PROJECT1_MYSET_H
