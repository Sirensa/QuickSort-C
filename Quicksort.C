#include<stdio.h>
#include<stdlib.h>



 void echanger(int *a,int *b){

    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

int partition(int T[],int bas,int haut )
{

    int pivot = T[haut];
    int i = bas - 1;

    for (int j = bas; j < haut; j++)
    {
        if (T[j] <= pivot)
        {
            i++;
            echanger(&T[i], &T[j]);
        }
    }
    echanger(&T[i + 1], &T[haut]);
    return (i + 1);

}
void trirapide( int T[],int bas ,int haut){

    if (bas<haut){

        int pi =partition(T,bas,haut);

        trirapide(T,bas,pi-1);
        trirapide(T,pi+1,haut);

    }


}

void affichage (int T[],int bas,int haut){

    for (int i = bas; i < haut; i++)
    {
       printf("%d ", T[i]);
    }
    printf("\n");
}




int main() {

    int n;
   

    printf ("Entrer la taille de tableau :");
    scanf("%d",&n);

    int *T= (int*) malloc(n*sizeof(int)); 
    if (T==NULL)
    {

    printf ("La memoire n'est pas allouee");
    return 1;

    }
    else
    

    printf ("Entrer les elements :\n");

    for (int i = 0; i <n; i++)
    {

        printf ("L'element %d :",i+1);
        scanf("%d",&T[i]);
    }
  
    trirapide(T,0,n-1);

    printf (" Apres le tri: \n" ) ;
    
    affichage(T,0,n);
    printf("\n");

   
       




  free(T);

  return 0;
}