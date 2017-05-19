#include <process.h>
#include <ctest.h>

CTEST(return_datype_valid_test, correct_int)
{
    const char *str = "int";

    const int result = return_datype_valid(str);

	const int expected = 0;
    ASSERT_EQUAL(expected, result); 
}

CTEST(return_datype_valid_test, correct_char)
{
    const char *str = "char";

    const int result = return_datype_valid(str);

	const int expected = 0;
    ASSERT_EQUAL(expected, result); 
}

CTEST(return_datype_valid_test, correct_float)
{
    const char *str = "float";

    const int result = return_datype_valid(str);

	const int expected = 0;
    ASSERT_EQUAL(expected, result); 
}

CTEST(return_datype_valid_test, correct_double)
{
    const char *str = "double";

    const int result = return_datype_valid(str);

	const int expected = 0;
    ASSERT_EQUAL(expected, result); 
}

CTEST(return_datype_valid_test, correct_void)
{
    const char *str = "void";

    const int result = return_datype_valid(str);

	const int expected = 0;
    ASSERT_EQUAL(expected, result); 
}

CTEST(return_datype_valid_test, incorrect_example_one)
{
    const char *str = "doubledou";

    const int result = return_datype_valid(str);

	const int expected = -1;
    ASSERT_EQUAL(expected, result); 
}

CTEST(return_datype_valid_test, incorrect_example_sec)
{
    const char *str = "voidfe";

    const int result = return_datype_valid(str);

	const int expected = -1;
    ASSERT_EQUAL(expected, result); 
}