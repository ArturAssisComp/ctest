#include "../ctest/ctest.h"

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
		//integer type:
		//floating_point type:
		//bool type:
		NULL
	};
	//----------------------------------------------------------------------------
	start_suite("FAIL", "ALL tests in this suite must fail.", functions_tested);

		/*Arrays*/
		/*TEST CASES for unsigned_integer*/

		//---------------ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL------------------
		//Tests that will fail:
		start_module("UNSIGNED_INTEGER ARRAY-equal", "Every assert in this module must fail.", (char *[]){"ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL", NULL});

			verbose = LOW;
			ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL( (UI{1, 2, 3, 34}), 4, (UC{1, 2, 3}), 3, __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL( (UI{1}), 1, (UI{2}), 1, __LINE__, NULL);
			verbose = MEDIUM;
			ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL( (UI{1, 2, 3, 34}), 4, (UC{1, 2, 3}), 3, __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL( (UI{1}), 1, (UI{2}), 1, __LINE__, NULL);
			unsigned char arr1[] = {12, 23, 34}, arr2[] = {2, 23, 45};
			ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL( arr1, ARR_SZ(arr1), arr2, ARR_SZ(arr2), __LINE__, "arr1 != arr2");

			verbose = HIGH;
			ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL( (ULI{1, 2, 3}), 3, (UC{1, 223, 3}), 3, __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL( (UC{1, 2, 3}), 3, (UC{1, 3, 2}), 3, __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL( (ULLI{0, 0, 0}), 3, (ULLI{0, 0, 0, 0}), 4, __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_EQUAL( arr1, ARR_SZ(arr1), arr2, ARR_SZ(arr2), __LINE__, "arr1 != arr2");

		end_module();
		//----------------------------------------------------------------------------

		//---------------ASSERT_UNSIGNED_INTEGER_ARRAY_NOT_EQUAL------------------
		//Tests that will fail:
		start_module("UNSIGNED_INTEGER ARRAY-notEqual", "Every assert in this module must fail.", (char *[]){"ASSERT_UNSIGNED_INTEGER_ARRAY_NOT_EQUAL", NULL});
			int arr3[] = {12, 34, 2};
			int arr4[] = {12, 34, 2};


			verbose = LOW;
			ASSERT_UNSIGNED_INTEGER_ARRAY_NOT_EQUAL(arr3, ARR_SZ(arr3), arr4, ARR_SZ(arr4), __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_NOT_EQUAL( (ULI{1, 2, 3}), 3, (UC{1, 2, 3}), 3, __LINE__, NULL);

			verbose = MEDIUM;
			ASSERT_UNSIGNED_INTEGER_ARRAY_NOT_EQUAL(arr3, ARR_SZ(arr3), arr4, ARR_SZ(arr4), __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_NOT_EQUAL( (ULI{1, 2, 3}), 3, (UC{1, 2, 3}), 3, __LINE__, "{1, 2, 3}=={1, 2, 3}");

			verbose = HIGH;
			ASSERT_UNSIGNED_INTEGER_ARRAY_NOT_EQUAL(arr3, ARR_SZ(arr3), arr4, ARR_SZ(arr4), __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_NOT_EQUAL( (ULI{1, 2, 3}), 3, (UC{1, 2, 3}), 3, __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_NOT_EQUAL( (UC{1, 3, 2}), 3, (UC{1, 3, 2}), 3, __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_NOT_EQUAL( (ULLI{0, 0, 0, 0}), 4, (ULLI{0, 0, 0, 0}), 4, __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_NOT_EQUAL( (ULLI{10}), 1, (ULLI{10}), 1, __LINE__, NULL);


		end_module();
		//----------------------------------------------------------------------------


		//---------------ASSERT_UNSIGNED_INTEGER_ARRAY_SORTED------------------
		//Tests that will fail:
		start_module("UNSIGNED_INTEGER ARRAY-sorted", "Every assert in this module must fail.", (char *[]){"ASSERT_UNSIGNED_INTEGER_ARRAY_SORTED", NULL});
			int arr5[] = {12, 34, 2};
			int arr6[] = {12, 222, 3123, 41231, 5612312, 5, 5, 898, 34, 2};


			verbose = LOW;
			ASSERT_UNSIGNED_INTEGER_ARRAY_SORTED(arr5, ARR_SZ(arr5), ASC, __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_SORTED( (ULI{1, 2, 3}), 3, DSC, __LINE__, NULL);

			verbose = MEDIUM;
			ASSERT_UNSIGNED_INTEGER_ARRAY_SORTED(arr6, ARR_SZ(arr6), ASC, __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_SORTED(arr6, ARR_SZ(arr6), DSC, __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_SORTED( (UC{1, 2, 3}), 3, DSC, __LINE__, "(UC{1, 2, 3}), 3, DSC");

			verbose = HIGH;
			ASSERT_UNSIGNED_INTEGER_ARRAY_SORTED(arr6, ARR_SZ(arr6), ASC, __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_SORTED(arr6, ARR_SZ(arr6), DSC, __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_SORTED( (UC{1, 2, 3}), 3, DSC, __LINE__, "(UC{1, 2, 3}), 3, DSC");
			ASSERT_UNSIGNED_INTEGER_ARRAY_SORTED( (ULI{112, 2, 3}), 3, DSC, __LINE__, NULL);
			ASSERT_UNSIGNED_INTEGER_ARRAY_SORTED( (ULLI{0, 1, 0, 0}), 4, ASC, __LINE__, NULL);


		end_module();
		//----------------------------------------------------------------------------



	end_suite();
	//----------------------------------------------------------------------------

	return 0;
}