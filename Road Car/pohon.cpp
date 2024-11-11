#include <GL/glut.h>
#include "pohon.h"

void drawTree(float x, float z) {
    // Batang pohon
    glPushMatrix();
    glColor3f(0.55f, 0.27f, 0.07f); // Warna coklat untuk batang pohon
    glTranslatef(x, 1.0f, z); // Mengatur posisi batang pohon
    glScalef(0.2f, 4.0f, 0.2f); // Membuat batang pohon lebih besar
    glutSolidCube(1.0);
    glPopMatrix();

    // Daun pohon
    glPushMatrix();
    	glPushMatrix();
		    glColor3f(0.0f, 1.0f, 0.0f); // Warna hijau untuk daun pohon
		    glTranslatef(x, 2.0f, z); // Mengatur posisi daun pohon
		    glRotatef(-90, 1, 0, 0);
		    glutSolidCone(1.5, 2.0, 10, 10); // Membuat daun pohon lebih besar
	    glPopMatrix();
	    glPushMatrix();
		    glColor3f(0.0f, 1.0f, 0.0f); // Warna hijau untuk daun pohon
		    glTranslatef(x, 3.5f, z); // Mengatur posisi daun pohon
		    glRotatef(-90, 1, 0, 0);
		    glutSolidCone(1.0, 1.5, 10, 10); // Membuat daun pohon lebih besar
	    glPopMatrix();
	glPopMatrix();
}


