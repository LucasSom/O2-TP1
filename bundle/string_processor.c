#include <stdbool.h>
#include <stdio.h>
#include "string_processor.h"

/**  **/

char* string_proc_func_type_string(string_proc_func_type type){
	switch(type){
		case REVERSIBLE: return "reversible";
		case IRREVERSIBLE: return "irreversible";
		default: return "undefined";
	}
}

//TODO: DEBE IMPLEMENTAR
void string_proc_list_print(string_proc_list* list, FILE* file){}

//TODO: DEBE IMPLEMENTAR
void string_proc_list_encode(string_proc_list* list, char* msg, FILE* file){}

//TODO: DEBE IMPLEMENTAR
void string_proc_list_decode(string_proc_list* list, char* msg, FILE* file){}

//TODO: DEBE IMPLEMENTAR
uint32_t string_proc_list_type_amount(string_proc_list* list, string_proc_func_type type){	return -1;}

//TODO: DEBE IMPLEMENTAR
string_proc_list* string_proc_list_filter_by_type(string_proc_list* list, string_proc_func_type type){	return NULL;	}

//TODO: DEBE IMPLEMENTAR
string_proc_list* string_proc_list_invert(string_proc_list* list){	return NULL;}

/** AUX FUNCTIONS **/
//TODO: DEBE IMPLEMENTAR
uint32_t str_len(char* a) { return 0; }

//TODO: DEBE IMPLEMENTAR
char* str_copy(char* a) { return NULL; }

//TODO: DEBE IMPLEMENTAR
int32_t str_cmp(char* a, char* b) { return -1000;}

/** **/
char wrap_around_int(int32_t value){
	if(value < 0){
		while(value < 0)value += 256;
	}else if(value > 255){
		while(value > 255)value -=  256;
	}
	return (char)value;
}

char saturate_int(int32_t value){
	if(value < 0){
		value = 0;
	}else if(value > 255){
		value = 255;
	}
	return (char)value;
}

//TODO: DEBE IMPLEMENTAR
void shift_2(string_proc_key* key){}
//TODO: DEBE IMPLEMENTAR
void unshift_2(string_proc_key* key){}
//TODO: DEBE IMPLEMENTAR
void shift_position(string_proc_key* key){}
//TODO: DEBE IMPLEMENTAR
void unshift_position(string_proc_key* key){}
//TODO: DEBE IMPLEMENTAR
void saturate_2(string_proc_key* key){}
//TODO: DEBE IMPLEMENTAR
void unsaturate_2(string_proc_key* key){}
void saturate_position(string_proc_key* key){}
void unsaturate_position(string_proc_key* key){}
