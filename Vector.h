#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

template<class T>
class Vector
{
public:
    /**
    * Default Constructor that creates a vector template T data type object with default set values:
    * Capacity set as 2,
    * Used space set as 0,
    * T data type pointer set to the new created dynamic array index 0 address int he heap memory.
    */
    Vector();

    /**
    * Destructor which deletes and deallocates the array.
    * Uses the Deallocate method function.
    */
    ~Vector();

    /**
    * Deallocates and releases the memory back to the system.
    *
    * @param The pointer that will be used to delete and release memory from.
    */
    void Deallocate(T *&ptr);

    /**
    * A Getter member function that is used to get the
    * capacity value from the private member variable m_capacity.
    *
    * @return The capacity value from m_capacity.
    */
    unsigned GetCapacity() const;

    /**
    * A Getter member function that is used to get the
    * used value from the private member variable m_used.
    *
    * @return The used value from m_used.
    */
    unsigned GetUsed() const;

    /**
    * A Getter member function that is used to get the
    * array pointer address it's pointing from the private member variable m_array.
    *
    * @return The pointer pointing address value from m_array.
    */
    T *GetArray() const;

private:
    unsigned m_capacity;
    unsigned m_used;
    T *m_array;
    const unsigned INITIAL_VALUE = 2;
};

template<class T>
Vector<T>::Vector()
{
    m_capacity = INITIAL_VALUE;
    m_used = 0;
    m_array = new T[INITIAL_VALUE];
}

template<class T>
Vector<T>::~Vector()
{
    Deallocate(m_array);
}

template<class T>
void Vector<T>::Deallocate(T *&ptr)
{
    if(ptr != nullptr)
    {
        delete [] ptr;
        ptr = nullptr;
    }
}

template<class T>
unsigned Vector<T>::GetCapacity() const
{
    return m_capacity;
}

template<class T>
unsigned Vector<T>::GetUsed() const
{
    return m_used;
}

template<class T>
T *Vector<T>::GetArray() const
{
    return m_array;
}

#endif // VECTOR_H_INCLUDED
