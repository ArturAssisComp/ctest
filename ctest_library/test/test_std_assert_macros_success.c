#include "../ctest/ctest.h"

#define UI (unsigned int[])
#define UC (unsigned char[])
#define ULI (unsigned long int[])
#define ULLI (unsigned long long int[])

#define ARR_SZ(ARR) sizeof (ARR) / sizeof (ARR)[0]

int main(void)
{
	char *functions_tested[] = {
		/*Arrays*/
		//unsigned_integer type:
		"ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL",
		"ASSERT_UNSIGNED_INTEGER_ARRAY_NOT_EQUAL",
		//integer type:
		//floating_point type:
		//bool type:
		NULL
	};

	//----------------------------------------------------------------------------
	start_suite("SUCCESS", "ALL tests in this suite must be successful.", functions_tested);

		/*Arrays*/
		/*TEST CASES for unsigned_integer*/
		
		//----------------------ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL-------------------
		//----------------------------------------------------------------------------
		//Tests that will be successful:
		start_module("UNSIGNED_INTEGER ARRAY-equal", "Every assert in this module must pass.", (char *[]){"ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL", NULL});
			int arr1[] = {12, 34, 2};
			int arr2[] = {12, 34, 2};
			ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL(arr1, ARR_SZ(arr1), arr2, ARR_SZ(arr2), __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL( (ULI{1, 2, 3}), 3, (UC{1, 2, 3}), 3, __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL( (UC{1, 3, 2}), 3, (UC{1, 3, 2}), 3, __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL( (ULLI{0, 0, 0, 0}), 4, (ULLI{0, 0, 0, 0}), 4, __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL( (ULLI{10}), 1, (ULLI{10}), 1, __LINE__, NULL);


		end_module();
		//----------------------------------------------------------------------------

		//----------------------ASSERT_UNSIGNED_INTEGER_ARRAY_NOT_EQUAL-------------------
		//----------------------------------------------------------------------------
		//Tests that will be successful:
		start_module("UNSIGNED_INTEGER ARRAY-notEqual", "Every assert in this module must pass.", (char *[]){"ASSERT_UNSIGNED_INTEGER_ARRAY_NOT_EQUAL", NULL});

			ASSERT_UNSIGNED_INTEGER_ARRAY_NOT_EQUAL( (UI{1, 2, 3, 34}), 4, (UC{1, 2, 3}), 3, __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_NOT_EQUAL( (UI{1}), 1, (UI{2}), 1, __LINE__, NULL);
			unsigned char arr3[] = {12, 23, 34}, arr4[] = {2, 23, 45};
			ASSERT_UNSIGNED_INTEGER_ARRAY_NOT_EQUAL( arr3, ARR_SZ(arr3), arr4, ARR_SZ(arr4), __LINE__, "arr3 != arr4");
			ASSERT_UNSIGNED_INTEGER_ARRAY_NOT_EQUAL( (ULI{1, 2, 3}), 3, (UC{1, 223, 3}), 3, __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_NOT_EQUAL( (UC{1, 2, 3}), 3, (UC{1, 3, 2}), 3, __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_NOT_EQUAL( (ULLI{0, 0, 0}), 3, (ULLI{0, 0, 0, 0}), 4, __LINE__, NULL);

		end_module();
		//----------------------------------------------------------------------------



	end_suite();
	//----------------------------------------------------------------------------

	return 0;
}