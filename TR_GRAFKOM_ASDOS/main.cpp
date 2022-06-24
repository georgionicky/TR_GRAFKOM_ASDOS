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
bool kondisiLampu = false;

//Langit
float r1 = 0.12;
float g1 = 0.12;
float b1 = 0.12;

//Rumput
float o1 = 0.7;

//Gunung
float g2 = 0.36;
float g21 = 0.36;

//Pohon
float g3 = 0.6;

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
<<<<<<< HEAD

=======
    
>>>>>>> 4cdf592ad3ac7ddebae5d9c02d7d808d610a7db4
>>>>>>> f33c2822b8b3c043c9b4cd774180f203cbb4504d
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
        o1 -= 0.7 / 180 / 10;
        g2 += 0.2 / 180 / 10;
        g21 += 0.4 / 180 / 10;
        g3 += 0.2 / 180 / 10;
        kondisiLampu = true;
    }

    if (sudut >= 180) {
        r1 -= 0.0045 / 10 / 2;
        g1 -= 0.0076 / 10 / 2;
        b1 -= 0.0089 / 10 / 2;
        o1 += 0.7 / 180 / 10;
        g2 -= 0.2 / 180 / 10;
        g21 -= 0.4 / 180 / 10;
        g3 -= 0.2 / 180 / 10;

    }

    if (sudut >= 110) {
        kondisiLampu = false;
    }

    //bulan
    glColor3f(1, 1, 1);
    glPushMatrix();
    glRotatef(-sudut + 45, -0.55, 0, -0.45);
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
<<<<<<< HEAD
    /* --------------------- bikin ngelaggg
=======
    /* --------------------- bikin ngelaggg 
>>>>>>> 4cdf592ad3ac7ddebae5d9c02d7d808d610a7db4
>>>>>>> f33c2822b8b3c043c9b4cd774180f203cbb4504d
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
    }*/
    

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


<<<<<<< HEAD
=======
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
    
>>>>>>> f33c2822b8b3c043c9b4cd774180f203cbb4504d
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

<<<<<<< HEAD
//Laut
=======
>>>>>>> 4cdf592ad3ac7ddebae5d9c02d7d808d610a7db4
>>>>>>> f33c2822b8b3c043c9b4cd774180f203cbb4504d
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

//Dasar Laut
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

