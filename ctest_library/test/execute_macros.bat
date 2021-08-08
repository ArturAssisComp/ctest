@echo off
cls
echo FIRST SUITE --^> SUCCESSES
gcc test_std_assert_macros_success.c ../ctest/ctest.c ../assert/assert_aux_functions.c ../assert/std_assert_functions.c  ../aux_libs/text_formatting.c  
a
del a.exe
pause
cls
echo.
echo SECOND SUITE --^>  FAILS:
gcc test_std_assert_macros_fail.c ../ctest/ctest.c ../assert/assert_aux_functions.c ../assert/std_assert_functions.c  ../aux_libs/text_formatting.c  
a
del a.exe
pause
cls
echo.
echo LAST SUITE --^> IGNORES:
gcc test_std_assert_macros_ignore.c ../ctest/ctest.c ../assert/assert_aux_functions.c ../assert/std_assert_functions.c  ../aux_libs/text_formatting.c  
a
del a.exe
pause