#include "bearishRecognizer.h" // Include header file for the bearishRecognizer class

namespace Stonks_Cpp {

	// Constructor for bearishRecognizer class
	bearishRecognizer::bearishRecognizer() : recognizer(1, "Bearish")
	{
		// Constructor initializes the bearishRecognizer with a pattern size of 1 and sets the pattern name to "Bearish"
	}

	// Override method to recognize a bearish pattern for a single candlestick
	bool bearishRecognizer::recognize(List<smartCandlestick^>^ sc, int index)
	{
		// Retrieve the candlestick at the specified index from the list
		smartCandlestick^ sc1 = sc[index];
		bool value;

		// Check if the pattern has already been recognized for this candlestick
		if (sc1->Patterns->TryGetValue(patternName, value))
		{
			// If the pattern has already been recognized, return the stored value
			return value;
		}
		else
		{
			// If the pattern has not been recognized, mark it as a bearish pattern and return the result
			sc1->Patterns->Add(patternName, sc1->IsBearish);
			return sc1->IsBearish;
		}
	}
}
