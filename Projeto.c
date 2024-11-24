#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int registradores(char *registrador)
{

	// Compara o nome do registrador
	if (strcmp(registrador, "$zero,") == 0)
		return 0;
	if (strcmp(registrador, "$at,") == 0)
		return 1;
	if (strcmp(registrador, "$v0,") == 0)
		return 2;
	if (strcmp(registrador, "$v1,") == 0)
		return 3;
	if (strcmp(registrador, "$a0,") == 0)
		return 4;
	if (strcmp(registrador, "$a1,") == 0)
		return 5;
	if (strcmp(registrador, "$a2,") == 0)
		return 6;
	if (strcmp(registrador, "$a3,") == 0)
		return 7;
	if (strcmp(registrador, "$t0,") == 0)
		return 8;
	if (strcmp(registrador, "$t1,") == 0)
		return 9;
	if (strcmp(registrador, "$t2,") == 0)
		return 10;
	if (strcmp(registrador, "$t3,") == 0)
		return 11;
	if (strcmp(registrador, "$t4,") == 0)
		return 12;
	if (strcmp(registrador, "$t5,") == 0)
		return 13;
	if (strcmp(registrador, "$t6,") == 0)
		return 14;
	if (strcmp(registrador, "$t7,") == 0)
		return 15;
	if (strcmp(registrador, "$t8,") == 0)
		return 16;
	if (strcmp(registrador, "$t9,") == 0)
		return 17;
	if (strcmp(registrador, "$s0,") == 0)
		return 18;
	if (strcmp(registrador, "$s1,") == 0)
		return 19;
	if (strcmp(registrador, "$s2,") == 0)
		return 20;
	if (strcmp(registrador, "$s3,") == 0)
		return 21;
	if (strcmp(registrador, "$s4,") == 0)
		return 22;
	if (strcmp(registrador, "$s5,") == 0)
		return 23;
	if (strcmp(registrador, "$s6,") == 0)
		return 24;
	if (strcmp(registrador, "$s7,") == 0)
		return 25;
	if (strcmp(registrador, "$k0,") == 0)
		return 26;
	if (strcmp(registrador, "$k1,") == 0)
		return 27;
	if (strcmp(registrador, "$gp,") == 0)
		return 28;
	if (strcmp(registrador, "$sp,") == 0)
		return 29;
	if (strcmp(registrador, "$fp,") == 0)
		return 30;
	if (strcmp(registrador, "$ra,") == 0)
		return 31;

	return -1; // Registrador nao encontrado
}

int registradoresSemVirgula(char *registrador)
{

	// Compara o nome do registrador
	if (strcmp(registrador, "$zero") == 0)
		return 0;
	if (strcmp(registrador, "$at") == 0)
		return 1;
	if (strcmp(registrador, "$v0") == 0)
		return 2;
	if (strcmp(registrador, "$v1") == 0)
		return 3;
	if (strcmp(registrador, "$a0") == 0)
		return 4;
	if (strcmp(registrador, "$a1") == 0)
		return 5;
	if (strcmp(registrador, "$a2") == 0)
		return 6;
	if (strcmp(registrador, "$a3") == 0)
		return 7;
	if (strcmp(registrador, "$t0") == 0)
		return 8;
	if (strcmp(registrador, "$t1") == 0)
		return 9;
	if (strcmp(registrador, "$t2") == 0)
		return 10;
	if (strcmp(registrador, "$t3") == 0)
		return 11;
	if (strcmp(registrador, "$t4") == 0)
		return 12;
	if (strcmp(registrador, "$t5") == 0)
		return 13;
	if (strcmp(registrador, "$t6") == 0)
		return 14;
	if (strcmp(registrador, "$t7") == 0)
		return 15;
	if (strcmp(registrador, "$t8") == 0)
		return 16;
	if (strcmp(registrador, "$t9") == 0)
		return 17;
	if (strcmp(registrador, "$s0") == 0)
		return 18;
	if (strcmp(registrador, "$s1") == 0)
		return 19;
	if (strcmp(registrador, "$s2") == 0)
		return 20;
	if (strcmp(registrador, "$s3") == 0)
		return 21;
	if (strcmp(registrador, "$s4") == 0)
		return 22;
	if (strcmp(registrador, "$s5") == 0)
		return 23;
	if (strcmp(registrador, "$s6") == 0)
		return 24;
	if (strcmp(registrador, "$s7") == 0)
		return 25;
	if (strcmp(registrador, "$k0") == 0)
		return 26;
	if (strcmp(registrador, "$k1") == 0)
		return 27;
	if (strcmp(registrador, "$gp") == 0)
		return 28;
	if (strcmp(registrador, "$sp") == 0)
		return 29;
	if (strcmp(registrador, "$fp") == 0)
		return 30;
	if (strcmp(registrador, "$ra") == 0)
		return 31;

	return -1; // Registrador nao encontrado
}

