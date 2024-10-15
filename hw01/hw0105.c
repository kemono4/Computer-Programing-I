#include <stdio.h>
#include <stdint.h>
int main()
{
	uint16_t n =0;
	printf("Please input a hex: ");
	if (!scanf("%hX",&n)){printf("Error: invalid input\n");return 0;}
	int32_t t =0;
	printf("Please choose the output type(1:integer,2:unsigned integer,3:float): ");
	scanf(" %d",&t);
	if (t!=1&&t!=2&&t!=3){printf("Error: invalid input\n");return 0;}
	//loop banned
	uint32_t b =65536;
	printf("%d",n%b/(b/2));b/=2;
	printf("%d",n%b/(b/2));b/=2;
	printf("%d",n%b/(b/2));b/=2;
	printf("%d ",n%b/(b/2));b/=2;
	printf("%d",n%b/(b/2));b/=2;
	printf("%d",n%b/(b/2));b/=2;
	printf("%d",n%b/(b/2));b/=2;
	printf("%d ",n%b/(b/2));b/=2;
	printf("%d",n%b/(b/2));b/=2;
	printf("%d",n%b/(b/2));b/=2;
	printf("%d",n%b/(b/2));b/=2;	
	printf("%d ",n%b/(b/2));b/=2;
	printf("%d",n%b/(b/2));b/=2;
	printf("%d",n%b/(b/2));b/=2;
	printf("%d",n%b/(b/2));b/=2;
	printf("%d\n",n%b/(b/2));b/=2;

	if(t==1){printf("Converted integer is: %hd\n",n);return 0;}
	if(t==2){printf("Converted unsigned integer is: %hu\n",n);return 0;}
	if(t==3){
		int8_t u =1;
		if(n/32768) u=-1;

		int32_t exp =n%32768/16384*16+n%16384/8192*8+n%8192/4096*4+n%4096/2048*2+n%2048/1024-15;
		//special cases
		printf("Converted float is: ");
		if(n==0){printf("+0.0\n");return 0;}
		else if(n==32768){printf("-0.0\n");return 0;}
		else if(n==31744){printf("+inf\n");return 0;}
		else if(n==64512){printf("-inf\n");return 0;}
		else if((n>31744&&n<32768)||n>64512){printf("NaN\n");return 0;}

		double f = 1+n%1024/512*0.5+n%512/256*0.25+n%256/128*0.125+n%128/64*0.0625+n%64/32*0.03125+n%32/16*0.015625+n%16/8*0.0078125+n%8/4*0.00390625+n%4/2*0.001953125+n%2*0.0009765625;
		printf("%lf*2^%d\n",f*u,exp);
		return 0;
	}	
}
