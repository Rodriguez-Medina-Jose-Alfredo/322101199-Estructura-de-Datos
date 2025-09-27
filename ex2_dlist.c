#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dlist.h"

/*
   Print List
*/

static void print_list (const DList *list) {
    DListNode *node;
    int *data, i;

    fprintf(stdout, "DList size is %d\n", dlist_size(list));

    i = 0;
    node = dlist_head(list);

    while (1) {
        data = dlist_data(node);
        fprintf(stdout, "dlist.node[%03d]=%03d, %14p <- %p -> %p \n", i, *data, node->prev, node, node->next);

        i++;

        if (dlist_is_tail(node))
            break;
        else
            node = dlist_next(node);
    }

   return;
}


int main (int argc, char **argv) {
    DList list;
    DListNode *node;

    int *data, i;

	char *num = argv[1];

    // Initialize the linked list
    dlist_init(&list, free);

    // Fill the linked list
    node = dlist_head(&list);
    for (i = strlen(argv[1]); i > 0; i--) {

        if ((data = (int *)malloc(sizeof(int) * strlen(argv[1]))) == NULL)
            return 1;

        *data = i;

        if (dlist_ins_prev(&list, dlist_head(&list), data) != 0)
            return 1;
    }	
    
    
    
        node = dlist_head(&list);    
        
        for (i = 0; i < 7; ++i)
        node = dlist_next(node);    
        data = dlist_data(node);
        
        digit = ((int) num[i]);
        
        dlist_data(node)= digit;
    

    fprintf(stdout, "\nRemoving a node after the one containing %03d\n", *data);

    if (dlist_remove(&list, node, (void**)&data) != 0)
        return 1;

    print_list(&list);        
    
    node = dlist_head(&list);
    *data=argv[0];
    
  
    for(i=0;i<= argc;i++){
         
          node = dlist_head(&list);
          
         for(j=0;j<= argc; i++){
    node = dlist_next(node);
    node = dlist_prev(node);
            }
        
            *data=argv[i];
        
    }
    fprintf(stdout, "arg[1] = %s \n", argv[1]);
	
	for(i = 0; i < strlen(argv[1]); i++){
	    print_list(&list);
		fprintf(stdout, "num[%d] = %c \n", i, num[i]);
	}


    

    i = dlist_is_head(dlist_head(&list));
    fprintf(stdout, "\nTesting list_is_head... value=%d (1=OK)\n", i);
    i = dlist_is_head(dlist_tail(&list));
    fprintf(stdout, "Testing list_is_head... value=%d (1=OK)\n", i);
    i = dlist_is_tail(dlist_tail(&list));
    fprintf(stdout, "Testing list_is_tail... value=%d (1=OK)\n", i);
    i = dlist_is_tail(dlist_head(&list));
    fprintf(stdout, "Testing list_is_tail... value=%d (1=OK)\n", i);
    

    // Destroying the list
    fprintf(stdout, "\nDestroying the list\n");
    dlist_destroy(&list);

    return 0;
}
