#include "gravestoneDojiRecognizer.h" // Include header file for the gravestoneDojiRecognizer class

namespace Stonks_Cpp {

	// Constructor for gravestoneDojiRecognizer class
	gravestoneDojiRecognizer::gravestoneDojiRecognizer() : recognizer(1, "GravestoneDoji")
	{
		// Constructor initializes the gravestoneDojiRecognizer with a pattern size of 1 and sets the pattern name to "GravestoneDoji"
	}

	// Override method to recognize a gravestone doji pattern for a single candlestick
	bool gravestoneDojiRecognizer::recognize(List<smartCandlestick^>^ sc, int index)
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
			// If the pattern has not been recognized, mark it as a gravestone doji and return the result
			sc1->Patterns->Add(patternName, sc1->IsGravestoneDoji);
			return sc1->IsGravestoneDoji;
		}
	}
}
