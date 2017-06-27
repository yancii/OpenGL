//LUIS FERNANDO HERNANDEZ CASTILLO HC12012
//MARIA YANCI MARTINEZ GARCIA MG12040
//DUGLAS ENRIQUE DIAZ BARAHONA DB12001

//Librerias a utilizar
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <stdio.h>
#include <SOIL/SOIL.h> //Libreria para el uso de Texturas
#include <stdlib.h>
#include <cstdio>
#include <SDL/SDL.h>
//Llamando el archivo de sonido

#define MUS_PATH "juego.wav"

//Prototipo de nuestra devolución de llamada de audio
// Ver la implementación para más información

void my_audio_callback(void *userdata, Uint8 *stream, int len);

// Declaraciones de variables
static Uint8 *audio_pos; // Puntero global al búfer de audio que se va a reproducir
static Uint64 audio_len; // Longitud restante de la muestra que tenemos que jugar

//Función de devolución de llamada de audio
//Aquí tiene que copiar los datos de su buffer de audio en el
// Solicitud de búfer de audio (secuencia)
//Sólo debe copiar tanto como la longitud solicitada (len)

void my_audio_callback(void *userdata, Uint8 *stream, int len) 
{

	if (audio_len ==0)
		return;

	len = ( len > audio_len ? audio_len : len );
	//SDL_memcpy (stream, audio_pos, len); 					// Simplemente copie desde un buffer en el otro
	SDL_MixAudio(stream, audio_pos, len, SDL_MIX_MAXVOLUME);// Mezclar de un buffer a otro

	audio_pos += len ;
	audio_len -= len ;
}


using namespace std;
int animating = 0;      // 0 sin animación 
                        // Se cambia con la llamada a las funciones startAnimation() and pauseAnimation()

double cambio=0.0;
//guarda las texturas

GLuint texture[0];
int frameNumber;   // Numero de frames
float scale = 2;  // escala en  x, y, and z
float Xe=0;
float Ye=0;
float Ze=0;

//Variables que controlan el movimiento de la camara
float X1=0;

//float Y1=5;
float Z1=0;

//Variables que capturan los movimientos de la nave

//Movimientos X,Y,Z
double X=0;
double Y=3;
double Z=10.0;
double X0=0;

//Movimientos del Disparo 
double Xd=1.5;
double Yd=0.0;
double Zd=0.0;

//Si a ocurrido un choque k=1
int k=0;
double k1=0.2;

//Disparo
int fuego=0;

//Rotacion
float rotateX;

//Cuenta el numero de enemigos eliminados
int n=0;

//Variables que capturan el movimiento de los enemigos

//capturan el Movimiento del Enemigo 1
//Movimientos
double x1=10;
double y1=10;
double z1=10;
int esquina1=1;
int x1e=0;
int posicionen1=0;
double objetivo_enemigo1=0.2;
float rotateY1; 
float rotateX1;

//capturan el Movimiento del Enemigo 2
//movimientos
double x2=60;
double y2=5;
double z2=10;
int esquina2=1;
int x2e=0;
int posicionen2=0;

//Captura la Posicion del enemigo 2
double objetivo_enemigo2=0.2;
float rotateY2; 
float rotateX2;

//capturan el Movimiento del Enemigo 3
//movimientos
double x3=18;
double y3=12;
double z3=10;
int esquina3=1;
int x3e=0;
int posicionen3=0;

//Captura la Posicion del enemigo 3
double objetivo_enemigo3=0.2;
float rotateY3; 
float rotateX3;

//capturan el Movimiento del Enemigo 4
//movimientos
double x4=55;
double y4=27;
double z4=10;
int esquina4=1;
int x4e=0;
int posicionen4=0;

//Captura la Posicion del enemigo 4
double objetivo_enemigo4=0.2;
float rotateY4; 
float rotateX4;

//capturan el Movimiento del Enemigo 5
//movimientos
double x5=70;
double y5=22;
double z5=10;
int esquina5=1;
int x5e=0;
int posicionen5=0;

//Captura la Posicion del enemigo 5
double objetivo_enemigo5=0.2;
float rotateY5; 
float rotateX5;


void camara(int w, int h)
{

    // Evitar una división por cero, cuando la ventana es demasiado pequeña
    // (No permitir una ventana de alto 0).
    if (h == 0)
        h = 1;
        float proporcion = w * 1.0 / h;

    // Usando Matrix proyección
    glMatrixMode(GL_PROJECTION);

    // Reseteando la Matrix
    glLoadIdentity();

    // configurar el viewport para una ventana completa
    glViewport(0, 0, w, h);

    // Configurando las perspectivas.
    glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 90.0);


    // Regresar la vista a Modelview
    glMatrixMode(GL_MODELVIEW);
}

void text()
{
    char text[62];
    char text2[60];
    char text3[32];
     if(n!=15){//***
    if(animating==1){
        sprintf(text, "Enemigos : %d",n);
        glColor3f(1.0, 1.000, 1.000);
        glRasterPos3f( X-2.5 , Y+8.5 , Z+5);
        for(int i = 0; text[i] != '\0'; i++){
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
            }  
        sprintf(text2, "A:Retroceder D:Adelantar W:Subir S:Bajar");
        glColor3f(1.0, 1.000, 1.000);
        glRasterPos3f( X-2.1 , Y+9.4 , Z+6);
        for(int i = 0; text2[i] != '\0'; i++){
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text2[i]);
            }
        sprintf(text3, "X:Acercar E:Disparar Z:Alejar");
        glColor3f(1.0, 1.000, 1.000);
        glRasterPos3f( X-2.1 , Y+8.8 , Z+6);
        for(int i = 0; text3[i] != '\0'; i++){
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text3[i]);
            }
       
    }
    else{
        sprintf(text, "Has perdido ! Pulse la barra de espacio para iniciar");
        glColor3f(1.000, 1.0, 1.000);
        glRasterPos3f( X-1 , Y+5.0 , Z+5);
        for(int i = 0; text[i] != '\0'; i++){
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
            }
    }
   }//***
    else{//***
            sprintf(text, "Mision Completada!!!Gracias por jugar, presione esq para salir");//***
    glColor3f(1.000, 1.0, 1.000);//***
    glRasterPos3f( X+1 , Y+2.0 , Z+5);//***
    for(int i = 0; text[i] != '\0'; i++){//**
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);}//***
       }//***
}

