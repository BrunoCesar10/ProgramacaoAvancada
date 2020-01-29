#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "questoes.h"

int questao1() {
	float x = 1.0;
	float y = 1.0;
	float vetor[50];
	float total = 0;
	for (int i = 0; i < 50; i++) {
		vetor[i] = (x / y);
		x = x + 2.0;
		y = y + 1.0;
	}
	for (int j = 0; j < 50; j++) {
		total += vetor[j];
	}
	return total;
}

float questao2(float n) {
	float numerador = 4;
	float denominador = 1;
	float total = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			total = total + (numerador / denominador);
		}
		else {
			total = total - (numerador / denominador);
		}
		denominador = denominador + 2;
	}
	return total;
}

float questao3() {
	float expoente = 1;
	float denominador = 50;
	float vetor[50];
	float total = 0;
	for (int i = 0; i < 50; i++) {
		vetor[i] = ((pow(2, expoente)) / denominador);
		expoente++;
		denominador--;
	}
	for (int i = 0; i < 50; i++) {
		total += vetor[i];
	}
	return total;
}

void questao4() {
	int n;
	std::cout << std::endl << "Insira o enesimo termo: " << std::endl;
	std::cin >> n;
	int inicio = 1;
	int aux = 3;
	int num = inicio;
	std::cout << "Resposta da quarta questao: " << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << " " << num;
		num = num + aux;
		aux += 2;
	}
}

void questao5() {
	int n;
	int num = 1;
	std::cout << std::endl << "Insira o enesimo termo: " << std::endl;
	std::cin >> n;
	int aux = 0;
	int vetor[] = { 3, 0, -2 };

	for (int i = 0; i < n; i++) {
		std::cout << num << " ";
		if (2 < aux) {
			aux = 0;
		}
		num = num + vetor[aux];
		aux++;
	}
}

void questao7() {
	char opcoes[5] = { 'A', 'B', 'C', 'D', 'E' };
	int qtd_otimo = 0;
	int qtd_bom = 0;
	int qtd_regular = 0;
	int idade_ruim = 0;
	int qtd_ruim = 0;
	int qtd_pessimo = 0;
	int maior_idade_pessimo = 0;
	Espectador audiencia[100];
	for (int i = 0; i < 100; i++) {
		audiencia[i] = Espectador();
		audiencia[i] = { (rand() % 100) , opcoes[(rand() % 5)] };
	}

	for (int i = 0; i < 100; i++) {
		if (audiencia[i].nota == 'A') {   //quantidade de resposta ótimo
			qtd_otimo++;
		}
		if (audiencia[i].nota == 'D') {   // média de idade das pessoas que responderam ruim
			qtd_ruim++;
			idade_ruim += audiencia[i].idade;
		}
		if (audiencia[i].nota == 'E') {  //a percentagem de respostas péssimo e a maior idade que utilizou esta opção
			qtd_pessimo++;
			if (audiencia[i].idade > maior_idade_pessimo) {
				maior_idade_pessimo = audiencia[i].idade;
			}
		}
	}
	int media_idade_ruim = idade_ruim / qtd_ruim;

	std::cout << "A quantidade de respostas ótimo foi " << qtd_otimo << std::endl;
	std::cout << "A média de idade das pessoas que responderam ruim foi " << media_idade_ruim << std::endl;
	std::cout << "A percentagem de respostas péssimo foi " << qtd_pessimo << "%, e a maior idade que utilizou essa opcao foi " << maior_idade_pessimo << std::endl;
}

void resposta(int n) {
	int resposta;
	float respostaFloat;
	float vetor[] = { 10, 100, 500, 1000, 10000, 20000 };
	switch (n)
	{
	case 1:
		resposta = questao1();
		std::cout << "Resposta primeira questao: " << std::endl;
		std::cout << resposta << "\n\n";
		break;

	case 2:
		std::cout << "Resposta segunda questao: " << std::endl;
		for (int i = 0; i < 6; i++) {
			respostaFloat = questao2(vetor[i]);
			std::cout << "Para " << vetor[i] << ": " << respostaFloat << std::endl;
		}
		std::cout << "\n\n";
		break;

	case 3:
		respostaFloat = questao3();
		std::cout << "Resposta terceira questao: " << std::endl;
		std::cout << respostaFloat << "\n\n";

	case 4:
		questao4();
		break;

	case 5:
		questao5();
		break;

	default:
		std::cout << "Questao nao existe.";
	}
}