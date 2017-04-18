//
//  main.c
//  Prog19
//
//  Created by Fallingstar on 2017. 4. 4..
//  Copyright © 2017년 Fallingstar. All rights reserved.
//

#include <stdio.h>
#include <GLUT/GLUT.h>
#include <math.h>

GLfloat vertices[][3] = { {-1.0,-1.0,-1.0}, {1.0,-1.0,-1.0}, {1.0,1.0,-1.0}, {-1.0,1.0,-1.0}, {-1.0,-1.0, 1.0}, {1.0,-1.0, 1.0}, {1.0,1.0, 1.0}, {-1.0,1.0, 1.0} };
GLfloat colors [][3] = { { 0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {1.0,1.0, 0.0}, { 0.0,1.0, 0.0},
    { 0.0, 0.0, 1.0}, {1.0, 0.0, 1.0}, {1.0,1.0, 1.0}, { 0.0,1.0, 1.0} };

static GLfloat theta = 0.0;
static GLfloat scale = 1.0;
static GLfloat axis = 1;

static GLfloat eyex=1, eyey=1, eyez=1, atx=0, aty=0, atz=0, upx=0, upy=1, upz=0;

void init();
void display();
void polygon(int a, int b, int c, int d);
void spinCube();
void keyboard_handler(unsigned char key, int x, int y);
void mouse_handler(int btn, int state, int x, int y);

int main(int argc, const char * argv[]) {
    glutInit(&argc, (char**)argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Prog14 : color cube");
        glutIdleFunc(spinCube);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard_handler);
    glutMouseFunc(mouse_handler);
    
    init();
    glutMainLoop();
    
    return 0;
}

void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    glClearColor(0, 1, 1, 1);
    glOrtho(-2, 2, -2, 2, -10, 10);
    glEnable(GL_DEPTH_TEST);
    
    glMatrixMode(GL_MODELVIEW);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);
    
}
void display() {
    
    
    GLubyte indices[] = {0,3,2,1, 2,3,7,6, 0,4,7,3, 1,2,6,5, 4,5,6,7, 0,1,5,4};
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glLoadIdentity();
    gluLookAt(eyex, eyey, eyez, atx, aty, atz, upx, upy, upz);
    
    switch ((int)axis) {
        case 0:
            glRotatef(theta, 1, 0, 0);
            break;
        case 1:
            glRotatef(theta, 0, 1, 0);
            break;
        case 2:
            glRotatef(theta, 0, 0, 1);
            break;
        default:
            break;
    }
    glScalef(scale, scale, scale);
    
    for (int i = 0; i < 6; i++) {
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, &indices[4*i]);
    }
    
    glutSwapBuffers();
}
void polygon(int a, int b, int c, int d) {
    glBegin(GL_POLYGON);
    glColor3fv ( colors  [a] );
    glVertex3fv( vertices[a] );
    glColor3fv ( colors  [b] );
    glVertex3fv( vertices[b] );
    glColor3fv ( colors  [c] );
    glVertex3fv( vertices[c] );
    glColor3fv ( colors  [d] );
    glVertex3fv( vertices[d] );
    glEnd();
}

void spinCube() {
//    theta += 2.0;
//    if (theta >= 360.0) {
//        theta -= 360.0;
//    }
    glutPostRedisplay();
}

void keyboard_handler(unsigned char key, int x, int y) {
    if (key == 'x') eyex -= 0.1;
    if (key == 'X') eyex += 0.1;
    if (key == 'y') eyey -= 0.1;
    if (key == 'Y') eyey += 0.1;
    if (key == 'z') eyez -= 0.1;
    if (key == 'Z') eyez += 0.1;
    if ( scale < 0.1 ) scale = 0.1;
    if ( scale > 1.4 ) scale = 1.4;
    
    glutPostRedisplay();
}


void mouse_handler(int btn, int state, int x, int y) {
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 0;
    if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis = 1;
    if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) axis = 2;
}
