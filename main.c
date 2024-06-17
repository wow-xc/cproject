#include "raylib.h"
#include "stdio.h"
#include "math.h"
#include "stdlib.h"

#define PLAYER_SIZE 40

int main(void)
{   

    bool skillturn1 = false;
    float skillcool1 = 0.0f;
    int skillframe1 = 0;
    
    int skillx1 = 0;
    int skilly1 = 0;

    bool skillturn2 = false;
    float skillcool2 = 0.0f;
    int skillframe2 = 0;

    int skillx2 = 0;
    int skilly2 = 0;

    const int screenWidth = 1600;
    const int screenHeight = 880;
    
    InitWindow(screenWidth, screenHeight, "2player battle game");

    Texture2D background1 = LoadTexture("Background1.png");
    Texture2D background2 = LoadTexture("Background2.png");

    Texture2D Elec = LoadTexture("Animation/Lightning/4.png");
    int ElecWidth = Elec.width / 10;
    int ElecHeight = Elec.height;

    Rectangle ElecRecs[10] = {0};
    for(int i=0;i<10;i++){
        ElecRecs[i] = (Rectangle){ElecWidth*i, 0, ElecWidth, ElecHeight };
    }

    Texture2D Boom = LoadTexture("Animation/Barrel/Boom1.png");
    int BoomWidth = Boom.width / 8;
    int BoomHeight = Boom.height;

    Rectangle BoomRecs[8] = {0};
    for(int i=0;i<8;i++){
        BoomRecs[i] = (Rectangle){BoomWidth*i, 0, BoomWidth, BoomHeight };
    }

    Texture2D Swalk1 = LoadTexture("chars/2/S_Walk.png");
    int SWidth1 = Swalk1.width / 6;
    int SHeight1 = Swalk1.height;

    Rectangle SwalkRecs1[6] = {0};
    for(int i=0;i<6;i++){
        SwalkRecs1[i] = (Rectangle){SWidth1*i, 0, SWidth1, SHeight1};
    }

    Texture2D Wwalk1 = LoadTexture("chars/2/W_Walk.png");
    int WWidth1 = Wwalk1.width / 6;
    int WHeight1 = Wwalk1.height;

    Rectangle WwalkRecs1[6] = {0};
    for(int i=0;i<6;i++){
        WwalkRecs1[i] = (Rectangle){WWidth1*i, 0, WWidth1, WHeight1};
    }

    Texture2D Awalk1 = LoadTexture("chars/2/A_Walk.png");
    int AWidth1 = Awalk1.width / 6;
    int AHeight1 = Awalk1.height;

    Rectangle AwalkRecs1[6] = {0};
    for(int i=0;i<6;i++){
        AwalkRecs1[i] = (Rectangle){AWidth1*i, 0, AWidth1, AHeight1};
    }

    Texture2D Dwalk1 = LoadTexture("chars/2/D_Walk.png");
    int DWidth1 = Dwalk1.width / 6;
    int DHeight1 = Dwalk1.height;

    Rectangle DwalkRecs1[6] = {0};
    for(int i=0;i<6;i++){
        DwalkRecs1[i] = (Rectangle){DWidth1*i, 0, DWidth1, DHeight1};
    }
    
    Texture2D Stand1 = LoadTexture("chars/2/Stand1.png");
    int TWidth1 = Stand1.width;
    int THeight1 = Stand1.height;

    Rectangle StandRecs1[1] = {
        { 0, 0, TWidth1, THeight1 },
    };

    Texture2D Swalk2 = LoadTexture("chars/3/S_Walk.png");
    int SWidth2 = Swalk2.width / 6;
    int SHeight2 = Swalk2.height;

    Rectangle SwalkRecs2[6] = {0};
    for(int i=0;i<6;i++){
        SwalkRecs2[i] = (Rectangle){SWidth2*i, 0, SWidth2, SHeight2};
    }

    Texture2D Wwalk2 = LoadTexture("chars/3/W_Walk.png");
    int WWidth2 = Wwalk2.width / 6;
    int WHeight2 = Wwalk2.height;

    Rectangle WwalkRecs2[6] = {0};
    for(int i=0;i<6;i++){
        WwalkRecs2[i] = (Rectangle){WWidth2*i, 0, WWidth2, WHeight2};
    }

    Texture2D Awalk2 = LoadTexture("chars/3/A_Walk.png");
    int AWidth2 = Awalk2.width / 6;
    int AHeight2 = Awalk2.height;

    Rectangle AwalkRecs2[6] = {0};
    for(int i=0;i<6;i++){
        AwalkRecs2[i] = (Rectangle){AWidth2*i, 0, AWidth2, AHeight2};
    }

    Texture2D Dwalk2 = LoadTexture("chars/3/D_Walk.png");
    int DWidth2 = Dwalk2.width / 6;
    int DHeight2 = Dwalk2.height;

    Rectangle DwalkRecs2[6] = {0};
    for(int i=0;i<6;i++){
        DwalkRecs2[i] = (Rectangle){DWidth2*i, 0, DWidth2, DHeight2};
    }
    
    Texture2D Stand2 = LoadTexture("chars/3/Stand.png");
    int TWidth2 = Stand2.width;
    int THeight2 = Stand2.height;

    Rectangle StandRecs2[1] = {
        { 0, 0, TWidth2, THeight2 },
    };

    int p1healvalue = 60;
    int p2healvalue = 60;
    int p1energy = 300;
    int p2energy = 300;

    Rectangle player1 = { 100, 440, SWidth1, SHeight1 };
    Rectangle player2 = { 1500, 440, SWidth2, SHeight2 };

    Texture2D Fire = LoadTexture("Images/Animated_Objects/Campfire/2.png");
    int FireWidth = Fire.width / 6;
    int FireHeight = Fire.height;

    Rectangle FireRecs[6] = {
        { 0, 0, FireWidth, FireHeight },
        { FireWidth, 0, FireWidth, FireHeight },
        { FireWidth*2, 0, FireWidth, FireHeight },
        { FireWidth*3, 0, FireWidth, FireHeight },
        { FireWidth*4, 0, FireWidth, FireHeight },
        { FireWidth*5, 0, FireWidth, FireHeight },
    };

    Camera2D camera1 = { 0 };
    camera1.target = (Vector2){ player1.x, player1.y };
    camera1.offset = (Vector2){ 400.0f, 400.0f };
    camera1.rotation = 0.0f;
    camera1.zoom = 1.0f;

    Camera2D camera2 = { 0 };
    camera2.target = (Vector2){ player2.x, player2.y };
    camera2.offset = (Vector2){ 400.0f, 400.0f };
    camera2.rotation = 0.0f;
    camera2.zoom = 1.0f;

    RenderTexture screenCamera1 = LoadRenderTexture(screenWidth/2, screenHeight);
    RenderTexture screenCamera2 = LoadRenderTexture(screenWidth/2, screenHeight);

    Texture2D mapTexture = LoadTexture("Images/Tiles/FieldsTile_01.png");
    Texture2D down = LoadTexture("Images/Tiles/FieldsTile_02.png");
    Texture2D right = LoadTexture("Images/Tiles/FieldsTile_09.png");
    Texture2D left = LoadTexture("Images/Tiles/FieldsTile_13.png");
    Texture2D up = LoadTexture("Images/Tiles/FieldsTile_35.png");
    Texture2D upright = LoadTexture("Images/Tiles/FieldsTile_08.png");
    Texture2D upleft = LoadTexture("Images/Tiles/FieldsTile_06.png");
    Texture2D downright = LoadTexture("Images/Tiles/FieldsTile_24.png");
    Texture2D downleft = LoadTexture("Images/Tiles/FieldsTile_22.png");
    Texture2D grass = LoadTexture("Images/Tiles/FieldsTile_38.png");

    mapTexture.height = 40; mapTexture.width = 40;
    down.height = 40; down.width = 40;
    right.height = 40; right.width = 40;
    left.height = 40; left.width = 40;
    up.height = 40; up.width = 40;
    upright.height = 40; upright.width = 40;
    upleft.height = 40; upleft.width = 40;
    downright.height = 40; downright.width = 40;
    downleft.height = 40; downleft.width = 40;
    grass.height = 40; grass.width = 40;

    bool gameintro = true;
    bool p1ready = false;
    bool p2ready = false;

    int currentFrame = 0;
    int framesCounter = 0;
    int framesSpeed = 8;
    
    int directioncheck1 = 0;
    int directioncheck2 = 0;

    int skillintcool1 = 0;
    int skillintcool2 = 0;

    Rectangle splitScreenRect = { 0.0f, 0.0f, (float)screenCamera1.texture.width, (float)-screenCamera1.texture.height };

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {   

        if(gameintro){
            if(p1ready && p2ready){
                gameintro = false;
            }
            if(IsKeyDown(KEY_W)){
                p1ready = true;
            }
            if(IsKeyDown(KEY_UP)){
                p2ready = true;
            }
        }else if(p1healvalue>0 && p2healvalue>0){

        framesCounter++;
        if (framesCounter >= (60 / framesSpeed))
        {
            framesCounter = 0;
            currentFrame++;
            if (currentFrame > 5) currentFrame = 0;
        }

        if (IsKeyDown(KEY_S)){if(IsKeyDown(KEY_LEFT_SHIFT) && p1energy > 0){player1.y += 5.0f; p1energy -=5;}else{player1.y += 3.0f;} directioncheck1 = 1;}
        else if (IsKeyDown(KEY_W)){if(IsKeyDown(KEY_LEFT_SHIFT) && p1energy > 0){player1.y -= 5.0f; p1energy -=5;}else{player1.y -= 3.0f;} directioncheck1 = 2;} 
        else if (IsKeyDown(KEY_D)){if(IsKeyDown(KEY_LEFT_SHIFT) && p1energy > 0){player1.x += 5.0f; p1energy -=5;}else{player1.x += 3.0f;} directioncheck1 = 3;} 
        else if (IsKeyDown(KEY_A)){if(IsKeyDown(KEY_LEFT_SHIFT) && p1energy > 0){player1.x -= 5.0f; p1energy -=5;}else{player1.x -= 3.0f;} directioncheck1 = 4;} 
        else{directioncheck1 = 0;}

        if(IsKeyDown(KEY_LEFT_SHIFT) == false && p1energy < 300)p1energy+=1;

        if (IsKeyDown(KEY_DOWN)){if(IsKeyDown(KEY_RIGHT_SHIFT) && p2energy > 0){player2.y += 5.0f; p2energy -=5;}else{player2.y += 3.0f;}directioncheck2=1;}
        else if (IsKeyDown(KEY_UP)){if(IsKeyDown(KEY_RIGHT_SHIFT) && p2energy > 0){player2.y -= 5.0f; p2energy -=5;}else{player2.y -= 3.0f;}directioncheck2=2;}
        else if (IsKeyDown(KEY_RIGHT)){if(IsKeyDown(KEY_RIGHT_SHIFT) && p2energy > 0){player2.x += 5.0f; p2energy -=5;}else{player2.x += 3.0f;}directioncheck2=3;}
        else if (IsKeyDown(KEY_LEFT)){if(IsKeyDown(KEY_RIGHT_SHIFT) && p2energy > 0){player2.x -= 5.0f; p2energy -=5;}else{player2.x -= 3.0f;}directioncheck2=4;}
        else{directioncheck2=0;}

        if(IsKeyDown(KEY_RIGHT_SHIFT) == false && p2energy < 300)p2energy+=1;
        
        if(player1.x > 1560) player1.x = 1560;
        if(player1.x < 0) player1.x = 0;
        if(player1.y > 840) player1.y = 840;
        if(player1.y < 0) player1.y = 0;

        if(player2.x > 1560) player2.x = 1560;
        if(player2.x < 0) player2.x = 0;
        if(player2.y > 840) player2.y = 840;
        if(player2.y < 0) player2.y = 0;

        if(skillcool1 > 0.0f){skillcool1 -= GetFrameTime();}

        if(IsKeyDown(KEY_Q) && skillcool1 <= 0.0f){skillturn1 = true; skillcool1 = 2.0f; skillframe1 = 0;}

        if(skillcool2 > 0.0f){skillcool2 -= GetFrameTime();}

        if(IsKeyDown(KEY_SLASH) && skillcool2 <= 0.0f){skillturn2 = true; skillcool2 = 3.0f; skillframe2 = 0;}

        camera1.target = (Vector2){ player1.x, player1.y };
        camera2.target = (Vector2){ player2.x, player2.y };

        if(player1.x > 800 - FireWidth && player1.x < 800 && player1.y > 440 - FireHeight && player1.y < 440){
            p1healvalue -= 1;
        }
        if(player2.x > 800 - FireWidth && player2.x < 800 && player2.y > 440 - FireHeight && player2.y < 440){
            p2healvalue -= 1;
        }
        if(player1.x > skillx2 -50 && player1.x < skillx2+ElecWidth+50 && player1.y > skilly2-50 && player1.y < skilly2+ElecHeight+50 && skillturn2 == true){
            p1healvalue -= 3;
        }
        if(player2.x > skillx1 -30 && player2.x < skillx1+BoomWidth+30 && player2.y > skilly1-30 && player2.y < skilly1+BoomHeight+30 && skillturn1 == true){
            p2healvalue -= 3;
        }

            BeginTextureMode(screenCamera1);
            ClearBackground(RAYWHITE);

            BeginMode2D(camera1);

                for(int i = -1000; i< 2600; i+=40){
                    for(int j = -1000; j< 1880; j+=40){
                        if(i<-40 || i>1600 || j<-40 || j>880){
                            DrawTexture(grass, i, j, WHITE);
                        }
                    }
                }
            
                for (int i = 0; i < screenWidth; i+=40){
                    for(int j = 0; j < screenHeight; j+=40){
                        DrawTexture(mapTexture, i, j, WHITE);
                    }
                }
                
                for(int i = 0; i < screenWidth; i+=40){
                    DrawTexture(up, i, -40, WHITE);
                }
                for(int i = 0; i < screenWidth; i+=40){
                    DrawTexture(down, i, screenHeight, WHITE);
                }
                for(int i = 0; i < screenHeight; i+=40){
                    DrawTexture(left, -40, i, WHITE);
                }
                for(int i = 0; i < screenHeight; i+=40){
                    DrawTexture(right, screenWidth, i, WHITE);
                }
                DrawTexture(upleft, -40, -40, WHITE);
                DrawTexture(downleft, -40, screenHeight, WHITE);
                DrawTexture(upright, screenWidth, -40, WHITE);
                DrawTexture(downright, screenWidth, screenHeight, WHITE);

                DrawTextureRec(Fire, FireRecs[currentFrame], (Vector2){ 800, 440 }, WHITE);

                switch (directioncheck1)
                {
                case 1:
                    DrawTextureRec(Swalk1, SwalkRecs1[currentFrame], (Vector2){ player1.x, player1.y }, WHITE);
                    skillx1 = player1.x;
                    skilly1 = player1.y + 80;
                    break;
                case 2:
                    DrawTextureRec(Wwalk1, WwalkRecs1[currentFrame], (Vector2){ player1.x, player1.y }, WHITE);
                    skillx1 = player1.x;
                    skilly1 = player1.y - 80;
                    break;
                case 3:
                    DrawTextureRec(Dwalk1, DwalkRecs1[currentFrame], (Vector2){ player1.x, player1.y }, WHITE);
                    skillx1 = player1.x + 80;
                    skilly1 = player1.y;
                    break;
                case 4:
                    DrawTextureRec(Awalk1, AwalkRecs1[currentFrame], (Vector2){ player1.x, player1.y }, WHITE);
                    skillx1 = player1.x - 80;
                    skilly1 = player1.y;
                    break;
                case 0:
                    DrawTextureRec(Stand1, StandRecs1[0], (Vector2){ player1.x, player1.y }, WHITE);
                }

                switch (directioncheck2)
                {
                case 1:
                    DrawTextureRec(Swalk2, SwalkRecs2[currentFrame], (Vector2){ player2.x, player2.y }, WHITE);
                    skillx2 = player2.x;
                    skilly2 = player2.y + 80;
                    break;
                case 2:
                    DrawTextureRec(Wwalk2, WwalkRecs2[currentFrame], (Vector2){ player2.x, player2.y }, WHITE);
                    skillx2 = player2.x;
                    skilly2 = player2.y - 160;
                    break;
                case 3:
                    DrawTextureRec(Dwalk2, DwalkRecs2[currentFrame], (Vector2){ player2.x, player2.y }, WHITE);
                    skillx2 = player2.x + 80;
                    skilly2 = player2.y - 60;
                    break;
                case 4:
                    DrawTextureRec(Awalk2, AwalkRecs2[currentFrame], (Vector2){ player2.x, player2.y }, WHITE);
                    skillx2 = player2.x - 80;
                    skilly2 = player2.y - 60;
                    break;
                case 0:
                    DrawTextureRec(Stand2, StandRecs2[0], (Vector2){ player2.x, player2.y }, WHITE);
                }
                if(skillturn1 && skillframe1 < 8){
                    DrawTextureRec(Boom, BoomRecs[skillframe1], (Vector2){ skillx1, skilly1 }, WHITE);
                    skillframe1++;
                }else{
                    skillturn1 = false;
                }
                if(skillturn2 && skillframe2 < 10){
                    DrawTextureRec(Elec, ElecRecs[skillframe2], (Vector2){ skillx2, skilly2 }, WHITE);
                    skillframe2++;
                }else{
                    skillturn2 = false;
                }

                // DrawText(skillcooltext1, player1.x-10, player1.y-30, 30, BLACK);
                DrawRectangle(player1.x-10, player1.y-20, p1energy/5, 10, RED);
                DrawRectangle(player1.x-10, player1.y-10, p1healvalue, 10, GREEN);
                DrawRectangle(player2.x-10, player2.y-10, p2healvalue, 10, GREEN);
                
            EndMode2D();
            
            DrawRectangle(0, 0, GetScreenWidth()/2, 30, Fade(RAYWHITE, 0.6f));
            DrawText("PLAYER1: W/S/A/D to move|Q to attack|RUN to L_SHIFT", 10, 10, 10, MAROON);
            
        EndTextureMode();

        BeginTextureMode(screenCamera2);
            ClearBackground(RAYWHITE);
            
            BeginMode2D(camera2);
                
                for(int i = -1000; i< 2600; i+=40){
                    for(int j = -1000; j< 1880; j+=40){
                        if(i<-40 || i>1600 || j<-40 || j>880){
                            DrawTexture(grass, i, j, WHITE);
                        }
                    }
                }
            
                for (int i = 0; i < screenWidth; i+=40){
                    for(int j = 0; j < screenHeight; j+=40){
                        DrawTexture(mapTexture, i, j, WHITE);
                    }
                }
                // DrawText();
                
                for(int i = 0; i < screenWidth; i+=40){
                    DrawTexture(up, i, -40, WHITE);
                }
                for(int i = 0; i < screenWidth; i+=40){
                    DrawTexture(down, i, screenHeight, WHITE);
                }
                for(int i = 0; i < screenHeight; i+=40){
                    DrawTexture(left, -40, i, WHITE);
                }
                for(int i = 0; i < screenHeight; i+=40){
                    DrawTexture(right, screenWidth, i, WHITE);
                }
                DrawTexture(upleft, -40, -40, WHITE);
                DrawTexture(downleft, -40, screenHeight, WHITE);
                DrawTexture(upright, screenWidth, -40, WHITE);
                DrawTexture(downright, screenWidth, screenHeight, WHITE);

                DrawTextureRec(Fire, FireRecs[currentFrame], (Vector2){ 800, 440 }, WHITE);

                switch (directioncheck1)
                {
                case 1:
                    DrawTextureRec(Swalk1, SwalkRecs1[currentFrame], (Vector2){ player1.x, player1.y }, WHITE);
                    skillx1 = player1.x;
                    skilly1 = player1.y + 80;
                    break;
                case 2:
                    DrawTextureRec(Wwalk1, WwalkRecs1[currentFrame], (Vector2){ player1.x, player1.y }, WHITE);
                    skillx1 = player1.x;
                    skilly1 = player1.y - 80;
                    break;
                case 3:
                    DrawTextureRec(Dwalk1, DwalkRecs1[currentFrame], (Vector2){ player1.x, player1.y }, WHITE);
                    skillx1 = player1.x + 80;
                    skilly1 = player1.y;
                    break;
                case 4:
                    DrawTextureRec(Awalk1, AwalkRecs1[currentFrame], (Vector2){ player1.x, player1.y }, WHITE);
                    skillx1 = player1.x - 80;
                    skilly1 = player1.y;
                    break;
                case 0:
                    DrawTextureRec(Stand1, StandRecs1[0], (Vector2){ player1.x, player1.y }, WHITE);
                }

                switch (directioncheck2)
                {
                case 1:
                    DrawTextureRec(Swalk2, SwalkRecs2[currentFrame], (Vector2){ player2.x, player2.y }, WHITE);
                    skillx2 = player2.x;
                    skilly2 = player2.y + 80;
                    break;
                case 2:
                    DrawTextureRec(Wwalk2, WwalkRecs2[currentFrame], (Vector2){ player2.x, player2.y }, WHITE);
                    skillx2 = player2.x;
                    skilly2 = player2.y - 160;
                    break;
                case 3:
                    DrawTextureRec(Dwalk2, DwalkRecs2[currentFrame], (Vector2){ player2.x, player2.y }, WHITE);
                    skillx2 = player2.x + 80;
                    skilly2 = player2.y - 60;
                    break;
                case 4:
                    DrawTextureRec(Awalk2, AwalkRecs2[currentFrame], (Vector2){ player2.x, player2.y }, WHITE);
                    skillx2 = player2.x - 80;
                    skilly2 = player2.y - 60;
                    break;
                case 0:
                    DrawTextureRec(Stand2, StandRecs2[0], (Vector2){ player2.x, player2.y }, WHITE);
                }
                if(skillturn1 && skillframe1 < 8){
                    DrawTextureRec(Boom, BoomRecs[skillframe1], (Vector2){ skillx1, skilly1 }, WHITE);
                    skillframe1 += 1;
                }else{
                    skillturn1 = false;
                }
                if(skillturn2 && skillframe2 < 10){
                    DrawTextureRec(Elec, ElecRecs[skillframe2], (Vector2){ skillx2, skilly2 }, WHITE);
                    skillframe2 += 1;
                }else{
                    skillturn2 = false;
                }
                
                
                DrawRectangle(player2.x-10, player2.y-20, p2energy/5, 10, RED);
                DrawRectangle(player1.x-10, player1.y-10, p1healvalue, 10, GREEN);
                DrawRectangle(player2.x-10, player2.y-10, p2healvalue, 10, GREEN);
                
            EndMode2D();
            
            DrawRectangle(0, 0, GetScreenWidth()/2, 30, Fade(RAYWHITE, 0.6f));
            DrawText("PLAYER2: UP/DOWN/LEFT/RIGHT to move|SLASH to attack|RUN to R_SHIFT", 10, 10, 10, DARKBLUE);
            
        EndTextureMode();

        
        }else{
            if(IsKeyDown(KEY_SPACE)){
                p1ready = false;
                p2ready = false;
                gameintro = true;
                skillturn1 = false;
                skillcool1 = 0.0f;
                skillframe1 = 0;
    
                skillx1 = 0;
                skilly1 = 0;

                skillturn2 = false;
                skillcool2 = 0.0f;
                skillframe2 = 0;

                skillx2 = 0;
                skilly2 = 0;

                p1healvalue = 60;
                p2healvalue = 60;
                p1energy = 300;
                p2energy = 300;
    
                int directioncheck1 = 0;
                int directioncheck2 = 0;

                player1.x = 100;
                player1.y = 440;
                player2.x = 1500;
                player2.y = 440;
                }
        }
        BeginDrawing();
            
            if (gameintro) {
                ClearBackground(RAYWHITE);
                DrawTexture(background1, 0, 0, WHITE);
                DrawText("2Player Battle Game", screenWidth/2 - 260, screenHeight/2 - 50, 40, BLACK);
                DrawText("Press W and UP arrow to start", screenWidth/2 - 190, screenHeight/2, 18, BLACK);
                if(p1ready)DrawText("Ready!", screenWidth/2 - 500, screenHeight/2 + 200, 25, BLACK);
                else DrawText("Press W", screenWidth/2 - 500, screenHeight/2 + 200, 25, BLACK);
                if(p2ready)DrawText("Ready!", screenWidth/2 + 350, screenHeight/2 + 200, 25, BLACK);
                else DrawText("Press Up", screenWidth/2 + 350, screenHeight/2 + 200, 25, BLACK);
                
            } else if(p1healvalue>0 && p2healvalue>0) {
                    ClearBackground(BLACK);
            
                    DrawTextureRec(screenCamera1.texture, splitScreenRect, (Vector2){ 0, 0 }, WHITE);
                    DrawTextureRec(screenCamera2.texture, splitScreenRect, (Vector2){ screenWidth/2.0f, 0 }, WHITE);
            
                    DrawRectangle(GetScreenWidth()/2 - 2, 0, 4, GetScreenHeight(), LIGHTGRAY);
            } else{
                ClearBackground(RAYWHITE);
                DrawTexture(background2, 0, 0, WHITE);
                if(p1healvalue<=0)DrawText("Player2", screenWidth/2 - 230, screenHeight/2 - 150, 100, BLACK);
                else if(p2healvalue<=0)DrawText("Player1", screenWidth/2 - 230, screenHeight/2 - 150, 100, BLACK);
                else DrawText("Both", screenWidth/2 - 230, screenHeight/2 - 150, 100, BLACK);
                DrawText("WIN", screenWidth/2 - 130, screenHeight/2 - 40, 100, BLACK);
                DrawText("Back to Intro, Press Space", screenWidth/2 - 380, screenHeight/2 +200, 50, BLACK);
            }
        EndDrawing();
    }


    UnloadRenderTexture(screenCamera1); 
    UnloadRenderTexture(screenCamera2);
    
    CloseWindow();

    return 0;
}

