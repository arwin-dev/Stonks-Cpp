#include "recognizer.h"
#include "smartCandlestick.h"

namespace Stonks_Cpp {

	recognizer::recognizer(int size, String^ name)
	{
		this->patternSize = size;
		this->patternName = name;
	}

	bool recognizer::recognizePattern(smartCandlestick^ cs)
	{
		return false;
	}

	bool recognizer::recognizePattern(List<smartCandlestick^>^ cs)
	{
		return false;
	}

	bullishRecognizer::bullishRecognizer() : recognizer(1, "Bullish")
	{

	}

	bool bullishRecognizer::recognizePattern(smartCandlestick^ cs)
	{
		return cs->IsBullish;
	}

	bearishRecognizer::bearishRecognizer() : recognizer(1, "Bearish")
	{

	}

	bool bearishRecognizer::recognizePattern(smartCandlestick^ cs)
	{
		return cs->IsBearish;
	}

	neutralRecognizer::neutralRecognizer() : recognizer(1, "Neutral")
	{

	}

	bool neutralRecognizer::recognizePattern(smartCandlestick^ cs)
	{
		return cs->IsNeutral;
	}

	dojiRecognizer::dojiRecognizer() : recognizer(1, "Doji")
	{

	}

	bool dojiRecognizer::recognizePattern(smartCandlestick^ cs)
	{
		return cs->IsDoji;
	}

	marubozuRecognizer::marubozuRecognizer() : recognizer(1, "Marubozu")
	{

	}

	bool marubozuRecognizer::recognizePattern(smartCandlestick^ cs)
	{
		return cs->IsMarubozu;
	}

	dragonFlyDojiRecognizer::dragonFlyDojiRecognizer() : recognizer(1, "DragonFlyDoji")
	{

	}

	bool dragonFlyDojiRecognizer::recognizePattern(smartCandlestick^ cs)
	{
		return cs->IsDragonFlyDoji;
	}

	gravestoneDojiRecognizer::gravestoneDojiRecognizer() : recognizer(1, "GravestoneDoji")
	{

	}

	bool gravestoneDojiRecognizer::recognizePattern(smartCandlestick^ cs)
	{
		return cs->IsGravestoneDoji;
	}

	hammerRecognizer::hammerRecognizer() : recognizer(1, "Hammer")
	{

	}

	bool hammerRecognizer::recognizePattern(smartCandlestick^ cs)
	{
		return cs->IsHammer;
	}

	invertedHammerRecognizer::invertedHammerRecognizer() : recognizer(1, "InvertedHammer")
	{

	}

	bool invertedHammerRecognizer::recognizePattern(smartCandlestick^ cs)
	{
		return cs->IsInvertedHammer;
	}

	peakRecognizer::peakRecognizer() : recognizer(3, "Peak")
	{

	}

	bool peakRecognizer::recognizePattern(List<smartCandlestick^>^ sc)
	{
		if (sc->Count == 3)
		{
			smartCandlestick^ sc1 = sc[0];
			smartCandlestick^ sc2 = sc[1];
			smartCandlestick^ sc3 = sc[2];

			return (sc2->High > sc1->High) && (sc2->High > sc3->High);
		}

		return false;
	}

	valleyRecognizer::valleyRecognizer() : recognizer(3, "Valley")
	{
		
	}

	bool valleyRecognizer::recognizePattern(List<smartCandlestick^>^ sc)
	{
		if (sc->Count == 3)
		{
			smartCandlestick^ sc1 = sc[0];
			smartCandlestick^ sc2 = sc[1];
			smartCandlestick^ sc3 = sc[2];

			return (sc2->Low > sc1->Low) && (sc2->Low > sc3->Low);
		}

		return false;
	}
}
