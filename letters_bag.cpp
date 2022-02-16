#include "letters_bag.h"
#include "vector"

char LettersBag::extractLetter() {
    return letters.get();
}

vector<char>LettersBag::extractLetters(int num) {
    char aux;
    vector<char> v;

    for (int i = 0; i < num; i++){
        aux = letters.get();
        v.push_back(aux);
    }

    return v;

}