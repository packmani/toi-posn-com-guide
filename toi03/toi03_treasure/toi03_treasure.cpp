//toi3_treasure
//brute force
#include <stdio.h>
#include <math.h>
#include <string.h>
#define SQ sqrt(2);
double x, y, sum;
char s[10], dir[2];
int d, i, t;
signed main(){
	while(1){
		scanf("%s", s);    
		if(s[0] == '*') break;
		for(sum = d = 0, i = strlen(s)-(t = 1); ~i; --i){ //process from back
			if('0' <= s[i] && s[i] <= '9') sum = sum + t * (s[i]-'0'), t *= 10;	
			else dir[d++] = s[i];
		}
		if(d == 2){
			if(dir[1] == 'N' && dir[0] == 'E'){ y += sum/SQ; x += sum/SQ;}
			else if(dir[1] == 'N' && dir[0] == 'W'){ y += sum/SQ; x -= sum/SQ;}
			else if(dir[1] == 'S' && dir[0] == 'E'){ y -= sum/SQ; x += sum/SQ;}
			else if(dir[1] == 'S' && dir[0] == 'W'){ y -= sum/SQ; x -= sum/SQ;}
		}else{
			if(dir[0] == 'N') y += sum;
			else if(dir[0] == 'S') y -= sum;
			else if(dir[0] == 'E') x += sum;
			else if(dir[0] == 'W') x -= sum;
		}
	}
	printf("%.3lf %.3lf\n%.3lf", x, y, sqrt(x*x + y*y));
}
