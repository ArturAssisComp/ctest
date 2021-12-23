#include "ctest.h"

//Short for casting arrays:
#define UI (unsigned_integer[])
#define FP (floating_point[])
#define SI (integer[])
#define BL (bool[])

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
			assert_floating_point_lessEqual      (12.2331, 2.998, __LINE__, NULL);
			assert_bool_equal    (true, true, __LINE__, NULL);
			assert_bool_notEqual (true, true, __LINE__, NULL);
			assert_bool_true     (true, __LINE__, NULL);
			assert_bool_false    (false, __LINE__, NULL);
			assert_unsigned_integerArray_equal(UI{12, 34}, 2, UI{3,3,3,3}, 4, __LINE__, NULL);
			assert_unsigned_integerArray_notEqual(UI{12, 34}, 2, UI{3,3,3,3}, 4, __LINE__, NULL);
			assert_unsigned_integerArray_sorted(UI{1, 2, 3}, 3, true, __LINE__, NULL);
			assert_unsigned_integerArray_notSorted(UI{1, 2, 3}, 3, true, __LINE__, NULL);
			assert_unsigned_integerArray_permutation(UI{1, 1, 4}, 3, UI{1, 3, 1}, 3, __LINE__, NULL);
			assert_unsigned_integerArray_notPermutation(UI{1, 1, 4}, 3, UI{1, 3, 1}, 3, __LINE__, NULL);

ignore = false;
		end_module();
		//----------------------------------------------------------------------------

	end_suite();
	//----------------------------------------------------------------------------

	return 0;
}
