#include <gtest/gtest.h>
#include "SymTable.hpp"

// Test for inserting and retrieving values
TEST(SymbolTableTest, InsertRetrieve) {
    Symbol symbol;
    int val1 = 10;
    float val2 = 20.5;
    
    symbol.SymTable_put("intKey", &val1);
    symbol.SymTable_put("floatKey", &val2);

     EXPECT_EQ(*static_cast<int*>(symbol. SymTable_get("intKey")), 10);
    EXPECT_FLOAT_EQ(*static_cast<float*>(symbol. SymTable_get("floatKey")), 20.5);
}
// Test for checking key existence(contains)
TEST(SymbolTableTest, Contains) {
    Symbol symbol;
    int val = 30;
    
    symbol. SymTable_put("key1", &val);
    EXPECT_TRUE(symbol. SymTable_contains("key1"));
    EXPECT_FALSE(symbol. SymTable_contains("nonexistent"));
}

// Test for removing values
TEST(SymbolTableTest, Remove) {
    Symbol table;
    int val = 50;
    
    table.SymTable_put("removeKey", &val);
    EXPECT_TRUE(table. SymTable_contains("removeKey"));

    table.SymTable_remove("removeKey");
    EXPECT_FALSE(table. SymTable_contains("removeKey"));
}

// Test for empty table
TEST(SymbolTableTest, EmptyTable) {
    Symbol table;
    EXPECT_FALSE(table. SymTable_contains("key_avail"));
    EXPECT_EQ(table. SymTable_get("key_avail"), nullptr);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}