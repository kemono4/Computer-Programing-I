#include <stdio.h>

int main()
{	
	int c1 =-1,c2 =-1,c3 =-1,c4 =-1,c5 =-1,flush =0;

	printf("Please enter 5 cards: ");
	scanf("%d %d %d %d %d",&c1,&c2,&c3,&c4,&c5);
	if (c1 <1 ||c1 >52 ||c2 <1 ||c2 >52 
      ||c3 <1 ||c3 >52 ||c4 <1 ||c4 >52 
      ||c5 <1 ||c5 >52 
      ||c1 ==c2 ||c1 ==c3 ||c1 ==c4 ||c1 ==c5
      ||c2 ==c3 ||c2 ==c5 ||c2 ==c4 ||c3 ==c4
      ||c3 ==c5 ||c4 ==c5)
    {
            printf("Error: invalid input\n");
            return 0;
    }
	
    int max=c1;
	if (c2>max)max=c2;
	if (c3>max)max=c3;
	if (c4>max)max=c4;
	if (c5>max)max=c5;
	int min=c1;
	if (c2<min)min=c2;
	if (c3<min)min=c3;
	if (c4<min)min=c4;
	if (c5<min)min=c5;
	if ((max-min<13)&&min%13!=0&&(max%13>min%13||max%13==0))flush=1;
	if (c1+c2+c3+c4+c5-5*min==10&&flush) {printf("Straight Flush\n");return 0;}
//
	int n=0;
	int three=0,two=0;
	if (c1%13==c2%13) n+=1;
	if (c1%13==c3%13) n+=1;
	if (c1%13==c4%13) n+=1;
	if (c1%13==c5%13) n+=1;
	if (n==3) {printf("Four of a kind\n");return 0;}
	if (n==2) three=1;
	if (n==1) two+=1;
	if (n!=3)
	{
		n=0;
		if (c2%13==c1%13) n+=1;
		if (c2%13==c3%13) n+=1;
		if (c2%13==c4%13) n+=1;
		if (c2%13==c5%13) n+=1;
		if (n==3) {printf("Four of a kind\n");return 0;}
		if (n==2) three=1;
		if (n==1) two+=1;
		if (n!=3){
		n=0;
		if (c3%13==c1%13) n+=1;
		if (c3%13==c2%13) n+=1;
		if (c3%13==c4%13) n+=1;
		if (c3%13==c5%13) n+=1;

		if (n==3) {printf("Four of a kind\n");return 0;}
		if (n==2) three=1;
		if (n==1) two+=1;}
	}
//
	n=0;
	if (c4%13==c1%13) n+=1;
	if (c4%13==c2%13) n+=1;
	if (c4%13==c3%13) n+=1;
	if (c4%13==c5%13) n+=1;
	if (n==1)two+=1;
	n=0;
	if (c5%13==c1%13) n+=1;
	if (c5%13==c2%13) n+=1;
	if (c5%13==c4%13) n+=1;
	if (c5%13==c3%13) n+=1;
	if (n==1)two+=1;

	if (three&&two==2){printf("Full House\n");return 0;}
//
	if (flush){printf("Flush\n");return 0;}
//
	c1%=13,c2%=13,c3%=13,c4%=13,c5%=13;
	if (c2<c1){n=c1;c1=c2;c2=n;}
	if (c3<c2){n=c2;c2=c3;c3=n;}
	if (c4<c3){n=c3;c3=c4;c4=n;}
	if (c5<c4){n=c4;c4=c5;c5=n;}
	
	if (c2<c1){n=c1;c1=c2;c2=n;}
	if (c3<c2){n=c2;c2=c3;c3=n;}
	if (c4<c3){n=c3;c3=c4;c4=n;}

	if (c2<c1){n=c1;c1=c2;c2=n;}
	if (c3<c2){n=c2;c2=c3;c3=n;}

	if (c2<c1){n=c1;c1=c2;c2=n;}
	
	if (((c3-c2==1&&c4-c3==1&&c5-c4==1)&&((c2-c1==1) || (c2-c1==9) ))||(c1==0&&c2==9&&c3==10&&c4==11&&c5==12)||(c1==0&&c2==1&&c3==10&&c4==11&&c5==12)){printf("Straight\n");return 0;}
//
	if (three) {printf("Three of a kind\n");return 0;}
	if (two==4){printf("Two pair\n");return 0;}
	else if (two==2){printf("One pair\n");return 0;}
	else printf("High card\n");
	return 0;
}
