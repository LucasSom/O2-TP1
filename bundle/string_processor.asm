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

; /** defines cosas de la lista **/
	%define tamano_lista 24
	%define offset_name 0
	%define offset_first 8
	%define offset_last 16
	
; /** defines cosas de los nodos **/
	%define tamano_nodo 33
	%define offset_next 0
	%define offset_prev 8
	%define offset_f 16
	%define offset_g 24
	%define offset_type 32
	
section .data


section .text

global string_proc_list_create
string_proc_list_create:
	;RDI = *char name
	;el tamano de la lista es:
	;TO CHECK
	;	*char + *nodo + *nodo = 8 + 8 + 8 = 24
	
	push rbp
	mov rbp, rsp
	push rdi		;porque aca va a estar el tamano de lo que voy a pedir con malloc
	mov rdi, tamano_lista
	call malloc		;en RAX esta el ptr a la nueva lista
	pop rdi			;vuelvo a tener el *char name
	;MOVER esta linea a la antepenultima
	
	mov [rax+offset_name], rdi		;guardo en (el lugar donde esta la nueva lista) el nombre
	
	;CONSULTAR chanchada: con "mov [] NULL" se moria todo (como vimos en clase)
	;como lo soluciono sin tener que hacer esta asquerosidad?
	;opcion mas usable generalmente?: push rdi - xor rdi,rdi -...- pop rdi 
	xor rdi, rdi					;pongo rdi=0 porque ya no lo voy a usar y sino despues se queja
	mov	[rax+offset_first], rdi		;guardo en (...) el ptr al first, ie, a null
	mov	[rax+offset_last], rdi		;idem con el ptr a last
	pop rbp
	ret

global string_proc_node_create
string_proc_node_create:
	;INCOMPLETO: preguntar EN QUE LUGAR DE LA LISTA PONE EL NODO?
	;*nodo + *nodo + *funcion + *funcion + TYPE = 8 + 8 + 8 + 8 + 1 = 33
	;rdi=f, rsi=g, rdx=type
	
	push rbp		;corremos la pila
	mov rbp, rsp
	push rdi		;en rdi vamos a guardar el tamano del nodo
	mov rdi, tamano_nodo
	call malloc		;en rax esta el ptr a la memoria que me dio malloc
	pop rdi			;en rdi vuelve a estar f
	;mov [rax+offset_next], 
	;mov [rax+offset_prev], EN QUE LUGAR DE LA LISTA PONE EL NODO?
	mov [rax+offset_f], rdi
	mov [rax+offset_g], rsi
	mov [rax+offset_type], rdx
	
	pop rbp
	ret

global string_proc_key_create
string_proc_key_create:
	ret

global string_proc_list_destroy
string_proc_list_destroy:
	;RDI = *lista
	
	;en RDI ya esta el ptr a lo que quiero liberar
	call free				;borra *name
	
lista_no_vacia:
	cmp [rdi+offset_first], NULL	;OJO: mal el NULL. Mismo problema de siempre
	JNE lista_vacia
	push rdi
	mov rdi, rdi+offset_first
	;LLAMAR A 
	string_proc_node_destroy
	;consultar como llamr a funcion de asm
	JMP lista_no_vacia
lista_vacia:
	pop rdi
	add rdi, offset_first
	call free				;borra *first
	add rdi, 8				;porque 8 = offset_last - offset_first
	call free				;borra *last
	
	ret

global string_proc_node_destroy
string_proc_node_destroy:
	;RDI = ptr al nodo a destruir
	push rbp		;corremos la pila
	mov rbp, rsp
	cmp [rdi+offset_prev], NULL		;si el nodo es el primero de la lista
	JNE es_ultimo					;sigue aca. Sino, que salte a ver si es el ultimo
	;CONSULTAR: COMO HAGO PARA ACCEDER A LA LISTA?
	
	;OJO con el caso si es el unico
	
es_ultimo:
	cmp [rdi+offset_next], NULL	;OJO: mal el NULL. Mismo problema de siempre
	JNE es_intermedio
	;IDEM antes
	
es_intermedio:
	;nodo 1 == [prev]
	;ptr nodo 1 (=next(anterior)) == [prev+offset_next]
	;next == rdi+offset_prev
	push rax
	mov rax, [rdi+offset_prev] 
	mov [rax+offset_next], [rdi+offset_next]
	;CONSULTAR chanchada: esto esta mal. como hago para ponerlo bien?
	
	;IDEM con ptr nodo 2 := prev
	;//////////////////////////////
	;-------COMPLETAR paso 2-------
	;//////////////////////////////
	
	;paso 3
	mov rax, rdi
	;en RDI esta lo que quiero liberar con free
	mov rdi, rax+offset_next
	call free
	;paso 4
	mov rdi, rax+offset_prev
	call free
	;paso 5
	mov rdi, rax+offset_f
	call free
	;paso 6
	mov rdi, rax+offset_g
	call free
	;paso 7
	mov rdi, rax+offset_type
	call free
	
	pop rax
	pop rbp	
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
