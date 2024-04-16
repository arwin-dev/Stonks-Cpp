#include "recognizer.h" 
#include "smartCandlestick.h" 

namespace Stonks_Cpp {

	// Constructor for the recognizer class
	recognizer::recognizer(int size, String^ name)
	{
		this->patternSize = size; // Set the pattern size
		this->patternName = name; // Set the pattern name
	}

	// Default implementation of recognizePattern for a single candlestick
	bool recognizer::recognizePattern(smartCandlestick^ cs)
	{
		return false; // Default implementation always returns false
	}

	// Default implementation of recognizePattern for a list of candlesticks
	bool recognizer::recognizePattern(List<smartCandlestick^>^ cs)
	{
		return false; // Default implementation always returns false
	}

	// Constructor for bullishRecognizer class
	bullishRecognizer::bullishRecognizer() : recognizer(1, "Bullish")
	{

	}

	// Override method to recognize a bullish pattern for a single candlestick
	bool bullishRecognizer::recognizePattern(smartCandlestick^ cs)
	{
		return cs->IsBullish; // Check if the candlestick is bullish
	}

	// Constructor for bearishRecognizer class
	bearishRecognizer::bearishRecognizer() : recognizer(1, "Bearish")
	{

	}

	// Override method to recognize a bearish pattern for a single candlestick
	bool bearishRecognizer::recognizePattern(smartCandlestick^ cs)
	{
		return cs->IsBearish; // Check if the candlestick is bearish
	}

	// Constructor for neutralRecognizer class
	neutralRecognizer::neutralRecognizer() : recognizer(1, "Neutral")
	{

	}

	// Override method to recognize a neutral pattern for a single candlestick
	bool neutralRecognizer::recognizePattern(smartCandlestick^ cs)
	{
		return cs->IsNeutral; // Check if the candlestick is neutral
	}

	// Constructor for dojiRecognizer class
	dojiRecognizer::dojiRecognizer() : recognizer(1, "Doji")
	{

	}

	// Override method to recognize a doji pattern for a single candlestick
	bool dojiRecognizer::recognizePattern(smartCandlestick^ cs)
	{
		return cs->IsDoji; // Check if the candlestick is a doji
	}

	// Constructor for marubozuRecognizer class
	marubozuRecognizer::marubozuRecognizer() : recognizer(1, "Marubozu")
	{

	}

	// Override method to recognize a marubozu pattern for a single candlestick
	bool marubozuRecognizer::recognizePattern(smartCandlestick^ cs)
	{
		return cs->IsMarubozu; // Check if the candlestick is a marubozu
	}

	// Constructor for dragonFlyDojiRecognizer class
	dragonFlyDojiRecognizer::dragonFlyDojiRecognizer() : recognizer(1, "DragonFlyDoji")
	{

	}

	// Override method to recognize a dragonfly doji pattern for a single candlestick
	bool dragonFlyDojiRecognizer::recognizePattern(smartCandlestick^ cs)
	{
		return cs->IsDragonFlyDoji; // Check if the candlestick is a dragonfly doji
	}

	// Constructor for gravestoneDojiRecognizer class
	gravestoneDojiRecognizer::gravestoneDojiRecognizer() : recognizer(1, "GravestoneDoji")
	{

	}

	// Override method to recognize a gravestone doji pattern for a single candlestick
	bool gravestoneDojiRecognizer::recognizePattern(smartCandlestick^ cs)
	{
		return cs->IsGravestoneDoji; // Check if the candlestick is a gravestone doji
	}

	// Constructor for hammerRecognizer class
	hammerRecognizer::hammerRecognizer() : recognizer(1, "Hammer")
	{

	}

	// Override method to recognize a hammer pattern for a single candlestick
	bool hammerRecognizer::recognizePattern(smartCandlestick^ cs)
	{
		return cs->IsHammer; // Check if the candlestick is a hammer
	}

	// Constructor for invertedHammerRecognizer class
	invertedHammerRecognizer::invertedHammerRecognizer() : recognizer(1, "InvertedHammer")
	{

	}

	// Override method to recognize an inverted hammer pattern for a single candlestick
	bool invertedHammerRecognizer::recognizePattern(smartCandlestick^ cs)
	{
		return cs->IsInvertedHammer; // Check if the candlestick is an inverted hammer
	}

