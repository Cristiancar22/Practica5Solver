#include <vector>
#include <iostream>

using namespace std;


#ifndef __BAG_H__
#define __BAG_H__

/**
 *  \brief TDA abstracto Bolsa
 *
 *  Este TDA abstracto nos permite trabajar con una colección de elementos que
 *  permite la extracción de elementos de forma aleatoria sin reemplazamiento
 */

template <class T>
class Bag{
    /**
     * @page repBag Representación del TDA Bag .
     *
     * @section invBag Invariante de la representación.
     *
     * Esta estructura de datos puede almacenar cualquier valor T pero ninguno otro.
     *
     * @section faBag Función de abstracción
     +
     * Bag<int> =>   {1,4,2,6} -> v[0] = 1, v[1] = 4, v[2] = 2, v[3] = 6
     */
private:

    /**
     *  @brief Vector dinamico de tipo T
     *
     *  v almacena en un vector dinamico valores de tipo T
     */
    vector<T> v;
public:

    /**
     * @brief Constructor por defecto
     * Crea una bolsa vacía
     */
    inline Bag(){};

    /**
     * @brief Constructor de copia.
     * Crea una copia exacta de otro objeto de tipo Bag
     * @param other Objeto de tipo Bag<T> del que se va a realizar la copia
     */
    inline Bag(const Bag<T> & other):v(other.v){}

    /**
     * @brief Añade un elemento a la bolsa
     * @param element elemento del tipo T a añadir a la bolsa
     */
    inline void add(const T & element){v.push_back(element);}

    /**
     * @brief Extrae un elemento aleatorio de la bolsa
     * Devuelve un elemento aleatorio de la bolsa y lo elimina de la misma
     * @return Elemento de tipo T extraido de la bolsa
     * @pre La bolsa no está vacía
     * @post El elemento devuelto se ha eliminado de la bolsa
     */
    inline T get(){
        srand(time(NULL));
        int num = (rand())%(v.size());
        T aux = v[num];

        swap(v[num],v[v.size()-1]);

        v.pop_back();

        return aux;

    }

    /**
     * @brief Elimina todos los elementos de la bolsa
     * Borra todos los elementos almacenados en la bolsa
     */
    inline void clear(){v.clear();}

    /**
     * @brief Tamaño de la bolsa
     * @return Número de elementos que hay en la bolsa
     */
    inline unsigned int size()const{return v.size();}

    /**
     * @brief Comprueba si la bolsa está vacía
     * @return true si la bolsa está vacía, false en caso contrario
     */
    inline bool empty(){return v.empty();}

    /**
     * @brief Sobrecarga del operador de asignación
     * @param other Bag<T> a copiar
     * @return Referencia a this para poder encadenar el operador
     */
    inline const Bag<T> operator=(const Bag<T> &other){
        this->v = other.v;

        return *this;
    }


};
#endif
