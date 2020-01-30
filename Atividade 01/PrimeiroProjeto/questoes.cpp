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
	for (int i = 0; i < n; i++) {
		std::cout << " " << num;
		num = num + aux;
		aux += 2;
	}
	std::cout << std::endl;
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
	std::cout << std::endl;
}

int questao6(int num) {
	if (num == 1 || num == 2) {
		return 1;
	}
	if (num > 2) {
		return questao6(num - 1) + questao6(num - 2);
	}
	else {
		return 0;
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
	int maior_idade_otimo = 0;
	int maior_idade_ruim = 0;
	int diferenca_idade = 0;
	int maior_idade_pessimo = 0;
	int diferenca_percentual;
	Espectador audiencia[100];
	for (int i = 0; i < 100; i++) {
		audiencia[i] = Espectador();
		audiencia[i] = { (rand() % 100) , opcoes[(rand() % 5)] };
	}

	for (int i = 0; i < 100; i++) {
		if (audiencia[i].nota == 'A') {   //quantidade de resposta ótimo
			qtd_otimo++;
			if (audiencia[i].idade > maior_idade_otimo) {
				maior_idade_otimo = audiencia[i].idade;
			}
		}
		if (audiencia[i].nota == 'B') {
			qtd_bom++;
		}
		if (audiencia[i].nota == 'C') {
			qtd_regular++;
		}
		if (audiencia[i].nota == 'D') {   // média de idade das pessoas que responderam ruim
			qtd_ruim++;
			idade_ruim += audiencia[i].idade;
			if (audiencia[i].idade > maior_idade_ruim) {
				maior_idade_ruim = audiencia[i].idade;
			}
		}
		if (audiencia[i].nota == 'E') {  //a percentagem de respostas péssimo e a maior idade que utilizou esta opção
			qtd_pessimo++;
			if (audiencia[i].idade > maior_idade_pessimo) {
				maior_idade_pessimo = audiencia[i].idade;
			}
		}
	}

	if (qtd_bom > qtd_regular) {      //a diferença percentual entre respostas bom e regular
		diferenca_percentual = qtd_bom - qtd_regular;
	}
	else {
		diferenca_percentual = qtd_regular - qtd_bom;
	}

	if (maior_idade_otimo > maior_idade_ruim) {      //a diferença de idade entre o mais velho ótimo e o mais velho ruim
		diferenca_idade = maior_idade_otimo - maior_idade_ruim;
	}
	else {
		diferenca_idade = maior_idade_ruim - maior_idade_otimo;
	}
	int media_idade_ruim = idade_ruim / qtd_ruim;

	std::cout << "A quantidade de respostas otimo foi " << qtd_otimo << std::endl;
	std::cout << "A diferenca percentual entre respostas bom e regular foi de " << diferenca_percentual << "%" << std::endl;
	std::cout << "A media de idade das pessoas que responderam ruim foi " << media_idade_ruim << std::endl;
	std::cout << "A percentagem de respostas pessimo foi " << qtd_pessimo << "%, e a maior idade que utilizou essa opcao foi " << maior_idade_pessimo << std::endl;
	std::cout << "A diferenca de idade entre a maior idade que respondeu otimo e a maior idade que respondeu ruim foi de " << diferenca_idade << " anos." << std::endl;
}

void resposta(int n, int variavel) {
	int resposta;
	int resposta6;
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
		break;

	case 4:
		std::cout << "Resposta quarta questao: " << std::endl;
		questao4();
		std::cout << std::endl;
		break;

	case 5:
		std::cout << "Resposta quinta questao: " << std::endl;
		questao5();
		std::cout << std::endl;
		break;

	case 6:
		std::cout << "Resposta sexta questao: " << std::endl;
		resposta6 = questao6(variavel);
		std::cout << resposta6 << std::endl;
		std::cout << std::endl;
		break;

	case 7:
		std::cout << "Resposta setima questao: " << std::endl;
		questao7();
		break;

	default:
		std::cout << "Questao nao existe.";
		break;
	}
}
