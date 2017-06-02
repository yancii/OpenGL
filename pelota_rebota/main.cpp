//Maria Yanci Martinez Garcia MG12040

#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

using namespace std;
 // Numero de frames
int frameNumber;   
int Max_Y=10;
int Min_Y=-1;
int Max_X=10;
int Min_X=-10;
float X1=-10;
float scale = 2;  // escala en  x, y, and z

float rotateX, rotateY;  // variables para rotación con teclas especiales 

void display() {
       // función dibujo 

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_PROJECTION);  // Set up the projection.
    glLoadIdentity();
    glOrtho(-10,10,-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);
    
    glLoadIdentity();             // configuración de matrix de identidad. 
    glTranslatef(Min_X,Min_Y,0.0);
    glRotatef(rotateY,0,1,0);
    glRotatef(rotateX,1,0,0);

    //  Codigo dibujar
    glColor3f(1.0,1.0,0.0);
    glutSolidSphere (0.5,10,10);
    glFlush ();
    glutSwapBuffers();    
}


// **********************************************************************************
//animacion

int animating = 0;      // 0 sin animación 
                        // Se cambia con la llamada a las funciones startAnimation() and pauseAnimation()
//******************************************************************************************************
void pauseAnimation() {
// Llamamo a la función para detener la animación 
    animating = 0;
}
//***************************************************************************************************

void updateFrame() {
   // funcion que contiene el codigo para que rebote la pelota
  
  glColor3f(0.0,1.0,0.0);
    if(Min_X<Max_X){
        if(Min_X<Max_X){
        Min_X+=1;
        printf ("Valor de Min_X: %d \n", Min_X);
         }
        if(Min_X==Max_X){
        X1=Min_X;
        Min_X=Max_X;
        Max_X=-8.0;
        }
        }
        if(Min_X==Max_X){
    if(Max_X<Min_X){
        if(Max_X<Min_X){
        Min_X-=1;
        printf ("Valor de Min_X: %d \n", Min_X);
        }
        if(Min_X==Max_X){
             X1=Min_X;
        Min_X=Max_X;
        Max_X=9.0;
            }
        }
        if(Min_Y<Max_Y){
        if(Min_Y<Max_Y){
        Min_Y++;
        printf ("Valor de Min_Y: %d \n", Min_Y);
         }
        if(Min_Y==Max_Y){
        X1=Min_Y;
        Min_Y=Max_Y;
        Max_Y=-3;   //elevacion en y negativo para rebote
        }
        }
    if(Max_Y<Min_Y){
        if(Max_Y<Min_Y){
        Min_Y--;
        printf ("Valor de Min_Y: %d \n", Min_Y);
        }
        if(Min_Y==Max_Y){
             X1=Min_Y;
        Min_Y=Max_Y;
        Max_Y=3;  //elevacion en y negativo para rebote
            }
        }
        
  //Hacemos que la pelota gire 
  for (int i=3; i<=500; i++){
    rotateY=rotateY-= i;
  }
   //Verificamos el numero de frames para detener animación 
   if(frameNumber==100)
    {
      pauseAnimation();
      frameNumber=0;
    }
  //n frames 
  frameNumber++;
  printf ("Numero Frame: %d \n", frameNumber);
}

void timerFunction(int timerID) {
      // controla el tiempo de la ejecucion de funciones 
    if (animating) {
        updateFrame();
        glutTimerFunc(30, timerFunction, 0);
        glutPostRedisplay();
    }
}

void startAnimation() {
      // inicia la animación 
   if ( ! animating ) {
       animating = 1;
       glutTimerFunc(30, timerFunction, 1);
   }
}



// —---------— Manejo de Teclado---------------------------------------------—


void key(unsigned char key, int x, int y) {
        // La animación inicia al presionar la tecla espaciadora de igual forma se detiene
    if ( key == ' ' ) {
    if ( animating )
       pauseAnimation();
  
    else
       startAnimation();
  }
  if (key == 27){
    exit(0);
  }
}

void special(int key, int x, int y) {
       // control de teclas especiales 
    if ( key == GLUT_KEY_LEFT )
       rotateY -= 15;
    else if ( key == GLUT_KEY_RIGHT )
       rotateY += 15;
    else if ( key == GLUT_KEY_DOWN)
       rotateX += 15;
    else if ( key == GLUT_KEY_UP )
       rotateX -= 15;
    else if ( key == GLUT_KEY_HOME )
       rotateX = rotateY = 0;
    glutPostRedisplay();
}

// —------------------—  Funcion principal —----------------

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("pelota_rebota");
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutSpecialFunc(special);
    glEnable(GL_DEPTH_TEST);

    frameNumber = 0;
    rotateX = rotateY = 0;
    
    // Activar iluminación 
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
    
    // Descomentar si queremos que la animación inicie al levantar el script
    startAnimation();

    glutMainLoop();
    return 0;
}
