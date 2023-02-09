#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int l=1;
char eog='n';
char eol='n';
int points=0,dis_points=0;

class level1
{
    protected:

        int stars=0;
        int *s=&stars;
        char grid[11][11];
        int row=0,col=0,dis_row=0,dis_col=10,freezer_row=0,freezer_col=0,bomb_timer=0,
        dis1_movement='a',cnt1=0,dis_freezecnt=0,dis_row2=7,dis_col2=5,dis2_movement='s',
        dis_row3=10,dis_col3=1,dis3_movement='d',dis_row4=3,dis_col4=3,dis4_movement='w',
        bomb_row,bomb_col;
        char a[4]={'d','a','w','s'};

    public:
        level1(){}

       void base_grid()
        {
            for (int i = 0; i < 11; i++)
            {
                for (int j = 0; j < 11; j++)
                {
                    grid[i][j] = '\0';
                }
            }

        }

       void grid_design();
       void grid_print();
       void coursor_position();
       void distructor_position();
       void distructor2_position();
       void distructor3_position();
       void distructor4_position();
       void distructor_movement(int dis_movement);
       void distructor2_movement(int dis_movement);
       void distructor3_movement(int dis_movement);
       void distructor4_movement(int dis_movement);
       void create_dis_freezer();
       void create_bomb();
       void nextlevel();
};
void level1::create_dis_freezer()
{
    srand( time(NULL) );
    do
    {
        freezer_row =rand() % 11;
        freezer_col =rand() % 11;
    } while ( grid[freezer_row ][freezer_col] == '|' || grid[freezer_row ][freezer_col] == '='
            || (freezer_row == row && freezer_col == col) || grid[freezer_row ][freezer_col] == '~'
            || grid[freezer_row ][freezer_col] == 'B');
    if(grid[freezer_row][freezer_col]=='*')
    {
        stars--;
    }
    grid[freezer_row ][freezer_col] = '$';
}
void level1::create_bomb()
{
    srand( time(NULL) );
    do
    {
        bomb_row =rand() % 11;
        bomb_col =rand() % 11;
    } while ( grid[bomb_row ][bomb_col] == '|' || grid[bomb_row ][bomb_col] == '='
            || (bomb_row == row && bomb_col == col) || grid[bomb_row ][bomb_col] == '~'
            || grid[bomb_row][bomb_col] == '$');
    if(grid[bomb_row][bomb_col]=='*')
    {
        stars--;
    }
    grid[bomb_row][bomb_col] = 'B';
}
void level1::distructor_position()
{
    //delete a;
    a[0]='\0';
    a[1]='\0';
    a[2]='\0';
    a[3]='\0';
    int i=0;
    if (grid[dis_row][dis_col+1] != '|' && grid[dis_row][dis_col+1] != '=' && grid[dis_row][dis_col+1] != 'B' && dis_col != 10)
    {
        a[i]='d';
        i++;
        //cout<<a[i];
    }
    if (grid[dis_row][dis_col-1] != '|' && grid[dis_row][dis_col-1] != '=' && grid[dis_row][dis_col-1] != 'B' && dis_col != 0)
    {
        a[i]='a';
        i++;
    }
    //cout<<endl<<dis_row<<endl;
    if (grid[dis_row-1][dis_col] != '|' && grid[dis_row-1][dis_col] != '='&& grid[dis_row-1][dis_col] != 'B' && dis_row != 0)
    {
        a[i]='w';
        i++;
    }
    if (grid[dis_row+1][dis_col] != '|' && grid[dis_row+1][dis_col] != '='&& grid[dis_row+1][dis_col] != 'B' && dis_row != 10)
    {
        a[i]='s';
        i++;
    }
    cnt1=i;
    //for(int j=0;j<=i;j++)
    //cout<<endl<<a[j]<<',';
}
void level1::distructor2_position()
{
    //delete a;
    a[0]='\0';
    a[1]='\0';
    a[2]='\0';
    a[3]='\0';
    int i=0;
    if (grid[dis_row2][dis_col2+1] != '|' && grid[dis_row2][dis_col2+1] != '='&& grid[dis_row2][dis_col2+1] != 'B' && dis_col2 != 10 && grid[dis_row2][dis_col2+1] != '~')
    {
        a[i]='d';
        i++;
        //cout<<a[i];
    }
    if (grid[dis_row2][dis_col2-1] != '|' && grid[dis_row2][dis_col2-1] != '='&& grid[dis_row2][dis_col2-1] != 'B' && dis_col2 != 0 && grid[dis_row2][dis_col2-1] != '~')
    {
        a[i]='a';
        i++;
    }
    //cout<<endl<<dis_row<<endl;
    if (grid[dis_row2-1][dis_col2] != '|' && grid[dis_row2-1][dis_col2] != '='&& grid[dis_row2-1][dis_col2] != 'B' && dis_row2 != 0 && grid[dis_row2-1][dis_col2] != '~')
    {
        a[i]='w';
        i++;
    }
    if (grid[dis_row2+1][dis_col2] != '|' && grid[dis_row2+1][dis_col2] != '=' && grid[dis_row2+1][dis_col2] != 'B' && dis_row2 != 10 && grid[dis_row2+1][dis_col2] != '~')
    {
        a[i]='s';
        i++;
    }
    cnt1=i;
    //for(int j=0;j<=i;j++)
    //cout<<endl<<a[j]<<',';
}
void level1::distructor3_position()
{
    //delete a;
    a[0]='\0';
    a[1]='\0';
    a[2]='\0';
    a[3]='\0';
    int i=0;
    if (grid[dis_row3][dis_col3+1] != '|' && grid[dis_row3][dis_col3+1] != '='&& grid[dis_row3][dis_col3+1] != 'B' && dis_col3 != 10 && grid[dis_row3][dis_col3+1] != '~')
    {
        a[i]='d';
        i++;
        //cout<<a[i];
    }
    if (grid[dis_row3][dis_col3-1] != '|' && grid[dis_row3][dis_col3-1] != '='&& grid[dis_row3][dis_col3-1] != 'B' && dis_col3 != 0 && grid[dis_row3][dis_col3-1] != '~')
    {
        a[i]='a';
        i++;
    }
    //cout<<endl<<dis_row<<endl;
    if (grid[dis_row3-1][dis_col3] != '|' && grid[dis_row3-1][dis_col3] != '='&& grid[dis_row3-1][dis_col3] != 'B' && dis_row3 != 0 && grid[dis_row3-1][dis_col3] != '~')
    {
        a[i]='w';
        i++;
    }
    if (grid[dis_row3+1][dis_col3] != '|' && grid[dis_row3+1][dis_col3] != '='&& grid[dis_row3+1][dis_col3] != 'B' && dis_row3 != 10 && grid[dis_row3+1][dis_col3] != '~')
    {
        a[i]='s';
        i++;
    }
    cnt1=i;
    //for(int j=0;j<=i;j++)
    //cout<<endl<<a[j]<<',';
}
void level1::distructor4_position()
{
    //delete a;
    a[0]='\0';
    a[1]='\0';
    a[2]='\0';
    a[3]='\0';
    int i=0;
    if (grid[dis_row4][dis_col4+1] != '|' && grid[dis_row4][dis_col4+1] != '='&& grid[dis_row4][dis_col4+1] != 'B' && dis_col4 != 10 && grid[dis_row4][dis_col4+1] != '~')
    {
        a[i]='d';
        i++;
        //cout<<a[i];
    }
    if (grid[dis_row4][dis_col4-1] != '|' && grid[dis_row4][dis_col4-1] != '='&& grid[dis_row4][dis_col4-1] != 'B' && dis_col4 != 0 && grid[dis_row4][dis_col4-1] != '~')
    {
        a[i]='a';
        i++;
    }
    //cout<<endl<<dis_row<<endl;
    if (grid[dis_row4-1][dis_col4] != '|' && grid[dis_row4-1][dis_col4] != '='&& grid[dis_row4-1][dis_col4] != 'B' && dis_row4 != 0 && grid[dis_row4-1][dis_col4] != '~')
    {
        a[i]='w';
        i++;
    }
    if (grid[dis_row4+1][dis_col4] != '|' && grid[dis_row4+1][dis_col4] != '='&& grid[dis_row4+1][dis_col4] != 'B' && dis_row4 != 10 && grid[dis_row4+1][dis_col4] != '~')
    {
        a[i]='s';
        i++;
    }
    cnt1=i;
    //for(int j=0;j<=i;j++)
    //cout<<endl<<a[j]<<',';
}
void level1::distructor_movement(int dis_movement)
{
    srand( time(NULL) );
    //char dis_movement='s';
    //cout<<"coursor dis_movement :";
    //cin>>dis_movement
    if (dis_movement == 'd')
        {

            if (grid[dis_row][dis_col+1] != '|' && grid[dis_row][dis_col+1] != '=' && grid[dis_row][dis_col+1] != 'B' && dis_col != 10)
            {
                grid[dis_row][dis_col] = '\0';
                dis_col += 1;
                if (grid[dis_row][dis_col]=='*')
                {
                    dis_points+=1;
                    stars--;
                }
                else if (grid[dis_row][dis_col]=='$')
                {
                    dis_points+=2;
                    this->create_dis_freezer();
                }

                grid[dis_row][dis_col] = '~';
               dis1_movement=dis_movement;
               if(dis_row==row && dis_col==col)
               {
                   grid[dis_row][dis_col] = 'X';
                    eog = 'y';
               }
            }
            else
            {
                //int a[3]={'a','w','s'};
                int rand_index=rand() % cnt1;
                dis_movement=a[rand_index];
                //cout<<a[rand_index];
                this->distructor_movement(dis_movement);
            }
        }

        else if (dis_movement == 'a')
        {
            if (grid[dis_row][dis_col-1] != '|' && grid[dis_row][dis_col-1] != '=' && grid[dis_row][dis_col-1] != 'B' && dis_col != 0)
            {
                grid[dis_row][dis_col] = '\0';
                dis_col -= 1;
                //cout<<endl<<grid[dis_row][dis_col];
                if (grid[dis_row][dis_col]=='*')
                {
                    dis_points+=1;
                    stars--;
                    //cout<<endl<<grid[dis_row][dis_col];
                }
                else if (grid[dis_row][dis_col]=='$')
                {
                    dis_points+=2;
                    this->create_dis_freezer();
                }
                grid[dis_row][dis_col] = '~';
                dis1_movement=dis_movement;
                if(dis_row==row && dis_col==col)
               {
                   grid[dis_row][dis_col] = 'X';
                    eog = 'y';
               }
            }
            else
            {
                //int a[3]={'d','w','s'};
                int rand_index=rand() % cnt1;
                dis_movement=a[rand_index];
                //cout<<a[rand_index];
                this->distructor_movement(dis_movement);
            }
        }

        else if (dis_movement == 'w')
        {
            if (grid[dis_row-1][dis_col] != '|' && grid[dis_row-1][dis_col] != '='&& grid[dis_row-1][dis_col] != 'B' && dis_row != 0)
            {
                grid[dis_row][dis_col] = '\0';
                dis_row -= 1;
                if (grid[dis_row][dis_col]=='*')
                {
                    dis_points+=1;
                    stars--;
                }
                else if (grid[dis_row][dis_col]=='$')
                {
                    dis_points+=2;
                    this->create_dis_freezer();
                }
                grid[dis_row][dis_col] = '~';
                dis1_movement=dis_movement;
                if(dis_row==row && dis_col==col)
               {
                   grid[dis_row][dis_col] = 'X';
                    eog = 'y';
               }
            }
            else
            {
                //int a[3]={'a','d','s'};
                int rand_index=rand() % cnt1;
                dis_movement=a[rand_index];
                //<<a[rand_index];
                this->distructor_movement(dis_movement);
            }
        }

        else if (dis_movement == 's')
        {
            if (grid[dis_row+1][dis_col] != '|' && grid[dis_row+1][dis_col] != '='&& grid[dis_row+1][dis_col] != 'B' && dis_row != 10)
            {
                grid[dis_row][dis_col] = '\0';
                dis_row += 1;
                if (grid[dis_row][dis_col]=='*')
                {
                    dis_points+=1;
                    stars--;
                }
                else if (grid[dis_row][dis_col]=='$')
                {
                    dis_points+=2;
                    this->create_dis_freezer();
                }

                grid[dis_row][dis_col] = '~';
                dis1_movement=dis_movement;
                if(dis_row==row && dis_col==col)
               {
                   grid[dis_row][dis_col] = 'X';
                    eog = 'y';
               }
            }
            else
            {
                //int a[3]={'a','w','d'};
                int rand_index=rand() % cnt1;
                dis_movement=a[rand_index];
                //cout<<a[rand_index];
                this->distructor_movement(dis_movement);
            }
        }
}
void level1::distructor2_movement(int dis_movement)
{
    srand( time(NULL) );
    //char dis_movement='s';
    //cout<<"coursor dis_movement :";
    //cin>>dis_movement
    if (dis_movement == 'd')
        {

            if (grid[dis_row2][dis_col2+1] != '|' && grid[dis_row2][dis_col2+1] != '='&& grid[dis_row2][dis_col2+1] != 'B' && dis_col2 != 10 && grid[dis_row2][dis_col2+1] != '~')
            {
                grid[dis_row2][dis_col2] = '\0';
                dis_col2 += 1;
                if (grid[dis_row2][dis_col2]=='*')
                {
                    dis_points+=1;
                    stars--;
                }
                else if (grid[dis_row2][dis_col2]=='$')
                {
                    dis_points+=2;
                    this->create_dis_freezer();
                }

                grid[dis_row2][dis_col2] = '~';
               dis2_movement=dis_movement;
               if(dis_row2==row && dis_col2==col)
               {
                   grid[dis_row2][dis_col2] = 'X';
                    eog = 'y';
               }
            }
            else
            {
                //int a[3]={'a','w','s'};
                int rand_index=rand() % cnt1;
                dis_movement=a[rand_index];
                //cout<<a[rand_index];
                this->distructor2_movement(dis_movement);
            }
        }

        else if (dis_movement == 'a')
        {
            if (grid[dis_row2][dis_col2-1] != '|' && grid[dis_row2][dis_col2-1] != '='&& grid[dis_row2][dis_col2-1] != 'B' && dis_col2 != 0 && grid[dis_row2][dis_col2-1] != '~')
            {
                grid[dis_row2][dis_col2] = '\0';
                dis_col2 -= 1;
                //cout<<endl<<grid[dis_row2][dis_col2];
                if (grid[dis_row2][dis_col2]=='*')
                {
                    dis_points+=1;
                    stars--;
                    //cout<<endl<<grid[dis_row2][dis_col2];
                }
                else if (grid[dis_row2][dis_col2]=='$')
                {
                    dis_points+=2;
                    this->create_dis_freezer();
                }
                grid[dis_row2][dis_col2] = '~';
                dis2_movement=dis_movement;
                if(dis_row2==row && dis_col2==col)
               {
                   grid[dis_row2][dis_col2] = 'X';
                    eog = 'y';
               }
            }
            else
            {
                //int a[3]={'d','w','s'};
                int rand_index=rand() % cnt1;
                dis_movement=a[rand_index];
                //cout<<a[rand_index];
                this->distructor2_movement(dis_movement);
            }
        }

        else if (dis_movement == 'w')
        {
            if (grid[dis_row2-1][dis_col2] != '|' && grid[dis_row2-1][dis_col2] != '='&& grid[dis_row2-1][dis_col2] != 'B' && dis_row2 != 0 && grid[dis_row2-1][dis_col2] != '~')
            {
                grid[dis_row2][dis_col2] = '\0';
                dis_row2 -= 1;
                if (grid[dis_row2][dis_col2]=='*')
                {
                    dis_points+=1;
                    stars--;
                }
                else if (grid[dis_row2][dis_col2]=='$')
                {
                    dis_points+=2;
                    this->create_dis_freezer();
                }
                grid[dis_row2][dis_col2] = '~';
                dis2_movement=dis_movement;
                if(dis_row2==row && dis_col2==col)
               {
                   grid[dis_row2][dis_col2] = 'X';
                    eog = 'y';
               }
            }
            else
            {
                //int a[3]={'a','d','s'};
                int rand_index=rand() % cnt1;
                dis_movement=a[rand_index];
                //cout<<endl <<"a[]"<<a[rand_index];
                this->distructor2_movement(dis_movement);
            }
        }

        else if (dis_movement == 's')
        {
            if (grid[dis_row2+1][dis_col2] != '|' && grid[dis_row2+1][dis_col2] != '=' && grid[dis_row2+1][dis_col2] != 'B' && dis_row2 != 10 && grid[dis_row2+1][dis_col2] != '~')
            {
                grid[dis_row2][dis_col2] = '\0';
                dis_row2 += 1;
                if (grid[dis_row2][dis_col2]=='*')
                {
                    dis_points+=1;
                    stars--;
                }
                else if (grid[dis_row2][dis_col2]=='$')
                {
                    dis_points+=2;
                    this->create_dis_freezer();
                }

                grid[dis_row2][dis_col2] = '~';
                dis2_movement=dis_movement;
                if(dis_row2==row && dis_col2==col)
               {
                   grid[dis_row2][dis_col2] = 'X';
                    eog = 'y';
               }
            }
            else
            {
                //int a[3]={'a','w','d'};
                int rand_index=rand() % cnt1;
                dis_movement=a[rand_index];
                //cout<<endl <<"a[]"<<a[rand_index];
                this->distructor2_movement(dis_movement);
            }
        }
}
void level1::distructor3_movement(int dis_movement)
{
    srand( time(NULL) );
    //char dis_movement='s';
    //cout<<"coursor dis_movement :";
    //cin>>dis_movement
    if (dis_movement == 'd')
        {

            if (grid[dis_row3][dis_col3+1] != '|' && grid[dis_row3][dis_col3+1] != '='&& grid[dis_row3][dis_col3+1] != 'B' && dis_col3 != 10 && grid[dis_row3][dis_col3+1] != '~')
            {
                grid[dis_row3][dis_col3] = '\0';
                dis_col3 += 1;
                if (grid[dis_row3][dis_col3]=='*')
                {
                    dis_points+=1;
                    stars--;
                }
                else if (grid[dis_row3][dis_col3]=='$')
                {
                    dis_points+=2;
                    this->create_dis_freezer();
                }

                grid[dis_row3][dis_col3] = '~';
               dis3_movement=dis_movement;
               if(dis_row3==row && dis_col3==col)
               {
                   grid[dis_row3][dis_col3] = 'X';
                    eog = 'y';
               }
            }
            else
            {
                //int a[3]={'a','w','s'};
                int rand_index=rand() % cnt1;
                dis_movement=a[rand_index];
                //cout<<a[rand_index];
                this->distructor3_movement(dis_movement);
            }
        }

        else if (dis_movement == 'a')
        {
            if (grid[dis_row3][dis_col3-1] != '|' && grid[dis_row3][dis_col3-1] != '='&& grid[dis_row3][dis_col3-1] != 'B' && dis_col3 != 0 && grid[dis_row3][dis_col3-1] != '~')
            {
                grid[dis_row3][dis_col3] = '\0';
                dis_col3 -= 1;
                //cout<<endl<<grid[dis_row3][dis_col3];
                if (grid[dis_row3][dis_col3]=='*')
                {
                    dis_points+=1;
                    stars--;
                    //cout<<endl<<grid[dis_row3][dis_col3];
                }
                else if (grid[dis_row3][dis_col3]=='$')
                {
                    dis_points+=2;
                    this->create_dis_freezer();
                }
                grid[dis_row3][dis_col3] = '~';
                dis3_movement=dis_movement;
                if(dis_row3==row && dis_col3==col)
               {
                   grid[dis_row3][dis_col3] = 'X';
                    eog = 'y';
               }
            }
            else
            {
                //int a[3]={'d','w','s'};
                int rand_index=rand() % cnt1;
                dis_movement=a[rand_index];
                //cout<<a[rand_index];
                this->distructor3_movement(dis_movement);
            }
        }

        else if (dis_movement == 'w')
        {
            if (grid[dis_row3-1][dis_col3] != '|' && grid[dis_row3-1][dis_col3] != '='&& grid[dis_row3-1][dis_col3] != 'B' && dis_row3 != 0 && grid[dis_row3-1][dis_col3] != '~')
            {
                grid[dis_row3][dis_col3] = '\0';
                dis_row3 -= 1;
                if (grid[dis_row3][dis_col3]=='*')
                {
                    dis_points+=1;
                    stars--;
                }
                else if (grid[dis_row3][dis_col3]=='$')
                {
                    dis_points+=2;
                    this->create_dis_freezer();
                }
                grid[dis_row3][dis_col3] = '~';
                dis3_movement=dis_movement;
                if(dis_row3==row && dis_col3==col)
               {
                   grid[dis_row3][dis_col3] = 'X';
                    eog = 'y';
               }
            }
            else
            {
                //int a[3]={'a','d','s'};
                int rand_index=rand() % cnt1;
                dis_movement=a[rand_index];
                //cout<<endl <<"a[]"<<a[rand_index];
                this->distructor3_movement(dis_movement);
            }
        }

        else if (dis_movement == 's')
        {
            if (grid[dis_row3+1][dis_col3] != '|' && grid[dis_row3+1][dis_col3] != '='&& grid[dis_row3+1][dis_col3] != 'B' && dis_row3 != 10 && grid[dis_row3+1][dis_col3] != '~')
            {
                grid[dis_row3][dis_col3] = '\0';
                dis_row3 += 1;
                if (grid[dis_row3][dis_col3]=='*')
                {
                    dis_points+=1;
                    stars--;
                }
                else if (grid[dis_row3][dis_col3]=='$')
                {
                    dis_points+=2;
                    this->create_dis_freezer();
                }

                grid[dis_row3][dis_col3] = '~';
                dis3_movement=dis_movement;
                if(dis_row3==row && dis_col3==col)
               {
                   grid[dis_row3][dis_col3] = 'X';
                    eog = 'y';
               }
            }
            else
            {
                //int a[3]={'a','w','d'};
                int rand_index=rand() % cnt1;
                dis_movement=a[rand_index];
                //cout<<endl <<"a[]"<<a[rand_index];
                this->distructor3_movement(dis_movement);
            }
        }
}
void level1::distructor4_movement(int dis_movement)
{
    srand( time(NULL) );
    //char dis_movement='s';
    //cout<<"coursor dis_movement :";
    //cin>>dis_movement
    if (dis_movement == 'd')
        {

            if (grid[dis_row4][dis_col4+1] != '|' && grid[dis_row4][dis_col4+1] != '='&& grid[dis_row4][dis_col4+1] != 'B' && dis_col4 != 10 && grid[dis_row4][dis_col4+1] != '~')
            {
                grid[dis_row4][dis_col4] = '\0';
                dis_col4 += 1;
                if (grid[dis_row4][dis_col4]=='*')
                {
                    dis_points+=1;
                    stars--;
                }
                else if (grid[dis_row4][dis_col4]=='$')
                {
                    dis_points+=2;
                    this->create_dis_freezer();
                }

                grid[dis_row4][dis_col4] = '~';
               dis4_movement=dis_movement;
               if(dis_row4==row && dis_col4==col)
               {
                   grid[dis_row4][dis_col4] = 'X';
                    eog = 'y';
               }
            }
            else
            {
                //int a[3]={'a','w','s'};
                int rand_index=rand() % cnt1;
                dis_movement=a[rand_index];
                //cout<<a[rand_index];
                this->distructor4_movement(dis_movement);
            }
        }

        else if (dis_movement == 'a')
        {
            if (grid[dis_row4][dis_col4-1] != '|' && grid[dis_row4][dis_col4-1] != '='&& grid[dis_row4][dis_col4-1] != 'B' && dis_col4 != 0 && grid[dis_row4][dis_col4-1] != '~')
            {
                grid[dis_row4][dis_col4] = '\0';
                dis_col4 -= 1;
                //cout<<endl<<grid[dis_row4][dis_col4];
                if (grid[dis_row4][dis_col4]=='*')
                {
                    dis_points+=1;
                    stars--;
                    //cout<<endl<<grid[dis_row4][dis_col4];
                }
                else if (grid[dis_row4][dis_col4]=='$')
                {
                    dis_points+=2;
                    this->create_dis_freezer();
                }
                grid[dis_row4][dis_col4] = '~';
                dis4_movement=dis_movement;
                if(dis_row4==row && dis_col4==col)
               {
                   grid[dis_row4][dis_col4] = 'X';
                    eog = 'y';
               }
            }
            else
            {
                //int a[3]={'d','w','s'};
                int rand_index=rand() % cnt1;
                dis_movement=a[rand_index];
               // cout<<a[rand_index];
                this->distructor4_movement(dis_movement);
            }
        }

        else if (dis_movement == 'w')
        {
            if (grid[dis_row4-1][dis_col4] != '|' && grid[dis_row4-1][dis_col4] != '='&& grid[dis_row4-1][dis_col4] != 'B' && dis_row4 != 0 && grid[dis_row4-1][dis_col4] != '~')
            {
                grid[dis_row4][dis_col4] = '\0';
                dis_row4 -= 1;
                if (grid[dis_row4][dis_col4]=='*')
                {
                    dis_points+=1;
                    stars--;
                }
                else if (grid[dis_row4][dis_col4]=='$')
                {
                    dis_points+=2;
                    this->create_dis_freezer();
                }
                grid[dis_row4][dis_col4] = '~';
                dis4_movement=dis_movement;
                if(dis_row4==row && dis_col4==col)
               {
                   grid[dis_row4][dis_col4] = 'X';
                    eog = 'y';
               }
            }
            else
            {
                //int a[3]={'a','d','s'};
                int rand_index=rand() % cnt1;
                dis_movement=a[rand_index];
                //cout<<endl <<"a[]"<<a[rand_index];
                this->distructor4_movement(dis_movement);
            }
        }

        else if (dis_movement == 's')
        {
            if (grid[dis_row4+1][dis_col4] != '|' && grid[dis_row4+1][dis_col4] != '='&& grid[dis_row4+1][dis_col4] != 'B' && dis_row4 != 10 && grid[dis_row4+1][dis_col4] != '~')
            {
                grid[dis_row4][dis_col4] = '\0';
                dis_row4 += 1;
                if (grid[dis_row4][dis_col4]=='*')
                {
                    dis_points+=1;
                    stars--;
                }
                else if (grid[dis_row4][dis_col4]=='$')
                {
                    dis_points+=2;
                    this->create_dis_freezer();
                }

                grid[dis_row4][dis_col4] = '~';
                dis4_movement=dis_movement;
                if(dis_row4==row && dis_col4==col)
               {
                   grid[dis_row4][dis_col4] = 'X';
                    eog = 'y';
               }
            }
            else
            {
                //int a[3]={'a','w','d'};
                int rand_index=rand() % cnt1;
                dis_movement=a[rand_index];
                //cout<<endl <<"a[]"<<a[rand_index];
                this->distructor4_movement(dis_movement);
            }
        }
}
void level1::coursor_position()
{
    char movement ;
    cout<<"coursor movement :";
    cin>>movement;
    if (movement == 'd')
        {
            if (grid[row][col+1] != '|' && grid[row][col+1] != '=' && grid[row][col+1] != 'B' && col != 10 && grid[row][col+1]!='~')
            {
                //cout<<"in1";
                grid[row][col] = '\0';
                col += 1;
                if (grid[row][col]=='*')
                {
                   // cout<<"in2";
                    points+=1;
                    stars--;
                }
                else if (grid[row][col]=='$')
                {
                   // cout<<"in3";
                    points+=2;
                    dis_freezecnt=5;
                    this->create_dis_freezer();
                }
                grid[row][col] = '<';
            }
            else
            {
                //cout<<"in4";
                grid[row][col] = 'X';
                eog = 'y';
            }
        }

        else if (movement == 'a')
        {
            if (grid[row][col-1] != '|' && grid[row][col-1] != '=' && grid[row][col-1] != 'B' && col != 0 && grid[row][col-1] != '~')
            {
                grid[row][col] = '\0';
                col -= 1;
                if (grid[row][col]=='*')
                {
                    points+=1;
                    stars--;
                }
                else if (grid[row][col]=='$')
                {
                    points+=2;
                    dis_freezecnt=5;
                    this->create_dis_freezer();
                }
                grid[row][col] = '>';
            }
            else
            {
                grid[row][col] = 'X';
                eog = 'y';
            }
        }

        else if (movement == 'w')
        {
            if (grid[row-1][col] != '|' && grid[row-1][col] != '=' && grid[row-1][col] != 'B' && row != 0 && grid[row-1][col] != '~')
            {
                grid[row][col] = '\0';
                row -= 1;
                if (grid[row][col]=='*')
                {
                    points+=1;
                    stars--;
                }
                else if (grid[row][col]=='$')
                {
                    points+=2;
                    dis_freezecnt=5;
                    this->create_dis_freezer();
                }
                grid[row][col] = 'V';
            }
            else
            {
                grid[row][col] = 'X';
                eog = 'y';
            }
        }

        else if (movement == 's')
        {
            if (grid[row+1][col] != '|' && grid[row+1][col] != '=' && grid[row+1][col] != 'B' && row != 10 && grid[row+1][col] != '~')
            {
                grid[row][col] = '\0';
                row += 1;
                if (grid[row][col]=='*')
                {
                    points+=1;
                    stars--;
                }
                else if (grid[row][col]=='$')
                {
                    points+=2;
                    dis_freezecnt=5;
                    this->create_dis_freezer();

                }
                grid[row][col] = 'M';
            }
            else
            {
                grid[row][col] = 'X';
                eog = 'y';
            }
        }
        //cout<<"called \n";
        //cout<<this->dis1_movement<<'123'<<endl;
        if(dis_freezecnt==0)
        {
            if (l>=1)
            {
                //cout<<"row1="<<dis_row<<"col1="<<dis_col<<endl;
                //cout<<"enter"<<endl;
                //level1 *p,l1dis;
                //p=&l1dis;
                this->distructor_position();
                this->distructor_movement(dis1_movement);
                //cout<<"row2="<<dis_row<<"col2="<<dis_col<<endl;
            }
            if (l>=2)
            {
                //level2 *p,l2dis;
                //p=&l2dis;
                this->distructor2_position();
                this->distructor2_movement(dis2_movement);
            }
            if (l>=3)
            {
                //level2 *p,l2dis;
                //p=&l2dis;
                this->distructor3_position();
                this->distructor3_movement(dis3_movement);
            }
            if (l>=4)
            {
                //level2 *p,l2dis;
                //p=&l2dis;
                this->distructor4_position();
                this->distructor4_movement(dis4_movement);
            }
        }
        else if(dis_freezecnt>0)
        dis_freezecnt--;

        if (l>=5)
        {
            if(bomb_timer==4)
                    {
                        if(grid[bomb_row+1][bomb_col] == '<' ||grid[bomb_row+1][bomb_col] == '>'||
                            grid[bomb_row+1][bomb_col] == 'V'||grid[bomb_row+1][bomb_col] == 'M'||

                            grid[bomb_row+1][bomb_col-1] == '<'||grid[bomb_row+1][bomb_col-1] == '>'||
                            grid[bomb_row+1][bomb_col-1] == 'V'||grid[bomb_row+1][bomb_col-1] == 'M'||

                            grid[bomb_row+1][bomb_col+1] == '<' ||grid[bomb_row+1][bomb_col+1] == '>'||
                            grid[bomb_row+1][bomb_col+1] == 'V'||grid[bomb_row+1][bomb_col+1] == 'M'||

                            grid[bomb_row-1][bomb_col] == '<'||grid[bomb_row-1][bomb_col] == '>'||
                            grid[bomb_row-1][bomb_col] == 'V'||grid[bomb_row-1][bomb_col] == 'M'||

                            grid[bomb_row-1][bomb_col-1] == '<'||grid[bomb_row-1][bomb_col-1] == '>'||
                            grid[bomb_row-1][bomb_col-1] == 'V'||grid[bomb_row-1][bomb_col-1] == 'M'||

                            grid[bomb_row-1][bomb_col+1] == '<'||grid[bomb_row-1][bomb_col+1] == '>'||
                            grid[bomb_row-1][bomb_col+1] == 'V'||grid[bomb_row-1][bomb_col+1] == 'M'||

                            grid[bomb_row][bomb_col+1] == '<'||grid[bomb_row][bomb_col+1] == '>'||
                            grid[bomb_row][bomb_col+1] == 'V'||grid[bomb_row][bomb_col+1] == 'M'||

                            grid[bomb_row][bomb_col-1] == '<'||grid[bomb_row][bomb_col-1] == '>'||
                            grid[bomb_row][bomb_col-1] == 'V'||grid[bomb_row][bomb_col-1] == 'M' )
                        {
                            eog='y';
                            grid[bomb_row+1][bomb_col] = 'b';
                            grid[bomb_row+1][bomb_col-1] ='b';
                            grid[bomb_row+1][bomb_col+1] = 'b';
                            grid[bomb_row-1][bomb_col] = 'b';
                            grid[bomb_row-1][bomb_col-1] = 'b';
                            grid[bomb_row-1][bomb_col+1] = 'b';
                            grid[bomb_row][bomb_col-1] = 'b';
                            grid[bomb_row][bomb_col+1] = 'b';
                            grid[row][col]='X';

                        }
                        else
                        {
                            grid[bomb_row][bomb_col] ='\0';
                            this->create_bomb();
                            bomb_timer=0;
                        }
                    }
                else
                bomb_timer++;
        }

}
void level1::grid_design()
{
    grid[2][1]='|';grid[3][1]='|';grid[4][1]='|';
    grid[1][1]='=';grid[1][2]='=';
    grid[6][1]='|';grid[7][1]='|';grid[8][1]='|';
    grid[9][1]='=';grid[9][2]='=';
    grid[2][9]='|';grid[3][9]='|';grid[4][9]='|';
    grid[1][8]='=';grid[1][9]='=';
    grid[6][9]='|';grid[7][9]='|';grid[8][9]='|';
    grid[9][8]='=';grid[9][9]='=';
    grid[0][4]='|';grid[1][4]='|';grid[10][4]='|';
    grid[9][4]='|';grid[0][6]='|';grid[1][6]='|';
    grid[10][6]='|';grid[9][6]='|';grid[4][4]='|';
    grid[5][4]='|';grid[6][4]='|';grid[4][6]='|';
    grid[5][6]='|';grid[6][6]='|';
    grid[3][4]='=';grid[3][6]='=';
    grid[7][4]='=';grid[7][6]='=';
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
             if (grid[i][j] == '\0'){
            grid[i][j]='*';
            stars++;
             }
        }
    }
    stars-=2;
    grid[0][0]='<';
    grid[dis_row][dis_col]='~';
    this->create_dis_freezer();
    grid[freezer_row][freezer_col]='$';
}
void level1::grid_print()
{
    //cout<<stars<<endl;
    if(!stars){
        eol = 'y';

    }
    if(eog=='n'){
        cout<<endl<<"\t\tPOINTS GAINED:\t"<<points<<endl;
        cout<<endl<<"\t\tPOINTS LOST:\t"<<dis_points<<endl;
    }
    else{
        cout<<endl<<"\t\tFINAL SCORE:\t"<<points<<endl;
    }
    cout<<" ________________ ";
        cout<<endl;
        for (int i = 0; i < 11; i++)
        {
            cout<<"|";
            for (int j = 0; j < 11; j++)
            {
                if (grid[i][j] != '\0')
                    cout<<" "<< grid[i][j]<<"  ";

                 else
                    cout<<"  "<< grid[i][j]<<"  ";
            }
            cout<<"|";
            cout<<endl;
        }
        cout<<"----------------------------------------------";
        cout<<endl;
}
class level2: public level1
{
    protected:
    public:
    void grid_design2();
};
void level2::grid_design2()
{
        grid[0][2]='|';grid[0][5]='|';grid[0][6]='=';grid[0][7]='|';
        grid[0][8]='|';
        grid[1][2]='|';grid[1][5]='=';grid[1][6]='|';grid[1][7]='|';
        grid[1][8]='|';
        grid[2][2]='|';grid[2][5]='|';grid[2][6]='=';grid[2][7]='|';
        grid[2][8]='|';
        grid[3][2]='=';grid[3][5]='|';grid[3][6]='|';grid[3][7]='|';
        grid[3][8]='|';grid[3][10]='=';
        grid[4][2]='|';grid[4][5]='|';grid[4][6]='=';grid[4][7]='|';
        grid[4][8]='|';
        grid[5][0]='=';grid[5][6]='|';grid[5][7]='|';
        grid[6][0]='|';grid[6][4]='|';grid[6][6]='|';grid[6][7]='|';
        grid[6][10]='|';
        grid[7][0]='|';grid[7][1]='=';grid[7][2]='|';grid[7][4]='|';
        grid[7][6]='|';grid[7][7]='|';grid[7][10]='|';
        grid[8][0]='=';grid[8][1]='|';grid[8][4]='=';grid[8][6]='|';
        grid[8][9]='|';grid[8][10]='|';
        grid[9][0]='|';grid[9][1]='=';grid[9][2]='|';grid[9][3]='|';
        grid[9][4]='|';grid[9][6]='|';grid[9][8]='=';grid[9][9]='|';
        grid[9][10]='|';
        grid[10][0]='|';grid[10][1]='=';grid[10][2]='|';grid[10][3]='|';
        grid[10][4]='=';grid[10][9]='|';grid[10][10]='|';


        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                if (grid[i][j] == '\0')
                {
                    grid[i][j]='*';
                    *s=(*s)+1;
                    //cout<<"stars:"<<*s<<endl;
                }
            }
        }
        dis_row=0;dis_col=10;dis1_movement='a';
        *s=(*s)-3;
        grid[0][0]='<';
        grid[dis_row][dis_col]='~';
        grid[dis_row2][dis_col2]='~';
        this->create_dis_freezer();
        grid[freezer_row][freezer_col]='$';
}
class level3: public level2
{
public:
      void grid_design3();
};
void level3 :: grid_design3()
      {
          grid[0][5]='|';grid[0][6]='|';grid[0][9]='|';
     grid[1][0]='|';grid[1][3]='|';grid[1][5]='|';grid[1][6]='|';grid[1][9]='|';
     grid[2][3]='|';grid[2][5]='|';grid[2][6]='|';grid[2][9]='|';
     grid[3][1]='|';grid[3][3]='|';grid[3][5]='|';grid[3][6]='|';grid[3][9]='|';
     grid[4][1]='|';grid[4][3]='|';grid[4][5]='|';grid[4][6]='|';
     grid[5][1]='|';grid[5][3]='|';grid[5][5]='|';grid[5][6]='|';grid[5][10]='|';
     grid[6][1]='|';grid[6][5]='|';grid[6][6]='|';grid[6][10]='|';
     grid[7][4]='|';grid[7][10]='|';
     grid[8][0]='|';grid[8][4]='|';grid[8][6]='|';grid[8][10]='|';
     grid[9][0]='|';grid[9][4]='|';grid[9][7]='|';grid[9][10]='|';
     grid[10][0]='|';grid[10][6]='|';grid[10][10]='|';



      for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
             if (grid[i][j] == '\0')
             {
                grid[i][j]='*';
                *s=(*s)+1;
                //cout<<"stars:"<<*s<<endl;
             }
        }
    }
    dis_row=0;dis_col=10;dis1_movement='a';
    dis_row2=7;dis_col2=5;dis2_movement='s';
    *s=(*s)-4;
    grid[0][0]='<';
    grid[dis_row][dis_col]='~';
    grid[dis_row2][dis_col2]='~';
    grid[dis_row3][dis_col3]='~';
    this->create_dis_freezer();
    grid[freezer_row][freezer_col]='$';
    }
