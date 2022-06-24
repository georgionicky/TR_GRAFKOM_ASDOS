#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

#define FPS 120
#define TO_RADIANS 3.14/180.0

//  Anggota Kelompok X
//  Georgio Nicky (672020267)
//  Ezer Soleiman Junior Ranti (672020139)
//  Aprillia Tetikay (672020021)
//  Siska Angeline (672020123)
//  Julita Veronika Lenda (672020266)


int posX[500];
int posZ[500];
const int width = 1280;
const int height = 720;
int i;
float sudut;
double x_geser, y_geser, z_geser;
float r1 = 0.12;
float g1 = 0.12;
float b1 = 0.12;

float pitch = 0.0, yaw = 0.0;
float camX = 0.0, camZ = 0.0, terbang = 25.0;

void display();
void reshape(int w, int h);
void timer(int);
void passive_motion(int, int);
void camera();
void keyboard(unsigned char key, int x, int y);
void keyboard_up(unsigned char key, int x, int y);

struct Motion {
    bool Forward, Backward, Left, Right, Naik, Turun;
};
Motion motion = { false,false,false,false,false,false };


void init() {
<<<<<<< HEAD

=======
    
>>>>>>> 4cdf592ad3ac7ddebae5d9c02d7d808d610a7db4
    for (int i = 0; i < 500; i++) {
        posX[i] = ((float(rand()) / float(RAND_MAX)) * (10000 - (-10000))) + -10000;
        posZ[i] = ((float(rand()) / float(RAND_MAX)) * (10000 - (-10000))) + -10000;

    }
    glClearColor(0.529, 0.807, 0.921, 0.0);
    glutSetCursor(GLUT_CURSOR_NONE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthFunc(GL_LEQUAL);
    glutWarpPointer(width / 2, height / 2);
}



void matahariBulan() {
    if (sudut >= 360) {
        sudut = 0;
    }

    glClearColor(r1, g1, b1, 1);
    if (sudut >= 0 && sudut < 180) {
        r1 += 0.0045 / 10 / 2;
        g1 += 0.0076 / 10 / 2;
        b1 += 0.0089 / 10 / 2;
    }

    if (sudut >= 180) {
        r1 -= 0.0045 / 10 / 2;
        g1 -= 0.0076 / 10 / 2;
        b1 -= 0.0089 / 10 / 2;
    }

    //bulan
    glColor3f(1, 1, 1);
    glPushMatrix();
    glRotatef(-sudut - 45, -0.55, 0, -0.45);
    glTranslatef(0, 7000, 0);
    glutSolidSphere(200, 20, 20);
    glPopMatrix();

    //matahari
    glColor3f(1.0f, 1.0f, 0.0f);
    glPushMatrix();
    glRotatef(-(180 + sudut), -0.55, 0, -0.45);
    glTranslatef(0, 7000, 0);
    glutSolidSphere(300, 20, 20);
    glPopMatrix();

<<<<<<< HEAD
    /* --------------------- bikin ngelaggg
=======
    /* --------------------- bikin ngelaggg 
>>>>>>> 4cdf592ad3ac7ddebae5d9c02d7d808d610a7db4
    //bintang
    glColor3f(1, 1, 1);
    for (int i = 0; i < 500; i++) {
        glPushMatrix();
        glTranslatef(posX[i], 5000, posZ[i]);
        glutSolidSphere(10, 20, 20);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(posX[i], posZ[i], 5000);
        glutSolidSphere(5, 20, 20);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(posX[i], posZ[i], -5000);
        glutSolidSphere(5, 20, 20);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(5000, posZ[i], posX[i]);
        glutSolidSphere(5, 20, 20);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-5000, posZ[i], posX[i]);
        glutSolidSphere(5, 20, 20);
        glPopMatrix();
    }
    */

    sudut += 0.1;
}

void objek1(float x, float y, float z, float t, float l, float p) {
    glBegin(GL_QUADS); //alas
    glVertex3f(x - (p / 2), y, z - (l / 2));
    glVertex3f(x - (p / 2), y, z + (l / 2));
    glVertex3f(x + (p / 2), y, z + (l / 2));
    glVertex3f(x + (p / 2), y, z - (l / 2));
    glEnd();

    glBegin(GL_QUADS); //atas
    glVertex3f(x - (p / 2), y + t, z - (l / 2));
    glVertex3f(x - (p / 2), y + t, z + (l / 2));
    glVertex3f(x + (p / 2), y + t, z + (l / 2));
    glVertex3f(x + (p / 2), y + t, z - (l / 2));
    glEnd();

    glBegin(GL_QUADS); //kiri
    glVertex3f(x - (p / 2), y, z - (l / 2));
    glVertex3f(x - (p / 2), y + t, z - (l / 2));
    glVertex3f(x - (p / 2), y + t, z + (l / 2));
    glVertex3f(x - (p / 2), y, z + (l / 2));
<<<<<<< HEAD
    glEnd();

    glBegin(GL_QUADS); //kanan
    glVertex3f(x + (p / 2), y, z - (l / 2));
    glVertex3f(x + (p / 2), y + t, z - (l / 2));
    glVertex3f(x + (p / 2), y + t, z + (l / 2));
    glVertex3f(x + (p / 2), y, z + (l / 2));
    glEnd();

    glBegin(GL_QUADS); //blkng
    glVertex3f(x - (p / 2), y, z - (l / 2));
    glVertex3f(x - (p / 2), y + t, z - (l / 2));
    glVertex3f(x + (p / 2), y + t, z - (l / 2));
    glVertex3f(x + (p / 2), y, z - (l / 2));
    glEnd();

    glBegin(GL_QUADS); //depan
    glVertex3f(x - (p / 2), y, z + (l / 2));
    glVertex3f(x - (p / 2), y + t, z + (l / 2));
    glVertex3f(x + (p / 2), y + t, z + (l / 2));
    glVertex3f(x + (p / 2), y, z + (l / 2));
    glEnd();
}

void krucut(float x, float y, float z, float sisi, float t, float r) {
    glBegin(GL_POLYGON);
    glVertex3f(x, y + t, z);
    for (int i = 0; i <= sisi; i++) {
        glVertex3f((r * cos(2 * 3.14159265 * i / sisi)) + x, y, (r * sin(2 * 3.14159265 * i / sisi)) + z);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for (int i = 0; i < sisi; i++) {
        glVertex3f((r * cos(2 * 3.14159265 * i / sisi)) + x, y, (r * sin(2 * 3.14159265 * i / sisi)) + z);
    }
    glEnd();
}


//masih fail
void kotakBisadiPutar(float x, float y, float z, float t, float l, float p, float derajat) {
    glBegin(GL_QUADS); //alas
    glVertex3f(x, y, z);
    glVertex3f(x - (derajat * p), y, z + (derajat * p));
    glVertex3f(x - (derajat * p) - (derajat * l), y, z + (derajat * p) - (derajat * l));
    glVertex3f(x - (derajat * l), y, z - (derajat * l));
    glEnd();


    glBegin(GL_QUADS); //atas
    glVertex3f(x, y + t, z);
    glVertex3f(x - (derajat * p), y + t, z + (derajat * p));
    glVertex3f(x - (derajat * p) - (derajat * l), y + t, z + (derajat * p) - (derajat * l));
    glVertex3f(x - (derajat * l), y + t, z - (derajat * l));
    glEnd();


    glBegin(GL_QUADS); //kiri
    glVertex3f(x, y, z);
    glVertex3f(x, y + t, z);
    glVertex3f(x - (derajat * p), y + t, z + (derajat * p));
    glVertex3f(x - (derajat * p), y, z + (derajat * p));
=======
>>>>>>> 4cdf592ad3ac7ddebae5d9c02d7d808d610a7db4
    glEnd();


    /*

    glBegin(GL_QUADS); //kanan
<<<<<<< HEAD
    glVertex3f(x - p, y, z);
    glVertex3f(x - p, y + t, z);
    glVertex3f(x - (derajat * p) - p, y + t, z + (derajat * p));
    glVertex3f(x - (derajat * p) - p, y, z + (derajat * p));
=======
    glVertex3f(x + (p / 2), y, z - (l / 2));
    glVertex3f(x + (p / 2), y + t, z - (l / 2));
    glVertex3f(x + (p / 2), y + t, z + (l / 2));
    glVertex3f(x + (p / 2), y, z + (l / 2));
>>>>>>> 4cdf592ad3ac7ddebae5d9c02d7d808d610a7db4
    glEnd();



    glBegin(GL_QUADS); //blkng
    glVertex3f(x - (p / 2), y, z - (l / 2));
    glVertex3f(x - (p / 2), y + t, z - (l / 2));
    glVertex3f(x + (p / 2), y + t, z - (l / 2));
    glVertex3f(x + (p / 2), y, z - (l / 2));
    glEnd();

    glBegin(GL_QUADS); //depan
    glVertex3f(x - (p / 2), y, z + (l / 2));
    glVertex3f(x - (p / 2), y + t, z + (l / 2));
    glVertex3f(x + (p / 2), y + t, z + (l / 2));
    glVertex3f(x + (p / 2), y, z + (l / 2));
<<<<<<< HEAD
=======
    glEnd();
}

void krucut(float x, float y, float z, float sisi, float t, float r) {
    glBegin(GL_POLYGON);
    glVertex3f(x, y + t, z);
    for (int i = 0; i <= sisi; i++) {
        glVertex3f((r * cos(2 * 3.14159265 * i / sisi)) + x, y, (r * sin(2 * 3.14159265 * i / sisi)) + z);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for (int i = 0; i < sisi; i++) {
        glVertex3f((r * cos(2 * 3.14159265 * i / sisi)) + x, y, (r * sin(2 * 3.14159265 * i / sisi)) + z);
    }
    glEnd();
}


//masih fail
void kotakBisadiPutar(float x, float y, float z, float t, float l, float p, float derajat) {
    glBegin(GL_QUADS); //alas
    glVertex3f(x , y, z );
    glVertex3f(x - (derajat * p), y, z + (derajat * p));
    glVertex3f(x - (derajat * p) - (derajat * l), y, z + (derajat * p) - (derajat * l));
    glVertex3f(x - (derajat * l), y, z - (derajat * l));
>>>>>>> 4cdf592ad3ac7ddebae5d9c02d7d808d610a7db4
    glEnd();
    */
}

<<<<<<< HEAD
=======
    
    glBegin(GL_QUADS); //atas
    glVertex3f(x , y + t, z );
    glVertex3f(x - (derajat * p), y + t, z + (derajat * p));
    glVertex3f(x - (derajat * p) - (derajat * l), y + t, z + (derajat * p) - (derajat * l));
    glVertex3f(x - (derajat * l), y + t, z - (derajat * l));
    glEnd();

    
    glBegin(GL_QUADS); //kiri
    glVertex3f(x, y, z);
    glVertex3f(x, y + t, z);
    glVertex3f(x - (derajat * p), y + t, z + (derajat * p));
    glVertex3f(x - (derajat * p), y, z + (derajat * p));
    glEnd();


    /*

    glBegin(GL_QUADS); //kanan
    glVertex3f(x - p, y, z);
    glVertex3f(x - p, y + t, z);
    glVertex3f(x - (derajat * p) - p, y + t, z + (derajat * p));
    glVertex3f(x - (derajat * p) - p, y, z + (derajat * p));
    glEnd();


    
    glBegin(GL_QUADS); //blkng
    glVertex3f(x - (p / 2), y, z - (l / 2));
    glVertex3f(x - (p / 2), y + t, z - (l / 2));
    glVertex3f(x + (p / 2), y + t, z - (l / 2));
    glVertex3f(x + (p / 2), y, z - (l / 2));
    glEnd();

    glBegin(GL_QUADS); //depan
    glVertex3f(x - (p / 2), y, z + (l / 2));
    glVertex3f(x - (p / 2), y + t, z + (l / 2));
    glVertex3f(x + (p / 2), y + t, z + (l / 2));
    glVertex3f(x + (p / 2), y, z + (l / 2));
    glEnd();
    */
}

>>>>>>> 4cdf592ad3ac7ddebae5d9c02d7d808d610a7db4
void ground() {
    glBegin(GL_QUADS);
    glColor4f(0, 0.35, 0.7, 0.6);
    glVertex3f(-5000.0, -150, -5000.0);

    glColor4f(0, 0.35, 0.7, 0.6);
    glVertex3f(5000.0, -150, -5000.0);

    glColor4f(0, 0.35, 0.7, 0.6);
    glVertex3f(5000.0, -100, 5000.0);

    glColor4f(0, 0.35, 0.7, 0.6);
    glVertex3f(-5000.0, -150, 5000.0);
    glEnd();
}

void ground2() {
    glBegin(GL_QUADS);
    glColor3f(0.71, 0.6, 0.4);
    glVertex3f(-5000.0, -300, -5000.0);

    glColor3f(0.71, 0.6, 0.4);
    glVertex3f(5000.0, -300, -5000.0);

    glColor3f(0.71, 0.6, 0.4);
    glVertex3f(5000.0, -300, 5000.0);

    glColor3f(0.71, 0.6, 0.4);
    glVertex3f(-5000.0, -300, 5000.0);
    glEnd();
}

void pagar_lantai1() {

}

//prisma
void objek2(float x, float y, float z, float t, float plAlas, float plAtas) {
    glBegin(GL_QUADS); //alas
    glVertex3f(x - (plAlas / 2), y, z - (plAlas / 2));
    glVertex3f(x - (plAlas / 2), y, z + (plAlas / 2));
    glVertex3f(x + (plAlas / 2), y, z + (plAlas / 2));
    glVertex3f(x + (plAlas / 2), y, z - (plAlas / 2));
    glEnd();

    glBegin(GL_QUADS); //atas
    glVertex3f(x - (plAtas / 2), y + t, z - (plAtas / 2));
    glVertex3f(x - (plAtas / 2), y + t, z + (plAtas / 2));
    glVertex3f(x + (plAtas / 2), y + t, z + (plAtas / 2));
    glVertex3f(x + (plAtas / 2), y + t, z - (plAtas / 2));
    glEnd();

    glBegin(GL_QUADS); //kiri
    glVertex3f(x - (plAlas / 2), y, z - (plAlas / 2));
    glVertex3f(x - (plAtas / 2), y + t, z - (plAtas / 2));
    glVertex3f(x - (plAtas / 2), y + t, z + (plAtas / 2));
    glVertex3f(x - (plAlas / 2), y, z + (plAlas / 2));
    glEnd();

    glBegin(GL_QUADS); //kanan
    glVertex3f(x + (plAlas / 2), y, z - (plAlas / 2));
    glVertex3f(x + (plAtas / 2), y + t, z - (plAtas / 2));
    glVertex3f(x + (plAtas / 2), y + t, z + (plAtas / 2));
    glVertex3f(x + (plAlas / 2), y, z + (plAlas / 2));
    glEnd();

    glBegin(GL_QUADS); //blkng
    glVertex3f(x - (plAlas / 2), y, z - (plAlas / 2));
    glVertex3f(x - (plAtas / 2), y + t, z - (plAtas / 2));
    glVertex3f(x + (plAtas / 2), y + t, z - (plAtas / 2));
    glVertex3f(x + (plAlas / 2), y, z - (plAlas / 2));
    glEnd();

    glBegin(GL_QUADS); //depan
    glVertex3f(x - (plAlas / 2), y, z + (plAlas / 2));
    glVertex3f(x - (plAtas / 2), y + t, z + (plAtas / 2));
    glVertex3f(x + (plAtas / 2), y + t, z + (plAtas / 2));
    glVertex3f(x + (plAlas / 2), y, z + (plAlas / 2));
    glEnd();
}

void objek3(float x, float y, float z, float t, float plAlas, float plAtas) {
    glBegin(GL_QUADS); //alas
    glColor3f(0.4, 0.24, 0.13);
    glVertex3f(x - (plAlas / 2), y, z - (plAlas / 2));
    glVertex3f(x - (plAlas / 2), y, z + (plAlas / 2));
    glVertex3f(x + (plAlas / 2), y, z + (plAlas / 2));
    glVertex3f(x + (plAlas / 2), y, z - (plAlas / 2));
    glEnd();

    glBegin(GL_QUADS); //atas
    glColor3f(0.41, 0.72, 0.15);
    glVertex3f(x - (plAtas / 2), y + t, z - (plAtas / 2));
    glColor3f(0.41, 0.62, 0.15);
    glVertex3f(x - (plAtas / 2), y + t, z + (plAtas / 2));
    glColor3f(0.41, 0.62, 0.15);
    glVertex3f(x + (plAtas / 2), y + t, z + (plAtas / 2));
    glColor3f(0.41, 0.72, 0.15);
    glVertex3f(x + (plAtas / 2), y + t, z - (plAtas / 2));
    glEnd();

    glBegin(GL_QUADS); //kiri
    glColor3f(0.4, 0.24, 0.13);
    glVertex3f(x - (plAlas / 2), y, z - (plAlas / 2));
    glVertex3f(x - (plAtas / 2), y + t, z - (plAtas / 2));
    glVertex3f(x - (plAtas / 2), y + t, z + (plAtas / 2));
    glVertex3f(x - (plAlas / 2), y, z + (plAlas / 2));
    glEnd();

    glBegin(GL_QUADS); //kanan
    glColor3f(0.4, 0.24, 0.13);
    glVertex3f(x + (plAlas / 2), y, z - (plAlas / 2));
    glVertex3f(x + (plAtas / 2), y + t, z - (plAtas / 2));
    glVertex3f(x + (plAtas / 2), y + t, z + (plAtas / 2));
    glVertex3f(x + (plAlas / 2), y, z + (plAlas / 2));
    glEnd();

    glBegin(GL_QUADS); //blkng
    glColor3f(0.4, 0.24, 0.13);
    glVertex3f(x - (plAlas / 2), y, z - (plAlas / 2));
    glVertex3f(x - (plAtas / 2), y + t, z - (plAtas / 2));
    glVertex3f(x + (plAtas / 2), y + t, z - (plAtas / 2));
    glVertex3f(x + (plAlas / 2), y, z - (plAlas / 2));
    glEnd();

    glBegin(GL_QUADS); //depan
    glColor3f(0.4, 0.24, 0.13);
    glVertex3f(x - (plAlas / 2), y, z + (plAlas / 2));
    glVertex3f(x - (plAtas / 2), y + t, z + (plAtas / 2));
    glVertex3f(x + (plAtas / 2), y + t, z + (plAtas / 2));
    glVertex3f(x + (plAlas / 2), y, z + (plAlas / 2));
    glEnd();
}

void atap(float x, float y, float z, float panjangLebar, float jumlahKotak, float tinggiKotak, float kurang) {
    for (int i = 0; i <= jumlahKotak; i++) {
        objek1(x, y, z, tinggiKotak, panjangLebar, panjangLebar);
        y += tinggiKotak;
        panjangLebar -= kurang;
    }
}

void tangga(float x, float y, float z, float panjangLebar, float jumlahKotak, float tinggiKotak, float kurang) {
    float c = 0.55;
    float kurangWarna = c / jumlahKotak / 5;
    float c2 = c - kurangWarna * 10;

    int panjang = panjangLebar;
    for (int i = 0; i <= jumlahKotak; i++) {
        glColor3f(c2, c2, c2);
        objek1(x, y, z, tinggiKotak, panjangLebar, panjang);
        c2 += kurangWarna;
        y += tinggiKotak;
        z -= kurang;
        panjangLebar -= 2 * kurang;
    }
}

void pagar(float x, float y, float z, float panjang)
{
    objek1(x, y + 2, z, 2, 5, panjang);
    for (int i = 0; i <= panjang; i++) {
        if (i % 20 == 0) {
            objek1(x - (panjang / 2) + i, y - 15, z, 25, 5, 5);
        }
    }
    objek1(x, y - 5, z, 2, 5, panjang);
}

void pintu(float x, float y, float z, float t, float p) {
    glColor3f(0.70, 0.2, 0);
    objek1(x - p / 2, y, z, t, 3, 3); //kiri
    objek1(x + p / 2, y, z, t, 3, 3);// kanan
    objek1(x, y + t, z, -3, 3, p); //atas
    objek1(x, y, z, 3, 3, p); //bawah


    //tutup
    glColor3f(0.76, 0.26, 0.04);
    objek1(x - p / 2 + 7.75, y + 2, z, t * 0.70 - 4, 2, p / 2 - 2);//bawah

    glColor3f(0.93, 0.94, 0.95);
    //tutupAtas
    glColor3f(0.46, 0.06, 0.0);
<<<<<<< HEAD
    objek1(x - p / 4 - 2, y + t * 0.70 + t * 0.15 - 1.5, z, -1, 2.5, p / 2 - 4);
=======
    objek1(x - p/4 - 2, y + t * 0.70 + t * 0.15 - 1.5, z, -1, 2.5, p / 2 - 4);
>>>>>>> 4cdf592ad3ac7ddebae5d9c02d7d808d610a7db4
    objek1(x - p / 4 - 2, y + t * 0.70 - 2, z, p / 2 - 4 + 2, 2.5, 1);
    objek1(x - 4, y + t * 0.70 - 2, z, p / 2 - 4 + 2, 2.5, 1);


    //buka
    glColor3f(0.76, 0.26, 0.04);
<<<<<<< HEAD

    objek1(x + p / 2, y + 2, z + p / 2 - 9.5, t * 0.70 - 4, p / 2 - 2, 2);//bawah

    //bukaAtas
    glColor3f(0.46, 0.06, 0.0);
    objek1(x + p / 2, y + t * 0.70 + t * 0.15 - 1.5, z + p / 4, -1, p / 2 - 2, 2.5);
    objek1(x + p / 2, y + t * 0.70 - 2, z + p / 2 - 1, p / 2 - 4 + 2, 1, 2.5);
    objek1(x + p / 2, y + t * 0.70 - 2, z + p / 4, p / 2 - 4 + 2, 1, 2.5);
=======
    
    objek1(x + p / 2 , y + 2, z + p / 2 - 9.5, t * 0.70 - 4, p/2 - 2, 2);//bawah

    //bukaAtas
    glColor3f(0.46, 0.06, 0.0);
    objek1(x + p / 2, y + t * 0.70 + t * 0.15 - 1.5, z + p/4, -1, p / 2 - 2, 2.5);
    objek1(x + p / 2, y + t * 0.70 - 2, z + p/2 -1, p / 2 - 4 + 2, 1, 2.5);
    objek1(x + p / 2, y + t * 0.70 - 2, z + p/4, p / 2 - 4 + 2, 1, 2.5);
>>>>>>> 4cdf592ad3ac7ddebae5d9c02d7d808d610a7db4
    objek1(x + p / 2, y + t * 0.70 + t * 0.3 - 1.5, z + p / 4, -1, p / 2 - 2, 2.5);
}

void jendela(float x, float y, float z, float t, float p) {
    objek1(x, y, z, t, 2, 2);
    objek1(x + p, y, z, t, 2, 2);
    objek1(x + p, y, z, 2, 2, p);
    objek1(x, y, z, 2, 2, p);

}

<<<<<<< HEAD
void pintuEmpatSisi(float x, float y, float z, float tinggi) {
=======
void pintuEmpatSisi(float x, float y, float z , float tinggi) {
>>>>>>> 4cdf592ad3ac7ddebae5d9c02d7d808d610a7db4
    pintu(x, y, z, tinggi, 40); //pintu depan

    glPushMatrix(); //pintu kanan
    glRotatef(90, 0, 1, 0);
    pintu(x, y, z, tinggi, 40);
    glPopMatrix();

    glPushMatrix(); //pintu kiri
    glRotatef(-90, 0, 1, 0);
    pintu(x, y, z, tinggi, 40);
    glPopMatrix();

    glPushMatrix(); //pintu belakang
    glRotatef(180, 0, 1, 0);
    pintu(x, y, z, tinggi, 40);
    glPopMatrix();
}

void pohon(float x, float y, float z) {
    glColor3f(0.4, 0.24, 0.13);
<<<<<<< HEAD
    objek1(x, y, z, 155, 10, 10);

    glColor4f(0.2, 0.6, 0.2, 0.9);
=======
    objek1(x,y,z,155,10,10);

    glColor4f(0.2, 0.6, 0.2,0.9);
>>>>>>> 4cdf592ad3ac7ddebae5d9c02d7d808d610a7db4
    objek1(x, y + 50, z, 7, 60, 60);
    objek1(x, y + 60, z, 7, 70, 70);
    objek1(x, y + 70, z, 7, 65, 65);
    objek1(x, y + 80, z, 7, 60, 60);
    objek1(x, y + 90, z, 7, 55, 55);
    objek1(x, y + 100, z, 7, 50, 50);
    objek1(x, y + 110, z, 7, 45, 45);
    objek1(x, y + 120, z, 7, 40, 40);
    objek1(x, y + 130, z, 7, 35, 35);
    objek1(x, y + 140, z, 7, 30, 30);
    objek1(x, y + 150, z, 7, 25, 25);
    objek1(x, y + 160, z, 7, 20, 20);
}



void draw() {
    // Mulai tuliskan isi pikiranmu disini
<<<<<<< HEAD

    //Warna
    //glColor3f(0.32, 0.47, 0.48);  || Atap Lapisan 1
    //glColor3f(0.4, 0.58, 0.59);   || Atap Lapisan 2
    //glColor3f(0.93, 0.94, 0.95);  ||  Tembok

=======
    
    //Warna
    //glColor3f(0.32, 0.47, 0.48);  || Atap Lapisan 1
    //glColor3f(0.4, 0.58, 0.59);   || Atap Lapisan 2
    //glColor3f(0.93, 0.94, 0.95);  ||  Tembok

>>>>>>> 4cdf592ad3ac7ddebae5d9c02d7d808d610a7db4
    matahariBulan(); //matahari dan bulan,, bisa bergerak lohh

    //pintu lantai ------------------------------------------->
    pintuEmpatSisi(0, 110, 176, 60); //1
<<<<<<< HEAD
    pintuEmpatSisi(0, 186, 137, 60); //2
=======
    pintuEmpatSisi(0, 186, 137,60); //2
>>>>>>> 4cdf592ad3ac7ddebae5d9c02d7d808d610a7db4
    pintuEmpatSisi(0, 329, 100, 60); //3
    pintuEmpatSisi(0, 435, 100, 60); //4
    //-------------------------------------------------------->

    //pohon-pohonan ------------------------------------------>
    pohon(400, 0, 600);



    //-------------------------------------------------------->


    //dasar
    glColor3f(0.55, 0.55, 0.55);
<<<<<<< HEAD
    objek2(0, 0, 0, 110, 700, 650);

=======
    objek2(0, 0, 0, 110, 700,650);
    
>>>>>>> 4cdf592ad3ac7ddebae5d9c02d7d808d610a7db4
    //tangga
    tangga(0, 0, 430, 210, 10, 10, 10);

    //Lantai 1
    glColor3f(0.93, 0.94, 0.95);
    objek1(0, 102, 0, 75, 350, 350);
    //Lantai 1 - Atap
    glColor3f(0.58, 0.55, 0.54);
    objek1(0, 175, 0, 10, 500, 500);
    //Lantai 1 - Pagar
    //Depan
    glColor3f(0.76, 0.26, 0.04);
    pagar(-190, 125, 322, 260);
    glColor3f(0.76, 0.26, 0.04);
    pagar(190, 125, 322, 265);
    //Belakang
    glColor3f(0.76, 0.26, 0.04);
    pagar(0, 125, -322, 646);
    //Kiri
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glColor3f(0.76, 0.26, 0.04);
    pagar(0, 125, 322, 644);
    glPopMatrix();
    //Kiri
    glPushMatrix();
    glRotatef(-90, 0, 1, 0);
    glColor3f(0.76, 0.26, 0.04);
    pagar(0, 125, 322, 644);
    glPopMatrix();


    //Lantai 2
    glColor3f(0.93, 0.94, 0.95);
    objek1(0, 186, 0, 100, 275, 275);
    //Lantai 2 - Atap1
    glColor3f(0.32, 0.47, 0.48);
    atap(0, 287, 0, 300, 10, 2, -10);
    glColor3f(0.4, 0.58, 0.59);
    atap(0, 308, 0, 320, 10, 2, 10);

    //Lantai 2 - Pagar
    //Depan
    glColor3f(0.76, 0.26, 0.04);
    pagar(0, 200, 248, 494);
    //Belakang
    glColor3f(0.76, 0.26, 0.04);
    pagar(0, 200, -248, 494);
    //Kiri
    glPushMatrix();
    glRotatef(-90, 0, 1, 0);
    glColor3f(0.76, 0.26, 0.04);
    pagar(0, 200, -248, 494);
    glPopMatrix();
    //Kanan
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glColor3f(0.76, 0.26, 0.04);
    pagar(0, 200, -248, 494);
    glPopMatrix();


    //Lantai 3 - Dasaran
    glColor3f(0.58, 0.55, 0.54);
    objek1(0, 329, 0, 10, 300, 300);
    //Lantai 3
    glColor3f(0.93, 0.94, 0.95);
    objek1(0, 339, 0, 60, 200, 200);
    //Lantai 3 - Atap1
    glColor3f(0.32, 0.47, 0.48);
    atap(0, 400, 0, 260, 10, 2, -10);
    glColor3f(0.4, 0.58, 0.59);
    atap(0, 411, 0, 280, 10, 2, 10);
    //Lantai 3 - Pagar
    //Depan
    glColor3f(0.76, 0.26, 0.04);
    pagar(0, 352, 150, 300);
    //Belakang
    glColor3f(0.76, 0.26, 0.04);
    pagar(0, 352, -150, 300);
    //Kiri
    glPushMatrix();
    glRotatef(-90, 0, 1, 0);
    glColor3f(0.76, 0.26, 0.04);
    pagar(0, 352, -150, 300);
    glPopMatrix();
    //Kanan
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glColor3f(0.76, 0.26, 0.04);
    pagar(0, 352, -150, 300);
    glPopMatrix();


    //Lantai 4 - Dasaran
    glColor3f(0.58, 0.55, 0.54);
    objek1(0, 431, 0, 10, 300, 300);
    //Lantai 4
    glColor3f(0.93, 0.94, 0.95);
    objek1(0, 441, 0, 60, 200, 200);
    //Lantai 4 - Atap1
    glColor3f(0.32, 0.47, 0.48);
    atap(0, 496, 0, 300, 10, 2, -10);
    glColor3f(0.4, 0.58, 0.59);
    atap(0, 519, 0, 320, 10, 2, 10);
    //Lantai 4- Atap2
    glColor3f(0.32, 0.47, 0.48);
    atap(0, 529, 0, 240, 10, 2, -10);
    glColor3f(0.4, 0.58, 0.59);
    atap(0, 544, 0, 260, 10, 6, 20);
    //Lantai 2 - Pagar
    //Depan
    glColor3f(0.76, 0.26, 0.04);
    pagar(0, 455, 150, 300);
    //Belakang
    glColor3f(0.76, 0.26, 0.04);
    pagar(0, 455, -150, 300);
    //Kiri
    glPushMatrix();
    glRotatef(-90, 0, 1, 0);
    glColor3f(0.76, 0.26, 0.04);
    pagar(0, 455, -150, 300);
    glPopMatrix();
    //Kanan
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glColor3f(0.76, 0.26, 0.04);
    pagar(0, 455, -150, 300);
    glPopMatrix();

    objek3(0, -297, 0, 300, 1500, 1500);
    objek3(2000, -299, 0, 300, 1500, 1500); //Kanan
    objek3(-2000, -299, 0, 300, 1500, 1500); // Kiri
    objek3(0, -299, 2000, 300, 1500, 1500); // Depan
    objek3(0, -299, -2000, 300, 1500, 1500); // Belakang

    ground2();
    ground();

    glFlush();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    camera();
    draw();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, 16.0 / 9.0, 2, 10000);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int) {
    glutPostRedisplay();
    glutWarpPointer(width / 2, height / 2);
    glutTimerFunc(1000 / FPS, timer, 0);
}

void passive_motion(int x, int y) {
    int dev_x, dev_y;
    dev_x = (width / 2) - x;
    dev_y = (height / 2) - y;
    yaw += (float)dev_x / 20.0;
    pitch += (float)dev_y / 20.0;
}

void camera() {
    if (motion.Forward) {
        camX += cos((yaw + 90) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90) * TO_RADIANS) * 2;
    }
    if (motion.Backward) {
        camX += cos((yaw + 90 + 180) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90 + 180) * TO_RADIANS) * 2;
    }
    if (motion.Left) {
        camX += cos((yaw + 90 + 90) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90 + 90) * TO_RADIANS) * 2;
    }
    if (motion.Right) {
        camX += cos((yaw + 90 - 90) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90 - 90) * TO_RADIANS) * 2;
    }
    if (motion.Naik) {
        terbang -= 2.0;
    }
    if (motion.Turun) {
        terbang += 2.0;
    }

    if (pitch >= 70)
        pitch = 70;
    if (pitch <= -90)
        pitch = -90;


    glRotatef(-pitch, 1.0, 0.0, 0.0);
    glRotatef(-yaw, 0.0, 1.0, 0.0);

    glTranslatef(-camX, -terbang, -350 - camZ);
    if (terbang < 25)
        terbang = 24;
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'W':
    case 'w':
        motion.Forward = true;
        break;
    case 'A':
    case 'a':
        motion.Left = true;
        break;
    case 'S':
    case 's':
        motion.Backward = true;
        break;
    case 'D':
    case 'd':
        motion.Right = true;
        break;
    case 'E':
    case 'e':
        motion.Naik = true;
        break;
    case 'Q':
    case 'q':
        motion.Turun = true;
        break;
    case '6':
        x_geser += 0.5;
        break;
    case '4':
        x_geser -= 0.5;
        break;
    case '8':
        y_geser += 0.5;
        break;
    case '2':
        y_geser -= 0.5;
        break;
    case '9':
        z_geser -= 0.5;
        break;
    case '1':
        z_geser += 0.5;
        break;
    case '`': // KELUAR DARI PROGRAM
        exit(1);
    }
}

void keyboard_up(unsigned char key, int x, int y) {
    switch (key) {
    case 'W':
    case 'w':
        motion.Forward = false;
        break;
    case 'A':
    case 'a':
        motion.Left = false;
        break;
    case 'S':
    case 's':
        motion.Backward = false;
        break;
    case 'D':
    case 'd':
        motion.Right = false;
        break;
    case 'E':
    case 'e':
        motion.Naik = false;
        break;
    case 'Q':
    case 'q':
        motion.Turun = false;
        break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("TR GRAFKOM KELOMPOK X");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutPassiveMotionFunc(passive_motion);
    glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard_up);

    glutMainLoop();
    return 0;
}