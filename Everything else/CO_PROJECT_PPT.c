#include<stdio.h>
#include<cstdlib>
#include<windows.h>


#define WIDTH 50
#define HEIGHT 25

using namespace std;

struct COORD{int X,Y};

int x=10,y=10;
void board()
{
    for(int i=0;i<HEIGHT;i++)
    {
        count<<"\t\t#";
        for(int j=0;j<WIDTH-2;j++)
        {
            if(i==0||i==HEIGHT-1) cout<<'#';
            else cout<<'';
        }
        cout<<"#\n"
    }
}

int main()
{
    
    while(true)
    {
        board();
        x++;

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
        
    }
    


}