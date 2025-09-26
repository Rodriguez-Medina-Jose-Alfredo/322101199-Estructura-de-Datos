#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/*
   IMPRIMIR LISTA

   MODIFICAR PARA CHAR
*/

static void print_list (const List *list) {
    ListNode *node;
    char *data;
    int i;

    fprintf(stdout, "List size is %d\n", list_size(list));

    i = 0;
    node = list_head(list);

    while (1) {
        data = list_data(node);
        fprintf(stdout, "list.node[%03d]=%s, %p -> %p \n", i, data, node, node->next);

        i++;

        if (list_is_tail(node))
            break;
        else
            node = list_next(node);
    }

   return;
}


 //MAIN

int main (int argc, char **argv) {
    List list;
    ListNode *node;

    char *data;
    int i; //CAMBIAR POR CHAR

    // INICIALIZAR LA LISTA
    list_init(&list, free);

    // LLENA LA LISTA CON MALLOC
    node = list_head(&list);
    for (i = 27; i > 0; i--) {

        if ((data = (char *)malloc(sizeof(char))) == NULL)
            return 1;

        *data = i;

        if (list_ins_next(&list, NULL, data) != 0)
            return 1;
    }

    print_list(&list);

    //CREACION DEL PRIMER NODO

    node = list_head(&list); //list head ESTA EN EL .h

    for (i = 0; i < 7; ++i)
        node = list_next(node);

    data = list_data(node);
    fprintf(stdout, "\nRemoving a node after the one containing %03d\n", *data);

    if (list_rem_next(&list, node, (void**)&data) != 0)
        return 1;

    print_list(&list);

    fprintf(stdout, "\nInserting (z) at the tail of the list\n");
    *data = 'z';
    if (list_ins_next(&list, list_tail(&list), data) != 0)
        return 1;

    print_list(&list);

    fprintf(stdout, "\nRemoving a node after the first node\n");
    if (list_rem_next(&list, list_head(&list), (void**)&data) != 0)
        return 1;
    print_list(&list);

    fprintf(stdout, "\nRemoving a node at the head of the list\n");
    if (list_rem_next(&list, NULL, (void**)&data) != 0)
        return 1;
    print_list(&list);

    fprintf(stdout, "\nInsert (a) at the head of the list\n");
    *data = 'a';
    if (list_ins_next(&list, NULL, data) != 0)
        return 1;
    print_list(&list);

    fprintf(stdout, "\nIterating and removing the fourth node\n");

    node = list_head(&list);
    node = list_next(node);
    node = list_next(node);

    if (list_rem_next(&list, node, (void **)&data) != 0)
        return 1;

    print_list(&list);

    fprintf(stdout, "\nInserting (b) after the first node\n");
    *data = 'b';
    if (list_ins_next(&list, list_head(&list), data) != 0)
        return 1;
    print_list(&list);

   int j;
   char abecedario[23]={'c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y'};
   
   for(i=0;i<=23;i++){
       
       node = list_head(&list);
        node = list_next(node);
        //a y b ya estan agregados
        
       for(j=0;j<=i;j++){
       node = list_next(node);
        }
        
            *data = abecedario[i];
    if (list_ins_next(&list, node, data) != 0)
        return 1;
    print_list(&list);
    
        
   }
   

    i = list_is_head(&list, list_head(&list));
    fprintf(stdout, "\nTesting list_is_head... value=%d (1=OK)\n", i);
    i = list_is_head(&list, list_tail(&list));
    fprintf(stdout, "Testing list_is_head... value=%d (1=OK)\n", i);
    i = list_is_tail(list_tail(&list));
    fprintf(stdout, "Testing list_is_tail... value=%d (1=OK)\n", i);
    i = list_is_tail(list_head(&list));
    fprintf(stdout, "Testing list_is_tail... value=%d (1=OK)\n", i);


    // Destroying the list
    fprintf(stdout, "\nDestroying the list\n");
    list_destroy(&list);

    return 0;
}
