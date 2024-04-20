#include "marubozuRecognizer.h" // Include header file for the marubozuRecognizer class

namespace Stonks_Cpp {

	// Constructor for marubozuRecognizer class
	marubozuRecognizer::marubozuRecognizer() : recognizer(1, "Marubozu")
	{
		// Constructor initializes the marubozuRecognizer with a pattern size of 1 and sets the pattern name to "Marubozu"
	}

	// Override method to recognize a marubozu pattern for a single candlestick
	bool marubozuRecognizer::recognize(List<smartCandlestick^>^ sc, int index)
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
			// If the pattern has not been recognized, mark it as a marubozu and return the result
			sc1->Patterns->Add(patternName, sc1->IsMarubozu);
			return sc1->IsMarubozu;
		}
	}
}
