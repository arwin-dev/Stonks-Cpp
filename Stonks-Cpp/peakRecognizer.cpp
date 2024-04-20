#include "peakRecognizer.h"

namespace Stonks_Cpp {
	// Constructor for peakRecognizer class
	peakRecognizer::peakRecognizer() : recognizer(3, "Peak")
	{

	}

	// Override method to recognize a peak pattern for a list of candlesticks
	bool peakRecognizer::recognize(List<smartCandlestick^>^ sc, int index)
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
			if ((index < offset) || (index == sc->Count - offset))
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


		// Check if there are exactly three candlesticks
		if (sc->Count == 3)
		{
			smartCandlestick^ sc1 = sc[0];
			smartCandlestick^ sc2 = sc[1];
			smartCandlestick^ sc3 = sc[2];

			// Check conditions for peak pattern
			return (sc2->High > sc1->High) && (sc2->High > sc3->High);
		}

		return false;
	}
}