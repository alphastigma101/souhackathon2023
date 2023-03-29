#ifndef PEOTRY_ON_CRACK_H
#define PEOTRY_ON_CRACK_H
#include <string.h> // std::tuple
#include <tuple> // std::tuple
#include <fstream> // std::ifstream
#include <list> // std::list
#include <iostream> // std::cout
#include <vector> // std::vector
#include <cctype> // std::isupper

struct Bag {
    int key;
    int index;
    std::ifstream Contents;
    std::string words;
    std::vector<std::string> temp_vec;
    std::string temp;
    std::list<std::string> *hash_table_temp;
    int counter = 0;
};
class Open_Hashing {
    public:
        Open_Hashing(std::vector<std::string> &vec);
        Open_Hashing();
        void Print();
        void Print_HashTable(std::list<std::string> *hash_table);  
        Bag Goodies;
        std::list<std::string>* Get_Hash(std::list<std::string> *hash_table);

    private:
        std::list<std::string> *hash_table;
        int table_size;
        int Hash_Function(std::vector<std::string> &vec);
        //int Insert_Key(int key); 
        
    
};

class Encryption {
    public:
        std::string PlainText;
    private:
        std::string CipherText;
        //auto Encryption(); 


};

class Decryption {
    public:
        //
    private:
        //  
};



#endif
