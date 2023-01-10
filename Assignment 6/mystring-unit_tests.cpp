#define BOOST_TEST_MODULE mystring_unit_test
#include <boost/test/unit_test.hpp>
#include "mystring.h"
using namespace stringexercise;

BOOST_AUTO_TEST_CASE(mystring_test)
{
    /**
     * @brief Checking the empty constructor
     *
     */
    mystring emptyCtorTest;
    BOOST_CHECK_EQUAL(emptyCtorTest.length(), 0);
    BOOST_CHECK_EQUAL(emptyCtorTest.is_empty(), 1);

    /**
     * @brief Checking the C string constructor
     *
     */
    mystring cStringCtor("C String");
    BOOST_CHECK_EQUAL(cStringCtor.length(), 8);
    BOOST_CHECK_EQUAL(cStringCtor, "C String");

    /**
     * @brief Checking the copy constructor
     *
     */
    mystring parameter("mystringCtor");
    mystring mystringCtor(parameter);
    BOOST_CHECK_EQUAL(mystringCtor.length(), 12);
    BOOST_CHECK_EQUAL(mystringCtor, "mystringCtor");

    /**
     * @brief Checking the += operator with mystring
     *
     */
    mystring mystringParam("Mystring");
    mystring plusEqualMystring("plusEquall");
    BOOST_CHECK_EQUAL((plusEqualMystring += mystringParam), "plusEquallMystring");

    /**
     * @brief Checking the += operator with C String
     *
     */
    mystring plusEqualMystringWithCString("plusEquall");
    BOOST_CHECK_EQUAL((plusEqualMystringWithCString += "CString"), "plusEquallCString");

    /**
     * @brief Checking the += operator with char
     *
     */
    mystring plusEqualMystringWithChar("plusEquall");
    BOOST_CHECK_EQUAL((plusEqualMystringWithChar += 'C'), "plusEquallC");

    /**
     * @brief Checking the = operator with mystring
     *
     */
    mystring rightOperand("right operand");
    mystring leftOperand;
    leftOperand = rightOperand;
    BOOST_CHECK_EQUAL(leftOperand, "right operand");

    /**
     * @brief Checking the square bracket operator []
     *
     */
    mystring squareBracketOp("[]");
    BOOST_CHECK_EQUAL(squareBracketOp[0], '[');

    /**
     * @brief Checking the swap function
     *
     */
    mystring swapLeft("swapLeft");
    mystring swapright("swapRight");
    swapLeft.swap(swapright);
    BOOST_CHECK_EQUAL(swapLeft, "swapRight");
    BOOST_CHECK_EQUAL(swapright, "swapLeft");

    /**
     * @brief Checking the == operator with C string
     *
     */
    mystring equalOperatorWithCString("equal operator");
    BOOST_CHECK_EQUAL(equalOperatorWithCString, "equal operator");

    /**
     * @brief Checking the == operator with mystring
     *
     */
    mystring myStringEqualParam("equal operator");
    mystring equalOperatorWithMyString("equal operator");
    BOOST_CHECK_EQUAL(equalOperatorWithCString, myStringEqualParam);

     /**
     * @brief Checking the != operator with mystring
     *
     */
    mystring myStringNotEqualParam("not equal operator differnt");
    mystring notEqualOperatorWithMyString("not equal operator");
    BOOST_CHECK(notEqualOperatorWithMyString != myStringNotEqualParam);

     /**
     * @brief Checking the >= operator with mystring
     *
     */
    mystring myStringGreaterEqualParam("greater equal operator");
    mystring greaterEqualOperatorWithMyString("greater equal operator");
    BOOST_CHECK(myStringGreaterEqualParam >= greaterEqualOperatorWithMyString);


    /**
     * @brief Checking the <= operator with mystring
     *
     */
    mystring myStringSmallerEqualParam("smaller equal operator");
    mystring smallerEqualOperatorWithMyString("smaller equal operator");
    BOOST_CHECK(smallerEqualOperatorWithMyString <= myStringSmallerEqualParam);

    /**
     * @brief Checking the > operator with mystring
     *
     */
    mystring myStringGreaterOperatorParam("a");
    mystring greaterOperatorWithMystring("b");
    BOOST_CHECK(greaterOperatorWithMystring > myStringGreaterOperatorParam);

    /**
     * @brief Checking the < operator with mystring
     *
     */
    mystring myStringSmallerOperatorParam("b");
    mystring smallerOperatorWithMystring("a");
    BOOST_CHECK(smallerOperatorWithMystring < myStringSmallerOperatorParam);
}