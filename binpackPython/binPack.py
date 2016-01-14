import sys

def display(first, next, best):
	print("BinPack Python : \n")
	print("	First : " +str(len(first)))
	print("	Next : " + str(len(next)))
	print("	Best : " + str(len(best)))


def hasMoreElement(enum, iterator):
	return iterator < len(enum)

def nextElement(enum, iterator):
	return 	enum[iterator]


def terminated(enum, iterator):
	return not(hasMoreElement(enum, iterator))

def addFirstFit(first, obj, currbag, capacite):
	done = False
	bag = 0

	if len(first) == 0:
		first.append(0)
		currbag = len(first) - 1

	#print("Objet = " + str(obj))
	if first[currbag] + obj > capacite:
		for i in range(len(first)):
			if (first[i] + obj <= capacite) and not(done):
				done = True
				bag = i

		if not(done):
			first.append(0)
			currbag = len(first) - 1
		else:
			currbag = bag

	
	tmp = first[currbag] + obj
	del first[currbag]
	first.insert(currbag, tmp)
	currbag = len(first) - 1
	#print(first)

	return first, currbag

def addNextFit(next, obj, currbag, capacite):
	if len(next) == 0:
		next.append(0)
		currbag = len(next) - 1

	#print("Objet = " + str(obj))
	if next[currbag] + obj > capacite:
		next.append(obj)
		currbag = len(next) - 1 
	else:
		tmp = next[currbag] + obj
		next[currbag] = tmp

	#print(next)
	return next, currbag

def addBestFit(best, obj, currbag, capacite):
	done = False
	bag = 0
	gap = -1

	if len(best) == 0:
		best.append(0)
		currbag = len(best) - 1

	#print("Objet = " + str(obj))

	for i in range(len(best)):

		if best[i] + obj <= capacite:
			if(gap == -1):
				done = True
				gap = capacite - (best[i] + obj)
				bag = i

			if gap > capacite - (best[i] + obj):
				gap = capacite - (best[i] + obj)
				bag = i
				
				
	if not(done):
		best.append(0)
		currbag = len(best) - 1
	else:
		currbag = bag
	
	tmp = best[currbag] + obj
	del best[currbag]
	best.insert(currbag, tmp)
	currbag = len(best) - 1

	#print(best)

	return best, currbag

def nextPartialSolution(enum, capacite, current, first, next, best, iterator):
		obj = nextElement(enum, iterator)
		first, current[0] = addFirstFit(first, obj, current[0], capacite)
		next, current[1] = addNextFit(next, obj, current[1], capacite)
		best, current[2] = addBestFit(best, obj, current[2], capacite)

		return next, current


def readFile(file):
	enum = []

	with open(file, "r") as fp:
		nbObj=int(fp.readline())
		print("OBJET : " + str(nbObj))
		capacite=int(fp.readline())
		print("CAPACITE : " + str(capacite))

		for line in fp:
			enum.append(int(line))
	
	return nbObj, capacite, enum

def main():
	nbObj=0
	capacite=0
	current=[0,0,0]
	iterator=0
	enumeration = []
	first = []
	next = []
	best = []

	if len(sys.argv) < 2:
		sys.exit("No data file given.")
	else:
		nbObj, capacite, enumeration = readFile(sys.argv[1])
		print("NBOBJ  : " + str(nbObj) + "   ------   Capacite : " + str(capacite))
		print("Taille enumeration : " + str(len(enumeration)))

	while not(terminated(enumeration, iterator)):
		next, current = nextPartialSolution(enumeration, capacite, current, first, next, best, iterator)
		iterator+=1

	display(first, next, best)
		

if __name__ == "__main__":
			main()
