#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAILLE 1000
#define NBSAC 100
typedef struct{
	int obj[TAILLE];
	int iterator;
	int length;
} enumeration; 


typedef struct{
	int* sacs;
	int length;
	int currBag;
	int capacite;
} bags;

extern bool hasMoreElement(enumeration*);
extern int NextElement(enumeration *);
extern int sum(enumeration*);



