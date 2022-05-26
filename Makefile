# Makefile completo separando os diferentes elementos da aplicação em diretórios:
# - bin: arquivos executáveis (programa)
# - build: arquivos binários
# - doc: documentação (idealmente gerada de forma automática)
# - src: arquivos de código fonte
#
# Algumas variáveis são usadas com significado especial:
# - $@: nome do alvo (target)
# - $^: lista com os nomes de todos os pré-requisitos sem duplicatas
# - $<: nome do primeiro pré-requisito
#
# Comandos do sistema operacional
# Linux: rm -rf
# Windows: cmd //C del
RM=rm -rf
MKDIR=mkdir

# Compilador
CC=g++

# Variáveis para os diretórios
BIN_DIR=bin
BUILD_DIR=build
DOC_DIR=doc
SRC_DIR=src

# Nome do programa
PROG=$(demo)

# Opções de compilação
FLAGS=-W -Wall -pedantic -std=c++11

# Alvo para a compilação completa, removendo os arquivos objeto gerados ao final
all: $(PROG)

# Alvo para a construção do executável
# Ligação dos arquivos objeto (.o) definidos como dependências
$(PROG): $(BUILD_DIR)/$(PROG).o
	$(MKDIR) -p $(BIN_DIR)
	$(CC) $(FLAGS) -o $(BIN_DIR)/$@ $^
	@echo "> Executavel '$@' criado em '$(BIN_DIR)'"

# Alvo para a construção do arquivo objeto
# Compilação dos arquivos fonte definidos como dependências
$(BUILD_DIR)/$(PROG).o: $(SRC_DIR)/$(PROG).cpp
	$(MKDIR) -p $(BUILD_DIR)
	$(CC) -c $(FLAGS) -o $@ $<

# Garantia de que os alvos desta lista não sejam confundidos com arquivos de mesmo nome
.PHONY: all clean doxy debug doc

# Alvos para a geração automática de documentação de código fonte com Doxygen
# Remove sempre a documentação anterior (caso exista) e gera uma nova versão
doxy:
	$(RM) $(DOC_DIR)/*
	doxygen -g
doc:
	doxygen

# Alvo adicionando flags para depuração
debug: FLAGS += -g -O0
debug: $(PROG)

# Alvo para limpar arquivos temporários (objeto) gerados durante a compilação,
# assim como os arquivos executáveis
clean:
	$(RM) $(BIN_DIR)/*
	$(RM) $(BUILD_DIR)/*