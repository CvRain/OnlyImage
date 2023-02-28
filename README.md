# OnlyImage
**一段非常简单的图片判断代码**

**A very simple image judgment code**

## 使用需求
- 需要使用到opencv4库
- 需要使用C++17版本

## need
- library: opencv
- cxx_std_17

## 如何使用 How to use

**vcpkg**

`vcpkg install opencv4 opencv4:x64-windows `

**vcpkg with CMakeLists.txt**
```cmake
set(OpenCV_DIR "${VCPKG_INSTALLED_DIR}/x86-windows/share/opencv4")
find_package(OpenCV REQUIRED)
```

**arch**

`sudo pacman -S opencv4`


**OpenSUSE**

`sudo zypper install opencv-devel`

**Centos**

`sudo dnf install opencv opencv-devel opencv-python -y`

**CMakeLists**
```cmake
set(OpenCV_DIR {YOURS_DIR}) #OpenCVConfig.cmake
find_package(opencv required)	# find opencv
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBRARIES})

```