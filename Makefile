CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c18 -O3
T_CFLAGS=-Wall -Wextra -pedantic -std=c18 $$(pkg-config --cflags cunit)
T_LIBS=$$(pkg-config --libs cunit)
LIB_PATH=/usr/lib/
INCLUDE_PATH=/usr/include/
TARGET=libtensor.a
TEST=tensor_test
BUILD=build

MODULES=\
tensor.o\
tensor_generic.o\
tensor_float.o\
tensor_int8.o

TEST_MODELS=\
test.o\
test_tensor_generic.o


all: release gen_doc


gen_doc:
	doxygen Doxyfile


tensor.o: tensor_generic.o tensor_float.o src/tensor.c src/include/tensor.h
	$(CC) $(CFLAGS) -c src/tensor.c -o tensor.o


tensor_generic.o: src/tensor_generic.c src/include/tensor_generic.h
	$(CC) $(CFLAGS) -c src/tensor_generic.c -o tensor_generic.o


tensor_float.o: tensor_generic.o src/tensor_float.c src/include/tensor_float.h
	$(CC) $(CFLAGS) -c src/tensor_float.c -o tensor_float.o


tensor_int8.o: tensor_generic.o src/tensor_int8.c src/include/tensor_int8.h
	$(CC) $(CFLAGS) -c src/tensor_int8.c -o tensor_int8.o


release: env $(MODULES)
	ar rcs $(BUILD)/$(TARGET) $(MODULES)


test.o: test/test.c
	$(CC) $(T_CFLAGS) -c test/test.c -o test.o


test_tensor_generic.o: test/test_tensor_generic.c test/test_tensor_generic.h tensor_generic.o
	$(CC) $(T_CFLAGS) -c test/test_tensor_generic.c -o test_tensor_generic.o


test: env $(TEST_MODELS) $(MODULES)
	$(CC) $(T_CFLAGS) $(MODULES) $(TEST_MODELS) $(T_LIBS) -o $(BUILD)/$(TEST)
	$(BUILD)/$(TEST)


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
	rm -vf $(MODULES)


