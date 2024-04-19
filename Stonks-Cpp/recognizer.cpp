#include "recognizer.h" 
#include "smartCandlestick.h" 

namespace Stonks_Cpp {

	// Constructor for the recognizer class
	recognizer::recognizer(int size, String^ name)
	{
		this->patternSize = size; // Set the pattern size
		this->patternName = name; // Set the pattern name
	}

	// Default implementation of recognizePattern for a single candlestick
	bool recognizer::recognize(smartCandlestick^ cs)
	{
		return false; // Default implementation always returns false
	}

	// Default implementation of recognizePattern for a list of candlesticks
	bool recognizer::recognize(List<smartCandlestick^>^ cs)
	{
		return false; // Default implementation always returns false
	}

}
