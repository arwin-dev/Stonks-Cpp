#include "bullishRecognizer.h" // Include header file for the bullishRecognizer class

namespace Stonks_Cpp {

	// Constructor for bullishRecognizer class
	bullishRecognizer::bullishRecognizer() : recognizer(1, "Bullish")
	{
		// Constructor initializes the bullishRecognizer with a pattern size of 1 and sets the pattern name to "Bullish"
	}

	// Override method to recognize a bullish pattern for a single candlestick
	bool bullishRecognizer::recognize(List<smartCandlestick^>^ sc, int index)
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
			// If the pattern has not been recognized, mark it as bullish and return the result
			sc1->Patterns->Add(patternName, sc1->IsBullish);
			return sc1->IsBullish;
		}
	}
}