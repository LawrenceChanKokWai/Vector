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


private:
    unsigned m_capacity;
    unsigned m_used;
    T *m_array;
    const unsigned INITIAL_VALUE(2);
};

template<class T>
Vector<T>::Vector()
{
    m_capacity = INITIAL_VALUE;
    m_used = 0;
    m_array = new T[INITIAL_VALUE];
}

#endif // VECTOR_H_INCLUDED
