#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include "car.h"
#include "road.h"
#include "pohon.h"

// Variabel global untuk mengatur posisi kamera
float camX = -2.25f, camY = 0.5f, camZ = 0.0f;
float camAngle = 0.0f;

// Variabel untuk posisi mobil
float carPosX = -2.25f, carPosY = 0.25f, carPosZ = -10.0f, carAcc = 0.025f, carSpeed = 0.0f;
float wheelAngle = 0.0f;
bool crash = false;

// Variabel untuk posisi NPC mobil biru
float carPosX2 = 2.3f, carPosY2 = 0.25f, carPosZ2 = -500.0f, carAcc2 = 0.025f, carSpeed2 = 0.025f;
float wheelAngle2 = 0.0f;
bool crash2 = false;

// Variabel untuk posisi NPC mobil merah
float carPosX3 = 2.3f, carPosY3 = 0.25f, carPosZ3 = -650.0f, carAcc3 = 0.025f, carSpeed3 = 0.025f;
float wheelAngle3 = 0.0f;
bool crash3 = false;

// Variabel untuk posisi NPC mobil kuning
float carPosX4 = 2.3f, carPosY4 = 0.25f, carPosZ4 = -1050.0f, carAcc4 = 0.025f, carSpeed4 = 0.025f;
float wheelAngle4 = 0.0f;
bool crash4 = false;

// Variabel untuk posisi NPC mobil hijau
float carPosX5 = 2.3f, carPosY5 = 0.25f, carPosZ5 = -850.0f, carAcc5 = 0.025f, carSpeed5 = 0.025f;
float wheelAngle5 = 0.0f;
bool crash5 = false;

// Panjang Jalan
int RoadLength = 2000;

// Lighting
const GLfloat light_ambient[] = {0.5f,0.5f,0.5f,0.0f};
const GLfloat light_diffuse[] = {1.0f,1.0f,1.0f,1.0f};
const GLfloat light_specular[] = {1.0f,1.0f,1.0f,1.0f};
const GLfloat light_position[] = {50.0f,25.0f,20.0f,1.0f};
const GLfloat mat_ambient[] = {0.7f,0.7f,0.7f,1.0f};
const GLfloat mat_diffuse[] = {0.8f,0.8f,0.8f,1.0f};
const GLfloat mat_specular[] = {1.0f,1.0f,1.0f,1.0f};
const GLfloat high_shininess[] = {100.0f};

// Fungsi untuk mendeteksi tabrakan
bool checkCollision(float car1X, float car1Y, float car1Z, float car2X, float car2Y, float car2Z) {
    float distance = sqrt(pow(car1X - car2X, 2) + pow(car1Y - car2Y, 2) + pow(car1Z - car2Z, 2));
    return distance < 1.0f; // Menggunakan jarak untuk deteksi tabrakan
}

