#include<math.h>
#include <GL/glut.h>
#define DEG2RAD 3.14159/180.0

void drawEllipse(float xpos, float ypos) {
    int i;
    glBegin(GL_POLYGON);
    
    for(i = 0;i < 360; i++) {
      float rad = i * DEG2RAD;
      glVertex2d(xpos + cos(rad) * 0.2, ypos + sin(rad) * 0.1);
    }
    glEnd();
}

void drawEllipseMon(float xpos, float ypos) {
    int i;
    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_POLYGON);
    
    for(i = 0;i < 360; i++) {
      float rad = i * DEG2RAD;
      glVertex2d(xpos + cos(rad) * 0.1, ypos + sin(rad) * 0.15);
    }
    glEnd();
}

void drawCircle(float xpos, float ypos, float r) {
    int i;
    glBegin(GL_POLYGON);
    
    for(i = 0;i < 360; i++) {
      float rad = i * DEG2RAD;
      glVertex2d(xpos + cos(rad) * r, ypos + sin(rad) * r);
    }
    glEnd();
}
void drawEyes(float xpos, float ypos) {
    int i;
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    for(i = 0;i < 360; i++) {
        float rad = i * DEG2RAD;
        glVertex2d(xpos + cos(rad) * 0.025, ypos + sin(rad) * 0.025);
    }
    glEnd();
    glColor3f(0.1, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for(i = 0;i < 360; i++) {
      float rad = i * DEG2RAD;
      glVertex2d(xpos + cos(rad) * 0.015, ypos + sin(rad) * 0.015);
    }
    
    glEnd();
}
void drawEllipseMouth(float xpos , float ypos) {
    int i;
    glBegin(GL_POLYGON);
    
    for(i = 0;i < 360; i++) {
      float rad = i * DEG2RAD;
      glVertex2d(xpos + cos(rad) * 0.05, ypos + sin(rad) * 0.075);
    }
    glEnd();
}


void drawMonkey(float x, float y) {
    
    glColor4f(1.0f, 0.5f, 0.01f, 0.0f);
    drawCircle(x + 0.2 , y + 0.2, 0.1);
    drawEllipseMon(x + 0.2 ,y + 0.1);
    drawEyes(x + 0.17 , y + 0.2);
    drawEyes(x + 0.23 , y + 0.2);
    
    glColor3f(1.0, 0.0, 0.0);
    drawEllipseMouth(x + 0.2 ,y + 0.05);
    
    glColor4f(1.0f, 0.5f, 0.01f, 0.0f);
    drawCircle(x + 0.35 , y + 0.2 , 0.075);
    drawCircle(x + 0.05, y + 0.2, 0.075);
    
    glColor3f(1.0, 0.6, 0.05);
    drawCircle(x + 0.35, y + 0.2, 0.05);
    drawCircle(x + 0.05, y + 0.2, 0.05);
    
}


