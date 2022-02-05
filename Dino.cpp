#define STDIN_FILENO 0
#define esc 27
#include <conio.h>
#include <termio.h>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <ctime>
#include <iostream>

using namespace std;

//dinoStates -> left ,2legs,right,2legs
int dino [4][15][15] ={
{
    0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,
    0,0,0,0,0,0,0,0,1,3,2,3,3,3,1,
    0,0,0,0,0,0,0,0,1,3,3,3,3,3,1,
    0,0,0,0,0,0,0,0,1,3,3,3,1,1,1,
    0,0,0,0,0,0,0,0,1,3,3,1,0,0,0,
    0,0,0,0,0,0,0,1,3,3,3,1,0,0,0,
    0,0,0,0,0,0,1,3,3,3,3,3,1,1,0,
    1,0,0,0,0,1,3,3,3,3,3,1,0,1,0,
    1,1,0,0,1,3,3,3,3,3,3,1,0,0,0,
    1,1,1,1,3,3,3,3,3,3,3,1,0,0,0,
    0,1,1,1,3,3,3,3,3,3,1,0,0,0,0,
    0,0,1,1,3,3,1,3,3,1,0,0,0,0,0,
    0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,
    0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,1,1,0,0,0,0,0,0,0,0,0
},
{
    0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,
    0,0,0,0,0,0,0,0,1,3,2,3,3,3,1,
    0,0,0,0,0,0,0,0,1,3,3,3,3,3,1,
    0,0,0,0,0,0,0,0,1,3,3,3,1,1,1,
    0,0,0,0,0,0,0,0,1,3,3,1,0,0,0,
    0,0,0,0,0,0,0,1,3,3,3,1,0,0,0,
    0,0,0,0,0,0,1,3,3,3,3,3,1,1,0,
    1,0,0,0,0,1,3,3,3,3,3,1,0,1,0,
    1,1,0,0,1,3,3,3,3,3,3,1,0,0,0,
    1,1,1,1,3,3,3,3,3,3,3,1,0,0,0,
    0,1,1,1,3,3,3,3,3,3,1,0,0,0,0,
    0,0,1,1,3,3,1,3,3,1,0,0,0,0,0,
    0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,
    0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,
    0,0,0,0,1,1,0,1,1,0,0,0,0,0,0
},
{
    0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,
    0,0,0,0,0,0,0,0,1,3,3,3,3,3,1,
    0,0,0,0,0,0,0,0,1,3,3,3,3,3,1,
    0,0,0,0,0,0,0,0,1,3,3,3,1,1,1,
    0,0,0,0,0,0,0,0,1,3,3,1,0,0,0,
    0,0,0,0,0,0,0,1,3,3,3,1,0,0,0,
    0,0,0,0,0,0,1,3,3,3,3,3,1,1,0,
    1,0,0,0,0,1,3,3,3,3,3,1,0,1,0,
    1,1,0,0,1,3,3,3,3,3,3,1,0,0,0,
    1,1,1,1,3,3,3,3,3,3,3,1,0,0,0,
    0,1,1,1,3,3,3,3,3,3,1,0,0,0,0,
    0,0,1,1,3,3,1,3,3,1,0,0,0,0,0,
    0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,
    0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,1,1,0,0,0,0,0,0
},
{
    0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,
    0,0,0,0,0,0,0,0,1,3,2,3,3,3,1,
    0,0,0,0,0,0,0,0,1,3,3,3,3,3,1,
    0,0,0,0,0,0,0,0,1,3,3,3,1,1,1,
    0,0,0,0,0,0,0,0,1,3,3,1,0,0,0,
    0,0,0,0,0,0,0,1,3,3,3,1,0,0,0,
    0,0,0,0,0,0,1,3,3,3,3,3,1,1,0,
    1,0,0,0,0,1,3,3,3,3,3,1,0,1,0,
    1,1,0,0,1,3,3,3,3,3,3,1,0,0,0,
    1,1,1,1,3,3,3,3,3,3,3,1,0,0,0,
    0,1,1,1,3,3,3,3,3,3,1,0,0,0,0,
    0,0,1,1,3,3,1,3,3,1,0,0,0,0,0,
    0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,
    0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,
    0,0,0,0,1,1,0,1,1,0,0,0,0,0,0
}};

