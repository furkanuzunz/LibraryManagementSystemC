#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int number_books = 0;


struct book_info
{
    char name[75];
    char writer[75];
    int ISBN;
};
struct book_info kutuphane[100];
struct book_info book_update;

void add_books(struct book_info *kutuphane, int *Number_books)
{
    if (*Number_books < 100)
    {
        printf("enter book name that you want to add\n");
        getchar();
        // fgets(kutuphane[numbers_book].name, sizeof(kutuphane[numbers_book].name), stdin);
        // ÖNCE FGETS İ DENEDİM AMA YAZDIGIM SEYDEN SONRA 2 KERE ENTER BASMAM GEREKİYORDU.
        gets(kutuphane[*Number_books].name); // https://www.geeksforgeeks.org/scanfns-str-vs-getsstr-in-c-with-examples/
        printf("enter man's name that who writer on your book\n");
        // fgets(kutuphane[numbers_book].writer, sizeof(kutuphane[numbers_book].writer), stdin);
        gets(kutuphane[*Number_books].writer);
        printf("enter ISBN your book that you want to add\n");
        scanf("%d", &kutuphane[*Number_books].ISBN);

        (*Number_books)++;
        printf("now we will show you informations that you just have entered book information\n");

        printf("book name : %s\n", kutuphane[*Number_books - 1].name); // index olarak diziler sıfırdan baslar
        printf("book writer : %s\n", kutuphane[*Number_books - 1].writer);
        printf("book ISBN : %d\n", kutuphane[*Number_books - 1].ISBN);

        printf("Thanks your book adding.");
    }
    else
    {
        printf("you reach the max_books number,we can't add your book informations sorry about that miieeenn :( ");
    }

    FILE *fileBooks;

    fileBooks = fopen("libraryLists.txt", "a");
    fprintf(fileBooks, "%s,%s,%d\n", kutuphane[*Number_books - 1].name, kutuphane[*Number_books - 1].writer, kutuphane[*Number_books - 1].ISBN);
    fclose(fileBooks);

    
}

void list_books(int *Number_books)
{
    printf("\nBooks informations in library\n\n");

    int i;

    if (*Number_books > 0)
    {
        for (i = 0; i < *Number_books; i++)
        {
            printf("******%d.book information******\n", i + 1);
            printf("\n");
            printf("%d.book name: %s\n", i + 1, kutuphane[i].name);
            printf("%d.book writer: %s\n", i + 1, kutuphane[i].writer);
            printf("%d.book ISBN: %d\n", i + 1, kutuphane[i].ISBN);
        }
    }
    else
        printf("kutuphanede kayitli kitap yoktur");
}

void update_books(int *number_books)
{
    int ISBNupdate;
    char update_name[75];
    char update_writer[75];
    int i;
    printf("Enter ISBN number that you want to update book's informations");
    scanf("%d", &ISBNupdate);
    for (i = 0; i < *number_books; i++)
    {
        if (kutuphane[i].ISBN == ISBNupdate)
        {
            int update_index = i;
            printf("write your book's name again");
            scanf("%s",update_name);
            printf("write your book's writer again");
            scanf("%s",update_writer);

            strcpy(kutuphane[update_index].name, update_name);
            strcpy(kutuphane[update_index].writer, update_writer);

            break;
        }
    }
    FILE *fileBooks;
        fileBooks = fopen("libraryLists.txt", "w");
        for (i = 0; i < *number_books; i++)
        {
            fprintf(fileBooks, "%s,%s,%d\n", kutuphane[i].name, kutuphane[i].writer, kutuphane[i].ISBN);
        }
        fclose(fileBooks);
}

void delete_books(int *number_books)
{
    https://www.geeksforgeeks.org/delete-element-from-array-of-structs-in-c/ I learned this subject from here
    int ISBNdelete;
    char delete_name[75];
    char delete_writer[75];
    int i;
    int delete_index;
    printf("Enter ISBN number that you want to delete book's informations");
    scanf("%d", &ISBNdelete);
    for (i = 0; i < *number_books; i++)
    {
        if (kutuphane[i].ISBN == ISBNdelete)
        {
            delete_index = i;
            break;
        }
    }
    if (delete_index == -1)
    {
        printf("not match found try again");
    }
    else
    {

        kutuphane[i] = kutuphane[i + 1]; // burda amac indexini buldugumuz seyi kaydırmak alta.Yani noldu simdi onun yerine bi sonrak geldi ve kaydı sıra düzgün bir sekilde.
    }
    *number_books--;
    FILE *fileBooks;
        fileBooks = fopen("libraryLists.txt", "w");
        for (i = 0; i < *number_books; i++)
        {

            fprintf(fileBooks, "%s,%s,%d\n", kutuphane[i].name, kutuphane[i].writer, kutuphane[i].ISBN);
            
        }

        fclose(fileBooks);
}

void listbooks_file()
{
    FILE *fileBooks;

    fileBooks = fopen("libraryLists.txt", "r");
        printf("Books informations in library from file\n");
    char reading[100];
    while (fgets(reading, sizeof(reading), fileBooks) != 0)
    {    
           printf("%s",reading);
            printf("\n\n");
            
    }
    
    if(fgets(reading, sizeof(reading), fileBooks) == 0)
    {
        printf("\n\nthere aren't any books here");
    }
    

    https://www.geeksforgeeks.org/basics-file-handling-c/ 
}



void menu_library(int *number_books)
{
    printf("welcome to the library\n\n");
    int i, secenek;

    while (secenek != 6)
    {
        printf("\npress 1 to add book\n");
        printf("press 2 to list book\n");
        printf("press 3 to update book informations\n");
        printf("press 4 to delete book from library\n");
        printf("press 5 to list books from file\n");
        printf("press 6 to quit from library\n\n");
        scanf("%d", &secenek);

        switch (secenek)
        {
        case 1:
            add_books(kutuphane, number_books);
            break;

        case 2:
            list_books(number_books);
            break;

        case 3:
            update_books(number_books);
            break;

        case 4:
            delete_books(number_books);
            break;
        case 5:
          listbooks_file();
            break;

        case 6:
            printf("cikis yaptiniz");
            break;
        }
    }
}


int main()
{

    FILE *fileBooks;

    // add_books(kutuphane, &number_books); // ya da &kutuphane[0] ile adresi gönder.
     /*list_books(&number_books);
     update_books(&number_books);
    delete_books(&number_books);*/
    menu_library(&number_books);
    return 0;
}
