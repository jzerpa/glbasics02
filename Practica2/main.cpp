#include <gl/glut.h>

static int year = 0, day = 0, moon=0;

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glColor3f (1.0, 1.0, 0.0);
   
   glPushMatrix();

   /* dibujar sol */
   glRotatef (90, 1.0, 0.0, 0.0);
   glutWireSphere(1.0, 20, 16);   
   /* dibujar tierra y definir sus transformaciones */

   glRotatef ((GLfloat) year , 0.0, 0.0, 1.0);
   glTranslatef (2.0, 0.0, 0.0);
   glRotatef ((GLfloat) day, 0.0, 0.0, 1.0);
   glColor3f (0.0, 0.0, 1.0);
   glutWireSphere(0.2, 10, 8);    
   /* dibujar luna y definir sus transformaciones */
   glRotatef ((GLfloat) moon, 0.0, 0.0, 1.0);
   glTranslatef (0.5, 0.0, 0.0);
   glColor3f (1.0, 0.0, 0.0);
   glutWireSphere(0.05, 5, 4); 

   glPopMatrix();
   glutSwapBuffers();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt (0.0, 0.0, 7.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 'r':
         day = (day + 10) % 360;
         glutPostRedisplay();
         break;
      case 'R':
         day = (day - 10) % 360;
         glutPostRedisplay();
         break;
      case 't':
         year = (year + 5) % 360;
         glutPostRedisplay();
         break;
      case 'T':
         year = (year - 5) % 360;
         glutPostRedisplay();
         break;
	  case 'm':
         moon = (moon + 5) % 360;
         glutPostRedisplay();
         break;
      case 'M':
         moon = (moon - 5) % 360;
         glutPostRedisplay();
         break;
      default:
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (500, 500); 
   glutCreateWindow("Practica 2");  

   init ();

   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}