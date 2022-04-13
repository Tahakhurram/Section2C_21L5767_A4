#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool searching(char *grid, int row, int col, string word, int R, int C, int &filer, int &filec, int &lastr, int &lastc);
void checkmatch(char *grid, string word, int R, int C, int &filer, int &filec, int &lastr, int &lastc, int &chk);     

int main()
{
    char option;
    string word;
    int R=10, C=10, filer=0, filec=0, lastr=0, lastc=0;;
    char grid[10][10];
    ifstream fin("input_Q2.txt", ios::in);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            fin >> grid[i][j];
        }
    }
    
    fin.close();
    cout << "Enter 0 to exit \n          OR \nAny key to continue: ";
    cin>>option;
    ofstream fout("output_Q2.txt");
    while (option != '0')
    {
        int chk = 0;
        cout<<"Enter word you want to check: " << endl;
        cin>>word;
        checkmatch((char *)grid, word, R, C, filer, filec, lastr, lastc, chk);
        if (chk==1)
        {
            fout<<"Starting index: "<<"("<<filer<<" , "<<filec<<")"<<endl;
            fout<<"Ending index: "<<"("<<lastr <<" , "<<lastc<<")"<<endl;
        }
        else if(chk > 1)
        {
            fout<<"This word not found in this puzzle!"<<endl;
        }
      	cout<<"Enter 0 to exit \n          OR \nAny key to continue: ";
    	cin>>option;
    }
    fout.close();
    cout<<endl;
    return 0;
}

                                                         
int x[] = {-1, -1, -1,  0,  0,  1, 1, 1};              //combinations to search in all 8 directions
int y[] = {-1,  0,  1, -1,  1, -1, 0, 1};              //dir = 0 2 5 7 , check for diagnols
bool searching(char *grid, int row, int col, string word, int R, int C, int &filer, int &filec, int &lastr, int &lastc)      //Main woking function
{
    if (*(grid + row * C + col) != word[0])                                  // If first character of word does not match
        return false;

    int len = word.length();

    for (int dir = 0; dir < 8; dir++)                            // Search word in all 8 directions
    {
        int k, rd = row + x[dir], cd = col + y[dir];                       // Initialize starting point
        for (k = 1; k < len; k++)                                       // First character is already checked
        {
            if (rd >= R || rd < 0 || cd >= C || cd < 0)                                       //If invalid value
            {
                break;
            }
           
            if (*(grid + rd * C + cd) != word[k])                    //break if doesnt match
            {
                break;
            }

            rd += x[dir], cd += y[dir];
        }

        if (k == len){
            if (dir == 0)                                      //Checks diagnol from right to left for ending index
            {
                rd = rd + 1;
                cd = cd + 1;
            }
            else if (dir == 1)                             //For below to top for ending index
            {
                rd = rd + 1;
            }
            else if (dir == 2)                                 //Checks diagnol from left to right for ending index
            {
                rd = rd + 1;
                cd = cd - 1;
            }
            else if (dir == 3)
            {
                cd = cd + 1;
            }
            else if (dir == 4)
            {
                cd = cd - 1;
            }
            else if (dir == 5)                                       //Checks diagnol from right to left for ending index
            {
                rd = rd - 1;
                cd = cd + 1;
            }
            else if (dir == 6)
            {
                rd = rd - 1;
            }
            else                                                 //Checks diagnol from left to right for ending index
            {
                cd = cd - 1;
                rd = rd - 1;
            }
            lastr = rd;
            lastc = cd;
            cout<<endl<<"The ending point is: ";                   // for ending index 
            cout<<"("<<rd<<" , "<<cd<<")"<<endl;   
        	 return true;
		}
           
        
    }
    return false;        
                         
}


void checkmatch(char *grid, string word, int R, int C, int &filer, int &filec, int &lastr, int &lastc, int &chk)       // Searches word in all 8 directions
{
    for (int row=0; row<R; row++)
    {
        for (int col=0; col<C; col++)
        {
            if (searching(grid, row, col, word, R, C, filer, filec, lastr, lastc))
            {
                cout<<"\nStaring index of match: "<<"("<<row<<" , "<<col<<")"<<endl;
                filer = row;
                filec = col;
                
            }
        }
    }
    for (int row = 0; row < R; row++)
    {
        for (int col = 0; col < C; col++)
        {
            if (searching(grid, row, col, word, R, C, filer, filec, lastr, lastc))
            {
                chk=1;
                return;
            }
            else {
                chk++;
            }
        }
    }
    if(chk>1){
        cout<<"Sorry! Could not find this word in this puzzle."<<endl;
    }
    
}
