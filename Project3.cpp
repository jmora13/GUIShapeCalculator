#include<iostream>
#include <math.h>   

using namespace std;


const float PI = 3.141592654f;
double area, circumference, volume, surfaceArea;
double length,width,height, radius;

	double square(double l){
		area = l*l;
		return area;
	}
	
	double rectangle(double l,double h){
		area = l*h;
		return area;
	}

	double triangle(double l, double h){
		area = (l*h)/2.0;
		return area;
	}
	
	double circle(double r){
		area = PI*r*r;
		circumference = 2*PI*r;
		return area;
	}
	

	double rectangularPrism(double l, double w, double h){
		volume = l*w*h;
		surfaceArea= (2*l*w) + (2*h*w) + (2*l*h);
		return volume;
	}

	double squarePyramid(double l, double w, double h){
		volume = (l*w*h)/3;
		surfaceArea = l*l +((l*4)*(sqrt((h*h)+(l*l/4))/2));
		return volume;
 	}

	double cylinder(double h, double r){
		volume = PI*r*r*h;
		surfaceArea = (2*PI*r*r) + (2*PI*r*h);
		return volume;
	}

	double cone(double r, double h){
		volume = (PI*r*r*h)/3;
		surfaceArea = PI*r*r + (2*PI*r*(sqrt((h*h)+(r*r))/2));
		return volume;
	}

	double sphere(double r){
		volume = (4*PI*r*r*r)/3;
		surfaceArea = 4*PI*r*r;
		return volume;
	}


	int main () {
		char ESC = 27;
		cin >> length >> width >> height >> radius;
		double shapeArea[4] = {square(length),rectangle(length,width),triangle		(length,width),circle(radius) };
		string shapes[4] = { "Square", "Rectangle", "Triangle", "Circle"};
		for(int i = 3; i > 0; i--){
			for(int j = 1; j <= i; j++)
				if(shapeArea[j] > shapeArea[j-1]){
					double temp = shapeArea[j];
					string temp2 = shapes[j];
					shapeArea[j] = shapeArea[j-1];
					shapes[j] = shapes[j-1];
					shapeArea[j-1] = temp;
					shapes[j-1] = temp2;
			}
		}

		double shapeVolume[5] = {rectangularPrism(length,width,height), squarePyramid(length,width,height), cylinder(height,radius), cone(radius,height),sphere(radius)};
		string figures[5] = { "Rectangular Prism", "Square Pyramid", "Cylinder", "Cone", "Sphere"};	int counter = 0;
		for(int x = 4; x > 0; x--){
			for (int y = 1; y <= x; y++){
				if(shapeVolume[y] > shapeVolume[y-1]){
					double temp = shapeVolume[y];
					string temp2 = figures[y];
					shapeVolume[y] = shapeVolume[y-1];
					figures[y] = figures[y-1];
					shapeVolume[y-1] = temp;
					figures[y-1] = temp2;
				}
			}
		}
		cout << ESC << "[2J" << flush;
		cout << ESC << "[5;27f" << "--------Max Shape Area--------" << endl;
		cout << ESC << "[6;20f" << "SHAPE"<< ESC << "[6;40f" << "AREA" << ESC << "[6;60f" << "RATIO" <<  endl;
		cout << ESC << "[8;20f"<< shapes[0] << ESC << "[8;40f"<< shapeArea[0] << ESC << "[8;60f" << shapeArea[0]/shapeArea[0] << endl;
		cout << ESC << "[9;20f"<< shapes[1] << ESC << "[9;40f"<< shapeArea[1] << ESC << "[9;60f" << shapeArea[1]/shapeArea[0] << endl;
		cout << ESC << "[10;20f"<< shapes[2] << ESC << "[10;40f"<< shapeArea[2] << ESC << "[10;60f" << shapeArea[2]/shapeArea[0] << endl;
		cout << ESC << "[11;20f"<< shapes[3] << ESC << "[11;40f"<< shapeArea[3] << ESC << "[11;60f" << shapeArea[3]/shapeArea[0] << endl;

		cout << ESC << "[13;27f" << "--------Max Figure Volume--------" << endl;
		cout << ESC << "[14;20f" << "FIGURE" << ESC << "[14;40f" << "VOLUME "  << ESC << "[14;60f" << "RATIO" << endl;
		cout << ESC << "[16;20f" << figures[0] << ESC << "[16;40f" << shapeVolume[0] << ESC << "[16;60f" << shapeVolume[0] / shapeVolume[0] << endl;
		cout << ESC << "[17;20f" << figures[1] << ESC << "[17;40f" << shapeVolume[1] << ESC << "[17;60f" << shapeVolume[1] / shapeVolume[0] << endl;
		cout << ESC << "[18;20f" << figures[2] << ESC << "[18;40f" << shapeVolume[2] << ESC << "[18;60f" << shapeVolume[2] / shapeVolume[0] << endl;
		cout << ESC << "[19;20f" << figures[3] << ESC << "[19;40f" << shapeVolume[3] << ESC << "[19;60f" << shapeVolume[3] / shapeVolume[0] << endl;
		cout << ESC << "[20;20f" << figures[4] << ESC << "[20;40f" << shapeVolume[4] << ESC << "[20;60f" << shapeVolume[4] / shapeVolume[0] << endl;
		cout << ESC << "[0;0f";
  	return 0;
	}
	
	
