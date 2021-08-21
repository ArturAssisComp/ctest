#include "../ctest/ctest.h"

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
		/*Single data type*/
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
	start_suite("SUCCESS", "ALL tests in this suite must be successful.", functions_tested);

		/*Single data type*/
		/*TEST CASES for unsigned_integer*/
		
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

		/*TEST CASES for integer*/

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

		//----------------------assert_integer_less--------------------------
		//Tests that will be successful:
		start_module("integer - less", "Every assert in this module must pass.", (char *[]){"assert_integer_less", NULL});
			assert_integer_less (0, 1, __LINE__, NULL);
			assert_integer_less (1, 2, __LINE__, NULL);
			assert_integer_less (2, 3, __LINE__, NULL);
			assert_integer_less (0, 2, __LINE__, NULL);
			assert_integer_less (2, 4, __LINE__, NULL);
			assert_integer_less (-14, 87, __LINE__, NULL);
			assert_integer_less (20, 100, __LINE__, NULL);
			assert_integer_less (-12739, 127139, __LINE__, NULL);
			a1 = 1022; a3 = 102;
			assert_integer_less (a3, a1, __LINE__, NULL);
			a2 = 35; a4 = 3;
			assert_integer_less (a4, a2, __LINE__, NULL);
		end_module();

		//----------------------------------------------------------------------------

		//----------------------assert_integer_lessEqual---------------------
		//Tests that will be successful:
		start_module("integer - lessEqual", "Every assert in this module must pass.", (char *[]){"assert_integer_lessEqual", NULL});
			assert_integer_lessEqual (0, 1, __LINE__, NULL);
			assert_integer_lessEqual (1, 2, __LINE__, NULL);
			assert_integer_lessEqual (2, 2, __LINE__, NULL);
			assert_integer_lessEqual (0, 2, __LINE__, NULL);
			assert_integer_lessEqual (-2, 4, __LINE__, NULL);
			assert_integer_lessEqual (14, 87, __LINE__, NULL);
			assert_integer_lessEqual (20, 20, __LINE__, NULL);
			assert_integer_lessEqual (12739, 127139, __LINE__, NULL);
			a1 = 1022; a3 = 102;
			assert_integer_lessEqual (a3, a1, __LINE__, NULL);
			a2 = 35; a4 = 3;
			assert_integer_lessEqual (a4, a2, __LINE__, NULL);
		end_module();

		//----------------------------------------------------------------------------

		/*TEST CASES for floating_point*/

		//----------------------assert_floating_point_almostEqual-------------------------
		//Tests that will be successful:
		floating_point max_diff;
		start_module("floating_point - almostEqual", "Every assert in this module must pass.", (char *[]){"assert_floating_point_almostEqual", NULL});
			max_diff = 0.001;
			assert_floating_point_almostEqual(0.1239, 0.1235, max_diff, __LINE__, NULL);
			assert_floating_point_almostEqual(23.1239, 23.1235, max_diff, __LINE__, NULL);
			assert_floating_point_almostEqual(-90.88898, -90.88878, max_diff, __LINE__, NULL);
			max_diff = 0.0001;
			assert_floating_point_almostEqual(1, 1, max_diff, __LINE__, NULL);
			assert_floating_point_almostEqual(292.99938291, 292.99930001, max_diff, __LINE__, "2 == 2");
			assert_floating_point_almostEqual(-3.90, -3.90, max_diff, __LINE__, NULL);
			assert_floating_point_almostEqual(-4.999, -4.999, max_diff, __LINE__, NULL);
			assert_floating_point_almostEqual(5.299382, 5.29938234, max_diff, __LINE__, NULL);
			max_diff = 0.3;
			assert_floating_point_almostEqual(100.2, 100.1, max_diff, __LINE__, NULL);
			assert_floating_point_almostEqual(12739.1092, 12739.3990, max_diff, __LINE__, NULL);
			max_diff = 100;
			float b1 = 1e3, b2 = 1.09e3;
			assert_floating_point_almostEqual(b1, b2, max_diff, __LINE__, NULL);
			double b3 = 100, b4 = 35;
			assert_floating_point_almostEqual(b3, b4, max_diff, __LINE__, NULL);
		end_module();
		//----------------------------------------------------------------------------

		//----------------------assert_floating_point_notAlmostEqual-------------------------
		//Tests that will be successful:
		floating_point min_diff;
		start_module("floating_point - notAlmostEqual", "Every assert in this module must pass.", (char *[]){"assert_floating_point_notAlmostEqual", NULL});
			min_diff = 0.001;
			assert_floating_point_notAlmostEqual(0.2239, 0.1235, min_diff, __LINE__, NULL);
			assert_floating_point_notAlmostEqual(23.1239, 24.1235, min_diff, __LINE__, NULL);
			assert_floating_point_notAlmostEqual(-90.98898, -90.88878, min_diff, __LINE__, NULL);
			min_diff = 0.0001;
			assert_floating_point_notAlmostEqual(1, 1.001, min_diff, __LINE__, NULL);
			assert_floating_point_notAlmostEqual(292.99938291, 292.999490001, min_diff, __LINE__, "2 == 2");
			assert_floating_point_notAlmostEqual(-3.90, -3.94, min_diff, __LINE__, NULL);
			assert_floating_point_notAlmostEqual(-4.9499, -4.999, min_diff, __LINE__, NULL);
			assert_floating_point_notAlmostEqual(5.299382, 5.29948234, min_diff, __LINE__, NULL);
			min_diff = 0.3;
			assert_floating_point_notAlmostEqual(100.2, 100.7, min_diff, __LINE__, NULL);
			assert_floating_point_notAlmostEqual(1e10, 12739.3990, min_diff, __LINE__, NULL);
			min_diff = 100;
			b1 = 1.23e3; b2 = 1.09e3;
			assert_floating_point_notAlmostEqual(b1, b2, min_diff, __LINE__, NULL);
			b3 = 1030; b4 = 35;
			assert_floating_point_notAlmostEqual(b3, b4, min_diff, __LINE__, NULL);
		end_module();
		//----------------------------------------------------------------------------

		//----------------------assert_floating_point_greater-----------------------
		//Tests that will be successful:
		start_module("floating_point - greater", "Every assert in this module must pass.", (char *[]){"assert_floating_point_greater", NULL});
			assert_floating_point_greater(1.23, 0, __LINE__, NULL);
			assert_floating_point_greater(2e15, 1e3, __LINE__, NULL);
			assert_floating_point_greater(3, 2, __LINE__, NULL);
			assert_floating_point_greater(-2, -1e4, __LINE__, NULL);
			assert_floating_point_greater(322.223, 21.2, __LINE__, NULL);
			assert_floating_point_greater(87.34, -14.23231, __LINE__, NULL);
			assert_floating_point_greater(100, 20, __LINE__, NULL);
			assert_floating_point_greater(127139, 12739, __LINE__, NULL);
			b1 = 1022; b3 = 102;
			assert_floating_point_greater(a1, a3, __LINE__, NULL);
			b2 = 35; b4 = 3;
			assert_floating_point_greater(a2, a4, __LINE__, NULL);
		end_module();

		//----------------------------------------------------------------------------

		//----------------------assert_floating_point_greaterEqual------------------
		//Tests that will be successful:
		start_module("floating_point - greaterEqual", "Every assert in this module must pass.", (char *[]){"assert_floating_point_greaterEqual", NULL});
			assert_floating_point_greaterEqual(0, 0, __LINE__, NULL);
			assert_floating_point_greaterEqual(0.298765, 0.29876, __LINE__, NULL);
			assert_floating_point_greaterEqual(1, 0, __LINE__, NULL);
			assert_floating_point_greaterEqual(2, 1, __LINE__, NULL);
			assert_floating_point_greaterEqual(3, 2, __LINE__, NULL);
			assert_floating_point_greaterEqual(2, 0, __LINE__, NULL);
			assert_floating_point_greaterEqual(2.982, 2, __LINE__, NULL);
			assert_floating_point_greaterEqual(87.09, -14, __LINE__, NULL);
			assert_floating_point_greaterEqual(100, 20, __LINE__, NULL);
			assert_floating_point_greaterEqual(127139, 12739, __LINE__, NULL);
			b1 = 1022; b3 = 102;
			assert_floating_point_greaterEqual(b1, b3, __LINE__, NULL);
			b2 = 35; b4 = 3e-2;
			assert_floating_point_greaterEqual(b2, b4, __LINE__, NULL);
		end_module();

		//----------------------------------------------------------------------------

		//----------------------assert_floating_point_less--------------------------
		//Tests that will be successful:
		start_module("floating_point - less", "Every assert in this module must pass.", (char *[]){"assert_floating_point_less", NULL});
			assert_floating_point_less (0.971, 1.2389, __LINE__, NULL);
			assert_floating_point_less (1, 2, __LINE__, NULL);
			assert_floating_point_less (0, 2, __LINE__, NULL);
			assert_floating_point_less (-2.092, 3.23098, __LINE__, NULL);
			assert_floating_point_less (0.29e2, 0.2e3, __LINE__, NULL);
			assert_floating_point_less (2.23, 4.23, __LINE__, NULL);
			assert_floating_point_less (-14, 87, __LINE__, NULL);
			assert_floating_point_less (20, 100, __LINE__, NULL);
			assert_floating_point_less (12739, 127139, __LINE__, NULL);
			b1 = 1022; b3 = 102;
			assert_floating_point_less (b3, b1, __LINE__, NULL);
			b2 = 35; b4 = 3;
			assert_floating_point_less (b4, b2, __LINE__, NULL);
		end_module();

		//----------------------------------------------------------------------------

		//----------------------assert_floating_point_lessEqual---------------------
		//Tests that will be successful:
		start_module("floating_point - lessEqual", "Every assert in this module must pass.", (char *[]){"assert_floating_point_lessEqual", NULL});
			assert_floating_point_lessEqual (0.4108, 1, __LINE__, NULL);
			assert_floating_point_lessEqual (1, 2, __LINE__, NULL);
			assert_floating_point_lessEqual (0, 0, __LINE__, NULL);
			assert_floating_point_lessEqual (2, 2, __LINE__, NULL);
			assert_floating_point_lessEqual (0.109, 2.19, __LINE__, NULL);
			assert_floating_point_lessEqual (-2, 4, __LINE__, NULL);
			assert_floating_point_lessEqual (-14e4, 87e2, __LINE__, NULL);
			assert_floating_point_lessEqual (20, 20, __LINE__, NULL);
			assert_floating_point_lessEqual (12739, 127139, __LINE__, NULL);
			b1 = 1022; b3 = 102;
			assert_floating_point_lessEqual (b3, b1, __LINE__, NULL);
			b2 = 35; b4 = 3;
			assert_floating_point_lessEqual (b4, b2, __LINE__, NULL);
		end_module();

		//----------------------------------------------------------------------------

		/*TEST CASES for bool*/
		
		//----------------------assert_bool_equal-------------------------
		//----------------------------------------------------------------------------
		//Tests that will be successful:
		start_module("bool - Equal", "Every assert in this module must pass.", (char *[]){"assert_bool_equal", NULL});
			assert_bool_equal(true, true, __LINE__, NULL);
			assert_bool_equal(false, false, __LINE__, NULL);
			assert_bool_equal(2, 2, __LINE__, NULL);
			assert_bool_equal(3, 3, __LINE__, NULL);
			assert_bool_equal(0, 0, __LINE__, NULL);
		end_module();
		//----------------------------------------------------------------------------

		//----------------------assert_bool_notEqual----------------------
		//Tests that will be successful:
		start_module("bool - notEqual", "Every assert in this module must pass.", (char *[]){"assert_bool_notEqual", NULL});
			assert_bool_notEqual(true, false, __LINE__, NULL);
			assert_bool_notEqual(false, true, __LINE__, NULL);
			assert_bool_notEqual(1, 0, __LINE__, NULL);
			assert_bool_notEqual(0, 1, __LINE__, NULL);
		end_module();

		//----------------------------------------------------------------------------

		//----------------------assert_bool_true----------------------
		//Tests that will be successful:
		start_module("bool - true", "Every assert in this module must pass.", (char *[]){"assert_bool_true", NULL});
			assert_bool_true(true, __LINE__, NULL);
			assert_bool_true(2, __LINE__, NULL);

		end_module();

		//----------------------------------------------------------------------------

		//----------------------assert_bool_false----------------------
		//Tests that will be successful:
		start_module("bool - false", "Every assert in this module must pass.", (char *[]){"assert_bool_false", NULL});
			assert_bool_false(false, __LINE__, NULL);
			assert_bool_false(0, __LINE__, NULL);

		end_module();

		//----------------------------------------------------------------------------



		/*Arrays*/
		/*TEST CASES for unsigned_integer*/
		
		//----------------------assert_unsigned_integerArray_equal-------------------------
		//----------------------------------------------------------------------------
		//Tests that will be successful:
		start_module("unsigned_integerArray - Equal", "Every assert in this module must pass.", (char *[]){"assert_unsigned_integerArray_equal", NULL});
			assert_unsigned_integerArray_equal(UI{2}, 1, UI{2}, 1, __LINE__, NULL);
			assert_unsigned_integerArray_equal(UI{0}, 1, UI{0}, 1, __LINE__, NULL);
			assert_unsigned_integerArray_equal(UI{1, 2}, 2, UI{1, 2}, 2, __LINE__, NULL);
			assert_unsigned_integerArray_equal(UI{1, 2, 345}, 3, UI{1, 2, 345}, 3, __LINE__, NULL);
			assert_unsigned_integerArray_equal(UI{1, 2, 4, 4, 4}, 5, UI{1, 2, 4, 4, 4}, 5, __LINE__, NULL);

		end_module();
		//----------------------------------------------------------------------------

		//----------------------assert_unsigned_integerArray_notEqual-------------------------
		//----------------------------------------------------------------------------
		//Tests that will be successful:
		start_module("unsigned_integerArray - notEqual", "Every assert in this module must pass.", (char *[]){"assert_unsigned_integerArray_notEqual", NULL});
			assert_unsigned_integerArray_notEqual(UI{3}, 1, UI{2}, 1, __LINE__, NULL);
			assert_unsigned_integerArray_notEqual(UI{0}, 1, UI{6}, 1, __LINE__, NULL);
			assert_unsigned_integerArray_notEqual(UI{1, 1}, 2, UI{1, 2}, 2, __LINE__, NULL);
			assert_unsigned_integerArray_notEqual(UI{1, 0, 345}, 3, UI{1, 2, 345}, 3, __LINE__, NULL);
			assert_unsigned_integerArray_notEqual(UI{10, 2, 4, 4, 4}, 5, UI{1, 2, 4, 4, 4}, 5, __LINE__, NULL);
			assert_unsigned_integerArray_notEqual(UI{1, 2, 345, 4}, 4, UI{1, 2, 345}, 3, __LINE__, NULL);

		end_module();
		//----------------------------------------------------------------------------

		//----------------------assert_unsigned_integerArray_sorted-------------------------
		//----------------------------------------------------------------------------
		//Tests that will be successful:
		start_module("unsigned_integerArray - sorted", "Every assert in this module must pass.", (char *[]){"assert_unsigned_integerArray_sorted", NULL});
			assert_unsigned_integerArray_sorted(UI{1}, 1, ASC, __LINE__, NULL);
			assert_unsigned_integerArray_sorted(UI{0}, 1, ASC, __LINE__, NULL);
			assert_unsigned_integerArray_sorted(UI{10}, 1, DSC, __LINE__, NULL);
			assert_unsigned_integerArray_sorted(UI{1, 2}, 2, ASC, __LINE__, NULL);
			assert_unsigned_integerArray_sorted(UI{4, 4}, 2, ASC, __LINE__, NULL);
			assert_unsigned_integerArray_sorted(UI{4, 4}, 2, DSC, __LINE__, NULL);
			assert_unsigned_integerArray_sorted(UI{4, 1}, 2, DSC, __LINE__, NULL);
			assert_unsigned_integerArray_sorted(UI{1, 2, 3}, 3, ASC, __LINE__, NULL);
			assert_unsigned_integerArray_sorted(UI{1, 2, 3, 3, 4, 5, 5, 5, 6, 6, 7}, 11, ASC, __LINE__, NULL);
			assert_unsigned_integerArray_sorted(UI{1, 1, 1, 1, 1, 1, 1, 1, 0}, 9, DSC, __LINE__, NULL);

		end_module();
		//----------------------------------------------------------------------------

		//----------------------assert_unsigned_integerArray_notSorted-------------------------
		//----------------------------------------------------------------------------
		//Tests that will be successful:
		start_module("u_iArray - notSorted", "Every assert in this module must pass.", (char *[]){"assert_unsigned_integerArray_notSorted", NULL});
			assert_unsigned_integerArray_notSorted(UI{1, 0}, 2, ASC, __LINE__, NULL);
			assert_unsigned_integerArray_notSorted(UI{0, 1}, 2, DSC, __LINE__, NULL);
			assert_unsigned_integerArray_notSorted(UI{10, 11}, 2, DSC, __LINE__, NULL);
			assert_unsigned_integerArray_notSorted(UI{1, 2}, 2, DSC, __LINE__, NULL);
			assert_unsigned_integerArray_notSorted(UI{4, 45}, 2, DSC, __LINE__, NULL);
			assert_unsigned_integerArray_notSorted(UI{1, 2, 1}, 3, ASC, __LINE__, NULL);
			assert_unsigned_integerArray_notSorted(UI{1, 2, 3, 0, 4, 5, 5, 5, 6, 6, 7}, 11, ASC, __LINE__, NULL);
			assert_unsigned_integerArray_notSorted(UI{1, 1, 1, 1, 1, 1, 1, 0, 1}, 9, DSC, __LINE__, NULL);

		end_module();
		//----------------------------------------------------------------------------




	end_suite();
	//----------------------------------------------------------------------------

	return 0;
}