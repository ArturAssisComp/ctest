base_lib_dir    = ./build/ctest_lib
tmp_lib_dir     = $(base_lib_dir)/tmp
include_lib_dir = $(base_lib_dir)/include
archive_lib_dir = $(base_lib_dir)/lib
obj_dir         = ./build/obj
test_dir        = ./ctest_library/test

include_files = $(addprefix ./ctest_library/, $(addprefix assert/, assert.h std_assert_macros.h) $(addprefix aux_libs/, array.h counter_dict.h dict.h hash_function.h linked_list.h text_formatting.h types.h) $(addprefix ctest/, ctest.h ctest_functions.h) $(addprefix globals/, globals.h))
source_files  = $(addprefix ./ctest_library/, $(addprefix assert/, assert_aux_functions.c std_assert_functions.c) $(addprefix aux_libs/, array.c counter_dict.c dict.c hash_function.c linked_list.c text_formatting.c types.c) $(addprefix ctest/, ctest.c))
objects       = $(addprefix $(obj_dir)/, assert_aux_functions.o std_assert_functions.o array.o counter_dict.o dict.o hash_function.o linked_list.o text_formatting.o types.o ctest.o)

create_lib: build $(base_lib_dir) $(include_lib_dir) $(obj_dir) $(archive_lib_dir) $(tmp_lib_dir)  $(archive_lib_dir)/ctest.a
	rm -fr $(tmp_lib_dir)

build:
	mkdir build

$(base_lib_dir): 
	mkdir $(base_lib_dir) 

$(include_lib_dir): $(include_files)
	rm -fr $(include_lib_dir)/
	mkdir $(include_lib_dir)
	@echo Update include files
	cp $(include_files) $(include_lib_dir)

$(obj_dir):
	mkdir $(obj_dir)


$(archive_lib_dir):
	mkdir $(archive_lib_dir)

$(tmp_lib_dir):
	mkdir $(tmp_lib_dir)
	@echo Update temp file
	cp $(include_files) $(source_files) $(tmp_lib_dir)/

