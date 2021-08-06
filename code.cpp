#include&lt;iostream&gt;
#include&lt;math.h&gt;
#include&lt;GL/glut.h&gt;
using namespace std;
static GLfloat input[4][3] =
{
{0,60,20},{60,60,40},{60,0,0},{0,0,0}
};
float output[4][3];
float tx, ty, tz;
void translate(int tx, int ty, int tz)
{
for (int i = 0; i &lt; 4; i++)
{
output[i][0] = input[i][0] + tx;
output[i][1] = input[i][1] + ty;
output[i][2] = input[i][2] + tz;
}

Computer Graphics and Visualization

Dept of CSE, AIET Mijar 16
}
void Axes(void)
{
glColor3f(0.0, 0.0, 0.0); // Set the color to BLACK
glBegin(GL_LINES); // Plotting X-Axis
glVertex2s(-1000, 0);
glVertex2s(1000, 0);
glEnd();
glBegin(GL_LINES); // Plotting Y-Axis
glVertex2s(0, -1000);
glVertex2s(0, 1000);
glEnd();
}
void draw(float a[4][3])
{
glBegin(GL_TRIANGLES);
glColor3f(0.7, 0.4, 0.5); //front
glVertex3fv(a[0]);
glVertex3fv(a[2]);
glVertex3fv(a[3]);
glColor3f(0.3, 0.6, 0.7); //left
glVertex3fv(a[0]);
glVertex3fv(a[1]);
glVertex3fv(a[3]);
glColor3f(0.2, 0.8, 0.2); //right
glVertex3fv(a[0]);
glVertex3fv(a[1]);
glVertex3fv(a[2]);
glColor3f(0.7, 0.7, 0.2); //bottom
glVertex3fv(a[1]);
glVertex3fv(a[2]);
glVertex3fv(a[3]);
glEnd();
}

Computer Graphics and Visualization

Dept of CSE, AIET Mijar 17
void init()
{
glClearColor(1.0, 1.0, 1.0, 1.0);
glOrtho(-454.0, 454.0, -250.0, 250.0, -250.0, 250.0);
glEnable(GL_DEPTH_TEST);
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
Axes();
draw(input);
translate(tx, ty, tz);
draw(output);
glFlush();
}
int main(int argc, char** argv)
{
glutInit(&amp;argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize(1362, 750);
glutInitWindowPosition(0, 0);
glutCreateWindow(&quot;3D TRANSLATION&quot;);
init();
cout &lt;&lt; &quot;\nEnter Tx,Ty &amp;Tz values to translate: \n&quot;;
cin &gt;&gt; tx &gt;&gt; ty &gt;&gt; tz;
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
