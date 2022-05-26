/**
 * @file	vector-iterator.cpp
 * @brief	Demonstracao do uso de iteradores sobre o container
 *          <code>vector</code>
 * @author	Everton Cavalcante (everton.cavalcante@ufrn.br)
 * @since	25/05/2022
 * @date	25/05/2022
 * @sa      http://www.cplusplus.com/reference/vector/vector/
 * @sa      https://www.cplusplus.com/reference/iterator/
 */

#include <iostream>
using std::cout;
using std::endl;

#include <iterator>
using std::advance;
using std::begin;
using std::distance;
using std::end;
using std::prev;

#include <vector>
using std::vector;

/**
 * @brief Função genérica que imprime os elementos de um vetor
 * @tparam T Tipo genérico
 * @param v Vetor
 */
template <typename T>
void imprime(vector<T> v) {
    cout << "Elementos do vetor: ";
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

/** @brief Função principal */
int main() {
    vector<int> numeros;
    for (int i = 1; i <= 5; i++) {
        numeros.push_back(i);
    }
    imprime(numeros);

    vector<int>::iterator it = begin(numeros);
    advance(it, 2);
    cout << "Terceiro elemento do vetor: " << *it << endl;
    cout << "Último elemento do vetor: " << *prev(end(numeros)) << endl;

    cout << "Número de elementos entre " << *(numeros.begin()) << " e " << *prev(end(numeros)) << ": ";
    cout << distance(numeros.begin(), numeros.end()) << endl;

    return 0;
}