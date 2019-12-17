#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <ctime>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
int i = 0;
class star {
private:
	double xPos;
	double yPos;
	int size;
	int r;
	int g;
	int b;
	double yVel;
	double xVel;
public:
	star();
	void draw();
	void move();
	void reposition();
};


int main() {
	vector<star*> starfield;
	vector<star*>::iterator iter3;
	for (int i = 0; i <= 1000; i++) {
		star* newStar = new star();
		starfield.push_back(newStar);
	}

	al_init();
	al_init_primitives_addon();
	srand(time(NULL));

	ALLEGRO_DISPLAY* stars = al_create_display(1000, 1000);
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();
	while (1) {
		al_clear_to_color(al_map_rgb(0, 100, 200));

		for (iter3 = starfield.begin(); iter3 != starfield.end(); iter3++) {
			(*iter3)->move();
			(*iter3)->reposition();
		}
		for (iter3 = starfield.begin(); iter3 != starfield.end(); iter3++) {
			(*iter3)->draw();
		}

		al_flip_display();
	}
	al_rest(10);
	al_destroy_display(stars);
}

star::star() {
	xPos = rand() % 1000;
	yPos = (rand() % 2000 - 1000);
	r = 255;
	g = 255;
	b = 255;
	size = rand() % 5;
	yVel = 0;
	xVel = 0;
}

void star::draw() {
	al_draw_filled_circle(xPos, yPos, size, al_map_rgb(r, g, b));

}

void star::reposition() {
	if (yPos >= 1000) {
		yVel *= -2;
	}
	if (xPos >= 1000) {
		xVel *= -2;
	}
}

void star::move() {
	yVel += .05;
	xVel += .05;
	if (yVel > 10) {
		yVel = 5;
	}
	if (xVel > 10)
		xVel = 5;

	xPos += xVel;
	yPos += yVel;
}