//--------------------------------------------------------------------------
// Tipo I

void executorAddi(int vetor[], char *tokens, char *tokens2, int numeroAddi)
{
	int validacao = 0;
	int i1 = registradores(tokens);
	int i2 = registradores(tokens2);
	if (i1 > 0 && i2 >= 0)
	{
		vetor[i1] = vetor[i2] + numeroAddi;
	}
	else
	{
		validacao = 1;
		printf("algo deu errado");
	}

	if (validacao == 0)
	{
		printf("\n--------Valores em decimal--------\nCódigo da Instrução: 8\nrs: %d\nrt: %d\nEnd. Imediato: %d\n----------------------------------\n", i1, i2, numeroAddi);
	}
}

int executorLi(int vetor[], char *tokens, int numeroLi)
{
	int validacao = 0;
	int i1 = registradores(tokens);
	if (i1 > 0)
	{
		vetor[i1] = numeroLi;
	}
	else
	{
		validacao = 1;
		printf("algo deu errado\n");
		return 1;
	}
	if (validacao == 0)
	{
		printf("\n--------Valores em decimal--------\nCódigo da Instrução: 32\nrs: %d\nrt: 0\nEnd. Imediato: %d\n----------------------------------\n", i1, numeroLi);
		return 0;
	}
	return 1;
}

//--------------------------------------------------------------------------
// Tipo R

void executorSub(int vetor[], char *tokens, char *tokens2, char *tokens3)
{
	int validacao = 0;
	int i1 = registradores(tokens);
	int i2 = registradores(tokens2);
	int i3 = registradoresSemVirgula(tokens3);
	if (i1 > 0 && i2 >= 0 && i3 >= 0)
	{
		vetor[i1] = vetor[i2] - vetor[i3];
	}
	else
	{
		validacao = 1;
		printf("algo deu errado");
	}

	if (validacao == 0)
	{
		printf("\n--------Valores em decimal--------\nCódigo da Instrução: 0\nrs: %d\nrt: %d\nrd: %d\nShamt: 0\nFunct: 34\n----------------------------------\n", i1, i2, i3);
	}
}

void executorSubu(int vetor[], char *tokens, char *tokens2, char *tokens3)
{
	int validacao = 0;
	int i1 = registradores(tokens);
	int i2 = registradores(tokens2);
	int i3 = registradoresSemVirgula(tokens3);
	if (i1 > 0 && i2 >= 0 && i3 >= 0)
	{
		vetor[i1] = vetor[i2] - vetor[i3];
	}
	else
	{
		validacao = 1;
		printf("algo deu errado");
	}

	if (vetor[i1] < 0 && validacao == 0)
	{
		vetor[i1] = (vetor[i1]) * (-1);
	}


	if (validacao == 0)
	{
		printf("\n--------Valores em decimal--------\nCódigo da Instrução: 0\nrs: %d\nrt: %d\nrd: %d\nShamt: 0\nFunct: 35\n----------------------------------\n", i1, i2, i3);
	}
}

