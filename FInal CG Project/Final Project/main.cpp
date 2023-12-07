#include <GL/glut.h>
#include <cmath>

GLfloat angle = 0.0;
GLfloat cameraDistance = 5.0;
GLfloat cameraAngleX = 45.0;
GLfloat cameraAngleY = 45.0;
GLfloat wireframeColor[3] = {0.0, 0.0, 0.0}; // Initial color is black

void drawWireframeModel() {
    // Vertex Listing (Sample Vertices)
    GLfloat vertices[][3] = {{-1.0, -1.0, -1.0}, {1.0, -1.0, -1.0}, {1.0, 1.0, -1.0}, {-1.0, 1.0, -1.0},
                             {-1.0, -1.0, 1.0}, {1.0, -1.0, 1.0}, {1.0, 1.0, 1.0}, {-1.0, 1.0, 1.0}};

    // Polygon Listing (Sample Polygons)
    GLint polygons[][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {0, 3, 7, 4}, {1, 2, 6, 5}, {0, 1, 5, 4}, {2, 3, 7, 6}};

    glEnable(GL_DEPTH_TEST); // Enable depth testing for Z-buffer

    glColor3fv(wireframeColor); // Set wireframe color

    for (int i = 0; i < 6; ++i) {
        glBegin(GL_LINE_LOOP);
        for (int j = 0; j < 4; ++j) {
            glVertex3fv(vertices[polygons[i][j]]);
        }
        glEnd();
    }

    // Draw Cone on Top of Cube
    glPushMatrix();
    glTranslatef(0.0, 2.5, 0.0); // Translate to the top center of the cube
    glRotatef(90.0, 1.0, 0.0, 0.0); // Rotate the cone by 90 degrees around the x-axis
    glColor3fv(wireframeColor);    // Set color for the cone
    glutWireCone(1.0, 1.5, 20, 20); // Draw the cone
    glPopMatrix();

    glDisable(GL_DEPTH_TEST); // Disable depth testing after rendering
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(cameraDistance * sin(cameraAngleY * M_PI / 180.0) * cos(cameraAngleX * M_PI / 180.0),
              cameraDistance * sin(cameraAngleX * M_PI / 180.0),
              cameraDistance * cos(cameraAngleY * M_PI / 180.0) * cos(cameraAngleX * M_PI / 180.0),
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);

    glRotatef(angle, 0.0, 1.0, 0.0); // Rotate the model

    drawWireframeModel();

    glutSwapBuffers();
}

void update(int value) {
    angle += 1.0;
    if (angle > 360.0) {
        angle -= 360.0;
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            cameraAngleX += 5.0;
            break;
        case GLUT_KEY_DOWN:
            cameraAngleX -= 5.0;
            break;
        case GLUT_KEY_LEFT:
            cameraAngleY -= 5.0;
            break;
        case GLUT_KEY_RIGHT:
            cameraAngleY += 5.0;
            break;
        case GLUT_KEY_HOME:
            cameraDistance -= 0.5;
            break;
        case GLUT_KEY_END:
            cameraDistance += 0.5;
            break;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        angle += 10.0; // Rotate the model on left mouse click
        glutPostRedisplay();
    }
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'r':
            wireframeColor[0] = 1.0;
            wireframeColor[1] = 0.0;
            wireframeColor[2] = 0.0; // Change color to red on keypress 'r'
            break;
        case 'g':
            wireframeColor[0] = 0.0;
            wireframeColor[1] = 1.0;
            wireframeColor[2] = 0.0; // Change color to green on keypress 'g'
            break;
        case 'b':
            wireframeColor[0] = 0.0;
            wireframeColor[1] = 0.0;
            wireframeColor[2] = 1.0; // Change color to blue on keypress 'b'
            break;
        case 'c':
            // Change color of both cube and cone (random color for example)
            wireframeColor[0] = static_cast<GLfloat>(rand()) / RAND_MAX;
            wireframeColor[1] = static_cast<GLfloat>(rand()) / RAND_MAX;
            wireframeColor[2] = static_cast<GLfloat>(rand()) / RAND_MAX;
            break;
    }
    glutPostRedisplay();
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0, 1.0, 1.0, 1.0); // White background
    glMatrixMode(GL_PROJECTION);
    gluPerspective(60.0, 1.0, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Enable depth buffer
    glutCreateWindow("3D Wireframe Model with Z-buffer");
    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);
    glutSpecialFunc(specialKeys);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();
    return 0;
}
