#include "list.h"
#include "sign.h"
#include "menu.h"


void add_element(LIBRARY **first_el,int cat,char aut[size],char tit[size], char cate[size], char publ_h[size], int date, int is_av){

    LIBRARY *new_element = malloc(sizeof(LIBRARY));
    LIBRARY *pomocnicza;

    new_element->catalog_nb = cat;
    strcpy(new_element->author,aut);
    strcpy(new_element->title,tit);
    strcpy(new_element->category,cate);
    new_element->date = date;
    strcpy(new_element->publ_house,publ_h);
    new_element->is_available = is_av;
    new_element->next = NULL;

    if(*first_el == NULL){
       *first_el = new_element;
    }
    else
    {
        pomocnicza = *first_el;
        while(pomocnicza->next!=NULL){
            pomocnicza=pomocnicza->next;
        }
        pomocnicza->next = new_element;
    }
    return 0;
}

void save_in(LIBRARY **START){// QUESTIONABLE

}

void change_to_floor(char* character){ ///DONE
    int size_char = strlen(character);
    for(int i=0; i<size_char; i++){
        if((character[i]) == ' '){
            (character[i]) = '_';
        }
    }
}

void change_to_space(char* character){ ///DONE
    int size_char = strlen(character);
    for(int i=0; i<size_char; i++){
        if((character[i]) == '_'){
            (character[i]) = ' ';
        }
    }
}

void print_list(LIBRARY *f){ ///DONE
    LIBRARY *p;
    p=f;
   while(p!=NULL){
        printf("nr: %d,\n autor: %s,\n tytul: %s,\n kategoria: %s,\n wydawnictwo: %s,\n data: %d,\n dostepnosc: %d;\n\n",
               p->catalog_nb, p->author, p->title, p->category, p->publ_house, p->date, p->is_available);
        p=p->next;
    }
    return 0;
}

void print_element(LIBRARY *START){ ///DONE
    LIBRARY *p = START;
    printf("nr: %d,\n autor: %s,\n tytul: %s,\n kategoria: %s,\n wydawnictwo: %s,\n data: %d,\n dostepnosc: %d;\n\n\n",
               p->catalog_nb, p->author, p->title, p->category, p->publ_house, p->date, p->is_available);

}

void read_file(LIBRARY *START, char *file_name){ ///DONE
    //printf("%s",file_name);
    bool red = false;
    int cat, date, is_av;
    char aut[size], tit[size], cate[size], publ_h[size];

    FILE *file_o = fopen(file_name, "r");
    if(file_o == NULL){
        printf("Brak odczytu pliku! \n");
        return 1;
    }
    while(red != true){
        if(fscanf(file_o,"%d %s %s %s %s %d %d\n",&cat, aut, tit, cate, publ_h, &date, &is_av)==7){
          add_element(START, cat, aut, tit, cate, publ_h, date, is_av);
        }
        else{
            red = true;
        }
    }
    fclose(file_o);
    return 0;
}

void write_file(LIBRARY *START, char *file_name){ ///DONE Jan KOwalski
    FILE *file_o = fopen(file_name, "w");
    if(file_o == NULL){
        printf("Brak odczytu pliku! \n");
        return;
    }

    LIBRARY *current = START;
    while(current != NULL) {
        fprintf(file_o,"%d %s %s %s %s %d %d\n", current->catalog_nb, current->author, current->title, current->category, current->publ_house, current->date, current->is_available);
        current = current->next;
    }

    fclose(file_o);
}

bool available_status(LIBRARY *START){ ///DONE
    if(START->is_available){
        return true;
    }
    else{
        return false;
    }
}

bool is_empty(LIBRARY *START){///DONE
    if(START){
        return false;
    }
    else{
        return true;
    }
}

bool is_alone(LIBRARY *START){///DONE
    if(START->next){
        return false;
    }
    else{
        return true;
    }
}

int amount_of_elements(LIBRARY *START){ ///DONE
    int amount;
    LIBRARY *TMP = START;
    while(TMP){
        if(TMP->next){
            amount++;
        }
        TMP = TMP->next;
    }
    return amount;
}

bool is_available_catalog_nb(LIBRARY *START,int nb){ ///DONE
    while(START){
        if(START->catalog_nb == nb){
            return true;
        }
        else{
            START = START->next;
        }
    }
    return false;
}

