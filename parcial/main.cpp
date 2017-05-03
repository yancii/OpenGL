// Maria Yanci Martinez Garcia MG12040


//con las flechas de direccion de derecha a izquierda con las teclas especiales se hace 
//la rotacion de 180 grados 
//con la "y" minuscula suba la cuerda y con la "Y" mayuscula baja 

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


void display()
{
    //  Borrar pantalla y Z-buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // Resetear transformaciones
    glLoadIdentity();
    // Rotar en el eje X,Y y Z
    //glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    //glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    //glRotatef( rotate_z, 0.0, 0.0, 1.0 );
    glTranslatef(X, Y, Z); 	// Transladar en los 3 ejes
    // Otras transformaciones
    glScalef(scale, scale, scale);
    // Primera cara, se identica por multiples colores
    glLoadIdentity();
     /* transformación modelo/vista */
    gluLookAt(0.1,0.2,0.2, //punto de vista en el eje X,Y,Z
              0.0,0.0,0.0, //Centro del Objeto en el eje X,Y,Z
              0.0,1.0,0.0); //Orientación de la cámara (vector UP el eje X,Y,Z)
  //glViewport(0,0,500,500);
  
  //******************************************************************************************************
  //cubo que esta parado
    glRotatef( -20, 4.0, -20.0, 0.05 );
    glTranslatef(-0.5, 0.0, 0.0);
    
    glColor3f( 1.0, 0.0, 0.0 );
    glBegin(GL_POLYGON);

    //glColor3f( 1.0, 1.0, 1.0 );
    glVertex3f(  0.1, -0.5, -0.1 );      // V1 Blanco
    //glColor3f( 1.0, 1.0, 0.0 );
    glVertex3f(  0.1,  0.5, -0.1 );      // V2 Amarillo
    //glColor3f( 0.0, 0.0, 1.0 );
    glVertex3f( -0.1,  0.5, -0.1 );      // V3 es azul
    //glColor3f( 1.0, 0.0, 0.0 );
    glVertex3f( -0.1, -0.5, -0.1 );      // V4 rojo

    glEnd();

    // LADO TRASERO: lado blanco
    glBegin(GL_POLYGON);
    glColor3f(1.0,  0.0,  0.0 );
    //glColor3f( 1.0,  1.0, 1.0 );
    glVertex3f( 0.1, -0.5, 0.1 );
    glVertex3f( 0.1,  0.5, 0.1 );
    glVertex3f(-0.1,  0.5, 0.1 );
    glVertex3f(-0.1, -0.5, 0.1 );
    glEnd();

    // LADO DERECHO: lado verde
    glBegin(GL_POLYGON);
    glColor3f( 0.0,  1.0,  0.0 );
    glVertex3f(0.1, -0.5, -0.1 );
    glVertex3f(0.1,  0.5, -0.1 );
    glVertex3f(0.1,  0.5,  0.1 );
    glVertex3f(0.1, -0.5,  0.1 );
    glEnd();

    // LADO IZQUIERDO: lado Amarillo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  1.0,  0.0 );
    glVertex3f(-0.1, -0.5,  0.1 );
    glVertex3f(-0.1,  0.5,  0.1 );
    glVertex3f(-0.1,  0.5, -0.1 );
    glVertex3f(-0.1, -0.5, -0.1 );
    glEnd();

    // LADO SUPERIOR: lado azul
    glBegin(GL_POLYGON);
    glColor3f(0.0,  0.0,  1.0 );
    glVertex3f(0.1,  0.5,  0.1 );
    glVertex3f(0.1,  0.5, -0.1 );
    glVertex3f(-0.1,  0.5, -0.1 );
    glVertex3f(-0.1,  0.5,  0.1 );
    glEnd();

    // LADO INFERIOR: lado rojo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  0.0,  0.0 );
    glVertex3f(0.1, -0.5, -0.1 );
    glVertex3f(0.1, -0.5,  0.1 );
    glVertex3f(-0.1, -0.5,  0.1 );
    glVertex3f(-0.1, -0.5, -0.1 );
    glEnd();

    glFlush();
    
    //******************************************************************************************************
    //cubo de base 
    
   // glRotatef( -20, 4.0, -20.0, 0.05 );
    glTranslatef(0.0, -0.6, 0.0);
    glColor3f( 0.0, 0.0, 1.0 );
    glBegin(GL_POLYGON);

    //glColor3f( 1.0, 1.0, 1.0 );
    glVertex3f(  0.2, -0.1, -0.1 );      // V1 Blanco
   // glColor3f( 1.0, 1.0, 0.0 );
    glVertex3f(  0.2,  0.1, -0.1 );      // V2 Amarillo
    //glColor3f( 0.0, 0.0, 1.0 );
    glVertex3f( -0.2,  0.1, -0.1 );      // V3 es azul
    //glColor3f( 1.0, 0.0, 0.0 );
    glVertex3f( -0.2, -0.1, -0.1 );      // V4 rojo

    glEnd();

    // LADO TRASERO: lado blanco
    glBegin(GL_POLYGON);
    glColor3f( 0.0, 0.0, 1.0 );
    //glColor3f( 1.0,  1.0, 1.0 );
    glVertex3f( 0.2, -0.1, 0.1 );
    glVertex3f( 0.2,  0.1, 0.1 );
    glVertex3f(-0.2,  0.1, 0.1 );
    glVertex3f(-0.2, -0.1, 0.1 );
    glEnd();

    // LADO DERECHO: lado verde
    glBegin(GL_POLYGON);
    glColor3f( 0.0,  1.0,  0.0 );
    glVertex3f(0.2, -0.1, -0.1 );
    glVertex3f(0.2,  0.1, -0.1 );
    glVertex3f(0.2,  0.1,  0.1 );
    glVertex3f(0.2, -0.1,  0.1 );
    glEnd();

    // LADO IZQUIERDO: lado Amarillo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  1.0,  0.0 );
    glVertex3f(-0.2, -0.1,  0.1 );
    glVertex3f(-0.2,  0.1,  0.1 );
    glVertex3f(-0.2,  0.1, -0.1 );
    glVertex3f(-0.2, -0.1, -0.1 );
    glEnd();

    // LADO SUPERIOR: lado azul
    glBegin(GL_POLYGON);
    glColor3f(0.0,  0.0,  1.0 );
    glVertex3f(0.2,  0.1,  0.1 );
    glVertex3f(0.2,  0.1, -0.1 );
    glVertex3f(-0.2,  0.1, -0.1 );
    glVertex3f(-0.2,  0.1,  0.1 );
    glEnd();

    // LADO INFERIOR: lado rojo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  0.0,  0.0 );
    glVertex3f(0.2, -0.1, -0.1 );
    glVertex3f(0.2, -0.1,  0.1 );
    glVertex3f(-0.2, -0.1,  0.1 );
    glVertex3f(-0.2, -0.1, -0.1 );
    glEnd();
    
    // Rotar en el eje X,Y y Z
    //glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    //glRotatef( rotate_z, 0.0, 0.0, 1.0 );

    glFlush();
    //******************************************************************************************************
    
    //cubo largo de arriba
    
    glTranslatef(0.5, 1.0, 0.0);

    glColor3f( 1.0, 0.0, 0.0 );
    glBegin(GL_POLYGON);

    //glColor3f( 1.0, 1.0, 1.0 );
    glVertex3f(  0.4, -0.1, -0.1 );      // V1 Blanco
   // glColor3f( 1.0, 1.0, 0.0 );
    glVertex3f(  0.4,  0.1, -0.1 );      // V2 Amarillo
    //glColor3f( 0.0, 0.0, 1.0 );
    glVertex3f( -0.4,  0.1, -0.1 );      // V3 es azul
   // glColor3f( 1.0, 0.0, 0.0 );
    glVertex3f( -0.4, -0.1, -0.1 );      // V4 rojo

    glEnd();

    // LADO TRASERO: lado blanco
    glBegin(GL_POLYGON);
    
     glColor3f( 1.0, 0.0, 0.0 ); //rojo
   // glColor3f( 1.0,  1.0, 1.0 );
    glVertex3f( 0.4, -0.1, 0.1 );
    glVertex3f( 0.4,  0.1, 0.1 );
    glVertex3f(-0.4,  0.1, 0.1 );
    glVertex3f(-0.4, -0.1, 0.1 );
    glEnd();

    // LADO DERECHO: lado verde
    glBegin(GL_POLYGON);
    glColor3f( 0.0,  1.0,  0.0 );
    glVertex3f(0.4, -0.1, -0.1 );
    glVertex3f(0.4,  0.1, -0.1 );
    glVertex3f(0.4,  0.1,  0.1 );
    glVertex3f(0.4, -0.1,  0.1 );
    glEnd();

    // LADO IZQUIERDO: lado Amarillo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  1.0,  0.0 );
    glVertex3f(-0.2, -0.1,  0.1 );
    glVertex3f(-0.4,  0.1,  0.1 );
    glVertex3f(-0.4,  0.1, -0.1 );
    glVertex3f(-0.4, -0.1, -0.1 );
    glEnd();

    // LADO SUPERIOR: lado azul
    glBegin(GL_POLYGON);
    glColor3f(0.0,  0.0,  1.0 );
    glVertex3f(0.4,  0.1,  0.1 );
    glVertex3f(0.4,  0.1, -0.1 );
    glVertex3f(-0.4,  0.1, -0.1 );
    glVertex3f(-0.4,  0.1,  0.1 );
    glEnd();

    // LADO INFERIOR: lado rojo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  0.0,  0.0 );
    glVertex3f(0.4, -0.1, -0.1 );
    glVertex3f(0.4, -0.1,  0.1 );
    glVertex3f(-0.4, -0.1,  0.1 );
    glVertex3f(-0.4, -0.1, -0.1 );
    glEnd();

    glFlush();
    
    //******************************************************************************************************
    
    //cubo pegado a la parte del cubo de arriba 
    
    glTranslatef(0.5, -0.098, 0.0);
    glBegin(GL_POLYGON);

    glColor3f( 1.0, 1.0, 1.0 );
    glVertex3f(  0.1, -0.2, -0.1 );      // V1 Blanco
    glColor3f( 1.0, 1.0, 0.0 );
    glVertex3f(  0.1,  0.2, -0.1 );      // V2 Amarillo
    glColor3f( 0.0, 0.0, 1.0 );
    glVertex3f( -0.1,  0.2, -0.1 );      // V3 es azul
    glColor3f( 1.0, 0.0, 0.0 );
    glVertex3f( -0.1, -0.2, -0.1 );      // V4 rojo

    glEnd();

    // LADO TRASERO: lado blanco
    glBegin(GL_POLYGON);
    //glColor3f(0.0,  0.0,  1.0 );
    glColor3f( 1.0,  0.0, 0.0 );
    glVertex3f( 0.1, -0.2, 0.1 );
    glVertex3f( 0.1,  0.2, 0.1 );
    glVertex3f(-0.1,  0.2, 0.1 );
    glVertex3f(-0.1, -0.2, 0.1 );
    glEnd();

    // LADO DERECHO: lado verde
    glBegin(GL_POLYGON);
    glColor3f( 0.0,  1.0,  0.0 );
    glVertex3f(0.1, -0.2, -0.1 );
    glVertex3f(0.1,  0.2, -0.1 );
    glVertex3f(0.1,  0.2,  0.1 );
    glVertex3f(0.1, -0.2,  0.1 );
    glEnd();

    // LADO IZQUIERDO: lado Amarillo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  1.0,  0.0 );
    glVertex3f(-0.1, -0.2,  0.1 );
    glVertex3f(-0.1,  0.2,  0.1 );
    glVertex3f(-0.1,  0.2, -0.1 );
    glVertex3f(-0.1, -0.2, -0.1 );
    glEnd();

    // LADO SUPERIOR: lado azul
    glBegin(GL_POLYGON);
    glColor3f(0.0,  0.0,  1.0 );
    glVertex3f(0.1,  0.2,  0.1 );
    glVertex3f(0.1,  0.2, -0.1 );
    glVertex3f(-0.1,  0.2, -0.1 );
    glVertex3f(-0.1,  0.2,  0.1 );
    glEnd();

    // LADO INFERIOR: lado rojo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  0.0,  0.0 );
    glVertex3f(0.1, -0.2, -0.1 );
    glVertex3f(0.1, -0.2,  0.1 );
    glVertex3f(-0.1, -0.2,  0.1 );
    glVertex3f(-0.1, -0.2, -0.1 );
    glEnd();

    glFlush();
    
    //******************************************************************************************************
    
    //cubo que simule una cuerda
    
    glTranslatef(0.0, -0.50, 0.0);
     glTranslatef(0.0,Y,0.0);
    glBegin(GL_POLYGON);

    glColor3f( 1.0, 1.0, 1.0 );
    glVertex3f(  0.025, -0.30, -0.025 );      // V1 Blanco
    glColor3f( 1.0, 1.0, 0.0 );
    glVertex3f(  0.025,  0.30, -0.025 );      // V2 Amarillo
    glColor3f( 0.0, 0.0, 1.0 );
    glVertex3f( -0.025,  0.30, -0.025 );      // V3 es azul
    glColor3f( 1.0, 0.0, 0.0 );
    glVertex3f( -0.025, -0.30, -0.025 );      // V4 rojo

    glEnd();

    // LADO TRASERO: lado blanco
    glBegin(GL_POLYGON);
    glColor3f( 0.0, 0.0, 1.0 );
    //glColor3f( 1.0,  1.0, 1.0 );
    glVertex3f( 0.025, -0.3, 0.025 );
    glVertex3f( 0.025,  0.3, 0.025 );
    glVertex3f(-0.025,  0.3, 0.025 );
    glVertex3f(-0.025, -0.3, 0.025 );
    glEnd();

    // LADO DERECHO: lado verde
    glBegin(GL_POLYGON);
    glColor3f( 0.0,  1.0,  0.0 );
    glVertex3f(0.025, -0.3, -0.025 );
    glVertex3f(0.025,  0.3, -0.025 );
    glVertex3f(0.025,  0.3,  0.025 );
    glVertex3f(0.025, -0.3,  0.025 );
    glEnd();

    // LADO IZQUIERDO: lado Amarillo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  1.0,  0.0 );
    glVertex3f(-0.025, -0.3,  0.025 );
    glVertex3f(-0.025,  0.3,  0.025 );
    glVertex3f(-0.025,  0.3, -0.025 );
    glVertex3f(-0.025, -0.3, -0.025 );
    glEnd();

    // LADO SUPERIOR: lado azul
    glBegin(GL_POLYGON);
    glColor3f(0.0,  0.0,  1.0 );
    glVertex3f(0.025,  0.3,  0.025 );
    glVertex3f(0.025,  0.3, -0.025 );
    glVertex3f(-0.025,  0.3, -0.025 );
    glVertex3f(-0.025,  0.3,  0.025 );
    glEnd();

    // LADO INFERIOR: lado rojo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  0.0,  0.0 );
    glVertex3f(0.025, -0.3, -0.025 );
    glVertex3f(0.025, -0.3,  0.025 );
    glVertex3f(-0.025, -0.3,  0.025 );
    glVertex3f(-0.025, -0.3, -0.025 );
    glEnd();
    
    

    glFlush();
    
    //******************************************************************************************************
    
    //cubo colgante de la cuerda 
    
    // glRotatef( -20, 4.0, -20.0, 0.05 );
    glTranslatef(0.003125, -0.30, 0.0);
    glColor3f( 1.0, 1.0, 1.0 );
   
    glBegin(GL_POLYGON);
    
    //glColor3f( 1.0, 1.0, 1.0 );
    glVertex3f(  0.05, -0.05, -0.05 );      // V1 Blanco
    //glColor3f( 1.0, 1.0, 0.0 );
    glVertex3f(  0.05,  0.05, -0.05 );      // V2 Amarillo
    //glColor3f( 0.0, 0.0, 1.0 );
    glVertex3f( -0.05,  0.05, -0.05 );      // V3 es azul
    //glColor3f( 1.0, 0.0, 0.0 );
    glVertex3f( -0.05, -0.05, -0.05 );      // V4 rojo

    glEnd();

    // LADO TRASERO: lado blanco
    glBegin(GL_POLYGON);
     glColor3f( 1.0, 0.0, 0.0 );
    //glColor3f( 1.0,  1.0, 1.0 );
    glVertex3f( 0.05, -0.05, 0.05 );
    glVertex3f( 0.05,  0.05, 0.05 );
    glVertex3f(-0.05,  0.05, 0.05 );
    glVertex3f(-0.05, -0.05, 0.05 );
    glEnd();

    // LADO DERECHO: lado verde
    glBegin(GL_POLYGON);
    glColor3f( 0.0,  1.0,  0.0 );
    glVertex3f(0.05, -0.05, -0.05 );
    glVertex3f(0.05,  0.05, -0.05 );
    glVertex3f(0.05,  0.05,  0.05 );
    glVertex3f(0.05, -0.05,  0.05 );
    glEnd();

    // LADO IZQUIERDO: lado Amarillo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  1.0,  0.0 );
    glVertex3f(-0.05, -0.05,  0.05 );
    glVertex3f(-0.05,  0.05,  0.05 );
    glVertex3f(-0.05,  0.05, -0.05 );
    glVertex3f(-0.05, -0.05, -0.05 );
    glEnd();

    // LADO SUPERIOR: lado azul
    glBegin(GL_POLYGON);
    glColor3f(0.0,  0.0,  1.0 );
    glVertex3f(0.05,  0.05,  0.05 );
    glVertex3f(0.05,  0.05, -0.05 );
    glVertex3f(-0.05,  0.05, -0.05 );
    glVertex3f(-0.05,  0.05,  0.05 );
    glEnd();

    // LADO INFERIOR: lado rojo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  0.0,  0.0 );
    glVertex3f(0.05, -0.05, -0.05 );
    glVertex3f(0.05, -0.05,  0.05);
    glVertex3f(-0.05, -0.05,  0.05 );
    glVertex3f(-0.05, -0.05, -0.05 );
    glEnd();


    glFlush();
    
    //******************************************************************************************************
    
    
    glLoadIdentity();
    
    //cubo  1 cerca del cubo de arriba
    
    glRotatef( -20, 4.0, -20.0, 0.05 );
    glTranslatef(0.5, -0.7, 0.0);
    glColor3f( 0.0,  1.0,  0.0 );
    glBegin(GL_POLYGON);

   // glColor3f( 1.0, 1.0, 1.0 );
    glVertex3f(  0.05, 0.0, -0.05 );      // V1 Blanco
    //glColor3f( 1.0, 1.0, 0.0 );
    glVertex3f(  0.05,  0.05, -0.05 );      // V2 Amarillo
    //glColor3f( 0.0, 0.0, 1.0 );
    glVertex3f( -0.05,  0.05, -0.05 );      // V3 es azul
    //glColor3f( 1.0, 0.0, 0.0 );
    glVertex3f( -0.05, -0.05, -0.05 );      // V4 rojo

    glEnd();

    // LADO TRASERO: lado blanco
    glBegin(GL_POLYGON);
    glColor3f( 1.0,  0.0,  0.0 );
    //glColor3f( 1.0,  1.0, 1.0 );
    glVertex3f( 0.05, -0.05, 0.05 );
    glVertex3f( 0.05,  0.05, 0.05 );
    glVertex3f(-0.05,  0.05, 0.05 );
    glVertex3f(-0.05, -0.05, 0.05 );
    glEnd();

    // LADO DERECHO: lado verde
    glBegin(GL_POLYGON);
    glColor3f( 1.0,  1.0,  0.0 );
    glVertex3f(0.05, -0.05, -0.05 );
    glVertex3f(0.05,  0.05, -0.05 );
    glVertex3f(0.05,  0.05,  0.05 );
    glVertex3f(0.05, -0.05,  0.05 );
    glEnd();

    // LADO IZQUIERDO: lado Amarillo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  1.0,  0.0 );
    glVertex3f(-0.05, -0.05,  0.05 );
    glVertex3f(-0.05,  0.05,  0.05 );
    glVertex3f(-0.05,  0.05, -0.05 );
    glVertex3f(-0.05, -0.05, -0.05 );
    glEnd();

    // LADO SUPERIOR: lado azul
    glBegin(GL_POLYGON);
    glColor3f(0.0,  0.0,  1.0 );
    glVertex3f(0.05,  0.05,  0.05 );
    glVertex3f(0.05,  0.05, -0.05 );
    glVertex3f(-0.05,  0.05, -0.05 );
    glVertex3f(-0.05,  0.05,  0.05 );
    glEnd();

    // LADO INFERIOR: lado rojo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  0.0,  0.0 );
    glVertex3f(0.05, -0.05, -0.05 );
    glVertex3f(0.05, -0.05,  0.05);
    glVertex3f(-0.05, -0.05,  0.05 );
    glVertex3f(-0.05, -0.05, -0.05 );
    glEnd();

    glFlush();
    
    //******************************************************************************************************
    
    glLoadIdentity();
    
    //cubo del suelo 2 parte de la cuerda cerca lado derecho
    
    glRotatef( -20, 4.0, -20.0, 0.05 );
    glTranslatef(0.3, -0.8, 0.0);
     glColor3f( 1.0, 1.0, 0.0 );
    glBegin(GL_POLYGON);

  
    //glColor3f( 1.0, 1.0, 1.0 );
    glVertex3f(  0.05, -0.05, -0.05 );      // V1 Blanco
   
    glVertex3f(  0.05,  0.05, -0.05 );      // V2 Amarillo
  
   // glColor3f( 0.0, 0.0, 1.0 );
    glVertex3f( -0.05,  0.05, -0.05 );      // V3 es azul

   // glColor3f( 1.0, 0.0, 0.0 );
    glVertex3f( -0.05, -0.05, -0.05 );      // V4 rojo

    glEnd();

    // LADO TRASERO: lado blanco
    glBegin(GL_POLYGON);
    glColor3f( 1.0,  1.0, 1.0 );
    glVertex3f( 0.05, -0.05, 0.05 );
    glVertex3f( 0.05,  0.05, 0.05 );
    glVertex3f(-0.05,  0.05, 0.05 );
    glVertex3f(-0.05, -0.05, 0.05 );
    glEnd();

    // LADO DERECHO: lado verde
    glBegin(GL_POLYGON);
    glColor3f( 0.0,  1.0,  0.0 );
    glVertex3f(0.05, -0.05, -0.05 );
    glVertex3f(0.05,  0.05, -0.05 );
    glVertex3f(0.05,  0.05,  0.05 );
    glVertex3f(0.05, -0.05,  0.05 );
    glEnd();

    // LADO IZQUIERDO: lado Amarillo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  1.0,  0.0 );
    glVertex3f(-0.05, -0.05,  0.05 );
    glVertex3f(-0.05,  0.05,  0.05 );
    glVertex3f(-0.05,  0.05, -0.05 );
    glVertex3f(-0.05, -0.05, -0.05 );
    glEnd();

    // LADO SUPERIOR: lado azul
    glBegin(GL_POLYGON);
    glColor3f(0.0,  0.0,  1.0 );
    glVertex3f(0.05,  0.05,  0.05 );
    glVertex3f(0.05,  0.05, -0.05 );
    glVertex3f(-0.05,  0.05, -0.05 );
    glVertex3f(-0.05,  0.05,  0.05 );
    glEnd();

    // LADO INFERIOR: lado rojo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  0.0,  0.0 );
    glVertex3f(0.05, -0.05, -0.05 );
    glVertex3f(0.05, -0.05,  0.05);
    glVertex3f(-0.05, -0.05,  0.05 );
    glVertex3f(-0.05, -0.05, -0.05 );
    glEnd();

    glFlush();
    
    //******************************************************************************************************************
    
    glLoadIdentity();
    
    //cubo del suelo  3  parte de abajo del dibujo
    
   
    
    glRotatef( -20, 4.0, -20.0, 0.05 );
    glTranslatef(0.1, -0.9, 0.0);
     glColor3f(1.0,  0.0,  0.0 );
    glBegin(GL_POLYGON);
     

   // glColor3f( 1.0, 1.0, 1.0 );
    glVertex3f(  0.05, -0.05, -0.05 );      // V1 Blanco
    
    //glColor3f( 1.0, 1.0, 0.0 );
    glVertex3f(  0.05,  0.05, -0.05 );// V2 Amarillo
   
    //glColor3f( 0.0, 0.0, 1.0 );
    glVertex3f( -0.05,  0.05, -0.05 );      // V3 es azul

    glVertex3f( -0.05, -0.05, -0.05 );      // V4 rojo

    glEnd();

    // LADO TRASERO: lado blanco
    glBegin(GL_POLYGON);
    glColor3f( 1.0,  1.0,  0.0 );
    //glColor3f( 1.0,  1.0, 1.0 );
    glVertex3f( 0.05, -0.05, 0.05 );
    glVertex3f( 0.05,  0.05, 0.05 );
    glVertex3f(-0.05,  0.05, 0.05 );
    glVertex3f(-0.05, -0.05, 0.05 );
    glEnd();

    // LADO DERECHO: lado verde
    glBegin(GL_POLYGON);
    glColor3f( 0.0,  1.0,  0.0 );
    glVertex3f(0.05, -0.05, -0.05 );
    glVertex3f(0.05,  0.05, -0.05 );
    glVertex3f(0.05,  0.05,  0.05 );
    glVertex3f(0.05, -0.05,  0.05 );
    glEnd();

    // LADO IZQUIERDO: lado Amarillo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  1.0,  0.0 );
    glVertex3f(-0.05, -0.05,  0.05 );
    glVertex3f(-0.05,  0.05,  0.05 );
    glVertex3f(-0.05,  0.05, -0.05 );
    glVertex3f(-0.05, -0.05, -0.05 );
    glEnd();

    // LADO SUPERIOR: lado azul
    glBegin(GL_POLYGON);
    glColor3f(0.0,  0.0,  1.0 );
    glVertex3f(0.05,  0.05,  0.05 );
    glVertex3f(0.05,  0.05, -0.05 );
    glVertex3f(-0.05,  0.05, -0.05 );
    glVertex3f(-0.05,  0.05,  0.05 );
    glEnd();

    // LADO INFERIOR: lado rojo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  0.0,  0.0 );
    glVertex3f(0.05, -0.05, -0.05 );
    glVertex3f(0.05, -0.05,  0.05);
    glVertex3f(-0.05, -0.05,  0.05 );
    glVertex3f(-0.05, -0.05, -0.05 );
    glEnd();

    glFlush(); 
    
    
    glutSwapBuffers();

}

//*******************************************************************************************************

// Función para controlar teclas especiales
void specialKeys( int key, int x, int y )
{

    //  Flecha derecha: aumentar rotación 7 grados
    if (key == GLUT_KEY_RIGHT){
        if(rotate_y<=90){
        rotate_y += 10;
    }
}
    //  Flecha izquierda: rotación en eje Y negativo 7 grados
    else if (key == GLUT_KEY_LEFT){
        if(rotate_y>=-90){
        rotate_y -= 7;
    }
    }
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
        scale=0.5;
        break;
    case 'd':
        scale=1.5;
        break;
    //case 'x' :
      //  X += 0.1f;
        //break;
    //case 'X' :
      //  X -= 0.1f;
        //break;
    case 'y' :
    if(Y<=0.4){
       Y += 0.1f;
   }
       
        break;
    case 'Y' :
    if(Y>0.1){
        Y -= 0.1f;
    }
        break;
    //case 'z':
      //  Z -= 0.1f;
        //break;
    //case 'Z':
      //  Z += 0.1f;
        //break;
    case 'q':
        exit(0);			// exit
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
    glOrtho(-1.5, 1.5, -1.5, 1.5, -1.5, 1.5);
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
    glutCreateWindow("Cubo controlado por teclas");

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
