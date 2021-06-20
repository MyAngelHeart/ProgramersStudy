#include <string>
#include <vector>
#include <iostream>
using namespace std;

enum Dicrection
{
    Right,
    Down,
    Left,    
    Up,    
};

struct Road
{
    int Straight;
    int Corner;
};

struct WayData
{
    int SizeX;
    int SizeY;
    int LocationX;
    int LocationY;
};

Road BestWay(vector<vector<int>> board);
int Cost(Road RoadData);

int main() 
{    
    vector<vector<int>> board;
    
    board.push_back(vector<int>(5));
    board.push_back(vector<int>(5));
    board.push_back(vector<int>(5));
    board.push_back(vector<int>(5));
    board.push_back(vector<int>(5));
    
    Cost(BestWay(board));
    
    return 0;
}

Road BestWay(vector<vector<int>> board)
{
    Road RoadData;
    RoadData.Straight = 0;
    RoadData.Corner = 0;
    WayData WayData;
    Dicrection Dic = Right;
    WayData.SizeX = board[0].size();
    WayData.SizeY = board.size();
    WayData.LocationX = 0;
    WayData.LocationY = 0;    
    
    int TempRight = 0;
    int TempDown = 0;
    int TempLocationX = 0;
    int TempLocationY = 0;    
    
    while(WayData.LocationX < WayData.SizeX - 1 || WayData.LocationY < WayData.SizeY - 1)
    {
        cout<<"Test"<<endl;
        RoadData.Corner++;
        TempRight = 0;
        TempDown = 0;
        TempLocationX = WayData.LocationX + 1;
        TempLocationY = WayData.LocationY;
        while(TempLocationX <= WayData.SizeX - 1 && board[TempLocationY][TempLocationX] != 1)
        {
            TempRight++;
            TempLocationX++;
            cout<<"TestRight"<<endl;
        }

        TempLocationX = WayData.LocationX;
        TempLocationY = WayData.LocationY + 1;
        while(TempLocationY <= WayData.SizeY - 1 && board[TempLocationY][TempLocationX] != 1)
        {
            TempDown++;
            TempLocationY++;
            cout<<"TestDown"<<endl;
        }

        if(TempRight > TempDown)
        {
            WayData.LocationX += TempRight;
            RoadData.Straight += TempRight;
            cout<<TempRight<<endl;
            Dic = Right;
        }
        else if(TempRight < TempDown)
        {
            WayData.LocationY += TempDown;
            RoadData.Straight += TempDown;
            cout<<TempDown<<endl;
            Dic = Down;
        }
        else
        {
            if(Dic != Right)
            {
                cout<<"미구현"<<endl;
                return RoadData;
            }
            else
            {
                WayData.LocationY -= 1;
                RoadData.Straight += 1;
                Dic = Left;
            }
        }
        
    }
    RoadData.Corner -= 1;
    return RoadData;
}

int Cost(Road RoadData)
{
    int Cost = 0;
    
    Cost += 100 * RoadData.Straight;
    Cost += 500 * RoadData.Corner;
    cout<<"결과는 ";
    cout<<Cost<<endl;
    
    return Cost;
}
