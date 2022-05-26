/**
 * @file	numeric.cpp
 * @brief	Demonstracao da execução de algoritmos que realizam operações numéricas 
 *          sobre os elementos de <i>containers</i>
 * @author	Everton Cavalcante (everton.cavalcante@ufrn.br)
 * @since	25/05/2022
 * @date	25/05/2022
 * @sa      https://www.cplusplus.com/reference/numeric/
 */

#include <functional>
using std::multiplies;

#include <iterator>
using std::begin;
using std::end;

#include <iostream>
using std::cout;
using std::endl;

#include <numeric>
using std::accumulate;

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
    for (auto it = begin(v); it != end(v); ++it) {
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

    // Somatório dos elementos do vetor
    int soma = 0;
    soma += accumulate(begin(numeros), end(numeros), soma);
    cout << "Soma dos elementos do vetor: " << soma << endl;

    // Produtório dos elementos do vetor
    // É utilizado um objeto da classe operador 'multiplies' para representar a operação de multiplicação 
    // https://www.cplusplus.com/reference/functional/multiplies/
    int produto = 1;
    produto *= accumulate(begin(numeros), end(numeros), produto, multiplies<int>());
    cout << "Produto dos elementos do vetor: " << produto << endl;

    return 0;
}