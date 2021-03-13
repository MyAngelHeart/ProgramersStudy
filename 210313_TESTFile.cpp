#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

    int nTestCase = 0;
    int CakeSize = 0;    

    cin>>nTestCase;
    
    while(nTestCase--)
    {
        cin>>CakeSize;
        int nHowManyPour = 0;  
        vector<bool> Cake(CakeSize,false);
        
        for(int i = 0; i<CakeSize; i++)
        {                  
            cin>>nHowManyPour;

            for(int j = 0; j < nHowManyPour; j++)
            {
                Cake[i-j] = true;
                if(i-j == 0)
                    break;
            }
        }

        for(int i=0; i<CakeSize; i++)
        {
            cout<<(Cake[i] ? "1" : "0")<<" ";
        }
        cout<<"\n";
    }   

    return 0;
}