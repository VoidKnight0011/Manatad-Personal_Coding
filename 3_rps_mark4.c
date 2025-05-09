#include<stdio.h>
#include<ctype.h>
#include<unistd.h>

#define MAX_NAME_LEN 75

typedef struct ScoreCount{
    int score;
    char name[MAX_NAME_LEN];
}score;

void RockPaperScissors(score**, score**);
score *createPlayer(score**);
        void N();
        void clear();
        void slowTypeV1(const char*);
        void slowTypeV2(const char*);
    void uniqueStringInt(char*, int);
    void IntroGame();
    void query(score**);

// ----------

int main(){
score *p1, *p2;
    RockPaperScissors(&p1, &p2);
    return 0;
}

// ----------

score *createPlayer(score **player){
    *player = (score*)malloc(sizeof(score));
    if(player == NULL){
       printf("Memory Allocation Failed!");
       exit(1); 
    }
}

void RockPaperScissors(score **p1, score **p2){
    createPlayer(p1);
    createPlayer(p2);
    IntroGame();
    query(p1);
    
    printf("%s\n", (*p1)->name);
}

void IntroGame(){
    slowTypeV1("Welcome to");
    slowTypeV2("...");
    N();
    slowTypeV1("Rock");
    slowTypeV2(", ");
    slowTypeV1("Paper");
    slowTypeV2(", ");
    slowTypeV1("Scissors");
    slowTypeV2("!!!");
    clear();
}

void query(score **p1){
    printf("Enter Your Name: ");
    fgets((*p1)->name, sizeof((*p1)->name), stdin);
        (*p1)->name[strcspn((*p1)->name, "\n")] = '\0';
}

void slowTypeV1(const char *string){
    while(*string != '\0'){
        putchar(*string);
        fflush(stdout);
        usleep(45 * 1000);
        string++;
    }
}

void slowTypeV2(const char *string){
    while(*string != '\0'){
        putchar(*string);
        fflush(stdout);
        usleep(600 * 1000);
        string++;
    }
}

void uniqueStringInt(char *string, int value){
    sprintf(string, "Player 1 has %d points!\n", value);
}

void N(){
printf("\n");
}

void clear(){
printf("\033[H\033[J");
}
