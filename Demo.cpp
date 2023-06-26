#include<stdio.h>
#include<stdlib.h>

// Functions for performing different operations.

// Funtion to Add the Property Record
void Add_Property_Record();
// Function to View Property Record
void View_Property_Record();
// Function to Search Property Record
void Search_Property_Record();
// Function to Delete Property Record
void Delete_Property_Record();
// Function to buy or sell the Property
void Buy_Sell_Property();

// Storing the values of different datatypes together by making a structure named property.
struct property {
    char property_location[50];
    char property_owner[20];
    int property_price;
    int no_of_BHK;
    float property_size;
};

// Main function
int main()
{
    
    while(1){
        
    printf("\t\t\t=====Real Estate Advisor Management System=====");
    printf("\n\n\n\t\t\t\t     1. Add Property\n");
    printf("\t\t\t\t     2. View Property\n");
    printf("\t\t\t\t     3. Search Property\n");
    printf("\t\t\t\t     4. Delete Property Record\n");
    printf("\t\t\t\t     5. Buy or Sell Property\n");
    printf("\t\t\t\t     6. Exit\n");
    printf("\t\t\t\t    _____________________\n");
    printf("\t\t\t\t     ");
    int choice;
    printf("Enter Your Choice(1-6): "); // Asking user his choice from the above operations.
    scanf("%d",&choice);
    
   switch(choice){
   	 default :
         printf("\n\t\t\t\t\tEnter a valid number\n\n");
         printf("\t\t\t\tPress any key to continue.......");
         break;
         
     case 1:
          Add_Property_Record();
         break;
     case 2: 
        
          View_Property_Record();
          printf("\t\t\t\t  press any key to exit..... \n");
          
         break;
        
     case 3:
         Search_Property_Record();
         printf("\n\t\t\t\t  Press any key to exit.......\n");
         break;
  
     case 4:
        Delete_Property_Record();
        printf("\n\t\t\t\tPress any key to exit.......\n");
        break;
    case 5:
    	Buy_Sell_Property();
    	printf("\n\t\t\t\tPress any key to exit.......\n");
    	break;
     case 6:
          printf("\n\t\t\t\tThank you, for using this software.\n\n");
          exit(0);
          
        break;
        }
  }
        return 0;
     }
    
// Add Property Module
void Add_Property_Record(){
   
     char another;
     FILE *fptr;
     struct property info;
   do{
       printf("\t\t\t\t=======Add Property Info=======\n\n\n"); 
       fptr=fopen("Addrecords.txt","a"); //use can give any file name. Give the name with extention or without extention.
         
          printf("\n\t\t\tEnter Property Location	:	");
          scanf("%s",&info.property_location);
          printf("\n\t\t\tEnter Owner's First Name:	");
          scanf("%s",&info.property_owner);
          printf("\n\t\t\tEnter Property Price	:	$");
          scanf("%d",&info.property_price);
          printf("\n\t\t\tEnter Number of BHK	:	");
          scanf("%d",&info.no_of_BHK);
          printf("\n\t\t\tEnter Property Size In (m/sq)	:   ");
          scanf("%f",&info.property_size);
          printf("\n\t\t\t______________________________\n");
       
      if(fptr==NULL){
        fprintf(stderr,"can't open file");
    }else{
        printf("\t\t\tRecord stored successfully\n");
    }
    
    fprintf(fptr, "%s %s %d %d %f\n", info.property_location, info.property_owner, info.property_price, info.no_of_BHK, info.property_size);
    fclose(fptr);
    printf("\t\t\tYou want to add another record?(y/n) : ");
    scanf("%s",&another);
    }while(another=='y'||another=='Y');
}

// View property module
void View_Property_Record() {
    FILE *fp;
    struct property info;
    fp = fopen("Addrecords.txt", "r");
    printf("\t\t\t\t=======PROPERTY RECORD=======\n\n\n");
    if (fp == NULL) {
        fprintf(stderr, "can't open file\n");
    } else {
        printf("\t\t\t\tRECORDS :\n");
        printf("\t\t\t\t___________\n\n");
        while (fscanf(fp, "%s %s %d %d %f", info.property_location, info.property_owner, &info.property_price, &info.no_of_BHK, &info.property_size) != EOF) {
            printf("\n\t\t\t\t Property Location: %s", info.property_location);
            printf("\n\t\t\t\t Owner Name	: %s", info.property_owner);
            printf("\n\t\t\t\t Property Price	: %d", info.property_price);
            printf("\n\t\t\t\t Number of BHK	: %d", info.no_of_BHK);
            printf("\n\t\t\t\t Property Size in m/sq	: %f", info.property_size);
            printf("\n\t\t\t\t ________________________________\n");
			}
        fclose(fp);
    }

}