void ColorAlpha(float c1,float c2,float c3, float c4)
{
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glShadeModel (GL_FLAT);
    glClearColor (1,1,1, 1);
    glColor4f(c1,c2,c3,c4);
}
//Funcion que establece el fondo
static void fondo (GLfloat x, GLfloat y, GLfloat z,int horizontal,int vertical)
{
   
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_COMBINE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glPushMatrix();
    glTranslatef (x-25, y, z);
    glBegin(GL_POLYGON);
    glTexCoord2f(horizontal, 0.0f);
    
    glVertex3f(0,0,0);
    glTexCoord2f(0.0f, 0.0f);
    
    glVertex3f(210,0,0);
    glTexCoord2f(0.0f, vertical);
    
    glVertex3f(210,110,0);
    glTexCoord2f(horizontal, vertical);
    glVertex3f(0,110,0);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

//Funcion que establece el fondo
static void fondo1 (GLfloat x, GLfloat y, GLfloat z)
{
    ColorAlpha(0.118, 0.565, 1.000, cambio);
    glPushMatrix();
    glTranslatef (x-25, y, z);
    glBegin(GL_POLYGON);

    glVertex3f(0,0,0);
    glVertex3f(250,0,0);
    glVertex3f(250,150,0);
    glVertex3f(0,150,0);
    glEnd();
    glPopMatrix();
    //desactivando color alpha
    glDisable (GL_BLEND);

}

//Funcion para dibujar arboles
void Arbol(GLfloat x, GLfloat y, GLfloat z)
{
    glPushMatrix();
    glTranslatef(x,y,z);
    glRotatef(-90,1,0,0);
    glutSolidCone (1,2,10,10); 
    glPopMatrix();
}

void Tronco(GLfloat x, GLfloat y, GLfloat z)
{
    glPushMatrix();
    glTranslatef(x,y,z);
    glScalef(0.2,1.5,0.2);
    glutSolidCube (1); 
    glPopMatrix();
}

//Funcion que dibuja Edificios

static void edificio (GLfloat x, GLfloat y, GLfloat z, int vertical, int horizontal)
{
         
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_COMBINE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glPushMatrix();
    glTranslatef (x, y, z);
    glBegin(GL_POLYGON);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(  0.3, -0.3, -0.3 );      
    glTexCoord2f(0.0f, vertical);
    glVertex3f(  0.3,  0.3, -0.3 );      
    glTexCoord2f(horizontal,vertical);
    glVertex3f( -0.3,  0.3, -0.3 );      
    glTexCoord2f(horizontal, 0.0f);
    glVertex3f( -0.3, -0.3, -0.3 );     

    glEnd();

    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.3, -0.3, -0.3 );
    glTexCoord2f(0.0f, vertical);
    glVertex3f(0.3,  0.3, -0.3 );
    glTexCoord2f(horizontal, vertical);
    glVertex3f(0.3,  0.3,  0.3 );
    glTexCoord2f(horizontal, 0.0f);
    glVertex3f(0.3, -0.3,  0.3 );
    glEnd();

    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.3, -0.3,  0.3 );
    glTexCoord2f(0.0f, vertical);
    glVertex3f(-0.3,  0.3,  0.3 );
    glTexCoord2f(horizontal, vertical);
    glVertex3f(-0.3,  0.3, -0.3 );
    glTexCoord2f(horizontal, 0.0f);
    glVertex3f(-0.3, -0.3, -0.3 );
    glEnd();

    // LADO SUPERIOR: Negro
    glBegin(GL_POLYGON);
    glColor3f(0.0,  0.0,  0.0 );
    glVertex3f(0.3,  0.3,  0.3 );
    glVertex3f(0.3,  0.3, -0.3 );
    glVertex3f(-0.3,  0.3, -0.3 );
    glVertex3f(-0.3,  0.3,  0.3 );
    glEnd();
    glPopMatrix();
  
    
}

//Funcion que establece el Suelo
static void suelo (GLfloat x, GLfloat y, GLfloat z,int vertical, int horizontal)
{
   
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_COMBINE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glPushMatrix();
    glTranslatef (x-20, y, z-10);
    glRotatef(90,1,0,0);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0,0,0);
    glTexCoord2f(0.0f, vertical);
    glVertex3f(190,0,0);
    glTexCoord2f(horizontal, vertical);
    glVertex3f(190,50,0);
    glTexCoord2f(horizontal, 0.0f);
    glVertex3f(0,50,0);
    glEnd();
    glPopMatrix();

}

void Material(float amb1,float amb2,float amb3,float dif1, float dif2,float dif3,float spe1,float spe2, float spe3)
{
    //Activando Los Materiales
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    // Propiedades del material
    GLfloat mat_ambient[] = { amb1,amb2,amb3   };
    GLfloat mat_diffuse[] = {  dif1,dif2,dif3 };
    GLfloat mat_specular[] = {  spe1,spe2,spe3 };
    //setMaterial
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
}

