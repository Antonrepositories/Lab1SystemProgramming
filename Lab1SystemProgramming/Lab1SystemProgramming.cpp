// 8 variant
//
#include <iostream>
#include<fstream>
#include<locale>
#include<vector>
#include<Windows.h>
#include <set>
using namespace std;


bool IsRight(string word) {
    int golosni = 0;
    for (int i = 0; i < word.length(); i++) {
        char letter = toupper(word[i]);
        if (letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U' || letter == 'Y') {
            golosni += 1;
        }
    }
    return word.length() - golosni < golosni;
}


int main()
{
    vector<string>words_result;
    set<string>set_result;
    locale loc("en_US.UTF8");
    ifstream file;
    string word = "";
    file.open("Text.txt");
    while (!file.eof()) {
        char x = file.get();
        if (isalpha(x, loc))
        {
            word += x;
        }
        else {
            if (word.length() > 0 && IsRight(word)) {
                //words_result.push_back(word);
                set_result.insert(word);
            }
            word = "";
        }
    }
    for (int i = 0; i < words_result.size(); i++) {
        cout << words_result[i] << endl;
    }
    cout << "RESULT: " << set_result.size() << " words found >>>>>>>>>>>>>>>>>" << endl;
    int i = 1;
    for (auto it = set_result.begin(); it !=
        set_result.end(); ++it) {
        cout << i << ". " << *it << endl;
        i++;
    }
}

