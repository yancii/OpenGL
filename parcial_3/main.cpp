// Maria Yanci Martinez Garcia MG12040

//librerias a utilizar
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <SOIL/SOIL.h>

//**********************************************************************
int shadow=0;
//Definimos variables
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;

GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
//**********************************************************************

static void init(void)
{
   GLfloat position[] = { 2.0, 3.0, 0.5, 10.0 };

   glEnable(GL_DEPTH_TEST);

   glLightfv(GL_LIGHT0, GL_POSITION, position);
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
}

//**********************************************************************
static void renderSphere (GLfloat x, GLfloat y, GLfloat z)
{
   glPushMatrix();
   glTranslatef (x, y, z);
   glutSolidSphere(0.5, 16, 16);
   glPopMatrix();
}

//**********************************************************************
//funcion donde se dibuja y aplica materiales
void display(void)
{
	
	GLfloat mat_ambient[] = { 0.0, 0.0, 0.0 };
	GLfloat mat_diffuse[] = { 0.55, 0.55, 0.55 };
	GLfloat mat_specular[] = { 0.70, 0.70, 0.70};
	GLfloat shine[] = {30.8974f};
   //  Borrar pantalla y Z-buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
     glLoadIdentity();
     
   //Control de la camara
    gluLookAt (0, 6,10.0 , 0, 0, 0, 0.0, 1.0, 0.0);
//materiales a utilizar
   glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, shine);

//**********************************************************************
   //comienza a dibujar
   //Base
   glPushMatrix();
   glTranslatef (0, 0, 0);
   glScalef(10.0,0.5,10.0);
   glNormal3f(0,1,0);
   glutSolidCube(1);
   glPopMatrix();
   //Esfera
   glPushMatrix();
   glTranslatef (-3, 1.25, -3);
   glutSolidSphere (1,20,20);
   glPopMatrix();
   //Cubo
   glPushMatrix();
   glTranslatef (3, 1.2, 3);
   glutSolidCube (1.75);
   glPopMatrix();
   //Torus
   glPushMatrix();
   glTranslatef (3, 1.29, -3);
   glutSolidTorus (0.5,0.65,20,20);
   glPopMatrix();
   //Cono
   glPushMatrix();
   glTranslatef (-3, 0.5, -0);
   glRotatef(-90,1,0,0);
   glutSolidCone (1, 1,20,20);
   glPopMatrix();
   //Icosahedro
   glPushMatrix();
   glTranslatef (0, 1.2, 0);
   glutSolidIcosahedron ();
   glPopMatrix();
   //Octaedro
   glPushMatrix();
   glTranslatef (3, 1.2, 0);
   glutSolidOctahedron ();
   glPopMatrix();
   //Tetrahedro
   glPushMatrix();
   glTranslatef (-3, 0.8, 3);
   glRotatef(-20,0,0,1);
   glutSolidTetrahedron ();
   glPopMatrix();
   //Dodecahedro
   glPushMatrix();
   glTranslatef (0, 1.25, -3);
    glRotatef(-90,0,1,0);
    glRotatef(-90,1,0,0);
   glRotatef(45,1,0,0);
   glScalef(0.5,0.5,0.5);
   glutSolidDodecahedron ();
    glPopMatrix();
    //Tetera
    glPushMatrix();
   glTranslatef (0, 1.25, 3);
   glutSolidTeapot (1);
    glPopMatrix();
    
   glFlush();
   glutSwapBuffers();
}

//**********************************************************************
//Funsion Reshape
	void reshape (int w, int h)
{
glViewport (0, 0, (GLsizei) w, (GLsizei) h);
glMatrixMode (GL_PROJECTION);
glLoadIdentity ();
glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 60.0);
glMatrixMode(GL_MODELVIEW);
}

//**********************************************************************
// Función para controlar teclas especiales
void specialKeys( int key, int x, int y )
{

    //  Flecha derecha: aumentar rotación 7 grados
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 7;

    //  Flecha izquierda: rotación en eje Y negativo 7 grados
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 7;
    //  Flecha arriba: rotación en eje X positivo 7 grados
    else if (key == GLUT_KEY_UP)
        rotate_x += 7;
    //  Flecha abajo: rotación en eje X negativo 7 grados
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 7;
    //  Tecla especial F2 : rotación en eje Z positivo 7 grados
    else if (key == GLUT_KEY_F2)
        rotate_z += 7;
    //  Tecla especial F2 : rotación en eje Z negativo 7 grados
    else if (key == GLUT_KEY_F2)
        rotate_z -= 7;

    //  Solicitar actualización de visualización
    glutPostRedisplay();

}
//**********************************************************************
//teclado normal

void keyboard(unsigned char key, int x, int y)
{
	if(key=='w'){
		Y+=1;
		}
	if(key=='s'){
		Y-=1;
		}
	if(key=='a'){
		X-=1;
		}
	if(key=='d'){
		X+=1;
		}
 if(key=='z'){
    Z+=1;
    }
if(key=='x'){
   Z-=1;
   }
      if (key == 27){
		exit(0);
	}
        glutPostRedisplay();
   }


//**********************************************************************
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(500, 500);
   glutCreateWindow("Figuras solidas");
   glEnable(GL_DEPTH_TEST);
   init();
   glutReshapeFunc (reshape);
    glutSpecialFunc(specialKeys);
   glutKeyboardFunc (keyboard);
   glutDisplayFunc (display);
   glutMainLoop();
   return 0;
}
