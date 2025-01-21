#include<iostream>
#include <string>


class sym{
    private:
    std::string key;
    void* value;
    sym* next;

    public:
    sym(const std::string& k, void* v, sym* n)
    : key(k), value(v), next(n) {}
    friend class Symbol;

};

class Symbol{

    private:
    sym* head;
    int size;
    public:
    Symbol();
    void free();
    int len() ;
    bool put( const std::string& key, void* value);
    void* replace( std::string& key, void* value);
    bool contains( const std::string& key);
    void* remove( std::string& key);
    void* get(std:: string &key);
    void printbinding();

};
