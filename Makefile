CC = gcc

all: stackStaticTest stackDynamicTest staticTest dynamicTest

staticTest : stackStaticTest
	./stackStaticTest > staticTest.txt

dynamicTest : stackDynamicTest
	./stackDynamicTest > dynamicTest.txt

stackStaticTest: StackModuleContiguousStatic.o StackModuleTest.o
	$(CC) -o stackStaticTest StackModuleContiguousStatic.o StackModuleTest.o

stackDynamicTest: StackModuleLinkedDynamic.o StackModuleLinkedDynamicTest.o
	$(CC) -o stackDynamicTest StackModuleLinkedDynamic.o StackModuleLinkedDynamicTest.o

StackModuleContiguousStatic.o: StackModuleContiguousStatic.c stackModule.h
	$(CC) -c StackModuleContiguousStatic.c

StackModuleLinkedDynamic.o: StackModuleLinkedDynamic.c stackModule.h
	$(CC) -c StackModuleLinkedDynamic.c

StackModuleTest.o: StackModuleTest.c stackModule.h
	$(CC) -c StackModuleTest.c

StackModuleLinkedDynamicTest.o: StackModuleLinkedDynamicTest.c stackModule.h
	$(CC) -c StackModuleLinkedDynamicTest.c

clean:
	rm -f *.o stackStaticTest stackDynamicTest *.exe *.txt
