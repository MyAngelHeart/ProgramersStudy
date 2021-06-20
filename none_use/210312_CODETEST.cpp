#include <vector>
#include <iostream>
using namespace std;
int MOD = 20170805;

enum Dicrection
{
    Right,
    Down, 
};

bool moveDir(int x, int y, vector<vector<int>> city_map, Dicrection Dir)
{
    if(Dir == Right)
    {
        if(x+1 >= city_map[0].size())
        {
            return false;
        }
        
        if(city_map[y][x+1] == 0)
        {
            return true;
        }
        else if(city_map[y][x+1] == 2)
        {
            if(moveDir(x+1,y,city_map,Dir))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else if(Dir == Down)
    {
        if(y+1 >= city_map.size())
        {
            return false;
        }
        
       if(city_map[y+1][x] == 0)
        {
            return true;
        }
        else if(city_map[y+1][x] == 2)
        {
            if(moveDir(x,y+1,city_map,Dir))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }    
}

bool CanRotate(int x, int y, vector<vector<int>> city_map)
{
    if(city_map[y][x] == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void Go(int *PtrAnswer, int x, int y, int m, int n ,vector<vector<int>> city_map, Dicrection Dir);

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) 
{    
    int answer = 0;
    Dicrection MoveDir = Right;
    int *PtrAnswer = &answer;
      
    Go(PtrAnswer, 0, 0, m, n, city_map, MoveDir);
    
    answer %= MOD;
    
    return answer;
}

void Go(int *PtrAnswer, int x, int y, int m, int n ,vector<vector<int>> city_map, Dicrection Dir)
{
    if(CanRotate(x,y,city_map))
    {
        if(Dir == Right)
        {
            Dicrection NewDir = Down;
            Go(PtrAnswer,x,y,m,n,city_map,NewDir);
        }
        else if(Dir == Down)
        {
            Dicrection NewDir = Right;
            Go(PtrAnswer,x,y,m,n,city_map,NewDir);
        }
    }
    
    if(moveDir(x,y,city_map,Dir))
    {
        if(Dir == Right)
        {
            if(y == m-1 && x+1 == n-1)
            {
                *PtrAnswer++;
                cout<<"Count"<<endl;
            }
            else
            {
                Go(PtrAnswer,x+1,y,m,n,city_map,Dir);
            }
        }
        else if(Dir == Down)
        {
            if(y+1 == m-1 && x == n-1)
            {
                *PtrAnswer++;
                cout<<"Count"<<endl;
            }
            else
            {
                Go(PtrAnswer,x,y+1,m,n,city_map,Dir);
            }
        }
    }
    
    return;
}