	// Constructor for bullishEngulfingRecognizer class
	bullishEngulfingRecognizer::bullishEngulfingRecognizer() : recognizer(2, "Bullish Engulfing")
	{

	}

	// Override method to recognize a bullish engulfing pattern for a list of candlesticks
	bool bullishEngulfingRecognizer::recognizePattern(List<smartCandlestick^>^ sc)
	{
		// Check if there are exactly two candlesticks
		if (sc->Count == 2)
		{
			smartCandlestick^ sc1 = sc[0];
			smartCandlestick^ sc2 = sc[1];

			// Check conditions for bullish engulfing pattern
			return (sc2->Close > sc2->Open) && (sc1->Close < sc1->Open) && (sc2->Close > sc1->Open) && (sc2->Open < sc1->Close);
		}

		return false;
	}

	// Constructor for bearishEngulfingRecognizer class
	bearishEngulfingRecognizer::bearishEngulfingRecognizer() : recognizer(2, "Bearish Engulfing")
	{

	}

	// Override method to recognize a bearish engulfing pattern for a list of candlesticks
	bool bearishEngulfingRecognizer::recognizePattern(List<smartCandlestick^>^ sc)
	{
		// Check if there are exactly two candlesticks
		if (sc->Count == 2)
		{
			smartCandlestick^ sc1 = sc[0];
			smartCandlestick^ sc2 = sc[1];

			// Check conditions for bearish engulfing pattern
			return (sc2->Close < sc2->Open) && (sc1->Close > sc1->Open) && (sc2->Close < sc1->Open) && (sc2->Open > sc1->Close);
		}

		return false;
	}

	// Constructor for bullishHaramiRecognizer class
	bullishHaramiRecognizer::bullishHaramiRecognizer() : recognizer(2, "Bullish Harami")
	{

	}

	// Override method to recognize a bullish harami pattern for a list of candlesticks
	bool bullishHaramiRecognizer::recognizePattern(List<smartCandlestick^>^ sc)
	{
		// Check if there are exactly two candlesticks
		if (sc->Count == 2)
		{
			smartCandlestick^ sc1 = sc[0];
			smartCandlestick^ sc2 = sc[1];

			// Check conditions for bullish harami pattern
			return ((sc2->Close > sc2->Open) && (sc1->Close < sc1->Open) && (sc2->Close < sc1->Open) && (sc2->Open > sc1->Open));
		}

		return false;
	}

	// Constructor for bearishHaramiRecognizer class
	bearishHaramiRecognizer::bearishHaramiRecognizer() : recognizer(2, "Bearish Harami")
	{

	}

	// Override method to recognize a bearish harami pattern for a list of candlesticks
	bool bearishHaramiRecognizer::recognizePattern(List<smartCandlestick^>^ sc)
	{
		// Check if there are exactly two candlesticks
		if (sc->Count == 2)
		{
			smartCandlestick^ sc1 = sc[0];
			smartCandlestick^ sc2 = sc[1];

			// Check conditions for bearish harami pattern
			return ((sc2->Close < sc2->Open) && (sc1->Close > sc1->Open) && (sc2->Close > sc1->Open) && (sc2->Open < sc1->Close));
		}

		return false;
	}

	// Constructor for peakRecognizer class
	peakRecognizer::peakRecognizer() : recognizer(3, "Peak")
	{

	}

	// Override method to recognize a peak pattern for a list of candlesticks
	bool peakRecognizer::recognizePattern(List<smartCandlestick^>^ sc)
	{
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

	// Constructor for valleyRecognizer class
	valleyRecognizer::valleyRecognizer() : recognizer(3, "Valley")
	{

	}

	// Override method to recognize a valley pattern for a list of candlesticks
	bool valleyRecognizer::recognizePattern(List<smartCandlestick^>^ sc)
	{
		// Check if there are exactly three candlesticks
		if (sc->Count == 3)
		{
			smartCandlestick^ sc1 = sc[0];
			smartCandlestick^ sc2 = sc[1];
			smartCandlestick^ sc3 = sc[2];

			// Check conditions for valley pattern
			return (sc2->Low > sc1->Low) && (sc2->Low > sc3->Low);
		}

		return false;
	}
}
