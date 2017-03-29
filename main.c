#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int vertex = 0;
    FILE* fp = NULL;
	char buffer[255];
	int len;
	int result = 0;
    char* s;
    int i = 0;
	int j = 0;
	int ctrl = 0;
	
	//int array[4][2] = { { 0, 1 }, { 1, 2 }, { 2, 3 }, { 3, 0 } };
	int array[100][100];
	
	for(i = 0; i < 100; i++)
		for(j = 0; j < 100; j++)
			array[i][j] = 0;
	
	fp = fopen("file.txt", "r");
	int arrayAnswer[vertex][vertex];
	
	while(fgets(buffer, 255, (FILE*) fp) && ctrl <= vertex) {
	    printf("BUFFER: %s\n", buffer);
        for (s = &buffer[0]; *s != '\0'; s++)
	    {
	    	j = 0;
	    	printf("Ctrl: %d\n", ctrl);
	        printf("C: %c\n", *s);
	        int qt = atoi(s);
	        
	        if(ctrl == 0)
			{
	        	vertex = qt;
	        	printf("VERTEX: %d\n", vertex);
				break;
			}
			else
			{
				array[ctrl-1][j] = qt;
				j++;
			}
	    }
	    ctrl++;
		//printf("RESULT: %d", result);
	}
	
	fclose(fp);
	
	for(i = 0; i < vertex; i++) {
		for(j = 0; j < vertex; j++)
			prift(array[i][j]);
		
		printf("\n");
	}
	
	system("PAUSE");
	
	return 0;
}
