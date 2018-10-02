//header files
#include<stdio.h>
#include<conio.h>          //getch()
#include<windows.h>          //sleeep()
#include<string.h>          //strcmp()

//list of function prototype
void Password(void);  //for password
void mainmenu(void);  //for main menu
void searchproduct(void);  //for search product
void addproduct(void);  //for add product
void sellproduct(void);  //for sell product
void stockproduct(void);  //for stock product
void closeapplication(void);  //for close program

FILE *fp_pass, *fp_pro, *fp_temp;  //list of files

struct product //structure for product
{
    int pieces;
    int code[3];
    char name[10];
    double price;
};
struct product a;

int main()
{
    Password();

    return 0;
}

void Password(void)  //for password option
{
    system("cls");
    int j;
    char d[25] = " Password Protected";

    printf("\n\n\n\n\t");
    for(j = 0; j < 20; j++){
        printf("*");
        Sleep(20);
    }
    for(j = 0; j < 20; j++){
        printf("%c", d[j]);
        Sleep(200);
    }
    for(j = 0; j < 20; j++){
        printf("*");
        Sleep(20);
    }

    int i= 0, z = 0, count = 0;
    int len;
	char pass[10];

    fp_pass = fopen("PASS.txt","r");

    fscanf(fp_pass, " %[^\n]", pass);

	len = strlen(pass);

    printf("\n\n Enter Password: ");

    char passs[10];

    for(i = 0; i < len; i++){
    	passs[i] = getch();
    	printf("*");
	}
    for(i = 0; i < len; i++){
    	if(passs[i]==pass[z]){
    		count++;
		}
		z++;
	}
	if(count==len){
        system("cls");
        system("color A");
        printf("\n\n Password match");
        printf("\n\n\n Press any key to continue.....");

        getch();
        mainmenu();
	}
	else{  //for new password set
        system("color 4");
        printf("\n\n \a Warning!! Incorrect Password");
        printf("\n\n Forget Password?(Y/N)");

        if(getch()=='y'){

            char temp[10];

            fp_pass = fopen("PASS.txt","w");

            system("cls");
            system ("color 5");
            printf("\n\n Enter new password: ");
            scanf(" %[^\n]", temp);

            system("cls");
            system("color A");
            printf("\n\n Password is successfully saved \n\n");

            fprintf(fp_pass,"%s\n", temp);
        }
        else{
            system("color 7");
            Password();
        }
	}

    fclose(fp_pass);
}

void mainmenu(void)  //for menu function
{
    system("cls");
    system("color F");
    printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Agora Supper Shop");
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\t\t\xB2 1. Search product\n");
    printf("\t\t\xB2 2. Add product \n");
    printf("\t\t\xB2 3. Sell product \n");
    printf("\t\t\xB2 4. Stock product \n");
    printf("\t\t\xB2 5. Close Application \n");
    printf("\t\t-----------------------------------------------");
    printf("\n\n Enter your choice: ");

    switch (getch())
    {
        case '1':{
            searchproduct();
            break;
        }
        case '2':{
            addproduct();
            break;
        }
        case '3':{
            sellproduct();
            break;
        }
        case '4':{
            stockproduct();
            break;
        }
        case '5':{
            system("cls");
            system ("color 3");
            printf("\n\n Exiting in few second ");
            int i;
            for(i = 0; i < 10; i++){
                printf(".");
                Sleep(200);
            }
            system("cls");
            exit(0);
        }
        default:{
            system("color 5");
            printf("\n\n \a Wrong Entry!! Please re-entered correct option");

            if(getch()){
                mainmenu();
            }
        }
    }
}

