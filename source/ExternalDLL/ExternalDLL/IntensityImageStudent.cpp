#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	// To prevent multiple executions AND more importantly ensuring that for some reason the width or height is changed according to a get.
	int pixelAmount = other.getWidth() * other.getHeight();
	// Looping through all the pixels and settting them.
	for (int pixelCount = 0; pixelCount < pixelAmount; pixelCount++) {
		setPixel(pixelCount, other.getPixel(pixelCount));
	}
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	// Resizing based on new width and height (which clears on it's own).
	Pixels.resize(width*height);
}

IntensityImageStudent::~IntensityImageStudent() { /* Nothing to clear */}

void IntensityImageStudent::set(const int width, const int height) {
	// In the event of a function call, we're assuming everything needs to go. 
	// We can't keep images with wrong height and widths.

	// Resizing already calls the  "erase(begin(), end());" so we won't do that seperately.	
	Pixels.resize(width*height);

	
	// Making sure that our get calls don't crash inadvertely
	IntensityImage::set(width, height);

}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());

	// To prevent multiple executions AND more importantly ensuring that for some reason the width or height is changed according to a get.
	int pixelAmount = other.getWidth()*other.getHeight();

	// Resizing already calls the  "erase(begin(), end());" so we won't do that seperately.
	Pixels.resize(pixelAmount);

	// each pixel gets written into a new pixel.
	for (int pixelCount = 0; pixelCount < pixelAmount; pixelCount++) {
		setPixel(pixelCount, other.getPixel(pixelCount));
	}
}

// We don't want to make multiple insertation functions so we'll create a series of interfaces that do the work.
void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	int pixelID = (y * IntensityImage::getWidth()) + x; // order of operations is very important so double ensuring it with braces
	setPixel(pixelID, pixel);
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	// Writing to a specific memory point with error catching for outside.
	Pixels.at(i) = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	// Masker function so calculation logic can be done at class level.
	int i = y * IntensityImage::getWidth() + x;// order of operations is very important so double ensuring it with braces
	return getPixel(i);
}

Intensity IntensityImageStudent::getPixel(int i) const {
	// Returing a single pixel from the Pixels with at check for error catching (debugging)
	return Pixels.at(i);;
}