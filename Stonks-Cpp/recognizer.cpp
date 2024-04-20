#include "recognizer.h" 
#include "smartCandlestick.h" 

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

	void recognizer::recognizeAll(List<smartCandlestick^>^ listOfCandlesticks)
	{
		for (int i = 0; i < listOfCandlesticks->Count; i++)
		{
			recognize(listOfCandlesticks, i);
		}
	}
}
