base_lib_dir    = ./build/ctest_lib
tmp_lib_dir     = $(base_lib_dir)/tmp
include_lib_dir = $(base_lib_dir)/include
archive_lib_dir = $(base_lib_dir)/lib
obj_dir         = ./build/obj

include_files = $(addprefix ./ctest_library/, $(addprefix assert/, assert.h std_assert_macros.h) $(addprefix aux_libs/, text_formatting.h) $(addprefix ctest/, ctest.h ctest_functions.h) $(addprefix globals/, globals.h))
source_files  = $(addprefix ./ctest_library/, $(addprefix assert/, assert_aux_functions.c std_assert_functions.c) $(addprefix aux_libs/, text_formatting.c) $(addprefix ctest/, ctest.c))
objects       = $(addprefix $(obj_dir)/, assert_aux_functions.o std_assert_functions.o text_formatting.o ctest.o)

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

$(obj_dir)/std_assert_functions.o: ctest_library/assert/std_assert_functions.c ctest_library/assert/assert.h ctest_library/globals/globals.h
	cc -c $(tmp_lib_dir)/std_assert_functions.c -o $(obj_dir)/std_assert_functions.o

$(obj_dir)/text_formatting.o: ctest_library/aux_libs/text_formatting.c ctest_library/aux_libs/text_formatting.h 
	cc -c $(tmp_lib_dir)/text_formatting.c -o $(obj_dir)/text_formatting.o

$(obj_dir)/ctest.o: ctest_library/ctest/ctest.c ctest_library/ctest/ctest_functions.h ctest_library/aux_libs/text_formatting.h ctest_library/globals/globals.h 
	cc -c $(tmp_lib_dir)/ctest.c -o $(obj_dir)/ctest.o

.PHONY = clean

clean:
	rm -fr ./build
