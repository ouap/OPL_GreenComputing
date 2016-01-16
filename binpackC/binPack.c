#include "binPack.h"

bool hasMoreElement(enumeration* e){
	return e->iterator < e->length;
}

int nextElement(enumeration* e){
	int i = e->obj[e->iterator];
	(e->iterator)++;
	return i;
}

int sum(enumeration* e){
	int sum = 0;
	int i;
	for (i = 0; i < e->length; i++)
	{
		sum += e->obj[i];
	}
	return sum;
}

void checkSize(bags *bag){
	if (bag->currBag > bag->length)
	{
		int* tmp = realloc(bag->sacs,  sizeof(int) * (bag->currBag + 500));
		if (tmp != NULL)
		{
			bag->sacs = tmp;
			bag->length += 500;	
		}

	}
}

void addNextFit(int obj, bags *next){
	if (next->currBag == -1)
	{
		next->currBag = 0;
	}


	if (next->sacs[next->currBag] + obj > next->capacite)
	{
		next->currBag++;
		checkSize(next);
		next->sacs[next->currBag] = obj;
	}else{
		int tmp = next->sacs[next->currBag] + obj;
		next->sacs[next->currBag] = tmp;
	}

	
}

void addFirstFit(int obj, bags *first){
	bool done = false;
	int bag = 0;

	if (first->currBag == -1)
	{
		first->currBag = 0;
	}


	if (first->sacs[first->currBag] + obj > first->capacite)
	{
		int i;
		for (i = 0; i < first->currBag; i++)
		{
			if (first->sacs[i] + obj <= first->capacite && !done)
			{
				done = true;
				bag=i;
			}
		}

		if (!done)
		{
			first->currBag++;
			checkSize(first);
			first->sacs[first->currBag] = obj;
		}else{
			int tmp = first->sacs[bag] + obj;
			first->sacs[bag] = tmp;
		}


	}else{
		int tmp = first->sacs[first->currBag] + obj;
		first->sacs[first->currBag] = tmp;
	}


}

void addBestFit(int obj, bags *best){
	bool done = false;
	int bag = 0;
	int gap = -1;

	if (best->currBag == -1)
	{
		best->currBag = 0;
	}

	
	int i;
	for (i = 0; i < best->currBag + 1 ; i++)
	{
		if (best->sacs[i] + obj <= best->capacite)
		{
			if (gap == -1)
			{
				done = true;
				gap = best->capacite - (best->sacs[i] + obj);
				bag = i;
			}

			if (gap > best->capacite - (best->sacs[i] + obj))
			{
				gap = best->capacite - (best->sacs[i] + obj);
				bag = i;
			}
		}
	}

	if (!done)
	{
		best->currBag++;
		checkSize(best);
		best->sacs[best->currBag] = obj;
	}else{
		int tmp = best->sacs[bag] + obj;
		best->sacs[bag] = tmp;
	}

	

}

bool terminated(enumeration *e){
	return (!hasMoreElement(e)) ;
}

void nextPartialSolution(enumeration * e, bags *bag, int method){
	if (!terminated(e))
	{
		int obj = nextElement(e);

		switch(method){
			case 1:
				addFirstFit(obj, bag);
				break;
			case 2:
				addNextFit(obj, bag);
				break;
			case 3:
				addBestFit(obj, bag);
				break;
		}
		
	}else{
		printf("Plus d'objet. \n");
	}

}



int readFile(char *file_name, int *nbObj, int *capacite, enumeration *enu){
	char buf[256];


	FILE *fp;

	fp = fopen(file_name,"r");

	if( fp == NULL )
	{
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}

	*nbObj =  atoi(fgets (buf, sizeof(buf), fp));
	*capacite = atoi(fgets (buf, sizeof(buf), fp));

	int i;
	for (i = 0; i < *nbObj; i++)
	{
		fgets (buf, sizeof(buf), fp);
		enu->obj[i] = atoi(buf);
		enu->length++;
	}

	if (ferror(stdin)) {
		fprintf(stderr,"Oops, error reading stdin\n");
		abort();
	}

	return 0;
}



void init(bags* bag, int capacite){
	bag->sacs = calloc(NBSAC, sizeof(int));
	bag->length = NBSAC;
	bag->currBag = -1;
	bag->capacite = capacite;
}

void free_bags(bags *bag){
	free(bag->sacs);
	bag->sacs = NULL;
}

void display(bags bag, int method){
	printf("BinPack : \n");
	switch(method){
		case 1:
		printf("	First : %d\n", bag.currBag +1);
		break;
		case 2:
		printf("	Next : %d\n", bag.currBag +1);
		break;
		case 3:
		printf("	Best : %d\n", bag.currBag +1);
		break;
	}
}


int main(int argc, char **argv){
	enumeration enu;
	int nbObj = 0, capacite = 0;
	bags bag;
	char* f = "first";
	char* n = "next";
	char* b = "best";
	int method;

	printf("%s\n",b );

	if (argc < 3)
	{
		perror("No data file given and/or binpack method.\n");
		exit(EXIT_FAILURE);
	}else{
		readFile(argv[1], &nbObj, &capacite, &enu);

		printf("NBObj : %d  --- Capacité : %d  \n", enu.length, capacite);
		//Initializing bags
		if(strcmp(argv[2], f)==0){
			method =1;
		}else if(strcmp(argv[2], n)==0){
			method =2;
		}else if(strcmp(argv[2], b) == 0){
			method =3;
		}else{
			perror("Wrong binpack method.\n");
			exit(EXIT_FAILURE);
		}
		init(&bag, capacite);
	}	

	
	//Processing binPack
	while(!terminated(&enu)){
		nextPartialSolution(&enu, &bag, method);
	}

	display(bag, method);

	free_bags(&bag);

	return 0;
}
