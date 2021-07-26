@echo off
gcc test_std_assert_functions.c ../ctest/ctest.c ../assert/assert_aux_functions.c ../assert/std_assert_functions.c  ../aux_libs/text_formatting.c  
a
del a.exe
pause