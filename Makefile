CXX = g++
CXXFLAGS += -std=c++17 -Wall -Wextra -g -I/usr/local/include/gtest
LDFLAGS += -L/usr/local/lib -lgtest -lgtest_main -pthread

sym_table: main.o symtable.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

symtable.o: src/SymTable.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

symtest.o: test/SymTest.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

sym_test: symtest.o symtable.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
	./sym_test

clean:
	rm -f *.o main sym_test
