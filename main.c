#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>

int main(int argc, char* argv[]) {
	//setup needed vars
	char acc[20] = "";	//contains account name
	int request_id = 10000; //send id start
	
	//Open the output file
	FILE* send_items_file;
	send_items_file = fopen("send_items.sql", "a");
	
	//Test additional start info
	if(argc > 1) {
		strcpy(acc, argv[1]);	//use the defined account name
		if(argc > 2) {
			request_id = (int) strtol(argv[2], (char **)NULL, 10);	//use the defined request_id to start
		}
	}
	
	
	//Close the output file
	fclose(send_items_file);
	return 0;
}