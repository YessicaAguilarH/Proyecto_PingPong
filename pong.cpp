#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
// global variables
static GLint windowSizeX = 800, windowSizeY = 1200;
static GLint orthoSizeX = 600, orthoSizeY = 400;

// game variables
static char score_1[20], score_2[20];
static GLint player1_score = 0, player2_score = 0;
static GLint player1_life = 3, player2_life = 3;
static GLint paddle_boundary = 350, paddle_height = 100, paddile_velocity = 8.0;
static GLint player1_paddile_y = 0, player2_paddile_y = 0, paddle_x = 595;
static GLfloat ball_velocity_x = 0, ball_velocity_y = 0, speed_increment = 0.05;
static GLint ball_pos_x = 0, ball_pos_y = 0, ball_radius = 20;

void init(void) {
	// initalise display with black colors
	glClearColor (0.2, 0.2, 0.3, 0.3);
	glShadeModel (GL_FLAT);
	
	srand(time(NULL));   // should only be called once
}

// draw text on screen
void drawStrokeText(char*string, int x, int y, int z)
{
	char *c;
	glPushMatrix();
	glTranslatef(x, y+8,z);
	// glScalef(0.09f,-0.08f,z);
	for (c=string; *c != '\0'; c++)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
	}
	glPopMatrix();
}

// draw the center lines spaces 20 pixels apart and with a width of 4 px
void drawCenterLines() {
	// center lines start
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(-2 , -410);
	glVertex2f(2 , -410);
	glVertex2f(2 , -390);
	glVertex2f(-2 , -390);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(-2 , -370);
	glVertex2f(2 , -370);
	glVertex2f(2 , -350);
	glVertex2f(-2 , -350);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(-2 , -330);
	glVertex2f(2 , -330);
	glVertex2f(2 , -310);
	glVertex2f(-2 , -310);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(-2 , -290);
	glVertex2f(2 , -290);
	glVertex2f(2 , -270);
	glVertex2f(-2 , -270);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(-2 , -250);
	glVertex2f(2 , -250);
	glVertex2f(2 , -230);
	glVertex2f(-2 , -230);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(-2 , -210);
	glVertex2f(2 , -210);
	glVertex2f(2 , -190);
	glVertex2f(-2 , -190);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(-2 , -170);
	glVertex2f(2 , -170);
	glVertex2f(2 , -150);
	glVertex2f(-2 , -150);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(-2 , -130);
	glVertex2f(2 , -130);
	glVertex2f(2 , -110);
	glVertex2f(-2 , -110);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(-2 , -90);
	glVertex2f(2 , -90);
	glVertex2f(2 , -70);
	glVertex2f(-2 , -70);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(-2 , -50);
	glVertex2f(2 , -50);
	glVertex2f(2 , -30);
	glVertex2f(-2 , -30);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(-2 , -10);
	glVertex2f(2 , -10);
	glVertex2f(2 , 10);
	glVertex2f(-2 , 10);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(-2 , 30);
	glVertex2f(2 , 30);
	glVertex2f(2 , 50);
	glVertex2f(-2 , 50);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(-2 , 70);
	glVertex2f(2 , 70);
	glVertex2f(2 , 90);
	glVertex2f(-2 , 90);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(-2 , 110);
	glVertex2f(2 , 110);
	glVertex2f(2 , 130);
	glVertex2f(-2 , 130);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(-2 , 150);
	glVertex2f(2 , 150);
	glVertex2f(2 , 170);
	glVertex2f(-2 , 170);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(-2 , 190);
	glVertex2f(2 , 190);
	glVertex2f(2 , 210);
	glVertex2f(-2 , 210);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(-2 , 230);
	glVertex2f(2 , 230);
	glVertex2f(2 , 250);
	glVertex2f(-2 , 250);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(-2 , 270);
	glVertex2f(2 , 270);
	glVertex2f(2 , 290);
	glVertex2f(-2 , 290);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(-2 , 310);
	glVertex2f(2 , 310);
	glVertex2f(2 , 330);
	glVertex2f(-2 , 330);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(-2 , 350);
	glVertex2f(2 , 350);
	glVertex2f(2 , 370);
	glVertex2f(-2 , 370);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(-2 , 390);
	glVertex2f(2 , 390);
	glVertex2f(2 , 410);
	glVertex2f(-2 , 410);
	glEnd();
	// center lines end
}

