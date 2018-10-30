CC=g++
CCFLAGS= -Wno-deprecated -Wall -g -std=c++11
TEST_DIR=./test
TEST_BUILD_DIR=./build/test
TEST_OBJ=test/*.cc
TEST_IDIR=-I./
SOURCE_FILES=*.c

unit_test: $(TEST_OBJ)
	mkdir -p $(TEST_BUILD_DIR)
	$(CC) $(CCFLAGS) $(SOURCE_FILES) -o $(TEST_BUILD_DIR)/$@ $^ $(TEST_IDIR)
	$(TEST_BUILD_DIR)/$@ -r console -a -s