//Dibujando la nave del Jugador
//parte frontal de la nave
static void frontal (GLfloat x, GLfloat y, GLfloat z)
{
    
    glPushMatrix();
    glTranslatef (x, y, z);
    glRotatef(90,0,1,0);
    glutSolidCone(0.8,0.8,16,16);
    glPopMatrix();

}

//parte intermedia de la nave
static void medio (GLfloat x, GLfloat y, GLfloat z)
{

    glPushMatrix();
    glTranslatef (x, y, z);
    glScalef(0.7,0.8,0.8);
    glTranslatef(-0.50,0,0);
    //setMaterial
    glutSolidCube(1);
    glPopMatrix();

}

//Alas de la nave
static void alas (GLfloat x, GLfloat y, GLfloat z)
{
    glPushMatrix();
    glTranslatef (x, y, z);
    glTranslatef (-0.6, 0.5, 0);
    glPushMatrix();
    glRotatef(-90,0,0,1);
    glBegin(GL_TRIANGLES);
    glVertex3f(-1.2,0,0);
    glVertex3f(0,1.2,0);
    glVertex3f(1.2,0,0);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

//Naves enemigas
static void enemigo1 (GLfloat x, GLfloat y, GLfloat z)
{
    glPushMatrix();
    glTranslatef (x, y, z);
    glRotatef(90,1,0,0);
    glScalef(1.6,1.6,0.6);//Platillo
    glutSolidTorus (0.30, 0.3,15,15);
    glPushMatrix();
    glScalef(1.3,1.3,2.5);
    glutSolidSphere (0.25,15,15);//Centro
    glPopMatrix();
    glPopMatrix();
    
}

void display() 
{
    // LLamada a función dibujo 

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glLoadIdentity();
    // Configurando camara
    gluLookAt(	X1=X+3, Y, Z1=Z+20, X+8, Y+2, Z, 0.0f, 1.0f, 0.0f);
    text();
    GLfloat light_position[] = { 110, 100, 20, 1.0 };
    GLfloat shine[] = {15.21794872f};
    glMaterialfv(GL_FRONT, GL_SHININESS, shine);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glShadeModel(GL_SMOOTH);
    
    // Aplicando textura

    texture[0] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
    (
        "Fondo1.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );
    
    texture[1] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
    (
        "ventana1.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );
    
     texture[2] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
    (
        "Suelo1.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );
   
    texture[3] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
    (
        "Pavimento1.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );
    
    //Suelo
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[3]);
    glPushMatrix();
    glTranslatef(Xe,Ye,Ze);
    glColor3f(1,1,1);
    suelo(0,0,-30,20,20);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    
    //Suelo
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[2]);
    glPushMatrix();
    glTranslatef(Xe,Ye,Ze);
    glColor3f(1,1,1);
    suelo(0,0,20,10,10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
   
    //Fondo 
    glPushMatrix();
    glPushMatrix();
    glTranslatef(Xe,Ye,Ze-17);
    glColor3f(1,1,1);
    fondo(0,0,0,10,10);
    glPopMatrix();
    glPopMatrix();
  
    glPushMatrix();
 
    glPushMatrix();
    glTranslatef(0,0,-16);
    fondo1(0,0,-0.1);
    glPopMatrix();
    glPopMatrix();
    
    //Arboles
    for(int i =-10;i<150;i+=5){
        for(int j=12;j<50;j+=10){
        glPushMatrix();
        Material(0.0, 0.0, 0.0, 0.1, 0.35, 0.1, 0.45, 0.55, 0.45 );
        Arbol(i,1,j);
        Material(0.05, 0.05, 0.05, 0.5, 0.5, 0.5, 0.7, 0.7, 0.7 );
        Tronco(i,0.5,j);
        }
    }
    
    //Desactivando Materiales
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glPopMatrix();
    
    //Edificio1 
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glPushMatrix();
    glTranslatef(-2,21,0);
    glRotatef(180,0,1,0);
    glScalef(10,70,5);
    glColor3f(1,1,1);
    edificio(0,0,0,15,4);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    
    //Edificio2 
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glPushMatrix();
    glTranslatef(8,15,0);
    glRotatef(180,0,1,0);
    glScalef(20,50,15);
    glColor3f(1,1,1);
    edificio(0,0,0,10,8);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    
    //Edificio3 
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glPushMatrix();
    glTranslatef(100,21,4);
    glRotatef(180,0,1,0);
    glScalef(10,70,5);
    glColor3f(1,1,1);
    edificio(0,0,0,15,4);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    
    //Edificio4 
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glPushMatrix();
    glTranslatef(90,15,4);
    glRotatef(180,0,1,0);
    glScalef(20,50,15);
    glColor3f(1,1,1);
    edificio(0,0,0,10,8);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
  
    //Edificio5 
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glPushMatrix();
    glTranslatef(20,21,-5);
    glRotatef(180,0,1,0);
    glScalef(10,70,5);
    glColor3f(1,1,1);
    edificio(0,0,0,15,4);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    
    //Edificio6 
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glPushMatrix();
    glTranslatef(30,15,-4);
    glRotatef(180,0,1,0);
    glScalef(20,50,15);
    glColor3f(1,1,1);
    edificio(0,0,0,10,8);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    
    //Edificio7 
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glPushMatrix();
    glTranslatef(55,21,4);
    glRotatef(180,0,1,0);
    glScalef(10,70,5);
    glColor3f(1,1,1);
    edificio(0,0,0,15,4);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    
    //Edificio8 
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glPushMatrix();
    glTranslatef(45,22,-4);
    glRotatef(180,0,1,0);
    glScalef(20,75,15);
    glColor3f(1,1,1);
    edificio(0,0,0,14,7);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
  
    //Edificio9 
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glPushMatrix();
    glTranslatef(60,15,-4);
    glRotatef(180,0,1,0);
    glScalef(20,50,15);
    glColor3f(1,1,1);
    edificio(0,0,0,10,8);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
  
    //Edificio10 
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glPushMatrix();
    glTranslatef(75,15,0);
    glRotatef(180,0,1,0);
    glScalef(20,50,15);
    glColor3f(1,1,1);
    edificio(0,0,0,10,8);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
  
    //Edificio11 
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glPushMatrix();
    glTranslatef(110,21,0);
    glRotatef(180,0,1,0);
    glScalef(10,70,5);
    glColor3f(1,1,1);
    edificio(0,0,0,15,4);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    //Edificio12 
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glPushMatrix();
    glTranslatef(120,15,0);
    glRotatef(180,0,1,0);
    glScalef(20,50,15);
    glColor3f(1,1,1);
    edificio(0,0,0,10,8);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
  
    //Edificio13 
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glPushMatrix();
    glTranslatef(135,21,4);
    glRotatef(180,0,1,0);
    glScalef(10,70,5);
    glColor3f(1,1,1);
    edificio(0,0,0,15,4);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    
    //Edificio14 
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glPushMatrix();
    glTranslatef(140,15,4);
    glRotatef(180,0,1,0);
    glScalef(20,50,15);
    glColor3f(1,1,1);
    edificio(0,0,0,10,8);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //Edificio15
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glPushMatrix();
    glTranslatef(-14,15,4);
    glRotatef(180,0,1,0);
    glScalef(20,50,15);
    glColor3f(1,1,1);
    edificio(0,0,0,10,8);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    //dibujando el Jugador
   
    //frente
    //Aplicando Material
    Material(0.1745, 0.01175, 0.01175,0.61424, 0.04136, 0.04136,0.727811, 0.626959, 0.626959);
    glPushMatrix();
    glTranslatef(X,Y,Z);
    glRotatef(rotateX,1,0,0);
    frontal(0,0,0);
    glPopMatrix();
    //Desactivando Materiales
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    //medio
    //Aplicando Material
    Material(0.0, 0.0, 0.0, 0.55, 0.55, 0.55, 0.70, 0.70, 0.70  );
    glPushMatrix();
    glTranslatef(X,Y,Z);
    glRotatef(rotateX,1,0,0);
    medio(0,0,0);
    glTranslatef(X,Y+5,10);
    glPopMatrix();
    //Desactivando Materiales
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    //alas
    Material(0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.7, 0.6, 0.6 );
    glPushMatrix();
    glTranslatef(X,Y,Z);
    glRotatef(rotateX,1,0,0);
    alas(0,-0.5,0);
    glPopMatrix();
    //Desactivando Materiales
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    //fuego de la nave  posicion en Y es diferente y1 es diferente 
    ColorAlpha(0.000, 1.000, 0.000, 0.60);
    glPushMatrix();
    Xd=X;
    Yd=Y;
    Zd=Z;
    if(fuego==1 and (Y!=y1 ) and (Y != y2) and (Y !=y3) and (Y != y4) and (Y !=y5) )
    {
        glLineWidth(5);
        glBegin(GL_LINES);
        glVertex3f(Xd,Yd,Zd);
        glVertex3f(Xd+30,Yd,Zd);
        glEnd();
        fuego=0;
        glLineWidth(1);
	}
    glPopMatrix();
    //desactivando color alpha
    glDisable (GL_BLEND);
    
    ColorAlpha(0.000, 1.000, 0.00, 0.60);
    
    //fuego de la nave posicion en Y y y1 son iguales enemigo 1
    glPushMatrix();
    if(fuego ==1 and Y==y1 and Z==z1 and x1>X) 
    {
        if(Y==y1 and Z==z1 and x1>X)
        {
            glLineWidth(5);
            glBegin(GL_LINES);
            glVertex3f(Xd,Yd,Zd);
            glVertex3f(x1,y1,z1);
            glEnd();
            glLineWidth(1);
            x1e=1;
            n++;
            fuego=0;
        }
    }
    glPopMatrix();
 
    //fuego de la nave posicion en Y y y2 son iguales enemigo 2
    glPushMatrix();
    if(fuego ==1 and Y==y2 and Z==z2 and x2>X) 
    {
        if(Y==y2 and Z==z2 and x2>X)
        {
            glLineWidth(5);
            glBegin(GL_LINES);
            glVertex3f(Xd,Yd,Zd);
            glVertex3f(x2,y2,z2);
            glEnd();
            glLineWidth(1);
            x2e=1;
            n++;
            fuego=0;
        }
    }
    glPopMatrix();
 
    //fuego de la nave posicion en Y y y3 son iguales enemigo 3
    glPushMatrix();
    if(fuego ==1 and Y==y3 and Z==z3 and x3>X)
    {
        if(Y==y3 and Z==z3 and x3>X)
        {
            glLineWidth(5);
            glBegin(GL_LINES);
            glVertex3f(Xd,Yd,Zd);
            glVertex3f(x3,y3,z3);
            glEnd();
            glLineWidth(1);
            x3e=1;
            n++;
            fuego=0;
        }
    }
    glPopMatrix();
    
    //fuego de la nave posicion en Y y y4 son iguales enemigo 4
    glPushMatrix();
    if(fuego ==1 and Y==y4 and Z==z4 and x4>X) 
    {
        if(Y==y4 and Z==z4 and x4>X)
        {
            glLineWidth(5);
            glBegin(GL_LINES);
            glVertex3f(Xd,Yd,Zd);
            glVertex3f(x4,y4,z4);
            glEnd();
            glLineWidth(1);
            x4e=1;
            n++;
            fuego=0;
        }
    }
    glPopMatrix();
 
    //fuego de la nave posicion en Y y y5 son iguales enemigo 5
    glPushMatrix();
    if(fuego ==1 and Y==y5 and Z==z5 and x5>X) 
    {
        if(Y==y5 and Z==z5 and x5>X)
        {
            glLineWidth(5);
            glBegin(GL_LINES);
            glVertex3f(Xd,Yd,Zd);
            glVertex3f(x5,y5,z5);
            glEnd();
            glLineWidth(1);
            x5e=1;
            n++;
            fuego=0;
        }
    }
    
    //desactivando color alpha
    glDisable (GL_BLEND);
    glPopMatrix();
    
    //enemigos
    Material(0.19225, 0.19225, 0.19225, 0.50754, 0.50754, 0.50754, 0.508273, 0.508273, 0.508273);
    
    //enemigo 1
    glPushMatrix();
    glTranslatef(x1,y1,z1);
    glRotatef(rotateY1,0,1,0);
    glRotatef(rotateX1,1,0,0);
    enemigo1(0,0,0);
    glPopMatrix();
    //Desactivando Materiales
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    //Objetivo Enemigo 1
    glPushMatrix();
    glTranslatef(x1,y1,z1);
    glScalef(objetivo_enemigo1,objetivo_enemigo1,objetivo_enemigo1);
    glRotatef(rotateX,0,0,1);
    ColorAlpha(1.000, 1.000, 0.000, 0.85);
    glutSolidSphere (0.5,15,15);
    glPopMatrix();
    //desactivando color alpha
    glDisable (GL_BLEND);
    
    //enemigo 2
    Material(0.0, 0.1, 0.06, 0.0, 0.50980392, 0.50980392, 0.50196078, 0.50196078, 0.50196078);
    glPushMatrix();
    glTranslatef(x2,y2,z2);
    glRotatef(rotateY2,0,1,0);
    glRotatef(rotateX2,1,0,0);
    enemigo1(0,0,0);
    glPopMatrix();
    //Desactivando Materiales
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    //Objetivo Enemigo 2
    glPushMatrix();
    glTranslatef(x2,y2,z2);
    glScalef(objetivo_enemigo2,objetivo_enemigo2,objetivo_enemigo2);
    glRotatef(rotateX,0,0,1);
    ColorAlpha(1.000, 1.000, 0.000, 0.85);
    glutSolidSphere (0.5,15,15);
    glPopMatrix();   
    glDisable (GL_BLEND);
    
    //enemigo 3
    Material(0.0, 0.0, 0.0, 0.1, 0.35, 0.1, 0.45, 0.55, 0.45 );
    glPushMatrix();
    glTranslatef(x3,y3,z3);
    glRotatef(rotateY3,0,1,0);
    glRotatef(rotateX3,1,0,0);
    enemigo1(0,0,0);
    glPopMatrix();
    //Desactivando Materiales
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    //Objetivo Enemigo 3
    glPushMatrix();
    glTranslatef(x3,y3,z3);
    glScalef(objetivo_enemigo3,objetivo_enemigo3,objetivo_enemigo3);
    glRotatef(rotateX,0,0,1);
    ColorAlpha(1.000, 1.000, 0.000, 0.85);
    glutSolidSphere (0.5,15,15);
    glPopMatrix();
    glDisable (GL_BLEND);
    
    //enemigo 4
    Material(0.24725, 0.1995, 0.0745, 0.75164, 0.60648, 0.22648, 0.628281, 0.555802, 0.366065 );
    glPushMatrix();
    glTranslatef(x4,y4,z4);
    glRotatef(rotateY4,0,1,0);
    glRotatef(rotateX4,1,0,0);
    enemigo1(0,0,0);
    glPopMatrix();
    //Desactivando Materiales
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    //Objetivo Enemigo 4
   
    glPushMatrix();
    glTranslatef(x4,y4,z4);
    glScalef(objetivo_enemigo4,objetivo_enemigo4,objetivo_enemigo4);
    glRotatef(rotateX,0,0,1);
    ColorAlpha(1.000, 1.000, 0.000, 0.85);
    glutSolidSphere (0.5,15,15);
    glPopMatrix();
    glDisable (GL_BLEND);
    
    //enemigo 5
    Material(0.0, 0.0, 0.0, 0.5, 0.5, 0.0, 0.60, 0.60, 0.50  );
    glPushMatrix();
    glTranslatef(x5,y5,z5);
    glRotatef(rotateY5,0,1,0);
    glRotatef(rotateX5,1,0,0);
    enemigo1(0,0,0);
    glPopMatrix();
    //Desactivando Materiales
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    //Objetivo Enemigo 5
    glPushMatrix();
    glTranslatef(x5,y5,z5);
    glScalef(objetivo_enemigo5,objetivo_enemigo5,objetivo_enemigo5);
    glRotatef(rotateX,0,0,1);
    ColorAlpha(1.000, 1.000, 0.000, 0.85);
    glutSolidSphere (0.5,15,15);
    glPopMatrix();
    glDisable (GL_BLEND);
    //Desactivando Materiales
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    
    /* Empezar a jugar */
	SDL_PauseAudio(0);
    glFlush ();
    glutSwapBuffers();    
}


// --------------- Para animación  ------------------------------------------



//Donde aparecera el enemigo al caer

//enemigo 1			
void valores_iniciales_enemigo1()
{
    x1=50;
    y1=15;
    z1=30;
    x1e=0;
    rotateY1=0;
    rotateX1=0;
    objetivo_enemigo1=0.2;
    posicionen1=1;
}

void valores_iniciales_enemigo11()
{
    x1=12;
    y1=8;
    z1=20;
    x1e=0;
    rotateY1=0;
    rotateX1=0;
    objetivo_enemigo1=0.2;
    posicionen1=0;
}

//enemigo 2
void valores_iniciales_enemigo2()
{
    x2=25;
    y2=20;
    z2=30;
    x2e=0;
    rotateY2=0;
    rotateX2=0;
    objetivo_enemigo2=0.2;
    posicionen2=1;
}

void valores_iniciales_enemigo22()
{
    x2=15;
    y2=9;
    z2=20;
    x2e=0;
    rotateY2=0;
    rotateX2=0;
    objetivo_enemigo2=0.2;
    posicionen2=0;
}

//enemigo 3
void valores_iniciales_enemigo3()
{
    x3=55;
    y3=14;
    z3=30;
    x3e=0;
    rotateY3=0;
    rotateX3=0;
    objetivo_enemigo3=0.2;
    posicionen3=1;
}

void valores_iniciales_enemigo33()
{
    x3=28;
    y3=28;
    z3=20;
    x3e=0;
    rotateY3=0;
    rotateX3=0;
    objetivo_enemigo3=0.2;
    posicionen3=0;
}
    
//enemigo 4
void valores_iniciales_enemigo4()
{
    x4=78;
    y4=6;
    z4=30;
    x4e=0;
    rotateY4=0;
    rotateX4=0;
    objetivo_enemigo4=0.2;
    posicionen4=1;
}

void valores_iniciales_enemigo44()
{
    x4=60;
    y4=24;
    z4=20;
    x4e=0;
    rotateY4=0;
    rotateX4=0;
    objetivo_enemigo4=0.2;
    posicionen4=0;
}
    
//enemigo 5			
void valores_iniciales_enemigo5()
{
    x5=18;
    y5=12;
    z5=30;
    x5e=0;
    rotateY5=0;
    rotateX5=0;
    objetivo_enemigo5=0.2;
    posicionen5=1;
}

void valores_iniciales_enemigo55()
{
    x5=12;
    y5=13;
    z5=20;
    x5e=0;
    rotateY5=0;
    rotateX5=0;
    objetivo_enemigo5=0.2;
    posicionen5=0;
}

//Valores Predeterminados
void valores_iniciales_jugador(){
    //camara
    X1=0;
    Z1=0;
    Xe=0;
    Ze=0;
    Ye=0;
    //jugador
    X=3;
    Y=3;
    Z=10.0;
    X0=0;
    Xd=1.5;
    Yd=0.0;
    Zd=0.0;
    fuego=0;
    animating=0;
    n=0;
    //enemigo 1
    x1=15;
    y1=10;
    z1=10;
    x1e=0;
    rotateY1=0;
    rotateX1=0;
    objetivo_enemigo1=0.2;
    //enemigo 2
    x2=25;
    y2=3;
    z2=10;
    x2e=0;
    rotateY2=0;
    rotateX2=0;
    objetivo_enemigo2=0.2;
    //enemigo 3
    x3=40;
    y3=24;
    z3=10;
    x3e=0;
    rotateY3=0;
    rotateX3=0;
    objetivo_enemigo3=0.2;
    //enemigo 4
    x4=33;
    y4=15;
    z4=10;
    x4e=0;
    rotateY4=0;
    rotateX4=0;
    objetivo_enemigo4=0.2;
    //enemigo 5
    x5=43;
    y5=25;
    z5=10;
    x5e=0;
    rotateY5=0;
    rotateX5=0;
    objetivo_enemigo5=0.2;
}

void pauseAnimation() 
{
    // Llamamo a la función para detener la animación 
    animating = 0;
     
}

void updateFrame() 
{
    // En esta funcion agregamos el codigo que hara la secuencia de cada escena como si fuera un fotograma 
    if(n!=15)
    {//***
        //Movimientos de la nave del jugador
        if(X<=100)
        {//posicion final 100
            if((X!=x1 or Y!=y1 or Z!=z1) )
            {
                if (X!=x2 or Y!=y2 or Z!=z2)
                {
                    if (X!=x3 or Y!=y3 or Z!=z3)
                    {
                        if (X!=x4 or Y!=y4 or Z!=z4)
                        {
                            if (X!=x5 or Y!=y5 or Z!=z5)
                            {
                                X+=0.5;
                            }
                        }
                    }
                }
            }
        }
        else
        {
            X=0;//posicion inicial 0
        }

        printf ("enemigo: %f \n", x1);
        printf ("nave: %f \n", X);
        //Acciones de la nave
  
        if((X==x1 and Y==y1 and Z==z1) or (X==x2 and Y==y2 and Z==z2) or (X==x3 and Y==y3 and Z==z3) or (X==x4 and Y==y4 and Z==z4) or (X==x5 and Y==y5 and Z==z5))
        {
            k=1;
            if(k==1 and X==x1 and Y==y1 and Z==z1)
            {
                objetivo_enemigo1+=0.3;
                if(objetivo_enemigo1>=8.5)
                {
                    k=0;
                }
            }
      
            if(k==1 and X==x2 and Y==y2 and Z==z2)
            {
                objetivo_enemigo2+=0.3;
                if(objetivo_enemigo2>=8.5)
                {
                    k=0;
                }
            }
        
            if(k==1 and X==x3 and Y==y3 and Z==z3)
            {
                objetivo_enemigo3+=0.3;
                if(objetivo_enemigo3>=8.5)
                {
                    k=0;
                }
            }
        
            if(k==1 and X==x4 and Y==y4 and Z==z4)
            {
                objetivo_enemigo4+=0.3;
                if(objetivo_enemigo4>=8.5)
                {
                    k=0;
                }
            }
        
            if(k==1 and X==x5 and Y==y5 and Z==z5)
            {
                objetivo_enemigo5+=0.3;
                if(objetivo_enemigo5>=8.5)
                {
                    k=0;
                }
            }
        
            if(k==0)
            {
                valores_iniciales_jugador();
            }
        }

        //Movimiento de enemigos 
        //enemigo 1
        if(x1<=100 and x1e != 1 and esquina1==1)
        {
            if(X!=x1 or Y!=y1 or Z!=z1)
            {
                x1+=0.5;
            }
            if(x1==100)
            {
                esquina1=0;
            }
        }
        //Izquierda
        if(x1>=0 and x1e != 1 and esquina1==0)
        {
            if(X!=x1 or Y!=y1 or Z!=z1)
            {
                x1-=0.5;
            }
            if(x1==0)
            {
                esquina1=1;
            }
        }
     
        //enemigo 2
        if(x1<=100 and x2e != 1 and esquina2==1)
        {
            if(X!=x2 or Y!=y2 or Z!=z2)
            {
                x2+=0.5;
            }
            if(x2==100)
            {
                esquina2=0;
            }
        }
        //Izquierda
        if(x2>=0 and x2e != 1 and esquina2==0)
        {
            if(X!=x2 or Y!=y2 or Z!=z2)
            {
                x2-=0.5;
            }
            if(x2==0)
            {
                esquina2=1;
            }
        }
        //enemigo 3
        if(y3<=30 and x3e != 1 and esquina3==1)
        {
            if(X!=x3 or Y!=y3 or Z!=z3)
            {
                y3+=0.5;
            }
            if(y3==30)
            {
                esquina3=0;
            }
        }
        //abajo
        if(y3>= 2 and x3e != 1 and esquina3==0)
        {
            if(X!=x3 or Y!=y3 or Z!=z3)
            {
                y3-=0.5;
            }
            if(y3==2)
            {
                esquina3=1;
            }
        }
     
        //enemigo 4
        if(y4<=30 and x4e != 1 and esquina4==1)
        {
            if(X!=x4 or Y!=y4 or Z!=z4)
            {
                y4+=0.5;
            }
            if(y4==30)
            {
                esquina4=0;
            }
        }
        //abajo
        if(y4>= 2 and x4e != 1 and esquina4==0)
        {
            if(X!=x4 or Y!=y4 or Z!=z4)
            {
                y4-=0.5;
            }
            if(y4==2)
            {
                esquina4=1;
            }
        }
     
        //enemigo 5
        if(x5<=100 and x5e != 1 and esquina5==1)
        {
            if(X!=x5 or Y!=y5 or Z!=z5)
            {
                x5+=0.5;
            }
            if(x5==100)
            {
                esquina5=0;
            }
        }
        //Izquierda
        if(x5>=0 and x5e != 1 and esquina5==0)
        {
            if(X!=x5 or Y!=y5 or Z!=z5)
            {
                x5-=0.5;
            }
            if(x5==0)
            {
                esquina5=1;
            }
        }
     
        //caida de Enemigo 1
        if(x1e==1 and y1>=0)
        {
            y1-=0.5;
            z1+=0.1;
            x1+=0.5;
            rotateY1+=1;
            rotateX-=1.0;
            rotateX1+=10.5;
        }
     
        //Explosion de Enemigo 1
        if(y1<0 and objetivo_enemigo1<=10 and x1e==1)
        {
            objetivo_enemigo1+=0.5;
            if(objetivo_enemigo1>10)
            {
                if(posicionen1==0)
                {
                    valores_iniciales_enemigo1();
                }
                else
                {
                    valores_iniciales_enemigo11();
                }
            }
        }
        //caida de Enemigo 2
        if(x2e==1 and y2>=0)
        {
            y2-=0.3;
            z2+=0.1;
            x2-=0.1;
            rotateY2+=1;
            rotateX-=1.0;
            rotateX2+=10.5;
        }
     
        //Explosion de Enemigo 2
        if(y2<0 and objetivo_enemigo2<=10 and x2e==1)
        {
            objetivo_enemigo2+=0.5;
            if(objetivo_enemigo2>10)
            {
                if(posicionen2==0)
                {
                    valores_iniciales_enemigo2();
                }
                else
                {
                    valores_iniciales_enemigo22();
                }
            }
        }
    
        //caida de Enemigo 3
        if(x3e==1 and y3>=0)
        {
            y3-=0.3;
            z3+=0.1;
            x3+=0.5;
            rotateY3+=1;
            rotateX-=1.0;
            rotateX3-=10.5;
        }
     
        //Explosion de Enemigo 3
        if(y3<0 and objetivo_enemigo3<=10 and x3e==1)
        {
            objetivo_enemigo3+=0.5;
            if(objetivo_enemigo3>10)
            {
                if(posicionen3==0)
                {
                    valores_iniciales_enemigo3();
                }
                else
                {
                    valores_iniciales_enemigo33();
                }
            }
        }
    
        //caida de Enemigo 4
        if(x4e==1 and y4>=0)
        {
            y4-=0.3;
            z4+=0.1;
            x4+=0.5;
            rotateY4+=1;
            rotateX-=1.0;
            rotateX4-=10.5;
        }
     
        //Explosion de Enemigo 4
        if(y4<0 and objetivo_enemigo4<=10 and x4e==1)
        {
            objetivo_enemigo4+=0.5;
            if(objetivo_enemigo4>10)
            {
                if(posicionen4==0)
                {
                    valores_iniciales_enemigo4();
                }
                else
                {
                    valores_iniciales_enemigo44();
                }
            }
        }
    
        //caida de Enemigo 5
        if(x5e==1 and y5>=0)
        {
            y5-=0.3;
            z5+=0.1;
            x5+=0.5;
            rotateY5+=1;
            rotateX-=1.0;
            rotateX5-=10.5;
        }
     
        //Explosion de Enemigo 5
        if(y5<0 and objetivo_enemigo5<=10 and x5e==1)
        {
            objetivo_enemigo5+=0.5;
            if(objetivo_enemigo5>10)
            {
                if(posicionen5==0)
                {
                    valores_iniciales_enemigo5();
                }
                else
                {
                    valores_iniciales_enemigo55();
                }
            }
        }
    
        //glColor3f(0.0,1.0,0.0);
        //Giros Tanto de la nave como los Platillos 
        for (int i=3; i<=100; i++)
        {
            rotateX=rotateX-= i;
            rotateY1=rotateY1-= i;
            rotateY2=rotateY2-= i;
            rotateY3=rotateY3-= i;
            rotateY4=rotateY4-= i;
            rotateY5=rotateY5-= i;
        }
    
        if(cambio<1)
        {
            cambio+=0.001;
            printf ("Cambio: %f \n", cambio);
        }
   
        //Verificamos el numero de frames para detener animación 
        if(frameNumber==200)
        {
            //pauseAnimation();
            frameNumber=0;
        }
        //Almacenamos el numero de frames 
        frameNumber++;
    }//***
    else
    {//***
        text();//***
        pauseAnimation();//***
    }//***
    printf ("Numero de Frame: %d \n", frameNumber);
}

void timerFunction(int timerID) 
{
    // Invocamos la funcion para controlar el tiempo de la ejecucion de funciones 
    if (animating) 
    {
        updateFrame();
        glutTimerFunc(30, timerFunction, 0);
        glutPostRedisplay();
    }
}

void startAnimation() 
{
    // llamamos la función para iniciar la animación 
    if ( ! animating ) 
    {
        animating = 1;
        glutTimerFunc(30, timerFunction, 1);
    }
}



// ------------- Manejo de Teclado-----------------------------------------------

void key(unsigned char key, int x, int y) 
{
    // La animación inicia al presionar la tecla espaciadora de igual forma se detiene
    if ( key == ' ' ) 
    {
		if ( animating )
        {
		    pauseAnimation();
	    }
		else
        {
		    startAnimation();
        }
	}
    if((key=='w' or key=='W') and Y<=30)
    {
     
        if(k==0)
        {
            Y+=0.5;
        }
	}
    if((key=='s' or key=='S') and Y>1)
    {
  
        if(k==0)
        {
            Y-=0.5;
        }
	}
    if((key=='d' or key=='D'))
    {
        if(k==0)
        {
            X+=0.5;
        }
	}
    if((key=='a' or key=='A' )and X>=0)
    {
        if(k==0)
        {
            X-=1.0;
        }
	}
    if((key=='e' or key=='E') and fuego==0)
    {
        X0=X;
        fuego=1;
	}
    if((key=='z' or key=='Z') and Z<=20)
    {
        Z+=10;
	}
    if((key=='x' or key=='X') and Z>=11)
    {
        Z-=10;
	}
	if (key == 27)
    {
		exit(0);
	}
}

void special(int key, int x, int y) 
{
    // control de teclas especiales 
    if ( key == GLUT_KEY_LEFT )
        rotateY1 -= 15;
    else if ( key == GLUT_KEY_RIGHT )
        rotateY1 += 15;
    else if ( key == GLUT_KEY_DOWN)
        rotateX += 15;
    else if ( key == GLUT_KEY_UP )
        rotateX -= 15;
    else if ( key == GLUT_KEY_HOME )
        rotateX = rotateY1 = 0;
    glutPostRedisplay();
}

// ----------------------  Funcion principal ------------------

int main(int argc, char** argv) 
{
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(250,100);
    glutCreateWindow("VideoJuego de Naves Espaciales 3D version 0.0.1");
    glutDisplayFunc(display);
    glutReshapeFunc(camara);
    glutKeyboardFunc(key);
    glutSpecialFunc(special);
    glEnable(GL_DEPTH_TEST);
    // Inicializar SDL.
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
        return 1;

	// Variables locales
	static Uint32 wav_length; // Longitud de nuestra muestra
	static Uint8 *wav_buffer; // Buffer que contiene nuestro archivo de audio
	static SDL_AudioSpec wav_spec; // Las especificaciones de nuestra pieza de música


	/* Cargar el WAV */
	// Las especificaciones, la longitud y el búfer de nuestro wav se llenan
	if( SDL_LoadWAV(MUS_PATH, &wav_spec, &wav_buffer, &wav_length) == NULL )
	{
        return 1;
    }
	// Establecer la función de devolución de llamada
	wav_spec.callback = my_audio_callback;
	wav_spec.userdata = NULL;
	
	// Establecer nuestras variables estáticas globales
	audio_pos = wav_buffer ; // Copia el buffer de sonido
	audio_len = wav_length; // Copia la longitud del archivo

	/*Abrir el dispositivo de audio */
	if ( SDL_OpenAudio(&wav_spec, NULL) < 0 )
	{
        fprintf(stderr, "No se pudo abrir el audio: %s\n", SDL_GetError());
        exit(-1);
	}
    frameNumber = 0;
    rotateX = rotateY1 = 0;
    
    // Activar iluminación 
    // Activamos la fuente de luz
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0); //Activamos las luces en 0
    glDepthFunc(GL_LESS); //comparación de profundidad
    glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TEST
    // Descomentar si queremos que la animación inicie al levantar el script
    startAnimation();

    glutMainLoop();
  	// funcion SDL Cerrar todo
	SDL_CloseAudio();
	SDL_FreeWAV(wav_buffer);  
    return 0;
}

