//
//  main.c
//  Prog10
//
//  Created by Fallingstar on 2017. 3. 23..
//  Copyright © 2017년 Fallingstar. All rights reserved.
//

#define RADIAN 3.14/180

#include <stdio.h>
#include <GLUT/GLUT.h>
#include <math.h>

void init();
void display();
void timer1();
void timer2();

static double theta = 0;
static double thetainc = 5;
static int delay = 30;

int main(int argc, const char * argv[]) {
    glutInit(&argc, (char**)argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Prog10 - image in 3D");
    glutDisplayFunc(display);
    glutTimerFunc(delay, timer1, 0);
    
    init();
    glutMainLoop();
    
    
    return 0;
}

void init(){
    glClearColor(1, 1, 1, 1);
    glOrtho(0.0, 416.0, 0.0, 240.0, -500.0, 500.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPointSize(8);
}

void display(){
    int i,j;
    float x,y,z;
    
    static unsigned char buff[240][416];
    FILE *fpt = fopen("testo.y", "rb");
    fread(buff, 416*240, sizeof(char), fpt);
    fclose(fpt);
    
    glBegin(GL_POINTS);
    for (i = 0; i < 240; i++) {
        for (j = 0; j < 416; j++) {
            glColor3f(buff[i][j]/255.0, buff[i][j]/255.0, buff[i][j]/255.0);
            x = j;
            y = i;
            
            x = x*cos(theta*RADIAN);
            y = 239 - y;
            z = x*sin(theta*RADIAN);
            
            glVertex3f(x, y, z);
        }
    }
    glEnd();
    glFlush();
}
void timer1(){
    
    if (theta <= 80) {
        theta += thetainc;
        glutPostRedisplay();
        glutTimerFunc(delay, timer1, 0);
    }else{
        glutPostRedisplay();
        glutTimerFunc(delay, timer2, 0);
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void timer2(){
    
    if (theta >= 0) {
        theta -= thetainc;
        glutPostRedisplay();
        glutTimerFunc(delay, timer2, 0);
    }else{
        glutPostRedisplay();
        glutTimerFunc(delay, timer1, 0);
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
