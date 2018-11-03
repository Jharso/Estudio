#include <stdio.h>

int main()
{
            int x,tabla[100];
           x=1;
            while(x<=100)
            {
        tabla[x]=x;
        x++;
        }
           while(x<=100) 
            {
        printf("%d\n",tabla[x]);
        x++;
    	}
                
    return 0;
}

