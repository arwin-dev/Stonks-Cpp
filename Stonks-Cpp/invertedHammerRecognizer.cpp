#include "invertedHammerRecognizer.h" // Include header file for the invertedHammerRecognizer class

namespace Stonks_Cpp {

	// Constructor for invertedHammerRecognizer class
	invertedHammerRecognizer::invertedHammerRecognizer() : recognizer(1, "InvertedHammer")
	{
		// Constructor initializes the invertedHammerRecognizer with a pattern size of 1 and sets the pattern name to "InvertedHammer"
	}

	// Override method to recognize an inverted hammer pattern for a single candlestick
	bool invertedHammerRecognizer::recognize(List<smartCandlestick^>^ sc, int index)
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
			// If the pattern has not been recognized, mark it as an inverted hammer and return the result
			sc1->Patterns->Add(patternName, sc1->IsInvertedHammer);
			return sc1->IsInvertedHammer;
		}
	}
}
