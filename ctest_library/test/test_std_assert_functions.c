#include "../ctest/ctest.h"

int main(void)
{
	char *functions_tested[] = {
		"assert_unsigned_integer_equal",
		NULL
	};

	//----------------------------------------------------------------------------
	start_suite("Unsigned integer functions", "This test suite tests the unsigned integer asserts", functions_tested);

		//----------------------assert_unsigned_integer_equal-------------------------
		//----------------------------------------------------------------------------
		//Tests that will be successful:
		start_module("equal - pass", "Every assert in this module must pass.", (char *[]){"assert_unsigned_integer_equal", NULL});
			assert_unsigned_integer_equal(0, 0, __LINE__, NULL);
			assert_unsigned_integer_equal(1, 1, __LINE__, NULL);
			assert_unsigned_integer_equal(2, 2, __LINE__, "2 == 2");
			assert_unsigned_integer_equal(3, 3, __LINE__, NULL);
			assert_unsigned_integer_equal(4, 4, __LINE__, NULL);
			assert_unsigned_integer_equal(5, 5, __LINE__, NULL);
			assert_unsigned_integer_equal(100, 100, __LINE__, NULL);
			assert_unsigned_integer_equal(12739, 12739, __LINE__, NULL);
			int a1 = 102, a2 = 102;
			assert_unsigned_integer_equal(a1, a2, __LINE__, NULL);
			char a3 = 35, a4 = 35;
			assert_unsigned_integer_equal(a3, a4, __LINE__, NULL);
		end_module();

		//----------------------------------------------------------------------------
		//Tests that will fails:
		start_module("equal - fail", "Every assert in this module must fail.", (char *[]){"assert_unsigned_integer_equal", NULL});
			verbose = LOW;
			assert_unsigned_integer_equal(5, 6, __LINE__, NULL);
			assert_unsigned_integer_notEqual(7, 0, __LINE__, "Testing custom message system: 7 is not equal to 0.");

			verbose = MEDIUM;
			assert_unsigned_integer_equal(5, 6, __LINE__, NULL);
			assert_unsigned_integer_equal(7, 0, __LINE__, "Testing custom message system: 7 is not equal to 0.");

			verbose = HIGH;
			assert_unsigned_integer_equal(5, 6, __LINE__, NULL);
			assert_unsigned_integer_equal(7, 0, __LINE__, "Testing custom message system: 7 is not equal to 0.");
			assert_unsigned_integer_equal(8128739182638769123, 8128739186387694323, __LINE__, "Testing big numbers.");
		end_module();
		//----------------------------------------------------------------------------


		//----------------------assert_unsigned_integer_notEqual-------------------------
		//----------------------------------------------------------------------------
		//Tests that will be successful:
		start_module("equal - pass", "Every assert in this module must pass.", (char *[]){"assert_unsigned_integer_notEqual", NULL});
			assert_unsigned_integer_notEqual(1, 0, __LINE__, NULL);
			assert_unsigned_integer_notEqual(0, 1, __LINE__, NULL);
			assert_unsigned_integer_notEqual(1, 2, __LINE__, "2 == 2");
			assert_unsigned_integer_notEqual(2, 1, __LINE__, NULL);
			assert_unsigned_integer_notEqual(0, 4, __LINE__, NULL);
			assert_unsigned_integer_notEqual(87, 123, __LINE__, NULL);
			assert_unsigned_integer_notEqual(100, 1020, __LINE__, NULL);
			assert_unsigned_integer_notEqual(127139, 12739, __LINE__, NULL);
			a1 = 1022; a2 = 102;
			assert_unsigned_integer_notEqual(a1, a2, __LINE__, NULL);
			a3 = 35; a4 = 45;
			assert_unsigned_integer_notEqual(a3, a4, __LINE__, NULL);
		end_module();

		//----------------------------------------------------------------------------
		//Tests that will fails:
		start_module("equal - fail", "Every assert in this module must fail.", (char *[]){"assert_unsigned_integer_notEqual", NULL});
			verbose = LOW;
			assert_unsigned_integer_notEqual(0, 0, __LINE__, NULL);
			assert_unsigned_integer_notEqual(1, 1, __LINE__, "abcde");
			assert_unsigned_integer_notEqual(10, 10, __LINE__, "abcdefghijklmnopqrstuvwxyz");

			verbose = MEDIUM;
			assert_unsigned_integer_notEqual(0, 0, __LINE__, NULL);
			assert_unsigned_integer_notEqual(1, 1, __LINE__, "abcde");
			assert_unsigned_integer_notEqual(10, 10, __LINE__, "abcdefghijklmnopqrstuvwxyz");

			verbose = HIGH;
			assert_unsigned_integer_notEqual(0, 0, __LINE__, NULL);
			assert_unsigned_integer_notEqual(1, 1, __LINE__, "abcde");
			assert_unsigned_integer_notEqual(10, 10, __LINE__, "abcdefghijklmnopqrstuvwxyz");
			assert_unsigned_integer_notEqual(8128739182638769123, 8128739182638769123, __LINE__, "Testing big numbers.");
		end_module();
		//----------------------------------------------------------------------------








		//----------------------------------------------------------------------------
		//Tests that will be ignored:
		start_module("Ignore", "Ignore the following tests.", (char *[]){"assert_unsigned_integer_equal", NULL});
ignore = true;
			assert_unsigned_integer_equal(0, 0, __LINE__, NULL);
			assert_unsigned_integer_equal(1, 1, __LINE__, NULL);
			assert_unsigned_integer_equal(2, 2, __LINE__, "2 == 2");
ignore = false;
		end_module();
		//----------------------------------------------------------------------------

	end_suite();
	//----------------------------------------------------------------------------

	return 0;
}