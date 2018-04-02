; FUNCIONES de C
	extern malloc
	extern free
	extern fopen
	extern fclose
	extern fprintf

; /** defines bool y puntero **/
	%define NULL 0
	%define TRUE 1
	%define FALSE 0


section .data


section .text

global string_proc_list_create
string_proc_list_create:
	ret

global string_proc_node_create
string_proc_node_create:
	ret

global string_proc_key_create
string_proc_key_create:
	ret

global string_proc_list_destroy
string_proc_list_destroy:
	ret

global string_proc_node_destroy
string_proc_node_destroy:
	ret

global string_proc_key_destroy
string_proc_key_destroy:
	ret

global string_proc_list_add_node
string_proc_list_add_node:
	ret

global string_proc_list_apply
string_proc_list_apply:
	ret
