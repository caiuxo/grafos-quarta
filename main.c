#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	//file var
    FILE* fp = NULL;
    //read line/get every char
    char buffer[255];
    char* s;
    //number of vertex
	int vertex;
    int i;
	int j;
	//control var
	int ctrl = 0;
	//will receive the converted char*->int
	int qt;
	
	//int array[4][2] = { { 0, 1 }, { 1, 2 }, { 2, 3 }, { 3, 0 } };
	int matrix[100][100];
	int matrixAnswer[100][100];
	
	//reset the matriz
	for(i = 0; i < 100; i++)
		for(j = 0; j < 100; j++)
			matrix[i][j] = 0;
	
	fp = fopen("file.txt", "r");
	i = 0;
	j = 0;
	
	//read every single line from the file
	while(fgets(buffer, 255, (FILE*) fp)) {
	    //printf("BUFFER: %s\n", buffer);
	    
	    //compare to check if its not -1/EOF
	    if(strcmp("-1", buffer) != 0) {
		    j = 0;
	        
	        //get every single char
			for (s = &buffer[0]; *s != '\0'; s++)
		    {
	        	//printf("C: %c\n", *s);
		    	//parse it to int
		        qt = (int) s[0] - '0';
		        
		        //control variable to get the vertex
		        if(ctrl == 0)
				{
		        	vertex = qt;
		        	//printf("VERTEX: %d\n", vertex);
	    			ctrl = 1;
					break;
				}
				else
				{
	        		//printf("QT: %d\n", qt);
					matrix[i][j] = qt;
					j++;
					
					//control the number of connection 
					if(j > 1) 
					{
		    			i++;
						break;
					}
				}
		    }
		}
	}
	
	//close file
	fclose(fp);
	
	//print matriz received
	//for(i = 0; i < vertex; i++) {
	//	for(j = 0; j < 2; j++)
	//		printf("%d ", matrix[i][j]);
	//	
	//	printf("\n");
	//}
	
	//calculate matriz answer
	for(i = 0; i < vertex; i++)
	{
		int x = 0, y = 0;
		
		for(j = 0; j < 2; j++) {
			if(!x)
				x = matrix[i][j];
			else
				y = matrix[i][j];
		}
		
		matrixAnswer[x][y] = 1;
		matrixAnswer[y][x] = 1;
	}
		
	printf("----------Matrix answer----------\n");
	//print answer matriz	
	for(i = 0; i < vertex; i++)
	{
		for(j = 0; j < vertex; j++)
			printf("%d ", matrixAnswer[i][j]);
			
		printf("\n");
	}
	
	printf("\n\n");
	
	//Grau dos vértices
	printf("---------- Biggest/Smallest Vertex----------");
	int degree;
	int biggest = 0;
	int smallest = 0;
	
	for(i = 0; i < vertex; i++)
	{
		degree = 0;
		for(j = 0; j < vertex; j++)
			degree += matrixAnswer[i][j];
		
		if (biggest < degree)
			biggest = degree;
			
		if (i == 0)
			smallest = degree;
		else if (smallest > degree)
			smallest = degree;
		
		printf("\n");
        printf("d(%d) =  %d  ", i, degree);
	}
	
	printf("\n\nBiggest: %d", biggest);
	printf("\nSmallest degree: %d", smallest);
	printf("\nGrafo regular: ");
	
	if(biggest == smallest) {
		printf("SIM");
	}
	else {
		printf("NAO");
	}
	
	printf("\n\n");
	
	system("PAUSE");
	
	return 0;
}