// x, y is the top left corodinate of the paddle
void drawPaddle(int x, int y) {
	glPushMatrix();
	
	glTranslatef(x, y, 0);
	
	glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
	int height = paddle_height / 2;
	glVertex2f(-5 , height);
	glVertex2f(5 , height);
	glVertex2f(5 , -height);
	glVertex2f(-5, -height);
	glEnd();
	
	glPopMatrix();
}

void drawBall(int x, int y) {
	glPushMatrix();
	
	glTranslatef(x, y, 0);
	glColor3f(1.0, 1.0, 1.0);
	glutSolidSphere (ball_radius, 20, 16);
	
	glPopMatrix();
}

// main display functions
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	
	// create center lines
	drawCenterLines();
	
	
	drawPaddle(-paddle_x, player1_paddile_y); 	// draw left paddle at (-paddle_x, player1_paddile_y)
	
	drawPaddle(paddle_x, player2_paddile_y);	// draw right paddle at (paddle_x, player2_paddile_y)
	
	
	drawBall(ball_pos_x, ball_pos_y);	// draw the ball (ball_pos_x, ball_pos_y) - varies in each frame
	
	snprintf (score_1, sizeof(score_1), "%d", player1_score);	// draw the score on the left for player 1
	drawStrokeText(score_1, -300, 200, 0);
	
	snprintf (score_2, sizeof(score_2), "%d", player2_score);// draw the score on the left for player 1
	drawStrokeText(score_2, 200, 200, 0);
	
	glutSwapBuffers();// swap the current frame with the drawn frame
	glFlush();
}

void startGame(void) {
	
	// move the ball
	ball_pos_x += ball_velocity_x;
	ball_pos_y += ball_velocity_y;
	
	// ball hits the top or bottom
	if (ball_pos_y + ball_radius > orthoSizeY || ball_pos_y - ball_radius < -orthoSizeY)
		ball_velocity_y = -ball_velocity_y;
	
	// ball hits the left paddle
	if (ball_pos_x - ball_radius - 5 < -paddle_x && ball_pos_x - ball_radius < -paddle_x)
		if (ball_pos_y < player1_paddile_y + paddle_height && ball_pos_y > player1_paddile_y - paddle_height) {
			ball_velocity_x = -ball_velocity_x;
			ball_velocity_x += speed_increment;
			paddile_velocity += speed_increment;
	}
		
		
		// ball hits the right paddle
		if (ball_pos_x + ball_radius + 5 > paddle_x && ball_pos_x + ball_radius < paddle_x)
			if (ball_pos_y < player2_paddile_y + paddle_height && ball_pos_y > player2_paddile_y - paddle_height)
				ball_velocity_x = -ball_velocity_x;
		
		// player 1 scores
		if (ball_pos_x + ball_radius > orthoSizeX) {
			player1_score++;
			printf("Player 1 = %d \n", player1_score);
			ball_velocity_x = -ball_velocity_x;
		}
		
		// player 2 scores
		if (ball_pos_x - ball_radius < -orthoSizeX) {
			player2_score++;
			printf("Player 2 = %d \n", player2_score);
			ball_velocity_x = -ball_velocity_x;
		}
		
		
		if (player2_score > 20 || player1_score > 20) {
			printf("Perdiste pe chamo");
			glutDestroyWindow(1);
		}
		
		glutPostRedisplay();
}


/*
* Request double buffer display mode.
* Register mouse input callback functions
*/
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (1200, 800);
	glutInitWindowPosition (10, 10);
	glutCreateWindow (argv[0]);
	init ();
	
	// call back functions for rendering, reshape
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	
	// callback on mouse click and keyboard input
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