void update(int value) {
	// Player Car
	if(!crash){
		if(carPosZ<-9.5f){
			carPosZ += carSpeed;
		}
		else{
			carPosZ = -10.0f;
			carSpeed = -1*carSpeed;
		}
	}
	
	// Gerak Roda
    if (carSpeed > 0) {
        if(carSpeed != 0){
        	wheelAngle += carSpeed;
        }
    }
    else{
		if(carSpeed != 0){
			wheelAngle -= carSpeed;
		}
    }
	camZ = carPosZ;
	
	// Main Car
	    // Reset posisi mobil jika sudah keluar dari jalur
	    if (carPosZ < -1750.0f) {
	        carPosZ = -10.0f;
	        carPosX = -2.25f;
	        carSpeed = carAcc; // Mengembalikan kecepatan mobil jika sudah reset
	    }
	
	    // Cek tabrakan
	    if (checkCollision(carPosX, carPosY, carPosZ, carPosX2, carPosY2, carPosZ2)){
	        carSpeed = 0.05f; // Berhentikan mobil jika terjadi tabrakan
	        carPosZ += 0.75f;
	        carPosZ2 -= 0.75f;
	        carSpeed2 = 0.05f;
			crash = true;
			crash2 = true; 
		}
		else if (checkCollision(carPosX, carPosY, carPosZ, carPosX3, carPosY3, carPosZ3)){
			carSpeed = 0.05f; // Berhentikan mobil jika terjadi tabrakan
	        carPosZ += 0.75f;
	        carPosZ3 -= 0.75f;
	        carSpeed3 -= 0.05f;
	        crash = true; 
	        crash3 = true;
		}
		else if (checkCollision(carPosX, carPosY, carPosZ, carPosX4, carPosY4, carPosZ4)){
			carSpeed = 0.05f; // Berhentikan mobil jika terjadi tabrakan
	        carPosZ += 0.75f;
	        carPosZ4 -= 0.75f;
	        carSpeed4 -= 0.05f;
	        crash = true; 
	        crash4 = true;
		} 
		else if (checkCollision(carPosX, carPosY, carPosZ, carPosX5, carPosY5, carPosZ5)){
			carSpeed = 0.05f; // Berhentikan mobil jika terjadi tabrakan
	        carPosZ += 0.75f;
	        carPosZ5 -= 0.75f;
	        carSpeed5 -= 0.05f;
	        crash = true; 
	        crash5 = true;
		}
		else{
			crash = false;
		}
	
	
	// NPC Car Biru
		if (!crash2){
			carPosZ2 += carSpeed2; // Menggerakkan mobil figuran ke arah berlawanan
			if((int)carPosZ2%20==0){
				carSpeed2 += carAcc2;
			}
		}
		else{
			if(abs(carPosX2-carPosX)>0.75f){
				crash2 = false;
				carSpeed2 = carAcc2*3;
			}	
		}
		
		// Gerak Roda
		if (carSpeed2 > 0) {
        	if(carSpeed2 != 0){
        		wheelAngle2 -= carSpeed2;
        	}
    	}
    	else{
			if(carSpeed2 != 0){
				wheelAngle2 += carSpeed2;
			}
    	}
		
	    // Reset posisi mobil figuran jika sudah keluar dari jalur
	    if (carPosZ2 > -50.0f) {
	        carPosZ2 = -500.0f;
	        carSpeed2 = carAcc2; // Mengembalikan kecepatan mobil figuran jika sudah reset
	    }
	
	    // Cek tabrakan
		if (checkCollision(carPosX2, carPosY2, carPosZ2, carPosX3, carPosY3, carPosZ3)){
			carSpeed2 = 0.05f; // Berhentikan mobil jika terjadi tabrakan
	        carPosZ2 += 0.75f;
	        carPosZ3 -= 0.75f;
	        carSpeed3 -= 0.05f;
	        crash2 = true; 
	        crash3 = true;
		}
		else if (checkCollision(carPosX2, carPosY2, carPosZ2, carPosX4, carPosY4, carPosZ4)){
			carSpeed2 = 0.05f; // Berhentikan mobil jika terjadi tabrakan
	        carPosZ2 += 0.75f;
	        carPosZ4 -= 0.75f;
	        carSpeed4 -= 0.05f;
	        crash2 = true; 
	        crash4 = true;
		} 
		else if (checkCollision(carPosX2, carPosY2, carPosZ2, carPosX5, carPosY5, carPosZ5)){
			carSpeed2 = 0.05f; // Berhentikan mobil jika terjadi tabrakan
	        carPosZ2 += 0.75f;
	        carPosZ5 -= 0.75f;
	        carSpeed5 -= 0.05f;
	        crash2 = true; 
	        crash5 = true;
		}
	
	// NPC Car Merah
		if (!crash3){
			carPosZ3 += carSpeed3; // Menggerakkan mobil figuran ke arah berlawanan
			if((int)carPosZ3%25==0){
				carSpeed3 += carAcc3;
			}
		}
		else{
			if(abs(carPosX3-carPosX)>0.75f){
				crash3 = false;
				carSpeed3 = carAcc3*3;
			}	
		}
		
		// Gerak Roda
		if (carSpeed3 > 0){
       		if(carSpeed3 != 0){
        		wheelAngle3 -= carSpeed3;
        	}
    	}
    	else{
			if(carSpeed3 != 0){
				wheelAngle3 += carSpeed3;
			}
    	}
		
	    // Reset posisi mobil figuran jika sudah keluar dari jalur
	    if (carPosZ3 > -50.0f) {
	        carPosZ3 = -650.0f;
	        carSpeed3 = carAcc3; // Mengembalikan kecepatan mobil figuran jika sudah reset
	    }
	
	    // Cek tabrakan
		if (checkCollision(carPosX3, carPosY3, carPosZ3, carPosX4, carPosY4, carPosZ4)){
			carSpeed3 = 0.05f; // Berhentikan mobil jika terjadi tabrakan
	        carPosZ3 += 0.75f;
	        carPosZ4 -= 0.75f;
	        carSpeed4 -= 0.05f;
	        crash3 = true; 
	        crash4 = true;
		} 
		else if (checkCollision(carPosX3, carPosY3, carPosZ3, carPosX5, carPosY5, carPosZ5)){
			carSpeed3 = 0.05f; // Berhentikan mobil jika terjadi tabrakan
	        carPosZ3 += 0.75f;
	        carPosZ5 -= 0.75f;
	        carSpeed5 -= 0.05f;
	        crash3 = true; 
	        crash5 = true;
		}
    
    // NPC Car Kuning
		if (!crash4){
			carPosZ4 += carSpeed4; // Menggerakkan mobil figuran ke arah berlawanan
			if((int)carPosZ4%30==0){
				carSpeed4 += carAcc4;
			}
		}
		else{
			if(abs(carPosX4-carPosX)>0.75f){
				crash4 = false;
				carSpeed4 = carAcc4*3;
			}	
		}
		
		// Gerak Roda
		if (carSpeed4 > 0){
       		if(carSpeed4 != 0){
        		wheelAngle4 -= carSpeed4;
        	}
    	}
    	else{
			if(carSpeed4 != 0){
				wheelAngle4 += carSpeed4;
			}
    	}
		
	    // Reset posisi mobil figuran jika sudah keluar dari jalur
	    if (carPosZ4 > -150.0f) {
	        carPosZ4 = -1050.0f;
	        carSpeed4 = carAcc4; // Mengembalikan kecepatan mobil figuran jika sudah reset
	    }
	
	    // Cek tabrakan
		if (checkCollision(carPosX4, carPosY4, carPosZ4, carPosX5, carPosY5, carPosZ5)){
			carSpeed4 = 0.05f; // Berhentikan mobil jika terjadi tabrakan
	        carPosZ4 += 0.75f;
	        carPosZ5 -= 0.75f;
	        carSpeed5 -= 0.05f;
	        crash4 = true; 
	        crash5 = true;
		}
    
    // NPC Car Hijau
		if (!crash5){
			carPosZ5 += carSpeed5; // Menggerakkan mobil figuran ke arah berlawanan
			if((int)carPosZ5%35==0){
				carSpeed5 += carAcc5;
			}
		}
		else{
			if(abs(carPosX5-carPosX)>0.75f){
				crash5 = false;
				carSpeed5 = carAcc5*3;
			}	
		}
		
		// Gerak Roda
		if (carSpeed5 > 0){
       		if(carSpeed5 != 0){
        		wheelAngle5 -= carSpeed5;
        	}
    	}
    	else{
			if(carSpeed5 != 0){
				wheelAngle5 += carSpeed5;
			}
    	}
		
	    // Reset posisi mobil figuran jika sudah keluar dari jalur
	    if (carPosZ5 > -150.0f) {
	        carPosZ5 = -850.0f;
	        carSpeed5 = carAcc5; // Mengembalikan kecepatan mobil figuran jika sudah reset
	    }		
		else{
			if(abs(carPosX5-carPosX)>0.75f){
				crash5 = false;
				carSpeed5 = carAcc5*3;
			}	
		}
	
    glutPostRedisplay(); // Meminta redisplay untuk menggambar ulang scene
    glutTimerFunc(32, update, 0); // Menyetel timer lagi untuk pemanggilan berikutnya
}


