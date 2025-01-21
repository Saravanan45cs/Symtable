#include<iostream>
#include<string>
#include<cassert>
#include "sym.hpp"

Symbol::Symbol()
{
    head=nullptr;
    size=0;
}

int Symbol::len(){
    return size;
}

bool Symbol::contains(const std::string &key){
    sym* current=head;
    while(current){
        if(current->key==key){
            return 1;
        }
        current=current->next;
    }
    return 0;
}

void Symbol::free(){
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

bool Symbol::put(const std::string& key, void* value) {
    assert(!key.empty());
    if(contains(key)) return false;

    head=new sym(key,value,head);
    size++;
    return true;
}

void* Symbol::get(std::string &key){
    sym* current=head;
    while(current){
        if(current->key==key){
            return current->value;
        }
    }
    return nullptr;
}

void* Symbol::remove(std:: string &key){
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

void* Symbol::replace(std::string& key, void* value){
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

void Symbol::printbinding(){

    if(!head){
        std::cout<<"No data"<<std::endl;
        return;
    }
    sym* current=head;
    
    while(current){
        std::cout<<"Key: "<<current->key<<"Value: "<<static_cast<const char*>(current->value)<<std::endl;
        
        current=current->next;
    }
}