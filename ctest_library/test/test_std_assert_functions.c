#include "../ctest/ctest.h"

int main(void)
{
	char *functions_tested[] = {
		"assert_unsigned_integer_equal",
		NULL
	};

	//----------------------------------------------------------------------------
	start_suite("Unsigned integer functions", "This test suite tests the unsigned integer asserts", functions_tested);

		//----------------------------------------------------------------------------
		start_module("equal - pass", "Every assert in this module must pass.", (char *[]){"assert_unsigned_integer_equal", NULL});
		

			assert_unsigned_integer_equal(1, 1);






		end_module();

		//----------------------------------------------------------------------------
		start_module("equal - fail", "Every assert in this module must fail.", (char *[]){"assert_unsigned_integer_equal", NULL});

			assert_unsigned_integer_equal(5, 6);


		end_module();
		//----------------------------------------------------------------------------

	end_suite();
	//----------------------------------------------------------------------------
	return 0;
}