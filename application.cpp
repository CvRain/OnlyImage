#include <iostream>
#include <string>
#include "OnlyImage.h"

int main(const int argc, char** argv) {
	std::unique_ptr<OnlyImage::OnlyImage> image;
	if (argc >= 3) {
		image = std::make_unique<OnlyImage::OnlyImage>(std::string(argv[1]), std::string(argv[2]));
	}else {
		std::string temp_path{};
		image = std::make_unique<OnlyImage::OnlyImage>();

		std::cout << "Input first image path: " << std::endl;
		std::cin >> temp_path;
		image->SetFirstImage(temp_path);
		
		std::cout << "Iutput second image path: " << std::endl;;
		std::cin >> temp_path;
		image->SetSecondImage(temp_path);
		
	}
	
	std::cout << "| 0 same " << std::endl;
	std::cout << "| ~ 0.1 similar " << std::endl;
	std::cout << "| 0.2 - 0.3 really similar " << std::endl;
	std::cout << "| 0.3 - 0.5 approximately similar " << std::endl;
	std::cout << "| 0.5 - 0.8 quite different " << std::endl;
	std::cout << "| > 0.8 much different " << std::endl;

	std::cout << "Distance between images: " << std::fixed << image->SimpleCalc() << std::endl;

	return EXIT_SUCCESS;
}
