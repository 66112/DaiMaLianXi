#include <stdio.h>
#include <string.h>
int mian()
{
	char password[6] = { 0 };
	char ch[] = { 9, 9, 0, 6, 1, 1 };
	int i;
	for (i = 0; i < 3; i++)
	{
		printf("������6λ����:");
	    scanf("%s", password);
	    if ( strcmp(password , ch)==0)
	        {
	 	       printf("����ɹ�!\n");
		       break;
	         }
	    else
	        {
		        printf("������������ԣ�\n");
	         }
	}
	printf("3�δ������ҹ�̨����лл��\n");
	return 0;
}
