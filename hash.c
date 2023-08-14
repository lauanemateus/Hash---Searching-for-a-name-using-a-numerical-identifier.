#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define maxn 100001
#define maxword 30

char c, s[100];
int hash[maxn], mat[maxn], qtd[maxn],i,j,ind[maxn];
char nomes[maxn][maxword], num[10];

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int main(){					
	FILE *arq;

	i=1;
	arq = fopen("HashDados.txt", "r");
	if(arq == NULL){
		printf("Erro na leitura do arquivo\n");
		return 0;
	}
	while(fgets(s, 100, arq) != NULL){
		int k=0,j=0;
		while(s[j]!=';'){
			num[k++]=s[j];
			j++;
		}
		j++;
		num[k] = '\0';
		mat[i] = atoi(num);
		qtd[mat[i]%maxn]++;
		k=0;
		while(s[j]!='\0' && s[j]!='\n'){
			nomes[i][k++] = s[j];
			j++;
		}
		i++;
	}
	fclose(arq);

	for (i = 2; i < maxn; ++i)
	{
		qtd[i]+=qtd[i-1];
        	ind[i] = qtd[i-1];
	}
	for (i = 1; i < maxn; ++i){
		hash[ind[mat[i]%maxn]++] = i;
	}
	int n,y;
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &y);

		for (j = qtd[y%maxn - 1]; j <= qtd[y%maxn]-1; ++j)
		{
			if(mat[hash[j]]==y){
				printf("%s\n", nomes[hash[j]]);
				break;
			}
		}
	}
	return 0;
}
