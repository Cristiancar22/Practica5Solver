#include "dictionary.h"


int Dictionary::getOcurrences(const char c) {
    iterator iter = begin();
    iterator fin = end();
    int ocurrencias = 0;

    while (iter != fin){
        for(int i = 0; i < (*iter).size(); i++){
            if((*iter)[i] == c)
                ocurrencias++;
        }

        ++iter;
    }

    return ocurrencias;
}

int Dictionary::getTotalLetters() {
    int total = 0;
    iterator iter = begin();
    iterator fin = end();

    while(iter != fin){
        total+= (*iter).size();

        ++iter;
    }
    return total;
}

vector<string>Dictionary::wordsOfLength(int length) {
    vector<string>v;

    iterator iter = begin();
    iterator fin = end();

    while(iter != fin){
        if ((*iter).size() == length)
            v.push_back(*iter);
        ++iter;
    }

    return v;
}

ostream & operator << (ostream & os, const Dictionary & d)
{
    Dictionary::iterator iter = d.begin();
    Dictionary::iterator fin = d.end();

    while (iter != fin){
        os << *iter << endl;

        ++iter;
    }

    return os;
}

istream & operator >> (istream & is, Dictionary & d)
{
    string word;

    set<string>::iterator iter = d.words.end();

    while(is >> word)
        iter = d.words.insert(iter,word);

    is.ignore();

    return is;
}