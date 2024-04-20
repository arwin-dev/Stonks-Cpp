#include "neutralRecognizer.h"

namespace Stonks_Cpp {
	// Constructor for neutralRecognizer class
	neutralRecognizer::neutralRecognizer() : recognizer(1, "Neutral")
	{

	}

	// Override method to recognize a neutral pattern for a single candlestick
	bool neutralRecognizer::recognize(List<smartCandlestick^>^ sc, int index)
	{
		smartCandlestick^ sc1 = sc[index];
		bool value;
		if (sc1->Patterns->TryGetValue(patternName, value))
		{
			return value;
		}
		else
		{
			sc1->Patterns->Add(patternName, sc1->IsNeutral);
			return sc1->IsNeutral;;
		}
	}
}
