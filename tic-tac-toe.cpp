#include <string>
#include <vector>

using namespace std;
bool check(vector<string> board,char c, int num){
    if(num<3){
        string temp = board[num];
        for(int i=0;i<3;i++){
            if(c!=temp[i])return false;
        }
    }
    else if(num<6){
        for(int i=0;i<3;i++){
            string temp = board[i];
            if(c!=temp[num-3]) return false;
        }
    }
    else{
        if(num==6){
            for(int i=0;i<3;i++){
                string temp = board[i];
                if(c!=temp[num-6+i]) return false;
            }
        }
        else{
            for(int i=0;i<3;i++){
                string temp = board[i];
                if(c!=temp[num-7+2-i]) return false;
            }
        }
    }
    
    return true;
}//이겼는지 체크하는 함수

int solution(vector<string> board) {
    int answer = 1;
    int num1=0,num2=0;
    bool win1=false, win2=false;
    for(int i=0;i<3;i++){
        string temp = board[i];
        for(int j=0;j<3;j++){
            if(temp[j]=='O') num1++;
            else if(temp[j]=='X') num2++;
        }
    }//O랑X 개수 체크
    
    for(int i=0;i<8;i++){
        if(check(board,'O',i)){
            win1 = true; break;
        }
    }//선공이 이겼는지 체크
    for(int i=0;i<8;i++){
        if(check(board,'X',i)){
            win2 = true; break;
        }
    }//후공이 이겼는지 체크
    if(num1!=num2&&num1!=num2+1) return 0;
    if(win1&&win2) return 0;
    if(win1){
        if(num1!=num2+1) return 0;
    }
    if(win2){
        if(num1!=num2) return 0;
    }
    

    return 1;
}