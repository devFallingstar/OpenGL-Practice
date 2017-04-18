//
//  main.c
//  Prog07
//
//  Created by Fallingstar on 2017. 3. 21..
//  Copyright © 2017년 Fallingstar. All rights reserved.
//

#include <stdio.h>
#include <GLUT/glut.h>

void init();
void display();

int main(int argc, const char * argv[]) {
    glutInit(&argc, (char**)argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Prog07 - my first 3D");
    glutDisplayFunc(display);
    
    init();
    glutMainLoop();
    
    return 0;
}

void init(){
    glClearColor(0, 0, 0, 0);
    glOrtho(-100, 100.0, -100, 100.0, -100.0, 100.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
}

void display(){
    GLfloat v0[3] = {15,15,35}, v1[3] = {35,15,35}, v2[3] = {35,35,35}, v3[3] = {15,35,35};
    GLfloat v4[3] = {40,20,15}, v5[3] = {20,20,15}, v6[3] = {40,40,15}, v7[3] = {20,40,15};
    
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3fv(v0);
    glVertex3fv(v1);
    glVertex3fv(v2);
    glVertex3fv(v3);
    glEnd();
    
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
    glVertex3fv(v0);
    glVertex3fv(v1);
    glVertex3fv(v4);
    glVertex3fv(v5);
    glEnd();
    
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3fv(v5);
    glVertex3fv(v4);
    glVertex3fv(v6);
    glVertex3fv(v7);
    glEnd();
    
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex3fv(v7);
    glVertex3fv(v6);
    glVertex3fv(v2);
    glVertex3fv(v3);
    glEnd();
    
    glColor3f(0, 1, 1);
    glBegin(GL_POLYGON);
    glVertex3fv(v0);
    glVertex3fv(v5);
    glVertex3fv(v7);
    glVertex3fv(v3);
    glEnd();
    
    glColor3f(1, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3fv(v1);
    glVertex3fv(v4);
    glVertex3fv(v6);
    glVertex3fv(v2);
    glEnd();
    
    glFlush();
}



