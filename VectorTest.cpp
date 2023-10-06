#include<iostream>
#include<fstream>

#include "Vector.h"
#include "Utils.h"

using namespace std;

int main()
{
    Utils<unsigned> utils;
    ofstream ofs("TestReports/VectorTest.txt");
    Vector<unsigned> unsignedVec;
    Vector<unsigned> otherUnsignedVector;
    otherUnsignedVector.CopyVector(unsignedVec);
    Vector<unsigned>copyConstructorVector(otherUnsignedVector);

    unsigned expectedInitialCapacity(2);
    unsigned actualInitialCapacity(otherUnsignedVector.GetCapacity());
    unsigned expectedCopyConstructorCapacity(copyConstructorVector.GetCapacity());
    unsigned expectedInitialUsed(0);
    unsigned actualInitialUsed(otherUnsignedVector.GetUsed());
    unsigned expectedCopyConstructorUsed(copyConstructorVector.GetUsed());

    utils.Assert(
        "1. Default Constructor Test: m_capacity set to initial value of 2",
        unsignedVec.GetCapacity() == expectedInitialCapacity,
        expectedInitialCapacity, unsignedVec.GetCapacity(),ofs
    );

    utils.Assert(
        "2. Default Constructor Test: m_used set to initial value of 0",
        unsignedVec.GetUsed() == expectedInitialUsed,
        expectedInitialUsed, unsignedVec.GetUsed(), ofs
    );

    utils.Assert(
        "3. Default Constructor Test: m_array set to created dynamic address",
        unsignedVec.GetArray() != nullptr,
        "Pointer m_array is not pointing at nullptr",
        "Pointer m_array is pointing to nullptr", ofs
    );

    utils.Assert(
        "4. Test Copy Member Function: Both dynamic array should have the same m_capacity",
        unsignedVec.GetCapacity() == otherUnsignedVector.GetCapacity(),
        expectedInitialCapacity, actualInitialCapacity, ofs
    );

    utils.Assert(
        "5. Test Copy Member Function: Both dynamic array should have the same m_used",
        unsignedVec.GetUsed() == otherUnsignedVector.GetUsed(),
        expectedInitialUsed, actualInitialUsed, ofs
    );

    utils.Assert(
        "6. Test Copy Member Function: Both dynamic array pointer should not point at the same pointer address",
        unsignedVec.GetArray() != otherUnsignedVector.GetArray(),
        "Pointer array pointer is not pointing at the same address",
        "Pointer array pointer should not be pointing at the same address", ofs
    );

    utils.Assert(
        "7. Test Copy Constructor: Both dynamic array capacity should be the same as set to 2",
        copyConstructorVector.GetCapacity() == otherUnsignedVector.GetCapacity(),
        2, expectedCopyConstructorCapacity, ofs
    );

    utils.Assert(
        "8. Test Copy Constructor: Both dynamic array used should be the same as set to 0",
        copyConstructorVector.GetUsed() == otherUnsignedVector.GetUsed(),
        0, expectedCopyConstructorUsed, ofs
    );

    utils.Assert(
        "9. Test Copy Constructor: Both dynamic array pointer should be pointing at the same location",
        copyConstructorVector.GetArray() != otherUnsignedVector.GetArray(),
        "Array pointer is not pointing at the same location",
        "Array pointer should not be pointing at the same location", ofs
    );

    return 0;
}
