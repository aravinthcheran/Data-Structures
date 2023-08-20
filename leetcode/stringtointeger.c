#include <string.h>
#include <limits.h>

int myAtoi(char *s) {
    long int num = 0;
    int sign = 1;
    int i = 0;
    int flag = 0;
    while (s[i] != '\0') {
        if (s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
            i++;
            flag =1;
        } else if (s[i] == ' ') {
            if(flag==0)
            {
                i++;
            }
            else if(flag==1)
            {
                return num*sign;
            }
        } 
        else if (s[i] == '-') {
            if(flag==0)
            {
                sign *= -1;
                i++;
                flag = 1;
            }
            else
            {
                return num*sign;
            }
        } else if (s[i] == '+') {
            if(flag==0)
            {
                sign = 1;
                i++;
                flag = 1;
            }
            else
            {
                return num*sign;
            }
        } else {
            break;
        }

        if (num * sign > INT_MAX) {
            return INT_MAX;
        } else if (num * sign < INT_MIN) {
            return INT_MIN;
        }
        
    }
    return num * sign;
    
}
