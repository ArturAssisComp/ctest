#include "ctest.h"

#define UI (unsigned int[])
#define UC (unsigned char[])
#define ULI (unsigned long int[])
#define ULLI (unsigned long long int[])

#define ARR_SZ(ARR) sizeof (ARR) / sizeof (ARR)[0]

#define ASC true
#define DSC false

int main(void)
{
	char *functions_tested[] = {
		/*Arrays*/
		//unsigned_integer type:
		"ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL",
		"ASSERT_UNSIGNED_INTEGER_ARRAY_NOT_EQUAL",
		"ASSERT_UNSIGNED_INTEGER_ARRAY_SORTED",
		"ASSERT_UNSIGNED_INTEGER_ARRAY_NOT_SORTED",
		"ASSERT_UNSIGNED_INTEGER_ARRAY_PERMUTATION",
		"ASSERT_UNSIGNED_INTEGER_ARRAY_NOT_PERMUTATION",
		"ASSERT_UI_ARRAY_HAS_PP",
		//integer type:
		//floating_point type:
		//bool type:
		NULL
	};

	//----------------------------------------------------------------------------
	start_suite("IGNORE TEST", "Test if each assert is ignored.", functions_tested);

		//----------------------------------------------------------------------------
		//Tests that will be ignored:
		start_module("Ignore", "Ignore the following tests.", functions_tested);
ignore = true;
			ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL( (ULLI{0, 0, 0, 0}), 4, (ULLI{0, 0, 0, 0}), 4, __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_NOT_EQUAL( (ULLI{0, 0, 10, 0}), 4, (ULLI{0, 0, 0, 0}), 4, __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_SORTED( (ULLI{0, 0, 10, 0}), 4, ASC, __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_NOT_SORTED( (ULLI{0, 0, 10, 0}), 4, ASC, __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_PERMUTATION( (ULLI{0, 0, 0}), 3, (ULLI{0, 0, 0, 0}), 4, __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_NOT_PERMUTATION( (UI{1}), 1, (UI{2}), 1, __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_IS_PARTIAL_PERMUTATION( (UC{1, 2, 3}), 3, (UC{1, 3, 2}), 3, __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_NOT_IS_PARTIAL_PERMUTATION( (UI{1}), 1, (UI{2, 3, 4, 1}), 4, __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_HAS_PARTIAL_PERMUTATION( (ULI{1, 2, 3}), 3, (UC{1, 2, 3}), 3, __LINE__, NULL);
ignore = false;
		end_module();
		//----------------------------------------------------------------------------

	end_suite();
	//----------------------------------------------------------------------------

	return 0;
}
