//
//  main.c
//  Prog04
//
//  Created by Fallingstar on 2017. 3. 16..
//  Copyright © 2017년 Fallingstar. All rights reserved.
//
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <stdio.h>
#include <stdlib.h>
#include <GLUT/GLUT.h>
#include <time.h>

#define MAXPIX 1000

void init();
void display();
int divideTriangle(GLfloat*, GLfloat*, GLfloat*, int);
void drawVertex(GLfloat*, GLfloat*, GLfloat*);

int firstDepth = 10;
GLfloat v[3][2] = {{0,0}, {MAXPIX/2,MAXPIX}, {MAXPIX,0}};

int main(int argc, const char * argv[]) {
    glutInit(&argc, (char**)argv);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("Prog 4 recursive triangle");
    glutDisplayFunc(display);
    
    init();
    glutMainLoop();
    
    return 0;
}

void init(){
    srand(time(0));
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(0,MAXPIX,0,MAXPIX);
    glClear(GL_COLOR_BUFFER_BIT);
}

void display(){
    glColor3f(1, 0, 0);
    
    glBegin(GL_TRIANGLES);
    divideTriangle(v[0], v[1], v[2], firstDepth);
    glEnd();
    
    glFlush();
}

int divideTriangle(GLfloat* a, GLfloat* b, GLfloat* c, int depth){
    GLfloat ab[2], bc[2], ca[2];
    
    if (depth > 0) {
        for (int i = 0; i < 2; i++) {
            ab[i] = (a[i]+b[i])/2;
        }
        for (int i = 0; i < 2; i++) {
            bc[i] = (b[i]+c[i])/2;
        }
        for (int i = 0; i < 2; i++) {
            ca[i] = (c[i]+a[i])/2;
        }
        
        divideTriangle(a, ab, ca, depth-1);
        divideTriangle(b, ab, bc, depth-1);
        divideTriangle(c, ca, bc, depth-1);
    }else{
        drawVertex(a, b, c);
    }
    
    return 0;
}

void drawVertex(GLfloat* a, GLfloat* b, GLfloat* c){
    glVertex2fv(a);
    glVertex2fv(b);
    glVertex2fv(c);
}
