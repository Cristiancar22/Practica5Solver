#include <map>
#include <iostream>

using namespace std;

#ifndef __LETTER_SET_H__
#define __LETTER_SET_H__

/**
 * @brief TDA LetterInfo
 *
 * Contiene información sobre un determinado carácter del juego de las
 * letras. En concreto, almacena información sobre el número de repeticiones de
 * la letra en la partida y de la puntuación que otorga al utilizarse en una
 * palabra
 */

struct LetterInfo {
    int repetitions;
    int score;
};

/**
 * @brief TDA LettersSet
 *
 * Este TDA representa un conjunto de letras, con la información necesaria para
 * jugar una partida al juego de las letras, es decir, el número de repeticiones
 * que tenemos de la letra y la puntuación que dicha letra otorga cuando se
 * utiliza en una palabra
 */


class LettersSet{
/**
 *       @page repLettersSet Representación del TDA LettersSet .
 *
 *       @section invLettersSet Invariante de la representación.
 *
 *       LettersSet permite como valores de entrada del tipo pair<char, LetterInfo>, o otro LettersSet
 *
 *       @section faLettersSet Función de abstracción
 *
 *       {A,1,7,B,5,6} ->
 *          KEY: A   Score:1     Repetitions:7
 *          KEY: B   Score:5     Repetitions:6
 */
private:
    /**
     *  @brief Mapa cuya key es un char y contiene valores LetterInfo
     */
    map <char, LetterInfo> letters;

public:
    /**
     * @brief Constructor por defecto
     * Crea un LettersSet vacío
     */
    inline LettersSet(){}

    /**
     * @brief Constructor de copia
     * @param other LettersSet a copiar
     */
    inline LettersSet(const LettersSet & other):letters(other.letters){}

    /**
     * @brief Inserta un elemento en el LetterSet
     * @param val Pareja de letra y LetterInfo asociada a insertar
     * @return booleano que marca si se ha podido insertar la letra en el LettersSet. La letra sólo se inserta correctamente
     * si no estaba aún incluida en la colección
     */
    inline bool insert(const pair<char, LetterInfo> & val){return letters.insert(val).second;};

    /**
     * @brief Elimina un carácter del LetterSet
     * @param key Carácter a eliminar
     * @return Booleano que indica si se ha podido eliminar correctamente la letra del LettersSet
     */
    inline bool erase(const char & key){return letters.erase(key);};

    /**
     * @brief Limpia el contenido de LettersSet
     * Elimina el contenido del LettersSet
     */
    inline void clear(){letters.clear();};

    /**
     * @brief Consulta si el LettersSet es vacío
     * @return true si el LettersSet está vacío, falso en caso contrario
     */
    inline bool empty(){return letters.empty();};

    /**
     * @brief Tamaño del LetterSet
     * @return número de elementos en el letterSet
     */
    inline unsigned int size() const{return letters.size();};

    /**
     * @brief Iterador al comienzo del letterSet
     * @return un iterator a un LetterSet
     */
    inline map<char,LetterInfo>::const_iterator begin() const{return letters.cbegin();}

    /**
     * @brief Iterador al comienzo del letterSet
     * @return un iterador a un LetterSet
     */
    inline map<char,LetterInfo>::const_iterator end() const {return letters.cend();}

    /**
     * @brief Calcula la puntución dada de una palabra
     * @param word String con la palabra cuya puntuación queremos calcular
     * @return Puntación de la palabra, calculada como la suma de las puntuaciones de cada una de sus letras
     */
    int getScore (string word);

    /**
     * @brief Sobrecarga del operador de asignación
     * @param cl LetterSet a copiar
     * @return Referencia al objeto this para poder encadenar el operador
     */
    LettersSet & operator= (const LettersSet & cl);

    /**
     * @brief Sobrecarga del operador de consulta
     * @param val Carácter a consultar
     * @return Estructura de tipo LetterInfo con la información del carácter consultado: Número de repetición y puntuación
     */
    LetterInfo & operator[] (const char & val);

    /**
     * @brief Sobrecarga del operador de salida
     * @param os Flujo de salida, donde escribir el LettersSet
     * @param cl LettersSet que se escribe
     * @return Una referencia a un objeto ostream
     */
    friend ostream & operator<< (ostream & os, const LettersSet & cl);

    /**
     * @brief Sobrecarga del operador de entrada
     * @param is Flujo de entrada del que leer el LettersSet
     * @param cl LettersSet en el que almacenar la información leída
     * @return una referencia a un objeto istream
     */
    friend istream & operator>> (istream & is, LettersSet & cl );

};


#endif
