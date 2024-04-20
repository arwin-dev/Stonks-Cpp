#include "bullishRecognizer.h"


namespace Stonks_Cpp {
	// Constructor for bullishRecognizer class
	bullishRecognizer::bullishRecognizer() : recognizer(1, "Bullish")
	{

	}

	// Override method to recognize a bullish pattern for a single candlestick
	bool bullishRecognizer::recognize(List<smartCandlestick^>^ sc, int index)
	{
		smartCandlestick^ sc1 = sc[index];
		bool value;
		if (sc1->Patterns->TryGetValue(patternName, value))
		{
			return value;
		}
		else
		{
			sc1->Patterns->Add(patternName, sc1->IsBullish);
			return sc1->IsBullish;
		}
	}
}