#include "letters_set.h"

int LettersSet::getScore(string word) {
    int score = 0;

    for (int i = 0; i < word.size(); i++)
            score += letters[toupper(word[i])].score;

    return score;
}

LettersSet & LettersSet::operator=(const LettersSet &cl) {
    if(this != &cl)
        letters = cl.letters;
    return *this;
}

LetterInfo & LettersSet::operator[](const char &val) {
     return letters[val];
}

ostream & operator<<(ostream & os, const LettersSet & cl){

    for (auto iter = cl.begin(); iter != cl.end(); ++iter){
        os << "[ letra: " << iter->first << ", "
           << "repeticiones: " << iter->second.repetitions << ", "
           << "puntuación: " << iter->second.score << " ]" << endl;
    }

    return os;
}

istream & operator>>(istream & is, LettersSet & cl){
    string x;
    pair<char,LetterInfo> val;

    getline(is, x);

    while(is>>val.first>>val.second.repetitions>>val.second.score)
        cl.insert(val);

    is.ignore();

    return is;

}





