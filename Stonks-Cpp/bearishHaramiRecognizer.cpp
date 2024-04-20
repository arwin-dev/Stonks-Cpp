#include "bearishHaramiRecognizer.h" // Include header file for the bearishHaramiRecognizer class

namespace Stonks_Cpp {

	// Constructor for bearishHaramiRecognizer class
	bearishHaramiRecognizer::bearishHaramiRecognizer() : recognizer(2, "Bearish Harami")
	{
		// Constructor initializes the bearishHaramiRecognizer with a pattern size of 2 and sets the pattern name to "Bearish Harami"
	}

	// Override method to recognize a bearish harami pattern for a list of candlesticks
	bool bearishHaramiRecognizer::recognize(List<smartCandlestick^>^ sc, int index)
	{
		// Retrieve the candlestick at the specified index from the list
		smartCandlestick^ scs = sc[index];
		bool value;

		// Check if the pattern has already been recognized for this candlestick
		if (scs->Patterns->TryGetValue(patternName, value))
		{
			// If the pattern has already been recognized, return the stored value
			return value;
		}
		else
		{
			// Calculate the offset to ensure we have enough data points for analysis
			int offset = patternSize / 2;

			// Check if there are enough data points before the current index
			if (index < offset)
			{
				// If there are not enough data points, mark the pattern as unrecognized and return false
				scs->Patterns->Add(patternName, false);
				return false;
			}
			else
			{
				// Retrieve the previous candlestick for analysis
				smartCandlestick^ prevCs = sc[index - offset];

				// Check if the previous candlestick is bearish
				bool bearish = (prevCs->Open < prevCs->Close);

				// Check if the current candlestick and the previous candlestick form a harami pattern
				bool harami = (scs->TopPrice < prevCs->TopPrice) && (scs->BottomPrice > prevCs->BottomPrice);

				// Check if both conditions are met to confirm a bearish harami pattern
				bool bearish_harami = bearish && harami;

				// Store the recognition result for future reference
				scs->Patterns->Add(patternName, bearish_harami);

				// Return whether the current candlestick pattern is a bearish harami
				return bearish_harami;
			}
		}
	}
}
