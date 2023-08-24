#include <math.h>
#include <GL/glut.h>

float ang=0.0;
float PI=3.141592653589793238;

void circle_v2(){
    glBegin(GL_LINE_LOOP);
      for (int i=0; i<=50; i++) {
        ang = 2 * PI * i / 50;
        glVertex2f(0.5*cos(ang), 0.5*sin(ang));
      }
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
  // Cria um circulo
  circle_v2();
  
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