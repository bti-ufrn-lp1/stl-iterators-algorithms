/**
 * @file	algorithm1.cpp
 * @brief	Demonstracao da execução de algoritmos que realizam operações sobre
 *          <i>containers</i> sem modificar o seu conteúdo
 * @author	Everton Cavalcante (everton.cavalcante@ufrn.br)
 * @since	25/05/2022
 * @date	25/05/2022
 * @sa      https://www.cplusplus.com/reference/algorithm/
 */

#include <algorithm>
using std::any_of;
using std::count;
using std::find;
using std::for_each;
using std::none_of;

#include <array>
using std::array;

#include <iostream>
using std::cout;
using std::endl;

#include <iterator>
using std::begin;
using std::end;
using std::prev;

/** @brief Tamanho do <i>array</i> */
#define SIZE 8

/**
 * @brief Função que imprime um número qualquer na saída padrão
 * @param numero Número a ser impresso
 */
void imprime(int numero) {
    cout << numero << " ";
}

/**
 * @brief Função que verifica se um número é par
 * @param numero Número a ser verificado
 * @return Verdadeiro caso o número seja par, falso caso contrário
 */
bool ehPar(int numero) {
    return (numero % 2 == 0);
}

/** @brief Função principal */
int main() {
    array<int, SIZE> fibonacci = { 1, 1, 2, 3, 5, 8, 13, 21 };

    cout << "Sequência de Fibonacci (" << SIZE << " termos): ";
    for_each(begin(fibonacci), end(fibonacci), imprime);
    cout << endl;

    int buscado = 1;
    cout << "Foram encontradas " << count(begin(fibonacci), end(fibonacci), buscado) << " ocorrências de " << buscado << endl;

    buscado = 4;
    array<int, SIZE>::iterator it = find(begin(fibonacci), end(fibonacci), buscado);
    if (it == end(fibonacci)) {
        cout << "O número " << buscado << " não foi encontrado na sequência" << endl;
    }

    if (any_of(begin(fibonacci)+3, end(fibonacci), ehPar)) {
        cout << "Há pelo menos um número par entre " << *(begin(fibonacci)+3) << " e " << *prev(end(fibonacci)) << endl;
    }

    if (none_of(begin(fibonacci)+6, end(fibonacci), ehPar)) {
        cout << "Todos os números entre " << *(begin(fibonacci)+6) << " e " << *prev(end(fibonacci)) << " são ímpares" << endl;
    }

    return 0;
}