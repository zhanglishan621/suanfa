#include<stdio.h>
#include<stdlib.h>
bool concatenate(int,int,int,int);
int compare(const void *arg1,const void *arg2)
{
	return *(int *)arg2-*(int *)arg1;
}
int sticks[100];
bool used[100];
 
int main()
{
	int n;
	scanf("%d",&n);
	while(n!=0){
		int i,sum=0,len;
		for(i=0;i<n;i++){
			used[i]=false;
			scanf("%d",&sticks[i]);
			sum+=sticks[i];
		}
		qsort(sticks,n,sizeof(int),compare);
		len=sticks[0];
		for(i=len;i<=sum;i++){
			if(sum%i!=0) continue;
			if(concatenate(n,n,0,i)){
				printf("%d\n",i);
				break;
			}
		}
		scanf("%d",&n);
	}
	return 0;
}
 
bool concatenate(int totalSticks,int unusedSticks,int left,int len){
	int i;
	if(unusedSticks==0&&left==0) return true;
	if(left==0) left=len;
	for(i=0;i<totalSticks;i++){
		if(used[i]==true) continue;
		if(sticks[i]>left) continue;
		used[i]=true;
		if(concatenate(totalSticks,unusedSticks-1,left-sticks[i],len)) return true;
		used[i]=false;
		if(sticks[i]==left||left==len) break;
	}
	return false;
}

