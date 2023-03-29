#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liste.h"
#include <ctype.h>
#include <stdbool.h>

const relation Table[] = 
{
    {'\0',-1},
    {'0',0},
    {'1',1},
    {'2',2},
    {'3',3},
    {'4',4},
    {'5',5},
    {'6',6},
    {'7',7},
    {'8',8},
    {'9',9},
    {'A',10},
    {'B',11},
    {'C',12},
    {'D',13},
    {'E',14},
    {'F',15}
};

/*Fonction qui permet de vider le buffer*/

void freeBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

    /*Fonction qui vérifie que la base soit bien un number entre 2 et 16
    fonctionne par adressage pour modifier la valeur de la base*/

void check_base(int *base){

     while ( !(isdigit(*base)) && ((*base < 2) || (*base > 16)) ){

         printf("\nVeuillez rentrer une base ");
         freeBuffer();
         scanf("%i",base);
     }

}


void check_number(char *number, int base){

    int i=0;
    int taille_table=base+1;
    bool test=true;
    /*printf("La base vaut %d",base);*/

        while((i<strlen(number))&&(test)){

            test=false;
            /*printf("\nTEST POUR %c, i vaut %d",number[i],i);*/

            for(int j=0; j<taille_table; j++){

                /*printf("\n j vaut %d et Table[%d].c vaut %c",j,j,Table[j].c);*/

                if(number[i]==Table[j].c){

                    /*printf("\n%c est valide",number[i]);*/
                    test=true;
                }
            }


            if (!test){
                
                printf("\nle number n'est pas valide\nVeuillez rentrer un number valide. En fonction de la base %d: ",base);
                fgets (number, NB, stdin);
                number[strcspn(number, "\n" )] = '\0';
                check_number(number, base);
            }else{

                i++;

            }

        }
}


void free_LT(ListTable LT){

    if (LT!=NULL){

        if(LT->next==NULL){

            free(LT);

        }else{

        free_LT(LT->next);

        free(LT);
        }


    }

}

ListTable insert_head_T(ListTable LT, char table[NB]){

    ListTable newelT=NULL;
    newelT = (Element *)malloc(sizeof(Element));

    newelT->next=LT;
    strcpy(newelT->number,table);

    return newelT;
}

void show_LT(ListTable LT){
    
    printf("\n");

    while (LT != NULL){
        printf("%s\n",LT->number);
        LT=LT->next;

    }

}

ListTable insert_tail_T(ListTable LT, char table[NB]){


    if (LT==NULL){

        LT=insert_head_T(LT,table);
        return LT;
    }
    else{

        ListTable newelT=NULL;
        newelT = (Element *)malloc(sizeof(Element));

        newelT->next=NULL;
        strcpy(newelT->number,table);


        ListTable temp=LT;
        
        while(temp->next!=NULL){
                temp=temp->next;
        }
        temp->next=newelT;
        return LT;
    }
}

ListTable addzero(ListTable LT){
   
    if (LT!=NULL){  
        char tmp[NB]="";
        ListTable T=LT;

        while(T!=NULL){
            strcpy(tmp,"");

            for (int i = 0; i < (NB-(strlen(T->number)+1)); ++i){
                strcat(tmp,"0");
            }

            strcat(tmp,T->number);
            strcpy(T->number,tmp);

            T=T->next;
        }
    
        return LT;
    }else{
        return NULL;
    }

}

ListBucket create_Bucket(int nb_Buckets){

    ListBucket Bucket=NULL;
    Bucket=(ListTable *)malloc(sizeof(ListTable)*nb_Buckets);

        for (int k= 0; k < nb_Buckets; k++){
             Bucket[k] = NULL;
          }

    return Bucket;
    
}


void free_Bucket(ListBucket Bucket, int nb_Buckets){

     for(int a=0; a<nb_Buckets; a++){
        free_LT(Bucket[a]);
    }
    
    free(Bucket);
}


ListTable sort_Bucket(ListTable LT, int base, int position, ListBucket Bucket){        

    ListTable temp =LT;

    while(temp!=NULL){

        for(int j=0; j<base; j++){
                
            if(temp->number[position-1]==Table[j+1].c){

                Bucket[j]=insert_tail_T(Bucket[j],temp->number);
    
            }
        }


        temp=temp->next;
    }

    free_LT(LT);
        

    return (recup(Bucket,base) );

}



ListTable recup(ListBucket Bucket, int base){

    ListTable LT=NULL;
    ListTable temp=NULL;

    if(Bucket!=NULL){

        for (int i=0; i<base;i++){
            temp=Bucket[i];
            while(temp!=NULL){

                LT=insert_tail_T(LT,temp->number);
                temp=temp->next;
            }
        }

    }

    return LT;
}

ListTable sort(ListTable LT, int base, int position){


    for(int i=NB-1; i>0;i--){

        ListBucket Bucket = create_Bucket(base);
        LT=sort_Bucket(LT, base,i,Bucket);
        free_Bucket(Bucket,base);
        show_LT(LT);
       
    }

return LT;

}

