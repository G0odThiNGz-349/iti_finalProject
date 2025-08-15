#include <iostream>
#include <iomanip>
#include <conio.h> //for getch()
using namespace std;
enum moveability {ground, wall , object , passable , artifact , space , key , door };

moveability check_moveability(char);

int new_position_y(char,int);

int new_position_x(char, int);

int main() {
    int map_num=0;
    char map[4][20][40] = {
        "#######################################",
        "#P....................................#",
        "#.....................................#",
        "#...D.................................#",
        "#.....................................#",
        "#.....................................#",
        "#                                     #",
        "#.....................................#",
        "#.....................................#",
        "#.....................................#",
        "#.....................................#",
        "#.....................................#",
        "#.....................................#",
        "#..........................############",
        "#..........................#..........#",
        "#................................@....#",
        "#..........................#..........#",
        "#..........................#..........#",
        "#..........................#..........#",
        "#######################################",


        "#######################################",
        "#P.......#............................#",
        "#........#....................$.......#",
        "#...D.... ...................    .....#",
        "#........#............................#",
        "###########################.###########",
        "#...............###########.#.........#",
        "#......     ....I...........#.........#",
        "#...............#############.........#",
        "#.....................................#",
        "#.....................................#",
        "#.....................................#",
        "#.......   .......@...................#",
        "#.....................................#",
        "#.....................................#",
        "#.....................................#",
        "#..........................     ......#",
        "#.......    ..........................#",
        "#.....................................#",
        "#######################################",


        "#######################################",
        "#P..........   ...#........     ......#",
        "#.................#.    .....@....   .#",
        "#...D.............#.............   ...#",
        "#      ...    ....#####I###############",
        "#.....#....  .....#...................#",
        "#.....#...    ....#..............  ...#",
        "#.....#...........#.......    ...   ..#",
        "#.....#......    .#...................#",
        "#..$..#############......       ......#",
        "#.....................................#",
        "#.....................................#",
        "################    ###################",
        "#.....................................#",
        "#.......   ...........................#",
        "#..................     ..............#",
        "#............................   ... ..#",
        "#.....    ........@................ ..#",
        "#.....................................#",
        "#######################################",


        "#######################################",
        "#P..........   ....#.................p#",
        "#..................# .................#",
        "#...D..........   .#..................#",
        "#  .......     ....#..................#",
        "# ........   ......#..................#",
        "#  ...... .........#.......$..........#",
        "#.. ......  .......#..................#",
        "#...........       #..................#",
        "#.   ..............#..................#",
        "#...... ......    .#..................#",
        "#########I##########..................#",
        "#..................#..................#",
        "#..................#..................#",
        "#...D..............#..................#",
        "#.........        .# .................#",
        "#.......... .......#..................#",
        "#.......... ...@...#..................#",
        "#.....      .......#..................#",
        "#######################################"
    };
    bool started=0;
    int player_x = 1, player_y = 1;//intial player position
    int keys=0;
    char start; 
    cout<<setw(40)<<"wlecome to my mini game"<<endl<<endl;
    cout<<setw(31)<<"use "<<endl<<endl;
    cout<<setw(29)<<"W"<<endl;
    cout<<setw(31)<<" A S D"<<endl<<endl;
    cout<<setw(32)<<"to move"<<endl;
    cout<<setw(43)<<"Press ESC at anytime to exit"<<endl;
    cout<<setw(43)<<"Press R to reset the level"<<endl<<endl;
    cout<<"p- is the player character(your character)"<<endl;
    cout<<"#- are the Walls"<<endl;
    cout<<"  -are Voids "<<endl;
    cout<<"D-are Objects that can be used "<<endl;
    cout<<"I-are Doors "<<endl;
    cout<<"$-are Keys "<<endl;
    cout<<"@- Artifacts(you goal is to reach them)"<<endl<<endl;
    cout<<setw(100)<<"if you haven't already; you should run the html file first for info about the game and basic concepts for gameplay!"<<endl;
    cout<<setw(32)<<"Now Enjoy!"<<endl;
    cout<<setw(35)<<"do you wish to start the adventure (press y to start)? ";
    cin>>start;
    cout<<endl;

    while (start=='y' || start=='Y') {
        cout << "\033[2J";//clears terminal to update player position
            char game_map[20][40];
            if (started==0)
            {
                    for (int i = 0; i < 20; i++)
                {
                for (int j = 0; j < 40; j++)
                {
            game_map[i][j]=map[map_num][i][j];
                }
            }
            }
            started=1;

        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 40; x++) {
                cout << game_map[y][x];
            }
            cout << endl;
        }
        char ch = _getch();
        if (ch=='r'|| ch =='R')
        {
            game_map[20][40];
            for (int i = 0; i < 20; i++)
            {
            for (int j = 0; j < 40; j++)
            {
            game_map[i][j]=map[map_num][i][j];
            }
            }
            player_x = 1, player_y = 1;
            keys=0;
        }
        else if(ch==27) break; // ESC to exit
        int new_player_x  , new_player_y ;
         new_player_x = new_position_x(ch,player_x) , new_player_y = new_position_y(ch,player_y);
         
            int player2_x=38-player_x, player2_y=player_y;//mirrored player in map 4
            int new_player2_x=38-new_player_x , new_player2_y=new_player_y;

         if (check_moveability(game_map[new_player_y][new_player_x])== ground) {
            swap(game_map[player_y][player_x], game_map[new_player_y][new_player_x]);
            if(map_num==3){
            swap(game_map[player2_y][player2_x], game_map[new_player2_y][new_player2_x]);}
            player_x = new_player_x;
            player_y = new_player_y;
        }
        else if(check_moveability(game_map[new_player_y][new_player_x]) == object){ 
        int object_x  , object_y ;
        int new_object_x,new_object_y;
            object_x = new_player_x, object_y = new_player_y;
            new_object_x = object_x, new_object_y = object_y; 

            new_object_x=new_position_x(ch,object_x),new_object_y=new_position_y(ch,object_y);
                    if (check_moveability(game_map[new_object_y][new_object_x]) == space)
                    {
                        game_map[object_y][object_x]='.';
                        game_map[new_object_y][new_object_x]='|';
                         new_object_x=0;
                         new_object_y=0;
                    }
                    else{swap(game_map[object_y][object_x],game_map[new_object_y][new_object_x]);
                        swap(game_map[player_y][player_x], game_map[new_player_y][new_player_x]);
                        if(map_num==3){
                            swap(game_map[player2_y][player2_x], game_map[new_player2_y][new_player2_x]);}
                            player_x = new_player_x;
                            player_y = new_player_y;
                            object_x = new_object_x;
                            object_y = new_object_y;
                     }
        }
        else if(check_moveability(game_map[new_player_y][new_player_x]) == passable){
            new_player_x=new_position_x(ch,new_player_x), new_player_y=new_position_y(ch,new_player_y);
            swap(game_map[new_player_y][new_player_x],game_map[player_y][player_x]);
            if(map_num==3){
                new_player2_x=38-new_player_x , new_player2_y=new_player_y;
            swap(game_map[player2_y][player2_x], game_map[new_player2_y][new_player2_x]);}
            player_x = new_player_x;
            player_y = new_player_y;
        }
        else if(check_moveability(game_map[new_player_y][new_player_x]) == door){
            if (keys>0)
            {
                game_map[new_player_y][new_player_x]='|';
                keys--;
            }
                new_player_x=player_x;
                new_player_y=player_y;
        }
        else if(check_moveability(game_map[new_player_y][new_player_x]) == key ){
            keys++;
            game_map[new_player_y][new_player_x]='.';
             new_player_x=player_x;
             new_player_y=player_y;
        }
                else if(check_moveability(game_map[new_player_y][new_player_x]) == artifact){
             map_num++;
             player_x = 1, player_y = 1;
             started=0;
             if (map_num<=3)
             {
             cout<<"do you wish to go further (press y to continue)?";
             cin>>start;
             cout<<endl;
             }
             else{
                    cout<<endl;
                    cout << "\033[2J";
                    cout<<setw(40)<<"Congrats You Have Escaped!"<<endl;
                    cout<<setw(30)<<"Hope You Enjoyed!"<<endl;
                    cout<<endl<<endl<<"Press Any Key to exit"<<endl;
                    char ch=_getch();
                    start='n';
             }
        }
            else{
            new_player_x=player_x;
            new_player_y=player_y;
        }
           if(check_moveability(game_map[player2_y][player2_x]) == key){
            keys++;
            game_map[player2_y][player2_x]='.';   
        }
    }
    return 0;
}

moveability check_moveability(char next_postion){
if(next_postion=='.'){
    return ground;
}
else if(next_postion == 'D'){
    return object;
}
else if(next_postion == '#'){
    return wall;
}
else if(next_postion == '|'){
    return passable;
}
else if(next_postion == '@'){
    return artifact;
}
else if(next_postion == '$'){
    return key;
}
else if(next_postion == 'I'){
    return door;
}
else{
    return space;
}
}
int new_position_y(char input , int position_y){
        int new_position_y=position_y;
        if (input == 'w' || input == 'W' )new_position_y--;
        else if (input == 's' || input == 'S')new_position_y++;
        return new_position_y;

        }
int new_position_x(char input , int position_x ){
    int new_position_x=position_x;
        if (input == 'a'|| input == 'A')new_position_x--;
        else if (input == 'd' || input == 'D')new_position_x++;
        return new_position_x;
}