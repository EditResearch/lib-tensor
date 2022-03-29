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


all: release gen_doc


gen_doc:
	doxygen Doxyfile


release: env $(OBJFILES)
	ar rcs $(BUILD)/$(TARGET) $(OBJFILES)


%.o:
	$(CC) $(CFLAGS) -c $<


test: env $(T_OBJFILES) $(OBJFILES) 
	$(CC) $(T_CFLAGS) $(OBJFILES) $(T_OBJFILES) $(T_LIBS) -o $(BUILD)/$(TEST)


autotest: test
	$(BUILD)/$(TEST)


-include $(DEP_LIST)


.PHONY: configure
configure:
	$(CC) -MM src/*.c test/*.c > $(DEP_LIST)


.PHONY: env
env:
	mkdir -pv $(BUILD)


.PHONY: install
install:
	mkdir -pv $(INCLUDE_PATH)/lib-tensor/
	cp -rv src/include/*.h $(INCLUDE_PATH)/lib-tensor 
	cp -v $(BUILD)/$(TARGET) $(LIB_PATH) 


.PHONY: uninstall
uninstall:
	rm -rvf $(INCLUDE_PATH)/lib-tensor/
	rm -fv $(LIB_PATH)/$(TARGET)


.PHONY: clean
clean:
	rm -vfr $(BUILD)
	rm -vf $(OBJFILES)
	rm -vf $(DEP_LIST)


