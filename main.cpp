#include<iostream>
#include<string>
#include "sym.hpp"


int main(){
    Symbol symbol;
    symbol.put("1",const_cast<char*>("int"));
    symbol.put("2",const_cast<char*>("double"));

    symbol.printbinding();

    symbol.free();
    symbol.printbinding();
}