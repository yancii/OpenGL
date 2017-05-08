
//Luis Fernando Hernandez Castillo
//HC12012
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>


//Definimos variables
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;
int x1;
GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 1.0f;
float amb1,amb2,amb3,dif1,dif2,dif3,spe1,spe2,spe3;


void Material(float amb1,float amb2,float amb3,float dif1, float dif2,float dif3,float spe1,float spe2,float spe3){
 // Propiedades del material
 GLfloat mat_ambient[] = { amb1,amb2,amb3};
 GLfloat mat_diffuse[] = { dif1,dif2,dif3};
 GLfloat mat_specular[] = { spe1,spe2,spe3};
 glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
 glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
 
    }
    
    

void display()
{
    GLfloat light_position[] = { 0.0, 8.0, 9.0, 0.0 };
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    //  Borrar pantalla y Z-buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    // Resetear transformaciones
    glLoadIdentity();
      gluLookAt(0.0185,0.02,0.4, //punto de vista en el eje X,Y,Z
              0.0,0.0,0.35, //Centro del Objeto en el eje X,Y,Z
              0.0,1.0,0.0); //Orientación
    //glOrtho(-5.0, 5.0, -5.0, 5.0, -0.0, 5.0);
    //glFrustum(-8,8,-8,8,0.0,-10);
    glPushMatrix();
    // Rotar en el eje X,Y y Z
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 1.0 );
    glTranslatef(X,Y,-0.8);   // Transladar en los 3 ejes
    // Otras transformaciones
    glScalef(0.18, 0.18, 0.25);
    glRotatef( 25, 1.0, 2.0, 0.0 );
    
    // Primera cara, se identica por multiples colores
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glShadeModel(GL_SMOOTH);
    for (int x=-4;x<4;x++){
            x1=x;
            if (x<0){
            x1=x*-1;
            }
        for (int z=1;z<9;z++){
    
    if((x1%2==1 or x1%2==0) and z%2==1){
        if(x1%2==1){
        //Apliacando el material
        Material(0.0 ,0.0, 0.0, 0.01, 0.01, 0.01, 0.50, 0.50, 0.50 );  
        glColor3f(1.0f,0.0f,0.0f);
        }
        else if(x1%2==0){
        Material(0.0, 0.0, 0.0, 0.55, 0.55, 0.55, 0.70, 0.70 ,0.70);
            glColor3f(1.0f,1.0f,1.0f);
            }
    }
    else if((x1%2==1 or x1%2==0) and z%2==0){
        if(x1%2==1){
        Material(0.0, 0.0, 0.0, 0.55, 0.55, 0.55, 0.70, 0.70 ,0.70);
             glColor3f(1.0f,1.0f,1.0f);
            }
            else if(x1%2==0){
                    Material(0.0 ,0.0, 0.0, 0.01, 0.01, 0.01, 0.50, 0.50, 0.50 );
                glColor3f(1.0f,0.0f,0.0f);
                }
        }
        
   
    glBegin(GL_POLYGON);
    glNormal3f( 0.0f, 1.0f, 1.0f);
    glVertex3f(x,     0, z      );
    glNormal3f( 0.0f, 1.0f, 1.0f);
    glVertex3f(x,     0, z+1 );
    glNormal3f( 0.0f, 1.0f, 1.0f);
    glVertex3f(x+1,0, z+1 );
    glNormal3f( 0.0f, 1.0f, 1.0f);
    glVertex3f(x+1,     0, z );
    glEnd();
        }
    }
 
     //glDisable(GL_LIGHTING);
    //glDisable(GL_LIGHT0);
    //glDisable(GL_DEPTH_TEST);
    //glColor3f(0.914, 0.588, 0.478);
     //glBegin(GL_POLYGON);
    //glVertex3f(-4,     0, 1      );
    //glVertex3f(4,     0, 1 );
    //glVertex3f(4,6, 1 );
    //glVertex3f(-4,     6, 1 );
    //glEnd();
   
     //glBegin(GL_POLYGON);
    //glVertex3f(4,     0, 1      );
    //glVertex3f(4,     0, 9 );
    //glVertex3f(4,6, 9 );
    //glVertex3f(4,     6, 1 );
    //glEnd();
  
    //glBegin(GL_POLYGON);
    //glVertex3f(-4,     0, 1      );
    //glVertex3f(-4,     0, 9 );
    //glVertex3f(-4,6, 9 );
    //glVertex3f(-4,     6, 1 );
    //glEnd();
    //glFlush();
    glutSwapBuffers();

}



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



// Función para controlar teclas normales del teclado.
void keyboard(unsigned char key, int x, int y)
{
    //control de teclas que hacen referencia a Escalar y transladar el cubo en los ejes X,Y,Z.
    switch (key)
    {
    case 's':
        scale=0.18;
        break;
    case 'd':
        scale=1.5;
        break;
    case 'x' :
        X += 0.1f;
        break;
    case 'X' :
        X -= 0.1f;
        break;
    case 'y' :
        Y += 0.1f;
        break;
    case 'Y' :
        Y -= 0.1f;
        break;
    case 'z':
        Z -= 0.1f;
        break;
    case 'Z':
        Z += 0.1f;
        break;
    case 'q':
        exit(0);      // exit
    }
    glutPostRedisplay();
}

void reshape(int w, int h)
{
    glViewport(0, 0,  (GLsizei) w, (GLsizei) h);
// Activamos la matriz de proyeccion.
    glMatrixMode(GL_PROJECTION);
// "limpiamos" esta con la matriz identidad.
    glLoadIdentity();
// Usamos proyeccion ortogonal
    glOrtho(-2, 2, -2, 2, -2, 2);
// Activamos la matriz de modelado/visionado.
    glMatrixMode(GL_MODELVIEW);
// "Limpiamos" la matriz
    glLoadIdentity();
}


int main(int argc, char* argv[])
{

    //  Inicializar los parámetros GLUT y de usuario proceso
    glutInit(&argc,argv);

    // Solicitar ventana con color real y doble buffer con Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (0, 0);
    // Crear ventana
    glutCreateWindow("tablero");

    // Habilitar la prueba de profundidad de Z-buffer
    glEnable(GL_DEPTH_TEST);

    // Funciones de retrollamada
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    // Pasar el control de eventos a GLUT
    glutMainLoop();

    // Regresar al sistema operativo
    return 0;

}