void executorAdd(int vetor[], char *tokens, char *tokens2, char *tokens3)
{
	int validacao = 0;
	int i1 = registradores(tokens);
	int i2 = registradores(tokens2);
	int i3 = registradoresSemVirgula(tokens3);

	if (i1 > 0 && i2 >= 0 && i3 >= 0)
	{
		vetor[i1] = vetor[i2] + vetor[i3];
	}
	else
	{
		validacao = 1;
		printf("algo deu errado");
	}

	if (validacao == 0)
	{
		printf("\n--------Valores em decimal--------\nCódigo da Instrução: 0\nrs: %d\nrt: %d\nrd: %d\nShamt: 0\nFunct: 32\n----------------------------------\n", i1, i2, i3);
	}
}

void executorAddu(int vetor[], char *tokens, char *tokens2, char *tokens3)
{
	int validacao = 0;
	int i1 = registradores(tokens);
	int i2 = registradores(tokens2);
	int i3 = registradoresSemVirgula(tokens3);

	if (i1 > 0 && i2 >= 0 && i3 >= 0)
	{
		vetor[i1] = vetor[i2] + vetor[i3];
	}
	else
	{
		validacao = 1;
		printf("algo deu errado");
	}

	if (vetor[i1] < 0 && validacao == 0)
	{
		vetor[i1] = (vetor[i1]) * (-1);
	}

	if (validacao == 0)
	{
		printf("\n--------Valores em decimal--------\nCódigo da Instrução: 0\nrs: %d\nrt: %d\nrd: %d\nShamt: 0\nFunct: 33\n----------------------------------\n", i1, i2, i3);
	}
}

void executorMul(int vetor[], char *tokens, char *tokens2, char *tokens3)
{
	int validacao = 0;
	int i1 = registradores(tokens);
	int i2 = registradores(tokens2);
	int i3 = registradoresSemVirgula(tokens3);

	if (i1 > 0 && i2 >= 0 && i3 >= 0)
	{
		vetor[i1] = vetor[i2] * vetor[i3];
	}
	else
	{
		validacao = 1;
		printf("algo deu errado");
	}

	if (validacao == 0)
	{
		printf("\n--------Valores em decimal--------\nCódigo da Instrução: 0\nrs: %d\nrt: %d\nrd: %d\nShamt: 0\nFunct: 24\n----------------------------------\n", i1, i2, i3);
	}
}

void executorMulo(int vetor[], char *tokens, char *tokens2, char *tokens3)
{
	int validacao = 0;
	int i1 = registradores(tokens);
	int i2 = registradores(tokens2);
	int i3 = registradoresSemVirgula(tokens3);

	if (i1 > 0 && i2 >= 0 && i3 >= 0)
	{
		vetor[i1] = vetor[i2] * vetor[i3];
	}
	else
	{
		validacao = 1;
		printf("algo deu errado");
	}

	if (validacao == 0)
	{
		printf("\n--------Valores em decimal--------\nCódigo da Instrução: 0\nrs: %d\nrt: %d\nrd: %d\nShamt: 0\nFunct: 25\n----------------------------------\n", i1, i2, i3);
	}
}

void executorMulou(int vetor[], char *tokens, char *tokens2, char *tokens3)
{
	int validacao = 0;
	int i1 = registradores(tokens);
	int i2 = registradores(tokens2);
	int i3 = registradoresSemVirgula(tokens3);

	if (i1 > 0 && i2 >= 0 && i3 >= 0)
	{
		vetor[i1] = vetor[i2] * vetor[i3];
	}
	else
	{
		validacao = 1;
		printf("algo deu errado");
	}

	if (vetor[i1] < 0 && validacao == 0)
	{
		vetor[i1] = (vetor[i1]) * (-1);
	}

	if (validacao == 0)
	{
		printf("\n--------Valores em decimal--------\nCódigo da Instrução: 0\nrs: %d\nrt: %d\nrd: %d\nShamt: 0\nFunct: 26\n----------------------------------\n", i1, i2, i3);
	}
}

