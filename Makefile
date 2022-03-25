CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c18 -O3
T_CFLAGS=-Wall -Wextra -pedantic -std=c18
T_LIBS=
TARGET=libtensor.a
TEST=tensor_test
BUILD=build
MODULES=\
tensor.o\
tensor_generic.o\
tensor_float.o

all: release gen_doc


gen_doc:
	doxygen Doxyfile


tensor.o: tensor_generic.o tensor_float.o src/tensor.c src/include/tensor.h
	$(CC) $(CFLAGS) -c src/tensor.c -o tensor.o


tensor_generic.o: src/tensor_generic.c src/include/tensor_generic.h
	$(CC) $(CFLAGS) -c src/tensor_generic.c -o tensor_generic.o


tensor_float.o: tensor_generic.o src/tensor_float.c src/include/tensor_float.h
	$(CC) $(CFLAGS) -c src/tensor_float.c -o tensor_float.o


release: env $(MODULES)
	ar rcs $(BUILD)/$(TARGET) $(MODULES)


test.o: test/test.c
	$(CC) $(T_CFLAGS) -c test/test.c -o test.o


test: env test.o $(MODULES)
	$(CC) $(T_CFLAGS) $(MODULES) test.o $(T_LIBS) -o $(BUILD)/$(TEST)
	$(BUILD)/$(TEST)


env:
	mkdir -pv $(BUILD)


install:
	cp src/include/ /usr/include -v
	cp $(BUILD)/$(TARGET) /usr/lib -v


clean:
	rm -vfr $(BUILD)
	rm -vf $(MODULES)


