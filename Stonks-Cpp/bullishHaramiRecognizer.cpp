#include "bullishHaramiRecognizer.h"

namespace Stonks_Cpp {
	// Constructor for bullishHaramiRecognizer class
	bullishHaramiRecognizer::bullishHaramiRecognizer() : recognizer(2, "Bullish Harami")
	{

	}

	// Override method to recognize a bullish harami pattern for a list of candlesticks
	bool bullishHaramiRecognizer::recognize(List<smartCandlestick^>^ sc, int index)
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
				bool check = ((sc2->Close > sc2->Open) && (sc1->Close < sc1->Open) && (sc2->Close < sc1->Open) && (sc2->Open > sc1->Open));
				sc1->Patterns->Add(patternName, check);
				return check;
			}
		}
	}
}