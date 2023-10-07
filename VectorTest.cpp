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
    Vector<unsigned> overloadEqualsVector;
    otherUnsignedVector.CopyVector(unsignedVec);
    Vector<unsigned>copyConstructorVector(otherUnsignedVector);
    overloadEqualsVector = otherUnsignedVector;

    unsigned expectedInitialCapacity(2);
    unsigned actualInitialCapacity(otherUnsignedVector.GetCapacity());
    unsigned expectedCopyConstructorCapacity(copyConstructorVector.GetCapacity());
    unsigned expectedInitialUsed(0);
    unsigned actualInitialUsed(otherUnsignedVector.GetUsed());
    unsigned expectedCopyConstructorUsed(copyConstructorVector.GetUsed());

    unsigned firstValue(10);
    unsigned secondValue(20);
    unsigned thirdValue(30);
    unsigned fourthValue(40);

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

    utils.Assert(
        "9. Test Overload Equals Operator: Both dynamic array capacity should be the same as set to 2",
        copyConstructorVector.GetArray() != otherUnsignedVector.GetArray(),
        "Array pointer is not pointing at the same location",
        "Array pointer should not be pointing at the same location", ofs
    );

    utils.Assert(
        "10. Test Overload Equals Operator: Both dynamic array capacity should be the same as set to 2",
        copyConstructorVector.GetArray() != otherUnsignedVector.GetArray(),
        "Array pointer is not pointing at the same location",
        "Array pointer should not be pointing at the same location", ofs
    );

    unsignedVec.Append(firstValue);
    utils.Assert(
        "11. Test Append Member Function: Appending first value capacity as 2",
        unsignedVec.GetCapacity() == 2,
        2, unsignedVec.GetCapacity(), ofs
    );

    utils.Assert(
        "12. Test Append Member Function: Appending first value used as 1",
        unsignedVec.GetUsed() == 1,
        1, unsignedVec.GetUsed(), ofs
    );

    cout << endl;
    ofs << "Address After Appending First Number: " << unsignedVec.GetArray() << endl;
    cout << endl;

    unsignedVec.Append(secondValue);
    utils.Assert(
        "13. Test Append Member Function: Appending second value capacity as 4",
        unsignedVec.GetCapacity() == 4,
        4, unsignedVec.GetCapacity(), ofs
    );

    utils.Assert(
        "14. Test Append Member Function: Appending second value used as 2",
        unsignedVec.GetUsed() == 2,
        2, unsignedVec.GetUsed(), ofs
    );

    cout << endl;
    ofs << "Address After Appending Second Number: " << unsignedVec.GetArray() << endl;

    unsignedVec.Append(thirdValue);
    utils.Assert(
        "15. Test Append Member Function: Appending second value capacity as 8",
        unsignedVec.GetCapacity() == 8,
        8, unsignedVec.GetCapacity(), ofs
    );

    utils.Assert(
        "16. Test Append Member Function: Appending second value used as 3",
        unsignedVec.GetUsed() == 3,
        3, unsignedVec.GetUsed(), ofs
    );

    cout << endl;
    ofs << "Address After Appending Third Number: " << unsignedVec.GetArray() << endl;

    unsignedVec.Append(fourthValue);
    utils.Assert(
        "17. Test Append Member Function: Appending second value capacity as 8",
        unsignedVec.GetCapacity() == 8,
        8, unsignedVec.GetCapacity(), ofs
    );

    utils.Assert(
        "18. Test Append Member Function: Appending second value used as 4",
        unsignedVec.GetUsed() == 4,
        4, unsignedVec.GetUsed(), ofs
    );

    cout << endl;
    ofs << "Address After Appending Fourth Number: " << unsignedVec.GetArray() << endl;

    return 0;
}
