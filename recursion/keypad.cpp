// WAP to generate all possible words from a given keypad number list.
//  2 -> abc 3-> def 4-> ghi 5-> jkl 6-> mno 7-> pqrs 8-> tuv 9-> wxyz
// example: 235 -> { adj aej afj bdj bej bfj cdj cej cfj adk aek afk bdk bek bfk cdk cek cfk adl ael afl bdl bel bfl cdl cel cfl }

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <list>
using namespace std;

unordered_map<char, list<char>> map = {
    {'2', {'a', 'b', 'c'}},
    {'3', {'d', 'e', 'f'}},
    {'4', {'g', 'h', 'i'}},
    {'5', {'j', 'k', 'l'}},
    {'6', {'m', 'n', 'o'}},
    {'7', {'p', 'q', 'r', 's'}},
    {'8', {'t', 'u', 'v'}},
    {'9', {'w', 'x', 'y', 'z'}}
};

vector<string> result = {};

string str = "23";

void generate(string x, int index){
    if(x.length() == str.length()){
        result.push_back(x);
    }
    else{
        list<char> l = map[str[index]];
        for(auto i = l.begin(); i != l.end(); i++){
            generate(x + *i, index+1);
        }
    }
}

vector<string> generate(){
    if(str.length() == 0){
        return result;
    }
    else{
        generate("", 0);
        return result;
    }
}

int main(){
    vector<string> res = generate();
    for(auto i = res.begin(); i != res.end(); i++){
        cout << *i << " ";
    }
    return 0;
}