void executorMove(int vetor[], char *tokens, char *tokens2)
{
	int validacao = 0;
	int i1 = registradores(tokens);
	int i2 = registradoresSemVirgula(tokens2);

	if (i1 > 0 && i2 >= 0)
	{
		vetor[i1] = vetor[i2];
	}
	else
	{
		validacao = 1;
		printf("algo deu errado");
	}

	if (validacao == 0)
	{
		printf("\n--------Valores em decimal--------\nCódigo da Instrução: 0\nrs: %d\nrt: 0\nrd: %d\nShamt: 0\nFunct: Pseudo-instrução -> 32\n----------------------------------\n", i1, i2);
	}
}

void executorDiv(int vetor[], char *tokens, char *tokens2, char *tokens3)
{
	int validacao = 0;
	int i1 = registradores(tokens);
	int i2 = registradores(tokens2);
	int i3 = registradoresSemVirgula(tokens3);

	if (i1 > 0 && i2 >= 0 && i3 >= 0)
	{
		vetor[i1] = vetor[i2] / vetor[i3];
	}
	else
	{
		validacao = 1;
		printf("algo deu errado");
	}

	if (validacao == 0)
	{
		printf("\n--------Valores em decimal--------\nCódigo da Instrução: 0\nrs: %d\nrt: %d\nrd: %d\nShamt: 0\nFunct: 26\n----------------------------------\n", i1, i2, i3);
	}
}

void executorDivu(int vetor[], char *tokens, char *tokens2, char *tokens3)
{
	int validacao = 0;
	int i1 = registradores(tokens);
	int i2 = registradores(tokens2);
	int i3 = registradoresSemVirgula(tokens3);

	if (i1 > 0 && i2 >= 0 && i3 >= 0)
	{
		vetor[i1] = vetor[i2] / vetor[i3];
	}
	else
	{
		validacao = 1;
		printf("algo deu errado");
	}

	if (vetor[i1] < 0 && validacao == 0)
	{
		vetor[i1] = (vetor[i1]) * (-1);
	}

	if (validacao == 0)
	{
		printf("\n--------Valores em decimal--------\nCódigo da Instrução: 0\nrs: %d\nrt: %d\nrd: %d\nShamt: 0\nFunct: 27\n----------------------------------\n", i1, i2, i3);
	}
}

void executorRem(int vetor[], char *tokens, char *tokens2, char *tokens3)
{
	int validacao = 0;
	int i1 = registradores(tokens);
	int i2 = registradores(tokens2);
	int i3 = registradoresSemVirgula(tokens3);

	if (i1 > 0 && i2 >= 0 && i3 >= 0)
	{
		vetor[i1] = vetor[i2] % vetor[i3];
	}
	else
	{
		validacao = 1;
		printf("algo deu errado");
	}

	if (validacao == 0)
	{
		printf("\n--------Valores em decimal--------\nCódigo da Instrução: 0\nrs: %d\nrt: %d\nrd: %d\nShamt: 0\nFunct: 36\n----------------------------------\n", i1, i2, i3);
	}
}

void executorRemu(int vetor[], char *tokens, char *tokens2, char *tokens3)
{
	int validacao = 0;
	int i1 = registradores(tokens);
	int i2 = registradores(tokens2);
	int i3 = registradoresSemVirgula(tokens3);

	if (i1 > 0 && i2 >= 0 && i3 >= 0)
	{
		vetor[i1] = vetor[i2] % vetor[i3];
	}
	else
	{
		validacao = 1;
		printf("algo deu errado");
	}

	if (vetor[i1] < 0 && validacao == 0)
	{
		vetor[i1] = (vetor[i1]) * (-1);
	}

	if (validacao == 0)
	{
		printf("\n--------Valores em decimal--------\nCódigo da Instrução: 0\nrs: %d\nrt: %d\nrd: %d\nShamt: 0\nFunct: 37\n----------------------------------\n", i1, i2, i3);
	}
}

