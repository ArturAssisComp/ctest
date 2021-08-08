#include "../ctest/ctest.h"
#include <stdbool.h>

int main(void)
{
	char *functions_tested[] = {
		//unsigned_integer type:
		"ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL",
		//integer type:
		//floating_point type:
		//bool type

		NULL
	};

	//----------------------------------------------------------------------------
	start_suite("FAIL", "ALL tests in this suite must fail.", functions_tested);

		/*TEST CASES for unsigned_integer*/

		//----------------------ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL-------------------------
		//Tests that will fail:
		start_module("unsigned_integer array - equal", "Every assert in this module must fail.", (char *[]){"ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL", NULL});
			verbose = LOW;
			ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL(5, 6, __LINE__, NULL);

			verbose = MEDIUM;

			verbose = HIGH;

		end_module();
		//----------------------------------------------------------------------------

		/*TEST CASES for integer*/

		/*TEST CASES for floating_point*/

		/*TEST CASES for bool*/

	end_suite();
	//----------------------------------------------------------------------------

	return 0;
}