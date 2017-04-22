//Maria Yanci Martinez Garcia MG12040

//librerias utilizar
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

int color=0;
//sin color de las textura

//comenzando a dibujar los lados del triangulo
//**********************************************************************

void LADO_INFERIOR1 ()
{
    glBegin(GL_POLYGON);
    glVertex3f(0.3, -0.3, -0.3 );
    glVertex3f(0.3, -0.3,  0.3 );
    glVertex3f(-0.3, -0.3,  0.3 );
    glVertex3f(-0.3, -0.3, -0.3 );
    glEnd();
    }
    
void LADO_IZQUIERDO1()
{
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.3, -0.3, -0.3 );
    glVertex3f(-0.3, -0.3,  0.3 );
    glVertex3f(0.0,  0.3,  0.0 );
    glEnd();
}

void LADO_DERECHO1()
{
    glBegin(GL_POLYGON);
    glVertex3f(0.3, -0.3, -0.3 );
    glVertex3f(0.3, -0.3,  0.3 );
    glVertex3f(0.0,  0.3, 0.0 );
    glEnd();
}

void LADO_FRONTAL1()
{
	glBegin(GL_POLYGON);
	glVertex3f( -0.3, -0.3, -0.3 );
	glVertex3f(0.3, -0.3, -0.3 );
	glVertex3f( 0.0,  0.3, 0.0 );
	glEnd();
}

void LADO_TASERO1()
{
    glBegin(GL_POLYGON);
    glVertex3f(  -0.3, -0.3, 0.3 );      
    glVertex3f(  0.3,  -0.3, 0.3 );      
    glVertex3f( 0.0,  0.3, 0.0 );      
    glEnd();
}

//dandole color de textura al triangulo
//**********************************************************************

void LADO_INFERIOR ()
{
    // Propiedades del material color white rubber 
    GLfloat mat_ambient[] = { 0.05, 0.05,0.05 };
    GLfloat mat_diffuse[] = { 0.05, 0.05, 0.05 };
    GLfloat mat_specular[] = { 0.7, 0.7, 0.7   };
    //setMaterial
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glBegin(GL_POLYGON);
    glVertex3f(0.3, -0.3, -0.3 );
    glVertex3f(0.3, -0.3,  0.3 );
    glVertex3f(-0.3, -0.3,  0.3 );
    glVertex3f(-0.3, -0.3, -0.3 );
    glEnd();
    }
    
void LADO_IZQUIERDO()
{
    //Propiedades del material color yellow plastic
    GLfloat mat_ambient[] = { 0.0, 0.0, 0.0 };
    GLfloat mat_diffuse[] = { 0.5, 0.5, 0.0 };
    GLfloat mat_specular[] = {0.60, 0.60, 0.50};
    //setMaterial
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.3, -0.3, -0.3 );
    glVertex3f(-0.3, -0.3,  0.3 );
    glVertex3f(0.0,  0.3,  0.0 );
    glEnd();
}

void LADO_DERECHO()
{
    // Propiedades del material color red rubber
    GLfloat mat_ambient[] = { 0.05, 0.0,0.0 };
    GLfloat mat_diffuse[] = { 0.5, 0.4, 0.4 };
    GLfloat mat_specular[] = { 0.7, 0.04, 0.04   };
 
    //setMaterial
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glBegin(GL_POLYGON);
    glVertex3f(0.3, -0.3, -0.3 );
    glVertex3f(0.3, -0.3,  0.3 );
    glVertex3f(0.0,  0.3, 0.0 );
    glEnd();
}

void LADO_FRONTAL()
{
	// Propiedades del material color bronze    
    GLfloat mat_ambient[] = { 0.2125, 0.1275, 0.054};
    GLfloat mat_diffuse[] = { 0.714, 0.4284, 0.18144};
    GLfloat mat_specular[] = { 0.393548, 0.271906, 0.166721 };
    //setMaterial
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glBegin(GL_POLYGON);
    glVertex3f( -0.3, -0.3, -0.3 );
    glVertex3f(0.3, -0.3, -0.3 );
    glVertex3f( 0.0,  0.3, 0.0 );
    glEnd();
}

void LADO_TASERO()
{
    // Propiedades del material color green plastic   
    GLfloat mat_ambient[] = { 0.0, 0.0, 0.0 };
    GLfloat mat_diffuse[] = { 0.1, 0.35, 0.1};
    GLfloat mat_specular[] = {0.45, 0.55, 0.45 };
    //setMaterial
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glBegin(GL_POLYGON);
    glVertex3f(  -0.3, -0.3, 0.3 );  
    glVertex3f(  0.3,  -0.3, 0.3 );      
    glVertex3f( 0.0,  0.3, 0.0 );      
    glEnd();
}

