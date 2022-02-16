#include "solver.h"

Solver::Solver(const Dictionary &dict, const LettersSet &letters_set){

    this->dictionary = dict;
    this->lettersSet = letters_set;
}

bool Solver::esLegal(vector<char> al, string word) {
    bool encontrado = true;             //Utilizamos un booleano para comprobar que la palabra contiene las letras en cuestion
    int i;

    for (i = 0; i < word.size() && encontrado; i++)
    {                                   //Para que el bucle itere aparte de recorrer la palabra se debe "encontrar" almenos
                                        //una de las letras por iteracion, sino no es valida la palabra
        auto iter = al.begin();
        auto fin = al.end();

        encontrado = false;             //En cada iteracion se declara false

        while (iter != fin && !encontrado)
        {

            if(tolower(*iter) == word[i])
            {
                al.erase(iter);
                encontrado = true;      //Una vez una letra coincide se borra del vector y se marca como true
            }

            ++iter;
        }
    }

    return encontrado;
}

pair<vector<string>,int> Solver ::getSolutions(const vector<char> &available_letters, bool score_game) {
    pair<vector<string>,int>solutions;
    auto iter = dictionary.begin();
    auto fin = dictionary.end();
    int best = 0;
    int score = 0;

    for(auto iter=dictionary.begin(); iter != dictionary.end(); iter++)
    {
        if(score_game)
            score = lettersSet.getScore(*iter);
        else
            score = (*iter).size();

        if( score >= best)
        {
            if(esLegal(available_letters,*iter))
            {
                if(score == best)
                    solutions.first.push_back(*iter);
                else
                {
                    if (!(solutions.first.empty()))
                        solutions.first.clear();

                        solutions.first.push_back(*iter);
                        best = score;
                }
            }
        }
    }

    solutions.second = best;

    return solutions;
}

