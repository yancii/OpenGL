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
//Materiales_Que_Contendran_Los_Materiales
float ambiente1, ambiente2, ambiente3, diffuse1, diffuse2, diffuse3, specular1, specular2, specular3, shine;
void Material(float ambiente1, float ambiente2, float ambiente3, float diffuse1, float diffuse2, float diffuse3, float specular1, float specular2, float specular3)
{  
    GLfloat mat_ambient_color[] = {ambiente1, ambiente2, ambiente3}; 
    GLfloat mat_diffuseColor[] = {diffuse1, diffuse2, diffuse3}; 
    
    GLfloat mat_specularColor[] = {specular1, specular2, specular3};
    GLfloat mat_shininess[] = {shine};
    
   //Aplicando_Materiales  
   glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuseColor);
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specularColor);
     glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess); 
     
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    GLfloat light_position[] = { 0.0, 0.5, 0.01, 0.0 };  
    

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
     glShadeModel(GL_SMOOTH);
     
       // Activamos la fuente de luz
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST); 
     
}

void Vistas(){
// Activamos la matriz de proyeccion.
    glMatrixMode(GL_PROJECTION);
// "limpiamos" esta con la matriz identidad.
    glLoadIdentity();
// Usamos proyeccion ortogonal
    glOrtho(-3, 3, -3, 3, -3, 3);
// Activamos la matriz de modelado/visionado.
    glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     gluLookAt(0.1,0.2,0.2, //punto de vista en el eje X,Y,Z
              0.0,0.0,0.0, //Centro del Objeto en el eje X,Y,Z
              0.0,1.0,0.0); //Orientació
    
// "Limpiamos" la matriz
    glLoadIdentity();
}

void display()
{
    //  Borrar pantalla y Z-buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    
    // Resetear transformaciones
    glLoadIdentity();
     /* transformación modelo/vista */
     
    Vistas();
    // Rotar en el eje X,Y y Z
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 1.0 );
    glTranslatef(X, Y, Z);   // Transladar en los 3 ejes
    // Otras transformaciones
    glScalef(scale, scale, scale);
    Material(0.24725, 0.1995, 0.0745, 0.75164, 0.60648, 0.22648, 0.628281, 0.555802, 0.366065);
    glRotatef( -7, 0.0, 1.0, 0.0 );
    glRotatef( 7, 1.0, 0.0, 0.0 );
    //Cubo_Centro
    glutSolidCube (0.5); 
    glLoadIdentity();
    Vistas();
    glTranslatef(-1.0, Y, Z);
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 1.0 );
    glRotatef( 7, 1.0, 0.0, 0.0 );
    glRotatef( -7, 0.0, 1.0, 0.0 );
    Material(0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.7, 0.6, 0.6);
    //Esfera_Izquierda
    glutSolidSphere (0.25,30,5); 
    glLoadIdentity();
    Vistas();
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 1.0 );
    glRotatef( 7, 1.0, 0.0, 0.0 );
    glRotatef( -7, 0.0, 1.0, 0.0 );
    glTranslatef(1, -0.25, 0);
    glRotatef( -90, 1.0, 0.0, 0.0 );
    glRotatef( 170, 0.0, 0.0, 1.0 );
    Material(0.0, 0.0, 1.000, 0.0, 0.0, 0.0, 0.70, 0.70, 0.70);
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };  
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    //Cono_Derecha
    glutSolidCone (0.25, 0.5,30,5);
   
    glFlush();
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
        rotate_x -= 10;
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
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    // Pasar el control de eventos a GLUT
    glutMainLoop();

    // Regresar al sistema operativo
    return 0;

}
