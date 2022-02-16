#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

/**
 * @brief TDA Dictionary
 * @details Almacena las palabras de un fichero de texto y permite iterar sobre ellas
 *
 */

class Dictionary{
/**
        @page repDictionary Representación del TDA Dictionary .

        @section invDictionary Invariante de la representación.

        Los valores permitidos en una estructura Dictionary se limita a cadenas de chars

        @section faDictionary Función de abstracción

        {a, avalancha, alga, esquimal, cacahuete, atroz,...} -->

        a
        alga
        atroz
        cacahuete
        esquimal
        ...

    **/

private:

    /**
     *  @brief Set de strings
     *
     *  words utiliza el tipo set, donde se almacenan de manera ordenada los strings que almacenamos en este
     */

    set <string> words;
public:

    /**
     * @brief Constructor por defecto
     * Crea un Dictionary vacío
     */
    inline Dictionary(){};

    /**
     * @brief Constructor de copia
     * Crea un Dictionary con el mismo contenido que el que se pasa como argumento
     * @param other Dictionary que se quiere copiar
     */
    inline Dictionary(const Dictionary & other):words(other.words){};

    /**
     * @brief Indica si una palabra esta en el diccionario o no
     * Este método comprueba si una determinada palabra se encuentra o no en el diccionario
     * @param val la palabra que se quiere buscar
     * @return Booleano indicando si la palabra existe o no en el diccionario
     */
    inline bool exists(const string & val) const{return (words.find(val) != words.end());};

    /**
     * @brief Inserta una palabra en el diccionario
     * @param val palabra a insertar en el diccionario
     * @return booleano que indica si la inserción ha tenido éxito. Una palabra se inserta con éxito si no existía previamente en el diccionario
     */
    inline bool insert(const string & val){return words.insert(val).second;};

    /**
     * @brief Elimina una palabra del diccionario
     * @param val Palabra a borrar del diccionario
     * @return Booleano que indica si la palabra se ha borrado del diccionario
     */
    inline bool erase(const string & val){return words.erase(val);};

    /**
     * @brief Limpia el Dictionary
     * Elimina todas las palabras contenidas en el conjunto
     */
    inline void clear(){words.clear();};

    /**
     * @brief Comprueba si el diccionario está vacío
     * @return true si el diccionario está vacío, false en caso contrario
     */
    inline bool empty()const {return words.empty();};

    /**
     * @brief Tamaño del diccionario
     * @return Número de palabras guardadas en el diccionario
     */
    inline int size() const {return words.size();};

    /**
     * @brief Iterador al comienzo del diccionario
     * @return Un iterador al diccionario
     */
    inline set<string>::const_iterator begin() const {return words.cbegin();};

    /**
     * @brief Iterador al final del diccionario
     * @return Un iterador al diccionario
     */
    inline set<string>::const_iterator end() const {return words.cend();};

    /**
     * @brief Indica el número de apariciones de una letra
     * @param c letra a buscar
     * @return Un entero indicando el número de apariciones
     */
    int getOcurrences(const char c);

    /**
     * @brief Cuenta el total de letras de un diccionario
     * @return Entero con el total de letras
     */
    int getTotalLetters();

    /**
     * @brief Devuelve las palabras en el diccionario con una longitud dada
     * @param length Longitud de las palabras buscadas
     * @return Vector de palabras con la longitud deseada
     */
    vector<string> wordsOfLength(int length);

    /**
     * @brief Sobrecarga del operador de salida
     * @param os Flujo de salida donde escribe el Dictionary
     * @param d Dictionary que se escribe
     * @return una referencia a un objeto ostream
     */
    friend  ostream & operator<< (ostream & os, const Dictionary & d);

    /**
     * @brief Sobrecarga del operador de entrada
     * @param is Flujo de entrada del que leer el Dictionary
     * @param d Dictionary en el que almacenar la información leída
     * @return Una referencia a un objeto istream
     */
    friend istream & operator>> (istream & is, Dictionary & d);


    class iterator{
    private:
        set<string>::iterator it;
    public:
        /**
         * @brief Constructor por defecto
         * Crea un iterator vacío
         */
        iterator(){}

        /**
         * Constructor de copia
         * @param otro un iterador de set<string> a copiar
         */
        iterator(const set<string>::iterator& otro):it(otro){}

        /**
         * Constructor de copia
         * @param otro iterator a copia
         */
        iterator(const iterator& otro):it(otro.it){}

        /**
         * @bri
         */
        ~iterator(){}

        /**
         * @brief Sobrecarga del operador de asignación
         * @param otro iterador de set<string> a copiar
         * @return Referencia al objeto this para poder encadenar el operador
         */
        iterator& operator=(const set<string>::iterator& otro){it=otro;return *this;}

