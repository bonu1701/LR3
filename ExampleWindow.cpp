#include "ExampleWindow.h"
#include <stdexcept>
#include <iostream>

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>

ExampleWindow::ExampleWindow(int width, int height)
:Window(width, height) {

	_tree = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "tree.png"),
			SDL_DestroyTexture
	);

	_cat = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "cat.png"),
			SDL_DestroyTexture
	);

	_tyan = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "tyan.png_large"),
			SDL_DestroyTexture
	);

	_skelet = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "skelet.png"),
			SDL_DestroyTexture
	);

	_star = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "star.gif"),
			SDL_DestroyTexture
	);
}

void ExampleWindow::render() {
	SDL_SetRenderDrawColor(_renderer.get(), 17, 41, 90, 255);
	SDL_RenderClear(_renderer.get());

	SDL_Rect star1 {0, 0, 800, 427};
	SDL_RenderCopy(_renderer.get(), _star.get(), nullptr, &star1);

	SDL_Rect star2 {800, 0, 800, 427};
	SDL_RenderCopy(_renderer.get(), _star.get(), nullptr, &star2);

	SDL_Rect star3 {-100, 120, 800, 427};
	SDL_RenderCopy(_renderer.get(), _star.get(), nullptr, &star3);

	SDL_Rect star4 {700, 120, 800, 427};
	SDL_RenderCopy(_renderer.get(), _star.get(), nullptr, &star4);

	SDL_Rect star5 {0, 250, 800, 427};
	SDL_RenderCopy(_renderer.get(), _star.get(), nullptr, &star5);

	SDL_Rect star6 {800, 250, 800, 427};
	SDL_RenderCopy(_renderer.get(), _star.get(), nullptr, &star6);

	//Земля
	SDL_SetRenderDrawColor(_renderer.get(), 0, 55, 0, 255);
	SDL_Rect ground {0, 500, 1280, 300};
	SDL_RenderFillRect(_renderer.get(), &ground);

	//Забор (Крепежи)
	for(int y = 370; y < 490; y += 110){
		SDL_SetRenderDrawColor(_renderer.get(), 0, 0, 0, 255);
		SDL_Rect fenceOne {800, y, 1290, 10};
		SDL_RenderFillRect(_renderer.get(), &fenceOne);
		SDL_SetRenderDrawColor(_renderer.get(), 170, 110, 10, 255);
		SDL_Rect fenceTwo {800, y+1, 1288, 8};
		SDL_RenderFillRect(_renderer.get(), &fenceTwo);
	}

	//Забор (Столбы)
	for (int x = 800; x <= 1280; x += 40){
		SDL_SetRenderDrawColor(_renderer.get(), 0, 0, 0, 255);
		SDL_Rect fenceOne {x, 330, 30, 200};
		SDL_RenderFillRect(_renderer.get(), &fenceOne);
		SDL_SetRenderDrawColor(_renderer.get(), 170, 110, 10, 255);
		SDL_Rect fenceTwo {x+1, 331, 28, 198};
		SDL_RenderFillRect(_renderer.get(), &fenceTwo);
	}

	SDL_Rect tree1 {450, 210, 236, 300};
	SDL_RenderCopy(_renderer.get(), _tree.get(), nullptr, &tree1);

	SDL_Rect tree2 {-20, 210, 236, 300};
	SDL_RenderCopy(_renderer.get(), _tree.get(), nullptr, &tree2);

	SDL_Rect cat {x_cat, 0, 300, 222};
	SDL_RenderCopy(_renderer.get(), _cat.get(), nullptr, &cat);

	//Дом
	SDL_SetRenderDrawColor(_renderer.get(), 0, 0, 0, 255);
	SDL_Rect homeBoxBorder {640, 290, 350, 260};
	SDL_RenderFillRect(_renderer.get(), &homeBoxBorder);
	SDL_SetRenderDrawColor(_renderer.get(), 150, 150, 150, 255);
	SDL_Rect homeBox {641, 291, 348, 258};
	SDL_RenderFillRect(_renderer.get(), &homeBox);

	double y = 290;
	SDL_SetRenderDrawColor(_renderer.get(), 0, 30, 0, 255);
	for(int x = 610; x <= 815; x++){
		SDL_RenderDrawLine(_renderer.get(), x, y, x, 290);
		y -= 0.8;
	}
	for(int x = 815; x <= 1020; x++){
		SDL_RenderDrawLine(_renderer.get(), x, y, x, 290);
		y += 0.8;
	}

	SDL_SetRenderDrawColor(_renderer.get(), 0, 0, 0, 255);
	SDL_Rect doorBorderTwo {850, 360, 90, 190};
	SDL_RenderFillRect(_renderer.get(), &doorBorderTwo);
	SDL_SetRenderDrawColor(_renderer.get(), 160, 82, 45, 255);
	SDL_Rect doorBorder {851, 361, 88, 188};
	SDL_RenderFillRect(_renderer.get(), &doorBorder);

	//Окно (Окантовка)
	SDL_SetRenderDrawColor(_renderer.get(), 0, 0, 0, 255);
	SDL_Rect windowBorder {690, 350, 130, 120};
	SDL_RenderFillRect(_renderer.get(), &windowBorder);
	SDL_SetRenderDrawColor(_renderer.get(), 160, 82, 45, 255);
	SDL_Rect windowHome {691, 351, 128, 118};
	SDL_RenderFillRect(_renderer.get(), &windowHome);
	//Окно (Стекло)
	y = 360;
	for(int x = 700; x <= 760; x += 60){
		SDL_SetRenderDrawColor(_renderer.get(), 0, 0, 0, 255);
		SDL_Rect windowBorder {x, y, 50, 100}; // @suppress("Invalid arguments")
		SDL_RenderFillRect(_renderer.get(), &windowBorder);
		SDL_SetRenderDrawColor(_renderer.get(), 135, 206, 235, 255);
		SDL_Rect windowHome {x+1, y+1, 48, 98}; // @suppress("Invalid arguments")
		SDL_RenderFillRect(_renderer.get(), &windowHome);
	}

	SDL_Rect tyan {x_tyan, y_tyan, 181, 250};
	SDL_RenderCopy(_renderer.get(), _tyan.get(), nullptr, &tyan);

	SDL_Rect skelet {800, 570, 400, 124};
	SDL_RenderCopy(_renderer.get(), _skelet.get(), nullptr, &skelet);

}

void ExampleWindow::do_logic() {
	x_cat -= 3;
	if (x_cat <= -350) x_cat = 1350;

}

void ExampleWindow::handle_keys(const Uint8 *keys) {
	if (keys[SDL_SCANCODE_LEFT] && x_tyan >= -50){
		x_tyan -= 3;
	}

	if (keys[SDL_SCANCODE_RIGHT] && x_tyan <= 1140){
		x_tyan += 3;
	}

	if (keys[SDL_SCANCODE_DOWN] && y_tyan <= 470){
		y_tyan += 3;
	}

	if (keys[SDL_SCANCODE_UP] && y_tyan >= 350){
		y_tyan -= 3;
	}
}

void ExampleWindow::handle_event(const SDL_Event &event) {

}
