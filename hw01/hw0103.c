#include <stdio.h>
#include <stdint.h>

int main()
{
	uint16_t n =0,o1 =0,o2 =0,o3 =0,o4 =0,o5 =0,o6 =0;

	printf("Please enter an unsigned 16-bits number: ");
	scanf("%hd",&n);
	printf("Before Flip:\n");
	printf("%d_10 = ",n);
	
	o1 =n /32768;
	o2 =n %32768/4096;
	o3 =n %4096/512;
	o4 =n %512/64;
	o5 =n %64/8;
	o6 =n %8;

	int z=0;
	if(o1 >0)    {printf("%d",o1);z+=1;}
	if(o2 >0 ||z){printf("%d",o2);z+=1;}
	if(o3 >0 ||z){printf("%d",o3);z+=1;}
	if(o4 >0 ||z){printf("%d",o4);z+=1;}
	if(o5 >0 ||z){printf("%d",o5);z+=1;}
	printf("%d_8\n",o6);z+=1;
	
	printf("After Flip:\n");
	
	if (z >0)  printf("%d",o6);
	if (z >1)  printf("%d",o5);
	if (z >2)  printf("%d",o4);
	if (z >3)  printf("%d",o3);
	if (z >4)  printf("%d",o2);
	if (z >5)  printf("%d",o1);
	if (z ==0) printf("0");
	printf("_8 = ");
	
	if (z>5)      printf("%d_10\n",o1 +o2*8 +o3*64 +o4*512 +o5*4096 +o6*32768);
	else if (z>4) printf("%d_10\n",o2 +o3*8 +o4*64 +o5*512 +o6*4096);
	else if (z>3) printf("%d_10\n",o3 +o4*8 +o5*64 +o6*512);
	else if (z>2) printf("%d_10\n",o4 +o5*8 +o6*64);
	else if (z>1) printf("%d_10\n",o5 +o6*8);
	else if (z>0) printf("%d_10\n",o6);
	else printf("0");

	return 0;
}
