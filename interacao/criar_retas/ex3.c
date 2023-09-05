#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

#define SCREEN_HEIGHT_SIZE 500
#define SCREEN_WIDTH_SIZE 500

int clicks = 0;
float startX = 0.0, startY = 0.0, endX = 0.0, endY = 0.0;
float red = 0.0, green = 0.0, blue = 1.0;

void retas(float x1, float y1, float x2, float y2) {
  glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
  glEnd();
}

void set_color(float red, float green, float blue) {
  glColor3f(red, green, blue);
}

void desenha() {
  glClear(GL_COLOR_BUFFER_BIT);
  set_color(red, green, blue);
  retas(startX, startY, endX, endY);
  glFlush();
}

void keyboard(unsigned char tecla, int x, int y) {
  switch (tecla) {
    case '1':
      red=1.0;
      green=0.0;
      blue=0.0;
      break;
    case '2':
      red=0.0;
      green=1.0;
      blue=0.0;
      break;
    case '3':
      red=0.0;
      green=0.0;
      blue=1.0;
      break;
    case '4':
      red=1.0;
      green=1.0;
      blue=0.0;
      break;
    case '5':
      red=1.0;
      green=0.0;
      blue=1.0;
      break;
    case '6':
      red=0.0;
      green=1.0;
      blue=1.0;
      break;
    case '7':
      red=1.0;
      green=0.647;
      blue=0.0;
      break;
    case '8':
      red=1.0;
      green=0.753;
      blue=0.796;
      break;
    case '9':
      red=0.502;
      green=0.0;
      blue=0.502;
      break;
    case '0':
      red=0.0;
      green=1.0;
      blue=0.75;
      break;
    default:
      break;
  }
  glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    clicks++;
    
    if (clicks % 2 == 1) {
      startX = (float) (x - glutGet(GLUT_WINDOW_WIDTH) / 2) / (glutGet(GLUT_WINDOW_WIDTH)/2);
      startY = (float) (glutGet(GLUT_WINDOW_HEIGHT) / 2 - y) / (glutGet(GLUT_WINDOW_HEIGHT) / 2);
    } else {
      endX = (float) (x - glutGet(GLUT_WINDOW_WIDTH) / 2) / (glutGet(GLUT_WINDOW_WIDTH)/2);
      endY = (float) (glutGet(GLUT_WINDOW_HEIGHT) / 2 - y) / (glutGet(GLUT_WINDOW_HEIGHT) / 2);
      glutPostRedisplay();
    }
  }
}

void init(){
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glColor3f(1.0,1.0,1.0);
  glPointSize(2.0);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(SCREEN_WIDTH_SIZE, SCREEN_HEIGHT_SIZE);
  glutCreateWindow("Draw Lines on Click");
  init();
  glutDisplayFunc(desenha);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);
  glutMainLoop();
  
  return 0;
}
