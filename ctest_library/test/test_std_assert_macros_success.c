#include "../ctest/ctest.h"

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
	start_suite("SUCCESS", "ALL tests in this suite must be successful.", functions_tested);

		/*TEST CASES for unsigned_integer*/
		
		//----------------------ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL-------------------
		//----------------------------------------------------------------------------
		//Tests that will be successful:
		start_module("unsigned_integer array - Equal", "Every assert in this module must pass.", (char *[]){"ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL", NULL});
			int INT_TARGET_ARRAY[] = {12, 34, 2};
			int INT_REFERENCE_ARRAY[] = {12, 34, 2};
			ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL(INT_TARGET_ARRAY, sizeof INT_TARGET_ARRAY, INT_REFERENCE_ARRAY, sizeof  INT_REFERENCE_ARRAY, __LINE__, NULL);


		end_module();
		//----------------------------------------------------------------------------


		/*TEST CASES for integer*/

		//----------------------assert_integer_equal-------------------------


		/*TEST CASES for floating_point*/

		//----------------------assert_floating_point_almostEqual-------------------------


		/*TEST CASES for bool*/
		
		//----------------------assert_bool_equal-------------------------


	end_suite();
	//----------------------------------------------------------------------------

	return 0;
}