//--------------------------------------------------------------------------

void exibicaoReg(int vetor[], int pc)
{

	printf("\n| $zero: %d |\t| $at: %d |\t| $v0: %d |\t| $v1: %d |\t| $a0: %d |\t| $a1: %d |\t| $a2: %d |\t| $a3: %d |\n|  $t0: %d  |\t| $t1: %d |\t| $t2: %d |\t| $t3: %d |\t| $t4: %d |\t| $t5: %d |\t| $t6: %d |\t| $t7: %d |\n", vetor[0], vetor[1], vetor[2], vetor[3], vetor[4], vetor[5], vetor[6], vetor[7], vetor[8], vetor[9], vetor[10], vetor[11], vetor[12], vetor[13], vetor[14], vetor[15]);
	printf("|  $t8: %d  |\t| $t9: %d |\t| $s0: %d |\t| $s1: %d |\t| $s2: %d |\t| $s3: %d |\t| $s4: %d |\t| $s5: %d |\n|  $s6: %d  |\t| $s7: %d |\t| $k0: %d |\t| $k1: %d |\t| $gp: %d |\t| $sp: %d |\t| $fp: %d |\t| $ra: %d |\n|  pc: %d  |\n\n", vetor[16], vetor[17], vetor[18], vetor[19], vetor[20], vetor[21], vetor[22], vetor[23], vetor[24], vetor[25], vetor[26], vetor[27], vetor[28], vetor[29], vetor[30], vetor[31], pc);
}

//--------------------------------------------------------------------------

