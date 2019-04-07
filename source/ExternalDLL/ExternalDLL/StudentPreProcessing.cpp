#include "StudentPreProcessing.h"
#include "ImageFactory.h"
#include <algorithm>

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	IntensityImage * intensityImage = ImageFactory::newIntensityImage(image.getWidth(), image.getHeight());
	
	
	// We're calculating the
	int pixelAmount = image.getHeight() * image.getWidth();
	//Calculating the intensity value for eacht pixel 
	for (int pixelCount = 0; pixelCount < pixelAmount; pixelCount++) {
		//get rgb values
		RGB RGBPixel = image.getPixel(pixelCount); // acquiring the pixel that's been set in motion


		// Different ways of performing grayscaling.
		/*
		Intensity intensity = ((RGBPixel.r * 0.2126 + RGBPixel.g * 0.7152 + RGBPixel.b * 0.0722)); // ITU-R BT-709
		Intensity intensity = ((RGBPixel.r * 0.299 + RGBPixel.g * 0.587 + RGBPixel.b * 0.114)); // ITU-R BT-601 
		Intensity intensity = ((RGBPixel.r * 0.3 + RGBPixel.g * 0.59 + RGBPixel.b * 0.11)); // GIMP, Photoshop


		Intensity intensity = (std::max(RGBPixel.r, RGBPixel.g, RGBPixel.b) + std::min(RGBPixel.r, RGBPixel.g, RGBPixel.b)) / 2; // Desaturation

		//single channels
		Intensity intensity = (RGBPixel.g);
		Intensity intensity = (RGBPixel.b); 

		*/

		Intensity intensity = (RGBPixel.r);
		intensityImage->setPixel(pixelCount, intensity);
	}
	return intensityImage;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}