void searchproduct()  //function that search product
{
    system("cls");
    system("color F");
    printf("\n\n\n\n\t************************** Search Product **************************");

    printf("\n\n 1. Search By Product Code");
    printf("\n\n 2. Search By Product Name");
    printf("\n\n Enter Your Choice");

    switch(getch())
    {
        case '1':{
            int c[3];
            int count = 0;

            system("cls");
            printf("\n\n\n **** Search Product By Code ****");

            printf("\n\n Enter the product Code: ");
            scanf("%s", &c);

            system("cls");
            printf("\n\n\n Searching");
            int i;
            for(i = 0; i < 5; i++){
                printf(".");
                Sleep(200);
            }
            system("cls");

            fp_pro = fopen("product.txt", "r");

            while(fscanf(fp_pro, "%d %s %s %lf", &a.pieces, &a.code, &a.name, &a.price)!= EOF){
                if(strcmp(a.code,(c))==0){  //checks whether a.code is equal to c or not
                    printf("\n\n The Product is available");
                    printf("\n\n  Total Pieces/kg: %d", a.pieces);
                    printf("\n\n  Code: %s", a.code);
                    printf("\n\n  Name: %s", a.name);
                    printf("\n\n  Price: %0.2lfTK.", a.price);

                    count++;

                    fclose(fp_pro);
                }
            }
            if(count == 0){
                system("cls");
                system("color 5");
                printf("\n\n \a No Product Found!");
            }
            printf("\n\n Try another search?(Y/N)");
            if(getch()=='y'){
                searchproduct();
            }
            else{
                mainmenu();
                break;
            }
        }
        case '2':{
            char n[10];
            int count = 0;

            system("cls");
            printf("\n\n\n **** Search Product By Name ****");

            printf("\n\n Enter Product Name: ");
            scanf("%s", n);

            system("cls");
            printf("\n\n\n Searching");
            int i;
            for(i = 0; i < 5; i++){
                printf(".");
                Sleep(200);
            }
            system("cls");

            fp_pro = fopen("product.txt", "r");

            while(fscanf(fp_pro, "%d %s %s %lf", &a.pieces, &a.code, &a.name, &a.price)!= EOF){
                if(strcmp(a.name,(n))==0){  //checks whether a.name is equal to n or not
                    printf("\n\n The Product is available");
                    printf("\n\n  Total Pieces/kg: %d", a.pieces);
                    printf("\n\n  Code: %s", a.code);
                    printf("\n\n  Name: %s", a.name);
                    printf("\n\n  Price: %0.2lfTK.", a.price);

                    count++;

                    fclose(fp_pro);
                }
            }
            if(count == 0){
                system("cls");
                system("color 5");
                printf("\n\n \a No Product Found!");
            }
            printf("\n\n Try another search?(Y/N)");
            if(getch()=='y'){
                searchproduct();
            }
            else{
                mainmenu();
                break;
            }
        }
        default:{
            system("color 5");
            printf("\n\n \a Wrong Entry!! Please re-entered correct option");

            if(getch()){
                searchproduct();
            }
        }
    }
}

void addproduct(void)  //function that add product
{
    int i;

    system("cls");
    system("color F");
    printf("\n\n SELECT CATEGOIES");
    printf("\n  1. Cosmetic");
    printf("\n  2. Confectionary");
    printf("\n  3. Oil");
    printf("\n  4. Rice");
    printf("\n  5. Fish");
    printf("\n  6. Flesh");
    printf("\n  7. Vegetable");
    printf("\n  8. Spice");
    printf("\n  9. Back to main menu");

    printf("\n\n Enter your choice:");
    scanf("%d", &i);

    if(i == 9){
        mainmenu();
    }

    int c[3];
    int p, s;
    double pr;

    printf("\n\n Add Previous Item or Add New Item?(P/N):");

    if(getch()=='p'){
        printf("\n\n Enter Product Code: ");
        scanf("%s", &c);

        fp_pro = fopen("product.txt", "r");
        fp_temp = fopen("temp.txt", "w");

        while(fscanf(fp_pro, "%d %s %s %lf", &a.pieces, &a.code, &a.name, &a.price)!= EOF){
            if(strcmp(a.code,(c))==0){  //checks whether a.code is equal to c or not
                printf("\n\n\n Product Name: %s", a.name);
                printf("\n\n\n Previous Pieces/kg: %d", a.pieces);
                printf("\n\n Enter Current Pieces/kg: ");
                scanf("%d", &p);
                printf("\n\n\n Previous Price: %0.2lfTK.", a.price);
                printf("\n\n Enter Current Price: ");
                scanf("%lf", &pr);

                s = a.pieces + p;

                fprintf(fp_temp, "%d %s %s %0.2lf\n", s, a.code, a.name, pr);

                printf("\n\n\n Product is successfully saved");
            }
            else{
                fprintf(fp_temp, "%d %s %s %0.2lf\n", a.pieces, a.code, a.name, a.price);
            }
        }

        fclose(fp_temp);
        fclose(fp_pro);

        fp_temp = fopen("temp.txt", "r");
        fp_pro = fopen("product.txt", "w");

        while(fscanf(fp_temp, "%d %s %s %lf", &a.pieces, &a.code, &a.name, &a.price)!= EOF){
            fprintf(fp_pro, "%d %s %s %0.2lf\n", a.pieces, a.code, a.name, a.price);
        }

        fclose(fp_temp);
        fclose(fp_pro);

    }
    else{
        int count = 0;

        printf("\n\n Enter Product Code: ");
        scanf("%s", &c);

        fp_pro = fopen("product.txt", "r");
        while(fscanf(fp_pro, "%d %s %s %lf", &a.pieces, &a.code, &a.name, &a.price)!= EOF){
            if(strcmp(a.code,(c))==0){  //checks whether a.code is equal to c or not
            system ("color B");
            printf("\n\n\n \a Product code already used! Please try a new product code.");

            count++;

            fclose(fp_pro);
            }
        }

        if(count == 0){
            fp_pro = fopen("product.txt", "a");

            printf("\n\n Enter Product Pieces/kg: ");
            scanf("%d", &a.pieces);
            printf("\n\n Enter Product Name: ");
            scanf("%s", &a.name);
            printf("\n\n Enter Product Price: ");
            scanf("%lf", &a.price);

            fprintf(fp_pro, "%d %s %s %0.2lf\n", a.pieces, c, a.name, a.price);

            fclose(fp_pro);

            printf("\n\n\n Product is successfully saved");
        }

    }

    printf("\n\n\n Save any more?(Y/N):");
    if(getch()=='y'){
        addproduct();
    }
    else{
        mainmenu();
    }
}

