#include "Peotry_On_Crack.h"


// pre-condition: 
// post-condition: 
Open_Hashing::Open_Hashing() {}

// pre-condition: Create the hash table and start populating the hash_table
// post-condition: 
Open_Hashing::Open_Hashing(std::vector<std::string> &vec) {
    table_size = static_cast<int>(vec.size());
    hash_table = new std::list<std::string>[table_size];
    while ( Goodies.counter != table_size ) {
        int key = Open_Hashing::Hash_Function(vec);
        hash_table[key].push_back(vec[Goodies.counter]);
        Goodies.counter += 1;
    }
    Goodies.hash_table_temp = Open_Hashing::Get_Hash(hash_table);
}

std::list<std::string>* Open_Hashing::Get_Hash(std::list<std::string> *hash_table) {
    Goodies.counter = 0;
    Goodies.hash_table_temp = hash_table;
    return Goodies.hash_table_temp;
}   

// pre-condition: This function takes the values from the Drive Code and it creates new indexes for the table
// post-condition: Returns new index
int Open_Hashing::Hash_Function(std::vector<std::string> &vec) {
    int hash_output = 0;
    Goodies.temp = vec.at(Goodies.counter);
    for (unsigned int index = 0; index <= Goodies.temp.length(); index++) {
        hash_output += Goodies.temp[index];
    }
    return hash_output % table_size;
}


// pre-condition: This is the Driver Code. 
// post-condition: It returns 0
int main(int argc, char** argv) {
    //std::string File_Contents = argv[1]; // Will uncomment after some testing!
    Open_Hashing Temp_OP; 
    const char *File_Contents = "poems/A Fairy Song by William Shakespeare";
    Temp_OP.Goodies.Contents.open(File_Contents);
    if ( Temp_OP.Goodies.Contents.is_open() ) {
        while(std::getline(Temp_OP.Goodies.Contents, Temp_OP.Goodies.words)) { 
            for (unsigned int index = 0; index <= Temp_OP.Goodies.words.length(); index++) {
                switch (Temp_OP.Goodies.words[index]) {
                    case ' ':
                        Temp_OP.Goodies.temp_vec.push_back(Temp_OP.Goodies.temp);
                        Temp_OP.Goodies.temp.clear();
                        break;
                    case ',':
                        Temp_OP.Goodies.temp_vec.push_back(Temp_OP.Goodies.temp);
                        Temp_OP.Goodies.temp.clear();
                        break;
                    case '!':
                        Temp_OP.Goodies.temp_vec.push_back(Temp_OP.Goodies.temp);
                        Temp_OP.Goodies.temp.clear();
                        break;
                    case ';':
                        Temp_OP.Goodies.temp_vec.push_back(Temp_OP.Goodies.temp);
                        Temp_OP.Goodies.temp.clear();
                        break;
                    default:
                        Temp_OP.Goodies.temp += Temp_OP.Goodies.words[index];
                }
            }
        }
    }
    Temp_OP.Goodies.Contents.close();
    Open_Hashing OP(Temp_OP.Goodies.temp_vec);
    //OP.Goodies.hash_table_temp = OP.Get_Hash(OP.Goodies.hash_table_temp);
    OP.Print_HashTable(OP.Goodies.hash_table_temp);
    return 0;
}

// pre-condition: Values are obtain from Driver Code that are stored in the Bag struct
// post-condition: Print the contents that are going to be hashed into a table  
void Open_Hashing::Print() {
    for (auto &it : Goodies.temp_vec) {
        std::cout << it << std::endl;
    }
    return;
}

// pre-condition: Goodies.hash_table_temp is passed into this function. It should print the table without the user being able to modify the real hash_table
// post-condition: Print the contents that are stored in the hash_table 
void Open_Hashing::Print_HashTable(std::list<std::string> *hash_table) {
    for (int k = 0; k < table_size; k++) {
        for (auto i = hash_table[k].begin(); i != hash_table[k].end(); i++) { 
            std::cout << "Key:  " << k << "   Value: " << *i << std::endl;
        }
    }
    return;
}
