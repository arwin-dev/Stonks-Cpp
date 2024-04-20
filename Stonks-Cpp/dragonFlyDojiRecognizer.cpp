#include "dragonFlyDojiRecognizer.h" // Include header file for the dragonFlyDojiRecognizer class

namespace Stonks_Cpp {

	// Constructor for dragonFlyDojiRecognizer class
	dragonFlyDojiRecognizer::dragonFlyDojiRecognizer() : recognizer(1, "DragonFlyDoji")
	{
		// Constructor initializes the dragonFlyDojiRecognizer with a pattern size of 1 and sets the pattern name to "DragonFlyDoji"
	}

	// Override method to recognize a dragonfly doji pattern for a single candlestick
	bool dragonFlyDojiRecognizer::recognize(List<smartCandlestick^>^ sc, int index)
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
			// If the pattern has not been recognized, mark it as a dragonfly doji and return the result
			sc1->Patterns->Add(patternName, sc1->IsDragonFlyDoji);
			return sc1->IsDragonFlyDoji;
		}
	}
}