void sellproduct(void)  //function that sell product
{
    int t, i, p, c[3];
    int t_p;
    double total = 0, total_p = 0;

    system("cls");
    system("color F");
    printf("\n\n Enter total type of item: ");
    scanf("%d", &t);

    for (i = 0; i < t; i++){
        printf("\n\n Enter product code: ");
        scanf("%s", &c);

        fp_pro = fopen("product.txt", "r");

        while(fscanf(fp_pro, "%d %s %s %lf", &a.pieces, &a.code, &a.name, &a.price)!= EOF){
                if(strcmp(a.code,(c))==0){  //checks whether a.code is equal to c or not
                    printf("\n\n Enter total pieces/kg: ");
                    scanf("%d", &p);

                    total = p * a.price;

                    t_p = a.pieces - p;

                    printf("\n\n\t%s\t\t\t\t\t   %0.2lf/=", a.name, total);

                    fclose(fp_pro);

                    total_p = total_p + total;
                }
        }

        fp_pro = fopen("product.txt", "r");
        fp_temp = fopen("temp.txt", "w");

        while(fscanf(fp_pro, "%d %s %s %lf", &a.pieces, &a.code, &a.name, &a.price)!= EOF){
            if(strcmp(a.code,(c))==0){  //checks whether a.code is equal to c or not
                fprintf(fp_temp, "%d %s %s %0.2lf\n", t_p, a.code, a.name, a.price);
            }
            else{
                fprintf(fp_temp, "%d %s %s %0.2lf\n", a.pieces, a.code, a.name, a.price);
            }
        }

        fclose(fp_pro);
        fclose(fp_temp);

        fp_temp = fopen("temp.txt", "r");
        fp_pro = fopen("product.txt", "w");

        while(fscanf(fp_temp, "%d %s %s %lf", &a.pieces, &a.code, &a.name, &a.price)!= EOF){
                fprintf(fp_pro, "%d %s %s %0.2lf\n", a.pieces, a.code, a.name, a.price);
        }

        fclose(fp_temp);
        fclose(fp_pro);

    }
    printf("\n\t=============================================================");
    printf("\n\tTotal \t\t\t\t\t = %0.2lf Taka\n", total_p);

    if(total_p = 0){
        printf("\n\n Product code not in record");
    }

    printf("\n\n\n Any more item sell?(Y/N)");
    if(getch()=='y'){
        sellproduct();
    }
    else{
        mainmenu();
    }
}

void stockproduct(void)  //show the list of stock product
{
    int count = 0;

    system("cls");
    system ("color 2");
    printf("\n\t********************* Stock Product List ********************");

    printf("\n\n Pieces\t\tProduct Code\t\tProduct Name\t\tProduct Price");

    fp_pro = fopen("product.txt", "r");

    while(fscanf(fp_pro, "%d %s %s %lf", &a.pieces, &a.code, &a.name, &a.price)!= EOF){
        printf("\n\n %d\t\t%s\t\t\t%s\t\t\t%0.2lf/=", a.pieces, a.code, a.name, a.price);

        count++;
    }

    fclose(fp_pro);

    printf("\n\n\n Total type of item in stock: %d", count);
    printf("\n\n\n Save any more item?(Y/N)");
    if(getch()=='y'){
        addproduct();
    }
    else{
        mainmenu();
    }
}


//End of program


