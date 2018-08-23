// Tested with multiplying 0 1 1 0 0 1 0 1 with 1 0 0 1 0 1 0 1
#include<stdio.h>					//Importing Libraries
#include <stdlib.h>

int main(){

int a[8],b[9],c[4];					//Number input
printf("Enter the first Number in binary\n");
for(int i=0;i<8;i++){
	printf("Enter the %dth bit in the first number: ",(i+1));
	scanf("%d",&a[i]);
	}

printf("Enter the Second Number in binary\n");		//Number Input
for(int i=0;i<8;i++){
	printf("Enter the %dth bit in the second number: ",(i+1));
	scanf("%d",&b[i]);
}

b[8]=0;
int r=3;

for(int i=7 ;i>=0;i--){
	if(i == 6 | i ==  4 | i == 2 | i== 0){		//Checking Pairs of 3
	int count =0,check=0;
	check = b[i];					//Calculating the value to as count*m
	if(check==1){					
		if(b[i+1]==0)
			count++;
		if(b[i+2]==0)
			count++;
	count = (-1)*count;
	}
	else{
		if(b[i+1]==1)
			count++;
		if(b[i+2]==1)
			count++;
	}
	
	c[r]=count;					//Making array of 4 bit multiplier
	r--;
	}
}
printf("\n Bit Pair Generated\n");			//Printing Generated pair
for(int i=0;i<4;i++){
	printf("%d ",c[i]);
}


int d[4][8]={(0,0)};

for(int i=3;i>=0;i--){					//Multiplying with the bith pair and storing accordingly
	int e[8];
	for(int j=0;j<8;j++)				//Copying to temporary array e
		e[j]=a[j];
	
	if(c[i]== 2){					// Multipying with 2
	for(int j=0;j<7;j++)
		e[j]=e[j+1];
	
	e[7]=0;	
	
	for(int j=0;j<8;j++)
		d[(3-i)][j]=e[j];
	}
	
	if(c[i]==1){					// Multiplying with 1
	for(int j=0;j<8;j++)
		d[(3-i)][j]=e[j];
	}
	
	if(c[i]==0){					// Multiply with 0
	for(int j=0;j<8;j++)
		d[(3-i)][j]=0;
	}
	
	if(c[i]== -1){					// Multiply with -1
	int trick=0;
		for(int j=7;j>=0;j--){
			if(trick==0){
				if(e[j]==1)
					trick=1;
			}
			else{
				e[j] = abs(e[j]-1);
			}
		}
	for(int j=0;j<8;j++)
		d[(3-i)][j]=e[j];
	}
	
	if(c[i]==-2){					// Multiply with 0
	int trick=0;
		for(int j=7;j>=0;j--){
			if(trick==0){
				if(e[j]==1)
					trick=1;
			}
			else{
				e[j] = abs(e[j]-1);
			}
		}
	for(int j=0;j<7;j++)
		e[j]=e[j+1];
	
	e[7]=0;
	
	for(int j=0;j<8;j++)
		d[(3-i)][j]=e[j];
	}
}
printf("\n\n Intermediary Step\n");			// Printing results after multiplication
for(int i=0;i<4;i++){
	for(int j=0;j<8;j++)
		printf("%d ",d[i][j]);
	printf("\n");
}

int f[4][16]={(0,0)};					// New extended bit array
/*for(int i=0;i<4;i++){
	for(int j=0;j<16;j++)
		printf("%d ",f[i][j]);
	printf("\n");
}*/
for(int i=0;i<4;i++){					// Extending to 16 bit
	for(int j=0;j<8-(2*i);j++)
		f[i][j]=d[i][0];
	for(int j=0;j<8;j++)
		f[i][8-(2*i)+j]=d[i][j];

}
printf("\n Addition Step\n");				// Printing extended 16 bit addition table
for(int i=0;i<4;i++){
	for(int j=0;j<16;j++)
		printf("%d ",f[i][j]);
	printf("\n");
}

int carry=0;
int final[16]={0};

for(int i=15;i>=0;i--){					// Calculating the final array
int sum=0;
	for(int j=0;j<4;j++)
		sum+=f[j][i];
sum+=carry;

final[i] = sum%2;

if((sum - (sum%2))>1){
	carry = (sum - (sum%2))/2;
}
else{
	carry =0;
}

}
printf("\n Final Answer\n");				// Printing the Final Answer

for(int j=0;j<16;j++)
	printf("%d ",final[j]);

printf("\n\n");

return 0;
}
