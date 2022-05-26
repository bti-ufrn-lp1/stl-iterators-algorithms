# *Standard Template Library* (STL) - Iteradores e Algoritmos

## Sobre
Este conjunto de programas serve à demonstração da execução de iteradores e algoritmos sobre os *containers* disponibilizados pela [*Standard Template Library* (STL)](https://en.wikipedia.org/wiki/Standard_Template_Library). 

Os iteradores são objetos utilizados para acessar os elementos de um *container*, enquanto os algoritmos são funções genéricas baseadas em tais iteradores que executam operações sobre os elementos de um *container*. Os algoritmos para operarem sobre *containers* estão disponíveis na biblioteca [`algorithm`](https://www.cplusplus.com/reference/algorithm/) e os algoritmos para realização de operações numéricas estão disponíveis na biblioteca [`numeric`](https://www.cplusplus.com/reference/numeric/).

## Estrutura do repositório
Este repositório contém um conjunto de arquivos fonte demonstrando, cada um, o uso de iteradores e algoritmos sobre *containers* e das funções eles disponibilizados. Os arquivos estão organizados de acordo com a seguinte estrutura:

```
+─stl-containers                ---> Nome do diretório do projeto
  ├─── bin                      ---> Diretório onde os programas executáveis serão gerados
  ├─── build                    ---> Diretório onde os arquivos objeto resultantes da compilação serão gerados
  ├─── Doxyfile                 ---> Arquivo de configuração para geração de documentação com Doxygen
  ├─── doc                      ---> Diretório onde a documentação em HTML será gerada
  ├─── Makefile                 ---> Arquivo Makefile para compilação
  └─── src                      ---> Diretório que contém os arquivos fonte
       └─── algorithm1.cpp      ---> Demonstração de algoritmos que realizam operações sobre containers sem modificar o seu conteúdo
       └─── algorithm2.cpp      ---> Demonstração de algoritmos que realizam operações sobre containers que modificam o seu conteúdo
       └─── list-iterator.cpp   ---> Demonstracao do uso de iteradores sobre o container 'list'
       └─── numeric.cpp         ---> Demonstracao de algoritmos que realizam operações numéricas sobre os elementos de containers
       └─── vector-iterator.cpp ---> Demonstracao do uso de iteradores sobre o container 'vector'
```

## Requisitos
Para a compilação e execução dos programas, os seguintes elementos devem estar devidamente instalados no ambiente de desenvolvimento:

- [Git](https://git-scm.com), como sistema de controle de versões
- [*GNU Compiler Collection*](https://gcc.gnu.org) (a qual inclui o compilador `g++`), [`clang`](https://clang.llvm.org/) ou qualquer outro compilador para a linguagem C++
- [*GNU Make*](https://www.gnu.org/software/make/), para a compilação via *makefile*
- [Doxygen](https://www.doxygen.nl), para geração automática de documentação

## Download, compilação e execução dos programas
No terminal do sistema operacional, insira os seguintes comandos para realizar o *download* da implementação a partir deste repositório Git e navegar para o diretório resultante:

```bash
 # Download da implementação a partir do repositório Git
 git clone https://github.com/bti-ufrn-lp1/stl-iterators-algorithms.git
 
 # Navegação para o diretório
 cd stl-iterators-algorithms
```

O [*makefile*](Makefile) foi construído para receber um parâmetro de entrada com nome `demo`, cujo valor será o nome do programa demonstrativo para o qual o respectivo código fonte (localizado dentre os arquivos no diretório [`src`](src) será compilado e executado. O seguinte comando deverá ser inserido no terminal do sistema operacional para compilar o programa associado:

```bash
 make demo=programa
```

sendo `programa` um dos seguintes *containers*:

| Valor   | Descrição |
| :---    | :---      |
| [`algorithm1`](src/algorithm1.cpp) | Algoritmos que realizam operações sobre *containers* sem modificar o seu conteúdo |
| [`algorithm2`](src/algorithm2.cpp) | Algoritmos que realizam operações sobre *containers* que modificam o seu conteúdo |
| [`list-iterator`](src/list-iterator.cpp) | Uso de iteradores sobre o container `list` |
| [`numeric`](src/numeric.cpp) | Algoritmos que realizam operações numéricas sobre os elementos de *containers* |
| [`vector-iterator`](src/vector-iterator.cpp) | Uso de iteradores sobre o container `vector` |

Dessa forma, por exemplo, para compilar o programa referente à demonstração [`vector-iterator`](src/vector-iterator.cpp), deve-se executar o comando `make` no terminal do sistema operacional da seguinte forma:

```bash
 make demo=vector-iterator
```

Note que o valor para o parâmetro `demo` deve ser **exatamente idêntico** aos relacionados acima. Caso esse parâmetro não seja informado, o comando `make` não fará nada e caso o valor não esteja dentre os relacionados acima, o comando `make` reportará um erro apontando que não existe regra definida para esse parâmetro. 

Finalmente, para executar o programa gerado, basta inserir o seguinte comando no terminal do sistema operacional:

```bash
 ./bin/vector-iterator
```

Nesse caso, será executado o programa de demonstração [`vector-iterator`](src/vector-iterator.cpp).
