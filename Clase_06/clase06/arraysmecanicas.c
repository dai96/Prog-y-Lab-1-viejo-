#include <stdio.h>

int main()
{


int vector[5]={5,2,8,6,5};
//char vector [5]={'w','s','r','t','j'};
int i;
int j;
int auxiliar;
for (i=0; i<4; i++)
{
    for (j=i+1;j<5;j++)
    {
        if(vector[i]>vector[j])//criteriode ordenamiento
        {
            auxiliar=vector[i];
            vector [i]=vector[j];
            vector[j]=auxiliar;
        }
    }

}
for (i=0;i<5;i++)
    {
        printf("%c\n",vector[i]);
    }
    return 0;
}