// Fungsi display
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Mengatur kamera
    gluLookAt(camX, camY + 2, camZ + 7,
              carPosX, carPosY, carPosZ,
              0.0f, 1.0f, 0.0f);

    // Mengaktifkan pencahayaan
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat light_position[] = { -150.0f, 50.0f, 20.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    // Menggambar mobil
    glPushMatrix();
        drawCar(carPosX, carPosY, carPosZ, wheelAngle, 1, 0, 0, -90);
		drawCar(carPosX2, carPosY2, carPosZ2, wheelAngle2, 0, 0, 1, 90);
		drawCar(carPosX3, carPosY3, carPosZ3, wheelAngle3, 1, 0, 0, 90);
		drawCar(carPosX4, carPosY4, carPosZ4, wheelAngle4, 1, 1, 0, 90);
		drawCar(carPosX5, carPosY5, carPosZ5, wheelAngle5, 0, 1, 0, 90);
	glPopMatrix();
	
    // Draw trees and their shadows
    float z; 
    drawRoad(RoadLength);
    for (z = -5.0f; z > -RoadLength; z -= 10.0f) {
        // Draw left tree
        drawTree(-4.5f, z);

        // Draw right tree
        drawTree(4.5f, z);
    }

    glEnable(GL_LIGHTING);
    glutSwapBuffers();
}


// Fungsi untuk mengatur ukuran viewport
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)w / (float)h, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

// Fungsi untuk mengatur input dari keyboard
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    	float temp;
        case 27: // ESC key
            exit(0);
            break;
        case 'w':
        	if(carSpeed > -1.5f){
				carSpeed -= carAcc;
        	}
            break;
        case 's':
        	if(carSpeed < 1.5f){
        		carSpeed += carAcc;
        	}
            break;
        case 'a':
        	if (carPosX > -2.5f){
        		carPosX -= 0.2f;
        		camX -= 0.2f;
        	}
            break;
        case 'd':
        	if (carPosX < 2.5f){
        		carPosX += 0.2f;
        		camX += 0.2f;
			}
            break;
        case 'q':
            camX = -10.0f;
            camY = 10.0f;
            break;
        case 'e':
            camX = 10.0f;
            camY = 10.0f;
            break;
        case 'x':
        	camX = carPosX;
        	camY = carPosY;
    }
    glutPostRedisplay();
}

void lighting()
{
    glDepthFunc(GL_LESS);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glMatrixMode(GL_PROJECTION);
    
    glLoadIdentity();
    gluPerspective(60.0f, 1.0, 1.0, 400.0);
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

// Fungsi untuk inisialisasi
void init() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.53f, 0.81f, 0.92f, 1.0f); // Warna latar belakang biru langit
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Car Game");
	
	lighting();
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    
	glutTimerFunc(32, update, 0);

	glutMainLoop();
	
    return 0;
}