int cactus[][15][15]={
    {
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,
        0,0,0,0,0,4,4,4,0,0,0,4,0,0,0,
        0,0,0,0,0,4,4,4,0,0,0,4,0,0,0,
        0,0,4,0,0,4,4,4,0,0,0,4,0,0,0,
        0,4,4,0,0,4,4,4,4,4,4,4,0,0,0,
        0,4,4,0,0,4,4,4,0,0,0,0,0,0,0,
        0,4,4,4,4,4,4,4,0,0,0,0,0,0,0,
        0,4,4,4,4,4,4,4,0,0,0,0,0,0,0,
        0,0,0,0,0,4,4,4,0,0,0,0,0,0,0,
        0,0,0,0,0,4,4,4,0,0,0,0,0,0,0,
        0,0,0,0,0,4,4,4,0,0,0,0,0,0,0,
        0,0,0,0,0,4,4,4,0,0,0,0,0,0,0
    },
    {
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,4,0,4,0,0,0,4,0,0,0,0,0,0,
        4,0,4,0,4,0,4,0,4,0,4,0,0,0,0,
        4,0,4,0,4,0,4,4,4,0,4,0,4,0,0,
        4,0,4,0,4,0,4,0,0,0,4,0,4,0,0,
        4,4,4,0,4,4,4,0,4,0,4,0,4,0,0,
        0,4,0,0,0,0,4,0,4,0,4,4,4,0,0,
        0,4,0,0,0,0,4,0,4,4,4,0,0,0,0,
        0,4,0,0,0,0,4,0,0,0,4,0,0,0,0
    }
};

int pressSpace[][100] ={
    0,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,6,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,6,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,6,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,6,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,6,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,6,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,6,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,6,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,6,0,0,0,6,0,0,6,6,6,6,6,0,6,6,6,6,6,0,6,6,6,6,6,0,6,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,6,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,6,0,0,6,0,0,6,0,0,0,0,0,0,6,0,0,0,6,0,6,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,6,0,0,6,0,0,0,0,0,0,0,0,0,6,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,6,6,6,0,0,0,6,0,0,0,0,0,0,6,0,0,0,6,0,6,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,0,6,6,6,6,6,0,0,0,6,6,6,6,0,0,0,6,0,0,0,0,6,6,6,0,0,6,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,6,0,0,0,0,0,6,0,0,0,0,0,0,6,0,0,0,6,0,6,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,6,0,0,0,6,0,0,0,6,0,0,0,0,0,0,6,0,0,0,6,0,0,0,6,0,0,6,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,6,0,0,0,0,0,6,0,0,0,0,0,0,6,6,6,6,6,0,6,6,6,6,6,0,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,6,0,0,0,6,0,0,0,6,0,0,0,0,0,0,6,0,0,0,6,0,0,0,6,0,0,0,6,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,6,0,0,0,0,0,6,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,6,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,6,0,0,0,6,0,0,0,6,0,0,0,6,0,0,0,0,0,0,6,0,0,0,6,0,0,0,6,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,6,0,0,0,0,0,6,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,6,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,6,0,0,0,6,0,0,0,6,0,0,0,6,0,0,0,0,0,0,6,0,0,0,6,0,0,6,6,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,6,0,0,0,0,0,6,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,6,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,6,0,0,0,6,0,0,0,6,0,0,0,6,0,0,0,0,0,0,6,0,0,0,6,0,6,0,6,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,6,0,0,0,0,0,6,0,0,0,0,0,0,6,6,6,6,6,0,6,6,6,6,6,0,6,6,6,6,6,0,0,0,0,6,6,6,6,6,6,6,6,6,6,6,6,6,0,0,0,0,6,0,0,0,6,6,6,6,6,0,0,0,6,0,0,0,0,0,0,0,6,6,0,6,6,0,0,6,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0

};
bool isBeginning = true;

