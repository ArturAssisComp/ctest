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
	start_suite("FAIL", "ALL tests in this suite must fail.", functions_tested);

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

	end_suite();
	//----------------------------------------------------------------------------

	return 0;
}