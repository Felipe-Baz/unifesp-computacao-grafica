#include <math.h>
#include <GL/glut.h>

float up=0.0;
float right=0.0;

void points(){
    glBegin(GL_POINTS);
      glVertex2f(0.0, 0.0);
      glVertex2f(0.0, 0.6);
      glVertex2f(0.8, 0.6);
      glVertex2f(0.6, 0.3);
      glVertex2f(0.8, 0.0);
    glEnd();
}

void screenSetup() {
  glClearColor(0, 0, 0, 0); //Preto
  glClear(GL_COLOR_BUFFER_BIT);
}

void desenha(){
  // Configura a screen
  screenSetup();

  // Define a cor do traço RGB
  glColor3f(1.0, 1.0, 1.0);
  // Cria alguns pontos
  points();
  
  // Apresenta na tela
  glFlush();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(50, 100);
  glutInitWindowSize(400, 300);
  glutCreateWindow("First Program with openGL");
  glutDisplayFunc(desenha);
  glutMainLoop();
}