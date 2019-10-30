#include "dictionary.hpp"
using namespace std;

int main() {
    // defaulting constructing a dictionary
    dictionary dc{};
    // read file from txt
    dc.readFile();
    // display menu and let user choose
    dc.choice();
    return 0;
}