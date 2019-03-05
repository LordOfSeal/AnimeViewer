/****************************
** Создатель : Косов Виктор
** Файл      : main.c
** Дата      : 4.03.2019
*****************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "db.h"


int main(int argc,char** argv)
{
	int opt;
	if(!openDB("anime.db"))
		printf("Error!\n");
	while((opt=getopt(argc,argv,"a:s")) != -1)
	{
		switch(opt)
		{
			case 's':
				getAll();
				break;
			case 'a':
				insertField(optarg);
				break;
		}
	}
	closeDB();	
	return 0;
}