        /**
         * @brief Sobrecarga del operador de asignación
         * @param otro iterator a copiar
         * @return Referencia al objeto this para poder encadenar el operador
         */
        iterator& operator=(const iterator& otro){it=otro.it;return *this;}

        /**
         * @brief Sobrecarga del operador *
         * @return Referncia al contenido apuntado por el iterador, es decir, un string
         */
        string operator*()const{return *it;}

        /**
         * @brief Sobrecarga del operador ++
         * @return Referencia al objeto this para poder encadenar el operador
         */
        iterator& operator++(){++it;return *this;}

        /**
         * @brief Sobrecarga del operador --
         * @return Referencia al objeto this para poder encadenar el operador
         */
        iterator& operator--(){--it;return *this;}

        /**
         * @brief Sobrecarga del operador ++
         * @return Referencia al objeto this para poder encadenar el operador
         */
        iterator& operator++(int){it++;return *this;}

        /**
         * @brief Sobrecarga del operador --
         * @return Referencia al objeto this para poder encadenar el operador
         */
        iterator& operator--(int){it--;return *this;}

        /**
         * @brief Sobrecarga del operador !=
         * @param otro iterator a comparar
         * @return true si se cumple la comparación, false en caso contrario
         */
        bool operator!=(const iterator& otro){return it != otro.it;}

        /**
         * @brief Sobrecarga del operador ==
         * @param otro iterator a comparar
         * @return true si se cumple la comparación, false en caso contrario
         */
        bool operator==(const iterator& otro){return it == otro.it;}
    };

    class const_iterator{
    private:
        set<string>::const_iterator const_it;
    public:
        /**
         * @brief Constructor por defecto
         * Crea un const_iterator vacío
         */
        const_iterator(){}

        /**
         * Constructor de copia
         * @param otro un iterador constante de set<string> a copiar
         */
        const_iterator(const set<string>::const_iterator& otro):const_it(otro){}

        /**
         * Constructor de copia
         * @param otro const_iterator a copia
         */
        const_iterator(const const_iterator& otro):const_it(otro.const_it){}

        ~const_iterator(){}

        /**
         * @brief Sobrecarga del operador de asignación
         * @param otro iterador constante de set<string> a copiar
         * @return Referencia al objeto this para poder encadenar el operador
         */
        const_iterator& operator=(const set<string>::iterator& otro){const_it=otro;return *this;}

        /**
         * @brief Sobrecarga del operador de asignación
         * @param otro const_iterator a copiar
         * @return Referencia al objeto this para poder encadenar el operador
         */
        const_iterator& operator=(const const_iterator& otro){const_it=otro.const_it;return *this;}

        /**
         * @brief Sobrecarga del operador *
         * @return Referncia al contenido apuntado por el iterador, es decir, un string
         */
        const string operator*()const{return *const_it;}

        /**
         * @brief Sobrecarga del operador ++
         * @return Referencia al objeto this para poder encadenar el operador
         */
        const_iterator& operator++(){++const_it;return *this;}

        /**
         * @brief Sobrecarga del operador --
         * @return Referencia al objeto this para poder encadenar el operador
         */
        const_iterator& operator--(){--const_it;return *this;}

        /**
         * @brief Sobrecarga del operador ++
         * @return Referencia al objeto this para poder encadenar el operador
         */
        const_iterator& operator++(int){const_it++;return *this;}

        /**
         * @brief Sobrecarga del operador --
         * @return Referencia al objeto this para poder encadenar el operador
         */
        const_iterator& operator--(int){const_it--;return *this;}

        /**
         * @brief Sobrecarga del operador !=
         * @param otro iterator a comparar
         * @return true si se cumple la comparación, false en caso contrario
         */
        bool operator!=(const const_iterator& otro){return const_it != otro.const_it;}

        /**
         * @brief Sobrecarga del operador ==
         * @param otro iterator a comparar
         * @return true si se cumple la comparación, false en caso contrario
         */
        bool operator==(const const_iterator& otro){return const_it == otro.const_it;}
    };

    /**
     * @brief Devuelve un iterador que hace referencia al primer elemento del contenedor
     * @return Un iterador del primer elemento del contenedor
     */
    iterator begin(){iterator i = words.begin();return i;}


    /**
     * @brief Devuelve un interador que hace referencia al ultimo elemento del contenedor
     * @return Un iterador del ultimo elemento del contenedor
     */
    iterator end(){iterator i = words.end();return i;}

    /**
     * @brief Devuelve un iterador que hace referencia al primer elemento del contenedor
     * @return Un iterador del primer elemento del contenedor
     */
    const_iterator const_begin() const{const_iterator i = words.cbegin();return i;}

    /**
     * @brief Devuelve un interador constante que hace referencia al ultimo elemento del contenedor
     * @return Un iterador constante del ultimo elemento del contenedor
     */
    const_iterator const_end() const{const_iterator i = words.cend();return i;}
};





#endif
