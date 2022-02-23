#pragma once
#include <exception>

template <typename T>
class DynamicArray
{
public:
    DynamicArray();
    ~DynamicArray();

    /// <summary>
    /// Adds an actor to the end of the array
    /// </summary>
    /// <param name="actor">The new actor to add to the array</param>
    void addItem(T item);

    /// <summary>
    /// Adds an actor to the end of the array
    /// </summary>
    /// <param name="actor">The new actor to add to the array</param>
    void addItems(T item[], int size);

    /// <summary>
    /// Removes the actor from the array
    /// </summary>
    /// <param name="actor">The actor to remove</param>
    /// <returns>False if the actor is not in the array</returns>
    bool removeItem(T item);

    bool removeItem(int index);

    /// <summary>
    /// Sorts all the items in the item array
    /// </summary>
    void sortItems();

    /// <summary>
    /// Gets the item in the index
    /// </summary>
    T getItem(int index);

    /// <summary>
    /// finds the lengths of the items
    /// </summary>
    int getLength();

    /// <summary>
    /// Checks if the actor is in the array
    /// </summary>
    /// <param name="actor">A reference to the actor to use to check</param>
    /// <returns>False if the actor is not in the array</returns>
    bool contains(T actor);

    T operator[](int index);
    

private:
    T* m_item;
    int m_length;

};

template<typename T>
inline DynamicArray<T>::DynamicArray()
{
    m_length = 0;
    m_item = nullptr;
}

template<typename T>
inline DynamicArray<T>::~DynamicArray()
{

}

template<typename T>
inline void DynamicArray<T>::addItem(T item)
{
    T* tempArray = new T[getLength() + 1];
    //Copy the values from the old array to the new array
    for (int i = 0; i < getLength(); i++)
    {
        tempArray[i] = m_item[i];
    }

    //Set the last value in the new array to be the actor we want to add
    tempArray[getLength()] = item;

    delete[] m_item;

    //Set old array to hold the values of the new array
    m_item = tempArray;
    m_length++;
}

template<typename T>
inline void DynamicArray<T>::addItems(T item[], int size)
{
    for (int i = 0; i < size; i++)
        addItem(item[i]);
}

template<typename T>
inline bool DynamicArray<T>::removeItem(T item)
{
    //Check to see if the actor was null
    if (!item || getLength() <= 0)
        return false;

    bool itemRemoved = false;
    //Create a new array with a size one less than our old array
    T* tempArray = new T[getLength() - 1];
    //Create variable to access tempArray index
    int j = 0;
    //Copy values from the old array to the new array
    for (int i = 0; i < getLength(); i++)
    {
        if (item != m_item[i] || itemRemoved)
        {
            tempArray[j] = m_item[i];
            j++;
        }
        else
        {
            itemRemoved = true;
        }
    }

    //Set the old array to the new array
    if (itemRemoved)
    {
        delete[] m_item;
        m_item = tempArray;
        m_length--;
    }
    //Return whether or not the removal was successful
    return itemRemoved;
}

template<typename T>
inline bool DynamicArray<T>::removeItem(int index)
{
    //Check to see if the actor was null
    if (!index || getLength() <= 0)
        return false;

    bool itemRemoved = false;
    //Create a new array with a size one less than our old array
    T* tempArray = new T[getLength() - 1];
    //Create variable to access tempArray index
    int j = 0;
    //Copy values from the old array to the new array
    for (int i = 0; i < getLength(); i++)
    {
        if (index = m_item[i] || itemRemoved)
        {
            tempArray[j] = m_item[i];
            j++;
        }
        else
        {
            itemRemoved = true;
        }
    }

    //Set the old array to the new array
    if (itemRemoved)
    {
        delete[] m_item;
        m_item = tempArray;
        m_length--;
    }
    //Return whether or not the removal was successful
    return itemRemoved;
}

template<typename T>
inline void DynamicArray<T>::sortItems()
{
    int j = 0;
    T key;

    for (int i = 1; i < getLength(); i++)
    {
        key = m_item[i];
        j = i - 1;

        while (j >= 0 && m_item[j] > key)
        {
            m_item[j + 1] = m_item[j];
            j--;
        }

        m_item[j + 1] = key;
    }
}

template<typename T>
inline T DynamicArray<T>::getItem(int index)
{
    //Return false if the index is out of bounds
    if (index < 0 || index >= getLength())
        return T();

    return m_item[index];
}

template<typename T>
inline int DynamicArray<T>::getLength()
{
    return m_length;
}

template<typename T>
inline bool DynamicArray<T>::contains(T actor)
{
    //Iterate through actor array
    for (int i = 0; i < m_length; i++)
    {
        //return the current actor if it matches the argument
        if (m_item[i] == actor)
            return true;
    }

    return false;
}

template<typename T>
inline T DynamicArray<T>::operator[](int index)
{
    //Return false if the index is out of bounds
    if (index > 0 || index < getLength())
        return m_item[index];

    throw std::exception("Index was outside the bounds of the array.");
}