$(archive_lib_dir)/ctest.a: $(objects)
	ar r $(archive_lib_dir)/ctest.a $(obj_dir)/*.o


$(obj_dir)/assert_aux_functions.o: ctest_library/assert/assert_aux_functions.c ctest_library/assert/assert.h ctest_library/globals/globals.h ctest_library/aux_libs/text_formatting.h 
	cc -c $(tmp_lib_dir)/assert_aux_functions.c -o $(obj_dir)/assert_aux_functions.o

$(obj_dir)/std_assert_functions.o: ctest_library/assert/std_assert_functions.c ctest_library/assert/assert.h ctest_library/globals/globals.h  ctest_library/aux_libs/types.h  ctest_library/aux_libs/array.h ctest_library/aux_libs/counter_dict.h ctest_library/aux_libs/text_formatting.h
	cc -c $(tmp_lib_dir)/std_assert_functions.c -o $(obj_dir)/std_assert_functions.o


$(obj_dir)/array.o: ctest_library/aux_libs/array.c ctest_library/aux_libs/array.h 
	cc -c $(tmp_lib_dir)/array.c -o $(obj_dir)/array.o

$(obj_dir)/counter_dict.o: ctest_library/aux_libs/counter_dict.c ctest_library/aux_libs/counter_dict.h 
	cc -c $(tmp_lib_dir)/counter_dict.c -o $(obj_dir)/counter_dict.o

$(obj_dir)/dict.o: ctest_library/aux_libs/dict.c ctest_library/aux_libs/dict.h 
	cc -c $(tmp_lib_dir)/dict.c -o $(obj_dir)/dict.o

$(obj_dir)/hash_function.o: ctest_library/aux_libs/hash_function.c ctest_library/aux_libs/hash_function.h 
	cc -c $(tmp_lib_dir)/hash_function.c -o $(obj_dir)/hash_function.o

$(obj_dir)/linked_list.o: ctest_library/aux_libs/linked_list.c ctest_library/aux_libs/linked_list.h 
	cc -c $(tmp_lib_dir)/linked_list.c -o $(obj_dir)/linked_list.o

$(obj_dir)/text_formatting.o: ctest_library/aux_libs/text_formatting.c ctest_library/aux_libs/text_formatting.h 
	cc -c $(tmp_lib_dir)/text_formatting.c -o $(obj_dir)/text_formatting.o

$(obj_dir)/types.o: ctest_library/aux_libs/types.c ctest_library/aux_libs/types.h 
	cc -c $(tmp_lib_dir)/types.c -o $(obj_dir)/types.o


$(obj_dir)/ctest.o: ctest_library/ctest/ctest.c ctest_library/ctest/ctest_functions.h ctest_library/aux_libs/text_formatting.h ctest_library/globals/globals.h 
	cc -c $(tmp_lib_dir)/ctest.c -o $(obj_dir)/ctest.o

.PHONY: clean test test_to_txt
.SILENT: test

clean:
	rm -fr ./build

test: create_lib
	rm -fr test_tmp
	mkdir test_tmp
	cp $(include_lib_dir)/*.h $(archive_lib_dir)/ctest.a $(test_dir)/test_*.c ./test_tmp/
	@echo FUNCTIONS
	@echo FIRST SUITE: SUCCESSES
	@echo press any button
	read
	cc test_tmp/test_std_assert_functions_success.c test_tmp/ctest.a -o test.out
	./test.out | less +G
	rm ./test.out
	@echo SECOND SUITE: FAILURES 
	@echo press any button
	read
	cc test_tmp/test_std_assert_functions_fail.c test_tmp/ctest.a -o test.out
	./test.out | less +G
	rm ./test.out
	@echo THIRD SUITE: IGNORES 
	@echo press any button
	read
	cc test_tmp/test_std_assert_functions_ignore.c test_tmp/ctest.a -o test.out
	./test.out | less +G
	rm ./test.out
	@echo MACROS 
	@echo FIRST SUITE: SUCCESSES
	@echo press any button
	read
	cc test_tmp/test_std_assert_macros_success.c test_tmp/ctest.a -o test.out
	./test.out | less +G
	rm ./test.out
	@echo SECOND SUITE: FAILURES 
	@echo press any button
	read
	cc test_tmp/test_std_assert_macros_fail.c test_tmp/ctest.a -o test.out
	./test.out | less +G
	rm ./test.out
	@echo THIRD SUITE: IGNORES 
	@echo press any button
	read
	cc test_tmp/test_std_assert_macros_ignore.c test_tmp/ctest.a -o test.out
	./test.out | less +G
	rm ./test.out
	rm -fr test_tmp
	

test_to_txt: create_lib
	rm -fr test_tmp build/test_results
	mkdir test_tmp
	mkdir build/test_results
	cp $(include_lib_dir)/*.h $(archive_lib_dir)/ctest.a $(test_dir)/test_*.c ./test_tmp/
	cc test_tmp/test_std_assert_functions_success.c test_tmp/ctest.a -o test.out
	./test.out > build/test_results/functions_successes.txt
	rm ./test.out
	
	cc test_tmp/test_std_assert_functions_fail.c test_tmp/ctest.a -o test.out
	./test.out > build/test_results/functions_failures.txt
	rm ./test.out
	
	cc test_tmp/test_std_assert_functions_ignore.c test_tmp/ctest.a -o test.out
	./test.out > build/test_results/functions_ignores.txt
	rm ./test.out
	
	cc test_tmp/test_std_assert_macros_success.c test_tmp/ctest.a -o test.out
	./test.out > build/test_results/macros_successes.txt
	rm ./test.out
	
	cc test_tmp/test_std_assert_macros_fail.c test_tmp/ctest.a -o test.out
	./test.out > build/test_results/macros_failures.txt
	rm ./test.out
	
	cc test_tmp/test_std_assert_macros_ignore.c test_tmp/ctest.a -o test.out
	./test.out > build/test_results/macros_ignores.txt
	rm ./test.out
	rm -fr test_tmp

