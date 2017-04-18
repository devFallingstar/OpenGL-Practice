//
//  main.c
//  Prog09
//
//  Created by Fallingstar on 2017. 3. 21..
//  Copyright © 2017년 Fallingstar. All rights reserved.
//

#include <stdio.h>
#include <GLUT/GLUT.h>
#include <math.h>


#define PI 3.14
#define KYONG 18
#define WE 9

typedef struct POINT {
    float x;
    float y;
    float z;
}Point3D;

float radius = 4;
float theta, deltaTheta;
float phi, deltaPhi;
Point3D vertex[KYONG+2][WE+2];

void init();
void display();
void drawPath(double pi, double theta);
void drawQuad(double pi, double theta);

int main(int argc, const char * argv[]) {
    glutInit(&argc, (char**)argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Prog09 - Goo");
    glutDisplayFunc(display);
    
    init();
    glutMainLoop();
    
    return 0;
}

void init(){
    glClearColor(1, 1, 1, 1);
    glOrtho(-10, 10, -10, 10, -10, 10);
//    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
}
void display(){
    int i=0,j=0;
    
    glBegin(GL_LINES);
    glColor3f(1.0, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(10, 0, 0);
    
    glColor3f(0, 1.0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 10, 0);
    
    glColor3f(0, 0, 1.0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 10);
    glEnd();
    
    
    
    deltaTheta = 2 * PI / KYONG;
    deltaPhi = PI / WE;
    
    for (i = 0; i < KYONG; i++) {
        for (j = 0; j < WE; j++) {
            theta = i * deltaTheta;
            phi = j * deltaPhi - (PI / 2);
            
            vertex[i][j].x = radius * cos(theta) * cos(phi);
            vertex[i][j].y = radius * sin(theta) * cos(phi);
            vertex[i][j].z = radius * sin(phi);
        }
    }
    
    glBegin(GL_QUAD_STRIP);
    for (i = 0; i < KYONG; i++) {
        for (j = 0; j < WE; j++) {
            
            glColor3f(theta/180.0, 0, 0);
            
            glVertex3f(vertex[i][j].x, vertex[i][j].y, vertex[i][j].z);
            glVertex3f(vertex[i+1][j].x, vertex[i+1][j].y, vertex[i+1][j].z);
            glVertex3f(vertex[i][j+1].x, vertex[i][j+1].y, vertex[i][j+1].z);
            glVertex3f(vertex[i+1][j+1].x, vertex[i+1][j+1].y, vertex[i+1][j+1].z);
        }
    }
    
    glEnd();
    
    
    glBegin(GL_QUAD_STRIP);
    for (i = 0; i < WE; i++) {
        
        glVertex3f(vertex[KYONG-1][i].x, vertex[KYONG-1][i].y, vertex[KYONG-1][i].z);
        glVertex3f(vertex[0][i].x, vertex[0][i].y, vertex[0][i].z);
        glVertex3f(vertex[KYONG-1][0].x, vertex[KYONG-1][0].y, vertex[KYONG-1][0].z);
        glVertex3f(vertex[0][0].x, vertex[0][0].y, vertex[0][0].z);
    }
    
    
    
    glEnd();
    
    glFlush();
}




