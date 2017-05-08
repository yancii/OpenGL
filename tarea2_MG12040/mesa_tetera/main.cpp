//Maria yanci Martinez Garcia MG12040

#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

//Definimos variables
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;

GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 1.0f;

//*****************************************************************************************************************
//declarando variables para los materiales 
float ambiente1, ambiente2, ambiente3, diffuse1, diffuse2, diffuse3, specular1, specular2, specular3, shine;
void material(float ambiente1, float ambiente2, float ambiente3, float diffuse1, float diffuse2, float diffuse3, float specular1, float specular2, float specular3, float shine)
{  
    GLfloat mat_ambient_color[] = {ambiente1, ambiente2, ambiente3}; // le aplica una luz azul debil
    GLfloat mat_diffuseColor[] = {diffuse1, diffuse2, diffuse3}; //Diseminacion RGBA de la intensidad de la luz del ambiente
    
    GLfloat mat_specularColor[] = {specular1, specular2, specular3};
    GLfloat mat_shininess[] = {shine};
    
//**********************************************************************************************************
   // Establecer el material actual  
   glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuseColor);
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specularColor);
     glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess); 
     
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    GLfloat light_position[] = { 0.1, 0.5, 0.7, 13.0 };  //posicionando iluminacion 
    
    //GLfloat shine[] = {12.21794872f};
    //glMaterialfv(GL_FRONT, GL_SHININESS, shine);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
     glShadeModel(GL_SMOOTH);
     
 //****************************************************************************************************************    
     
       // Activamos la fuente de luz
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST); 
     
    
}
//*********************************************************************************************************************

void superficie_mesa()
{
    // Rotar en el eje X,Y y Z
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 1.0 );
    glScalef(scale, scale, scale);
    glMatrixMode(GL_MODELVIEW);
  
   
    gluLookAt(0.2, -0.2, -0.2, //punto de vista en el eje X,Y,Z para que empieze de una vista de planta
    0.0,0.0,0.0, //Centro del Objeto en el eje X,Y,Z
    0.0,1.0,0.0); //Orientación de la cámara (vector UP el eje X,Y,Z)
    
         material(0.05, 0.0, 0.0, 0.5, 0.4, 0.4, 0.7, 0.04, 0.04, 0.078125);
    
    glBegin(GL_POLYGON);
    glColor3f(0.0,  0.0,  1.0 );
    glVertex3f(0.2, -0.2, -0.2 );
    glVertex3f(0.2, -0.2,  0.2 );
    glVertex3f(-0.2, -0.2,  0.2 );
    glVertex3f(-0.2, -0.2, -0.2 );
    glEnd();
}

//***************************************************************************************************************
void tetera()
{
  
    // Rotar en el eje X,Y y Z
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 1.0 );
    //glTranslatef(X, Y, Z);   // Transladar en los 3 ejes
    // Otras transformaciones
    glScalef(scale, scale, scale);
  
    
   glLoadIdentity();
   
   material(0.0 ,0.0 ,0.0 ,0.5 ,0.5 ,0.0, 0.60 ,0.60 ,0.50 ,0.25);

   glTranslatef(0.1f, -0.10f, -0.2);
   //glColor3f(1.0,  1.0,  0.0 );
   glutSolidTeapot(0.05);
}

