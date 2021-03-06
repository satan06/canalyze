#include <strings.h>
#include <ctest.h>

CTEST(schr_test, find_item_ok)
{
    const char *str = "function(smth)\0";
    const char item = '(';

    const char *result = schr(str, item);

    ASSERT_NOT_NULL(result); 
}

CTEST(schr_test, find_item_fail)
{
    const char *str = "function(smtth);\0";
    const char item = '}';

    const char *result = schr(str, item);

    ASSERT_NULL(result); 
}

CTEST(slen_test, correct_length)
{
    const char *str = "func1()";

    const int result = slen(str);

	const int expected = 7;
    ASSERT_EQUAL(expected, result); 
}

CTEST(slen_test, incorrect_length)
{
    const char *str = "int main() {";

    const int result = slen(str);

	const int expected = 3;
    ASSERT_NOT_EQUAL(expected, result); 
}

CTEST(scmp_test, str_equal)
{
	const char *str = "strsame";
	const char *str_equal = "strsame";

	const int result = scmp(str, str_equal); 

	const int expected = 0;
	ASSERT_EQUAL(expected, result);
}

CTEST(scmp_test, str_not_equal)
{
	const char *str = "strsame";
	const char *str_equal = "strnotsame";

	const int result = scmp(str, str_equal); 

	const int expected = 0;
	ASSERT_NOT_EQUAL(expected, result);
}

CTEST(strstr_test, find_token_ok)
{
    const char *str = "function_one(var);";
    const char *token = "function_one";

    const char *result = strstr(str, token); 

    const char *expected = "function_one";
    ASSERT_STR(expected, result);
}

CTEST(strstr_test, find_token_null_fail)
{
    const char *str = "function_one(var);";
    const char *token = NULL;

    const char *result = strstr(str, token); 

    ASSERT_NULL(result);
}

CTEST(strstr_test, str_null_find_token_fail)
{
    const char *str = NULL;
    const char *token = "smtoken";

    const char *result = strstr(str, token); 

    ASSERT_NULL(result);
}