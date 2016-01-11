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
	for (int i = 0; i < e->length; ++i)
	{
		sum += e->obj[i];
	}
	return sum;
}

void checkSize(bags *bag, int currSize){
	if (bag->currBag > bag->length)
	{
		bag->sacs = realloc(bag->sacs, sizeof(int) * (currSize + 500));
		bag->length += 500;
	}
}

void addNextFit(int obj, bags *next){
	if (next->currBag == -1)
	{
		next->currBag = 0;
	}


	if (*(next->sacs + next->currBag * sizeof(int)) + obj > next->capacite)
	{
		next->currBag++;
		checkSize(next, next->currBag);
	}

	int tmp = *(next->sacs + next->currBag * sizeof(int)) + obj;
	*(next->sacs + next->currBag * sizeof(int)) = tmp;
}

void addFirstFit(int obj, bags *first){
	bool done = false;
	int bag = 0;

	if (first->currBag == -1)
	{
		first->currBag = 0;
	}


	if (*(first->sacs + first->currBag * sizeof(int)) + obj > first->capacite)
	{
		for (int i = 0; i < first->currBag; ++i)
		{
			if (*(first->sacs + i * sizeof(int)) + obj <= first->capacite && !done)
			{
				done = true;
				bag=i;
			}
		}

		if (!done)
		{
			first->currBag++;
			checkSize(first, first->currBag);
			*(first->sacs + first->currBag * sizeof(int)) = obj;
		}else{
			int tmp = *(first->sacs + bag * sizeof(int)) + obj;
			*(first->sacs + bag * sizeof(int)) = tmp;
		}


	}else{
		int tmp = *(first->sacs + first->currBag * sizeof(int)) + obj;
		*(first->sacs + first->currBag * sizeof(int)) = tmp;
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

	if (*(best->sacs + best->currBag * sizeof(int)) + obj > best->capacite)
	{
		for (int i = 0; i < best->currBag; ++i)
		{
			if (*(best->sacs + i* sizeof(int)) + obj <= best->capacite)
			{
				if (gap == -1)
				{
					done = true;
					gap = best->capacite - (*(best->sacs + i * sizeof(int)) + obj);
					bag = i;
				}

				if (gap > best->capacite - (*(best->sacs + i * sizeof(int)) + obj))
				{
					gap = best->capacite - (*(best->sacs + i * sizeof(int)) + obj);
					bag = i;
				}
			}
		}

		if (!done)
		{
			best->currBag++;
			checkSize(best, best->currBag);

		}else{
			/*TODO Modifier pour garder currbag a nb de sac utilisé actuellement*/
			best->currBag = bag;
		}
	}

	int tmp = *(best->sacs + best->currBag * sizeof(int)) + obj;
	*(best->sacs + best->currBag * sizeof(int)) = tmp;


}

bool Terminated(enumeration *e){
	return (!hasMoreElement(e)) ;
}

void nextPartialSolution(enumeration * e, bags *first, bags *next, bags *best){
	if (!Terminated(e))
	{
		int obj = nextElement(e);

		addFirstFit(obj, first);
		addNextFit(obj, next);
		addBestFit(obj, best);
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

	for (int i = 0; i < *nbObj; ++i)
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



void init(bags* first, bags* next, bags* best, int capacite){
	first->sacs = calloc(NBSAC, sizeof(int));
	first->length = NBSAC;
	first->currBag = -1;
	first->capacite = capacite;
	next->sacs = calloc(NBSAC, sizeof(int));
	next->length = NBSAC;
	next->currBag = -1;
	next->capacite = capacite;
	best->sacs = calloc(NBSAC, sizeof(int));
	best->length = NBSAC;
	best->currBag = -1;
	best->capacite = capacite;
}

void free_bags(bags *first, bags *next, bags *best){
	free(first->sacs);
		free(next->sacs);
	free(best->sacs);

}

void display(bags first, bags next, bags best){
	printf("BinPack : \n");
	printf("	First : %d\n", first.currBag);
	printf("	Next : %d\n", next.currBag);
	printf("	Best : %d\n", best.currBag);
}


int main(int argc, char **argv){
	enumeration enu;
	int nbObj = 0, capacite = 0;
	//int current[3] = {0,0,0}; 
	bags first, next, best;


	if (argc < 2)
	{
		perror("No data file given.\n");
		exit(EXIT_FAILURE);
	}else{
		readFile(argv[1], &nbObj, &capacite, &enu);
		printf("NBObj : %d  --- Capacité : %d  \n", enu.length, capacite);
	}	

	//Initializing bags
	init(&first, &next, &best, capacite);

	//Processing binPack
	while(!Terminated(&enu)){
		nextPartialSolution(&enu, &first, &next, &best);
	}

	free_bags(&first, &next, &best);

	display(first, next, best);
	return 0;
}
