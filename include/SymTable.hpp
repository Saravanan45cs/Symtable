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
    ~Symbol();
    void SymTable_free();
    int SymTable_len() ;
    bool SymTable_put( const std::string& key, void* value);
    void* SymTable_replace( const std::string& key, void* value);
    bool SymTable_contains( const std::string& key);
    void* SymTable_remove( const std::string& key);
    void* SymTable_get(const std:: string &key);
    void SymTable_printbinding();

};
