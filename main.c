#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>

int main(int argc, char* argv[]) {
	//setup needed vars
	int request_id = 10000; //send id start
	char item_amount[20] = "1";	//item_amount, should not exceed stack limit
	char input_str[20] = "";	//string for the user input
	char entire_str[256] = "";	//string to store the entire sql command
	
	//Open the output file
	FILE* send_items_file;
	send_items_file = fopen("send_items.sql", "a");
	
	//Test additional start info
	if(argc > 1) {
		request_id = (int) strtol(argv[1], (char**) NULL, 10);	//use the defined request_id to start
	}
	
	while(TRUE) {	//main loop
		
		//init string and add request_id
		sprintf(entire_str, "INSERT INTO \"item_receivable\" VALUES (%d, 1, '2001-1-1 11:11:11.00001', '2001-1-1 11:11:11.00001', '", request_id);
		
		//test for account name
		if(argc < 3) {
			printf("Account name:\n");
			scanf("%s", &input_str);
			if(strcmp("exit", input_str) == 0) {
				break;
			} else {
				strcat(entire_str, input_str);
			}
		} else {
			strcat(entire_str, argv[2]);
		}
		strcat(entire_str, "', ");
		
		//enter item id
		printf("Item ID:\n");
		scanf("%s", &input_str);
		if(strcmp("exit", input_str) == 0) {
			break;
		} else {
			strcat(entire_str, input_str);
		}
		strcat(entire_str, ", ");
		
		//enter item amount
		printf("Enter item amount:\n");
		scanf("%s", &input_str);
		if(strcmp("exit", input_str) == 0) {
			break;
		} else {
			strcat(entire_str, input_str);
		}
		fprintf(send_items_file, "%s, 1010, 'spawn_items', 200, 1, '', 0, 0, 1);\n", entire_str);
		
		request_id++;
	}
	
	
	//Close the output file
	fclose(send_items_file);
	return 0;
}