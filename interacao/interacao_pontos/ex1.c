#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

#define SCREEN_HEIGHT_SIZE 500
#define SCREEN_WIDTH_SIZE 500

float X = 0.0, Y = 0.0;
float red = 0.0, green = 0.0, blue = 1.0;
float point_size = 5.0;

void set_color(float red, float green, float blue) {
  glColor3f(red, green, blue);
}

void set_point_size(float size) {
  glPointSize(size);
}

void pontos(int x, int y) {
  glBegin(GL_POINTS);
    glVertex2f(X, Y);
  glEnd();
}

void desenha() {
  glClear(GL_COLOR_BUFFER_BIT);
  set_color(red, green, blue);
  set_point_size(point_size);
  pontos(0, 0);
  glFlush();
}

void mouse(int button, int state, int x, int y) {
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
      X = (float) (x - glutGet(GLUT_WINDOW_WIDTH) / 2) / (glutGet(GLUT_WINDOW_WIDTH)/2);
      Y = (float) (glutGet(GLUT_WINDOW_HEIGHT) / 2 - y) / (glutGet(GLUT_WINDOW_HEIGHT) / 2);
    glutPostRedisplay();
  }
}

void init(){
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glColor3f(1.0,1.0,1.0);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(SCREEN_WIDTH_SIZE, SCREEN_HEIGHT_SIZE);
  glutCreateWindow("Draw Points on Click");
  init();
  glutDisplayFunc(desenha);
  glutMouseFunc(mouse);
  glutMainLoop();
  
  return 0;
}