class level4: public level3
{
    public:
    void grid_design4();

};
void level4 :: grid_design4()
{
    grid[0][1]='|';grid[0][2]='|';
    grid[1][2]='|';grid[1][4]='|';grid[1][5]='|';
    grid[2][0]='|';grid[2][2]='|';grid[2][4]='|';
    grid[2][5]='|';grid[2][9]='|';grid[2][10]='|';
    grid[3][0]='|';grid[3][5]='|';grid[3][9]='|';
    grid[4][0]='|';grid[4][2]='|';grid[4][3]='|';grid[4][7]='|';
    grid[5][2]='|';grid[5][3]='|';grid[5][5]='|';grid[5][6]='|';
    grid[5][10]='|';
    grid[6][2]='|';grid[6][3]='|';grid[6][8]='|';grid[6][9]='|';
    grid[6][10]='|';
    grid[7][0]='|';grid[7][2]='|';grid[7][3]='|';
    grid[7][6]='|';
    grid[7][7]='|';grid[7][8]='|';grid[7][9]='|';grid[7][10]='|';
    grid[8][0]='|';grid[8][2]='|';grid[8][5]='|';grid[8][6]='|';
    grid[8][7]='|';
    grid[8][8]='|';grid[8][9]='|';grid[8][10]='|';
    grid[9][0]='|';grid[9][2]='|';grid[9][4]='|';grid[9][5]='|';
    grid[9][6]='|';grid[9][7]='|';
    grid[9][8]='|';grid[9][9]='|';grid[9][10]='|';
    grid[10][0]='|';grid[10][4]='|';grid[10][5]='|';grid[10][6]='|';
    grid[10][7]='|';grid[10][8]='|';
    grid[10][9]='|';grid[10][10]='|';

    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
             if (grid[i][j] == '\0')
             {
                grid[i][j]='*';
                *s=(*s)+1;
                //cout<<"stars:"<<*s<<endl;
             }
        }
    }
    dis_row=0;dis_col=10;dis1_movement='a';
    dis_row2=7;dis_col2=5;dis2_movement='s';
    dis_row3=10;dis_col3=1;dis3_movement='d';
    *s=(*s)-5;
    grid[0][0]='<';
    grid[dis_row][dis_col]='~';
    grid[dis_row2][dis_col2]='~';
    grid[dis_row3][dis_col3]='~';
    grid[dis_row4][dis_col4]='~';
    this->create_dis_freezer();
    grid[freezer_row][freezer_col]='$';
}
class level5: public level4
{
public:
      void grid_design5();

};
void level5 :: grid_design5()
    {
        grid[0][1]='|';grid[0][6]='|';grid[0][7]='=';
        grid[1][1]='=';grid[1][7]='|';grid[1][9]='|';
        grid[2][3]='|';grid[2][5]='=';grid[2][9]='|';
        grid[3][0]='|';grid[3][3]='|';grid[3][8]='=';grid[3][9]='|';
        grid[4][6]='|';grid[4][8]='=';
        grid[5][1]='|';grid[5][3]='|';grid[5][6]='=';
        grid[6][3]='=';grid[6][5]='|';grid[6][6]='|';grid[6][7]='=';
        grid[6][8]='|';grid[6][9]='|';
        grid[7][0]='|';grid[7][3]='=';grid[7][9]='|';
        grid[8][0]='|';grid[8][6]='|';grid[8][7]='=';grid[8][9]='|';
        grid[9][2]='=';grid[9][3]='|';grid[9][4]='|';grid[9][7]='|';
        grid[10][10]='|';
        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                if (grid[i][j] == '\0')
                {
                    grid[i][j]='*';
                    *s=(*s)+1;
                    //cout<<"stars:"<<*s<<endl;
                }
            }
        }
        dis_row=0;dis_col=10;dis1_movement='a';
        dis_row2=7;dis_col2=5;dis2_movement='s';
        dis_row3=10;dis_col3=1;dis3_movement='d';
        dis_row4=3;dis_col4=3;dis4_movement='w';
        *s=(*s)-5;
        grid[0][0]='<';
        grid[dis_row][dis_col]='~';
        grid[dis_row2][dis_col2]='~';
        grid[dis_row3][dis_col3]='~';
        grid[dis_row4][dis_col4]='~';
        this->create_dis_freezer();
        this->create_bomb();
        grid[freezer_row][freezer_col]='$';
    }