void PIRAMIDE()
    {
	// Activamos la fuente de luz
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0); //Activamos las luces en 0
    glDepthFunc(GL_LESS); //comparación de profundidad
    glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TEST
    // Queremos que se dibujen las caras frontales
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    GLfloat light_position[] = { 2.0, 3.0, 0.6, 18.0 }; //pocicion de iluminacion de la piramide
    GLfloat shine[] = {1.21794872f};
    glMaterialfv(GL_FRONT, GL_SHININESS, shine);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glShadeModel(GL_SMOOTH);
    glNormal3f( 0.0f, 0.0f, 1.0f);
    LADO_FRONTAL();
    glNormal3f( 0.0f, 0.0f,-1.0f);
    LADO_TASERO();
    glNormal3f( -1.0f,0.0f, 0.0f );
    LADO_DERECHO();
    glNormal3f(1.0f, 0.0f, 0.0);
    LADO_IZQUIERDO();
    glNormal3f( 0.0f, -1.0f, 0.0f);
    LADO_INFERIOR();
}

void PIRAMIDE1()
{
    glShadeModel(GL_SMOOTH);
    glNormal3f( 0.0f, 0.0f, 1.0f);
    LADO_FRONTAL1();
    glNormal3f( 0.0f, 0.0f,-1.0f);
    LADO_TASERO1();
    glNormal3f( -1.0f,0.0f, 0.0f );
    LADO_DERECHO1();
    glNormal3f(1.0f, 0.0f, 0.0);
    LADO_IZQUIERDO1();
    glNormal3f( 0.0f, -1.0f, 0.0f);
    LADO_INFERIOR1();
}

//Definimos variables
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;

//**********************************************************************
//funcion display

void display()
{
    //  Borrar pantalla y Z-buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    // Resetear transformaciones
    glLoadIdentity();
    // Rotar en el eje X,Y y Z
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 1.0 );
    if (color==0){
    PIRAMIDE();
     }
     else if (color==1){
 glColor3f(0,0,1);
	 PIRAMIDE1();
	 }
    else if (color==2){
 glColor3f(0,1,0);
	 PIRAMIDE1();
	 }
	 else if (color==3){
 glColor3f(1,0,0);
	 PIRAMIDE1();
	 }
    else if (color==4){
 glColor3f(1,1,0);
	 PIRAMIDE1();
	 }
else if (color==5){
 glColor3f(1,0,1);
	 PIRAMIDE1();
	 }
    glFlush();
    glutSwapBuffers();

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
// Función para controlar teclas normales del teclado.
void keyboard(unsigned char key, int x, int y)
{
//control de teclas que hacen referencia a Escalar y transladar el cubo en los ejes X,Y,Z.
    switch (key)
    {
	    case '0':
 glDisable(GL_LIGHTING);
 glDisable(GL_LIGHT0); 
 glDisable(GL_DEPTH_TEST);
	color=0;
        break;
    case '1':
 glDisable(GL_LIGHTING);
 glDisable(GL_LIGHT0); 
 glDisable(GL_DEPTH_TEST);
	color=1;
        break;
	case '2':
 glDisable(GL_LIGHTING);
 glDisable(GL_LIGHT0); 
 glDisable(GL_DEPTH_TEST);
	color=2;
        break;
	case '3':
 glDisable(GL_LIGHTING);
 glDisable(GL_LIGHT0); 
 glDisable(GL_DEPTH_TEST);
	color=3;
        break;
	case '4':
 glDisable(GL_LIGHTING);
 glDisable(GL_LIGHT0); 
 glDisable(GL_DEPTH_TEST);
	color=4;
        break;
    case '5':
 glDisable(GL_LIGHTING);
 glDisable(GL_LIGHT0); 
 glDisable(GL_DEPTH_TEST);
	color=5;
        break;
    case 'q':
        exit(0);			// exit
    }
    glutPostRedisplay();
}

//**********************************************************************

int main(int argc, char* argv[])
{

    //  Inicializar los parámetros GLUT y de usuario proceso
    glutInit(&argc,argv);

    // Solicitar ventana con color real y doble buffer con Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (0, 0);
    // Crear ventana
    glutCreateWindow("Piramide");

    // Habilitar la prueba de profundidad de Z-buffer
    glEnable(GL_DEPTH_TEST);
    // Funciones de retrollamada
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    // Pasar el control de eventos a GLUT
    glutMainLoop();

    // Regresar al sistema operativo
    return 0;

}
