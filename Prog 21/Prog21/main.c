//
//  main.c
//  Prog21
//
//  Created by Fallingstar on 2017. 4. 18..
//  Copyright © 2017년 Fallingstar. All rights reserved.
//

#include <stdio.h>
#include <GLUT/GLUT.h>
#include <math.h>

#define SIZE 100



void init();
void loadImage();
void spinCube();
void myKeyboard(unsigned char key, int x, int y);
void myDisplay();

unsigned char buff[240][416];
static GLfloat viewer[3] = {0,0,130};
static int rot = 0;
static GLfloat theta = 0;
static GLfloat axis = 1;

int main(int argc, const char * argv[]) {
    glutInit(&argc, (char**)argv);
    glutInitWindowSize(800, 800);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow("Picture rotate");
    
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(myKeyboard);
    glutIdleFunc(spinCube);
    
    init();
    glutMainLoop();
    
    return 0;
}

void init(){
    glEnable(GL_DEPTH_TEST);
    
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-SIZE, SIZE, -SIZE, SIZE, -SIZE, SIZE);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    loadImage();
}
void loadImage(){
    FILE *fp = fopen("testo.y", "rb");
    fread(buff, 416*240, sizeof(char), fp);
    fclose(fp);
}
void spinCube(){
    
}
void myKeyboard(unsigned char key, int x, int y){
    if (key == 'x') {
        viewer[0] -= 5.0;
    }
    if (key == 'X') {
        viewer[0] += 5.0;
    }
    if (key == 'y') {
        viewer[1] -= 5.0;
    }
    if (key == 'Y') {
        viewer[1] += 5.0;
    }
    if (key == 'o') {
        viewer[0] = 0;
        viewer[1] = 0;
        viewer[2] = 130;
    }
    if (key == 'r') {
        rot = 1-rot;
    }
}
void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glLoadIdentity();
    gluLookAt(viewer[0], viewer[1], viewer[2], 0, 0, 0, 0, 1, 0);
    
    glRotatef(theta, 0, 0, 1);
    glScalef(1, -1, 1);
    glTranslatef(-208, -120, -128);
    
    GLint xp,yp,z;
    for (int y = 1; y < 240-1; y++) {
        for (int x = 1; x < 416-1; x++) {
            glBegin(GL_LINES);
            
            xp = x;
            yp = y;
            z = (GLfloat)buff[yp][xp];
            
            glColor3f(z/255, z/255, z/255);
            glVertex3i(xp, yp, -z);
            glVertex3i(xp, yp, z);
            glEnd();
        }
    }
    glFlush();
    glutSwapBuffers();
}