void Play(){
    int dinoXPos =30;
    int backgroundWidth = 154;
    int backgroundHeight = 50;
    int dinoYPos = backgroundHeight -20;
    float dinoYPosFloat = dinoYPos;
    float dinoState = 1;
    float changeRate = 0.1;
    float cactus1XPos = 160;
    float cactusSpeed = 2 ;
    float cactusAcceleration = 0.001;
    int pressSpaceXPos = 0;
    int pressSpaceYPos =0;
    float initialJumpSpeed =2;
    float jumpSpeed = initialJumpSpeed;
    float gravity = 0.1;
    float score = 0;
    int cactusType = 0;
    bool isUp = false;
    bool isDown = false;
    bool isColliding = false;
    int dinoGroundYPos = dinoYPos;
    int isInput;
    char input;
    char color[][7] ={{' ','?','O','.','@','.','#'},{'@',' ','O',' ',' ',' ',' '}};
    int colorMode = 0;
    int background[backgroundHeight][backgroundWidth];

    long totalFrame = 0;
    long shortFrame = 0;
    long s = clock();
    for(;;){
        long startFrame = clock();
        //reading input
        if(kbhit()){
            input = getchar(); 
            switch(input) {
                case ' ':
                    if(!isUp && !isDown){
                        isUp = true;
                    }
            }
        }
        //printf("%f",jumpSpeed);
        //if dino is jumping then move vertically
        if(isUp){
            //check if dino has reach max height
            if(jumpSpeed <= 0){
                isDown = true;
                isUp = false;
            }
            else{
                
                dinoYPosFloat -= jumpSpeed;
                dinoYPos = int(dinoYPosFloat);
                jumpSpeed -= gravity;
            }
        }
        //printf("%d",isDown);
        if(isDown){
            //check if dino has reach ground
            if(dinoYPos >= dinoGroundYPos){
                jumpSpeed = initialJumpSpeed;
                dinoYPos = dinoGroundYPos;
                dinoYPosFloat = dinoYPos;
                isDown = false;
            }
            else{
                dinoYPosFloat += jumpSpeed; 
                dinoYPos = int(dinoYPosFloat);
                jumpSpeed += gravity;
            }
        }


        //emptying background
        for(int j = 0;j<backgroundHeight;j++){
            for(int k=0;k<backgroundWidth;k++){
                background[j][k]=0;
            }
        }
        
        //placing cactus1 in the background
        for(int j=0;j<15;j++){
            for(int k=0;k<15;k++){
                if(cactus1XPos+k < backgroundWidth && cactus1XPos+k >= 0 ){
                    if (cactus[cactusType][j][k] != 0){
                        background[dinoGroundYPos+j][int(floor(cactus1XPos))+k] = cactus[cactusType][j][k];
                    }
                    
                }
                
            }
        }
        
        //placing dino in the background
        for(int j=0;j<15;j++){
            for(int k=0;k<15;k++){
                if(dino[int(floor(dinoState))][j][k] != 0){
                    //collision detection
                    if (background[dinoYPos+j][dinoXPos+k] != 0){
                        isColliding = true;
                    }
                    background[dinoYPos+j][dinoXPos+k] = dino[int(floor(dinoState))][j][k];
                }
                
                
            }
        }

        if(isColliding){
            //add sentence press space to play 
            for(int i = 0 ;i<sizeof(pressSpace)/sizeof(pressSpace[0]);i++){
                for(int j = 0 ;j<sizeof(pressSpace[0])/sizeof(pressSpace[0][0]) ;j++){
                    if(pressSpace[i][j] != 0){
                        background [pressSpaceYPos+i][pressSpaceXPos+j] = pressSpace[i][j];
                    }
                }
            }
        }

        printf("\x1b[d");
        
        //if it is beginning add sentence press space to play
        if(isBeginning){
            for(int i = 0 ;i<sizeof(pressSpace)/sizeof(pressSpace[0]);i++){
                for(int j = 0 ;j<sizeof(pressSpace[0])/sizeof(pressSpace[0][0]) ;j++){
                    
                    if(pressSpace[i][j] != 0){
                        background [pressSpaceYPos+i][pressSpaceXPos+j] = pressSpace[i][j];
                    }
                }
            }
        }
        //printing
        for(int j = 0;j<backgroundHeight;j++){
            for(int k=0;k<backgroundWidth;k++){
                //printf("%d",background[j][k]);
                printf("%c",color[colorMode][background[j][k]]);
            }
            printf("\n");
        }

        //if it is just for beginning screen then return
        if(isColliding){
            isColliding = false;
            return;
        }

        //if it is just for beginning screen then return
        if(isBeginning){
            isBeginning = false;
            return;
        }
        
        cactus1XPos = cactus1XPos-cactusSpeed;
        if (cactus1XPos <= 0){
            cactus1XPos = backgroundWidth;
            cactusType = rand()% (sizeof(cactus)/sizeof(cactus[0]));
        }
        dinoState = fmod(dinoState+changeRate,4);
        score += cactusSpeed/5;
        cactusSpeed += cactusAcceleration;
        colorMode = int(score / 500) % 2;
        printf("Score : %f\n",floor(score));
        printf("%ld\n",totalFrame - shortFrame);
        printf("%ld\n",shortFrame);
        printf("%ld",clock() - startFrame);
        totalFrame ++;

        while(clock() - startFrame < 20000){

            //just wait until frametime finish so we have fixed frame rate
        }
    }
}

int main(){
    //setting the termios
    struct termios old_tio, new_tio;
    /* get the terminal settings for stdin */
    tcgetattr(STDIN_FILENO, &old_tio);
    /* we want to keep the old setting to restore them a the end */
    new_tio = old_tio;
    /* disable canonical mode (buffered i/o) and local echo */
    new_tio.c_lflag &=(~ICANON );/*& ~ECHOE  );*/
    /* set the new settings immediately */
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);
    
    char input;
    int pressSpaceXPos = 0;
    int pressSpaceYPos = 0;
    printf("\x1b[2J");
    //printing the very first screen
    Play();
    //repeating play
    while(true){
        
        input = getch();
        if(input == esc){
            break;
        }
        else{
            Play();
        }
    }
    
}