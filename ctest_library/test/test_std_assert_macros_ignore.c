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
ignore = false;
		end_module();
		//----------------------------------------------------------------------------

	end_suite();
	//----------------------------------------------------------------------------

	return 0;
}