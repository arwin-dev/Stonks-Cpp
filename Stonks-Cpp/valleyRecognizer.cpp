#include "valleyRecognizer.h" // Include header file for the valleyRecognizer class

namespace Stonks_Cpp {

	// Constructor for valleyRecognizer class
	valleyRecognizer::valleyRecognizer() : recognizer(3, "Valley")
	{
		// Constructor initializes the recognizer with a pattern size of 3 and sets the pattern name to "Valley"
	}

	// Override method to recognize a valley pattern for a list of candlesticks
	bool valleyRecognizer::recognize(List<smartCandlestick^>^ sc, int index)
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
			// Calculate the offset to ensure we have enough data points for analysis
			int offset = patternSize / 2;

			// Check if there are enough data points before and after the current index
			if ((index < offset) || (index == sc->Count - offset))
			{
				// If there are not enough data points, mark the pattern as unrecognized and return false
				sc1->Patterns->Add(patternName, false);
				return false;
			}
			else
			{
				// Retrieve the candlesticks before and after the current index to analyze the pattern
				smartCandlestick^ sc2 = sc[index - offset];
				smartCandlestick^ sc3 = sc[index + offset];

				// Check if the current candlestick forms a valley pattern based on the lows of surrounding candlesticks
				bool valley = (sc1->Low < sc2->Low) && (sc1->Low < sc3->Low);

				// Store the recognition result for future reference
				sc1->Patterns->Add(patternName, valley);

				// Return whether the current candlestick forms a valley pattern
				return valley;
			}
		}
	}
}
