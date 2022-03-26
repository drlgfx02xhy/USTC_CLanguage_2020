#include<stdio.h>
#include<math.h>
/*1：define the length and speed
2:run the distance circle by intervals of 0.1m,form 0.0 to 50 and calculate the time
3:output the shortest time(if exchange)*/
int main()
{
    float walk=1.2,swim=0.8;
    float s1,s2,x,tempx,tempy=100.0,y;
    for(x=0.0;x<=50.0;)
    {
    	s1=x;
        s2=sqrt(625.0+(50.0-x)*(50.0-x));/*Firstly I put these 2 lines above out of the circle,*/
	    y=s1/walk+s2/swim;               /*actually at line 10&11.If so,'y'will be defined to an accurate number already.*/
        if(y<=tempy)
        {
    	    tempy=y;
    	    tempx=x;
    	}
        x=x+0.1;
    }
    printf("Pecfect x is:%f,samllest y=%f",tempx,tempy);
}
// Newton 迭代法 和 二分法算法思路也有参考价值    
    
