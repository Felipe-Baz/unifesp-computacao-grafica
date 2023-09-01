#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

#define SCREEN_HEIGHT_SIZE 500
#define SCREEN_WIDTH_SIZE 500

#define OPTION_RETA 1
#define OPTION_TRIANGULO 2

#define OPTION_COLOR 1
#define OPTION_THICKNESS 2

int clicks = 0, option = OPTION_RETA, selector = OPTION_COLOR;
float startX = -0.5, startY = 0.0, endX = 0.5, endY = 0.0;
float triX1 = -0.5, triY1 = 0.0, triX2 = 0.5, triY2 = 0.5, triX3 = -0.5, triY3 = -0.5;
float red = 1.0, green = 1.0, blue = 1.0;
float point_size = 2.0;

void write_pixel(float x, float y){
  x = (float) (x - glutGet(GLUT_WINDOW_WIDTH) / 2) / (glutGet(GLUT_WINDOW_WIDTH)/2);
  y = (float) (glutGet(GLUT_WINDOW_HEIGHT) / 2 - y) / (glutGet(GLUT_WINDOW_HEIGHT) / 2);
  // printf("%f,%f\n", x, y);
  glBegin(GL_POINTS);
    glVertex2f(x, y*-1);
  glEnd();
}

void bresenham(float x1, float y1, float x2, float y2) {
  int window_width = glutGet(GLUT_WINDOW_WIDTH);
  int window_height = glutGet(GLUT_WINDOW_HEIGHT);

  float x1_screen = (x1 + 1.0) * 0.5 * window_width;
  float y1_screen = (y1 + 1.0) * 0.5 * window_height;
  float x2_screen = (x2 + 1.0) * 0.5 * window_width;
  float y2_screen = (y2 + 1.0) * 0.5 * window_height;

  float dx = fabs(x2_screen - x1_screen);
  float dy = fabs(y2_screen - y1_screen);
  int sx = (x1_screen < x2_screen) ? 1 : -1;
  int sy = (y1_screen < y2_screen) ? 1 : -1;
  int err = (int)(dx - dy);

  while (1) {
    // Desenha um ponto na posição (x, y)
    write_pixel((int)x1_screen, (int)y1_screen);

    if ((int)x1_screen == (int)x2_screen && (int)y1_screen == (int)y2_screen)
      break;

    int e2 = 2 * err;
    if (e2 > -dy) {
      err -= (int)dy;
      x1_screen += sx;
    }
    if (e2 < dx) {
      err += (int)dx;
      y1_screen += sy;
    }
  }
}

void set_color(float red, float green, float blue) {
  glColor3f(red, green, blue);
}

void set_point_size(float size) {
  glPointSize(size);
}

void desenha() {
  glClear(GL_COLOR_BUFFER_BIT);
  set_color(red, green, blue);
  set_point_size(point_size);
  printf("%d\n",option);
  switch(option) {
    case OPTION_RETA:
      bresenham(startX, startY, endX, endY);
      break;
    case OPTION_TRIANGULO:
      bresenham(triX1, triY1, triX2, triY2);
      bresenham(triX2, triY2, triX3, triY3);
      bresenham(triX3, triY3, triX1, triY1);
      break;
    default:
      break;
  }
  glFlush();
}

