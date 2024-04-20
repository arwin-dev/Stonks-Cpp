#include "bullishEngulfingRecognizer.h"


namespace Stonks_Cpp {
	// Constructor for bullishEngulfingRecognizer class
	bullishEngulfingRecognizer::bullishEngulfingRecognizer() : recognizer(2, "Bullish Engulfing")
	{

	}

	// Override method to recognize a bullish engulfing pattern for a list of candlesticks
	bool bullishEngulfingRecognizer::recognize(List<smartCandlestick^>^ sc, int index)
	{

		smartCandlestick^ sc1 = sc[index];
		bool value;
		if (sc1->Patterns->TryGetValue(patternName, value))
		{
			return value;
		}
		else
		{
			int offset = patternSize / 2;
			if (index < offset)
			{
				sc1->Patterns->Add(patternName, false);
				return false;
			}
			else
			{
				smartCandlestick^ sc2 = sc[index - offset];
				bool bearish_engulfing = (sc2->Close > sc2->Open) && (sc1->Close < sc1->Open) && (sc2->Close > sc1->Open) && (sc2->Open < sc1->Close);
				sc1->Patterns->Add(patternName, bearish_engulfing);
				return bearish_engulfing;
			}
		}
	}
}
