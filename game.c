#include <GL/gl.h>
#include <GL/glut.h>
#include "game.h"

int gridx, gridy;

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
