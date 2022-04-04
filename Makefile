CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c18 -O3
T_CFLAGS=-Wall -Wextra -pedantic -std=c18 $$(pkg-config --cflags cunit)
T_LIBS=$$(pkg-config --libs cunit)
LIB_PATH=/usr/lib/
INCLUDE_PATH=/usr/include/
TARGET=libtensor.a
TEST=tensor_test
BUILD=build
DEP_LIST=dep.list


OBJFILES=\
tensor.o\
tensor_generic.o\
tensor_float.o\
tensor_int8.o


T_OBJFILES=\
test.o\
test_tensor_generic.o


all: tensor

gen_doc:
	doxygen Doxyfile


test: env $(T_OBJFILES) $(OBJFILES) 
	$(CC) $(T_CFLAGS) $(OBJFILES) $(T_OBJFILES) $(T_LIBS) -o $(BUILD)/$(TEST)


autotest: test
	$(BUILD)/$(TEST)


tensor: env $(OBJFILES)
	ar rcs $(BUILD)/$(TARGET) $(OBJFILES)


%.o :
ifneq (,$(wildcard $(DEP_LIST)))
	$(CC) $(CFLAGS) -c $<
endif



dep:
	$(CC) -MM src/*.c test/*.c > $(DEP_LIST)


-include $(DEP_LIST)


env:
	mkdir -pv $(BUILD)


install:
	mkdir -pv $(INCLUDE_PATH)/lib-tensor/
	cp -rv src/include/*.h $(INCLUDE_PATH)/lib-tensor 
	cp -v $(BUILD)/$(TARGET) $(LIB_PATH) 


uninstall:
	rm -rvf $(INCLUDE_PATH)/lib-tensor/
	rm -fv $(LIB_PATH)/$(TARGET)


clean:
	rm -vfr $(BUILD)
	rm -vf $(OBJFILES)
	rm -vf $(DEP_LIST)


