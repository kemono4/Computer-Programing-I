#include <stdio.h>
#include <stdint.h>

int main()
{
	int32_t a1 =-1,a2 =-1,b1 =-1,sum =-1,x =-1,y =-1,z =-1,j =0;

	printf("Please enter the first  operand: ");
	scanf("%dx%d",&a1,&a2);
	if (a1 >9 ||a1 <0 ||a2 >9 ||a2 <0){
		printf("Error: invalid input!\n");
		return 0;
	}

	printf("Please enter the second operand: ");
	scanf(" y%dz",&b1);
	if (b1 >9 ||b1 <0){
		printf("Error: invalid input!\n");
		return 0;
	}

	printf("Please enter the sum           : ");
	scanf(" %d",&sum);
	if (sum <0){
		printf("Error: invalid input!\n");
		return 0;
	}	

	z =sum %10 -a2;
	if (z <0){
		z +=10;
		j =1;
	}

	x =sum %100 /10 -b1;
	if (j ==1){
		x -=1;
		j =0;
	}
	if (x <0){
		x +=10;
		j =1;
	}

	y =sum /100 -a1;
	if (j ==1) y -=1;

	printf("Ans: x = %d, y = %d, z = %d\n",x,y,z);

	return 0;
}
