/* ** *** In the name of God *** ** */
// Only Heydar is Amir al-Momenin
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_FILE_NAME 100
#define MAX_LEN_ORDER 500
#define MAX_LEN_ID_ORDER 10
#define MAX_LEN_TYPE_ORDER 50

// @ali_naserinia

void Welcome(FILE **fpin);
void Show_Menu();
void Get_Orders(FILE *f);
void is_open(FILE *f, char name[]);
int Find_Id_Order(char order[]);
void Find_Order_type(char order[], char type[]);

int main() {

    FILE *fpin, *fpout;

    // fpout = fopen("40131053.txt", "w");

    Welcome(&fpin);
    Show_Menu();
    Get_Orders(fpin);
    



    return 0;
}

void Welcome(FILE **fpin) {
    printf("Dear Mr.zeynali\nI am ali_naserinia\nplease enter input file name: ");
    char inname[MAX_FILE_NAME];
    scanf("%s", inname);
    *fpin = fopen(inname, "r");
    is_open(*fpin, inname);
}

void is_open(FILE *f, char name[]) {
    if (f == NULL) {
        printf("Sorry, Can't open %s\n", name);
        exit(-1);
    }
}

void Get_Orders(FILE *f) {
    char Order[MAX_LEN_ORDER], Order_Type[MAX_LEN_TYPE_ORDER];
    while (fgets(Order, MAX_LEN_ORDER, f) != NULL) {
        int id = Find_Id_Order(Order);
        Find_Order_type(Order, Order_Type);
        printf("%s\n", Order_Type);
        
        sleep(2);
    }
}

int Find_Id_Order(char order[]) {
    char x, res[MAX_LEN_ID_ORDER];
    int i = 0;
    while ((x = order[i]) != '#') {
        res[i] = x;
        i++;
    }
    res[i] = '\0';
    int result = atoi(res);
    return result;
}

void Find_Order_type(char order[], char type[]) { 
    int i = 0, j = 0;
    while (order[i] != '#') i++;
    char x = order[++i];
    while (x != '#' && x != '\n') {
        type[j++] = x;
        x = order[++i];
    }
    type[j] = '\0';
}

void Show_Menu() {
    printf("\n*** ** * WELCOME TO SAMAD WEBSITE * ** ***\n");
    printf("#login\n#register\n\n");
}

void Show_Student_Page() {

}
void Show_Admin_Page() {

}