//*******************************************************************************************************************
void pata()
{
    // Rotar en el eje X,Y y Z
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 1.0 );
    //glTranslatef(X, Y, Z);   // Transladar en los 3 ejes
    // Otras transformaciones
    glScalef(scale, scale, scale);
    //glTranslatef(0.2f, -0.3f, 0.2f);
           
    gluLookAt(0.2, -0.2, -0.2, //punto de vista en el eje X,Y,Z para que empieze de una vista de planta
    0.0,0.0,0.0, //Centro del Objeto en el eje X,Y,Z
    0.0,1.0,0.0); //Orientación de la cámara (vector UP el eje X,Y,Z)
    
  double x=0.01, y=0.1, z=0.01;
  
  //**************************************************************************************************************
       material(0.2125, 0.1275, 0.054, 0.714, 0.4284, 0.18144, 0.393548, 0.271906, 0.166721, 0.2);
  glBegin(GL_POLYGON);
    glColor3f( 1.0, 1.0, 1.0 );
    glVertex3f(  x, -y, -z );      // V1 Blanco
    glColor3f( 1.0, 1.0, 0.0 );
    glVertex3f(  x,  y, -z );      // V2 Amarillo
    glColor3f( 0.0, 0.0, 1.0 );
    glVertex3f( -x,  y, -z );      // V3 es azul
    glColor3f( 1.0, 0.0, 0.0 );
    glVertex3f( -x, -y, -z );      // V4 rojo

    glEnd();


// LADO TRASERO: lado blanco
    glBegin(GL_POLYGON);
    glColor3f( 1.0,  1.0, 1.0 );
    glVertex3f( x, -y, z );
    glVertex3f( x,  y, z );
    glVertex3f(-x,  y, z );
    glVertex3f(-x, -y, z );
    glEnd();

    // LADO DERECHO: lado verde
    glBegin(GL_POLYGON);
    glColor3f( 1.0,  0.0,  0.0 );
    glVertex3f(x, -y, -z );
    glVertex3f(x,  y, -z );
    glVertex3f(x,  y,  z );
    glVertex3f(x, -y,  z);
    glEnd();

    // LADO IZQUIERDO: lado Amarillo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  1.0,  0.0 );
    glVertex3f(-x, -y,  z );
    glVertex3f(-x,  y,  z );
    glVertex3f(-x,  y, -z );
    glVertex3f(-x, -y, -z );
    glEnd();

    // LADO SUPERIOR: lado azul
    glBegin(GL_POLYGON);
    glColor3f(0.0,  0.0,  1.0 );
    glVertex3f(x,  y,  z );
    glVertex3f(x,  y, -z );
    glVertex3f(-x,  y, -z );
    glVertex3f(-x,  y,  z );
    glEnd();

    // LADO INFERIOR: lado rojo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  0.0,  0.0 );
    glVertex3f(x, -y, -z );
    glVertex3f(x, -y,  z );
    glVertex3f(-x, -y,  z );
    glVertex3f(-x, -y, -z );
    glEnd();
  
}
//*********************************************************************************************************************

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
    glTranslatef(X, Y, Z);   // Transladar en los 3 ejes
    // Otras transformaciones
    glScalef(scale, scale, scale);
    //rotate_y=rotate_y+45;
    //rotate_x=rotate_x+15;
    glMatrixMode(GL_MODELVIEW);
    
    
    gluLookAt(0.2, -0.2, -0.2, //punto de vista en el eje X,Y,Z para que empieze de una vista de planta
    0.0,0.0,0.0, //Centro del Objeto en el eje X,Y,Z
    0.0,1.0,0.0); //Orientación de la cámara (vector UP el eje X,Y,Z)
    
     material(0.0, 0.0, 0.0, 0.5, 0.5, 0.0, 0.60, 0.60, 0.50, 0.25);
    
    //*****************************************************************************************************
    // Primera cara, se identica por multiples colores
    glBegin(GL_POLYGON);
   

    glColor3f( 1.0, 1.0, 1.0 );
    glVertex3f(  0.4, -0.4, -0.4 );      // V1 Blanco
    glColor3f( 1.0, 1.0, 0.0 );
    glVertex3f(  0.4,  0.4, -0.4 );      // V2 Amarillo
    glColor3f( 0.0, 0.0, 1.0 );
    glVertex3f( -0.4,  0.4, -0.4 );      // V3 es azul
    glColor3f( 1.0, 0.0, 0.0 );
    glVertex3f( -0.4, -0.4, -0.4 );      // V4 rojo

    glEnd();
   
    

    // LADO DERECHO: lado verde
    glBegin(GL_POLYGON);
    glColor3f( 1.0,  0.0,  0.0 );
    glVertex3f(0.4, -0.4, -0.4 );
    glVertex3f(0.4,  0.4, -0.4 );
    glVertex3f(0.4,  0.4,  0.4 );
    glVertex3f(0.4, -0.4,  0.4 );
    glEnd();

 

    // LADO INFERIOR: lado rojo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  0.0,  0.0 );
    glVertex3f(0.4, -0.4, -0.4 );
    glVertex3f(0.4, -0.4,  0.4 );
    glVertex3f(-0.4, -0.4,  0.4 );
    glVertex3f(-0.4, -0.4, -0.4 );
    glEnd();
    
     
 
   glLoadIdentity(); 
   glTranslatef(0.2f, -0.25f, 0.2f);
   pata();
   
   
   glLoadIdentity(); 
   glTranslatef(-0.2f, -0.25f, 0.2f);
   pata();
   
    glLoadIdentity(); 
   glTranslatef(0.0f, -0.39f, -0.2f);
   pata();
    
    
    glLoadIdentity();
    tetera();
    
    glLoadIdentity();
    superficie_mesa();
  
  

    glFlush();
    glutSwapBuffers();

}

