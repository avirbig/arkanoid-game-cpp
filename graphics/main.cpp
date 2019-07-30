#include <iostream>
#include <string>

#include "window.h"
#include "conversions.h"
#include "shapeContainer.h"
#include "fileInput.h"

int main() {
	
	MyWindow window;
	sf::Vector2f windowDimensions = Conversions::V2uToV2f(window.getSize());
	
	ShapeContainer container(windowDimensions, FileInput().read("sources/level1.lvl"));
	window.play(container);
	
	return 0;
}

