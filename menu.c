#include "list.h"
#include "sign.h"
#include "menu.h"


void view_author_alfp(LIBRARY *START){ ///SORTING INSIDE
    LIBRARY *sorted = NULL;
    LIBRARY *current = START;
    LIBRARY *next;
    while (current) {
        next = current->next;
        LIBRARY *prev = NULL;
        LIBRARY *temp = sorted;
        while (temp && strcmp(temp->author, current->author) < 0) {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL) {
            current->next = sorted;
            sorted = current;
        } else {
            prev->next = current;
            current->next = temp;
        }
        current = next;
    }
    print_list(sorted);
}

void view_title(LIBRARY *START){ ///DONE
    LIBRARY *sorted = NULL;
    LIBRARY *current = START;
    LIBRARY *next;
    while (current) {
        next = current->next;
        LIBRARY *prev = NULL;
        LIBRARY *temp = sorted;
        while (temp && strcmp(temp->title, current->title) < 0) {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL) {
            current->next = sorted;
            sorted = current;
        } else {
            prev->next = current;
            current->next = temp;
        }
        current = next;
    }
    print_list(sorted);
}

void view_year_increase(LIBRARY *START){///DONE
    LIBRARY *sorted = NULL;
    LIBRARY *current = START;
    LIBRARY *next;
    while (current) {
        next = current->next;
        LIBRARY *prev = NULL;
        LIBRARY *temp = sorted;
        while (temp && temp->date < current->date) {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL) {
            current->next = sorted;
            sorted = current;
        } else {
            prev->next = current;
            current->next = temp;
        }
        current = next;
    }
    print_list(sorted);

}

void view_available(LIBRARY *START){ ///DONE
    LIBRARY *current = START;
    while(current){
        if(available_status(current)){
            print_element(current);
        }
        current = current->next;
    }
}

void edit_add(LIBRARY *START){ ///DONE
        int catalog_nb, date, is_available;
        char author[size], title[size], category[size], publ_house[size];

        printf("Podaj nr katalogowy: ");
        scanf("%d",&catalog_nb);
        while(catalog_nb < 1 || is_available_catalog_nb(START,catalog_nb)){
            system("cls");
            printf("\nPodaj poprawny nr katalogowy: ");
            scanf("%d",&catalog_nb);
        }
        fflush(stdin);

        printf("Podaj autora: ");
            fgets(author,size,stdin); //reading with spaces used scanf
            author[strlen(author)-1] = '\0';
            change_to_floor(author);
            //printf("%s",author);
            fflush(stdin);

        printf("Podaj tytul: ");
            fgets(title,size,stdin);
            title[strlen(title)-1] = '\0';
            change_to_floor(title);
            //printf("%s",title);
            fflush(stdin);

        printf("Podaj kategorie: ");
            fgets(category,255,stdin);
            category[strlen(category)-1] = '\0';
            change_to_floor(category);
            //printf("%s",category);


        printf("Podaj date: ");
        scanf("%d",&date);
        while(date > 2023 || date < 1300){
        printf("Podaj poprawny rok!\n");
        scanf("%d",&date);
        }

        fflush(stdin);
        printf("Podaj wydawnictwo: ");
            fgets(publ_house,255,stdin);
            publ_house[strlen(publ_house)-1] = '\0';
            change_to_floor(publ_house);
            //printf("%s",publ_house);
            fflush(stdin);

        printf("Podaj dostepnosc [1/0]: ");
            scanf("%d",&is_available);
            while(is_available != 1 && is_available != 0){
                printf("Podaj poprawny status dostepnosci! 1 - dostepny 0 - niedostepny! \n");
                scanf("%d",&is_available);
            }

            //printf("%d",is_available);
        add_element(&START,catalog_nb,author,title,category,publ_house,date,is_available);
        print_list(START);
}

void edit_delete(LIBRARY **START){///DONE
    int nr;
    printf("Podaj nr katalogowy elementu ktory chchcesz usunac! :");
    scanf("%d",&nr);
    while((is_available_catalog_nb(*START,nr))==0){
        printf("Nieprawidlowy nr, podaj poprawny numer aby usunac element! ");
        scanf("%d",&nr);
    }
    if(nr == (*START)->catalog_nb){
        LIBRARY *TMP = (*START)->next;
        free((*START));
        (*START) = TMP;
    }
    else{
        LIBRARY *tmp = *START;
        LIBRARY *prev= *START;
        while((tmp)->catalog_nb != nr){
            prev = tmp;
            tmp = tmp->next;
        }
        prev->next = tmp->next;
        free(tmp);
    }
}

