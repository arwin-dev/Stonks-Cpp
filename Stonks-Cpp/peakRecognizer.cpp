#include "peakRecognizer.h" // Include header file for the peakRecognizer class

namespace Stonks_Cpp {

	// Constructor for peakRecognizer class
	peakRecognizer::peakRecognizer() : recognizer(3, "Peak")
	{
		// Constructor initializes the peakRecognizer with a pattern size of 3 and sets the pattern name to "Peak"
	}

	// Override method to recognize a peak pattern for a list of candlesticks
	bool peakRecognizer::recognize(List<smartCandlestick^>^ sc, int index)
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

				// Check if the current candlestick forms a peak pattern based on the highs of surrounding candlesticks
				bool peak = (sc1->High > sc2->High) && (sc1->High > sc3->High);

				// Store the recognition result for future reference
				sc1->Patterns->Add(patternName, peak);

				// Return whether the current candlestick forms a peak pattern
				return peak;
			}
		}
	}
}
