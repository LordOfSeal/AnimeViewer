#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "db.h"


int main(void)
{
	if(!openDB("anime.db"))
		printf("Error!\n");
	getAll();
	closeDB();	
	return 0;
}