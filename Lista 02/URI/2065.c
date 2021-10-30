#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	int i, n, m;
	
	
	scanf("%d", &n);
	int a[n];
	scanf("%d", &m);
	int b[m];
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for(i = 0; i < m; i++)
		scanf("%d", &b[i]);
	
		
	int temp[n];
	int t =0;
	while(t < m) 
	{
		if(t < n)
		{
			temp[t] = b[t] * a[t];

			t++;
		}
		else
		{
			int index = temp[0];
			int z = 0;
			for(i = 0; i < n; i++)
				if(index > temp[i])
				{
					index = temp[i];
					z = i;
				}
			temp[z] += b[t] * a[z];
		
			z = 0;
			t++;
		}


	}
	int index = temp[0];

	for(i = 0; i < n; i++)
		if(index < temp[i])
			index = temp[i];
		printf("%d\n", index);
}