//*******************************************************************************************************************

//// Función para controlar teclas especiales
//void specialKeys( int key, int x, int y )
//{

    ////  Flecha derecha: aumentar rotación 7 grados
    //if (key == GLUT_KEY_RIGHT)
        //rotate_y += 7;

    ////  Flecha izquierda: rotación en eje Y negativo 7 grados
    //else if (key == GLUT_KEY_LEFT)
        //rotate_y -= 7;
    ////  Flecha arriba: rotación en eje X positivo 7 grados
    //else if (key == GLUT_KEY_UP)
        //rotate_x += 7;
    ////  Flecha abajo: rotación en eje X negativo 7 grados
    //else if (key == GLUT_KEY_DOWN)
        //rotate_x -= 7;
    ////  Tecla especial F2 : rotación en eje Z positivo 7 grados
    //else if (key == GLUT_KEY_F2)
        //rotate_z += 7;
    ////  Tecla especial F2 : rotación en eje Z negativo 7 grados
    //else if (key == GLUT_KEY_F2)
        //rotate_z -= 7;

////  Solicitar actualización de visualización
    //glutPostRedisplay();

//}

//*******************************************************************************************************************

//// Función para controlar teclas normales del teclado.
//void keyboard(unsigned char key, int x, int y)
//{
    ////control de teclas que hacen referencia a Escalar y transladar el cubo en los ejes X,Y,Z.
    //switch (key)
    //{
    //case 's':
        //scale=0.5;
        //break;
    //case 'd':
        //scale=1.5;
        //break;
    //case 'x' :
        //X += 0.1f;
        //break;
    //case 'X' :
        //X -= 0.1f;
        //break;
    //case 'y' :
        //Y += 0.1f;
        //break;
    //case 'Y' :
        //Y -= 0.1f;
        //break;
    //case 'z':
        //Z -= 0.1f;
        //break;
    //case 'Z':
        //Z += 0.1f;
        //break;
    //case 'q':
        //exit(0);      // exit
    //}
    //glutPostRedisplay();
//}

//*********************************************************************************************************

int main(int argc, char* argv[])
{

    //  Inicializar los parámetros GLUT y de usuario proceso
    glutInit(&argc,argv);

    // Solicitar ventana con color real y doble buffer con Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (0, 0);
    // Crear ventana
    glutCreateWindow("tetera_mesa");

    // Habilitar la prueba de profundidad de Z-buffer
    glEnable(GL_DEPTH_TEST);

    // Funciones de retrollamada
    glutDisplayFunc(display);
    //glutKeyboardFunc(keyboard);
    //glutSpecialFunc(specialKeys);

    // Pasar el control de eventos a GLUT
    glutMainLoop();

    // Regresar al sistema operativo
    return 0;

}
