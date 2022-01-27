#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int n,i;
    double *x,*xbar,*y,*ybar,m,c,xmean=0,ymean=0,sumxbar = 0,sumybar = 0;
	
	system("cls");
	
	start:
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    
    if(n<2)
    {
    	printf("\nVery less number of data points \nTry again !\n");
    	goto start;
	}

    x = (double*)malloc(n * sizeof(double));
    xbar = (double*)malloc(n * sizeof(double));
    y = (double*)malloc(n * sizeof(double));
    ybar = (double*)malloc(n * sizeof(double));

    printf("Enter the values of x\n");
    for (i=0;i<n;i++)
    {
        printf("Enter the value of x[%d] : ",i+1);
        scanf("%lf",x+i);
        xmean = xmean + *(x + i)/(double)n;
    }

    printf("\nEnter the value of y\n");
    for (i=0;i<n;i++)
    {
        printf("Enter the value of y[%d] : ",i+1);
        scanf("%lf",y + i);
        ymean = ymean + *(y + i)/(double)n;
    }
	
    for (i=0;i<n;i++)
    {
        *(xbar + i) = *(x + i) - xmean;
        *(ybar + i) = *(y + i) - ymean;

        *(xbar + i) = *(xbar + i) * *(xbar + i);
        *(ybar + i) = *(xbar + i) * *(ybar + i);

	sumybar = sumybar + *(ybar + i);
        sumxbar = sumxbar + *(xbar + i);        
    }
	
    m = sumybar/sumxbar;
    c = ymean - m*xmean;

    printf("\nThe desired linear equation is as follows\n");
    printf(" y = %lf * x + %lf",m,c);

    free(x);
    free(y);
    free(xbar);
    free(ybar);

    getchar();
    return 0;
}
