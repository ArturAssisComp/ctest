#include "../ctest/ctest.h"

int main(void)
{
	char *functions_tested[] = {
		"assert_unsigned_integer_equal",
		"assert_unsigned_integer_notEqual",
		"assert_unsigned_integer_greater",
		"assert_unsigned_integer_greaterEqual",
		NULL
	};

	//----------------------------------------------------------------------------
	start_suite("FAIL", "ALL tests in this suit must fail.", functions_tested);

		//----------------------assert_unsigned_integer_equal-------------------------
		//Tests that will fails:
		start_module("unsigned_integer - equal", "Every assert in this module must fail.", (char *[]){"assert_unsigned_integer_equal", NULL});
			verbose = LOW;
			assert_unsigned_integer_equal(5, 6, __LINE__, NULL);
			assert_unsigned_integer_equal(7, 0, __LINE__, "Testing custom message system: 7 is not equal to 0.");

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
		//Tests that will fails:
		start_module("unsigned_integer - notEqual", "Every assert in this module must fail.", (char *[]){"assert_unsigned_integer_notEqual", NULL});
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


		//----------------------assert_unsigned_integer_greater-------------------------
		//Tests that will fails:
		start_module("unsigned_integer - greater", "Every assert in this module must fail.", (char *[]){"assert_unsigned_integer_greater", NULL});
			verbose = LOW;
			assert_unsigned_integer_greater(0, 1, __LINE__, NULL);
			assert_unsigned_integer_greater(1, 1, __LINE__, "abcde");
			assert_unsigned_integer_greater(10, 10, __LINE__, "abcdefghijklmnopqrstuvwxyz");

			verbose = MEDIUM;
			assert_unsigned_integer_greater(0, 1, __LINE__, NULL);
			assert_unsigned_integer_greater(1, 1, __LINE__, "abcde");
			assert_unsigned_integer_greater(10, 10, __LINE__, "abcdefghijklmnopqrstuvwxyz");

			verbose = HIGH;
			assert_unsigned_integer_greater(0, 0, __LINE__, NULL);
			assert_unsigned_integer_greater(1, 10, __LINE__, "abcde");
			assert_unsigned_integer_greater(10, 123, __LINE__, "abcdefghijklmnopqrstuvwxyz");
			assert_unsigned_integer_greater(8128739182638769123, 8128739182638769126, __LINE__, "Testing big numbers.");
		end_module();
		//----------------------------------------------------------------------------


		//----------------------assert_unsigned_integer_greaterEqual-------------------------
		//Tests that will fails:
		start_module("unsigned_integer - greaterEqual", "Every assert in this module must fail.", (char *[]){"assert_unsigned_integer_greaterEqual", NULL});
			verbose = LOW;
			assert_unsigned_integer_greaterEqual(0, 1, __LINE__, NULL);
			assert_unsigned_integer_greaterEqual(1, 2, __LINE__, "abcde");
			assert_unsigned_integer_greaterEqual(10, 11, __LINE__, "abcdefghijklmnopqrstuvwxyz");

			verbose = MEDIUM;
			assert_unsigned_integer_greaterEqual(0, 1, __LINE__, NULL);
			assert_unsigned_integer_greaterEqual(1, 2, __LINE__, "abcde");
			assert_unsigned_integer_greaterEqual(10, 11, __LINE__, "abcdefghijklmnopqrstuvwxyz");

			verbose = HIGH;
			assert_unsigned_integer_greaterEqual(0, 2, __LINE__, NULL);
			assert_unsigned_integer_greaterEqual(1, 10, __LINE__, "abcde");
			assert_unsigned_integer_greaterEqual(10, 123, __LINE__, "abcdefghijklmnopqrstuvwxyz");
			assert_unsigned_integer_greaterEqual(8128739182638769123, 8128739182638769126, __LINE__, "Testing big numbers.");
		end_module();
		//----------------------------------------------------------------------------




	end_suite();
	//----------------------------------------------------------------------------

	return 0;
}