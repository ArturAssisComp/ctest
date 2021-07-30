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
		NULL
	};

	//----------------------------------------------------------------------------
	start_suite("SUCCESS", "ALL tests in this suite must be successful.", functions_tested);

		//----------------------assert_unsigned_integer_equal-------------------------
		//----------------------------------------------------------------------------
		//Tests that will be successful:
		start_module("unsigned_integer - Equal", "Every assert in this module must pass.", (char *[]){"assert_unsigned_integer_equal", NULL});
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

		//----------------------assert_unsigned_integer_notEqual----------------------
		//Tests that will be successful:
		start_module("unsigned_integer - notEqual", "Every assert in this module must pass.", (char *[]){"assert_unsigned_integer_notEqual", NULL});
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

		//----------------------assert_unsigned_integer_greater-----------------------
		//Tests that will be successful:
		start_module("unsigned_integer - greater", "Every assert in this module must pass.", (char *[]){"assert_unsigned_integer_greater", NULL});
			assert_unsigned_integer_greater(1, 0, __LINE__, NULL);
			assert_unsigned_integer_greater(2, 1, __LINE__, NULL);
			assert_unsigned_integer_greater(3, 2, __LINE__, NULL);
			assert_unsigned_integer_greater(2, 0, __LINE__, NULL);
			assert_unsigned_integer_greater(3, 2, __LINE__, NULL);
			assert_unsigned_integer_greater(87, 14, __LINE__, NULL);
			assert_unsigned_integer_greater(100, 20, __LINE__, NULL);
			assert_unsigned_integer_greater(127139, 12739, __LINE__, NULL);
			a1 = 1022; a3 = 102;
			assert_unsigned_integer_greater(a1, a3, __LINE__, NULL);
			a2 = 35; a4 = 3;
			assert_unsigned_integer_greater(a2, a4, __LINE__, NULL);
		end_module();

		//----------------------------------------------------------------------------

		//----------------------assert_unsigned_integer_greaterEqual------------------
		//Tests that will be successful:
		start_module("unsigned_integer - greaterEqual", "Every assert in this module must pass.", (char *[]){"assert_unsigned_integer_greaterEqual", NULL});
			assert_unsigned_integer_greaterEqual(1, 0, __LINE__, NULL);
			assert_unsigned_integer_greaterEqual(2, 1, __LINE__, NULL);
			assert_unsigned_integer_greaterEqual(3, 2, __LINE__, NULL);
			assert_unsigned_integer_greaterEqual(2, 0, __LINE__, NULL);
			assert_unsigned_integer_greaterEqual(2, 2, __LINE__, NULL);
			assert_unsigned_integer_greaterEqual(87, 14, __LINE__, NULL);
			assert_unsigned_integer_greaterEqual(100, 20, __LINE__, NULL);
			assert_unsigned_integer_greaterEqual(127139, 12739, __LINE__, NULL);
			a1 = 1022; a3 = 102;
			assert_unsigned_integer_greaterEqual(a1, a3, __LINE__, NULL);
			a2 = 35; a4 = 3;
			assert_unsigned_integer_greaterEqual(a2, a4, __LINE__, NULL);
		end_module();

		//----------------------------------------------------------------------------

		//----------------------assert_unsigned_integer_less--------------------------
		//Tests that will be successful:
		start_module("unsigned_integer - less", "Every assert in this module must pass.", (char *[]){"assert_unsigned_integer_less", NULL});
			assert_unsigned_integer_less (0, 1, __LINE__, NULL);
			assert_unsigned_integer_less (1, 2, __LINE__, NULL);
			assert_unsigned_integer_less (2, 3, __LINE__, NULL);
			assert_unsigned_integer_less (0, 2, __LINE__, NULL);
			assert_unsigned_integer_less (2, 4, __LINE__, NULL);
			assert_unsigned_integer_less (14, 87, __LINE__, NULL);
			assert_unsigned_integer_less (20, 100, __LINE__, NULL);
			assert_unsigned_integer_less (12739, 127139, __LINE__, NULL);
			a1 = 1022; a3 = 102;
			assert_unsigned_integer_less (a3, a1, __LINE__, NULL);
			a2 = 35; a4 = 3;
			assert_unsigned_integer_less (a4, a2, __LINE__, NULL);
		end_module();

		//----------------------------------------------------------------------------

		//----------------------assert_unsigned_integer_lessEqual---------------------
		//Tests that will be successful:
		start_module("unsigned_integer - lessEqual", "Every assert in this module must pass.", (char *[]){"assert_unsigned_integer_lessEqual", NULL});
			assert_unsigned_integer_lessEqual (0, 1, __LINE__, NULL);
			assert_unsigned_integer_lessEqual (1, 2, __LINE__, NULL);
			assert_unsigned_integer_lessEqual (2, 2, __LINE__, NULL);
			assert_unsigned_integer_lessEqual (0, 2, __LINE__, NULL);
			assert_unsigned_integer_lessEqual (2, 4, __LINE__, NULL);
			assert_unsigned_integer_lessEqual (14, 87, __LINE__, NULL);
			assert_unsigned_integer_lessEqual (20, 20, __LINE__, NULL);
			assert_unsigned_integer_lessEqual (12739, 127139, __LINE__, NULL);
			a1 = 1022; a3 = 102;
			assert_unsigned_integer_lessEqual (a3, a1, __LINE__, NULL);
			a2 = 35; a4 = 3;
			assert_unsigned_integer_lessEqual (a4, a2, __LINE__, NULL);
		end_module();

		//----------------------------------------------------------------------------

		//----------------------assert_unsigned_integer_bitMaskEqual------------------
		//Tests that will be successful:
		start_module("unsigned_integer - bitMaskEqual", "Every assert in this module must pass.", (char *[]){"assert_unsigned_integer_bitMaskEqual", NULL});
			assert_unsigned_integer_bitMaskEqual(0x4B, 0xC2, 0x0, __LINE__, NULL);   //0b0100.1011 - 0b1100.0010 with mask 0b0000.0000
			assert_unsigned_integer_bitMaskEqual(0x4C, 0xC2, 0x1, __LINE__, NULL);   //0b0100.1100 - 0b1100.0010 with mask 0b0001
			assert_unsigned_integer_bitMaskEqual(0x4B, 0xC2, 0x60, __LINE__, NULL);  //0b0100.1011 - 0b1100.0010 with mask 0b0110.0000
			assert_unsigned_integer_bitMaskEqual(0x4B, 0xC2, 0x460, __LINE__, NULL); //0b0100.1011 - 0b1100.0010 with mask 0b0100.0110.0000
			assert_unsigned_integer_bitMaskEqual(0x6, 0x6, 0xF, __LINE__, NULL); //0b0110 - 0b0110 with mask 0b1111
			assert_unsigned_integer_bitMaskEqual(0x6, 0x6, 0xFF, __LINE__, NULL); //0b0110 - 0b0110 with mask 0b1111.1111
			assert_unsigned_integer_bitMaskEqual(0x6, ~0x9, 0xF, __LINE__, NULL); //0b0110 - ~0b1001 with mask 0b1111
			assert_unsigned_integer_bitMaskEqual(0xD25, 0x5A5, 0x373C, __LINE__, NULL); //0b1101.0010.0101 - 0b0101.1010.0101 with mask 0b0011.0111.0011.1100
		end_module();

		//----------------------------------------------------------------------------

		//----------------------assert_integer_equal-------------------------
		//----------------------------------------------------------------------------
		//Tests that will be successful:
		start_module("integer - Equal", "Every assert in this module must pass.", (char *[]){"assert_integer_equal", NULL});
			assert_integer_equal(0, 0, __LINE__, NULL);
			assert_integer_equal(1, 1, __LINE__, NULL);
			assert_integer_equal(2, 2, __LINE__, "2 == 2");
			assert_integer_equal(3, 3, __LINE__, NULL);
			assert_integer_equal(4, 4, __LINE__, NULL);
			assert_integer_equal(5, 5, __LINE__, NULL);
			assert_integer_equal(100, 100, __LINE__, NULL);
			assert_integer_equal(12739, 12739, __LINE__, NULL);
			a1 = 102; a2 = 102;
			assert_integer_equal(a1, a2, __LINE__, NULL);
			a3 = 35; a4 = 35;
			assert_integer_equal(a3, a4, __LINE__, NULL);
		end_module();
		//----------------------------------------------------------------------------

		//----------------------assert_integer_notEqual----------------------
		//Tests that will be successful:
		start_module("integer - notEqual", "Every assert in this module must pass.", (char *[]){"assert_integer_notEqual", NULL});
			assert_integer_notEqual(1, 0, __LINE__, NULL);
			assert_integer_notEqual(0, 1, __LINE__, NULL);
			assert_integer_notEqual(1, 2, __LINE__, "2 == 2");
			assert_integer_notEqual(2, 1, __LINE__, NULL);
			assert_integer_notEqual(0, 4, __LINE__, NULL);
			assert_integer_notEqual(87, 123, __LINE__, NULL);
			assert_integer_notEqual(100, 1020, __LINE__, NULL);
			assert_integer_notEqual(127139, 12739, __LINE__, NULL);
			a1 = 1022; a2 = 102;
			assert_integer_notEqual(a1, a2, __LINE__, NULL);
			a3 = 35; a4 = 45;
			assert_integer_notEqual(a3, a4, __LINE__, NULL);
		end_module();

		//----------------------------------------------------------------------------

		//----------------------assert_integer_greater-----------------------
		//Tests that will be successful:
		start_module("integer - greater", "Every assert in this module must pass.", (char *[]){"assert_integer_greater", NULL});
			assert_integer_greater(1, 0, __LINE__, NULL);
			assert_integer_greater(2, 1, __LINE__, NULL);
			assert_integer_greater(3, 2, __LINE__, NULL);
			assert_integer_greater(-2, -10, __LINE__, NULL);
			assert_integer_greater(3, 2, __LINE__, NULL);
			assert_integer_greater(87, 14, __LINE__, NULL);
			assert_integer_greater(100, 20, __LINE__, NULL);
			assert_integer_greater(127139, 12739, __LINE__, NULL);
			a1 = 1022; a3 = 102;
			assert_integer_greater(a1, a3, __LINE__, NULL);
			a2 = 35; a4 = 3;
			assert_integer_greater(a2, a4, __LINE__, NULL);
		end_module();

		//----------------------------------------------------------------------------

		//----------------------assert_integer_greaterEqual------------------
		//Tests that will be successful:
		start_module("integer - greaterEqual", "Every assert in this module must pass.", (char *[]){"assert_integer_greaterEqual", NULL});
			assert_integer_greaterEqual(1, 0, __LINE__, NULL);
			assert_integer_greaterEqual(-2, -13, __LINE__, NULL);
			assert_integer_greaterEqual(3, 2, __LINE__, NULL);
			assert_integer_greaterEqual(2, 0, __LINE__, NULL);
			assert_integer_greaterEqual(2, 2, __LINE__, NULL);
			assert_integer_greaterEqual(87, 14, __LINE__, NULL);
			assert_integer_greaterEqual(100, -20, __LINE__, NULL);
			assert_integer_greaterEqual(127139, 12739, __LINE__, NULL);
			a1 = 1022; a3 = 102;
			assert_integer_greaterEqual(a1, a3, __LINE__, NULL);
			a2 = 35; a4 = 3;
			assert_integer_greaterEqual(a2, a4, __LINE__, NULL);
		end_module();

		//----------------------------------------------------------------------------

	end_suite();
	//----------------------------------------------------------------------------

	return 0;
}