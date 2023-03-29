#include <stdio.h>
#include <string.h>
#include "liste.h"

int main(){
	
	char *number=NULL;
	number=(char *)malloc(sizeof(char)*NB);

	int base=0;
	int nb_number=0;

	printf("\nEntrer base:");
	scanf("%d",&base);
	check_base(&base);
	freeBuffer();

	printf("\nEntrer le nombre number que vous voulez entrer:");
	scanf("%d",&nb_number);
	freeBuffer();


 ListTable LT=NULL;

	show_LT(LT);

	for (int i=0; i<nb_number; i++){

		printf("\nEntrer number: ");
		fgets (number, NB, stdin);
		number[strcspn(number, "\n" )] = '\0';
		freeBuffer();
		check_number(number,base);
		LT= insert_tail_T(LT,number);

	}

	LT=addzero(LT);
	printf("\n------------------------------\n");
	printf("sort en cours");
	printf("\n------------------------------\n");
	LT=sort(LT, base,NB-1);

	printf("\n------------------------------\n");
	printf("Fin du sort");
	printf("\n------------------------------\n");

	show_LT(LT);


	free_LT(LT);
	free(number);
	
	return 0;

}

