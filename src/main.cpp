#include<iostream>
#include<string>
#include "SymTable.hpp"


int main(){
    Symbol symbol;
    symbol.SymTable_put("1",const_cast<char*>("int"));
    symbol.SymTable_put("2",const_cast<char*>("double"));

    std::cout<<"Old value: "<<static_cast<const char*>(symbol.SymTable_replace("2",const_cast<char*>("float")))<<std::endl;

    symbol. SymTable_printbinding();

    symbol.SymTable_free();
    symbol.SymTable_printbinding();

    return 0;
}