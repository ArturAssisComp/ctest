#include "../ctest/ctest.h"

int main(void)
{
	char *functions_tested[] = {
		//unsigned_integer type:
		"assert_unsigned_integer_equal",
		"assert_unsigned_integer_notEqual",
		"assert_unsigned_integer_greater",
		"assert_unsigned_integer_greaterEqual",
		"assert_unsigned_integer_less",
		"assert_unsigned_integer_lessEqual",
		"assert_unsigned_integer_bitMaskEqual",
		//integer type:
		"assert_integer_equal",
		"assert_integer_notEqual",
		"assert_integer_greater",
		"assert_integer_greaterEqual",
		"assert_integer_less",
		"assert_integer_lessEqual",
		//floating_point type:
		"assert_floating_point_almostEqual",
		"assert_floating_point_notAlmostEqual",
		"assert_floating_point_greater",
		"assert_floating_point_greaterEqual",
		"assert_floating_point_less",
		"assert_floating_point_lessEqual",
		NULL
	};

	//----------------------------------------------------------------------------
	start_suite("IGNORE TEST", "Test if each assert is ignored.", functions_tested);

		//----------------------------------------------------------------------------
		//Tests that will be ignored:
		start_module("Ignore", "Ignore the following tests.", functions_tested);
ignore = true;
			assert_unsigned_integer_equal        (0, 0, __LINE__, NULL);
			assert_unsigned_integer_notEqual     (1, 1, __LINE__, NULL);
			assert_unsigned_integer_greater      (3, 1, __LINE__, NULL);
			assert_unsigned_integer_greaterEqual (23, 45, __LINE__, NULL);
			assert_unsigned_integer_less         (23, 45, __LINE__, NULL);
			assert_unsigned_integer_lessEqual    (3, 455, __LINE__, NULL);
			assert_unsigned_integer_bitMaskEqual (12, 3, 455, __LINE__, NULL);
			assert_integer_equal        (23, 45, __LINE__, NULL);
			assert_integer_notEqual     (-23, 45, __LINE__, NULL);
			assert_integer_greater      (23, 45, __LINE__, NULL);
			assert_integer_greaterEqual (23, 45, __LINE__, NULL);
			assert_integer_less         (43, 45, __LINE__, NULL);
			assert_integer_lessEqual    (43, 45, __LINE__, NULL);
			assert_floating_point_almostEqual    (23, 45, 0.1, __LINE__, NULL);
			assert_floating_point_notAlmostEqual (23, 45, 0.1, __LINE__, NULL);
			assert_floating_point_greater        (12.2331, 2998, __LINE__, NULL);
			assert_floating_point_greaterEqual   (132.2331, 2998, __LINE__, NULL);
			assert_floating_point_less           (12.2331, 2.998, __LINE__, NULL);
ignore = false;
		end_module();
		//----------------------------------------------------------------------------

	end_suite();
	//----------------------------------------------------------------------------

	return 0;
}