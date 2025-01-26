compile: main.c Central.c Compartimento.c RochaMineral.c ListaMinerais.c Minerais.c
	gcc -o Executar main.c Compartimento.c RochaMineral.c ListaMinerais.c Minerais.c Central.c && .\Executar