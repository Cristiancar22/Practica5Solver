//
// Created by Morad on 25/11/2021.
//

#include <iostream>
#include <vector>
#include <fstream>
#include "dictionary.h"
#include "letters_set.h"
#include "letters_bag.h"
#include "solver.h"

using namespace std;

int main(int argc, char * argv[])
{
    char *let;
    char *dic;
    char *modo;
    bool scoreGame = false;
    int numLetras;

    vector<char> av;

    Dictionary diccionario;
    LettersSet letras;



    if (argc != 5){
        cerr << "ERROR. Número incorrecto de argumentos" << endl;
        exit(-1);
    }

    if(*argv[3] != 'P' && *argv[3] != 'L' ){
        cerr <<"ERROR. Introduzca un Modo de Juego válido:\n"
             <<"L - > Longitud      P - > Puntuación \n";
        exit(-1);
    }

    let = argv[1];
    dic = argv[2];
    modo = argv[3];
    numLetras = atoi(argv[4]);

    if (*modo == 'P')
        scoreGame = true;



    ifstream f1(let);

    f1>>letras;

    f1.close();

    LettersBag bag(letras);

    ifstream f2(dic);

    f2>>diccionario;

    f2.close();


    av = bag.extractLetters(numLetras);

    Solver solver(diccionario, letras);

    pair<vector<string>, int> sol;


    sol = solver.getSolutions(av,scoreGame);

    cout << "LETRAS DISPONIBLES:" << endl;

    for (int  i = 0; i < av.size(); i++)
        cout << av[i] << " " ;

    cout << "\nSOLUCIONES:" << endl;

    auto iter = sol.first.begin();
    auto fin = sol.first.end();

    while(iter != fin)
    {
        cout << *iter << endl;

        ++iter;
    }

    cout << "PUNTUACION:" << endl
        << sol.second;

}


