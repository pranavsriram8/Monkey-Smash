#include <stdio.h>
#include <GL/glut.h>
#include "ellipse.c" 
#include <time.h>

typedef struct Pixel {
    GLfloat red;
    GLfloat green; 
    GLfloat blue;
} Pixel;

Pixel bg;
int difficulty = 900;

unsigned int rand_interval(unsigned int min, unsigned int max) {
    int r;
    const unsigned int range = 1 + max - min;
    const unsigned int buckets = RAND_MAX / range;
    const unsigned int limit = buckets * range;

    /* Create equal size buckets all in a row, then fire randomly towards
     * the buckets until you land in one of them. All buckets are equally
     * likely. If you land off the end of the line of buckets, try again. */
    do 
    {
        r = rand();
    } while (r >= limit);
    
    return min + (r / buckets);
}

static int score = 0;
struct Monkey {
    int state;   //takes values 0 OR 1
    float x, y;  // position
}m[6];

void draw() {
    
    glClearColor(bg.red, bg.green, bg.blue, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    
    drawEllipse(-0.5,-0.5);
    drawEllipse(-0.5,0.0);
    drawEllipse(-0.5,0.5);
    
    drawEllipse(0.5,-0.5);
    drawEllipse(0.5,0.0);
    drawEllipse(0.5,0.5);
    
    int n;
    n = rand_interval(0, 5);
    m[n].state = 1;
    drawMonkey(m[n].x, m[n].y);
    printf("%d\n",score);
}

void timer() {
    glutPostRedisplay();
}

void exitTimer() {
    printf("\nTime's up \nYour Score is %d\n",score);
    //glutLeaveMainLoop();
    exit(0);
}

void display(){

    glLoadIdentity();
    draw();
    glutTimerFunc(difficulty, timer, 0); //16.6 frame rate
    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    if(key == 27) {
        exit(0);
    }    
}
float rnd(float val) {
    return roundf(val * 100) / 100;
}
int compareColor(Pixel a, Pixel b) {
    return rnd(a.red) == b.red && rnd(a.green) == b.green && rnd(a.blue) == b.blue;
}
void mouse(int button, int state, int x, int y) {
    Pixel c;
    glReadPixels(x, 500 - y, 1, 1, GL_RGB, GL_FLOAT, &c);
    
    switch(button) {
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN && !compareColor(c,bg) && !compareColor(c, (Pixel){0.0,0.0,0.0})) {
                    score++;
                if(difficulty > 300) {
                    difficulty = difficulty - 50;
                    //printf("%d\n",difficulty);
                }
            } 
        break;
    }
}

void reshape(int w, int h) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argv, char** argc) {
    
    bg.red = 0.50;
    bg.green = 0.35;
    bg.blue = 0.05;
    
    m[0].x = -0.7;
    m[0].y = -0.5;
    m[0].state = 0;
    
    m[1].x = -0.7;
    m[1].y = 0.0;
    m[1].state = 0;
    
    m[2].x = -0.7;
    m[2].y = 0.5;
    m[2].state = 0;
    
    m[3].x = 0.3;
    m[3].y = -0.5;
    m[3].state = 0;

    m[4].x = 0.3;
    m[4].y = 0.0;
    m[4].state = 0;
    
    m[5].x = 0.3;
    m[5].y = 0.5;
    m[5].state = 0;
    
    srand(time(NULL));
    glutInit(&argv, argc);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Monkey Smash");
    gluOrtho2D(0, 500, 0, 500);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);       
    glutMouseFunc(mouse);
    glutTimerFunc(20000, exitTimer, 0); 
    glutMainLoop();
    return 0;
}
