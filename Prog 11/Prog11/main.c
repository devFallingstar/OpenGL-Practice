//
//  main.c
//  Prog11
//
//  Created by Fallingstar on 2017. 3. 21..
//  Copyright © 2017년 Fallingstar. All rights reserved.
//

#include <stdio.h>
#include <GLUT/glut.h>
#include <math.h>

#define SC_FACT 3

void init();
void display();
void rotate(GLfloat *v, GLfloat angle);
void translate(GLfloat *v, GLfloat *t);
void scaling(GLfloat *v, GLfloat *s);
void timer();

double angle = 0;
double delay = 10;

GLfloat t[3] = {-25,-25,-25};
GLfloat s[3] = {SC_FACT, SC_FACT, SC_FACT};

int main(int argc, const char * argv[]) {
    glutInit(&argc, (char**)argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Prog07 - my first 3D");
    glutDisplayFunc(display);
    glutTimerFunc(delay, timer, 0);
    
    init();
    glutMainLoop();
    
    return 0;
}

void init(){
    glClearColor(0, 0, 0, 0);
    glOrtho(-100, 100, -100, 100, -100, 100);
    glEnable(GL_DEPTH_TEST);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    GLfloat v0[3] = {15,15,35}, v1[3] = {35,15,35}, v2[3] = {35,35,35}, v3[3] = {15,35,35};
    GLfloat v4[3] = {40,20,15}, v5[3] = {20,20,15}, v6[3] = {40,40,15}, v7[3] = {20,40,15};
    
    translate(v0, t);
    translate(v1, t);
    translate(v2, t);
    translate(v3, t);
    translate(v4, t);
    translate(v5, t);
    translate(v6, t);
    translate(v7, t);
    
    scaling(v0, s);
    scaling(v1, s);
    scaling(v2, s);
    scaling(v3, s);
    scaling(v4, s);
    scaling(v5, s);
    scaling(v6, s);
    scaling(v7, s);
    
    rotate(v0, angle);
    rotate(v1, angle);
    rotate(v2, angle);
    rotate(v3, angle);
    rotate(v4, angle);
    rotate(v5, angle);
    rotate(v6, angle);
    rotate(v7, angle);
    
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


void translate(GLfloat *v, GLfloat *t) {
    int i;
    
    for (i = 0; i < 3; i++) {
        v[i] += t[i];
    }
}
void rotate(GLfloat *v, GLfloat angle) {
    GLfloat x,y,z;
    double PI = atan(1.0)*4.0;
    double theta = angle*PI / 180.0;
    
    x = v[0] * cos(theta) + v[2] * sin(theta);
    y = v[1];
    z = v[0] * -sin(theta) + v[2] * cos(theta);
    
    v[0] = x;
    v[1] = y;
    v[2] = z;
}
void scaling(GLfloat *v, GLfloat *s) {
    int i;
    static double scal = 1.0;
    static int isUp = 0;
    
    for (i = 0; i < 3; i++) {
        v[i] *= scal;
    }
    
    if (isUp == 0) {
        scal -= 0.001;
        if (scal <= 0.1) {
            isUp = 1;
        }
    }else{
        scal += 0.001;
        if (scal >= 1.0) {
            isUp = 0;
        }
    }
}

void timer() {
    glutPostRedisplay();
    glutTimerFunc(delay, timer, 0);
    
    angle += 1.0;
}





