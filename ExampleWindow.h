#ifndef EXAMPLEWINDOW_H_
#define EXAMPLEWINDOW_H_

#include "Window.h"

class ExampleWindow: public Window{
protected:
	std::shared_ptr<SDL_Texture> _tree;
	std::shared_ptr<SDL_Texture> _cat;
	std::shared_ptr<SDL_Texture> _tyan;
	std::shared_ptr<SDL_Texture> _skelet;
	std::shared_ptr<SDL_Texture> _star;

	int x_cat = 1300, y_tyan = 400, x_tyan = 300;
public:
	ExampleWindow(
		int width = DEFAULT_WIDTH,
		int height = DEFAULT_HEIGHT);
	virtual ~ExampleWindow() = default;

	virtual void render() override;
	virtual void do_logic() override;
	virtual void handle_keys(const Uint8 *keys) override;
	virtual void handle_event(const SDL_Event &event) override;
};

#endif /* EXAMPLEWINDOW_H_ */
