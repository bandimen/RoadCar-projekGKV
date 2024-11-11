#include <GL/glut.h>
#include "car.h"

void drawCar(float posX, float posY, float posZ, float wheelAngle, float warnaRed, float warnaGreen, float warnaBlue, float rotasi) {
    glPushMatrix();
    glTranslatef(posX, posY+0.6, posZ);

    // Rotasi 90 derajat
    glRotatef(rotasi, 0.0f, 1.0f, 0.0f);

    // Menggambar body utama mobil
    glColor3f(warnaRed, warnaGreen, warnaBlue); 
    glPushMatrix();
    glScalef(2.0f, 0.5f, 1.0f);
    glutSolidCube(1.0);
    glPopMatrix();

    // Menggambar bagian atas mobil
    glPushMatrix();
    glTranslatef(0.4f, 0.5f, 0.0f);
    glScalef(1.2f, 0.5f, 1.0f);
    glutSolidCube(1.0);
    glPopMatrix();

    // Menggambar kaca depan
    glColor3f(0.7686f, 0.8706f, 0.9647f); // Warna biru
    glPushMatrix();
    glTranslatef(-0.21f, 0.5f, 0.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(-0.5f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.05f, 0.2f);
    glVertex2f(0.95f, 0.2f);
    glVertex2f(0.95f, -0.2f);
    glVertex2f(0.05f, -0.2f);
    glEnd();
    glPopMatrix();

    // Menggambar kaca belakang
    glPushMatrix();
    glTranslatef(1.01f, 0.5f, 0.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(-0.5f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.05f, 0.2f);
    glVertex2f(0.95f, 0.2f);
    glVertex2f(0.95f, -0.2f);
    glVertex2f(0.05f, -0.2f);
    glEnd();
    glPopMatrix();
    
    // Menggambar bagian bawah mobil (serep)
    glColor3f(0.0f, 0.0f, 0.0f); // Warna hitam
    glPushMatrix();
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 0.23f, 1.11f);
    glutSolidTorus(0.1, 0.2, 20, 20);
    glPopMatrix();

    // Menggambar bumper
    glColor3f(0.4549f, 0.4549f, 0.4549f); // Warna abu-abu
    glPushMatrix();
    glTranslatef(1.01f, 0.0f, 0.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(-0.5f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.05f, -0.045f);
    glVertex2f(0.95f, -0.045f);
    glVertex2f(0.95f, -0.2f);
    glVertex2f(0.05f, -0.2f);
    glEnd();
    glPopMatrix();

    // Menggambar lampu belakang
    glColor3f(0.6784f, 0.0f, 0.0f); // Warna merah
    glPushMatrix();
    glTranslatef(1.0f, -0.12f, 0.3f);
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.0f, -0.12f, -0.3f);
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();

    // Menggambar lampu depan
    glColor3f(1.0f, 1.0f, 0.0f); // Warna kuning
    glPushMatrix();
    glTranslatef(-1.0f, -0.05f, 0.3f);
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.0f, -0.05f, -0.3f);
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();

    // Menggambar roda
    glColor3f(0.0f, 0.0f, 0.0f); // Warna hitam

    // Roda depan kiri
    glPushMatrix();
    glTranslatef(1.0f, -0.3f, 0.6f);
    glRotatef(wheelAngle, 0.0f, 0.0f, 1.0f); // Memutar roda
    glutSolidTorus(0.1, 0.2, 20, 20); // Menggunakan torus untuk roda
    glPopMatrix();

    // Roda depan kanan
    glPushMatrix();
    glTranslatef(1.0f, -0.3f, -0.6f);
    glRotatef(wheelAngle, 0.0f, 0.0f, 1.0f); // Memutar roda
    glutSolidTorus(0.1, 0.2, 20, 20); // Menggunakan torus untuk roda
    glPopMatrix();

    // Roda belakang kiri
    glPushMatrix();
    glTranslatef(-1.0f, -0.3f, 0.6f);
    glRotatef(wheelAngle, 0.0f, 0.0f, 1.0f); // Memutar roda
    glutSolidTorus(0.1, 0.2, 20, 20); // Menggunakan torus untuk roda
    glPopMatrix();

    // Roda belakang kanan
    glPushMatrix();
    glTranslatef(-1.0f, -0.3f, -0.6f);
    glRotatef(wheelAngle, 0.0f, 0.0f, 1.0f); // Memutar roda
    glutSolidTorus(0.1, 0.2, 20, 20); // Menggunakan torus untuk roda
    glPopMatrix();

    glPopMatrix();
}