void edit_edit(LIBRARY **START){//TODO

}

void search_year(LIBRARY *START){ ///DONE
    int year;
    printf("Podaj rok: ");
    scanf("%d", &year);
    while(START ->next != NULL){
        if(START->date == year){
            print_element(START);
        }
        START = START->next;
    }
}

void search_title(LIBRARY *START){///DONE
    bool x = false;
    //fflush(stdin);
    char title[size];
    printf("Podaj tytul lub fragment tytulu ksiazki: ");
    fgets(title,size,stdin);
    title[strlen(title)-1] = '\0';
    change_to_floor(title);

    int size_of_title = strlen(title);
    LIBRARY *TMP = START;
    while(TMP){
        char copy[size];
        strncpy(copy, TMP->title,size_of_title);
        strlwr(copy);
        strlwr(title);
        if(strcmpi(copy,title) == 0){// || strstr(copy,title)
            print_element(TMP);
        }
        TMP=TMP->next;
    }
    if(!x){
        printf("BRAK ZNALEZIONYCH ELEMENTOW");
    }
}

void search_author(LIBRARY *START){///DONE

    //fflush(stdin);
    char author[size];
    printf("Podaj autora: ");
    fgets(author,size,stdin);
    author[strlen(author)-1] = '\0';
    change_to_floor(author);

    int size_of_author = strlen(author);
    LIBRARY *TMP = START;
    bool x = false;
    while(TMP){
        char copy[size];
        strncpy(copy, TMP->author,size_of_author);
        strlwr(copy);
        strlwr(author);
        if(strcmpi(copy,author) == 0){
            print_element(TMP);
            x = true;
        }
        TMP=TMP->next;
    }
    if(!x){
        printf("BRAK ZNALEZIONYCH ELEMENTOW");
    }

}

void search_available(LIBRARY *START){//TODO??
    char title[size];
    printf("Podaj tytul lub fragment tytulu ksiazki: ");
    fgets(title,size,stdin);
    title[strlen(title)-1] = '\0';
    change_to_floor(title);

    int size_of_title = strlen(title);
    LIBRARY *TMP = START;
    while(TMP){
        char copy[size];
        strncpy(copy, TMP->title,size_of_title);
        //printf(" kopia tytulu zwezona i przed :  %s \n",copy);
        strlwr(copy);
        //printf(" kopia tytulu:  %s \n",copy); //dziala
        strlwr(title);
        //printf(" tytul urzytkownika: %s\n\n\n",title);
        if(strcmpi(copy,title) == 0 && available_status(TMP)){
            print_element(TMP);
        }
        TMP=TMP->next;
    }

}

void wait_for_user_move(){

}
///MENU FUNCTIONS


///MENU FUNCTION - PRINTS
void main_menu_options_print(){//TODO
    printf("     Witaj w bibliotece! Wybierz ponizsze opcje wpisujac numer opcji(1/2/3/0)! \n\n");
    printf("     Opcja ""1"": Przegladanie biblioteki.\n");
    printf("     Opcja ""2"": Szukaj w bibliotece.\n");
    printf("     Opcja ""3"": Dzialania na elementach.\n");
    printf("     Opcja ""0"": Wyjdz z biblioteki. \n\n");
    printf("     Twoja wybrana opcja: ");

}

void view_menu(){ ///DONE
    printf("                  \n");
    printf("     Wybierz ponizsze opcje wpisujac numer opcji(1/2/3/0)! \n\n");
    printf("     Opcja ""1"": Wyswietlanie alfabetyczne wg autorow.\n");
    printf("     Opcja ""2"": Wyswietlanie alfabetyczne wg tytolow.\n");
    printf("     Opcja ""3"": Wyswietlanie malejece wg roku.\n");
    printf("     Opcja ""4"": Elementy dostêpne w bibliotece.\n");
    printf("     Opcja ""0"": Wyjdz z biblioteki. \n\n");
    printf("     Twoja wybrana opcja: ");

}