void keyboard(unsigned char tecla, int x, int y) {
  switch (tecla) {
    case '1':
      if(selector == OPTION_THICKNESS) {
        point_size = 1.0;
        break;
      }
      red=1.0;
      green=0.0;
      blue=0.0;
      break;
    case '2':
      if(selector == OPTION_THICKNESS) {
        point_size = 2.0;
        break;
      }
      red=0.0;
      green=1.0;
      blue=0.0;
      break;
    case '3':
      if(selector == OPTION_THICKNESS) {
        point_size = 3.0;
        break;
      }
      red=0.0;
      green=0.0;
      blue=1.0;
      break;
    case '4':
      if(selector == OPTION_THICKNESS) {
        point_size = 4.0;
        break;
      }
      red=1.0;
      green=1.0;
      blue=0.0;
      break;
    case '5':
      if(selector == OPTION_THICKNESS) {
        point_size = 5.0;
        break;
      }
      red=1.0;
      green=0.0;
      blue=1.0;
      break;
    case '6':
      if(selector == OPTION_THICKNESS) {
        point_size = 6.0;
        break;
      }
      red=0.0;
      green=1.0;
      blue=1.0;
      break;
    case '7':
      if(selector == OPTION_THICKNESS) {
        point_size = 7.0;
        break;
      }
      red=1.0;
      green=0.647;
      blue=0.0;
      break;
    case '8':
      if(selector == OPTION_THICKNESS) {
        point_size = 8.0;
        break;
      }
      red=1.0;
      green=0.753;
      blue=0.796;
      break;
    case '9':
      if(selector == OPTION_THICKNESS) {
        point_size = 9.0;
        break;
      }
      red=0.502;
      green=0.0;
      blue=0.502;
      break;
    case '0':
      if(selector == OPTION_THICKNESS) {
        point_size = 10.0;
        break;
      }
      red=0.0;
      green=1.0;
      blue=0.75;
      break;
    case 'r':
      option = OPTION_RETA;
      break;
    case 'R':
      option = OPTION_RETA;
      break;
    case 't':
      option = OPTION_TRIANGULO;
      break;
    case 'T':
      option = OPTION_TRIANGULO;
      break;
    case 'e':
      selector = OPTION_THICKNESS;
      break;
    case 'E':
      selector = OPTION_THICKNESS;
      break;
    case 'k':
      selector = OPTION_COLOR;
      break;
    case 'K':
      selector = OPTION_COLOR;
      break;
    default:
      break;
  }
  glutPostRedisplay();
}

void retas(int clicks, int x, int y) {
  if (clicks % 2 == 1) {
    startX = (float) (x - glutGet(GLUT_WINDOW_WIDTH) / 2) / (glutGet(GLUT_WINDOW_WIDTH)/2);
    startY = (float) (glutGet(GLUT_WINDOW_HEIGHT) / 2 - y) / (glutGet(GLUT_WINDOW_HEIGHT) / 2);
  } else {
    endX = (float) (x - glutGet(GLUT_WINDOW_WIDTH) / 2) / (glutGet(GLUT_WINDOW_WIDTH)/2);
    endY = (float) (glutGet(GLUT_WINDOW_HEIGHT) / 2 - y) / (glutGet(GLUT_WINDOW_HEIGHT) / 2);
    glutPostRedisplay();
  }
}

void triangulos(int clicks, int x, int y) {
  if (clicks % 3 == 1) {
    triX1 = (float) (x - glutGet(GLUT_WINDOW_WIDTH) / 2) / (glutGet(GLUT_WINDOW_WIDTH)/2);
    triY1 = (float) (glutGet(GLUT_WINDOW_HEIGHT) / 2 - y) / (glutGet(GLUT_WINDOW_HEIGHT) / 2);
  } else if (clicks % 3 == 2) {
    triX2 = (float) (x - glutGet(GLUT_WINDOW_WIDTH) / 2) / (glutGet(GLUT_WINDOW_WIDTH)/2);
    triY2 = (float) (glutGet(GLUT_WINDOW_HEIGHT) / 2 - y) / (glutGet(GLUT_WINDOW_HEIGHT) / 2);
  } else {
    triX3 = (float) (x - glutGet(GLUT_WINDOW_WIDTH) / 2) / (glutGet(GLUT_WINDOW_WIDTH)/2);
    triY3 = (float) (glutGet(GLUT_WINDOW_HEIGHT) / 2 - y) / (glutGet(GLUT_WINDOW_HEIGHT) / 2);
    glutPostRedisplay();
  }
}

void mouse(int button, int state, int x, int y) {
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    clicks++;
    
    switch(option) {
      case OPTION_RETA:
        retas(clicks, x, y);
        break;
      case OPTION_TRIANGULO:
        triangulos(clicks, x, y);
        break;
      default:
        break;
    }
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
  glutCreateWindow("Draw Lines on Click - bresenham");
  init();
  glutDisplayFunc(desenha);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);
  glutMainLoop();
  
  return 0;
}
