//
//  main.c
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    int z=5;
    struct node a,b,*head ;
    a.value = z;
    a.next=&b;
    head=&a;
    b.value=head->value+3;

/*  Exercise I
    1. Add 1 more than at the end
    2. Add value(11)
    3. Make next become NULL
 */
    struct node c;
    c.value = 11;
    c.next = NULL;
    b.next = &c;

    
/*  Exercise II
        1. Add 1 more than at the begining!!!!
        2. Add value (2)
*/
    struct node d;
    d.next = &a;
    d.value = 2;
    head = &d;
    printf("%d\n", head ->value );
    printf("%d\n", head ->next->value );
    printf("%d\n", head ->next->next->value );
    printf("%d\n", head ->next->next->next->value );
    typedef struct node* NodePtr;
    NodePtr tmp=head; //add temp value to faciliate
        
    //Exercise III Use loop to print everything
    printf("[for loop]\n");
        int i,n=4;
        for(i=0;i<n;i++){
            printf("%-4d", tmp->value);
            tmp=tmp->next;
        }
        tmp=head;
        printf("\n");
    
   //  Exercise IV change to while loop!! (you can use NULL to help)
    printf("[while loop]\n");
         while(tmp!=NULL){
            printf("%-4d", tmp->value);
            tmp=tmp->next;
        }
        printf("\n");
    
 /*  Exercise V Use malloc to create all nodes, instead of create a struct!!
         //use a loop to help
          
     */
     printf("[Malloc]\n");
     head=(struct node*)malloc(sizeof(struct node));
     tmp = head;
     tmp -> value=2;
     tmp -> next=(struct node*)malloc(sizeof(struct node));

    tmp=tmp->next;
    tmp->value=5;
    tmp->next=(struct node*)malloc(sizeof(struct node));

    tmp=tmp->next;
    tmp->value=8;

    head=(NodePtr)malloc(sizeof(struct node));
    tmp=head;

    for(i=2;i<=11;i+=3){
        tmp->value=i;
        if(i==11)tmp->next=NULL;
        else{
            tmp->next=(NodePtr)malloc(sizeof(struct node));
            }
    tmp=tmp->next;
    }
    tmp=head;
    while(tmp){
        printf("%-4d",tmp->value);
        tmp=tmp->next;
    }
    printf("\n");
    

    /*  Exercise VI Free all node !!
         //use a loop to help
          
     */
     printf("[Free]\n");
     while(head!=NULL){
        tmp=head;
        head=head->next;
        printf("%-4d",tmp->value);
        free(tmp);
     }
    return 0;
}
