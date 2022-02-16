#include <iostream>
#include "bag.h"
#include "letters_set.h"

using namespace std;

#ifndef __LETTERS_BAG_H__
#define __LETTERS_BAG_H__

/**
 * @brief TDA LettersBag
 *
 * Este TDA almacena un conjunto de chars utilizado en el juego de letras.
 * La estructura de datos subyacente es una lista de chars.
 */

class LettersBag{
/**
 *       @page repLettersBag Representación del TDA LettersBag .
 *
 *       @section invLettersBag Invariante de la representación.
 *
 *       LettersBag permite como valores de entrada chars, o se puede utilizar un TDA LettersSet en el constructor
 *
 *       @section faLettersBag Función de abstracción
 *
 *       {LettersSet ls} -> [a, a, a, b, b, c, c, e, e, e, ...]
 *
 */
private:
    /*
     * @brief Estructura de tipo bag<char> (vector dinámico)
     * */
    Bag<char> letters;
public:

    /**
     * @brief Constructor por defecto
     * Crea un LettersBag vacío
     */
    inline LettersBag(){}

    /**
     * @brief Constructor dado un LettersSet
     * Dado un LettersSet como argumento, este constructor debe rellenar la LettersBag con las letras que contiene el
     * LettersSet, introduciendo cada letra el número de veces indicado por el campo LetterInfo::repetitions.
     * @param letterSet TDA LettersSet a parsear
     */
    inline LettersBag(const LettersSet & letterSet){
        auto fin = letterSet.end();

        for (auto iter = letterSet.begin(); iter != fin; ++iter){
            for (int i = 0; i < iter->second.repetitions; i++)
                letters.add(iter->first);
        }

    }

    /**
     * @brief Introduce una letra en la bolsa
     * @param l letra a añadir a la LettersBag
     */
    inline void insertLetter(const char & l){letters.add(l);}

    /**
     * @brief Extrae una letra aleatoria de la bolsa, eliminándola del conjunto
     * @return char, representa la letra extraída
     */
    char extractLetter();

    /**
     * @brief Extrae un conjunto de letras de la LettersBag, eliminándolas del conjunto
     * @param num Número de letras a extraer
     * @return Lista con las letras extraídas aleatoriamente
     */
    vector<char> extractLetters(int num);

    /**
     * @brief Vacía la LettersBag
     * Elimina todo el contenido de la LettersBag
     */
    inline void clear(){letters.clear();}

    /**
     * @brief Tamaño de la bolsa
     * @return int con el tamaño de la bolsa
     */
    inline unsigned int size() const {return letters.size();}

    /**
     * @brief Sobrecarga del operador de asignación
     * @param other LettersBag a copiar
     * @return Referencia a this para poder encadenar el operador
     */
    inline LettersBag operator=(const LettersBag & other){
        if(this != &other)
            this->letters = other.letters;

        return *this;
    }

};

#endif
