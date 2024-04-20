#include "neutralRecognizer.h" // Include header file for the neutralRecognizer class

namespace Stonks_Cpp {

	// Constructor for neutralRecognizer class
	neutralRecognizer::neutralRecognizer() : recognizer(1, "Neutral")
	{
		// Constructor initializes the neutralRecognizer with a pattern size of 1 and sets the pattern name to "Neutral"
	}

	// Override method to recognize a neutral pattern for a single candlestick
	bool neutralRecognizer::recognize(List<smartCandlestick^>^ sc, int index)
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
			// If the pattern has not been recognized, mark it as neutral and return the result
			sc1->Patterns->Add(patternName, sc1->IsNeutral);
			return sc1->IsNeutral;
		}
	}
}
