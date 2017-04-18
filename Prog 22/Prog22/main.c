//
//  main.c
//  Prog22
//
//  Created by Fallingstar on 2017. 4. 13..
//  Copyright © 2017년 Fallingstar. All rights reserved.
//

#include <stdio.h>
#include <GLUT/GLUT.h>

int width = 500, height = 500;

void Init();
void MyDisplay();

int main(int argc, const char * argv[]) {
    glutInit(&argc, (char**)argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("Teapot drawing like CAD UI");
    
    glutDisplayFunc(MyDisplay);
    
    Init();
    glutMainLoop();
    
    return 0;
}

void Init(){
    glEnable(GL_DEPTH_TEST);
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.3, 0.3, 0.7);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2, 2, -2, 2, 0.5, 5 );
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void MyDisplay(){
    glViewport(0, 0, width / 2, height / 2);
    
    glPushMatrix();
    gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0);
    glutWireTeapot(1.0);
    glPopMatrix();
    
    glViewport(width/2, 0, width/2, height/2);
    
    glPushMatrix();
    gluLookAt(1, 0, 0, 0, 0, 0, 0, 1, 0);
    glutWireTeapot(1.0);
    glPopMatrix();
    
    glViewport(0, height/2, width/2, height/2);
    
    glPushMatrix();
    gluLookAt(0, 1, 0, 0, 0, 0, 0, 0, -1);
    glutWireTeapot(1.0);
    glPopMatrix();
    
    glViewport(width/2, height/2, width/2, height/2);
    glMatrixMode(GL_PROJECTION);
    
    glPushMatrix();
    glLoadIdentity();
    gluPerspective(30, 1.0, 3.0, 50);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
    glutWireTeapot(1.0);
    glPopMatrix();
    
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glFlush();
}








