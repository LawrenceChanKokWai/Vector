#include<iostream>

#include "Vector.h"
#include "Utils.h"

using namespace std;

int main()
{
    Utils<unsigned> utils;
    Vector<unsigned> unsignedVec;

    unsigned expectedInitialCapacity(2);
    unsigned expectedInitialUsed(0);

    utils.Assert(
        "1. Default Constructor Test: m_capacity set to initial value of 2",
        unsignedVec.GetCapacity() == expectedInitialCapacity,
        expectedInitialCapacity, unsignedVec.GetCapacity()
    );

    utils.Assert(
        "2. Default Constructor Test: m_used set to initial value of 0",
        unsignedVec.GetUsed() == expectedInitialUsed,
        expectedInitialUsed, unsignedVec.GetUsed()
    );

    utils.Assert(
        "3. Default Constructor Test: m_array set to created dynamic address",
        unsignedVec.GetArray() != nullptr,
        "Pointer m_array is not pointing at nullptr",
        "Pointer m_array is pointing to nullptr"
    );

    return 0;
}
