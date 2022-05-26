/**
 * @file	algorithm2.cpp
 * @brief	Demonstracao da execução de algoritmos que realizam operações sobre <i>containers</i> 
 *          que modificam o seu conteúdo
 * @author	Everton Cavalcante (everton.cavalcante@ufrn.br)
 * @since	25/05/2022
 * @date	25/05/2022
 * @sa      https://www.cplusplus.com/reference/algorithm/
 */

#include <algorithm>
using std::random_shuffle;
using std::remove;
using std::replace;
using std::reverse;
using std::sort;
using std::swap;

#include <iomanip>
using std::setw;
using std::setfill;

#include <iostream>
using std::cout;
using std::endl;

#include <iterator>
using std::advance;
using std::begin;
using std::end;
using std::prev;

#include <string>
using std::string;

#include <vector>
using std::vector;

/**
 * @brief Função genérica que imprime os elementos de um vetor
 * @tparam T Tipo genérico
 * @param v Vetor
 */
template <typename T>
void imprime(vector<T> v) {
    for (auto it = begin(v); it != end(v); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

/** @brief Função principal */
int main() {
    // Construção de vector a partir de array
    // https://www.cplusplus.com/reference/vector/vector/vector/
    string arrayNomes[] = { "Amanda", "Carlos", "Victor", "Roberta", "Alexandre", "Patricia" };
    vector<string> nomes(arrayNomes, arrayNomes + sizeof(arrayNomes) / sizeof(string));
    cout << setw(17) << "original | ";
    imprime(nomes);

    // Disposição aleatória dos nomes no vetor
    random_shuffle(begin(nomes), end(nomes));
    cout << setw(14) << "random_shuffle | ";
    imprime(nomes);

    // Troca de posições entre o segundo e penúltimo nome no vetor
    vector<string>::iterator it = end(nomes);
    advance(it, -2);
    swap(*(begin(nomes)+1), *it);
    cout << setw(17) << "swap | ";
    imprime(nomes);

    // Remove ocorrências de um nome no vetor
    remove(begin(nomes), end(nomes), "Amanda");
    cout << setw(17) << "remove | ";
    imprime(nomes);

    // Substitui ocorrências de um nome no vetor
    replace(begin(nomes), end(nomes), string("Patricia"), string("Thais"));
    cout << setw(17) << "replace | ";
    imprime(nomes);

    // Ordena o vetor em ordem alfabética
    sort(begin(nomes), prev(end(nomes)));
    cout << setw(17) << "sort | ";
    imprime(nomes);

    // Ordena o vetor por ordem crescente do tamanho dos nomes
    // O comportamento da função sort é alterado por um predicado inline (retorna valor booleano)
    // https://www.cplusplus.com/reference/algorithm/sort/
    sort(begin(nomes), prev(end(nomes)), [](string n1, string n2) { 
        return (n1.size() < n2.size()); 
    });
    cout << setw(17) << "sort | ";
    imprime(nomes);

    // Inversão da ordem dos elementos do vetor
    reverse(begin(nomes), prev(end(nomes)));
    cout << setw(17) << "reverse | ";
    imprime(nomes);

    return 0;
}