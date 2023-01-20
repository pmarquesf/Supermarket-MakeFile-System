# Exemplo de Makefile para o codigo em estrutura de projeto

# Compiler
CC=cc

# Command used at clean target
RM=rm -f

STD=-std=c99 -Wall
# -std=c99: padrao C99 da linguagem C
# -ansi:    padrao C90 da linguagem C

# Flags for compiler
CC_FLAGS=-c -Wpedantic -Wno-unused-result -O0 -g
# -O0: nao otimiza o codigo ao compilar
# -g:  prepara o terreno para que o gdb possa encontrar bugs

INCLUDES=./includes
LIBRARIES=./libs

LIBS=
# -lm  necessario no caso de usar o header math.h

# .c files
C_SRC=$(wildcard ./src/*.c $(LIBRARIES)/*.c)

# .h files
H_SRC=$(wildcard $(INCLUDES)/*.h)

# Object files
OBJ:=$(patsubst %.c,./objs/%.o,$(notdir $(C_SRC)))
# notdir filtrarah somente o nome dos arquivos .c
# patsubst inclui o subdiretorio objs como parte do caminho
# dos arquivos, substituindo .c por .o

binary=main
# para produzir o arquivo executavel printy,
# basta digitar "make printy"

all: show objdir $(binary)

# $(binary): main.o helloWorld.o
$(binary): $(OBJ)
	@echo "Compilando o alvo principal: $@"
	$(CC) $(STD) $^ -o $@ $(LIBS) -I./ -I$(INCLUDES) -L$(LIBRARIES)
	@echo
	@echo "The End"
	@echo
# o que parecem ser espacos no comeco da linha anterior
# sao, na verdade, um unico caractere de tabulacao (\t)

./objs/main.o: ./src/main.c $(H_SRC)
	@echo 'Compilando o alvo para: $<'
	$(CC) $< $(STD) $(CC_FLAGS) -o $@ -I./ -I$(INCLUDES)
	@echo

./objs/%.o: ./libs/%.c
	@echo 'Compilando o alvo para: $<'
	$(CC) $< -fPIC $(STD) $(CC_FLAGS) -o $@ -I./ -I$(INCLUDES)
#	ar rvs $(LIBRARIES)/libhello.a $@
	@echo

objdir:
	@mkdir -p objs

show:
	@echo "C source files: $(C_SRC)"
	@echo "Header files: $(H_SRC)"
	@echo "Object files: $(OBJ)"
	@echo

clean:
	@$(RM) *~ $(binary) libs/*.a
	@find . -name "*.o" -exec $(RM) {} \;
	@$(RM)r objs

.PHONY: all clean