void search_menu(){ ///DONE
    printf("                  n");
    printf("     Wybierz ponizsze opcje wpisujac numer opcji(1/2/3/0)! \n\n");
    printf("     Opcja ""1"": Szukaj po autorze.\n");
    printf("     Opcja ""2"": Szukaj po tytule.\n");
    printf("     Opcja ""3"": Szukaj po roku.\n");
    printf("     Opcja ""4"": Szukaj dostêpne.\n");
    printf("     Opcja ""0"": Wyjdz z biblioteki. \n\n");
    printf("     Twoja wybrana opcja: ");
}

void edit_menu(){ ///DONE
    printf("                  n");
    printf("     Wybierz ponizsze opcje wpisujac numer opcji(1/2/3/0)! \n\n");
    printf("     Opcja ""1"": Dodaj element.\n");
    printf("     Opcja ""2"": Edytuj element.\n");
    printf("     Opcja ""3"": Usuñ element.\n");
    printf("     Opcja ""0"": Dzialanie na elementach.\n\n");
    printf("     Twoja wybrana opcja: ");
}

void view_menu_print(LIBRARY *START){ ///DONE
    int user_input2;
    while(true){
            ///VIEW MENU
                    system("cls");
                view_sign();
                view_menu();
                scanf("%d",&user_input2);
                while(user_input2 != 1 && user_input2 != 2 && user_input2 != 3 && user_input2 != 4 && user_input2 != 0 ){
                    printf("Podaj poprawna wartosc (1/2/3/4/0): ");
                    scanf("%d",&user_input2);
                }

            ///AUTHOR
            if(user_input2 == 1){
                    system("cls");
                view_author_alfp(START);
                getch();
            }
            ///TITLE
            else if(user_input2 == 2){
                    system("cls");
                view_title(START);
                getch();
            }
            ///YEAT
            else if(user_input2 == 3){
                    system("cls");
                view_year_increase(START);
                getch();

            ///AVAILABLE
            }
             else if(user_input2 == 4){
                    system("cls");
                view_available(START);
                getch();
            }
            ///GO BACK
            else if(user_input2 == 0){
                    system("cls");
                return 0;
            }
    }
}

void search_menu_print(LIBRARY *START){

    int user_input3;
    while(true){
            ///SEARCH MENU
                    system("cls");
                search_sign();
                search_menu();
                scanf("%d",&user_input3);
                while(user_input3 != 1 && user_input3 != 2 && user_input3 != 3 && user_input3 != 4 && user_input3 != 0 ){
                    printf("Podaj poprawna wartosc (1/2/3/4/0): ");
                    scanf("%d",&user_input3);
                }

            ///TITLE
            if(user_input3 == 1){
                    system("cls");
                search_title(START);
                getch();
            }
            ///AUTHOR
            else if(user_input3 == 2){
                    system("cls");
                    fflush(stdin);
                search_author(START);

            }
            ///YEAT
            else if(user_input3 == 3){
                    system("cls");
                search_year(START);
                getch();

            ///AVAILABLE
            }
             else if(user_input3 == 4){
                    system("cls");
                search_available(START);
                getch();
            }
            ///GO BACK
            else if(user_input3 == 0){
                    system("cls");
                return 0;
            }
    }
}

void edit_menu_print(LIBRARY *START){
     int user_input4;
    while(true){
            ///EDIT MENU
                    system("cls");
                edit_sign();
                edit_menu();
                scanf("%d",&user_input4);
                while(user_input4 != 1 && user_input4 != 2 && user_input4 != 3 && user_input4 != 4 && user_input4 != 0 ){
                    printf("Podaj poprawna wartosc (1/2/3/4/0): ");
                    scanf("%d",&user_input4);
                }

            ///ADD
            if(user_input4 == 1){
                    system("cls");
                edit_add(START);
                getch();
            }
            ///EDIT
            else if(user_input4 == 2){
                    system("cls");
                //edit_edit(&START);
                printf("FUNKCJA ZOSTANIE DODANA WKRÓTCE");
                getch();
            }
            ///DELETE
            else if(user_input4 == 3){
                    system("cls");
                edit_delete(&START);
                getch();
            }

            ///GO BACK
            else if(user_input4 == 0){
                    system("cls");
                return 0;
            }
    }
}



