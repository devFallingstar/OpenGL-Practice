//
//  main.c
//  Prog06
//
//  Created by Fallingstar on 2017. 3. 21..
//  Copyright © 2017년 Fallingstar. All rights reserved.
//
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <stdio.h>
#include <GLUT/glut.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 50.0

void display();
void init();
void timer(int t);

static double delay = 1;
static double x[3]={0,},y[3]={0,};
static double xinc[3], yinc[3];

int main(int argc, const char * argv[]) {
    glutInitWindowSize(500, 500);
    glutCreateWindow("Prog06 - bouncing triangle");
    glutDisplayFunc(display);
    glutTimerFunc(delay, timer, 0);
    
    init();
    glutMainLoop();
    
    return 0;
}

void init(){
    int i;
    
    srand((unsigned int)time(0));
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(0, MAXSIZE, 0, MAXSIZE);
    glClear(GL_COLOR_BUFFER_BIT);
    
    for (i = 0; i < 3; i++) {
        x[i] = rand()%(int)MAXSIZE;
        y[i] = rand()%(int)MAXSIZE;
        xinc[i] = (double)((rand()%21)-10)/100;
        yinc[i] = (double)((rand()%21)-10)/100;
    }
    
}

void display(){
    int i;
    
    for (i = 0; i < 3; i++) {
        x[i] += xinc[i];
        y[i] += yinc[i];
        
        glColor3f(x[i]/MAXSIZE, y[i]/MAXSIZE, (x[i]+y[i])/MAXSIZE);
    }
    
    glBegin(GL_TRIANGLES);
    for (i = 0; i < 3; i++) {
        glVertex2f(x[i], y[i]);
        
        if (x[i] <= 0.0 || x[i] >= 50.0) {
            xinc[i] = -xinc[i];
        }
        if (y[i] <= 0.0 || y[i] >= 50.0) {
            yinc[i] = -yinc[i];
        }
    }
    
    glEnd();
    
    glFlush();
}

void timer(int t){
    glutPostRedisplay();
    glutTimerFunc(delay, timer, t);
}

