#include<iostream>
using namespace std;
//global variable
char space[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}};//rows and column numbers of spaces
int row;
int column;
char token='x';
bool tie=false;
string n1="";
string n2="";

void functionOne(){ 
    
   //structure 
   cout<<"   |   |   \n";
   cout<<" "<<space[0][0]<<" | "<<space[0][1]<<" | "<<space[0][2]<<" \n";
   cout<<"___|___|___ \n";
   cout<<"   |   |    \n";
   cout<<" "<<space[1][0]<<" | "<<space[1][1]<<" | "<<space[1][2]<<" \n";
   cout<<"___|___|___ \n";
   cout<<"   |   |   \n";
   cout<<" "<<space[2][0]<<" | "<<space[2][1]<<" | "<<space[2][2]<<" \n";
   cout<<"   |   |   \n";

}

void functionTwo(){//we will check for any invalid value and make sure that it is 
//not there but before that we will create a variable digit so that we can take input from the user
 
   int digit;
   if(token=='x'){
     cout<<n1<<"please enter ";
     cin>>digit;
    }

    else if(token=='0'){
     cout<<n2<<"please enter ";
     cin>>digit;
    }

    if(digit==1){
        //first space
        row=0;
        column=0;
    }
    else if(digit==2){
        
        row=0;
        column=1;
    }
    else if(digit==3){
        
        row=0;
        column=2;
    }
    else if(digit==4){
        
        row=1;
        column=0;
    }
    else if(digit==5){
        
        row=1;
        column=1;
    }
    else if(digit==6){
    
        row=1;
        column=2;
    }
    else if(digit==7){

        row=2;
        column=0;
    }
    else if(digit==8){
        
        row=2;
        column=1;
    }
    else if(digit==9){
        
        row=2;
        column=2;
    }
    //if case is invalid
    else {
        cout<<"Invalid!!!"<<endl;
        return ;
    }
    
    /*1. We're checking if there are any empty spaces left on the game board.
      2. If it's player 1's turn (symbolized by "x"), we look for spaces on the board that are neither "x" nor "o".
      3. If we find such a space, we put "x" (player 1's symbol) in that empty space.
      4. Then, it becomes player 2's turn, so we change the symbol to "o" for player 2.
      5. We repeat this process until there are no empty spaces left on the board or until the game ends.*/
    if(token=='x' && space[row][column]!='x'&& space[row][column]!='0'){
        space[row][column]='x';
        token='0';
    }
    
    //same as above if player 2 turn is there
    else if(token=='0' && space[row][column]!='x'&& space[row][column]!='0'){
        space[row][column]='0';
        token='x';
    }

    else{
        cout<<"There isk no empty space"<<endl;
        //functionTwo();
        return;
    }
     functionOne();
}

//for checking whether the game is still going on or it is a draw
bool functionThree(){
   for(int i=0;i<3;i++){
     //set the condition for a player to win the match
     if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[i][i] && space[0][i]==space[2][i])//for horizontally & vertically
     return true;
    }
    
    //for digonally
    if(space[0][0]==space[1][1] && space[1][1]==space[2][2] || space[0][2]==space[1][1] && space[1][1]==space[2][0]){
        return true;
    }

    //check whether the game is still going on or is it finished
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(space[i][j]!='x' && space[i][j]!='0'){
                return false;
            }
        }
    }
    
    //if game will tie
    tie=true;
    return false;
}

//one by one hav eto call each function

int main(){

    cout<<"enter the name of 1st palyer: \n";
    getline(cin,n1);
    cout<<"enter the name of the second player: \n";
    getline(cin,n2);
    cout<<n1<< "is player1 so he/she will play first \n";
    cout<<n2<< "is player2 so he/she will play second \n";

    while(!functionThree() ){//this loop will keep on iterating till this will return false
        
        functionOne();
        functionTwo();
        functionThree();
    }

    if(token=='x' && tie==false){
        cout<<n2<<"Wins"<<endl;

    }
    else if(token=='0' && tie==false){
        cout<<n1<<"wins"<<endl;
    }

    else{
        cout<<"It's a draw"<<endl;
    }
}