int main()
{

//level 1


    level5 obj;
    cout<<endl<<"\t\t     LEVEL-1\t"<<endl;
    obj.base_grid();
    obj.grid_design();
    obj.grid_print();
    while(eol == 'n'&&eog=='n')
    {
        obj.coursor_position();
        //obj.distructor_call();
        obj.grid_print();
    }


//level 2


    if(eol=='y'&&eog=='n')
    {
        level5 obj;
        cout<<"\t\t\tLEVEL-2\t"<<endl;
        l=2;
        obj.base_grid();
        obj.grid_design2();
        obj.grid_print();
        eol='n';
        while(eol == 'n'&&eog=='n')
        {
            obj.coursor_position();
            //obj.distructor_call();
            obj.grid_print();
        }
    }


    //level 3


    if(eol=='y'&&eog=='n')
    {
        level5 obj;
        cout<<"\t\t\tLEVEL-3\t"<<endl;
        l=3;
        obj.base_grid();
        obj.grid_design3();
        obj.grid_print();
        eol='n';
        while(eol == 'n'&&eog=='n')
        {
            obj.coursor_position();
            obj.grid_print();
        }
    }


    //level 4


    if(eol=='y'&&eog=='n')
    {
        level5 obj;
        cout<<"\t\t\tLEVEL-4\t"<<endl;
        l=4;
        obj.base_grid();
        obj.grid_design4();
        obj.grid_print();
        eol='n';
        while(eol == 'n'&&eog=='n')
        {
            obj.coursor_position();
            obj.grid_print();
        }
    }


    //level 5


    if(eol=='y'&&eog=='n')
    {
        level5 obj;
        cout<<"\t\t\tLEVEL-5\t"<<endl;
        l=5;
        obj.base_grid();
        obj.grid_design5();
        obj.grid_print();
        eol='n';
        while(eol == 'n'&&eog=='n')
        {
            obj.coursor_position();
            obj.grid_print();
        }
    }
}