//Atas laut
void bigGround() {

    glBegin(GL_QUADS);
    glColor4f(0, 0, 0, o1);
    glVertex3f(-5000.0, 5, -5000.0);

    glColor4f(0, 0, 0, o1);
    glVertex3f(5000.0, 5, -5000.0);

    glColor4f(0, 0, 0, o1);
    glVertex3f(5000.0, 5, 5000.0);

    glColor4f(0, 0, 0, o1);
    glVertex3f(-5000.0, 5, 5000.0);
    glEnd();


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

void tangga(float x, float y, float z, float panjang, float lebar, float jumlahKotak, float tinggiKotak, float kurang, int mengadapMana) {
    float c = 0.55;
    float kurangWarna = c / jumlahKotak / 5;
    float c2 = c - kurangWarna * 10;


    if (mengadapMana == 1) {
        for (int i = 0; i <= jumlahKotak; i++) {
            glColor3f(c2, c2, c2);
            objek1(x, y, z, tinggiKotak, lebar, panjang);
            c2 += kurangWarna;
            y += tinggiKotak;
            z -= kurang;
            lebar -= 2 * kurang;
        }
    }
    else if (mengadapMana == 2) {
        for (int i = 0; i <= jumlahKotak; i++) {
            glColor3f(c2, c2, c2);
            objek1(x, y, z, tinggiKotak, lebar, panjang);
            c2 += kurangWarna;
            y += tinggiKotak;
            z += kurang;
            lebar -= 2 * kurang;
        }
    }
    else if (mengadapMana == 3) {
        for (int i = 0; i <= jumlahKotak; i++) {
            glColor3f(c2, c2, c2);
            objek1(x, y, z, tinggiKotak, lebar, panjang);
            c2 += kurangWarna;
            y += tinggiKotak;
            x -= kurang;
            panjang -= 2 * kurang;
        }
    }

    else if (mengadapMana == 4) {
        for (int i = 0; i <= jumlahKotak; i++) {
            glColor3f(c2, c2, c2);
            objek1(x, y, z, tinggiKotak, lebar, panjang);
            c2 += kurangWarna;
            y += tinggiKotak;
            x += kurang;
            panjang -= 2 * kurang;
        }
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

void pagar2(float x, float y, float z, float panjang, float t) //dibawah pagar
{
    objek1(x, y + t - 40, z, 2, 2, panjang);
    for (int i = 0; i <= panjang; i++) {
        if (i % 40 == 0) {
            objek1(x - (panjang / 2) + i, y - 15, z, t, 2, 2);

        }
    }
    
}

void pintu(float x, float y, float z, float t, float p) {
    glColor3f(0.70, 0.2, 0);
    objek1(x - p / 2, y, z, t, 5, 5); //kiri
    objek1(x + p / 2, y, z, t, 5, 5);// kanan
    objek1(x, y + t, z, -5, 5, p); //atas
    objek1(x, y, z, 5, 5, p); //bawah


    //tutup
    glColor3f(0.76, 0.26, 0.04);
<<<<<<< HEAD
    objek1(x - p * 0.25, y + 2, z, t - 4, 2, p / 2 - 4);//bawah
=======
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
>>>>>>> f33c2822b8b3c043c9b4cd774180f203cbb4504d

    glColor3f(0.33, 0.15, 0.1);
    objek1(x - p * 0.45, y + 2, z, t - 4, 2.5, 0.2);
    objek1(x - p * 0.40, y + 2, z, t - 4, 2.5, 0.2);
    objek1(x - p * 0.35, y + 2, z, t - 4, 2.5, 0.2);
    objek1(x - p * 0.30, y + 2, z, t - 4, 2.5, 0.2);
    objek1(x - p * 0.25, y + 2, z, t - 4, 2.5, 0.2);
    objek1(x - p * 0.20, y + 2, z, t - 4, 2.5, 0.2);
    objek1(x - p * 0.15, y + 2, z, t - 4, 2.5, 0.2);
    objek1(x - p * 0.10, y + 2, z, t - 4, 2.5, 0.2);
    glColor3f(0.2, 0.01, 0.00);
    objek1(x - p * 0.1, y + t / 2, z, 2, 2.5, 2);

    //buka
    glColor3f(0.76, 0.26, 0.04);
<<<<<<< HEAD
    objek1(x + p / 2, y + 2, z + p * 0.25, t - 4, p / 2 - 4, 2);//bawah
    glColor3f(0.33, 0.15, 0.1);
    objek1(x + p / 2, y + 2, z + p * 0.45, t - 4, 0.2, 2.5);
    objek1(x + p / 2, y + 2, z + p * 0.40, t - 4, 0.2, 2.5);
    objek1(x + p / 2, y + 2, z + p * 0.35, t - 4, 0.2, 2.5);
    objek1(x + p / 2, y + 2, z + p * 0.30, t - 4, 0.2, 2.5);
    objek1(x + p / 2, y + 2, z + p * 0.25, t - 4, 0.2, 2.5);
    objek1(x + p / 2, y + 2, z + p * 0.20, t - 4, 0.2, 2.5);
    objek1(x + p / 2, y + 2, z + p * 0.15, t - 4, 0.2, 2.5);
    objek1(x + p / 2, y + 2, z + p * 0.10, t - 4, 0.2, 2.5);
    glColor3f(0.2, 0.01, 0.00);
    objek1(x + p / 2, y + t / 2, z + p * 0.4, 2, 2, 2.5);

=======
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
>>>>>>> f33c2822b8b3c043c9b4cd774180f203cbb4504d
}

void jendela(float x, float y, float z, float t, float p) {
    objek1(x, y, z, t, 2, 2);
    objek1(x + p, y, z, t, 2, 2);
    objek1(x + p, y, z, 2, 2, p);
    objek1(x, y, z, 2, 2, p);

}

<<<<<<< HEAD
void pintuEmpatSisi(float x, float y, float z, float tinggi, float panjang) {
    pintu(x, y, z, tinggi, panjang); //pintu depan
=======
<<<<<<< HEAD
void pintuEmpatSisi(float x, float y, float z, float tinggi) {
=======
void pintuEmpatSisi(float x, float y, float z , float tinggi) {
>>>>>>> 4cdf592ad3ac7ddebae5d9c02d7d808d610a7db4
    pintu(x, y, z, tinggi, 40); //pintu depan
>>>>>>> f33c2822b8b3c043c9b4cd774180f203cbb4504d

    glPushMatrix(); //pintu kanan
    glRotatef(90, 0, 1, 0);
    pintu(x, y, z, tinggi, panjang);
    glPopMatrix();

    glPushMatrix(); //pintu kiri
    glRotatef(-90, 0, 1, 0);
    pintu(x, y, z, tinggi, panjang);
    glPopMatrix();

    glPushMatrix(); //pintu belakang
    glRotatef(180, 0, 1, 0);
    pintu(x, y, z, tinggi, panjang);
    glPopMatrix();
}

void pohon(float x, float y, float z) {
    glColor3f(0.4, 0.24, 0.13);
<<<<<<< HEAD
    objek1(x, y, z, 155, 10, 10);

    glColor4f(0.2, 0.6, 0.2, 0.9);
=======
<<<<<<< HEAD
    objek1(x, y, z, 155, 10, 10);

    glColor4f(0.2, 0.6, 0.2, 0.9);
=======
    objek1(x,y,z,155,10,10);

    glColor4f(0.2, 0.6, 0.2,0.9);
>>>>>>> 4cdf592ad3ac7ddebae5d9c02d7d808d610a7db4
>>>>>>> f33c2822b8b3c043c9b4cd774180f203cbb4504d
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
void pohonBesar(float x, float y, float z) {
    glColor3f(0.4, 0.24, 0.13);
    objek1(x, y, z, 250, 30, 30);

    glColor4f(0.2, g3, 0.2, 0.95);

    //Depan
    objek1(x, 250 / 2, z + 50, 50, 45, 45);
    objek1(x + 50, 250 / 2, z + 50, 50, 45, 45);
    objek1(x - 50, 250 / 2, z + 50, 50, 45, 45);

    objek1(x, 360 / 2, z + 90, 50, 45, 45);
    objek1(x + 50, 360 / 2, z + 50, 50, 45, 45);
    objek1(x - 50, 360 / 2, z + 50, 50, 45, 45);

    objek1(x, 470 / 2, z + 50, 50, 45, 45);
    objek1(x + 50, 470 / 2, z + 50, 50, 45, 45);
    objek1(x - 50, 470 / 2, z + 50, 50, 45, 45);

    //Belakang
    objek1(x, 250 / 2, z - 50, 50, 45, 45);
    objek1(x + 50, 250 / 2, z - 50, 50, 45, 45);
    objek1(x - 50, 250 / 2, z - 50, 50, 45, 45);

    objek1(x, 360 / 2, z - 90, 50, 45, 45);
    objek1(x + 50, 360 / 2, z - 50, 50, 45, 45);
    objek1(x - 50, 360 / 2, z - 50, 50, 45, 45);

    objek1(x, 470 / 2, z - 50, 50, 45, 45);
    objek1(x + 50, 470 / 2, z - 50, 50, 45, 45);
    objek1(x - 50, 470 / 2, z - 50, 50, 45, 45);

    //Tengah 
    objek1(x - 50, 250 / 2, z, 50, 45, 45);
    objek1(x - 90, 360 / 2, z, 50, 45, 45);
    objek1(x - 50, 470 / 2, z, 50, 45, 45);
    objek1(x + 50, 250 / 2, z, 50, 45, 45);
    objek1(x + 90, 360 / 2, z, 50, 45, 45);
    objek1(x + 50, 470 / 2, z, 50, 45, 45);

    //Atas
    objek1(x, 525 / 2, z, 50, 45, 45);

}

void lampion(int x, int y, int z) {
    glColor3f(0.58, 0.17, 0);
    objek1(x + 25, y - 103, z, 130, 5, 5);
    objek1(x + 15, y + 20, z, 8, 5, 75);
    objek1(x, y, z, 25, 5, 2);

    if (kondisiLampu == false) {
        glPushMatrix();
        glColor3f(0, 0, 0);
        glTranslatef(x, y, z);
        glutSolidSphere(5, 20, 20);
        glPopMatrix();




        // 

        glColor3f(0.58, 0.17, 0);
        objek1(-x - 25, y - 103, z, 130, 5, 5);
        objek1(-x - 15, y + 20, z, 8, 5, 75);
        objek1(-x, y, z, 25, 5, 2);
        glPushMatrix();
        glColor4f(0, 0, 0, 0.8);
        glTranslatef(-x, y, z);
        glutSolidSphere(5, 20, 20);
        glPopMatrix();


    }
    else {
        glPushMatrix();
        glColor3f(0.94, 0.42, 0);
        glTranslatef(x, y, z);
        glutSolidSphere(5, 20, 20);
        glPopMatrix();

        glPushMatrix();
        glColor4f(1, 0.98, 0.71, 0.8);
        glTranslatef(x, y, z);
        glutSolidSphere(10, 20, 20);
        glPopMatrix();

        glPushMatrix();
        glColor4f(0.99, 0.95, 0.2, 0.7);
        glTranslatef(x, y, z);
        glutSolidSphere(13.5, 20, 20);
        glPopMatrix();

        glPushMatrix();
        glColor4f(0.99, 0.95, 0.2, 0.6);
        glTranslatef(x, y, z);
        glutSolidSphere(14, 20, 20);
        glPopMatrix();

        glPushMatrix();
        glColor4f(0.99, 0.95, 0.2, 0.5);
        glTranslatef(x, y, z);
        glutSolidSphere(15, 20, 20);
        glPopMatrix();

        glPushMatrix();
        glColor4f(0.99, 0.95, 0.2, 0.45);
        glTranslatef(x, y, z);
        glutSolidSphere(20, 20, 20);
        glPopMatrix();

        glPushMatrix();
        glColor4f(0.99, 0.95, 0.2, 0.4);
        glTranslatef(x, y, z);
        glutSolidSphere(25, 20, 20);
        glPopMatrix();

        glPushMatrix();
        glColor4f(0.99, 0.95, 0.2, 0.35);
        glTranslatef(x, y, z);
        glutSolidSphere(30, 20, 20);
        glPopMatrix();

        glPushMatrix();
        glColor4f(0.99, 0.95, 0.2, 0.3);
        glTranslatef(x, y, z);
        glutSolidSphere(35, 20, 20);
        glPopMatrix();


        // 

        glColor3f(0.58, 0.17, 0);
        objek1(-x - 25, y - 103, z, 130, 5, 5);
        objek1(-x - 15, y + 20, z, 8, 5, 75);
        objek1(x, y, z, 25, 5, 2);
        glPushMatrix();
        glColor3f(0.94, 0.42, 0);
        glTranslatef(-x, y, z);
        glutSolidSphere(5, 20, 20);
        glPopMatrix();

        glPushMatrix();
        glColor4f(1, 0.98, 0.71, 0.8);
        glTranslatef(-x, y, z);
        glutSolidSphere(10, 20, 20);
        glPopMatrix();

        glPushMatrix();
        glColor4f(0.99, 0.95, 0.2, 0.7);
        glTranslatef(-x, y, z);
        glutSolidSphere(13.5, 20, 20);
        glPopMatrix();

        glPushMatrix();
        glColor4f(0.99, 0.95, 0.2, 0.6);
        glTranslatef(-x, y, z);
        glutSolidSphere(14, 20, 20);
        glPopMatrix();

        glPushMatrix();
        glColor4f(0.99, 0.95, 0.2, 0.5);
        glTranslatef(-x, y, z);
        glutSolidSphere(15, 20, 20);
        glPopMatrix();

        glPushMatrix();
        glColor4f(0.99, 0.95, 0.2, 0.45);
        glTranslatef(-x, y, z);
        glutSolidSphere(20, 20, 20);
        glPopMatrix();

        glPushMatrix();
        glColor4f(0.99, 0.95, 0.2, 0.4);
        glTranslatef(-x, y, z);
        glutSolidSphere(25, 20, 20);
        glPopMatrix();

        glPushMatrix();
        glColor4f(0.99, 0.95, 0.2, 0.35);
        glTranslatef(-x, y, z);
        glutSolidSphere(30, 20, 20);
        glPopMatrix();

        glPushMatrix();
        glColor4f(0.99, 0.95, 0.2, 0.3);
        glTranslatef(-x, y, z);
        glutSolidSphere(35, 20, 20);
        glPopMatrix();
    }







}

void lampuKuil(int x, int y, int z) {
    glColor3f(0.58, 0.17, 0);
    objek1(x, y, z, 10, 5, 2);


    if (kondisiLampu == false) {
        glPushMatrix();
        glColor3f(0, 0, 0);
        glTranslatef(x, y, z);
        glutSolidSphere(5, 20, 20);
        glPopMatrix();

    }
    else {

        glPushMatrix();
        glColor3f(0.99, 0.95, 0.2);
        glTranslatef(x, y, z);
        glutSolidSphere(5, 20, 20);
        glPopMatrix();

        glPushMatrix();
        glColor4f(0.99, 0.95, 0.2, 0.8);
        glTranslatef(x, y, z);
        glutSolidSphere(6, 20, 20);
        glPopMatrix();

        glPushMatrix();
        glColor4f(0.99, 0.95, 0.2, 0.6);
        glTranslatef(x, y, z);
        glutSolidSphere(8, 20, 20);
        glPopMatrix();

        glPushMatrix();
        glColor4f(0.99, 0.95, 0.2, 0.4);
        glTranslatef(x, y, z);
        glutSolidSphere(10, 20, 20);
        glPopMatrix();
    }



}

void Pulau() {
    objek3(0, -297, 0, 300, 1500, 1500);
    objek3(2000, -299, 0, 300, 1500, 1500); //Kanan
    objek3(-2000, -299, 0, 300, 1500, 1500); // Kiri
    objek3(0, -299, 2000, 300, 1500, 1500); // Depan
    objek3(0, -299, -2000, 300, 1500, 1500); // Belakang
}

void tiang(float x, float y, float z, float t) {

    glColor3f(0.7, 0.53, 0);
    objek2(x, y, z, t * 0.25, 18, 15);
    objek2(x, y + t * 0.25, z, t * 0.5, 14, 14);
    glColor3f(0.65, 0.45, 0);
    objek2(x, y + t * 0.75, z, t * 0.25, 11, 8);

    glColor3f(1, 0.83, 0);
    objek1(x, y + t * 0.2, z, 5, 25, 25);
    objek1(x, y + t * 0.25, z, 5, 25, 25);
    objek1(x, y + t * 0.3, z, 5, 25, 25);
    objek1(x, y + t * 0.35, z, 5, 25, 25);
    objek1(x, y + t * 0.4, z, 5, 25, 25);
    objek1(x, y + t * 0.45, z, 5, 25, 25);
    objek1(x, y + t * 0.5, z, 5, 25, 25);
    objek1(x, y + t * 0.55, z, 5, 25, 25);
    objek1(x, y + t * 0.6, z, 5, 25, 25);
    objek1(x, y + t * 0.65, z, 5, 25, 25);
    objek1(x, y + t * 0.7, z, 5, 25, 25);

    glPushMatrix();
    glTranslatef(0, y + t * 0.85, 0);
    glutSolidSphere(11, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, y + t, 0);
    glutSolidSphere(11, 20, 20);
    glPopMatrix();
}

void susunanKotak(float x, float y, float z, float panjang, float lebar, float jumlahKotak, float tinggiKotak, float kurang, int mengadapMana) {

    if (mengadapMana == 1) {
        for (int i = 0; i <= jumlahKotak; i++) {

            objek1(x, y, z, tinggiKotak, lebar, panjang);

            y += tinggiKotak;
            z -= kurang;
            lebar -= 2 * kurang;
        }
    }
    else if (mengadapMana == 2) {
        for (int i = 0; i <= jumlahKotak; i++) {

            objek1(x, y, z, tinggiKotak, lebar, panjang);

            y += tinggiKotak;
            z += kurang;
            lebar -= 2 * kurang;
        }
    }
    else if (mengadapMana == 3) {
        for (int i = 0; i <= jumlahKotak; i++) {

            objek1(x, y, z, tinggiKotak, lebar, panjang);

            y += tinggiKotak;
            x -= kurang;
            panjang -= 2 * kurang;
        }
    }

    else if (mengadapMana == 4) {
        for (int i = 0; i <= jumlahKotak; i++) {

            objek1(x, y, z, tinggiKotak, lebar, panjang);

            y += tinggiKotak;
            x += kurang;
            panjang -= 2 * kurang;
        }
    }

}
void jendela1(float x, float y, float z, float t, float p) {

    glColor3f(0.76, 0.26, 0.04);
    objek1(x, y, z - 1, t, 3, 2);
    objek1(x + p, y, z - 1, t, 3, 2);
    objek1(x + p / 2, y, z, 5, 5, p + 20);
    objek1(x + p / 2, y + t, z, 5, 5, p + 20);

    glColor3f(0.86, 0.66, 0.41);
    objek1(x + p / 2, y, z - 1, t, 2, p);

    glColor3f(0.4, 0.2, 0.1);
    objek1(x + p * 0.1, y, z - 1, t, 2.5, 0.3);
    objek1(x + p * 0.2, y, z - 1, t, 2.5, 0.3);
    objek1(x + p * 0.3, y, z - 1, t, 2.5, 0.3);
    objek1(x + p * 0.4, y, z - 1, t, 2.5, 0.3);
    objek1(x + p * 0.5, y, z - 1, t, 2.5, 0.3);
    objek1(x + p * 0.6, y, z - 1, t, 2.5, 0.3);
    objek1(x + p * 0.7, y, z - 1, t, 2.5, 0.3);
    objek1(x + p * 0.8, y, z - 1, t, 2.5, 0.3);
    objek1(x + p * 0.9, y, z - 1, t, 2.5, 0.3);


}
void ornamen(float x, float y, float z) {
    glColor3f(0.76, 0.26, 0.04);
    susunanKotak(-x, y, z, 20, 0, 3, 3, -3, 1);
    susunanKotak(-x + x / 2, y, z, 20, 0, 3, 3, -3, 1);

    susunanKotak(x, y, z, 20, 0, 3, 3, -3, 1);
    susunanKotak(x - x / 2, y, z, 20, 0, 3, 3, -3, 1);

    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    susunanKotak(-x, y, z, 20, 0, 3, 3, -3, 1);
    susunanKotak(-x + x / 2, y, z, 20, 0, 3, 3, -3, 1);

    susunanKotak(x, y, z, 20, 0, 3, 3, -3, 1);
    susunanKotak(x - x / 2, y, z, 20, 0, 3, 3, -3, 1);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 0, 1, 0);
    susunanKotak(-x, y, z, 20, 0, 3, 3, -3, 1);
    susunanKotak(-x + x / 2, y, z, 20, 0, 3, 3, -3, 1);

    susunanKotak(x, y, z, 20, 0, 3, 3, -3, 1);
    susunanKotak(x - x / 2, y, z, 20, 0, 3, 3, -3, 1);
    glPopMatrix();

    glPushMatrix();
    glRotatef(180, 0, 1, 0);
    susunanKotak(-x, y, z, 20, 0, 3, 3, -3, 1);
    susunanKotak(-x + x / 2, y, z, 20, 0, 3, 3, -3, 1);

    susunanKotak(x, y, z, 20, 0, 3, 3, -3, 1);
    susunanKotak(x - x / 2, y, z, 20, 0, 3, 3, -3, 1);
    glPopMatrix();
}

void ornamen2(float x, float y, float z, float t, float p, float lantai) {

    int kurang = 0;
    float kurang2 = 0;

    if (lantai >= 3) {
        kurang = 10;
        kurang2 = t * 0.28;
    }
    else if (lantai == 2) {
        kurang = 3;
        kurang2 = t * 0.28;
    }



    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glTranslatef(x + p / 2, z + p / 2, y);
    gluCylinder(gluNewQuadric(), 5, 5, t, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glTranslatef(x - p / 2, z + p / 2, y);
    gluCylinder(gluNewQuadric(), 5, 5, t, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glTranslatef(x - p / 2, z - p / 2, y);
    gluCylinder(gluNewQuadric(), 5, 5, t, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glTranslatef(x + p / 2, z - p / 2, y);
    gluCylinder(gluNewQuadric(), 5, 5, t, 32, 32);
    glPopMatrix();


    //tengah
    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glTranslatef(x + p * 0.1 + kurang, z + p / 2, y);
    gluCylinder(gluNewQuadric(), 5, 5, t - kurang2, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glTranslatef(x - p * 0.1 - kurang, z + p / 2, y);
    gluCylinder(gluNewQuadric(), 5, 5, t - kurang2, 32, 32);
    glPopMatrix();

    //

    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glTranslatef(x + p * 0.1 + kurang, z - p / 2, y);
    gluCylinder(gluNewQuadric(), 5, 5, t - kurang2, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glTranslatef(x - p * 0.1 - kurang, z - p / 2, y);
    gluCylinder(gluNewQuadric(), 5, 5, t - kurang2, 32, 32);
    glPopMatrix();

    //

    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glTranslatef(x - p / 2, z - p * 0.1 - kurang, y);
    gluCylinder(gluNewQuadric(), 5, 5, t - kurang2, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glTranslatef(x - p / 2, z + p * 0.1 + kurang, y);
    gluCylinder(gluNewQuadric(), 5, 5, t - kurang2, 32, 32);
    glPopMatrix();

    //

    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glTranslatef(x + p / 2, z - p * 0.1 - kurang, y);
    gluCylinder(gluNewQuadric(), 5, 5, t - kurang2, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glTranslatef(x + p / 2, z + p * 0.1 + kurang, y);
    gluCylinder(gluNewQuadric(), 5, 5, t - kurang2, 32, 32);
    glPopMatrix();


}

void ornamen3(float x, float y, float z, float t, float p) {
    objek1(x, y, z + p / 2, 5, 5, p);
    objek1(x, y + t - 5, z + p / 2, 5, 5, p);
    objek1(x, y + t - t * 0.2, z + p / 2, 5, 5, p);
    objek1(x, y + t - t * 0.28, z + p / 2, 5, 5, p);

    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    objek1(x, y, z + p / 2, 5, 5, p);
    objek1(x, y + t - 5, z + p / 2, 5, 5, p);
    objek1(x, y + t - t * 0.2, z + p / 2, 5, 5, p);
    objek1(x, y + t - t * 0.28, z + p / 2, 5, 5, p);
    glPopMatrix();

    glPushMatrix();
    glRotatef(180, 0, 1, 0);
    objek1(x, y, z + p / 2, 5, 5, p);
    objek1(x, y + t - 5, z + p / 2, 5, 5, p);
    objek1(x, y + t - t * 0.2, z + p / 2, 5, 5, p);
    objek1(x, y + t - t * 0.28, z + p / 2, 5, 5, p);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 0, 1, 0);
    objek1(x, y, z + p / 2, 5, 5, p);
    objek1(x, y + t - 5, z + p / 2, 5, 5, p);
    objek1(x, y + t - t * 0.2, z + p / 2, 5, 5, p);
    objek1(x, y + t - t * 0.28, z + p / 2, 5, 5, p);
    glPopMatrix();
}

void jendelaBanyak(float x, float y, float z, float t, float p, float lantai = 1) {

    
    float panjang = p * 0.3;
    float posY = t * 0.3;
    float posX = p * 15;
    float kurangX = 0;
    float tinggi = t * 0.4;
    if (lantai >= 3) {
        panjang = p * 0.25;
        posY = t * 0.1;
        tinggi = t * 0.2;
        posX = t * 0.20;
        kurangX = p * 0.05;
    }

    jendela1(x + p * 0.15 + kurangX, y + posY, z + p / 2 + 1, tinggi, panjang);
    jendela1(x - p * 0.15 - p * 0.3  , y + posY, z + p / 2 + 1, tinggi, panjang);

    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    jendela1(x + p * 0.15 + kurangX, y + posY, z + p / 2 + 1, tinggi, panjang);
    jendela1(x - p * 0.15 - p * 0.3 , y + posY, z + p / 2 + 1, tinggi, panjang);
    glPopMatrix();

    glPushMatrix();
    glRotatef(180, 0, 1, 0);
    jendela1(x + p * 0.15 + kurangX, y + posY, z + p / 2 + 1, tinggi, panjang);
    jendela1(x - p * 0.15 - p * 0.3 , y + posY, z + p / 2 + 1, tinggi, panjang);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 0, 1, 0);
    jendela1(x + p * 0.15 + kurangX, y + posY, z + p / 2 + 1, tinggi, panjang);
    jendela1(x - p * 0.15 - p * 0.3 , y + posY, z + p / 2 + 1, tinggi, panjang);
    glPopMatrix();


}

void ornamenTambahan() {
    glColor3f(0.76, 0.26, 0.04);
    objek1(-175 / 2 - 15, 162, 175, 5, 5, 350 / 2 - 30);
    objek1(175 / 2 + 15, 162, 175, 5, 5, 350 / 2 - 30);

    objek1(-175 / 2 - 15, 102, 175, 75, 5, 10);
    objek1(175 / 2 + 15, 102, 175, 75, 5, 10);

    objek1( - 175 / 2 - 15, 112, 175, 5, 5, 350 / 2 - 30);
    objek1( 175 / 2 + 15, 112, 175, 5, 5, 350 / 2 - 30);

    //jendelaTambahan untuk lantai 1, karena beda sendiri, nyusahin :|
    glColor3f(0.15, 0.15, 0);
    objek1(175 / 2 -20, 120, 175, 3, 3, 40); //kanan
    objek1(175 / 2 - 20, 120 + 38, 175, 3, 3, 40); //atas
    objek1(175 / 2 - 20, 120, 175, 40, 3, 3);
    objek1(175 / 2 - 40, 120, 175, 40, 3, 3);
    objek1(175 /2 , 120, 175, 40, 3, 3);
    objek1(175 / 2 - 10, 120, 175, 40, 3, 1);
    objek1(175 / 2 - 30, 120, 175, 40, 3, 1);
    objek1(175 / 2 - 20, 120 + 26, 175, 1, 3, 40);
    objek1(175 / 2 - 20, 120 + 14, 175, 1, 3, 40);

    glPushMatrix();
    glTranslatef(70,0,0);
    objek1(175 / 2 - 20, 120, 175, 3, 3, 40); //kanan
    objek1(175 / 2 - 20, 120 + 38, 175, 3, 3, 40); //atas
    objek1(175 / 2 - 20, 120, 175, 40, 3, 3);
    objek1(175 / 2 - 40, 120, 175, 40, 3, 3);
    objek1(175 / 2, 120, 175, 40, 3, 3);
    objek1(175 / 2 - 10, 120, 175, 40, 3, 1);
    objek1(175 / 2 - 30, 120, 175, 40, 3, 1);
    objek1(175 / 2 - 20, 120 + 26, 175, 1, 3, 40);
    objek1(175 / 2 - 20, 120 + 14, 175, 1, 3, 40);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-135, 0, 0);
    objek1(175 / 2 - 20, 120, 175, 3, 3, 40); //kanan
    objek1(175 / 2 - 20, 120 + 38, 175, 3, 3, 40); //atas
    objek1(175 / 2 - 20, 120, 175, 40, 3, 3);
    objek1(175 / 2 - 40, 120, 175, 40, 3, 3);
    objek1(175 / 2, 120, 175, 40, 3, 3);
    objek1(175 / 2 - 10, 120, 175, 40, 3, 1);
    objek1(175 / 2 - 30, 120, 175, 40, 3, 1);
    objek1(175 / 2 - 20, 120 + 26, 175, 1, 3, 40);
    objek1(175 / 2 - 20, 120 + 14, 175, 1, 3, 40);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-205, 0, 0);
    objek1(175 / 2 - 20, 120, 175, 3, 3, 40); //kanan
    objek1(175 / 2 - 20, 120 + 38, 175, 3, 3, 40); //atas
    objek1(175 / 2 - 20, 120, 175, 40, 3, 3);
    objek1(175 / 2 - 40, 120, 175, 40, 3, 3);
    objek1(175 / 2, 120, 175, 40, 3, 3);
    objek1(175 / 2 - 10, 120, 175, 40, 3, 1);
    objek1(175 / 2 - 30, 120, 175, 40, 3, 1);
    objek1(175 / 2 - 20, 120 + 26, 175, 1, 3, 40);
    objek1(175 / 2 - 20, 120 + 14, 175, 1, 3, 40);
    glPopMatrix();
}

void meja() {
    glColor3f(0.8, 0.65, 0.47);
    objek1(0, 132, 0, 2, 60, 60);
    glColor3f(0.6, 0.45, 0.27);
    objek1(0, 134, 0, 0.2, 50, 50);
    glColor3f(0.63, 0.46, 0.29);
    objek2(0, 102, 0, 30, 20, 10);
}

void kursi() {
    glColor3f(0.63, 0.46, 0.29);
    objek1(0, 122, -60, 2, 22, 22);
    objek1(10, 102, -50, 20, 2, 2);
    objek1(10, 102, -70, 20, 2, 2);
    objek1(-10, 102, -50, 20, 2, 2);
    objek1(-10, 102, -70, 20, 2, 2);
    objek1(0, 122, -70, 25, 2, 22);
}

void draw() {
    // Mulai tuliskan isi pikiranmu disini
<<<<<<< HEAD

    // Mulai tuliskan isi pikiranmu disini

=======
<<<<<<< HEAD

    //Warna
    //glColor3f(0.32, 0.47, 0.48);  || Atap Lapisan 1
    //glColor3f(0.4, 0.58, 0.59);   || Atap Lapisan 2
    //glColor3f(0.93, 0.94, 0.95);  ||  Tembok

=======
    
>>>>>>> f33c2822b8b3c043c9b4cd774180f203cbb4504d
    //Warna
    //glColor3f(0.32, 0.47, 0.48);  || Atap Lapisan 1
    //glColor3f(0.4, 0.58, 0.59);   || Atap Lapisan 2
    //glColor3f(0.93, 0.94, 0.95);  ||  Tembok

>>>>>>> 4cdf592ad3ac7ddebae5d9c02d7d808d610a7db4
    matahariBulan(); //matahari dan bulan,, bisa bergerak lohh

    //bagian dalam lantai 1
    meja();

    kursi();

    glPushMatrix();
    glRotatef(90,0,1,0);
    kursi();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 0, 1, 0);
    kursi();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90 * 2, 0, 1, 0);
    kursi();
    glPopMatrix();

    glColor3f(0.63, 0.16, 0.19);
    objek1(0, 110, 0, 0.2, 200, 200);

    //bagian dalam lantai 2

    glColor3f(0.37, 0.2, 0.2);
    objek1(0, 186, 0, 0.2, 200, 200);

    glPushMatrix();
    glTranslatef(0, 76, 0);
    meja();
    glPopMatrix();

    // bagian dalam lantai 3
    objek1(0, 339, 0, 0.2, 200, 200);

    glColor3f(0.1, 0.1, 0.1);
    objek1(0, 343, -80, 30, 3, 60);
    glColor3f(0.4, 0.4, 0.6);
    objek1(0, 344, -80, 28, 3.2, 56);

    glColor3f(0.1, 0.1, 0.1);
    objek2(0, 341, -80, 3, 10, 5);

    //bagian dalam lantai 4
    objek1(0, 441, 0, 0.2, 200, 200);
    glColor3f(0.8, 0.73, 0.73);
    objek2(50, 441, 50, 3, 30, 26);

    objek2(10, 441, 50, 3, 30, 26);

    objek2(-50, 441, 50, 3, 30, 26);

    objek2(-50, 441, 10, 3, 30, 26);

    objek2(-50, 441, -50, 3, 30, 26);


    
    //pintu lantai ------------------------------------------->
<<<<<<< HEAD
    pintuEmpatSisi(0, 110, 175, 60, 60); //1
    pintuEmpatSisi(0, 186, 137, 60, 50); //2
    pintuEmpatSisi(0, 339, 100, 30, 50); //3
    pintuEmpatSisi(0, 440, 100, 30, 50); //4
=======
    pintuEmpatSisi(0, 110, 176, 60); //1
<<<<<<< HEAD
    pintuEmpatSisi(0, 186, 137, 60); //2
=======
    pintuEmpatSisi(0, 186, 137,60); //2
>>>>>>> 4cdf592ad3ac7ddebae5d9c02d7d808d610a7db4
    pintuEmpatSisi(0, 329, 100, 60); //3
    pintuEmpatSisi(0, 435, 100, 60); //4
>>>>>>> f33c2822b8b3c043c9b4cd774180f203cbb4504d
    //-------------------------------------------------------->

    //pohon-pohonan ------------------------------------------>
    pohon(400, 0, 600);

    //--------------------------------------------------------->

    //jendelaan------------------------------------------------>
    jendelaBanyak(0, 186, 0, 100, 275);
    jendelaBanyak(0, 339, 0, 100, 200, 3);
    jendelaBanyak(0, 441, 0, 100, 200, 4);
    //--------------------------------------------------------->

    //tiang atap ---------------------------------------------->
    glColor3f(0.65, 0.45, 0);
    objek2(0, 610, 0, 25, 50, 65);
    glColor3f(0.85, 0.65, 0);
    objek2(0, 636, 0, 1, 65, 65);
    tiang(0, 635, 0, 250);

    //--------------------------------------------------------->

    //ornamen ------------------------------------------------->
    ornamen(128, 275, 137.6);
    ornamen(90.1, 390, 100.1);
    ornamen(90.1, 485, 100.1);

    ornamen2(0, 102, 0, 75, 350, 1);
    ornamen2(0, 186, 0, 100, 275, 2);
    ornamen2(0, 339, 0, 60, 200, 3);
    ornamen2(0, 441, 0, 60, 200, 4);

    ornamen3(0, 186, 0, 100, 275);
    ornamen3(0, 339, 0, 60, 200);
    ornamen3(0, 441, 0, 60, 200);

    //-----------ornamen tambahan lantai 1---------------------->
    glColor3f(0.76, 0.26, 0.04);
    objek1(230, 102, -230, 75, 5, 5);
    objek1(230,102,230,75,5,5);
    objek1(-230, 102, 230, 75, 5, 5);
    objek1(-230, 102, -230, 75, 5, 5);

    //----masih lantai 1---------------------------------
    ornamenTambahan();

    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    ornamenTambahan();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 0, 1, 0);
    ornamenTambahan();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90*2, 0, 1, 0);
    ornamenTambahan();
    glPopMatrix();


    
    //-----------ornamen tambahan lantai 2---------------------->

    //-----------ornamen tambahan lantai 3---------------------->
    glColor3f(0.76, 0.26, 0.04);
    pagar2(0, 471, 150, 300, 55);
    
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    pagar2(0, 471, 150, 300, 55);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 0, 1, 0);
    pagar2(0, 471, 150, 300, 55);
    glPopMatrix();

    glPushMatrix();
    glRotatef(180, 0, 1, 0);
    pagar2(0, 471, 150, 300, 55);
    glPopMatrix();

    //--------------------------------------------------------->

    //pohon-pohonan ------------------------------------------>
    pohon(400, 0, 600);
    pohon(600, 0, 600);
    pohon(600, 0, 400);

    pohon(-400, 0, 600);
    pohon(-600, 0, 600);
    pohon(-600, 0, 400);

    pohon(400, 0, -600);
    pohon(600, 0, -600);
    pohon(-400, 0, -600);
    pohon(-600, 0, -400);

    for (int i = 1; i < 1000; i += 300) {
        pohonBesar(150, 0, 1700 + i);
        pohonBesar(-150, 0, 1700 + i);
        pohon(150, 0, 1550 + i);
        pohon(-150, 0, 1550 + i);
    }

    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    for (int i = 1; i < 1000; i += 300) {
        pohonBesar(150, 0, 1700 + i);
        pohonBesar(-150, 0, 1700 + i);
        pohon(150, 0, 1550 + i);
        pohon(-150, 0, 1550 + i);
    }
    glPopMatrix();

    glPushMatrix();
    glRotatef(180, 0, 1, 0);
    for (int i = 1; i < 1000; i += 300) {
        pohonBesar(150, 0, 1700 + i);
        pohonBesar(-150, 0, 1700 + i);
        pohon(150, 0, 1550 + i);
        pohon(-150, 0, 1550 + i);
    }
    glPopMatrix();

    glPushMatrix();
    glRotatef(270, 0, 1, 0);
    for (int i = 1; i < 1000; i += 300) {
        pohonBesar(150, 0, 1700 + i);
        pohonBesar(-150, 0, 1700 + i);
        pohon(150, 0, 1550 + i);
        pohon(-150, 0, 1550 + i);
    }
    glPopMatrix();


    //Lampion
    for (int i = 1; i < 1000; i += 200) {
        lampion(90, 160, 1240 - i);
    }

    //Lampu Kuil
    //Lantai 1
    lampuKuil(210, 165, 210);
    lampuKuil(-210, 165, 210);
    lampuKuil(-210, 165, -210);
    lampuKuil(210, 165, -210);

    //Lantai 2
    lampuKuil(180, 290, 180);
    lampuKuil(-180, 290, 180);
    lampuKuil(-180, 290, -180);
    lampuKuil(180, 290, -180);

    //Lantai 3
    lampuKuil(130, 395, 130);
    lampuKuil(-130, 395, 130);
    lampuKuil(-130, 395, -130);
    lampuKuil(130, 395, -130);

    //Lantai 4
    lampuKuil(130, 485, 130);
    lampuKuil(-130, 485, 130);
    lampuKuil(-130, 485, -130);
    lampuKuil(130, 485, -130);


    //Gapura ------------------------------------------------->

    glColor3f(0.58, 0.17, 0);
    objek1(-85, 0, 1440, 200, 10, 10);
    objek1(85, 0, 1440, 200, 10, 10);

    objek1(0, 150, 1440, 10, 10, 250);
    objek1(0, 200, 1440, 10, 10, 250);

    //-------------------------------------------------------->

    //dasar
    glColor3f(0.55, 0.55, 0.55);
<<<<<<< HEAD
    objek2(0, 0, 0, 110, 700, 650);

=======
<<<<<<< HEAD
    objek2(0, 0, 0, 110, 700, 650);

=======
    objek2(0, 0, 0, 110, 700,650);
    
>>>>>>> 4cdf592ad3ac7ddebae5d9c02d7d808d610a7db4
>>>>>>> f33c2822b8b3c043c9b4cd774180f203cbb4504d
    //tangga
    tangga(0, 55, 410, 250, 170, 7, 7, 7, 1);
    //Jembatan Depan
    //Tangga
    tangga(0, 0, 1335, 250, 170, 10, 5, 7, 1);
    //Penghubung
    glColor3f(0.49, 0.25, 0);
    objek1(0, 35, 800, 20, 900, 280);
    for (int i = 1; i < 360; i += 30) {
        glColor3f(0.34, 0.17, 0);
        objek1(130, 2, 400 + i, 35, 10, 10);
        objek1(-130, 2, 400 + i, 35, 10, 10);
    }
    //Pagar
    //Kiri
    glPushMatrix();
    glRotatef(-90, 0, 1, 0);
    glColor3f(0.75, 0.75, 0.75);
    pagar(880, 70, 135, 750);
    glPopMatrix();
    //Kanan
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glColor3f(0.75, 0.75, 0.75);
    pagar(-880, 70, 135, 750);
    glPopMatrix();

    //Jembatan Belakang
    // //Tangga 2
    tangga(0, 0, -665, 250, 170, 10, 5, 7, 1);
    //Tangga 2
    tangga(0, 0, -1335, 250, 170, 10, 5, 7, 2);
    //Penghubung
    glColor3f(0.49, 0.25, 0);
    objek1(0, 35, -1000, 20, 500, 280);
    //Pagar
    //Kiri
    glPushMatrix();
    glRotatef(-90, 0, 1, 0);
    glColor3f(0.75, 0.75, 0.75);
    pagar(-1000, 70, 135, 500);
    glPopMatrix();
    //Kanan
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glColor3f(0.75, 0.75, 0.75);
    pagar(1000, 70, 135, 500);
    glPopMatrix();

    //Jembatan Kanan
    // //Tangga 2
    tangga(625, 0, 0, 250, 170, 10, 5, 7, 4);
    //Tangga 2
    tangga(1375, 0, 0, 250, 170, 10, 5, 7, 3);
    //Penghubung
    glPushMatrix();
    glRotatef(-90, 0, 1, 0);
    glColor3f(0.49, 0.25, 0);
    objek1(0, 35, -1000, 20, 500, 280);
    glPopMatrix();
    glColor3f(0.49, 0.25, 0);
    //Pagar
    //Kiri
    glColor3f(0.75, 0.75, 0.75);
    pagar(1000, 70, 135, 500);

    //Kanan
    glColor3f(0.75, 0.75, 0.75);
    pagar(1000, 70, -135, 500);



    //Jembatan Kiri
    // //Tangga 2
    tangga(-625, 0, 0, 250, 170, 10, 5, 7, 3);
    //Tangga 2
    tangga(-1375, 0, 0, 250, 170, 10, 5, 7, 4);
    //Penghubung
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glColor3f(0.49, 0.25, 0);
    objek1(0, 35, -1000, 20, 500, 280);
    glPopMatrix();
    glColor3f(0.49, 0.25, 0);
    //Pagar
    //Kiri
    glColor3f(0.75, 0.75, 0.75);
    pagar(-1000, 70, 135, 500);

    //Kanan
    glColor3f(0.75, 0.75, 0.75);
    pagar(-1000, 70, -135, 500);




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

    //Gunung
    //1
    glColor3f(0.21, g2, 0.13);
    objek2(5500, -100, 2800, 2900, 4000, 500);
    //2
    glColor3f(0.21, g21, 0.13);
    objek2(5000, -100, -1000, 2700, 4000, 500);
    //3
    glColor3f(0.21, g2, 0.13);
    objek2(3600, -100, -5300, 3000, 4000, 500);
    //4
    glColor3f(0.21, g21, 0.13);
    objek2(500, -100, -5700, 4000, 5000, 500);
    //5
    glColor3f(0.21, g2, 0.13);
    objek2(-3500, -100, -6000, 2700, 4000, 500);




    Pulau();
    ground2();
    ground();
    bigGround();

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