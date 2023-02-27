#include "OnlyImage.h"

namespace OnlyImage {
	OnlyImage::OnlyImage(const std::string& firstImagePath, const std::string& secondImagePath) {
		SetImage(firstImagePath, secondImagePath);
	}

	OnlyImage::OnlyImage(const std::pair<std::string, std::string>& imageGroup) {
		SetImage(imageGroup.first, imageGroup.second);
	}

	
	void OnlyImage::SetImage(const std::string& firstImagePath, const std::string& secondImagePath) {
		SetFirstImage(firstImagePath);
		SetFirstImage(secondImagePath);
	}

	void OnlyImage::SetImage(const std::pair<std::string, std::string>& imageGroup) {
		SetFirstImage(imageGroup.first);
		SetFirstImage(imageGroup.second);
	}

	void OnlyImage::SetFirstImage(const std::string& imagePath) {
		SetAnyImage(FIRST_IMAGE, imagePath);
	}
	
	void OnlyImage::SetSecondImage(const std::string& imagePath) {
		SetAnyImage(SECOND_IMAGE, imagePath);
	}

	void OnlyImage::SetAnyImage(const ImageType imageType, const std::string& imagePath) {
		if (!CheckPathExist(imagePath)) {
			return;
		}
		switch (imageType) {
		case FIRST_IMAGE:
			images.first = imread(imagePath, cv::IMREAD_GRAYSCALE);
			break;
		case SECOND_IMAGE:
			images.second = imread(imagePath, cv::IMREAD_GRAYSCALE);
			break;
		}
	}

	double OnlyImage::SimpleCalc() {
		float h_ranges[] = { 0, 255 };
		const float* ranges[] = { h_ranges };
		constexpr int channels[] = { 0 };
		constexpr int hist_size[] = { 255 };
		calcHist(&images.first, 1, channels, cv::Mat(), hist_images.first, 1, hist_size, ranges, true, false);
		calcHist(&images.second, 1, channels, cv::Mat(), hist_images.second, 1, hist_size, ranges, true, false);

		const double diff = compareHist(hist_images.first, hist_images.second, cv::HISTCMP_HELLINGER);
		return diff;
	}

	bool OnlyImage::CheckPathExist(const std::string& path) const {
		std::filesystem::path file_path = path;
		//check this path exists
		if (!std::filesystem::exists(path) && !std::filesystem::is_regular_file(path)) {
			return false;
		}
		return true;
	}
}
