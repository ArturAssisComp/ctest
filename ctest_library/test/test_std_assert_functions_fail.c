#include "../ctest/ctest.h"
#include <stdbool.h>

//Short for casting arrays:
#define UI (unsigned_integer[])
#define FP (floating_point[])
#define SI (integer[])
#define BL (bool[])

#define ASC true
#define DSC false

int main(void)
{
	char *functions_tested[] = {
		/*Single data*/
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
		//bool type
		"assert_bool_equal",
		"assert_bool_notEqual",
		"assert_bool_true",
		"assert_bool_false",
		/*Arrays*/
		//unsigned_integer type:
		"assert_unsigned_integerArray_equal",
		"assert_unsigned_integerArray_notEqual",
		"assert_unsigned_integerArray_sorted",
		"assert_unsigned_integerArray_notSorted",
		"assert_unsigned_integerArray_permutation",
		"assert_unsigned_integerArray_notPermutation",
		"assert_unsigned_integerArray_isPartialPermutation",
		"assert_unsigned_integerArray_notIsPartialPermutation",
		"assert_unsigned_integerArray_hasPartialPermutation",
		"assert_unsigned_integerArray_notHasPartialPermutation",
		"assert_unsigned_integerArray_setIn",
		"assert_unsigned_integerArray_notSetIn",
		"assert_unsigned_integerArray_setHas",
		"assert_unsigned_integerArray_notSetHas",
		"assert_unsigned_integerArray_isSubarray",
		"assert_unsigned_integerArray_notIsSubarray",
		"assert_unsigned_integerArray_hasSubarray",
		"assert_unsigned_integerArray_notHasSubarray",
		NULL
	};

	//----------------------------------------------------------------------------
	start_suite("FAIL", "ALL tests in this suite must fail.", functions_tested);

		/*Single data*/
		/*TEST CASES for unsigned_integer*/

		//----------------------assert_unsigned_integer_equal-------------------------
		//Tests that will fail:
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

		//----------------------assert_unsigned_integer_notEqual----------------------
		//Tests that will fail:
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

		//----------------------assert_unsigned_integer_greater-----------------------
		//Tests that will fail:
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


		//----------------------assert_unsigned_integer_greaterEqual------------------
		//Tests that will fail:
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

		//----------------------assert_unsigned_integer_less--------------------------
		//Tests that will fail:
		start_module("unsigned_integer - less", "Every assert in this module must fail.", (char *[]){"assert_unsigned_integer_less", NULL});
			verbose = LOW;
			assert_unsigned_integer_less(0, 0, __LINE__, NULL);
			assert_unsigned_integer_less(1, 0, __LINE__, "abcde");
			assert_unsigned_integer_less(10, 9, __LINE__, "abcdefghijklmnopqrstuvwxyz");

			verbose = MEDIUM;
			assert_unsigned_integer_less(2, 1, __LINE__, NULL);
			assert_unsigned_integer_less(1, 0, __LINE__, "abcde");
			assert_unsigned_integer_less(10, 10, __LINE__, "abcdefghijklmnopqrstuvwxyz");

			verbose = HIGH;
			assert_unsigned_integer_less(3, 2, __LINE__, NULL);
			assert_unsigned_integer_less(11, 10, __LINE__, "abcde");
			assert_unsigned_integer_less(1022, 123, __LINE__, "abcdefghijklmnopqrstuvwxyz");
			assert_unsigned_integer_less(8128739182638769127, 8128739182638769126, __LINE__, "Testing big numbers.");
		end_module();
		//----------------------------------------------------------------------------

		//----------------------assert_unsigned_integer_lessEqual---------------------
		//Tests that will fail:
		start_module("unsigned_integer - lessEqual", "Every assert in this module must fail.", (char *[]){"assert_unsigned_integer_lessEqual", NULL});
			verbose = LOW;
			assert_unsigned_integer_lessEqual(7, 6, __LINE__, NULL);
			assert_unsigned_integer_lessEqual(1, 0, __LINE__, "abcde");
			assert_unsigned_integer_lessEqual(10, 9, __LINE__, "abcdefghijklmnopqrstuvwxyz");

			verbose = MEDIUM;
			assert_unsigned_integer_lessEqual(2, 1, __LINE__, NULL);
			assert_unsigned_integer_lessEqual(1, 0, __LINE__, "abcde");
			assert_unsigned_integer_lessEqual(10, 9, __LINE__, "abcdefghijklmnopqrstuvwxyz");

			verbose = HIGH;
			assert_unsigned_integer_lessEqual(3, 2, __LINE__, NULL);
			assert_unsigned_integer_lessEqual(11, 10, __LINE__, "abcde");
			assert_unsigned_integer_lessEqual(1022, 123, __LINE__, "abcdefghijklmnopqrstuvwxyz");
			assert_unsigned_integer_lessEqual(8128739182638769127, 8128739182638769126, __LINE__, "Testing big numbers.");
		end_module();
		//----------------------------------------------------------------------------

		//----------------------assert_unsigned_integer_bitMaskEqual------------------
		//Tests that will fail:
		start_module("unsigned_integer - bitMaskEqual", "Every assert in this module must fail.", (char *[]){"assert_unsigned_integer_bitMaskEqual", NULL});
			verbose = LOW;
			assert_unsigned_integer_bitMaskEqual(0x4B, 0xC2, 0x80, __LINE__, NULL); //0b01001011 - 0b11000010 with mask 0b10000000
			assert_unsigned_integer_bitMaskEqual(0x4B, 0xC2, 0x61, __LINE__, NULL); //0b01001011 - 0b11000010 with mask 0b01100001
			assert_unsigned_integer_bitMaskEqual(0x4B, 0xC2, 0x461, __LINE__, NULL); //0b01001011 - 0b11000010 with mask 0b010001100001
			assert_unsigned_integer_bitMaskEqual(0x6, 0xD, 0xF, __LINE__, NULL); //0b0111 - 0b1101 with mask 0b1111
			assert_unsigned_integer_bitMaskEqual(0x6, 0xD, 0xFF, __LINE__, NULL); //0b0111 - 0b1101 with mask 0b11111111


			verbose = MEDIUM;
			assert_unsigned_integer_bitMaskEqual(0x4B, 0xC2, 0x80, __LINE__, NULL); //0b01001011 - 0b11000010 with mask 0b10000000
			assert_unsigned_integer_bitMaskEqual(0x4B, 0xC2, 0x61, __LINE__, NULL); //0b01001011 - 0b11000010 with mask 0b01100001
			assert_unsigned_integer_bitMaskEqual(0x4B, 0xC2, 0x461, __LINE__, NULL); //0b01001011 - 0b11000010 with mask 0b010001100001
			assert_unsigned_integer_bitMaskEqual(0x6, 0xD, 0xF, __LINE__, NULL); //0b0111 - 0b1101 with mask 0b1111
			assert_unsigned_integer_bitMaskEqual(0x6, 0xD, 0xFF, __LINE__, NULL); //0b0111 - 0b1101 with mask 0b11111111

			verbose = HIGH;
			assert_unsigned_integer_bitMaskEqual(0x4B, 0xC2, 0x80, __LINE__, NULL); //0b01001011 - 0b11000010 with mask 0b10000000
			assert_unsigned_integer_bitMaskEqual(0x4B, 0xC2, 0x61, __LINE__, NULL); //0b01001011 - 0b11000010 with mask 0b01100001
			assert_unsigned_integer_bitMaskEqual(0x4B, 0xC2, 0x461, __LINE__, NULL); //0b01001011 - 0b11000010 with mask 0b010001100001
			assert_unsigned_integer_bitMaskEqual(0x6, 0xD, 0xF, __LINE__, NULL); //0b0111 - 0b1101 with mask 0b1111
			assert_unsigned_integer_bitMaskEqual(0x6, 0xD, 0xFF, __LINE__, NULL); //0b0111 - 0b1101 with mask 0b11111111
			assert_unsigned_integer_bitMaskEqual(0x6, ~0x6, 0xF, __LINE__, NULL); //0b0111 - 0b(...)1000 with mask 0b1111
		end_module();
		//----------------------------------------------------------------------------

		/*TEST CASES for integer*/

		//----------------------assert_integer_equal-------------------------
		//Tests that will fail:
		start_module("integer - equal", "Every assert in this module must fail.", (char *[]){"assert_integer_equal", NULL});
			verbose = LOW;
			assert_integer_equal(5, 6, __LINE__, NULL);
			assert_integer_equal(7, 0, __LINE__, "Testing custom message system: 7 is not equal to 0.");

			verbose = MEDIUM;
			assert_integer_equal(5, 6, __LINE__, NULL);
			assert_integer_equal(7, 0, __LINE__, "Testing custom message system: 7 is not equal to 0.");

			verbose = HIGH;
			assert_integer_equal(5, 6, __LINE__, NULL);
			assert_integer_equal(7, 0, __LINE__, NULL);
			assert_integer_equal(76, -10, __LINE__, NULL);
			assert_integer_equal(8128739182638769123, 8128739186387694323, __LINE__, "Testing big numbers.");
		end_module();
		//----------------------------------------------------------------------------

		//----------------------assert_integer_notEqual----------------------
		//Tests that will fail:
		start_module("integer - notEqual", "Every assert in this module must fail.", (char *[]){"assert_integer_notEqual", NULL});
			verbose = LOW;
			assert_integer_notEqual(0, 0, __LINE__, NULL);
			assert_integer_notEqual(1, 1, __LINE__, "abcde");
			assert_integer_notEqual(10, 10, __LINE__, "abcdefghijklmnopqrstuvwxyz");

			verbose = MEDIUM;
			assert_integer_notEqual(0, 0, __LINE__, NULL);
			assert_integer_notEqual(1, 1, __LINE__, "abcde");
			assert_integer_notEqual(-10, -10, __LINE__, "abcdefghijklmnopqrstuvwxyz");

			verbose = HIGH;
			assert_integer_notEqual(0, 0, __LINE__, NULL);
			assert_integer_notEqual(-1, -1, __LINE__, "abcde");
			assert_integer_notEqual(10, 10, __LINE__, "abcdefghijklmnopqrstuvwxyz");
			assert_integer_notEqual(8128739182638769123, 8128739182638769123, __LINE__, "Testing big numbers.");
		end_module();
		//----------------------------------------------------------------------------

		//----------------------assert_integer_greater-----------------------
		//Tests that will fail:
		start_module("integer - greater", "Every assert in this module must fail.", (char *[]){"assert_integer_greater", NULL});
			verbose = LOW;
			assert_integer_greater(0, 1, __LINE__, NULL);
			assert_integer_greater(1, 1, __LINE__, "abcde");
			assert_integer_greater(-10, -10, __LINE__, "abcdefghijklmnopqrstuvwxyz");

			verbose = MEDIUM;
			assert_integer_greater(0, 1, __LINE__, NULL);
			assert_integer_greater(1, 1, __LINE__, "abcde");
			assert_integer_greater(10, 10, __LINE__, "abcdefghijklmnopqrstuvwxyz");

			verbose = HIGH;
			assert_integer_greater(0, 0, __LINE__, NULL);
			assert_integer_greater(1, 10, __LINE__, "abcde");
			assert_integer_greater(-104, 13, __LINE__, "abcdefghijklmnopqrstuvwxyz");
			assert_integer_greater(8128739182638769123, 8128739182638769126, __LINE__, "Testing big numbers.");
		end_module();
		//----------------------------------------------------------------------------

		//----------------------assert_integer_greaterEqual------------------
		//Tests that will fail:
		start_module("integer - greaterEqual", "Every assert in this module must fail.", (char *[]){"assert_integer_greaterEqual", NULL});
			verbose = LOW;
			assert_integer_greaterEqual(0, 1, __LINE__, NULL);
			assert_integer_greaterEqual(1, 2, __LINE__, "abcde");
			assert_integer_greaterEqual(10, 11, __LINE__, "abcdefghijklmnopqrstuvwxyz");

			verbose = MEDIUM;
			assert_integer_greaterEqual(0, 1, __LINE__, NULL);
			assert_integer_greaterEqual(1, 2, __LINE__, "abcde");
			assert_integer_greaterEqual(-10, 11, __LINE__, "abcdefghijklmnopqrstuvwxyz");

			verbose = HIGH;
			assert_integer_greaterEqual(0, 2, __LINE__, NULL);
			assert_integer_greaterEqual(-1, 10, __LINE__, "abcde");
			assert_integer_greaterEqual(-10, 123, __LINE__, "abcdefghijklmnopqrstuvwxyz");
			assert_integer_greaterEqual(8128739182638769123, 8128739182638769126, __LINE__, "Testing big numbers.");
		end_module();
		//----------------------------------------------------------------------------

		//----------------------assert_integer_less--------------------------
		//Tests that will fail:
		start_module("integer - less", "Every assert in this module must fail.", (char *[]){"assert_integer_less", NULL});
			verbose = LOW;
			assert_integer_less(0, 0, __LINE__, NULL);
			assert_integer_less(1, 0, __LINE__, "abcde");
			assert_integer_less(10, -9, __LINE__, "abcdefghijklmnopqrstuvwxyz");

			verbose = MEDIUM;
			assert_integer_less(2, 1, __LINE__, NULL);
			assert_integer_less(1, 0, __LINE__, "abcde");
			assert_integer_less(10, 10, __LINE__, "abcdefghijklmnopqrstuvwxyz");

			verbose = HIGH;
			assert_integer_less(3, 2, __LINE__, NULL);
			assert_integer_less(-11, -109, __LINE__, "abcde");
			assert_integer_less(1022, -123, __LINE__, NULL);
			assert_integer_less(8128739182638769127, 8128739182638769126, __LINE__, "Testing big numbers.");
		end_module();
		//----------------------------------------------------------------------------

		//----------------------assert_integer_lessEqual---------------------
		//Tests that will fail:
		start_module("integer - lessEqual", "Every assert in this module must fail.", (char *[]){"assert_integer_lessEqual", NULL});
			verbose = LOW;
			assert_integer_lessEqual(7, 6, __LINE__, NULL);
			assert_integer_lessEqual(1, 0, __LINE__, "abcde");
			assert_integer_lessEqual(10, -9, __LINE__, "abcdefghijklmnopqrstuvwxyz");

			verbose = MEDIUM;
			assert_integer_lessEqual(2, 1, __LINE__, NULL);
			assert_integer_lessEqual(1, 0, __LINE__, "abcde");
			assert_integer_lessEqual(10, 9, __LINE__, "abcdefghijklmnopqrstuvwxyz");

			verbose = HIGH;
			assert_integer_lessEqual(3, 2, __LINE__, NULL);
			assert_integer_lessEqual(11, 10, __LINE__, "abcde");
			assert_integer_lessEqual(1022, -123, __LINE__, "abcdefghijklmnopqrstuvwxyz");
			assert_integer_lessEqual(8128739182638769127, 8128739182638769126, __LINE__, "Testing big numbers.");
		end_module();
		//----------------------------------------------------------------------------

		/*TEST CASES for floating_point*/

		//----------------------assert_floating_point_almostEqual-------------------------
		//----------------------------------------------------------------------------
		//Tests that will fail:
		floating_point max_diff;
		start_module("floating_point - almostEqual", "Every assert in this module must fail.", (char *[]){"assert_floating_point_almostEqual", NULL});
			verbose = LOW;
			max_diff = 0.001;
			assert_floating_point_almostEqual(0, 0.1245, max_diff, __LINE__, NULL);
			assert_floating_point_almostEqual(0.1239, 0.1249, max_diff, __LINE__, NULL);

			verbose = MEDIUM;
			assert_floating_point_almostEqual(0, 0.1245, max_diff, __LINE__, NULL);
			assert_floating_point_almostEqual(0.1239, 0.1249, max_diff, __LINE__, "Test custom message");

			verbose = HIGH;
			max_diff = 0.001;
			assert_floating_point_almostEqual(0, 0.1245, max_diff, __LINE__, NULL);
			assert_floating_point_almostEqual(0.1239, 0.1249, max_diff, __LINE__, NULL);
			assert_floating_point_almostEqual(24.1539, 23.1235, max_diff, __LINE__, NULL);
			assert_floating_point_almostEqual(-90.88998, -90.88878, max_diff, __LINE__, NULL);
			max_diff = 0.0001;
			assert_floating_point_almostEqual(-1, 1, max_diff, __LINE__, NULL);
			assert_floating_point_almostEqual(292.99968291, 292.99930001, max_diff, __LINE__, NULL);
			assert_floating_point_almostEqual(-3.9045, -3.9021, max_diff, __LINE__, NULL);
			assert_floating_point_almostEqual(-4.9993, -4.999, max_diff, __LINE__, NULL);
			assert_floating_point_almostEqual(12235.299382, 5.29938234, max_diff, __LINE__, NULL);
			max_diff = 0.3;
			assert_floating_point_almostEqual(100.2, 100.987, max_diff, __LINE__, NULL);
			assert_floating_point_almostEqual(12739.1092, 127389.3990, max_diff, __LINE__, NULL);
			max_diff = 100;
			float b1 = 1e4, b2 = 1.09e3;
			assert_floating_point_almostEqual(b1, b2, max_diff, __LINE__, NULL);
			double b3 = 1000, b4 = -35;
			assert_floating_point_almostEqual(b3, b4, max_diff, __LINE__, NULL);
			assert_floating_point_almostEqual(0.12987982e23, 127389.3990, max_diff, __LINE__, NULL);
			max_diff = 1e-12;
			assert_floating_point_almostEqual(1e-11, 1.9e-11, max_diff, __LINE__, NULL);
		end_module();
		//----------------------------------------------------------------------------

		//----------------------assert_floating_point_notAlmostEqual-------------------------
		//Tests that will fail:
		floating_point min_diff;
		start_module("floating_point - notAlmostEqual", "Every assert in this module must fail.", (char *[]){"assert_floating_point_notAlmostEqual", NULL});
			verbose = LOW;
			min_diff = 0.001;
			assert_floating_point_notAlmostEqual(0.1239, 0.1235, min_diff, __LINE__, NULL);
			assert_floating_point_notAlmostEqual(23.1239, 23.1235, min_diff, __LINE__, NULL);

			verbose = MEDIUM;
			assert_floating_point_notAlmostEqual(0.1239, 0.1235, min_diff, __LINE__, NULL);
			assert_floating_point_notAlmostEqual(23.1239, 23.1235, min_diff, __LINE__, NULL);

			verbose = HIGH;
			assert_floating_point_notAlmostEqual(0.1239, 0.1235, min_diff, __LINE__, NULL);
			assert_floating_point_notAlmostEqual(23.1239, 23.1235, min_diff, __LINE__, NULL);
			assert_floating_point_notAlmostEqual(-90.88898, -90.88878, min_diff, __LINE__, NULL);
			min_diff = 0.0001;
			assert_floating_point_notAlmostEqual(1, 1, min_diff, __LINE__, NULL);
			assert_floating_point_notAlmostEqual(292.99938291, 292.99930001, min_diff, __LINE__, "2 == 2");
			assert_floating_point_notAlmostEqual(-3.90, -3.90, min_diff, __LINE__, NULL);
			assert_floating_point_notAlmostEqual(-4.999, -4.999, min_diff, __LINE__, NULL);
			assert_floating_point_notAlmostEqual(5.299382, 5.29938234, min_diff, __LINE__, NULL);
			min_diff = 0.3;
			assert_floating_point_notAlmostEqual(100.2, 100.1, min_diff, __LINE__, NULL);
			assert_floating_point_notAlmostEqual(12739.1092, 12739.3990, min_diff, __LINE__, NULL);
			min_diff = 100;
			b1 = 1e3; b2 = 1.09e3;
			assert_floating_point_notAlmostEqual(b1, b2, min_diff, __LINE__, NULL);
			b3 = 100; b4 = 35;
			assert_floating_point_notAlmostEqual(b3, b4, min_diff, __LINE__, NULL);
		end_module();
		//----------------------------------------------------------------------------

		//----------------------assert_floating_point_greater-----------------------
		//Tests that will fail:
		start_module("floating_point - greater", "Every assert in this module must fail.", (char *[]){"assert_floating_point_greater", NULL});
			verbose = LOW;
			assert_floating_point_greater(0, 1, __LINE__, NULL);
			assert_floating_point_greater(1.0, 1.0, __LINE__, "abcde");
			assert_floating_point_greater(10, 10, __LINE__, "abcdefghijklmnopqrstuvwxyz");

			verbose = MEDIUM;
			assert_floating_point_greater(0, 1, __LINE__, NULL);
			assert_floating_point_greater(1, 1, __LINE__, "abcde");
			assert_floating_point_greater(10, 10, __LINE__, "abcdefghijklmnopqrstuvwxyz");

			verbose = HIGH;
			assert_floating_point_greater(0.90912, 0.990123, __LINE__, NULL);
			assert_floating_point_greater(-1, 10, __LINE__, "abcde");
			assert_floating_point_greater(10.39, 123.12, __LINE__, "abcdefghijklmnopqrstuvwxyz");
			assert_floating_point_greater(-8128739182638769123.123, 8128739182638769126, __LINE__, "Testing big numbers.");
		end_module();
		//----------------------------------------------------------------------------


		//----------------------assert_floating_point_greaterEqual------------------
		//Tests that will fail:
		start_module("floating_point - greaterEqual", "Every assert in this module must fail.", (char *[]){"assert_floating_point_greaterEqual", NULL});
			verbose = LOW;
			assert_floating_point_greaterEqual(0, 1, __LINE__, NULL);
			assert_floating_point_greaterEqual(-1.4, 2, __LINE__, "abcde");
			assert_floating_point_greaterEqual(10, 11, __LINE__, "abcdefghijklmnopqrstuvwxyz");

			verbose = MEDIUM;
			assert_floating_point_greaterEqual(0, 1, __LINE__, NULL);
			assert_floating_point_greaterEqual(1, 2, __LINE__, "abcde");
			assert_floating_point_greaterEqual(10, 11, __LINE__, "abcdefghijklmnopqrstuvwxyz");

			verbose = HIGH;
			assert_floating_point_greaterEqual(0, 2, __LINE__, NULL);
			assert_floating_point_greaterEqual(0.199812, 0.199923, __LINE__, NULL);
			assert_floating_point_greaterEqual(1, 10, __LINE__, "abcde");
			assert_floating_point_greaterEqual(-10.3, 123, __LINE__, "abcdefghijklmnopqrstuvwxyz");
			assert_floating_point_greaterEqual(8128, 2.78e23, __LINE__, "Testing big numbers.");
			assert_floating_point_greaterEqual(8.21879e-20, 0.5, __LINE__, "Testing big numbers.");
		end_module();
		//----------------------------------------------------------------------------

		//----------------------assert_floating_point_less--------------------------
		//Tests that will fail:
		start_module("floating_point - less", "Every assert in this module must fail.", (char *[]){"assert_floating_point_less", NULL});
			verbose = LOW;
			assert_floating_point_less(0.42, 0, __LINE__, NULL);
			assert_floating_point_less(0, 0, __LINE__, NULL);
			assert_floating_point_less(1, 0, __LINE__, "abcde");
			assert_floating_point_less(10, 9, __LINE__, "abcdefghijklmnopqrstuvwxyz");

			verbose = MEDIUM;
			assert_floating_point_less(2.5, 1, __LINE__, NULL);
			assert_floating_point_less(1, 0, __LINE__, "abcde");
			assert_floating_point_less(10, 10, __LINE__, "abcdefghijklmnopqrstuvwxyz");

			verbose = HIGH;
			assert_floating_point_less(3.2, -2.2331123, __LINE__, NULL);
			assert_floating_point_less(11, 10, __LINE__, "abcde");
			assert_floating_point_less(1.022e3, 123, __LINE__, "abcdefghijklmnopqrstuvwxyz");
			assert_floating_point_less(-812, -81287391, __LINE__, "Testing big numbers.");
		end_module();
		//----------------------------------------------------------------------------

		//----------------------assert_floating_point_lessEqual---------------------
		//Tests that will fail:
		start_module("floating_point - lessEqual", "Every assert in this module must fail.", (char *[]){"assert_floating_point_lessEqual", NULL});
			verbose = LOW;
			assert_floating_point_lessEqual(7.84, 6, __LINE__, NULL);
			assert_floating_point_lessEqual(1, 0, __LINE__, "abcde");
			assert_floating_point_lessEqual(10, -9, __LINE__, "abcdefghijklmnopqrstuvwxyz");

			verbose = MEDIUM;
			assert_floating_point_lessEqual(2e2, -1e20, __LINE__, NULL);
			assert_floating_point_lessEqual(1.187e4, 0, __LINE__, "abcde");
			assert_floating_point_lessEqual(10, 9, __LINE__, "abcdefghijklmnopqrstuvwxyz");

			verbose = HIGH;
			assert_floating_point_lessEqual(3, 2, __LINE__, NULL);
			assert_floating_point_lessEqual(11, 10, __LINE__, "abcde");
			assert_floating_point_lessEqual(1022, 123, __LINE__, "abcdefghijklmnopqrstuvwxyz");
			assert_floating_point_lessEqual(12.3987, 126e-20, __LINE__, "Testing big numbers.");
		end_module();
		//----------------------------------------------------------------------------

		/*TEST CASES for bool*/

		//----------------------assert_bool_equal-------------------------
		//Tests that will fail:
		start_module("bool - equal", "Every assert in this module must fail.", (char *[]){"assert_bool_equal", NULL});
			verbose = LOW;
			assert_bool_equal(true, false, __LINE__, NULL);
			assert_bool_equal(false, true, __LINE__, NULL);

			verbose = MEDIUM;
			assert_bool_equal(true, false, __LINE__, NULL);
			assert_bool_equal(false, true, __LINE__, NULL);

			verbose = HIGH;
			assert_bool_equal(true, false, __LINE__, NULL);
			assert_bool_equal(false, true, __LINE__, NULL);
			assert_bool_equal(0, 1, __LINE__, NULL);
			assert_bool_equal(1, 0, __LINE__, NULL);
			assert_bool_equal(5, 0, __LINE__, NULL);
		end_module();
		//----------------------------------------------------------------------------

		//----------------------assert_bool_notEqual----------------------

		//Tests that will fail:
		start_module("bool - notEqual", "Every assert in this module must fail.", (char *[]){"assert_bool_notEqual", NULL});
			verbose = LOW;
			assert_bool_notEqual(true, true, __LINE__, NULL);
			assert_bool_notEqual(false, false, __LINE__, NULL);

			verbose = MEDIUM;
			assert_bool_notEqual(true, true, __LINE__, NULL);
			assert_bool_notEqual(false, false, __LINE__, NULL);

			verbose = HIGH;
			assert_bool_notEqual(true, true, __LINE__, NULL);
			assert_bool_notEqual(false, false, __LINE__, NULL);
			assert_bool_notEqual(1, 1, __LINE__, "abcde");
			assert_bool_notEqual(10, 10, __LINE__, NULL);


		end_module();
		//----------------------------------------------------------------------------

		//----------------------assert_bool_true----------------------
		//Tests that will fail:
		start_module("bool - true", "Every assert in this module must fail.", (char *[]){"assert_bool_true", NULL});
			verbose = LOW;
			assert_bool_true(false, __LINE__, NULL);
			assert_bool_true(0, __LINE__, "abcde");

			verbose = MEDIUM;
			assert_bool_true(false, __LINE__, NULL);
			assert_bool_true(0, __LINE__, "abcde");

			verbose = HIGH;
			assert_bool_true(false, __LINE__, NULL);
			assert_bool_true(0, __LINE__, "abcde");

		end_module();
		//----------------------------------------------------------------------------

		//----------------------assert_bool_false----------------------
		//Tests that will fail:
		start_module("bool - false", "Every assert in this module must fail.", (char *[]){"assert_bool_false", NULL});
			verbose = LOW;
			assert_bool_false(true, __LINE__, NULL);
			assert_bool_false(1, __LINE__, "abcde");

			verbose = MEDIUM;
			assert_bool_false(true, __LINE__, NULL);
			assert_bool_false(1, __LINE__, "abcde");

			verbose = HIGH;
			assert_bool_false(true, __LINE__, NULL);
			assert_bool_false(1, __LINE__, "abcde");

		end_module();
		//----------------------------------------------------------------------------

		/*Arrays*/
		/*TEST CASES for unsigned_integer*/

		//----------------------assert_unsigned_integerArray_equal-------------------------
		//Tests that will fail:
		start_module("unsigned_integerArray - equal", "Every assert in this module must fail.", (char *[]){"assert_unsigned_integerArray_equal", NULL});
			verbose = LOW;
			assert_unsigned_integerArray_equal(UI{1, 2, 3}, 3, UI{2, 2}, 2, __LINE__, NULL);

			verbose = MEDIUM;
			assert_unsigned_integerArray_equal(UI{1, 2, 3}, 3, UI{2, 2}, 2, __LINE__, NULL);

			verbose = HIGH;
			assert_unsigned_integerArray_equal(UI{1}, 1, UI{2}, 1, __LINE__, NULL);
			assert_unsigned_integerArray_equal(UI{0}, 1, UI{1239808712}, 1, __LINE__, NULL);
			assert_unsigned_integerArray_equal(UI{1, 2, 3, 4, 5, 1000, 7, 8, 9, 10}, 10, UI{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, __LINE__, NULL);
			assert_unsigned_integerArray_equal(UI{1, 2, 3}, 3, UI{2}, 1, __LINE__, NULL);
			assert_unsigned_integerArray_equal(UI{1}, 1, UI{2, 3, 4}, 3, __LINE__, NULL);
			assert_unsigned_integerArray_equal(UI{0}, 1, UI{0, 0, 0}, 3, __LINE__, NULL);
			assert_unsigned_integerArray_equal(UI{1, 2, 3}, 3, UI{1}, 1, __LINE__, NULL);


		end_module();
		//----------------------------------------------------------------------------

		//----------------------assert_unsigned_integerArray_notEqual-------------------------
		//Tests that will fail:
		start_module("unsigned_integerArray - notEqual", "Every assert in this module must fail.", (char *[]){"assert_unsigned_integerArray_notEqual", NULL});
			verbose = LOW;
			assert_unsigned_integerArray_notEqual(UI{1, 2, 3}, 3, UI{1, 2, 3}, 3, __LINE__, NULL);

			verbose = MEDIUM;
			assert_unsigned_integerArray_notEqual(UI{2, 2}, 2, UI{2, 2}, 2, __LINE__, NULL);

			verbose = HIGH;
			assert_unsigned_integerArray_notEqual(UI{1}, 1, UI{1}, 1, __LINE__, NULL);
			assert_unsigned_integerArray_notEqual(UI{0}, 1, UI{0}, 1, __LINE__, NULL);
			assert_unsigned_integerArray_notEqual(UI{1, 2, 3, 4, 5, 1000, 7, 8, 9, 10}, 10, UI{1, 2, 3, 4, 5, 1000, 7, 8, 9, 10}, 10, __LINE__, NULL);
			assert_unsigned_integerArray_notEqual(UI{1, 2, 3}, 3, UI{1, 2, 3}, 3, __LINE__, NULL);
			assert_unsigned_integerArray_notEqual(UI{10}, 1, UI{10}, 1, __LINE__, NULL);
			assert_unsigned_integerArray_notEqual(UI{0, 0, 0}, 3, UI{0, 0, 0}, 3, __LINE__, NULL);


		end_module();
		//----------------------------------------------------------------------------


		//----------------------assert_unsigned_integerArray_sorted-------------------------
		//Tests that will fail:
		start_module("unsigned_integerArray - sorted", "Every assert in this module must fail.", (char *[]){"assert_unsigned_integerArray_sorted", NULL});
			verbose = LOW;
			assert_unsigned_integerArray_sorted(UI{1, 0}, 2, ASC, __LINE__, NULL);
			assert_unsigned_integerArray_sorted(UI{0, 1}, 2, DSC, __LINE__, NULL);

			verbose = MEDIUM;
			assert_unsigned_integerArray_sorted(UI{1, 0}, 2, ASC, __LINE__, NULL);
			assert_unsigned_integerArray_sorted(UI{0, 1}, 2, DSC, __LINE__, NULL);

			verbose = HIGH;
			assert_unsigned_integerArray_sorted(UI{1, 0}, 2, ASC, __LINE__, NULL);
			assert_unsigned_integerArray_sorted(UI{1, 2, 3, 2, 4, 5, 6}, 7, ASC, __LINE__, NULL);
			assert_unsigned_integerArray_sorted(UI{1, 2, 3, 4, 5, 6, 7, 7, 8, 9, 10, 9}, 12, ASC, __LINE__, NULL);
			assert_unsigned_integerArray_sorted(UI{1, 200, 3000, 4238, 5209, 6000, 7001, 77003980, 8090, 999, 10, 9}, 12, ASC, __LINE__, NULL);
			assert_unsigned_integerArray_sorted(UI{0, 1}, 2, DSC, __LINE__, NULL);
			assert_unsigned_integerArray_sorted(UI{0, 0, 0, 0, 1}, 5, DSC, __LINE__, NULL);
			assert_unsigned_integerArray_sorted(UI{100, 99, 98, 100, 0}, 5, DSC, __LINE__, NULL);


		end_module();
		//----------------------------------------------------------------------------

		//----------------------assert_unsigned_integerArray_notSorted-------------------------
		//Tests that will fail:
		start_module("u_iArray - notSorted", "Every assert in this module must fail.", (char *[]){"assert_unsigned_integerArray_notSorted", NULL});
			verbose = LOW;
			assert_unsigned_integerArray_notSorted(UI{1, 0}, 2, DSC, __LINE__, NULL);
			assert_unsigned_integerArray_notSorted(UI{0, 1}, 2, ASC, __LINE__, NULL);

			verbose = MEDIUM;
			assert_unsigned_integerArray_notSorted(UI{1, 0}, 2, DSC, __LINE__, NULL);
			assert_unsigned_integerArray_notSorted(UI{0, 1}, 2, ASC, __LINE__, NULL);

			verbose = HIGH;
			assert_unsigned_integerArray_notSorted(UI{0}, 1, DSC, __LINE__, NULL);
			assert_unsigned_integerArray_notSorted(UI{1, 1, 1}, 3, DSC, __LINE__, NULL);
			assert_unsigned_integerArray_notSorted(UI{1, 0}, 2, DSC, __LINE__, NULL);
			assert_unsigned_integerArray_notSorted(UI{1, 2, 3, 3, 4, 5, 6}, 7, ASC, __LINE__, NULL);
			assert_unsigned_integerArray_notSorted(UI{1, 2, 3, 4, 5, 6, 7, 7, 8, 9, 10, 11}, 12, ASC, __LINE__, NULL);
			assert_unsigned_integerArray_notSorted(UI{1, 200, 3000, 4238, 5209, 6000, 7001, 7002, 8090, 9999, 10876, 95678}, 12, ASC, __LINE__, NULL);
			assert_unsigned_integerArray_notSorted(UI{0, 1}, 2, ASC, __LINE__, NULL);
			assert_unsigned_integerArray_notSorted(UI{1, 0, 0, 0, 0}, 5, DSC, __LINE__, NULL);
			assert_unsigned_integerArray_notSorted(UI{100, 99, 98, 98, 0}, 5, DSC, __LINE__, NULL);


		end_module();
		//----------------------------------------------------------------------------


	end_suite();
	//----------------------------------------------------------------------------

	return 0;
}