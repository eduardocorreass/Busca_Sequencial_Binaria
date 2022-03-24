#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int i, j, vet[500], num, achou, elem, inicio, fim, meio;
	
	for (i = 0; i < 500; i++)
		vet[i] = rand() % 1000;
		
	printf("Vetor nao ordenado: \n");	
	for (i = 0; i < 500; i++)
		printf("%d; ", vet[i]);
	
	printf("\n\nDigite o numero a ser buscado: ");
	scanf("%d", &num);
	
	i = 0;
	achou = 0;
	while (achou == 0 && i < 500){
		if (vet[i] == num){
			printf("\nBusca sequencial: O numero pertence ao vetor!\n");
			achou = 1;
		}
		i++;
	}
	if (achou == 0)
		printf("\nBusca sequencial: O numero nao pertence ao vetor!\n");
	
	inicio = -1;	
	for (i = 0; i < 500; i++){
		inicio++;
		for (j = inicio; j < 500; j++){
			if (vet[i] > vet[j]){
				elem = vet[i];
				vet[i] = vet[j];
				vet[j] = elem;
			}
		}
	}

	achou = 0;
	inicio = 0;
	fim = 499;
	i = 0;
	while (i < 500 && achou == 0){
		j = floor((inicio + fim) / 2);
		meio = vet[j];
		if (meio == num){
			printf("\nBusca binaria: O numero pertence ao vetor!");
			achou = 1;
		}
		else{
			if (num > meio)
				inicio = j + 1;
			else
				fim = j - 1;
		}
		i++;
	}
	if (achou == 0)
		printf("\nBusca binaria: O numero nao pertence ao vetor!");
	
	printf("\n\nVetor ordenado: \n");
	for (i = 0; i < 500; i++)
		printf("%d; ", vet[i]);
}
