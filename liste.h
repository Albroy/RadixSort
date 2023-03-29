#ifndef __LISTE_H__
#define __LISTE_H__

#include <stdio.h>
#include <stdlib.h>

#define NB 11

typedef struct elem{

	char number[NB];
	struct elem * next;

}Element;

typedef Element * ListTable;
typedef ListTable *ListBucket;


typedef struct {
	char c; 
	int order;
} relation;

void saisi(char * number);

ListTable insert_head_T(ListTable LT, char table[NB]);
ListTable insert_tail_T(ListTable LT, char table[NB]);
void show_LT(ListTable LT);
ListTable addzero(ListTable LT);
void free_LT(ListTable LT);

void free_Bucket(ListBucket Bucket, int nb_Bucketx);
ListBucket create_Bucket(int nb_Bucketx);
ListTable sort_Bucket(ListTable LT, int base, int position, ListBucket Bucket);
ListTable sort(ListTable LT, int base, int position);
ListTable recup(ListBucket Bucket, int base);

void freeBuffer();
void check_base(int *base);
void check_number(char *number, int base);

#endif