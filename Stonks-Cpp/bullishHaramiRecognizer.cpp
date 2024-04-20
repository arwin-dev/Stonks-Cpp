#include "bullishHaramiRecognizer.h" // Include header file for the bullishHaramiRecognizer class

namespace Stonks_Cpp {

	// Constructor for bullishHaramiRecognizer class
	bullishHaramiRecognizer::bullishHaramiRecognizer() : recognizer(2, "Bullish Harami")
	{
		// Constructor initializes the bullishHaramiRecognizer with a pattern size of 2 and sets the pattern name to "Bullish Harami"
	}

	// Override method to recognize a bullish harami pattern for a list of candlesticks
	bool bullishHaramiRecognizer::recognize(List<smartCandlestick^>^ sc, int index)
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

				// Check if the previous candlestick is bullish
				bool bullsih = (prevCs->Open > prevCs->Close);

				// Check if the current candlestick and the previous candlestick form a harami pattern
				bool harami = (scs->TopPrice < prevCs->TopPrice) && (scs->BottomPrice > prevCs->BottomPrice);

				// Check if both conditions are met to confirm a bullish harami pattern
				bool bullish_harami = bullsih && harami;

				// Store the recognition result for future reference
				scs->Patterns->Add(patternName, bullish_harami);

				// Return whether the current candlestick pattern is a bullish harami
				return bullish_harami;
			}
		}
	}
}