void instrucoes()
{
	int vetor[32] = {0}; // Vetor contendo todos os registradores
	/*vetor[0] = $zero
	vetor[1] = $at
	vetor[2 e 3] = $v0 e $v1
	vetor[4, 5, 6, 7] = $a0, $a1, $a2, $a3
	vetor[8 ao 17] = $t0 ao $t9
	vetor[18 ao 25] = $s0 ao $s7
	vetor[26 e 27] = $k0 e $k1
	vetor[28] = $gp
	vetor[29] = $sp
	vetor[30] = $fp
	vetor[31] = $ra
	*/

	char *tokens[50]; // vetor para armazenar os tokens
	int i;			  // Inicializando o indice
	char frase[256];  // A frase que o usuario digitar
	int numeroLi;	  // Esse nC:mero serC! utilizado para converter de char para int
	int pc = 0;		  // contador pc, utilizado no jump e conta instrucoes
	int invalido = 0; 

	while (1)
	{
		invalido = 0;
		fgets(frase, sizeof(frase), stdin); // Recebe o codigo do usuario
		frase[strcspn(frase, "\n")] = '\0'; // Remove o caractere de nova linha '\n' que o fgets pode deixar

		i = 0; // iniciliza o indice

		char *token = strtok(frase, " "); // Usa strtok para dividir a frase em tokens com base no espaco " "

		for (int j = 0; j < (int)sizeof(token); j++) // Converte maiusculas para minusculas
		{
			token[j] = tolower(token[j]);
		}

		// Armazena os tokens no vetor tokens[]
		while (token != NULL)
		{
			tokens[i] = token;		   // Armazena o token no vetor
			i++;					   // Incrementa o indice
			token = strtok(NULL, " "); // Continua dividindo a frase
		}

		// minusculo(tokens);

		// nesse momento sera encontrado qual instrucao o usuario digitou, no caso addi
		if (strcmp(tokens[0], "addi") == 0)
		{
			numeroLi = atoi(tokens[3]); // converte o fim da instrucao para um numero inteiro para calculo
			// nesse momento sera encontrado qual registrador o usuario digitou
			if (i == 4)
			{
				executorAddi(vetor, tokens[1], tokens[2], numeroLi);
			}
		}

		// intrucao sub
		else if (strcmp(tokens[0], "sub") == 0)
		{
			if (i == 4)
			{
				executorSub(vetor, tokens[1], tokens[2], tokens[3]);
			}
		}

		// instrucao mul
		else if (strcmp(tokens[0], "mul") == 0)
		{
			if (i == 4)
			{
				executorMul(vetor, tokens[1], tokens[2], tokens[3]);
			}
		}

		// instrucao mulo
		else if (strcmp(tokens[0], "mulo") == 0)
		{
			if (i == 4)
			{
				executorMul(vetor, tokens[1], tokens[2], tokens[3]);
			}
		}

		// instrucao mulou
		else if (strcmp(tokens[0], "mulou") == 0)
		{
			if (i == 4)
			{
				executorMulou(vetor, tokens[1], tokens[2], tokens[3]);
			}
		}

		// instrucao add
		else if (strcmp(tokens[0], "add") == 0)
		{
			if (i == 4)
			{
				executorAdd(vetor, tokens[1], tokens[2], tokens[3]);
			}
		}

		// instrucao addu
		else if (strcmp(tokens[0], "addu") == 0)
		{
			if (i == 4)
			{
				executorAddu(vetor, tokens[1], tokens[2], tokens[3]);
			}
		}

		// instrucao subu
		else if (strcmp(tokens[0], "subu") == 0)
		{
			if (i == 4)
			{
				executorSubu(vetor, tokens[1], tokens[2], tokens[3]);
			}
		}

		// intrucao carrega um imediato
		else if (strcmp(tokens[0], "li") == 0)
		{
			numeroLi = atoi(tokens[2]);
			if (i == 3)
			{
				invalido = executorLi(vetor, tokens[1], numeroLi);
			}
		}

		// instrucao de troca de registradores (move)
		else if (strcmp(tokens[0], "move") == 0)
		{
			if (i == 3)
			{
				executorMove(vetor, tokens[1], tokens[2]);
			}
		}

		// instrucao div
		else if (strcmp(tokens[0], "div") == 0)
		{
			if (i == 4)
			{
				executorDiv(vetor, tokens[1], tokens[2], tokens[3]);
			}
		}

		// instrucao divu
		else if (strcmp(tokens[0], "divu") == 0)
		{
			if (i == 4)
			{
				executorDivu(vetor, tokens[1], tokens[2], tokens[3]);
			}
		}

		// instrucao rem
		else if (strcmp(tokens[0], "rem") == 0)
		{
			if (i == 4)
			{
				executorRem(vetor, tokens[1], tokens[2], tokens[3]);
			}
		}

		// instrucao remu
		else if (strcmp(tokens[0], "remu") == 0)
		{
			if (i == 4)
			{
				executorRemu(vetor, tokens[1], tokens[2], tokens[3]);
			}
		}

		// intrucao Jump, TIPO J
		else if (strcmp(tokens[0], "j") == 0)
		{

			if (strcmp(tokens[1], "end") == 0)
			{

				break;
			}
			else if (strcmp(tokens[1], "end") != 0)
			{

				pc = atoi(tokens[1]) - 4;

				printf("\n--------Valores em decimal--------\nCódigo da Instrução: 2\nEndereço: %d\n----------------------------------\n", pc + 4);
			}
		}
		else
		{
			printf("Nenhum comando válido, digite novamente.\n");
			invalido = 1;
		}

		if (invalido == 0)
		{
			pc += 4;
			exibicaoReg(vetor, pc);
		}
	}

	printf("\n");
}

//--------------------------------------------------------------------------
// MAIN

int main()
{
	instrucoes();
	return 0;
}
