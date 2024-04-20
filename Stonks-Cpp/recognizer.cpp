#include "recognizer.h" // Include header file for the recognizer class
#include "smartCandlestick.h" // Include header file for the smartCandlestick class

namespace Stonks_Cpp {

	// Constructor for the recognizer class
	recognizer::recognizer(int size, String^ name)
	{
		this->patternSize = size; // Set the pattern size
		this->patternName = name; // Set the pattern name
	}

	// Default implementation of recognizePattern for a list of candlesticks
	bool recognizer::recognize(List<smartCandlestick^>^ cs, int index)
	{
		return false; // Default implementation always returns false
	}

	// Method to recognize patterns for all candlesticks in a list
	void recognizer::recognizeAll(List<smartCandlestick^>^ listOfCandlesticks)
	{
		// Loop through all candlesticks in the list
		for (int i = 0; i < listOfCandlesticks->Count; i++)
		{
			// Call the recognize method for each candlestick
			recognize(listOfCandlesticks, i);
		}
	}
}
