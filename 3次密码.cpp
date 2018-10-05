#include <stdio.h>
#include <string.h>
int mian()
{
	char password[6] = { 0 };
	char ch[] = { 9, 9, 0, 6, 1, 1 };
	int i;
	for (i = 0; i < 3; i++)
	{
		printf("ÇëÊäÈë6Î»ÃÜÂë:");
	    scanf("%s", password);
	    if ( strcmp(password , ch)==0)
	        {
	 	       printf("ÊäÈë³É¹¦!\n");
		       break;
	         }
	    else
	        {
		        printf("ÃÜÂë´íÎó£¬ÇëÖØÊÔ£¡\n");
	         }
	}
	printf("3´Î´íÎó£¬ÇëÕÒ¹ñÌ¨´¦Àí£¬Ð»Ð»£¡\n");
	return 0;
}
