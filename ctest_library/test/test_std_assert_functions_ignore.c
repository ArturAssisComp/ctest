#include "../ctest/ctest.h"

int main(void)
{
	char *functions_tested[] = {
		"assert_unsigned_integer_equal",
		"assert_unsigned_integer_notEqual",
		"assert_unsigned_integer_greater",
		"assert_unsigned_integer_greaterEqual",
		"assert_unsigned_integer_less",
		"assert_unsigned_integer_lessEqual",
		NULL
	};

	//----------------------------------------------------------------------------
	start_suite("IGNORE TEST", "Test if each assert is ignored.", functions_tested);

		//----------------------------------------------------------------------------
		//Tests that will be ignored:
		start_module("Ignore", "Ignore the following tests.", functions_tested);
ignore = true;
			assert_unsigned_integer_equal       (0, 0, __LINE__, NULL);
			assert_unsigned_integer_notEqual    (1, 1, __LINE__, NULL);
			assert_unsigned_integer_greater     (3, 1, __LINE__, NULL);
			assert_unsigned_integer_greaterEqual(23, 45, __LINE__, NULL);
			assert_unsigned_integer_less        (23, 45, __LINE__, NULL);
			assert_unsigned_integer_lessEqual   (3, 455, __LINE__, NULL);
ignore = false;
		end_module();
		//----------------------------------------------------------------------------

	end_suite();
	//----------------------------------------------------------------------------

	return 0;
}