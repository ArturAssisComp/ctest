@echo off
gcc test_std_assert_functions_fail.c ../ctest/ctest.c ../assert/assert_aux_functions.c ../assert/std_assert_functions.c  ../aux_libs/text_formatting.c  
a
del a.exe
gcc test_std_assert_functions_ignore.c ../ctest/ctest.c ../assert/assert_aux_functions.c ../assert/std_assert_functions.c  ../aux_libs/text_formatting.c  
a
del a.exe
gcc test_std_assert_functions_success.c ../ctest/ctest.c ../assert/assert_aux_functions.c ../assert/std_assert_functions.c  ../aux_libs/text_formatting.c  
a
del a.exe
pause