// Search property module
void Search_Property_Record() {
    struct property info;
    FILE *fp;
    int property_price, found = 0;

    fp = fopen("Addrecords.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
	printf("\t\t\t\t=======SEARCH PROPERTY RECORD=======\n\n\n");
	printf("\t\t\tEnter the Property Price : ");
    scanf("%d", &property_price);

    while (fscanf(fp, "%s %s %d %d %f", info.property_location, info.property_owner, &info.property_price, &info.no_of_BHK, &info.property_size) != EOF) {
        if (info.property_price == property_price) {
            found = 1;
            printf("\n\t\t\t\t Property Location	: %s", info.property_location);
            printf("\n\t\t\t\t Owner Name	: %s", info.property_owner);
            printf("\n\t\t\t\t Property Price	: %d", info.property_price);
            printf("\n\t\t\t\t Number of BHK	: %d", info.no_of_BHK);
            printf("\n\t\t\t\t Property Size in m/sq	: %f", info.property_size);
            printf("\n\t\t\t\t ________________________________\n");
        }
    }
	if (!found) {
        printf("\n\t\t\tRecord not found\n");
    }
	fclose(fp);
}
// Function For Buying And Selling The Property.
void Buy_Sell_Property() {
    struct property info;
    FILE *fptrr;
    int choice,purchase;
    int no_of_BHK, found = 0;

    printf("\t\t\t\t=======BUY OR SELL PROPERTY=======\n\n\n");
    fptrr = fopen("Addrecords.txt", "r");
    if (fptrr == NULL) {
        printf("Error opening file\n");
        return;
    }
	printf("\t\t\tEnter your choice Buy [1] or Sell [2]: ");
    scanf(" %d", &choice); // added space before %c to ignore leading whitespace
    printf("\t\t\tEnter the Number Of BHK: ");
    scanf("%d", &no_of_BHK);
    if (choice == 1 && no_of_BHK > 0) { // added check for no_of_BHK > 0
        while (fscanf(fptrr, "%s %s %d %d %f", info.property_location, info.property_owner, &info.property_price, &info.no_of_BHK, &info.property_size) != EOF) {
            if (info.no_of_BHK == no_of_BHK) { // moved the check for no_of_BHK inside the while loop
                found = 1;
                printf("\n\t\t\t\t Property Is Available For Sale\n");
                printf("\n");
                printf("\n\t\t\t\t Property Location	: %s", info.property_location);
                printf("\n\t\t\t\t Owner Name	: %s", info.property_owner);
                printf("\n\t\t\t\t Property Price	: %d", info.property_price);
                printf("\n\t\t\t\t Number of BHK	: %d", info.no_of_BHK);
                printf("\n\t\t\t\t Property Size in m/sq	: %f", info.property_size);
                printf("\n\t\t\t\t ________________________________\n");
                }
				}
         printf("\n\t\t\t\t Enter Yes[1] To Finalise This Purchase: ");
         scanf("%d",&purchase);
            if (purchase == 1)
            {
            	printf("\n\t\t\t\t Congratulations! You Owned This Property\n");
			}
			else{
				printf("\n\t\t\t\t Thank You For Checking Out Properties");
			}
			if (!found) {
            printf("\n\t\t\tProperty Not Available For Sale\n");
        }
    } 
    else if(choice ==2 && no_of_BHK>0)
    {
    	while (fscanf(fptrr, "%s %s %d %d %f", info.property_location, info.property_owner, &info.property_price, &info.no_of_BHK, &info.property_size) != EOF) {
            if (info.no_of_BHK == no_of_BHK) { // moved the check for no_of_BHK inside the while loop
                found = 1;
                printf("\n\t\t\t\t Property That You Want To Sell Is: \n");
                printf("\n\n");
                printf("\n\t\t\t\t Property Location	: %s", info.property_location);
                printf("\n\t\t\t\t Owner Name	: %s", info.property_owner);
                printf("\n\t\t\t\t Property Price	: %d", info.property_price);
                printf("\n\t\t\t\t Number of BHK	: %d", info.no_of_BHK);
                printf("\n\t\t\t\t Property Size in (m/sq)	: %f", info.property_size);
                printf("\n\t\t\t\t ________________________________\n");
                }
				}
				printf("\n\t\t\t\t Enter Yes[1] To Finalise This Purchase: ");
         scanf("%d",&purchase);
            if (purchase == 1)
            {
            	printf("\n\t\t\t\t Property Sold Successfully\n");
			}
			else{
				printf("\n\t\t\t\t Thank You For Checking Out Properties");
			}
			if (!found) {
            printf("\n\t\t\tProperty Not Available For Sale\n");
        }
	}
    fclose(fptrr);
}

// Delete property module
void Delete_Property_Record(){
    struct property info;
    FILE *fp, *fp1;
    int property_price, found=0;

    printf("\t\t\t\t=======DELETE PROPERTY RECORD=======\n\n\n");
    fp = fopen("Addrecords.txt", "r");
    fp1 = fopen("Temporary.txt", "w");
    printf("\t\t\t\tEnter the Property Price : ");
    scanf("%d", &property_price);
    if(fp == NULL){
        fprintf(stderr, "can't open file\n");
        return;
    }
    
    while(fscanf(fp, "%s %s %d %d %f", info.property_location, info.property_owner, &info.property_price, &info.no_of_BHK, &info.property_size) != EOF){
        if(info.property_price == property_price){
            found = 1;
        } else{
            fprintf(fp1, "%s %s %d %d %f\n", info.property_location, info.property_owner, info.property_price, info.no_of_BHK, info.property_size);
        }
    }

    fclose(fp);
    fclose(fp1);

    if(!found){
        printf("\n\t\t\t\tRecord not found\n");
    } else{ 
        remove("Addrecords.txt");
        rename("Temporary.txt", "Addrecords.txt"); 
        printf("\n\t\t\t\tRecord deleted successfully\n");
    }
}

