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
    void Assert(string titleOfTest, bool condition, T expected, T actual, ostream &output);

    /**
    * Member function override that is  used in asserting the result of a particular test.
    *
    * @param titleOfTest The test title description the test we are testing
    * @param condition The condition assertion we are testing
    * @param passMessage The pass message that we provide
    * @param failMessage The fail message that we provide
    */
    void Assert(string titleOfTest, bool condition, string passMessage, string failMessage, ostream &output);
};

template<class T>
void Utils<T>::Assert(string titleOfTest, bool condition, T expected, T actual, ostream &output)
{
    cout << titleOfTest << endl;
    output << titleOfTest << endl;
    if(condition)
    {
        cout << "[PASS]: " << "Expected: " << expected << " | Actual: " << actual  << endl << '\n';
        output << "[PASS]: " << "Expected: " << expected << " | Actual: " << actual  << endl << '\n';
    }
    else
    {
        cout << "[FAIL]: " << "Expected: " << expected << " | Actual: " << actual  << endl << '\n';
        output << "[FAIL]: " << "Expected: " << expected << " | Actual: " << actual  << endl << '\n';
    }
}

template<class T>
void Utils<T>::Assert(string titleOfTest, bool condition, string passMessage, string failMessage, ostream &output)
{
    cout << titleOfTest << endl;
    output << titleOfTest << endl;

    if(condition)
    {
        cout << "[PASS]: " << passMessage <<  endl << '\n';
        output << "[PASS]: " << passMessage <<  endl << '\n';
    }
    else
    {
        cout << "[FAIL]: " << failMessage <<  endl << '\n';
        output << "[FAIL]: " << failMessage <<  endl << '\n';
    }
}

#endif // UTILS_H_INCLUDED
