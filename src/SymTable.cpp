#include<iostream>
#include<string>
#include<cassert>
#include "SymTable.hpp"

Symbol::Symbol()
{
    head=nullptr;
    size=0;
}
Symbol::~Symbol() {
    sym* current = head;
    while (current != nullptr) {
        sym* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    size = 0;
}

int Symbol::SymTable_len(){
    return size;
}

bool Symbol::SymTable_contains(const std::string &key){
    sym* current=head;
    while(current){
        if(current->key==key){
            return 1;
        }
        current=current->next;
    }
    return 0;
}

void Symbol::SymTable_free(){
    sym* current =head;
    while(current){
        sym* remove=current;
        current=current->next;
        delete remove;
        --size;
    }
    head=nullptr;
    size=0;

}

bool Symbol::SymTable_put(const std::string& key, void* value) {
    assert(!key.empty());
    if( SymTable_contains(key)) return false;

    head=new sym(key,value,head);
    size++;
    return true;
}

void* Symbol::SymTable_get(const std::string &key){
    sym* current=head;
    while(current){
        if(current->key==key){
            return current->value;
        }
        current=current->next;
    }
    return nullptr;
}

void* Symbol::SymTable_remove(const std:: string &key){
    sym* current=head;
    sym* prev=nullptr;
    while(current){
        void * val=current->value;
        if(current->key==key){
            if(prev==nullptr){
                head=current->next;
            }
            else{
                prev->next=current->next;
            }
            return val;
        }
        prev=current;
        current=current->next;
    }
    return nullptr;
}

void* Symbol::SymTable_replace(const std::string& key, void* value){
    sym* current =head;
    while(current){
        if(current->key==key){
            void* old=current->value;
            current->value=value;
            return old;
        }
    }
    return nullptr;

}

void Symbol::SymTable_printbinding(){

    if(!head){
        std::cout<<"No data"<<std::endl;
        return;
    }
    sym* current=head;
    
    while(current){
        std::cout<<"Key: "<<current->key<<" Value: "<<static_cast<const char*>(current->value)<<std::endl;
        current=current->next;
    }
}