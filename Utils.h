#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include<string>

using namespace std;

/**
* Class used for testing purposes only
*/
template<class T>
class Utils
{
public:
    /**
    * Member function that is  used in asserting the result of a particular test.
    *
    * @param titleOfTest The test title description the test we are testing
    * @param condition The condition assertion we are testing
    * @param expected The expected value
    * @param actual The actual value returned from the the test
    */
    void Assert(string titleOfTest, bool condition, T expected, T actual);

    /**
    * Member function override that is  used in asserting the result of a particular test.
    *
    * @param titleOfTest The test title description the test we are testing
    * @param condition The condition assertion we are testing
    * @param passMessage The pass message that we provide
    * @param failMessage The fail message that we provide
    */
    void Assert(string titleOfTest, bool condition, string passMessage, string failMessage);
};

template<class T>
void Utils<T>::Assert(string titleOfTest, bool condition, T expected, T actual)
{
    cout << titleOfTest << endl;
    if(condition)
    {
        cout << "[PASS]: " << "Expected: " << expected << " | Actual: " << actual  << endl;
    }
    else
    {
        cout << "[FAIL]: " << "Expected: " << expected << " | Actual: " << actual  << endl;
    }
}

template<class T>
void Utils<T>::Assert(string titleOfTest, bool condition, string passMessage, string failMessage)
{
    cout << titleOfTest << endl;
    if(condition)
    {
        cout << "[PASS]: " << passMessage <<  endl;
    }
    else
    {
        cout << "[FAIL]: " << failMessage <<  endl;
    }
}

#endif // UTILS_H_INCLUDED
