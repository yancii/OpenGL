//Yanci
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


//DECLARACION DE VARIABLES A UTILIZAR

int id_menu[2]; // vector donde almacenaremos el id de la imagen a imprimir


//METODO QUE PERMITE IMPRIMIR LA IMAGEN A MOSTRAR
void punto(float x, float y){
	glClear (GL_COLOR_BUFFER_BIT);
	glPointSize(5.0f);
	glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
}


void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
}

void menu(int opc){
    id_menu[1]=opc; // En el vector VF, en su campo 1, se almacenara el id de la imagen
    glClear (GL_COLOR_BUFFER_BIT);//limpiar la pantalla
    switch(opc){ // checando la imagen elegida para mostrar
       case 1:
           punto(0,0);
           break;
       case 2:
		exit(0);
   }
   glutPostRedisplay();//redibujar denuevo cada una de las imagenes
   glFlush();
}

// METODO QUE RE DIBUJA LA PANTALLA
void redraw( void ){
    //Limpiando la pantalla
    glClear(GL_COLOR_BUFFER_BIT);
    // Haciendo uso del metodo menu, pasandoles como paramentro el id
    menu(id_menu[1]);
	glutSwapBuffers();
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutCreateWindow("Ejemplo menu ");
    glutPositionWindow(200,200);
    init ();
    // CREACION DEL MENU PARA ELEGIR ALGUNA IMAGEN
    glutCreateMenu(menu);
      glutAddMenuEntry("PUNTO",1);
      glutAddMenuEntry("SALIR",2);
      glutAttachMenu(GLUT_RIGHT_BUTTON); // Eligiendo con el click derecho del raton
	  glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
	  glutDisplayFunc(redraw);
	  glutIdleFunc(redraw);
    glutMainLoop();
    return 0;
}
