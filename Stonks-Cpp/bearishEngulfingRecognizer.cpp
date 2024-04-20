#include "bearishEngulfingRecognizer.h"


namespace Stonks_Cpp {
	// Constructor for bearishEngulfingRecognizer class
	bearishEngulfingRecognizer::bearishEngulfingRecognizer() : recognizer(2, "Bearish Engulfing")
	{

	}

	// Override method to recognize a bearish engulfing pattern for a list of candlesticks
	bool bearishEngulfingRecognizer::recognize(List<smartCandlestick^>^ sc, int index)
	{

		smartCandlestick^ sc1 = sc[index] ;
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
				bool check = (sc2->Close < sc2->Open) && (sc1->Close > sc1->Open) && (sc2->Close < sc1->Open) && (sc2->Open > sc1->Close);
				sc1->Patterns->Add(patternName, check);
				return check;
			}
		}
	}
}