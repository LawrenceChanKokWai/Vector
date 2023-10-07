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
    * A Copy Constructor that copies other Vector to this created
    * vector during construction.
    *
    * @param otherVector This consists of the existing vector object that will be used be passed in as a parameter to the CopyVector function.
    *
    */
    Vector(const Vector &otherVector);

    /**
    * A Overload Equals Operator that copies other Vector to this created
    * vector during construction.
    *
    * @param otherVector This consists of the existing vector object that will be used be passed in as a parameter to the CopyVector function.
    *
    */
    Vector &operator = (const Vector &otherVector);

    /**
    * Destructor which deletes and deallocates the array.
    * Uses the Deallocate method function.
    */
    ~Vector();

    /**
    * Deallocates and releases the memory back to the system.
    *
    * @param ptr The pointer that will be used to delete and release memory from.
    */
    void Deallocate(T *&ptr);

    /**
    * Copy Member Function that copies the context to another Vector
    *
    * @param otherVector The existing containing vector to be copied from
    */
    void CopyVector(const Vector &otherVector);

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

    /**
    * Resize Member function that creates a new dynamic array and copies the
    * existing dynamic array elements into the newly created array.
    * Deletes and set nullptr of existing array pointer.
    * Copies new dynamic array element, deletes created array and set nullptr.
    */
    void Resize();

    /**
    * This member function appends the value to the end of the dynamic array.
    * Checks condition if used slot is half of the capacity, doubles the capacity id so.
    * Resize when condition meets.
    *
    * @param object The Object of the value used to be appending to the vector
    * @return Boolean true when value appended else false
    */
    bool Append(T &object);

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
Vector<T>::Vector(const Vector &otherVector)
{
    CopyVector(otherVector);
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

template<class T>
void Vector<T>::CopyVector(const Vector &otherVector)
{
    m_capacity = otherVector.m_capacity;
    m_used = otherVector.m_used;
    m_array = new T[otherVector.m_capacity];

    for(unsigned i(0); i < m_used; i++)
    {
        m_array[i] = otherVector.m_array[i];
    }
}

template<class T>
Vector<T> &Vector<T>::operator = (const Vector &otherVector)
{
    if(this != &otherVector)
    {
        CopyVector(otherVector);
    }
    return *this;
}

template<class T>
void Vector<T>::Resize()
{
    unsigned newCapacity= m_capacity * 2;
    T *newArray = new T[newCapacity];
    if(newCapacity > m_capacity)
    {
        for(unsigned i(0); i < m_used; i++)
        {
            newArray[i] = m_array[i];
        }
        Deallocate(m_array);

        m_array = new T[newCapacity];
        for(unsigned i(0); i < m_used; i++)
        {
            m_array[i] = newArray[i];
        }
        Deallocate(newArray);
    }
    m_capacity = newCapacity;
}

template<class T>
bool Vector<T>::Append(T &object)
{
    if(m_used == m_capacity / 2)
    {
        Resize();
    }
    m_array[m_used] = object;
    m_used ++;
    return true;
}

#endif // VECTOR_H_INCLUDED
