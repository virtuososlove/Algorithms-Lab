#include<stdio.h>
#include<stdlib.h>
int EnyakinIndexBul(int sayilist[], int ilk, int son) 
{
    int i;
    double ort = 0;
    for (i = ilk; i <= son; i++) 
    {
        ort += sayilist[i];
    }
    ort=ort/(son-ilk+1);
    int yakinElem = ilk;
    for (i= ilk + 1; i<= son; i++) {
        if (abs(sayilist[i] - ort) < abs(sayilist[yakinElem] - ort)) 
        {
            yakinElem = i;
        }
    }
    return yakinElem;
}
int Partition2(int sayilist[],int ilk,int son)
{
	int j,t;
	int x = EnyakinIndexBul(sayilist,ilk,son);
	int pivot = sayilist[x];
    	t = sayilist[x];
    	sayilist[x] = sayilist[son];
    	sayilist[son] = t;
	int ct = ilk - 1;
	for(j= ilk; j< son; j++)
	{
		if(sayilist[j] <= pivot)
		{
			ct = ct + 1;
			t = sayilist[ct];
			sayilist[ct] = sayilist[j];
			sayilist[j] = t; 
		}	
	}
	t = sayilist[ct+1];
	sayilist[ct+1] = sayilist[son];
	sayilist[son] = t; 
	return ct+1;
}
void Quicfonc2(int sayilist[],int ilk, int son)
{
	int q;
	if(ilk < son)
	{
		q = Partition2(sayilist,ilk,son);
		Quicfonc2(sayilist,ilk,q-1);
		Quicfonc2(sayilist,(q+1),son);
	}
}
int Partition(int sayilist[],int ilk,int son)
{
	int j,t;
	int x = sayilist[son];
	int ct = ilk - 1;
	for(j= ilk; j< son; j++)
	{
		if(sayilist[j] <= x)
		{
			ct = ct + 1;
			t = sayilist[ct];
			sayilist[ct] = sayilist[j];
			sayilist[j] = t; 
		}	
	}
	t = sayilist[ct+1];
	sayilist[ct+1] = sayilist[son];
	sayilist[son] = t; 
	return ct+1;
}
void Quicfonc(int sayilist[],int ilk, int son)
{
	int q;
	if(ilk < son)
	{
		q = Partition(sayilist,ilk,son);
		Quicfonc(sayilist,ilk,q-1);
		Quicfonc(sayilist,(q+1),son);
	}
}
void mergefonk2(int sayilist[],int ilk, int q, int son)
{
	int i,j,k;
	int n1 = q-ilk + 1;
	int n2 = son -q;
	int L[n1];
	int R[n2];
	for(i = 0 ; i<n1; i++)
	{
		L[i] = sayilist[ilk + i];
	}
	for(j = 0 ; j<n2; j++)
	{
		R[j] = sayilist[q+j+1];
	}
	i=0;
	j=0;
	for(k = ilk ;i < n1 && j < n2;k++ )
	{
		if(L[i] <= R[j])
		{
			sayilist[k] = L[i];
			i++;
		}
		else
		{
			sayilist[k] = R[j];
			j++;
		}
	}
	for (; i < n1; i++, k++)
	{
        	sayilist[k] = L[i];
   	 }
    	for (; j < n2; j++, k++)
	{
      	  	sayilist[k] = R[j];
    	}
}
void mergefonk1(int sayilist[],int ilk,int son)
{
	int q= 0;
	if( ilk < son)
	{
		q = (ilk + son)/2;
		mergefonk1(sayilist,ilk,q);
		mergefonk1(sayilist,(q+1),son);
		mergefonk2(sayilist,ilk,q,son);
	}
}
int main()
{
	int i,k,n,j;
	scanf("%d %d",&i,&n);
	int sayilist[n];
	for(k = 0; k<n; k++)
	{
		scanf("%d",&sayilist[k]); 
	}
	switch(i)
	{
		case 0:
			mergefonk1(sayilist,0,n-1);
			printf("MergeSort\n");
			for(j=0; j<n;j++)
			{
				if( j == n-1)
				{
					printf("%d",sayilist[j]);
				}
				else
				{
					printf("%d\n",sayilist[j]);
				}
			}
			break;
		case 1:
			Quicfonc(sayilist,0,n-1);
			printf("QuickSort\n");
			for(j=0; j<n;j++)
			{
				if( j == n-1)
				{
					printf("%d",sayilist[j]);
				}
				else
				{
					printf("%d\n",sayilist[j]);
				}
			}
			break;
		case 2:
			Quicfonc2(sayilist,0,n-1);
			printf("QuickSort_M\n");
			for(j=0; j<n;j++)
			{
				if( j == n-1)
				{
					printf("%d",sayilist[j]);
				}
				else
				{
					printf("%d\n",sayilist[j]);
				}
			}
			break;
	}
}
