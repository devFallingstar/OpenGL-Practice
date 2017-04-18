//
//  main.c
//  test1
//
//  Created by Fallingstar on 2017. 3. 14..
//  Copyright © 2017년 Fallingstar. All rights reserved.
//
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <stdio.h>
#include <stdlib.h>
#include <GLUT/GLUT.h>
#include <time.h>

void init();
void display();
void timer(int i);

static double delay = 0.000001;
static double x=0,y=0;
static double xinc, yinc;

int main(int argc, const char * argv[]) {
    glutInit(&argc, (char**)argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("YS's First OpenGL program");
    glutDisplayFunc(display);
    glutTimerFunc(delay, timer, 0);
    
    init();
    glutMainLoop();
    
    return 0;
}

void init(){
    srand((unsigned int)time(0));
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(0, 50, 0, 50);
    glClear(GL_COLOR_BUFFER_BIT);
    printf("init");
    x = rand()%50;
    y = rand()%50;
    xinc = (double)((rand()%21)-10)/100;
    yinc = (double)((rand()%21)-10)/100;
    printf("%f, %f, %f, %f\n", x,y,xinc,yinc);
}
void display(){
    x = x+xinc;
    y = y+yinc;
    
    glColor3f(x/50.0, y/50.0, 0);
    
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    if (x <= 0.0 || x >= 50.0) {
        xinc = -xinc;
    }
    if (y <= 0.0 || y >= 50.0) {
        yinc = -yinc;
    }
    glEnd();
    
    glFlush();
}

void timer(int t){
    glutPostRedisplay();
    glutTimerFunc(delay, timer, t);
}
