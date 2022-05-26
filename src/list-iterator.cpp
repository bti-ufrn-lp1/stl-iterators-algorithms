/**
 * @file	list-iterator.cpp
 * @brief	Demonstracao do uso de iteradores sobre o container
 *          <code>list</code>
 * @author	Everton Cavalcante (everton.cavalcante@ufrn.br)
 * @since	25/05/2022
 * @date	25/05/2022
 * @sa      http://www.cplusplus.com/reference/list/list/
 */

#include <iostream>
using std::cout;
using std::endl;

#include <list>
using std::list;

/**
 * @brief Função genérica que imprime os elementos de uma lista
 * @tparam T Tipo genérico
 * @param l Lista
 */
template <typename T>
void imprime(list<T> l) {
    cout << "Elementos da lista: ";
    for (auto it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

/** @brief Função principal */
int main() {
    list<int> l;
    for (int i = 1; i <= 5; i++) {
        l.push_back(i);
    }
    imprime(l);

    l.insert(++l.begin(), 10);          // Inserção de elemento na segunda posição da lista
    imprime(l);

    return 0;
}