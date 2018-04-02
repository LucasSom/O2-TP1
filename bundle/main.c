#include "string_processor.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

/**
*	crea y destruye a una lista vacía
*/
extern string_proc_list* string_proc_list_create (char*);
extern void string_proc_list_destroy(string_proc_list*);

void test_create_destroy_list(){
	string_proc_list* lista = string_proc_list_create("listaNueva");
	string_proc_list_destroy(lista);
}

/**
*	crea y destruye un nodo
*	para esta función es conveniente haber implementado al menos un par de funciones
*	(por ej. shift_2, unshift_2)
*/
void test_create_destroy_node(){
}

/**
*	crea y destruye una clave 
*/
void test_create_destroy_key(){
}

/**
*	crea una lista y la imprime por salida standard (stdout)		
*/
void test_print_list(){
}

/**
*	crea una lista con un solo nodo con  f:shift_2, g:unshift_2, type:reversible
*	y prueba encode y decode por separado sobre "hola mundo" imprimiendo
*	el string procesado (aplicando encode primero y luego decode a través de string_proc_list_apply) 
* 	e imprima ambos strings por salida estandard seguido de un '\n'
*/
void test_shift_2(){
	printf("Probando shift_2, unshift_2\n============\n");
}

/**
*	crea una lista con un solo nodo con  f:shift_position, g:unshift_position, type:reversible
*	y prueba encode y decode por separado sobre "hola mundo" imprimiendo
*	el string procesado (aplicando encode primero y luego decode) e imprima ambos strings por salida estandard seguido de un '\n'
*/
void test_shift_position(){
	printf("Probando shift_positon, unshift_position\n============\n");
}

/**
*	crea una lista con un solo nodo con  f:saturate_2, g:unsaturate_2, type:irreversible
*	y prueba encode y decode por separado sobre "hola mundo" imprimiendo
*	el string procesado (aplicando encode primero y luego decode) e imprima ambos strings por salida estandard seguido de un '\n'
*/
void test_saturate_2(){
	printf("Probando saturate_2, unsaturate_2\n============\n");
}

/**
*	crea una lista con un solo nodo con f:saturate_position, g:unsaturate_position, type:irreversible
*	y prueba encode y decode por separado sobre "hola mundo" imprimiendo
*	el string procesado (aplicando encode primero y luego decode) e imprima ambos strings por salida estandard seguido de un '\n'
*/
void test_saturate_position(){
	printf("Probando saturate_position, unsaturate_position\n============\n");
}

/**
*	crea una lista con dos nodos 
*		- el primero con f:shif_2, g:unshift_2, type:reversible
*		- el primero con f:shif_position, g:unshift_position, type:reversible
*	y prueba encode y decode por separado sobre "hola mundo!" imprimiendo
*	el string procesado (aplicando encode primero y luego decode) e imprima ambos strings por salida estandard seguido de un '\n'
*	Consiga la copia que invierte las funciones de la lista y pruebe ésta con el string 
*	"hemos ido demasiado lejos y se acerca la hora de detenernos a reflexionar" imprimiendo
*	el string procesado (aplicando encode primero y luego decode) e imprima ambos strings por salida estandard seguido de un '\n'
*/
void test_combo_reversible(){
	printf("Probando combo reversible\n============\n");

	printf("Probando combo irreversible invertido\n============\n");
}

/**
*	crea una lista con dos nodos 
*		- el primero con f:shif_2, g:unshift_2, type:reversible
*		- el primero con f:saturate_position, g:saturate_position, type:irreversible
*	y prueba encode y decode por separado sobre "hola mundo!" imprimiendo
*	el string procesado (aplicando encode primero y luego decode) e imprima ambos strings por salida estandard seguido de un '\n'
*	Consiga la copia que invierte las funciones de la lista y pruebe ésta con el string 
*	"hemos ido demasiado lejos y se acerca la hora de detenernos a reflexionar" imprimiendo
*	el string procesado (aplicando encode primero y luego decode) e imprima ambos strings por salida estandard seguido de un '\n'
*	Consiga la copia que filtra la primer lista dejando sólo los nodos reversibles
*	y pruebe ésta con el string "mother forgive me" imprimiendo
*	el string procesado (aplicando encode primero y luego decode) e imprima ambos strings por salida estandard seguido de un '\n'
*/
void test_combo_irreversible(){
	printf("Probando combo irreversible\n============\n");

	printf("Probando combo irreversible invertido\n============\n");

	printf("Probando combo filtrado\n============\n");

}

/**
* Corre los test a se escritos por lxs alumnxs	
*/
void run_tests(){

	test_create_destroy_list();

	test_create_destroy_node();

	test_create_destroy_key();

	test_print_list();

	test_shift_2();
	
	test_shift_position();

	test_saturate_2();

	test_saturate_position();

	test_combo_reversible();

	test_combo_irreversible();
}

int main (void){
	run_tests();
	return 0;    
}