void insertion_sort(LIBRARY *START){ ///NOT NECESSARY BETA FOR TITLE
    LIBRARY *sorted = NULL;
    LIBRARY *current = START;
    LIBRARY *next;
    while (current != NULL) {
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

void clearr(LIBRARY **START){
    LIBRARY *tmp = *START;
    while(*START){
        tmp = (*START);
        *START = (*START)->next;
        free(tmp);
    }
}

void edit_element(LIBRARY **START){
    edit_sign();



    int user_input5;
    while(true){
            ///EDIT MENU


                int user_input6;
                printf("     Podaj numer katalogowy elementu ktory chcesz edytowac: ");
                scanf("%d",&user_input6);

                while(!is_available_catalog_nb(*START,user_input6)){
                    printf("     Podaj poprawny numer katalogowy elementu ktory chcesz edytowac: ");
                    scanf("%d",&user_input6);
                }
                LIBRARY *copy = *START;
                while(copy){
                    if(copy->catalog_nb == user_input6){
                          break;
                    }else{
                        copy = copy->next;
                    }
                }
                int catalog_nb, date, is_available;
                char author[size], title[size], category[size], publ_house[size];

                printf("     Wybierz ponizsze opcje wpisujac numer opcji(1/2/3/4/5/6/7/0)! \n\n");
                printf("     Opcja ""1"": Numer katalogowy.\n");
                printf("     Opcja ""2"": Autor.\n");
                printf("     Opcja ""3"": Tytul.\n");
                printf("     Opcja ""4"": Kategoria. \n");
                printf("     Opcja ""5"": Data.\n");
                printf("     Opcja ""6"": Wydawnictwo.\n");
                printf("     Opcja ""7"": Dostepnosc.\n");
                printf("     Opcja ""0"": Tytul.\n\n");
                printf("     Twoja wybrana opcja: ");


                ///USER CHOICE
                printf("     Podaj ktory z elementow chcesz edytowac ");
                scanf("%d",&user_input5);
                while(user_input5 != 1 && user_input5 != 2 && user_input5 != 3 && user_input5 != 4 && user_input5 != 5 && user_input5 != 6 && user_input5 != 7 && user_input5 != 0 ){
                    printf("Podaj poprawna wartosc (1/2/3/4/5/6/7/0): ");
                    scanf("%d",&user_input5);
                }

                ///CATALOG NB
                if(user_input5 == 1){
                    system("cls");
                    printf("Podaj nowy nr katalogowy: ");
                    scanf("%d",&catalog_nb);
                    while(catalog_nb < 1 || is_available_catalog_nb(START,catalog_nb)){
                        system("cls");
                        printf("\nPodaj poprawny nr katalogowy: ");
                        scanf("%d",&catalog_nb);
                    }
                    copy->catalog_nb = catalog_nb;
                }

                ///AUTHOR
                else if(user_input5 == 2){
                    system("cls");
                    printf("Podaj nowego autora: ");
                    fgets(author,size,stdin);
                    author[strlen(author)-1] = '\0';
                    change_to_floor(author);
                    strcpy(copy->author,author);
                }


                ///TITLE
                else if(user_input5 == 3){
                        system("cls");
                    printf("Podaj tytul: ");
                    fgets(title,size,stdin);
                    title[strlen(title)-1] = '\0';
                    change_to_floor(title);
                    //printf("%s",title);
                    strcpy(copy->title,title);
                    fflush(stdin);
                     getch();
                }
                 ///CATEGORY
                else if(user_input5 == 4){
                        system("cls");
                    printf("Podaj kategorie: ");
                    fgets(category,255,stdin);
                    category[strlen(category)-1] = '\0';
                    change_to_floor(category);
                    //printf("%s",category);
                    strcpy(copy->category,category);
                    getch();

                }
                ///DATE

                 else if(user_input5 == 5){
                        system("cls");
                        printf("Podaj nowa date: ");
                        scanf("%d",&date);
                        while(date > 2023 || date < 1300){
                        printf("Podaj poprawny rok!\n");
                        scanf("%d",&date);
                        }
                        copy->date = date;
                        getch();
                }

                ///PUBLISHING HOUSE

                 else if(user_input5 == 6){
                        system("cls");
                        fflush(stdin);
                        printf("Podaj wydawnictwo: ");
                        fgets(publ_house,255,stdin);
                        publ_house[strlen(publ_house)-1] = '\0';
                        change_to_floor(publ_house);
                            //printf("%s",publ_house);
                        strcpy(copy->publ_house,publ_house);
                        fflush(stdin);
                        getch();

                }

                ///AVAIABLE STATUS

                 else if(user_input5 == 7){
                        system("cls");
                        printf("Podaj dostepnosc [1/0]: ");
                        scanf("%d",&is_available);
                        while(is_available != 1 && is_available != 0){
                            printf("Podaj poprawny status dostepnosci! 1 - dostepny 0 - niedostepny! \n");
                            scanf("%d",&is_available);
                        }
                        getch();
                }
                ///GO BACK
                else if(user_input5 == 0){
                        system("cls");
                    return 0;
                }

}
}
