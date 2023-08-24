#include <math.h>
#include <GL/glut.h>

float up=0.0;
float right=0.0;

void flag(float incX, float incY){
    glBegin(GL_POLYGON);
      glVertex2f(0.1+incX+right, 0.1+incY+up);
      glVertex2f(0.1+incX+right, 0.6+incY+up);
      glVertex2f(0.8+incX+right, 0.6+incY+up);
      glVertex2f(0.6+incX+right, 0.35+incY+up);
      glVertex2f(0.8+incX+right, 0.1+incY+up);
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
  // Cria uma bandeira
  flag(-0.5, -0.5);
  
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