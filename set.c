#ifndef _disjSet_H
#define _disjSet_H
 
typedef int* disjSet;
 
void initial(disjSet S,int size);
void setUnion(disjSet S,int root1,int root2);
int find(disjSet S,int i);
 
#endif

void initial(disjSet S,int size){
	if(size < 10)
	  size=20;
	int i;
	
	for(i=1;i<=size;i++) 
	  S[i]=0;
	
}
 
void setUnion(disjSet S,int root1,int root2){
	
	if(S[root1]>0 || S[root2]>0){
		printf("some is not root");
		exit(1);
	}
	if(S[root2]<S[root1])
	  S[root1]=root2;
	else {
		if(S[root2]==S[root1])
		  S[root1]--;
		S[root2]=root1;
	}
	  	  
}
 
int find(disjSet S,int i){
	
	if(S[i]<=0)
	  return i;
	else return S[i]=find(S,S[i]);
}

