#pragma once

#include <opencv2/opencv.hpp>
#include <utility>
#include <string>
#include <filesystem>

namespace OnlyImage {
	using ImageType = enum {
		FIRST_IMAGE,
		SECOND_IMAGE
	};

	using ImageStatus = enum {
		OK,
		FAILED,
		ERROR
	};

	class OnlyImage {
	public:
		OnlyImage() = default;
		explicit OnlyImage(const std::string& firstImagePath, const std::string& secondImagePath);
		explicit OnlyImage(const std::pair<std::string, std::string>& imageGroup);
		explicit OnlyImage(const cv::MatND& firstImageNd, const cv::MatND& secondImageNd);
		// 设置一对需要比较的图片
		void SetImage(const std::string& firstImagePath, const std::string& secondImagePath);
		void SetImage(const std::pair<std::string, std::string>& imageGroup);
		// 设置第一张需要比较的图片
		void SetFirstImage(const std::string& imagePath);
		// 设置第二张需要比较的图片
		void SetSecondImage(const std::string& imagePath);
		// 设置任意一张图片 可以是 FIRST_IMAGE 或者 SECOND_IMAGE
		void SetAnyImage(ImageType imageType, const std::string& imagePath);
		//计算图片差值
		double SimpleCalc();

	private:
		[[nodiscard]] bool CheckPathExist(const std::string& path) const;
		std::pair<cv::Mat, cv::Mat> images;
		std::pair<cv::MatND, cv::MatND> hist_images;
	};
}
