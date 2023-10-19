#include <stdio.h>
int isAccepted(char str[]) 
{
    int currentState = 0;
    int i = 0;
    while (str[i] != '\0') 
	{
        if (currentState == 0 && str[i] == 'a') 
		{
            currentState = 1;
        } 
		else 
		{
            currentState = -1;
        }
        i++;
    }
    return currentState == 1;
}
int main() 
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    if (isAccepted(str)) 
	{
        printf("String accepted\n");
    } 
	else 
	{
        printf("String not accepted\n");
    }
    return 0;
}

