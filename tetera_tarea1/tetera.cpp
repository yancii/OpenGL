//MARIA YANCI MARTINEZ GARCIA  MG12040

//librerias a utilizar
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


//variables
double rotate_y=0;
double rotate_x=0;

GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 1.0f;
//**********************************************************************
//FUNCION INIT

void init(void)
{
    /* selecciona el color de borrado */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
}


//**********************************************************************
//FUNCION DISPLAY
void display(void)
{
 /* borra la pantalla */
 glClear (GL_COLOR_BUFFER_BIT);
 /* seleccionamos la matriz modelo/vista */
  glLoadIdentity();
  
    // Rotar en el eje X,Y y Z
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
   glTranslatef(X, Y,Z);   // Transladar en los 3 ejes
    
    // Otras transformaciones
    glScalef(scale, scale, scale);
    glMatrixMode(GL_MODELVIEW);
    /* color */
    glColor3f(1.0, 1.0, 1.0);

 /* transformación modelo/vista */
 gluLookAt(0.0,0.2,0.01, //punto de vista en el eje X,Y,Z
 0.0,0.0,0.0, //Centro del Objeto en el eje X,Y,Z
 0.0,1.0,0.0); //Orientación de la cámara (vector UP el eje X,Y,Z)
  glViewport(0,0,500,500);
 /* Dibujamos una tetera */
 glutWireTeapot(0.5);

 /* Vacia el buffer de dibujo */
 glFlush ();
}

//**********************************************************************
// FUNCION DE CONTROL DE TECLAS ESPECIALES
void specialKeys( int key, int x, int y )
{

    //  Flecha derecha: aumentar rotación 7 grados
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 1.8;

    //  Flecha izquierda: rotación en eje Y negativo 7 grados
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 1.8;
    //  Flecha arriba: rotación en eje X positivo 7 grados
    else if (key == GLUT_KEY_UP)
        rotate_x += 1.8;
    //  Flecha abajo: rotación en eje X negativo 7 grados
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 1.8;
    //  Solicitar actualización de visualización
    glutPostRedisplay();

}

//**********************************************************************
// FUNCION DE CONTROL DE TECLAS NORMALES (TECLADO)
void keyboard(unsigned char key, int x, int y)
{
//control de teclas que hacen referencia a Escalar y transladar el cubo 
//en los ejes X,Y,Z.
    switch (key)
    {
    case 'z':
        scale=0.5;
        break;
    case 'Z':
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
    case 'q':
        exit(0);      // exit
    }
    glutPostRedisplay();
}

//**********************************************************************
//FUNCION MAIN
int main(int argc, char** argv)
{
// Inicializa la librería auxiliar GLUT
    glutInit(&argc, argv);
// Inicializa el modo de visualización
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
// Indica el tamaño de la ventana (ancho,alto)
    glutInitWindowSize(500, 500);
// Indica la posición inicial (xmin,ymin)
    glutInitWindowPosition(100, 100);
// Abre la ventana con el título indicado
    glutCreateWindow("Dibujando una tetera 3d");
// Inicializar valores
    init();
//funcion para trasladar el objeto
    glutKeyboardFunc(keyboard);
// Indica cual es la función de dibujo
    glutDisplayFunc(display);
// Funcion para rotar el objeto
    glutSpecialFunc(specialKeys);
     
     
   //*******************************************************************  
    // FUNCIONES glEnable(GL_LIGHTING); glEnable(GL_LIGHT0);
    //glEnable(GL_COLOR_MATERIAL); glEnable(GL_NORMALIZE)
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL); // Permite que el color funcione junto con la iluminación
    glEnable(GL_NORMALIZE);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0); //Desarrollar textura
 
   // Luz y materiales
    glColor3f(0.000, 0.000,1.000); // Establecer color actual a azul
    GLfloat light_position[] = {1.0f, 0.0f, 0.0f,0.0}; // Desde la derecha
    GLfloat light_color[] = {0.529, 0.808, 0.980}; // luz azul
    GLfloat ambient_color[] = {0.000, 0.000, 1.000}; // Luz azul débil
    GLfloat mat_shininess[] = {50.0};
    GLfloat mat_ambientColor[] = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat mat_diffuseColor[] = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat mat_specularColor[] = {1.0f, 0.0f, 0.0f, 1.0f};
 
    // Establecer el material actual  
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambientColor);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuseColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specularColor);
 
    // Establecer luz
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_color);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_color);

// Comienza el bucle de dibujo y proceso de eventos.
    glutMainLoop();
}
