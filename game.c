#include <GL/gl.h>
#include <GL/glut.h>
#include <ctime>
#include "game.h"

int gridx, gridy;
int food =1;
int foodX,foodY;
short sDirection  = RIGHT ;
extern int gameOver;

int posX= 20  , posY = 20  ;

void initGrid(int x, int y)//initialize the grid coordinates
{
    gridx = x;
    gridy = y;
}

void drawGrid()
{
    for(int x=0;x<gridx;x++)
    {
        for(int y=0;y<gridy;y++)
        {
            unit(x,y);//draw the hole grid
        }
    }
}

void unit(int x, int y) //one closed square will formed
{
    if(x==0 || y==0 || x==gridx-1 || y==gridy-1)
    {
        glLineWidth(3.0); //set the thickness of the edge line
        glColor3f(1.0,0.0,0.0); // set the color of the edge to be red
    }
    else
    {
        glLineWidth(1.0); //set the thickness of the line
        glColor3f(1.0,1.0,1.0);//set the color of the line to be white
    }

    glBegin(GL_POLYGON);  //line_loop mean connected ends
        glVertex2f(x,y); //first point of the square
        glVertex2f(x+1,y); //second point
        glVertex2f(x+1,y+1);//third point
        glVertex2f(x,y+1); //forth point
    glEnd();
}
void drawFood()
{

    if(food)
        random(foodX,foodY);
    food=0;
    glRectf(foodX,foodY,foodX+1,foodY+1);

}

void drawSnake()
{
    if(sDirection == UP)
        posY++ ;
    else if(sDirection == DOWN)
        posY--;
    else if(sDirection == RIGHT)
        posX++;
    else if(sDirection == LEFT)
        posX--;
        glColor3f(0.0,1.0,0.0);
    glRectd(posX , posY , posX+1 , posY+1);
    if(posX==0 || posX == gridx-1 || posY ==0 || posY == gridy-1)
        gameOver=1;
        if (posX==foodX && posY==foodY)
            food=1;

}

void random(int &x,int&y)
{
    int _maxX = gridx-2;
    int _maxY = gridy-2
    int _min=1;
    srand(time(NULL));
    x= _min+rand()% (_maxX-_min);
    y= _min+rand()% (_maxY-_min);

}



