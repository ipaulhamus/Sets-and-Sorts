#include "mySet.h"
#include <iostream>

namespace MySet
{
    template <typename T>
    MySet<T>::MySet()
    {
        //Initializing with 4 elements if no amount is given
        setItems = new T[4];
        setCapacity = 4;
    }

    template <typename T>
    MySet<T>::MySet(size_t capacity)
    {
        setItems = new T[setCapacity];

    if(capacity == std::string::npos)
    {
        throw std::invalid_argument("Set's capacity must be greater than zero");
    }

        setCapacity = capacity;
    }

    template <typename T>
    MySet<T>::~MySet()
    {
        delete[] setItems;
    }

    //Index Override
    template <typename T>
    T& MySet<T>::operator[](size_t index)
    {
        if (index >= setSize)
        {
            throw std::range_error("Index given is out of bounds");
        }

        return setItems[index];
    }

    template <typename T>
    size_t MySet<T>::Find(const T& setItem)
    {
        for(size_t i = 0; i < this->setCapacity; ++i)
        {
            if(this->setItems[i] == setItem)
            {
                return i;
            }
        }
        return std::string::npos;
    }

    template <typename T>
    void MySet<T>::Insert(T setItem)
    {
        //Checking if the given value exists, no duplicates
        for(int i = 0; i < this->setSize; i++)
        {
            if(this->setItems[i] == setItem)
            {
                throw std::range_error("Item already exists");
            }
        }

        //Otherwise...we insert
        Insert(setItem, this->setSize);
    }

    template <typename T>
    void MySet<T>::Insert(T setItem, size_t index)
    {
        //Checking if the given value exists, no duplicates
        for(int i = 0; i < setSize; i++)
        {
            if(this->setItems[i] == setItem)
            {
                throw std::range_error("Item already exists");
            }
        }

        if(index > setSize)
        {
            throw std::range_error("The index given is out of range");
        }

        if (setSize + 1 >= setCapacity)
        {
            Grow();
        }

        for(size_t i = setCapacity - 1; i > index; --i)
        {
            setItems[i] = setItems[i - 1];
        }

        setItems[index] = setItem;

        ++setSize;
    }

    template <typename T>
    void MySet<T>::Grow()
    {

        int tempSize = setCapacity == 0 ? 1 : setCapacity * 2;

        T* tempSet = new T[tempSize];

        for(int i = 0; i < sizeof(T); ++i)
        {
            tempSet[i] = setItems[i];
        }
        delete[] setItems;
        setItems = tempSet;
        setCapacity = setCapacity == 0 ? 1 : setCapacity * 2;
    }

    template <typename T>
    void MySet<T>::Shrink()
    {
        int tempSize = setCapacity / 2;

        T* tempSet = new T[tempSize];

       for(int i = 0; i < sizeof(T); ++i)
       {
           tempSet[i] = setItems[i];
       }
       delete[] setItems;
       setItems = tempSet;
       setCapacity = setCapacity / 2;
    }

    template<typename T>
    void MySet<T>::RemoveAt(size_t index)
    {
        if(index > setSize)
        {
            throw std::range_error("The index given is out of range");
        }

        for(size_t i = index; i < setSize - 1; ++i)
        {
            setItems[i] = setItems[i + 1];
        }

        if(--setSize < setCapacity / 4)
        {
            Shrink();
        }
    }

    template <typename T>
    bool MySet<T>::Remove(const T& setItem)
    {
        size_t index = Find(setItem);
        if(index != std::string::npos)
        {
            RemoveAt(index);
            return true;
        }
        return false;
    }

    template <typename T>
    void MySet<T>::Clear()
    {
        setSize = 0;
    }

    template <typename T>
    std::string MySet<T>::ToString() const
    {
        std::string string = "";

        for(size_t i = 0; i < setSize; ++i)
        {
            string.append(std::to_string(setItems[i]));
            string.append(", ");
        }

        return string;
    }

    template <typename T>
    size_t MySet<T>::Median() const
    {
        size_t numsTotal = 0;

        if(setSize == 0)
        {
            return 0;
        }

        for(int i = 0; i <= setSize - 1; i++)
        {
            numsTotal = numsTotal + setItems[i];
        }

        return numsTotal / setSize;
    }

    template <typename T>
    void MySet<T>::Swap(int index, int index2)
    {
       T temp = setItems[index];
       setItems[index] = setItems[index2];
       setItems[index2] = temp;
    }

    template <typename T>
    void MySet<T>::BubbleSort()
    {
        bool sorted = false;
        int unsortedUntilIndex = setSize - 1;

        while(sorted == false)
        {
            sorted = true;

            for(int i = 0; i < unsortedUntilIndex; i++)
            {
                if(setItems[i] > setItems[i + 1])
                {
                    this->Swap(i, i + 1);
                    sorted = false;
                }

            }
            --unsortedUntilIndex;
        }
    }

    template <typename T>
    void MySet<T>::InsertionSort()
    {
        for(int i = 1; i < this->setSize; i++)
        {
            T temp = setItems[i];

            int j = i - 1;

            for(; j >= 0 && temp < setItems[j]; j--)
            {
                setItems[j + 1] = setItems[j];
            }

            setItems[j + 1] = temp;
        }
    }

    template <typename T>
    void MySet<T>::InsertionSortVerbose()
    {
        int copies = 0;
        int comparisons = 0;

        for(int i = 1; i < this->setSize; i++)
        {
            T temp = setItems[i];

            copies++;

            int j = i - 1;

            for(; j >= 0 && temp < setItems[j]; j--)
            {
                comparisons++;

                setItems[j + 1] = setItems[j];
            }

            setItems[j + 1] = temp;
        }

        std::cout << "Number of copies: " << copies << std::endl;
        std::cout << "Number of comparisons: " << comparisons << std::endl;
    }

    template <typename T>
    void MySet<T>::SelectionSort()
    {
        if(setSize - 1 == std::string::npos)
        {
            return;
        }

        for(int i = 0; i < setSize - 1; i++)
        {
            int minIndex = i;

            for(int j = i + 1; j < setSize; j++)
            {
                if(setItems[j] < setItems[minIndex])
                {
                    minIndex = j;
                }
            }

            if(minIndex != i)
            {
                Swap(i, minIndex);
            }
        }
    }

    template <typename T>
    void MySet<T>::BidirectionalBubbleSort()
    {
        bool sorted = false;

        int start = 0;
        int setEnd = this->setSize - 1;

        while(sorted == false)
        {
            sorted = true;

            for(int i = 0; i < setEnd; i++)
            {
                if(setItems[i] > setItems[i + 1])
                {
                    this->Swap(i, i + 1);
                    sorted = false;
                }
            }
            for(int j = setEnd; j > start; --j)
            {
                if(setItems[j] < setItems[j - 1])
                {
                    this->Swap(j, j - 1);
                    sorted = false;
                }
            }
        }
    }

    template <typename T>
    void MySet<T>::OddEvenSort()
    {
        bool sorted = false;
        int setEnd = this->setSize - 1;

        while(sorted == false)
        {
            sorted = true;

            for(int i = 1; i < setEnd; i++)
            {
                if(setItems[i] > setItems[i + 1])
                {
                    if(i % 2 == 1)
                    {
                        this->Swap(i, i + 1);
                        sorted = false;
                    }
                }
            }
            for(int j = 0; j < setEnd; j++)
            {
                if(setItems[j] > setItems[j + 1])
                {
                    if(j % 2 == 0)
                    {
                        this->Swap(j, j + 1);
                        sorted = false;
                    }
                }
            }
        }
    }

    template class MySet<int>;
    template class MySet<double>;
}
