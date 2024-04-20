#include "bullishEngulfingRecognizer.h" // Include header file for the bullishEngulfingRecognizer class

namespace Stonks_Cpp {

	// Constructor for bullishEngulfingRecognizer class
	bullishEngulfingRecognizer::bullishEngulfingRecognizer() : recognizer(2, "Bullish Engulfing")
	{
		// Constructor initializes the bullishEngulfingRecognizer with a pattern size of 2 and sets the pattern name to "Bullish Engulfing"
	}

	// Override method to recognize a bullish engulfing pattern for a list of candlesticks
	bool bullishEngulfingRecognizer::recognize(List<smartCandlestick^>^ sc, int index)
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

				// Check if the current candlestick completely engulfs the previous candlestick
				bool engulfing = (scs->TopPrice > prevCs->TopPrice) && (scs->BottomPrice < prevCs->BottomPrice);

				// Check if both conditions are met to confirm a bullish engulfing pattern
				bool bullish_engulfing = bullsih && engulfing;

				// Store the recognition result for future reference
				scs->Patterns->Add(patternName, bullish_engulfing);

				// Return whether the current candlestick pattern is a bullish engulfing
				return bullish_engulfing;
			}
		}
	}
}
