//
// Created by msi on 10/28/2019.
//

#include "dictionary.hpp"
// read the file then store word and definition into map mp
void dictionary::readFile() {
    f.open("../dictionary.txt");
    if (!f.is_open()) {
        cerr << "Unable to open file" << endl;
        exit(1);
    } else {
        while(getline(f, s)) {
            stringstream ss(s);
            string word, def;
            getline(ss, word, '-');
            getline(ss, def, '-');
            mp.insert(pair<string, string>(word, def));
        }
    }
}
// print the word and definition stored in map mp
void dictionary::printDic() {
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << "-" << it->second << endl;
    }
}
// show menu and pick choice
void dictionary::choice() {
    int choice;
    while(choice != 4) {
        // print menu
        cout << "1 - Print dictionary.txt\n"
             << "2 - Find word definition\n"
             << "3 - Enter new word and definition\n"
             << "4 - Exit\n";
        cout << "Enter a choice: ";
        // promote entry
        cin >> choice;
        while(choice <= 0 || choice > 4) {
            cout << "Not an option, enter a choice between 1 and 4!  Enter a choice: ";
            cin >> choice;
        }
        // choose to print the dictionary.txt
        if(choice==1) {
            cout << "\nHere's the full version of dictionary.txt: \n";
            printDic();
            cout <<"\n";
        } else if(choice==2) {  // choice to find a certain word in the dictionary.txt
            findWord();
        } else if(choice==3){ // choice to add a word into dictionary.txt if it doesnt exist
            addWord();
        }
        cin.clear();
    }
    cout << "Bye, BB" << endl;
}
// find word in dictionary.txt
void dictionary::findWord() {
    string word;
    cout << "Enter the word: ";
    cin >> word;
    cout << "\n";
    if(isExist(word)) { // checking if the word exists
        auto itr = mp.find(word);
        cout << "The definition for \"" << word << "\"" <<" - " << itr->second << endl;
        cout << "\n";
        cin.clear();
    }
    else
        cout << "There's no \"" << word << "\" in dictionary.txt\n\n";

}
// if the word exist
bool dictionary::isExist(string &s) {
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if(it->first == s)
            return true;
    }
    return false;
}
// add word and definition if it doesnt exist in the dictionary.txt
void dictionary::addWord() {
    string word, def;
    cout << "Enter the word: ";
    cin >> word;
    cout << "\n";
    if(isExist(word)) // checking if the word exists
        cout << "\"" << word << "\"" << " already exist\n\n";
    else {
        cout << "Enter the definition for \"" << word << "\" ";
        cin >> def;
        mp.insert(pair<string, string>(word, def));
        string newWord = word + "-" + def;
        cout << newWord<<"\n\n";
        cin.clear();
    }
}