//
// Created by msi on 10/28/2019.
//
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
using namespace std;
#ifndef LAB06_DICTIONARY_HPP
#define LAB06_DICTIONARY_HPP


class dictionary {
private:
    // private map<string, string> to match word and definition
    map<string, string> mp;
    string s;
public:

    fstream f;
    // default constructor
    dictionary() = default;
    // read the file then store word and definition into map mp
    void readFile();
    // print the word and definition stored in map mp
    void printDic();
    // show menu and pick choice
    void choice();
    // find word in dic.txt
    void findWord();
    // if the word exist
    bool isExist(string&);
    // add word and definition if it doesnt exist in the dic.txt
    void addWord();
};


#endif //LAB06_DICTIONARY_HPP
