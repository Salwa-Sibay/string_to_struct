#include <stdio.h>
#include <string.h>
//supposed to accept values from a user so that they can input their elements from the periodic table

typedef struct{
		int atomNum,
		electronShell[7];

		char name[26],
		chemSymbol[3],
		class[51];

		double atomWeight;

} element_t;

//struct st1 {
//	int a;
//	int b;
//};
//typedef struct st1 ST1;
//
//ST1 v1;
//struct st1 v2;

//declaring my new struct datatype to use later

element_t scan_element(char* inputP, element_t* element);
//https://dyclassroom.com/c/c-function-returning-structure trying to use this as a model to follow
void print_element(char* inputP, element_t* element, element_t periodicTable[121], int length);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){
	setbuf(stdout, NULL);
			//the above line is because using scanf in Windows makes it all funky
		char input[257];
		char* inputP;
		element_t element;
		element_t periodicTable[121];
		int length;
		int howMuch;

		inputP = input;

		printf("How many values do you want to enter? ");
		scanf("%d", &howMuch);

		if (howMuch<121){
			for(int i=0; i<howMuch; i++){
					printf("\nEnter the atomic number: ");
					scanf("%d%*c", &length);

					printf("\nEnter your values separated by a space: ");
					scanf("%[^\n]s%*c", input);
//					scanf("%256s", input);
					//fgets(input, 257, stdin);
					//when using fgets in thus for loop, it messes up how it outputs and screws up the rest of stuff, gonna do scanf instead

					print_element(inputP, &element, periodicTable, length);
			}
		}

		return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

element_t scan_element(char* inputP, element_t* elementP){
//	printf(inputP);
	sscanf(inputP, "%d %26s %3s %51s %lf %d %d %d %d %d %d %d", &elementP->atomNum,
														 	 	  elementP->name, elementP->chemSymbol, elementP->class,
																  &elementP->atomWeight,
																  &elementP->electronShell[0],
																  &elementP->electronShell[1],
																  &elementP->electronShell[2],
																  &elementP->electronShell[3],
																  &elementP->electronShell[4],
																  &elementP->electronShell[5],
																  &elementP->electronShell[6]);
	//printf("%s\n", elementP->name);
	//return (elementP);

}


void print_element(char* inputP, element_t* elementP, element_t periodicTable[121], int length){

	scan_element(inputP, elementP);
	//calling the scan function in hopes that it will save the values entered and send them here.

	periodicTable[length].atomNum = elementP->atomNum;

	strcpy(periodicTable[length].name, elementP->name);
//	printf("%s\n", elementP->name);
//	printf("%s\n", periodicTable[length].name);
	strcpy(periodicTable[length].chemSymbol, elementP->chemSymbol);
	strcpy(periodicTable[length].class, elementP->class);

	periodicTable[length].atomWeight = elementP->atomWeight;

	periodicTable[length].electronShell[0] = elementP->electronShell[0];
	periodicTable[length].electronShell[1] = elementP->electronShell[1];
	periodicTable[length].electronShell[2] = elementP->electronShell[2];
	periodicTable[length].electronShell[3] = elementP->electronShell[3];
	periodicTable[length].electronShell[4] = elementP->electronShell[4];
	periodicTable[length].electronShell[5] = elementP->electronShell[5];
	periodicTable[length].electronShell[6] = elementP->electronShell[6];


	printf("%d %s %s %s %.4f, %d %d %d %d %d %d %d", periodicTable[length].atomNum,
													 periodicTable[length].name,
													 periodicTable[length].chemSymbol,
													 periodicTable[length].class,
													 periodicTable[length].atomWeight,

													 periodicTable[length].electronShell[0],
													 periodicTable[length].electronShell[1],
													 periodicTable[length].electronShell[2],
													 periodicTable[length].electronShell[3],
													 periodicTable[length].electronShell[4],
													 periodicTable[length].electronShell[5],
													 periodicTable[length].electronShell[6]);
//	printing some chonky variables lol
}
