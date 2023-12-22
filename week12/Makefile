#TODO: Set your googletest directory path
GTEST_DIR = ../googletest/googletest

CC=clang++
CPPFLAGS += -isystem $(GTEST_DIR)/include

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
				$(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

#TODO: Set your executable target
all : hw12

hw12: hw12.cc vector.o list.o stack.o queue.o divide_by_zero_exception.o empty_container_exception.o safe_math.o
	$(CC) --std=c++17 $^ -o $@

#TODO: Change 'util.h' and 'util.cc' to your source files
vector.o : vector.cc
	$(CC) --std=c++17 -c $^ -o $@

list.o : list.cc
	$(CC) --std=c++17 -c $^ -o $@

stack.o : stack.cc
	$(CC) --std=c++17 -c $^ -o $@

queue.o : queue.cc
	$(CC) --std=c++17 -c $^ -o $@

divide_by_zero_exception.o : divide_by_zero_exception.cc
	$(CC) --std=c++17 -c $^ -o $@

empty_container_exception.o : empty_container_exception.cc
	$(CC) --std=c++17 -c $^ -o $@

safe_math.o : safe_math.cc
	$(CC) --std=c++17 -c $^ -o $@

#TODO: Change 'util_test.cc' to your test file
test.o : test.cc $(GTEST_HEADERS)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) --std=c++17 -c $< -o $@

#TODO: Change 'util_test.o'and 'util.o' to your object targets
test: test.o vector.o list.o stack.o queue.o divide_by_zero_exception.o empty_container_exception.o safe_math.o gtest_main.a
	$(CC) $(CPPFLAGS) $(CXXFLAGS) --std=c++17 $^ -o $@

#TODO: Change 'main' and 'main_test' to your executable and test respectively
clean:
	 rm -f gtest.a gtest_main.a *.o hw12 vector list stack queue divide_by_zero_exception empty_container_exception safe_math test

gtest-all.o: $(GTEST_SRCS_) 
	$(CC) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) --std=c++17 -c\
		$(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CC) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) --std=c++17 -c\
		$(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

.PHONY: all clean


