#include <iostream>
#include <set>
#include <vector>
#include "dictionary.h"
#include "letters_set.h"

using namespace std;


/**
 *   \file solver.h
 *   \brief Archivo de declaración de la clase Solver
 *
 *   La funcionalidad de este TDA sirve para la resolución "solver" del juego Scrabble,
 *   contiene como datos un diccionario, y un "lettersSet" con la información de cada letra.
 */



class Solver{
private:

    Dictionary dictionary;
    LettersSet lettersSet;

public:

    /**
     * @brief Constructor con parámetros.
     * Crea un Solver que tiene asociado un Dictionary y un LettersSet.
     * @param dict Objeto Dictionary a copiar.
     * @param letters_set Objeto LettersSet a copiar.
     */
    Solver(const Dictionary & dict, const LettersSet & letters_set);

    /**
     * @brief Construye el vector de soluciones a partir de las letras de una partida.
     * Dado un conjunto de letras posibles para crear una solución, y el modo de juego con el que se juega la partid,
     * se construye un vector con las mejores soluciones encontradas en función del tipo de juego planteado
     * @param available_letters Vector de letras disponibles para la partida
     * @param score_game Bool indicando el tipo de partida. True indica que la partida se juega a puntuación, false que se juega a longitud
     * @return Par <vector<string>, int>, con el vector de palabras que constituyen las mejores soluciones (puede haber empates) y la puntuación que obtienen
     */
    pair<vector<string>,int> getSolutions(const vector<char> & available_letters, bool score_game);

    /**
     * @brief Comprueba si la palabra está formada por algunas o todas las letras pasadas como argumento.
     * @param available_letters Vector de letras disponibles para la partida
     * @param word Palabra que se quiere comprobar
     * @return Booleano que contiene el resultado de la comprobación
     */
    bool esLegal(vector<char> available_letters, string word);
};