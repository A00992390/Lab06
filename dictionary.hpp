//
// Created by Kang on 10/28/2019.
// A class that reads dictionary.txt then store the word and definition
// into a map.
// User can select option from the menu to print the whole dictionary, search for a word
// and add a new word and definition into the dictionary.
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
