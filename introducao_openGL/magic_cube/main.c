#include <math.h>
#include <GL/glut.h>

float up=0.0;
float right=0.0;

void quadrado(float incX, float incY){
    glBegin(GL_POLYGON);
      glVertex2f(-0.25+incX+right, 0.25+incY+up);
      glVertex2f(0.25+incX+right, 0.25+incY+up);
      glVertex2f(0.25+incX+right, -0.25+incY+up);
      glVertex2f(-0.25+incX+right, -0.25+incY+up);
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
  glColor3f(0.0,1.0,1.0);
  // Cria um quadrado
  quadrado(0.0,0.0);

  // Define a cor do traço RGB
  glColor3f(1.0,1.0,1.0);
  // Cria um quadrado
  quadrado(0.0,-0.5);

  // Define a cor do traço RGB
  glColor3f(0.0,0.0,0.5);
  // Cria um quadrado
  quadrado(0.0,0.5);

  // Define a cor do traço RGB
  glColor3f(1.0,1.0,0.0);
  // Cria um quadrado
  quadrado(-0.5, 0.0);

  // Define a cor do traço RGB
  glColor3f(0.0,0.5,0.0);
  // Cria um quadrado
  quadrado(0.5, 0.0);
  
  // Define a cor do traço RGB
  glColor3f(0.0,0.0,1.0);
  // Cria um quadrado
  quadrado(0.5,-0.5);
  
  // Define a cor do traço RGB
  glColor3f(1.0,0.0,0.0);
  // Cria um quadrado
  quadrado(0.5,0.5);
  
  // Define a cor do traço RGB
  glColor3f(0.0,1.0,0.0);
  // Cria um quadrado
  quadrado(-0.5,0.5);
  
  // Define a cor do traço RGB
  glColor3f(1.0,0.0,1.0);
  // Cria um quadrado
  quadrado(-0.5,-0.5);
  
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