#include <GL/glut.h>
#include "road.h"
void drawRoadStrip(int x) {
	glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f); // Warna putih strip
		glRotatef(90, 0, 1, 0);
		glTranslatef(x, 0.0f, -0.20f);
		glBegin(GL_QUADS);
			glVertex3f(-2.0f, 0.1275f, 0.0f);
			glVertex3f(2.0f, 0.1275f, 0.0f);
			glVertex3f(2.0f, 0.1275f, 0.75f);
			glVertex3f(-2.0f, 0.1275f, 0.75f);
		glEnd();
	glPopMatrix();
}

void drawRoad(float RoadLength) {
	int x;
    glPushMatrix();
    	glColor3f(0.545f, 0.271f, 0.075f); // Dirt
		glTranslatef(0.0f, 0.115f, 0.0f);
		glBegin(GL_QUADS);
				glVertex3f(-50.0f, 0.0f, 0.0f);
				glVertex3f(50.0f, 0.0f, 0.0f);
				glVertex3f(50.0f, 0.0f, -RoadLength);
				glVertex3f(-50.0f, 0.0f, -RoadLength);
		glEnd();
	glPopMatrix();
	glPushMatrix();
		glColor3f(0.3f, 0.3f, 0.3f); // Warna hitam untuk jalan
		glTranslatef(0.0f, 0.125f, 0.0f);
		glBegin(GL_QUADS);
				glVertex3f(-4.5f, 0.0f, 0.0f);
				glVertex3f(4.5f, 0.0f, 0.0f);
				glVertex3f(4.5f, 0.0f, -RoadLength);
				glVertex3f(-4.5f, 0.0f, -RoadLength);
		glEnd();
    glPopMatrix();
    
    // Garis putih kanan kiri
    glPushMatrix();
    	// Kanan
    	glPushMatrix();
    		glColor3f(1, 1, 1);
    		glRotatef(-180, 0, 0, 1);
    		glTranslatef(4.5f, -0.135f, 5.0f);
    		glBegin(GL_QUADS);
				glVertex3f(-0.5f, 0.0f, 0.0f);
				glVertex3f(0.5f, 0.0f, 0.0f);
				glVertex3f(0.5f, 0.0f, -RoadLength);
				glVertex3f(-0.5f, 0.0f, -RoadLength);
			glEnd();
    	glPopMatrix();
    	// Kiri
    	glPushMatrix();
    		glColor3f(1, 1, 1);
	    	glRotatef(-180, 0, 0, 1);
    		glTranslatef(-4.5f, -0.135f, 5.0f);
			glBegin(GL_QUADS);
				glVertex3f(-0.5f, 0.0f, 0.0f);
				glVertex3f(0.5f, 0.0f, 0.0f);
				glVertex3f(0.5f, 0.0f, -RoadLength);
				glVertex3f(-0.5f, 0.00f, -RoadLength);
			glEnd();	
    	glPopMatrix();
    glPopMatrix();
    for(x=0;x<(int)RoadLength;x+=10){
    	drawRoadStrip(x);
    }
}
